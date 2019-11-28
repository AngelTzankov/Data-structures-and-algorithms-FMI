#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> arr;
    int heapSize;

    int parent(int idx)
    {
        return (idx-1)/2;
    }

    int leftChild(int idx)
    {
        return idx*2+1;
    }

    int rightChild(int idx)
    {
        return idx*2+2;
    }

    bool hasLeftChild(int idx)
    {
        return idx*2+1 < heapSize;
    }

    bool hasRightChild(int idx)
    {
        return idx*2+2 < heapSize;
    }

    void pullUp(int idx)
    {
        if(idx == 0)
            return;
        if(arr[idx] > arr[parent(idx)])
        {
            swap(arr[idx], arr[parent(idx)]);
            pullUp(parent(idx));
        }
    }

    void pullUpIterative(int idx)
    {
        while(idx > 0)
        {
            if(arr[idx] > arr[parent(idx)])
            {
                swap(arr[idx], arr[parent(idx)]);
                idx = parent(idx);
            }
            else
                break;
        }
    }

    void heapify(int idx)
    {
        ///Find which one is the child with higher value.
        int maxValueChild = leftChild(idx);
        if(hasRightChild(idx) && arr[leftChild(idx)] < arr[rightChild(idx)])
            maxValueChild = rightChild(idx);

        ///If such a child exists and its value is higher than the value of
        ///the current node then swap their values and balance the child.
        if(hasLeftChild(idx) && arr[maxValueChild] > arr[idx])
        {
            swap(arr[maxValueChild], arr[idx]);
            heapify(maxValueChild);
        }
    }

    void heapifyIterative(int idx)
    {
        while(idx > 0)
        {
            int maxValueChild = idx;
            if(hasRightChild(idx) && arr[leftChild(idx)] > arr[rightChild(idx)])
                maxValueChild = rightChild(idx);
            if(hasLeftChild(idx) && arr[maxValueChild] > arr[idx])
            {
                swap(arr[maxValueChild], arr[idx]);
                idx = maxValueChild;
            }
            else
                break;
        }
    }

public:
    Heap()
    {
        heapSize = 0;
    }

    ///This one is linear building of heap with a given array of n elements.
    ///In the last exercise I said it's not linear in time but it is :D
    ///Next time I may prove it if someone is interested.
    Heap(int* arr, int n)
    {
        for(int i=0;i<n;++i)
        {
            this->arr.push_back(arr[i]);
        }
        for(int i=n/2-1;i>=0;--i)
        {
            heapifyIterative(i);
        }
    }

    void push(int x)
    {
        arr.push_back(x);
        pullUpIterative(heapSize++);
    }

    int top()
    {
        return arr[0];
    }

    void pop()
    {
        swap(arr[0], arr[--heapSize]);
        heapify(0);
    }
};


int main()
{

}

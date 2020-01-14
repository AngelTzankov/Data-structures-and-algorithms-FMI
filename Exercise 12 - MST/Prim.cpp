#include <iostream>
#include <queue>
using namespace std;

struct Node {
    vector<int> neighbours;
    vector<int> weights;
};

struct Edge {
    int from, to, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

Node g[10000];
int nodeCost[10000], n, m;
bool visited[10000];

int mst(int start)
{
    int res = 0;
    priority_queue <Edge> pq;
    for(int i=0;i<n;++i)
    {
        nodeCost[i] = INT_MAX;
    }
    nodeCost[start] = 1;
    pq.push({start, start, 0});
    for(int i=0;i<n;++i) {
        if(pq.empty())
        {
            cout<<"No mst!"<<endl;
            return -1;
        }

        Edge x = pq.top();
        pq.pop();
        int u = x.to;
        if(!visited[u])
        {
            res+=x.weight;
            visited[u] = 1;
            for(int i=0;i<g[u].neighbours.size();++i)
            {
                int v = g[u].neighbours[i];
                int w = g[u].weights[i];
                if(nodeCost[v] > w && !visited[v])
                {
                    nodeCost[v] = w;
                    pq.push({u, v, w});
                }
            }
        }
    }
    return res;
}

int main()
{
    int from, to, w;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>from>>to>>w;
        g[from-1].neighbours.push_back(to-1);
        g[to-1].neighbours.push_back(from-1);
        g[from-1].weights.push_back(w);
        g[to-1].weights.push_back(w);
    }

    cout<<mst(0)<<endl;
}

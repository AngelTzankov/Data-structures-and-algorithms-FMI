#include <iotsream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    int arr[100];
    int positiveCnt = 0, zeroCnt = 0, negativeCnt = 0;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
        if( arr[i] > 0 )
        {
            positiveCnt++;
        }
        else if( arr[i] == 0 )
        {
            zeroCnt++;
        }
        else
        {
            negativeCnt++;
        }
    }
    cout<<fixed;
    cout<<setprecision(6)<<(double)positiveCnt/(double)n<<endl;
    cout<<setprecision(6)<<(double)zeroCnt/(double)n<<endl;
    cout<<setprecision(6)<<(double)negativeCnt/(double)n<<endl;

}

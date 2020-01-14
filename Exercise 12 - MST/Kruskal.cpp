#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int from, to, w;
    bool operator<(const Edge& other) {
        return w < other.w;
    }
};

vector<Edge> edges;
int p[10000], depth[10000], q[10000], edgesUsed, n, m;
bool hasBoss[100000];

void init()
{
    for(int i=0;i<n;++i)
    {
        p[i] = i;
        depth[i] = 1;
    }
}

int find(int v)
{
    if(p[v] == v)
        return v;
    return p[v] = find(p[v]);
}

/// union was reserved :(
int Union(Edge x)
{
    int r1 = find(x.from), r2 = find(x.to);
    if(r1 == r2)
        return 0;
    else
    {
        if(depth[r1] < depth[r2])
            swap(r1, r2);
        p[r2] = r1;
        if(depth[r1] == depth[r2])
            depth[r1]++;
        edgesUsed++;
        return x.w;
    }
}

int main()
{
    int ans = 0;
    cin>>n>>m;
    int from, to, w;
    for(int i=0;i<m;++i)
    {
        cin>>from>>to>>w;
        edges.push_back({from-1, to-1, w});
    }
    init();
    sort(edges.begin(), edges.end());
    for(int i=0;i<edges.size();++i)
    {
        ans += Union(edges[i]);

    }
    if(edgesUsed == n-1)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}

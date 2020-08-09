#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_V = 20001;
const int MAX_E = 50001;

struct Edge
{
    int u;
    int v;
    int cost;
};

bool cmp(const Edge& a, const Edge& b)
{
    return a.cost < b.cost;
}

Edge G[MAX_E];
int bingchaji[MAX_V];
int V, E;

int find_root(const int& pos)
{
    if (bingchaji[pos] == pos)
        return pos;
    else
        return bingchaji[pos] = find_root(bingchaji[pos]);
}

bool same(const int& a, const int& b)
{
    return find_root(a) == find_root(b);
}

void unite(const int& a, const int& b)
{
    int root = find_root(a);
    bingchaji[root] = b;
}

void inputs()
{
    int N, M, R;
    int x, y, d;
    scanf("%d %d %d", &N, &M, &R);
    V = N + M;
    E = R;
    for (int i=0; i < R; ++ i)
    {
        scanf("%d %d %d", &x, &y, &d);
        G[i] = {x, N + y, -d};
    }
}

int kruskal()
{
    int res = 0;
    sort(G, G + E, cmp);
    for (int i=0; i < V; ++ i)
    {
        bingchaji[i] = i;
    }
    for (int i=0; i < E; ++ i)
    {
        if (!same(G[i].u, G[i].v))
        {
            unite(G[i].u, G[i].v);
            res += G[i].cost;
        }
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T --)
    {
        inputs();
        int res = kruskal();
        printf("%d\n", 10000 * V + res);
        
    }
    return 0;
}

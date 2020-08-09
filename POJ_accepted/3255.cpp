#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V = 5001;
const int MAX_E = 100001;
const int INF = INT_MAX / 2;

typedef pair<int, int> Edge;    // 路径长度、点

vector<Edge> G[MAX_V];          // 邻接表
int dist[MAX_V];                // 从源点到其它点的最短距离
int dist2[MAX_V];               // 次短路
int V, E;                       // 节点数、路径数

void inputs()
{
    scanf("%d %d", &V, &E);
    int A, B, D;
    for (int i=0; i < E; ++ i)
    {
        scanf("%d %d %d", &A, &B, &D);
        G[A].push_back(make_pair(D, B));
        G[B].push_back(make_pair(D, A));
    }
}

int dijkstra(int s)
{
    priority_queue<Edge, vector<Edge>, greater<Edge> > que;
    fill(dist + 1, dist + V + 1, INF);
    fill(dist2 + 1, dist2 + V + 1, INF);
    dist[s] = 0;
    que.push(make_pair(0, s));

    while (!que.empty())
    {
        Edge e = que.top();
        que.pop();
        int v = e.second;
        int d = e.first;
        if (dist2[v] < d)
            continue;
        for (int i=0; i < G[v].size(); ++ i)
        {
            e = G[v][i];
            int d2 = d + e.first;
            if (dist[e.second] > d2)
            {
                swap(dist[e.second], d2);
                que.push(make_pair(dist[e.second], e.second));
            }
            if (dist2[e.second] > d2 && dist[e.second] < d2)
            {
                dist2[e.second] = d2;
                que.push(make_pair(dist2[e.second], e.second));
            }
        }
    }
    return dist2[V];
}

int main()
{
    inputs();
    int res = dijkstra(1);
    printf("%d\n", res);
    return 0;
}

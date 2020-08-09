#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Stop
{
    int distance;
    int fuel;
};

bool cmp(const Stop& a, const Stop& b)
{
    return a.distance < b.distance;
}

int main()
{
    int N, L, P, result=0;
    Stop stops[10001];
    priority_queue<int, vector<int>, less<int> > fuel_pool;
    scanf("%d", &N);
    for (int i=0; i < N; ++ i)
    {
        scanf("%d %d", &stops[i].distance, &stops[i].fuel);
    }
    scanf("%d %d", &L, &P);
    for (int i=0; i < N; ++ i)
    {
        stops[i].distance = L - stops[i].distance;
    }
    sort(stops, stops + N, cmp);
    for (int i=0; i < N; ++ i)
    {
        if (P < stops[i].distance)
        {
            while (P < stops[i].distance && !fuel_pool.empty())
            {
                P += fuel_pool.top();
                ++ result;
                fuel_pool.pop();
            }
        }
        if (P < stops[i].distance)
        {
            printf("-1\n");
            return 0;
        }
        fuel_pool.push(stops[i].fuel);
    }
    if (P < L)
    {
        while (P < L && !fuel_pool.empty())
        {
            P += fuel_pool.top();
            ++ result;
            fuel_pool.pop();
        }
    }
    if (P < L)
    {
        result = -1;
    }
    printf("%d\n", result);
    return 0;
}

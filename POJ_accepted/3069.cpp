#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int x[1001];

// 找到下标[start, end)之间小于等于limit的索引
int find_point(int start, int end, int limit)
{
    for (int i=start; i < end; ++ i)
    {
        if (x[i] > limit)
        {
            return i - 1;
        }
    }
    return end - 1;
}

int main()
{
    int R, n, temp, sum;
    while (true)
    {
        sum = 0;
        scanf("%d %d", &R, &n);
        if (R == -1 && n == -1)
        {
            break;
        }
        for (int i=0; i < n; ++ i)
        {
            scanf("%d", x + i);
        }
        sort(x, x + n);
        for (int i=0; i < n; ++ i)
        {
            temp = x[i] + R;
            int j = find_point(i, n, temp);
            temp = x[j] + R;
            i = find_point(j, n, temp);
            ++ sum;
        }
        printf("%d\n", sum);
    }
    return 0;
};

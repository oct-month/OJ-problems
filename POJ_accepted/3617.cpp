#include <cstdio>
using namespace std;


int main()
{
    int N;
    char cows[2000], tap;
    char temp[2];

    scanf("%d", &N);
    for (int i = 0; i < N; ++ i)
    {
        scanf("%s", temp);
        cows[i] = temp[0];
    }
    int front=0, end=N-1, i=0;
    while (front <= end)
    {
        int l=front, r=end;
        while (cows[l] == cows[r] && l < r) // 考虑首尾相同时的特殊情况
        {
            ++ l;
            -- r;
        }
        if (cows[l] < cows[r])
        {
            putchar(cows[front]);
            ++ front;
        }
        else
        {
            putchar(cows[end]);
            -- end;
        }
        if ((++ i) % 80 == 0)
        {
            putchar('\n');
        }
    }
    return 0;
}

#include <cstdio>
using namespace std;

int plank[20000];


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{
    int N, temp;
    long long result=0;
    scanf("%d", &N);
    for (int i=0; i < N; ++ i)
    {
        scanf("%d", plank + i);
    }
    while (N > 1)
    {
        int min_1=0, min_2=1;
        if (plank[min_1] > plank[min_2])
        {
            swap(min_1, min_2);
        }
        for (int i=2; i < N; ++ i)
        {
            if (plank[i] < plank[min_1])
            {
                min_2 = min_1;
                min_1 = i;
            }
            else if (plank[i] < plank[min_2])
            {
                min_2 = i;
            }
        }
        temp = plank[min_1] + plank[min_2];
        result += temp;
        if (min_1 == N-1)
        {
            swap(min_1, min_2);
        }
        plank[min_1] = temp;
        plank[min_2] = plank[N-1];
        -- N;
    }
    printf("%lld\n", result);
    return 0;
}

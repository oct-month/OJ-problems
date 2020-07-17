// 蚂蚁相遇后朝反方向走可以看做是交错而过

// #include <iostream>
#include <cstdio>
using namespace std;

const int MAX_INT = ((unsigned)(-1))>>1;
const int MIN_INT = ~MAX_INT;

int max(int a, int b)
{
    if (a < b) a = b;
    return a;
}

int max(int a, int b, int c)
{
    if (a < b) a = b;
    if (a < c) a = c;
    return a;
}

int min(int a, int b)
{
    if (a > b) a = b;
    return a;
}

int min(int a, int b, int c)
{
    if (a > b) a = b;
    if (a > c) a = c;
    return a;
}


int main()
{
    int case_num, pole_length, ant_num, left_width;
    scanf("%d", &case_num);
    // cin>>case_num;
    while (case_num--)
    {
        scanf("%d %d", &pole_length, &ant_num);
        // cin>>pole_length>>ant_num;
        int result_min=MIN_INT, result_max=MIN_INT;
        while (ant_num--)
        {
            scanf("%d", &left_width);
            // cin>>left_width;
            int tap = min(left_width, pole_length - left_width);
            result_min = max(tap, result_min);
            result_max = max(result_max, left_width, pole_length - left_width);
        }
        printf("%d %d\n", result_min, result_max);
        // cout<<result_min<<' '<<result_max<<endl;
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, char> Point;

int chessboard[27][27];
Point results[27 * 27];
int n, p, q;

int direct_x[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int direct_y[] = {-2, -2, -1, -1, 1, 1, 2, 2};

// 从（x, y）点开始深搜，（x, y）是第 pos 个点。
bool dfs(int x, int y, int pos)
{
    if (pos == p * q)
        return true;
    int tap_x, tap_y;
    for (int i=0; i < 8; ++ i)
    {
        tap_x = x + direct_x[i];
        tap_y = y + direct_y[i];
        if (tap_x >= 1 && tap_x <= p && tap_y >= 1 && tap_y <= q && chessboard[tap_x][tap_y] == 0)
        {
            chessboard[tap_x][tap_y] = pos + 1;
            if (dfs(tap_x,tap_y , pos + 1))
                return true;
            chessboard[tap_x][tap_y] = 0;
        }
    }
    return false;
}


int main()
{
    bool flag;
    scanf("%d", &n);
    for (int scenario=1; scenario <= n; ++ scenario)
    {
        flag = true;
        scanf("%d %d", &p, &q);
        for (int i=1; i <= p; ++ i)
        {
            memset(chessboard[i], 0, sizeof(chessboard[i]));
        }
        for (int i=1; i <= p && flag; ++ i)
        {
            for (int j=1; j <= q && flag; ++ j)
            {
                chessboard[i][j] = 1;
                if (dfs(i, j, 1))
                    flag = false;
                else
                    chessboard[i][j] = 0;
            }
        }
        if (flag)
            printf("Scenario #%d:\nimpossible\n\n", scenario);
        else
        {
            for (int j=1; j <= q; ++ j)
            {
                for (int i=1; i <= p; ++ i)
                {
                    results[chessboard[i][j]].first = i;
                    results[chessboard[i][j]].second = j + 'A' - 1;
                }
            }
            printf("Scenario #%d:\n", scenario);
            for (int i=1; i <= p * q; ++ i)
            {
                printf("%c%d", results[i].second, results[i].first);
            }
            putchar('\n');
            if (scenario != n)
                putchar('\n');
        }
    }
    return 0;
}

// 这题的坑点在于需要找到字典序最小的输出

#include <cstdio>
using namespace std;

int N, M;
char field[100][100];


void dfs(int x, int y)
{
    if (x >= 0 && x < N && y >=0 && y < M && field[x][y] == 'W')
    {
        field[x][y] = '.';
        dfs(x - 1, y);
        dfs(x - 1, y - 1);
        dfs(x - 1, y + 1);
        dfs(x, y - 1);
        dfs(x, y + 1);
        dfs(x + 1, y);
        dfs(x + 1, y - 1);
        dfs(x + 1, y + 1);
    }
}


int main()
{
    int result = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++ i) 
    {
        scanf("%s", field[i]);
    }
    for (int i = 0; i < N; ++ i)
    {
        for (int j = 0; j < M; ++ j)
        {
            if (field[i][j] == 'W')
            {
                dfs(i, j);
                ++ result;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}


#include <cstdio>
#include <queue>
using namespace std;

struct Point
{
    int x;
    int y;
};


int maze[5][5];
int direct_x[] = {0, 0, -1, 1};
int direct_y[] = {1, -1, 0, 0};
Point pre[5][5];

void bfs()
{
    int tap_x, tap_y;
    queue<Point> Q;
    maze[4][4] = 1;
    Q.push({4, 4});
    while (!Q.empty())
    {
        Point p = Q.front();
        Q.pop();
        if (p.x == 0 && p.y == 0)
            break;
        for (int i=0; i < 4; ++ i)
        {
            tap_x = p.x + direct_x[i];
            tap_y = p.y + direct_y[i];
            if (tap_x >=0 && tap_x < 5 && tap_y >= 0 && tap_y < 5 && maze[tap_x][tap_y] == 0)
            {
                pre[tap_x][tap_y] = p;
                maze[tap_x][tap_y] = 1;
                Q.push({tap_x, tap_y});
            }
        }
    }
}

int main()
{
    for (int i=0; i < 5; ++ i)
    {
        for (int j=0; j < 5; ++ j)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    bfs();
    Point p = {0, 0};
    while (true)
    {
        printf("(%d, %d)\n", p.x, p.y);
        if (p.x == 4 && p.y == 4)
            break;
        p = pre[p.x][p.y];
    }
    return 0;
}

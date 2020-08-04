#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char start[11] = "start";
    char password[201];
    char end[] = "end";
    while (scanf("%s", start) != EOF)
    {
        getchar();
        if (strcmp(start, "ENDOFINPUT") == 0)
            break;
        gets(password);
        // scanf("%s", password);
        int length = strlen(password);
        for (int i=0; i < length; ++ i)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
            {
                password[i] = 'A' + (password[i] - 'A' + 21) % 26;
            }
        }
        scanf("%s", end);
        printf("%s\n", password);
    }
    return 0;
}
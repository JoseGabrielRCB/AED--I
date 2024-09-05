#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int p[1000];

int a()
{
    int l = 0;
    while (l <= 0 || l > 1000)
    {
        scanf("%d", &l);
    }
    return (l);
}

void b(int x)
{
    int i = 0;
    srand(time(NULL));
    while (i < x)
    {
        p[i] = rand() % 100 + 1;
        i++;
    }
}

int c(int i)
{
    int j;
    for (j = 0; j < i; j++)
        printf("%d ", p[j]);
    return (0);
}

int d(int i, int j)
{
    int a = 0, k = 0;
    do
    {
        if (p[k] == i)
            a++;
        k++;
    } while (k < j);
    return (a);
}

void e(int i)
{
    printf("\n\n%d ", i);
}

int main()
{
    int x = a();
    b(x);
    c(x);
    e(d(5, x));
    
    return 0;
}
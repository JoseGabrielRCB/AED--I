// Complemente as partes para a construção de um programa que encontra o maior de três valores.

#include <stdlib.h>
#include <stdio.h>

int maxmin2(int,
            int); // protótipo de função

int maxmin3(int, int, int);
// protótipo de função
int main()
{
    printf("%d",
           maxmin3(5, 9, 2));
    return 0;
}

int maxmin2(int x, int y)
{
    if (x > y)

        return (x);

    else

        return (y);
}

int maxmin3(int x, int y, int z)
{
    return (
        maxmin2(maxmin2(x, y),
                z));
}

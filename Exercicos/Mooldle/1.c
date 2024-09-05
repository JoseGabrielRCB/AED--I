#include <stdlib.h>
#include <stdio.h>



int s(int i) {
    return(i*i);
}

int main()
{
    int x;
    for(x=1;x<=10;x++)
        printf("%d ",s(x));
    return 0;
}

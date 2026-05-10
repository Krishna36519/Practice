#include <stdio.h>

int main()
{
    int nos[3];
    char names[3][15];
    int i;
    
    for(i = 0; i < 3; i++)
    {
        printf("Enter serial number and name %d\n", i+1);
        scanf("%d %14s", &nos[i], names[i]);
        printf("%d %s\n\n", nos[i], names[i]);
    }
    
    return 0;
}
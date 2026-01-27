
#include <stdio.h>

int fac(int argc, char** argv)

{
    int i = 0;
    int num = 4;
    int j = 1;

    for (i = 1; i <= num; i++) 
        j = j * i;
    
        
    printf("The factorial of %d is %d\n", num, j);
}

#include <stdio.h>
#include <stdlib.h>

int getIntRange(int,int);
int main()
{
    printf("%d", getIntRange(100,500));

    return 0;
}

int getIntRange(int min, int max){

    int num;

    printf("Ingrese un numero: ");
    scanf("%d%", &num);

    while(num < min || num > max){

        printf("Error. Ingrese un numero: ");
        scanf("%d%", &num);
    }

    return num;
}



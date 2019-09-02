#include <stdio.h>
#include <stdlib.h>

void changeX(int* );
int main()
{
    int x = 5;

    changeX(&x);

    printf("%d",x);



    return 0;
}


void changeX(int* puntero){

    int num;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    *puntero = num;

}

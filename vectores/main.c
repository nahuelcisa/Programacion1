#include <stdio.h>
#include <stdlib.h>

void MostrarVectorInt (int vec[], int tam);
void MostrarVectorChar (char vec[], int tam);
void MostrarVectorFloat (float vec[], int tam);

int main()
{
    int numeros[] = {23,21,43,54,28,21,66,88,32};
    char x [] = {'a','e','i','o','u'};
    float reales [] = {23.5,56.34,55.1,89.7,90.9,10.10};

    MostrarVectorInt(numeros,10);
    MostrarVectorChar(x,5);
    MostrarVectorFloat(reales,6);


    return 0;
}

void MostrarVectorInt (int vec[], int tam){

for(int i=0;i<tam;i++){

    printf("%d ",vec[i]);
}
    printf("\n\n");
}

void MostrarVectorChar(char vec[], int tam){

for(int i=0;i<tam;i++){

    printf("%c ",vec[i]);
}
    printf("\n\n");
}


void MostrarVectorFloat(float vec[], int tam){

for(int i=0;i<tam;i++){

    printf("%.2f ",vec[i]);
}
    printf("\n\n");
}



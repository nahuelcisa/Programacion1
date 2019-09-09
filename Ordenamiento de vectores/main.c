#include <stdio.h>
#include <stdlib.h>

#define TAM 5 //DECLARAR CONSTANTES

void MostrarVectorInt (int vec[], int tam);

void ordenarVectorInt(int vec[], int tam, int criterio);

int main()
{

    int vec[TAM] = {7,5,8,1,3};


    printf("Vector sin ordenar \n\n");

    MostrarVectorInt(vec,TAM);


    ordenarVectorInt(vec,TAM,0);

    printf("Vector odenado Mayor a menor \n\n");
    MostrarVectorInt(vec,TAM);

    ordenarVectorInt(vec,TAM,1);
    printf("Vector ordenado Menor a mayor \n\n");
    MostrarVectorInt(vec,TAM);

    return 0;
}

void ordenarVectorInt(int vec[], int tam, int criterio)
{

    int aux;
    for(int i = 0; i < tam-1 ; i++)
    {

        for(int j = i + 1; j < tam; j++)
        {


            if(vec[j] > vec[i] && !criterio)
            {

                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }

            else if(vec[j] < vec[i] && criterio)
            {

                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }

        }

    }

}

void MostrarVectorInt (int vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {

        printf("%d ",vec[i]);
    }
    printf("\n\n");
}

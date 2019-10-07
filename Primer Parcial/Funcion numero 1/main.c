#include <stdio.h>
#include <stdlib.h>
float aplicarDescuento(float precio);

int main()
{
    float precio;


    printf("Ingrese precio: ");
    scanf("%f",&precio);

    precio = aplicarDescuento(precio);

    printf("\nEl descuento aplicado fue del 5% y el nuevo precio es : %.2f\n\n",precio);

    return 0;
}

float aplicarDescuento(float precio){

    float preciofinal;
    float descuento;

    descuento = (precio*5)/100;

    preciofinal = precio - descuento;
    return preciofinal;
}

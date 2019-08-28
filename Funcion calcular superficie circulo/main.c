#include <stdio.h>
#include <stdlib.h>

float calcularSupCirculo(float radio);
int main()
{
    float radio;
    float superficie;


    printf("Ingrese el radio del circulo que desea calcular la superficie: ");
    fflush(stdin);
    scanf("%f", &radio);
    system("pause");
    superficie = calcularSupCirculo(radio);
    printf("La superficie del circulo es %.2f \n \n",superficie);

    return 0;
}


float calcularSupCirculo(float radio){

    float superficie;

    superficie = ((radio*radio)* 3.1415926);

    return superficie;

}

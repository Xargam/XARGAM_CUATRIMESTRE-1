#include <stdio.h>
#include <stdlib.h>

int main()
{
    float precio;
    int descuento;
    float descuentoFinal;
    float precioDescuento;
    float IVA;
    float precioFinal;

    printf("Ingrese un precio:\n");
    scanf("%f",&precio);
    fflush(stdin);

    printf("Ingrese porcentaje de descuento:\n");
    scanf("%d",&descuento);

    descuentoFinal =(float) precio * descuento / 100;
    precioDescuento = precio - descuentoFinal;

    IVA = precioDescuento * 0.21;
    precioFinal = precioDescuento + IVA;

    printf("El precio final con I.V.A. incluido es: $%.2f.\n",precioFinal);
    printf("El precio con descuento aplicado sin I.V.A. incluido es: $%.2f\n",precioDescuento);
    printf("El importe correspondiente al I.V.A. es $%.2f\n", IVA);
    printf("El descuento que usted aplico al precio corresponde a: $%.2f\n",descuentoFinal);

    return 0;
}

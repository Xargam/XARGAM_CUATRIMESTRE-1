#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroVendedor;
    float ImporteVentas;
    float acumulador;
    float ganancia;

    while(ImporteVentas > 0)
    {
        printf("Ingrese numero de vendendor: ");
        scanf("%d", &numeroVendedor);
        setbuf(stdin, NULL);

        while(numeroVendedor < 1 || numeroVendedor > 3)
        {
            printf("\nEl numero de vendedor debe estar entre 1 y 3 inclusive, reingresar: ");
            scanf("%d", &numeroVendedor);
            setbuf(stdin, NULL);
        }

        printf("\nIngrese el importe de sus ventas: ");
        scanf("%f", &ImporteVentas);
        setbuf(stdin, NULL);

        while(ImporteVentas < 0)
        {
            printf("\nImporte invalido, reingresar: ");
            scanf("%f", &ImporteVentas);
            setbuf(stdin, NULL);
        }

        acumulador += ImporteVentas;

    }

    ganancia = acumulador - (acumulador * 0.05);

    printf("\nLa ganancia para usted corresponde a $%f",ganancia);







return 0;
}

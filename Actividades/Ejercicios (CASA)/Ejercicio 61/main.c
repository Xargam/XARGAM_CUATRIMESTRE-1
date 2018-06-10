#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mes, dia, i;
    printf("Seleccione la cantidad de dias que tiene el mes a tener en cuenta: ");
    scanf("%d",&mes);
    setbuf(stdin,NULL);
    while(mes < 1)
    {
        printf("Error: pocos dias, reingrese:\n");
        scanf("%d",&mes);
        setbuf(stdin,NULL);

    }

    printf("\n");
    float compras[mes], max;

    for(i = 0; i < mes; i++)
    {
        printf("Ingrese los gastos del dia %d: $",i+1);
        scanf("%f",&compras[i]);
        printf("\n");
        setbuf(stdin,NULL);
        if(i == 0)
        {
            max = compras[0];
            dia = 1;
        }

        while(compras[i] < 0)
        {
            printf("Gasto invalido reingrese:\n");
            scanf("%f",&compras[i]);
            setbuf(stdin, NULL);

        }

    }

    for(i = 0; i < mes; i++)
    {
        if(compras[i] > max)
        {
            max = compras[i];
            dia = i+1;
        }
    }
    printf("El dia de mayor gasto fue el dia %d en el que gastaste $%.2f!!",dia,max);

    return 0;
}

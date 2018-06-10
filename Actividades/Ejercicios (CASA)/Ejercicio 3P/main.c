#include <stdio.h>
#include <stdlib.h>
#define CANT 3

/* 3-	De los 30 empleados de una fábrica se registra la edad, el sexo y el legajo. Terminado el ingreso se pide conocer:
•	La edad promedio de los empleados de la fábrica.
•	El legajo y sexo de la persona de mayor edad.
•	Cuantas mujeres nacieron en el año 1978. */



int main()
{
    int edades[CANT];
    char sexo[CANT];
    int legajos[CANT];

    int mayor;
    char sexoDelMayor;
    int LegajoDelMayor;
    int flag = 0;
    int contadorMujeres78 = 0;
    int contador = 0;
    int acumulador = 0;
    float promedio;

    int i ;


    for( i = 0 ; i < CANT ; i++ )
    {
        contador++;
        printf("Ingrese edad del empleado %d: ", i+1);
        scanf("%d", edades + i );
        fflush(stdin);

        printf("\n\nIngrese sexo del empleado %d: ", i+1);
        *(sexo + i) = getche(sexo + i);
        fflush(stdin);

        printf("\n\nIngrese legajo del empleado %d: ", i+1);
        scanf("%d", legajos + i);

        acumulador += *(edades + i);

        if(flag == 0)
        {
            mayor = *(edades + i);
            sexoDelMayor = *(sexo + i );
            LegajoDelMayor = *(legajos + i);
            flag++;
        }
        else if( *(edades + i) > mayor)
        {
            mayor = *(edades + i);
            sexoDelMayor = *(sexo + i );
            LegajoDelMayor = *(legajos + i);
        }


        if( *(sexo + i) == 'f' && *(edades + i) == 40)
        {
            contadorMujeres78++;
        }
    }

    promedio = (float) acumulador / contador;
    printf("\nEn el año 1978 nacieron %d mujeres.\n", contadorMujeres78);
    printf("\nLa persona mas grande tiene %d anios , es de sexo %c y su legajo es %d", mayor, sexoDelMayor , LegajoDelMayor);
    printf("\nEdad promedio de los empleados de la fábrica: %.2f",promedio);

    return 0;
}

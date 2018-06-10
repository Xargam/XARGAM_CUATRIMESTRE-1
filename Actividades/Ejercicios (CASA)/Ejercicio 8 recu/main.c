#include <stdio.h>
#include <stdlib.h>

char pedirNombre();
int pedirPaginas();
int pedirVentas();
char pedirTemas();
int paginasPares(int pags);
int paginasImpares(int pags);

int i = 0;



int main()
{
    char nombre[41];
    int ventas;
    char tema[18];
    int respuesta;
    int paginas;
    int contadorPagsPares = 0;
    int contadorPagsImpares = 0;
    int contadorVenta0 = 0;

    int acumuladorVentas = 0;
    int acumuladorPaginas = 0;
    float promedio;



    while(respuesta != 0)
    {
        i++;
        nombre[41] = pedirNombre();
        tema[18] = pedirTemas();
        paginas = pedirPaginas();
        ventas = pedirVentas();

        if(ventas == 0)
        contadorVenta0++;

        acumuladorVentas += ventas;

        if(tema[18] == 'programacion')
        acumuladorPaginas += paginas;

        contadorPagsPares += paginasPares(paginas);
        contadorPagsImpares += paginasImpares(paginas);
        printf("Para finalizar escriba 0.\n");
        scanf("%d", &respuesta);


        return 0;

    }
    promedio =(float) acumuladorVentas / i;

    printf("a) Hay %d libros con paginas pares.\n",contadorPagsPares);
    printf("b) Hay %d libros con paginas impares.\n",contadorPagsImpares);
    printf("c) Hubo %d libros con 0 ventas.\n",contadorVenta0);
    printf("d) El promedio de las ventas ingresadas es %f\n",promedio);
    printf("e) Los libros de programacion suma %d paginas.\n",acumuladorPaginas);




}


char pedirNombre()
{
    char N[41];
    printf("Ingrese el nombre del libro: %d\n", i);
    scanf("%s",N);
    setbuf(stdin, NULL);
    return N[41];

}

char pedirTemas()
{
    char T[18];
    do
    {
        printf("Ingrese el tema del libro %d (robotica, programacion, patrones o base de datos):\n", i);
        scanf("%s",T);
        setbuf(stdin, NULL);
    }
    while(T[18] != 'robotica' && T[18] != 'programacion' && T[18] != 'patrones' && T[18] != 'base de datos');

    return T[18];

}

int pedirPaginas()
{
    int CP;

    printf("Ingrese la cantidad de paginas del libro: %d\n", i);
    scanf("%d",&CP);
    setbuf(stdin, NULL);

    return CP;
}

int pedirVentas()
{
    int V;
    do
    {
        printf("Ingrese la cantidad de ventas que ha tenido el libro:(No menos de 0)\n");
        scanf("%d", &V);
        setbuf(stdin, NULL);

    }
    while(V < 0);

    return V;
}

int paginasPares(int pags)
{
    if(pags % 2 == 0)
    {
        return 1;
    }
    else
    {
        return  0;
    }
}

int paginasImpares(int pags)
{
    if(pags % 2 != 0)
    {
        return 1;
    }
    else
    {
        return  0;
    }

}


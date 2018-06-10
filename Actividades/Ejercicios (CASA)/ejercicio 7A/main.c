#include <stdio.h>
#include <stdlib.h>

/*
7-	Realizar un programa que me permita trabajar con el archivo de operaciones de un banco.
 El archivo inicialmente contiene datos cargados con formato Struct banco. Todas las operaciones
 que se realizan deben quedar registradas en el archivo.

Struct banco {
		Int operación;		 1- Depósito, 2- Extracción.
		Float monto;		 cantidad de dinero a depositar o extraer
		Char clave[5];		 clave del usuario para las transacciones ( 4 dígitos )
	         }

Se debe contar con un menú de opciones como el siguiente
1-	Depósitos
2-	Extracciones
3-	Saldo
4-	Salir
*/

typedef struct
{
    int operacion;
    float monto;
    char clave[5];

} eBanco ;


int main()
{
    printf("Hello world!\n");
    return 0;
}

eBanco* nuevoBanco(void)
{
    eBanco* bank = malloc(sizeof(eBanco));
}

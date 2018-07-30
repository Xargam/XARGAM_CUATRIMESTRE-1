#include <stdio.h>
#include <stdlib.h>
#include "xget.h"
#include "xlook.h"
#include "xvalidate.h"

#include "xClientes.h"



//FUNCIONES



/** \brief Pide datos de un cliente .
 *
 * \return Devuelve un puntero a clientes cargado de datos en caso de error devuelve NULL.
 *
 */

eClientes* clientes_pedirDatos(void)
{
    eClientes* cliente = clientes_nuevoCliente(1);
    if( cliente != NULL)
    {
        long dni;
        int verify;
        do
        {
            verify = 0;
            if( getValidLong(&dni,"Ingrese su DNI: ","El numero de DNI no es valido.") && clientes_setDni(cliente,dni,XLK_INVALID_DATA) )
            {
                verify=1;
            }
        }
        while(verify == 0 );

    }
    return cliente;
}



/** \brief Reserva espacio dinamico para un array de de clientes.
 *
 * \param size : Cantidad de elementos del array.
 * \return Devuelve un puntero a clientes.
 *
 */

eClientes* clientes_nuevoCliente(int cantidad)
{
    eClientes* cliente = NULL;
    if( cantidad > 0)
    {
        cliente =(eClientes*) malloc(sizeof(eClientes)*cantidad);
    }
    return cliente;
}



/** \brief Setea el DNI en un puntero a clientes .
 *
 * \param cliente : Puntero a clientes .
 * \param num : el DNI a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error .
 *
 */

int clientes_setDni( eClientes* cliente, long dni, char* eMessage )
{
    int verify = 0;
    if( cliente != NULL && eMessage != NULL )
    {
        if( validateLongRange(dni,1000000,48000000) )
        {
            verify = 1;
            cliente->dni = dni;
        }
        else
        {
            printf("** %s",eMessage);
            xlkEnterPrinter(2);
        }
    }
    return verify;
}


/** \brief Muestra un cliente.
 *
 * \param Variable de tipo cliente a mostrar.
 * \return Devuelve [1] si se pudo mostrar el dato o [0] en caso de error.
 *
 */

int clientes_mostrarCliente(eClientes* cliente , int turn)
{
    int verify = 0;
    if( cliente != NULL)
    {
        verify = 1;
        xlkSortPrintf(2,"%s,%s",2,"DNI:","NUMERO DE TURNO:");
        xlkSortPrintf(1,"%ld,%d",2,cliente->dni,turn);
    }
    return verify;
}



/** \brief Compara el DNI de dos clientes.
 *
 * \param cliente1 : Puntero de tipo clientes a comparar con el segundo.
 * \param cliente2 : Puntero de tipo clientes que sera comparado con el primero.
 * \return Devuelve [1] si el primer cliente es mayor, [0] si son iguales o [-1] si el primer cliente es menor.
 *
 */

int clientes_compararDNI(void* cliente1 ,void* cliente2)
{
    int verify = 0;

    if(((eClientes*)cliente1)->dni > ((eClientes*)cliente2)->dni )
    {
        verify = 1;
    }
    if(((eClientes*)cliente1)->dni < ((eClientes*)cliente2)->dni)
    {
        verify = -1;
    }
    return verify;
}



/** \brief Setea un el numero de turno en un puntero a clientes .
 *
 * \param cliente : Puntero a clientes .
 * \param turn : turno a setear .
 * \param eMessage : Mensaje de error a mostrar si el dato a setear no es valido .
 * \return Devuelve [1] si el dato fue seteado o [0] en caso de error .
 *
 */

int clientes_setTurno( eClientes* cliente, int turn , char* eMessage )
{
    int verify = 0;
    if( cliente != NULL && eMessage != NULL )
    {
        if(validateIntCondition(turn,1 , 1) )
        {
            verify = 1;
            cliente->NumeroTurno = turn;
        }
        else
        {
            printf("** %s",eMessage);
            printf("\n\n");
        }
    }
    return verify;
}

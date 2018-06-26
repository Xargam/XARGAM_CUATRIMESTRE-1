#include <stdio.h>
#include <stdlib.h>
#include "xget.h"
#include "xlook.h"

//Estructuras:

typedef struct
{
    long dni;
    int turno;

} eClientes;



//FUNCIONES



/** \brief Reserva espacio dinamico para un array de de clientes.
 *
 * \param size : Cantidad de elementos del array.
 * \return Devuelve un puntero a clientes.
 *
 */

eClientes* nuevoCliente(int size)
{
    eClientes* cliente = NULL;
    if( size > 0)
    {
        cliente = malloc(sizeof(eClientes)*size);
    }
    return cliente;
}

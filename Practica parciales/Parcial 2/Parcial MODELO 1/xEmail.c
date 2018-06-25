#include <stdio.h>
#include <stdlib.h>
#include "xGenericStruct.h"
#include "xEmail.h"

/** \brief Reserva espacio dinamico para un array de destinatarios .
 *
 * \param size : Cantidad de elementos.
 * \return devuelve un puntero a un array de destinatarios .
 *
 */

eAdresseers* newAdresseer(int size)
{
    eAdresseers* destinatarios = NULL;
    if( size > 0)
    {
        destinatarios = (eAdresseers*)malloc(sizeof(eAdresseers)*size);
    }
    return destinatarios;
}

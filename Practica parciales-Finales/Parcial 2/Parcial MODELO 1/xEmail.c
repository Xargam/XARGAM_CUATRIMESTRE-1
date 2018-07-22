#include <stdio.h>
#include <stdlib.h>

#include "xGenericStruct.h"
#include "xArrayList.h"

#include "xFiles.h"
#include "xEmail.h"
#include "xlook.h"

/** \brief Reserva espacio dinamico para un array de destinatarios .
 *
 * \param size : Cantidad de elementos.
 * \return devuelve un puntero a un array de destinatarios .
 *
 */

eDestinatarios* xmailNewDestinatario(int size)
{
    eDestinatarios* destinatarios = NULL;
    if( size > 0)
    {
        destinatarios = (eDestinatarios*)malloc(sizeof(eDestinatarios)*size);
    }
    return destinatarios;
}



/** \brief Muestra un destinatario.
 *
 * \param Variable de tipo destinatario a mostrar.
 * \return Devuelve [1] si se pudo mostrar el dato o [0] en caso de error.
 *
 */

int xmailMostrarDestinatario(eDestinatarios* dest )
{
    int verify = 0;
    if( dest != NULL)
    {
        verify = 1;
        xlkSortPrintf(3,"%s,%s",2,dest->name,dest->email);
    }
    return verify;
}



/** \brief Parsea un archivo de texto con destinatarios y carga los en un arrayList.
 *
 * \param filePath : Nombre o ruta del archivo a parsear.
 * \param this : Variable de tipo arrayLis.
 * \return Devuelve [1] si el parseo se completo correctamente o [0] si hubo algun error.
 *
 */

int xmailParser( char* filePath, arrayList* this  )
{
    int verify = 0;
    if( filePath != NULL && this != NULL)
    {
        FILE* file = fopen(filePath,"r");
        if( file != NULL )
        {
            int reading;
            eDestinatarios* dest = NULL;
            do
            {
                if( dest != NULL )
                {
                    if( this->add(this,dest))
                    {
                        break;
                    }
                }
                dest =(eDestinatarios*) malloc(sizeof(eDestinatarios));
            }
            while( dest != NULL && (reading = xfilCSVGenericParser(file,2,"%s;%s;",2,dest->name,dest->email)) == 1 );
            if( dest != NULL)
            {
                free(dest);
            }
            if( !fclose(file) && reading == 0 && dest != NULL )
            {
                verify = 1;
            }
        }
    }
    return verify;
}



/** \brief verifica que el email de un destinatario no sea igual al de otro.
 *
 * \param dest1 : Destinatario el cual se comparara email con dest2.
 * \param dest2 : El email se comparara con dest1.
 * \return Devuelve [1] si los emails son iguales o [0] en caso de desigualdad o [-1] en caso de error.
 *
 */
 int xmailComparaEmail(void* dest1 ,void* dest2  )
{
    int verify = -1;
    if( dest1 != NULL && dest2 != NULL)
    {
        verify = 0;
        if( strcmp( ((eDestinatarios*)dest1)->email , ((eDestinatarios*)dest2)->email ) == 0  )
        {
            verify = 1;
        }
    }
    return verify;
}


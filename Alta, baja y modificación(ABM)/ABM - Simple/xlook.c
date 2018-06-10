#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


//Generadores de menus completos:


//XL1-1
/** \brief Genera un menu con la cantidad de opciones y texto a eleccion.
 *
 * \param head: Encabezado del menu.
 * \param totalOptions: se coloca un entero que indica la cantidad de opciones a generar
 * \param Se agregan parametros con string para las opciones, segun la cantidad elegida.
 *
 */

void xlkIndexGenerator(char head[],int totalOptions,...)
{
    system("cls");
    int i;
    va_list arguments;
    va_start(arguments,totalOptions);
    printf("#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
    printf("  *%s\n                                                                           ",head);
    printf("\n#*---*---*---*---*---*---*---*---*---*----*---*---*---*---*---*---*---*---*---*#\n");
    printf("###########____________________________________________________________________#\n"    );
    printf("   MENU:\n\n"                                                                          );
    printf("###########____________________________________________________________________#\n"  );
    for(i = 0; i < totalOptions; i++)
    {
        printf("-  %s\n",va_arg(arguments,int));
    }
    printf("\n############___________________________________________________________________#\n");
    va_end(arguments);
}



//Generadores de fragmentos de menu:


//XL1-2
/** \brief Recuadra un texto con un diseño agradable para utilizarlo como encabezado destacado.
 *
 * \param text: texto a encuadrar.
 * \return
 *
 */
void xlkHeadGenerator(char text[])
{
    system("cls");
    printf("\\/  \\/   \\/  \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/\n");
    printf(" ** %s\n\n",text);
    printf("/\\  /\\   /\\  /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\\n");
    printf("________________________________________________________________________________\n");
}


//XL1-3
/** \brief Genera un listado de opciones de cantidad variable sin encabezado.
 *
 * \param totalOptions: cantidad de opciones del listado.
 * \param ... Se colocan tantos argumentos como cantidad de opciones con texto a mostrar.
 * \return
 *
 */
void xlkIndexBodyGenerator(int totalOptions,...)
{
    va_list arguments;
    va_start(arguments,totalOptions);
    printf("________________________________________________________________________________\n");
    for(int i=0; i < totalOptions; i++)
    {
        printf(" * %s\n",va_arg(arguments,int));
    }
    printf("________________________________________________________________________________\n\n");
    va_end(arguments);
}


//XL1-4
/** \brief Recuadra un texto con un diseño agradable sin lineas debajo.
 *
 * \param text: texto a encuadrar.
 * \return
 *
 */
void xlkNoLineHeadGenerator(char text[])
{
    system("cls");
    printf("\\/  \\/   \\/  \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/   \\/\n");
    printf(" ** %s\n\n",text);
    printf("/\\  /\\   /\\  /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\   /\\\n");
}


//XL1-5
/** \brief Genera un listado de opciones de cantidad variable sin encabezado y sin lineas superiores.
 *
 * \param totalOptions: cantidad de opciones del listado.
 * \param ... Se colocan tantos argumentos como cantidad de opciones con texto a mostrar.
 * \return
 *
 */
void xlkNoLineIndexBodyGenerator(int totalOptions,...)
{
    va_list arguments;
    va_start(arguments,totalOptions);
    for(int i=0; i < totalOptions; i++)
    {
        printf(" * %s\n",va_arg(arguments,int));
    }
    printf("________________________________________________________________________________\n\n");
    va_end(arguments);
}

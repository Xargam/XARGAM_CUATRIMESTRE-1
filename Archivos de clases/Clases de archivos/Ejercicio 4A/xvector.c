#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Funciones de busqueda de numero maximo o minimo:


//XV1-1
/** \brief Busca el numero maximo o minimo de un vector de enteros.
 *
 * \param vec: vector en el que se buscara.
 * \param elements: Cantidad de elementos del vector pasado por la funcion
 * \param criterio: -1 para buscar el menor elemento del vector y 1 para encontrar el maximo.
 * \return devuelve el numero maximo o minimo del vector.
 *
 */

int xvecIGetMaxMin(int vec[], int elements, int criterio)
{
    int mayorMenor = vec[0];

    if(criterio == 1)
    {
        for(int i = 0; i < elements; i++)
        {
            if(vec[i] > mayorMenor)
            {
                mayorMenor = vec[i];
            }
        }
    }
    else if(criterio == -1)
    {
        for(int i = 0; i < elements; i++)
        {
            if(vec[i] < mayorMenor)
            {
                mayorMenor = vec[i];
            }
        }

    }
    return mayorMenor;
}


//XV1-2
/** \brief Busca el numero maximo o minimo de un vector de flotantes.
 *
 * \param vec: vector en el que se buscara.
 * \param elements: Cantidad de elementos del vector pasado por la funcion.
 * \param criterio: 1 para buscar el mayor elemnto del vector y -1 para encontrar el minimo.
 * \return devuelve el numero maximo o minimo de vector.
 *
 */

float xvecFGetMaxMin(float vec[], int elements, int criterio)
{
    float mayorMenor = vec[0];

    if(criterio == 1)
    {
        for(int i = 0; i < elements; i++)
        {
            if(vec[i] > mayorMenor)
            {
                mayorMenor = vec[i];
            }
        }
    }
    else if(criterio == -1)
    {
        for(int i = 0; i < elements; i++)
        {
            if(vec[i] < mayorMenor)
            {
                mayorMenor = vec[i];
            }
        }

    }
    return mayorMenor;
}



//Funciones de ordenamiento:


//XV1-3
/** \brief Ordena elementos de un vector de enteros segun criterio
 *
 * \param vec: vector de enteros que se ordenara.
 * \param elements: Cantidad de elementos que contiene el vector.
 * \param criterio: 1 para ordenar de mayor a menor y -1 de menor a mayor.
 * \return
 *
 */

void xvecISort(int vec[], int elements, int criterio)
{
    for(int i = 0; i < elements - 1; i++)
    {
        for(int j = i+1; j < elements; j++)
        {
            if(criterio == 1)
            {
                if(vec[j] > vec[i])
                {
                    int aux;
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }

            }
            else if(criterio == -1)
            {
                if(vec[j] < vec[i])
                {
                    int aux;
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}


//XV1-4
/** \brief Ordena elementos de un vector de flotantes segun criterio
 *
 * \param vec: vector de flotantes que se ordenara
 * \param elements: Cantidad de elementos que puede contener el vector
 * \param criterio: -1 para ordenar de menor a mayor y 1 de mayor a menor.
 * \return
 *
 */

void xvecFSort(float vec[], int elements, int criterio)
{
    for(int i = 0; i < elements - 1; i++)
    {
        for(int j = i+1; j < elements; j++)
        {
            if(criterio == 1)
            {
                if(vec[j] > vec[i])
                {
                    float aux;
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }

            }
            else if(criterio == -1)
            {
                if(vec[j] < vec[i])
                {
                    float aux;
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}



//Funciones de muestra:


//XV1-5
/** \brief muestra los elementos de un vector de enteros con un mensaje
 *
 * \param vec: Vector de enteros a ser mostrado.
 * \param cantidad de elementos del vector
 * \param message: Mensaje a ser mostrado antes de los elementos del vector
 * \return
 *
 */

void xvecIShow(int vec[],int elements,char message[])
{
    printf("%s",message);
    for(int i = 0; i < elements;i++)
    {
        printf("%d\n",vec[i]);
    }
}


//XV1-6
/** \brief muestra los elementos de un vector de flotantes con un mensaje.
 *
 * \param vec: Vector de flotantes a ser mostrado.
 * \param cantidad de elementos del vector
 * \param message: Mensaje a ser mostrado antes de los elementos del vector.
 * \return
 *
 */

void xvecFShow(float vec[],int elements,char message[])
{
    printf("%s",message);
    for(int i = 0; i < elements;i++)
    {
        printf("%.2f  ",vec[i]);
    }
}



//Funciones de swapeo:


//XV1-7
/** \brief intercambia los valores de dos variables enteras
 *
 * \param var1: variable entera 1
 * \param var2: variable entera 2
 * \return
 *
 */

void xvecISwap(int* var1,int* var2)
{
    int aux;
    int A = *var1;
    int B = *var2;
    aux = A;
    A = B;
    B = aux;

    *var1 = A;
    *var2 = B;
}


//XV1-8
/** \brief intercambia los valores de dos variables flotantes
 *
 * \param var1: variable flotante 1
 * \param var2: variable flotante 2
 * \return
 *
 */
void xvecFSwap(float* var1,float* var2)
{
    float aux;
    float A = *var1;
    float B = *var2;
    aux = A;
    A = B;
    B = aux;
    *var1 = A;
    *var2 = B;
}


//XV1-9
/** \brief intercambia los valores de dos cadenas
 *
 * \param cad1: cadena 1
 * \param cad2: cadena 2
 * \return
 *
 */
void xvecSSwap(char cad1[],char cad2[])
{
    char aux[1000];
    strcpy(aux,cad1);
    strcpy(cad1,cad2);
    strcpy(cad2,aux);
}



//Funciones de busqueda de espacio (Elemento 0):


//XV2-1
/** \brief Revisa un vector de enteros y busca el indice de una posicion vacia.
 *
 * \param vector: Se ingresa el vector a analizar.
 * \param elements: Cantidad de elementos que contiene el vector.
 * \return Devuelve el numero de indice que tenga espacio libre,
 * \return si no hay espacio en ninguno devuelve -1.
 *
 */
int xvecISpaceF(int vec[],int elements)
{
    int index = -1;
    for(int i = 0; i < elements; i++)
    {
        if(vec[i] == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


//XV2-2
/** \brief Revisa un vector de flotantes y busca el indice de una posicion vacia.
 *
 * \param vector: Se ingresa el vector a analizar.
 * \param elements: Cantidad de elementos que contiene el vector.
 * \return Devuelve el numero de indice que tenga espacio libre,
 * \return si no hay espacio en ninguno devuelve -1.
 *
 */
int xvecFSpaceF(float vec[],int elements)
{
    int index = -1;
    for(int i = 0; i < elements; i++)
    {
        if(vec[i] == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

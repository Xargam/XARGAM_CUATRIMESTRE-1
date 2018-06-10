#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xPerson.h"
#include "string.h"
#include "xvector.h"
#include "xvalidate.h"
#include "xget.h"
#include "xstring.h"
#include "xlook.h"

//FUNCIONES BASICAS:


//XP1-1
/** \brief harcodea las primeras 6 posiciones de un vector personas.
 *
 * \param per : vector de personas a hardcodear.
 * \return
 *
 */

void hardcode(ePerson per[])
{
    per[0].age = 25;
    strcpy(per[0].name,"Francisco");
    per[0].dni = 40050761;
    per[0].status = 1;

    per[1].age = 10;
    strcpy(per[1].name,"Nahuel");
    per[1].dni = 40050700;
    per[1].status = 1;

    per[2].age = 10;
    strcpy(per[2].name,"Daniela");
    per[2].dni = 40050710;
    per[2].status = 1;

    per[3].age = 45;
    strcpy(per[3].name,"Leonardo");
    per[3].dni = 40050720;
    per[3].status = 1;

    per[4].age = 20;
    strcpy(per[4].name,"Anibal");
    per[4].dni = 40050730;
    per[4].status = 1;

    per[5].age = 37;
    strcpy(per[5].name,"Tomas");
    per[5].dni = 40050750;
    per[5].status = 1;
}


//XP1-2
/** \brief Inicializa los estados de un vector de personas en 0.
 *
 * \param per : vector de personas a inicializar.
 * \param elements: cantidad de elementos del vector de personas.
 * \return
 *
 */

void initializePersons(ePerson per[], int elements)
{
    for(int i = 0; i < elements ; i++)
    {
        per[i].status = 0;
    }
}



//ABM DEPENDENCIAS:


//XP1-3
/** \brief Busca por dni a una persona dentro de un vector de personas.
 *
 * \param per : vector de personas a recorrer.
 * \param elements : cantidad de elementos del vector de personas.
 * \param dni : dni a buscar dentro del vector.
 * \return Devuelve el indice si encuentra una persona que coincida con el dni pasado a la funcion sino devuelve -1.
 *
 */

int searchByDNI(ePerson per[], int elements, int dni)
{
    int index = -1;
    for(int i=0; i < elements; i++)
    {
        if(per[i].status == 1 && per[i].dni == dni)
        {
            index = i;
            break;
        }
    }
    return index;
}


//XP1-4
/** \brief Busca un indice libre en un vector de personas.
 *
 * \param per: Vector de personas a recorrer.
 * \param elements: cantidad de elementos del vector de personas.
 * \return devuelve el numero del primer indice libre que encuentre sino hay espacio devuelve -1.
 *
 */

int searchSpace(ePerson per[],int elements)
{
    int index = -1;
    for(int i = 0; i < elements; i++)
    {
        if(per[i].status == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


//XP1-5
/** \brief Pide los datos de una persona a exepcion del dni.
 *
 * \return devuelve una variable de tipo ePerson con datos cargados.
 *
 */

ePerson getPerson(void)
{
    ePerson newPerson;
    char name[30];

    newPerson.age = getRangedInt(0,150,"Ingrese edad de la persona: ","\nError, numero muy grande o demasiado chico, reingrese: ");
    getRangedStr(2,29,"\nIngrese nombre de la persona: ","\nNombre demasiado largo o invalido, reingrese: ",name);

    xstrCapsSpaceFixer(name);
    xstrCapsAdder(name);

    strcpy(newPerson.name,name);

    newPerson.status = 1;

    return newPerson;
}



//FUNCIONES PARA ALTA BAJA Y MODIFICACION:



//XP1-6
/** \brief Da de alta una nueva persona en el sistema.
 *
 * \param per: Vector de persona donde dar de alta la nueva persona.
 * \param  elements: Cantidad de elementos del vector de personas.
 * \return devuelve 1 si la persona se dio de alta, 0 si el dni que se intento cargar ya existe o -1 si no hay espacio.
 *
 */

int newPerson(ePerson per[], int elements)
{
    long dni;
    int verify = -1;
    int freeIndex;
    int dniVerify;

    freeIndex = searchSpace(per,elements);

    if(freeIndex != -1)
    {
        dni = getRangedLong(1000000, 54999999,"\nIngrese DNI de la persona, sin puntos: ","\nUn DNI debe tener 7 u 8 digitos.\nAdemas el numero debe ser menor a 55 millones y mayor a 999.999 .\nNo use puntos. Reingrese: ");
        dniVerify = searchByDNI(per,elements,dni);
        if(dniVerify == -1)
        {
            printf("\n  -DNI dado de alta en el sistema.\n\n");
            per[freeIndex] = getPerson();
            per[freeIndex].dni = dni;
            verify = 1;
        }
        else
        {
            verify = 0;
        }
    }

    return verify ;
}


//XP1-7
/** \brief Daa de baja a una persona del sistema.
 *
 * \param per : Vector de personas donde buscar personas a dar de baja.
 * \param elements: Cantidad de elementos del vector de personas.
 * \return Devuelve 1 si una persona se dio de baja, 0 si se encontro una pero no se dio de baja o -1 si no se encontro ninguna persona.
 *
 */

int deletePerson(ePerson per[],int elements)
{
    long dni;
    int verify = -1;
    int dniVerify;

    showPeople(per,elements);
    if(inputGetLong(&dni,"Ingrese dni de la persona a eliminar: ","",1000000,54999999) == 1)
    {
        dniVerify = searchByDNI(per,elements,dni);
        if(dniVerify > -1 )
        {
            system("cls");
            verify = 0;
            printf("*Dara de baja a la siguiente persona: \n");
            showAPerson(per[dniVerify]);
            if(validateDualExit("\nConfirmar baja? s/n: ","\nError: no se reconoce su respuesta.\n Reingrese: ",'s','n') == 1)
            {
                per[dniVerify].status = 0;
                verify = 1;
            }
        }
    }
    return verify;
}

/*
//XP1-8
 \brief Modifica a una persona de un vector de personas.
 *
 * \param per : vector de personas a recorrer.
 * \param elements: cantidad de elementos del vector de personas.
 * \return devuelve 1 si se modifico a una persona, 0 si no se modifico pero se encontro una persona o -1 si no se encontro ninguna persona.
 *


int modifyPerson(ePerson per[],int elements)
{
    long dni;
    int age;
    int exit = 0;
    char name[30];
    int dniVerify;
    int dniVerify2;
    int verify = -1;
    int selection;

    printf("Lista de personas: ");
    showPeople(per,elements);
    if(inputGetLong(&dni,"\nIngrese dni de la persona a modificar: ","",1000000, 54999999) == 1)
    {
        dniVerify = searchByDNI(per,elements,dni);
        if(dniVerify > -1)
        {
            verify = 0;
            system("cls");
            printf("Va a modificar la siguiente persona:\n\n");
            showAPerson(per[dniVerify]);
            if(validateDualExit("Confirmar: s/n: ","\nError: no se reconoce la respuesta.\nReingrese: ",'s','n') == 1)
            {
                do
                {
                    xlkHeadGenerator("Modificar persona:");
                    showAPerson(per[dniVerify]);
                    xlkIndexBodyGenerator(4,"1-Cambiar DNI.","2-Cambiar nombre.","3-Cambiar edad.","4-Volver");
                    selection = getInt(" -Seleccionar opcion: ");
                    switch(selection)
                    {
                    case 1:
                        dni = getRangedInt(1000000, 99999999,"Ingrese DNI de la persona","Un DNI debe tener 7 u 8 digitos, reingrese: ");
                        dniVerify2 = searchByDNI(per,elements,dni);
                        if(dniVerify2 > -1)
                        {
                            printf("El DNI que intenta cargar se encuentra en uso.\n");
                        }
                        else if(dniVerify2 == -1 && validateDualExit("\nAplicar modificacion? s/n: ","\nError: no se reconoce su respuesta.\n Reingrese: ",'s','n') == 1)
                        {
                            per[dniVerify].dni = dni;
                            printf("\nDNI actualizado.\n");
                            verify++;
                        }
                        else
                        {
                            printf("\nAccion cancelada.");
                        }
                        system("pause");
                        break;
                    case 2:
                        getRangedStr(2,29,"Ingrese nuevo nombre: ","Nombre invalido, reingrese: ",name);
                        if(validateDualExit("\nAplicar modificacion? s/n: ","\nError: no se reconoce su respuesta.\n Reingrese: ",'s','n') == 1)
                        {
                            xstrCapsSpaceFixer(name);
                            strcpy(per[dniVerify].name,name);
                            printf("\nNombre actualizado.\n");
                            verify++;
                        }
                        else
                        {
                            printf("\nAccion cancelada.");
                        }
                        system("pause");
                        break;
                    case 3:
                        age = getRangedInt(0,150,"Ingrese edad de la persona: ","Error, numero muy grande o muy pequeño: ");
                        if(validateDualExit("\nAplicar modificacion? s/n: ","\nError: no se reconoce su respuesta.\n Reingrese: ",'s','n') == 1)
                        {
                            per[dniVerify].age = age;
                            printf("\nEdad actualizada.\n");
                            verify++;
                        }
                        else
                        {
                            printf("\nAccion cancelada.");
                        }
                        system("pause");
                        break;
                    case 4:
                        exit = 1;
                        system("pause");
                        break;
                    default:
                        printf("\nOpcion invalida.\n");
                        system("pause");
                        break;
                    }

                }
                while(exit == 0);
            }
        }
    }
    return verify;
}
*/


//FUNCIONES DE MUESTRA:


//XP1-9
/** \brief Muestra una persona.
 *
 * \param per : variable de tipo ePerson a mostrar.
 * \return
 *
 */

void showAPerson(ePerson per)
{
    printf("\n--------------------------------------------------------------------------------\n");
    printf("NOMBRE:\t\t\tDNI:\t\tEDAD:\n\n");
    printf(" %-29s\t%-10d\t\t\t%-3d\n",per.name,per.dni,per.age);
    printf("\n--------------------------------------------------------------------------------\n");
}


//XP2-1
/** \brief Muestra las personas de un vector de personas.
 *
 * \param per : vector de personas a mostrar.
 * \param elements: cantidad de elementos del vector de personas.
 * \return
 *
 */

void showPeople(ePerson per[],int elements)
{
    printf("\n\n                             LISTA DE PERSONAS");
    printf("\n--------------------------------------------------------------------------------");
    printf(" NOMBRE:\t\t\tDNI:\t\t\t\tEDAD:\n");
    printf("--------------------------------------------------------------------------------");
    for(int i = 0; i < elements; i++)
    {
        if(per[i].status == 1)
        {
            printf(" %-29s\t%-10d\t\t\t%-3d\n",per[i].name,per[i].dni,per[i].age);
        }
    }
    printf("--------------------------------------------------------------------------------\n");
}



//FUNCIONAS ADICIONALES:


//XP2-2
/** \brief Grafica con barras segun las edades de las personas de un vector de personas.
 *
 * \param per : Vector de personas a recorrer y graficar.
 * \param  elements: cantidad de elementos del vector de personas.
 * \return devuelve 1 si se graficaron elementos o 0 si no hay elementos para graficar.
 *
 */

int graph( ePerson per[], int elements)
{
    int counters[3] = {};
    int counterMaxValue;
    int verify = 1;
    int i;

    for( i = 0; i < elements; i++)
    {
        if(per[i].status == 1)
        {
            if(per[i].age < 18)
            {
                counters[0]++;
            }
            else if(per[i].age < 36 && per[i].age > 17)
            {
                counters[1]++;
            }
            else
            {
                counters[2]++;
            }
        }
    }

    if(counters[0] == 0 && counters[1] == 0 && counters[2] == 0)
    {
        verify = 0;
    }
    else
    {
        counterMaxValue = xvecIGetMaxMin(counters,3,1);
        printf("\n\n\t    GRAFICO DE BARRAS\n");
        printf("  _______________________________________\n");
        printf("  |                                     |\n");
        printf("  |   Cantidad de personas segun edad   |\n");
        printf("  |                                     |\n");
        printf("  |                                     |\n");
        printf("  |___*                                 |\n");
        printf("  |   |                                 |\n");
        for(i = counterMaxValue; i > 0; i--)
        {
            if(i % 3 == 0 || i == 1)
            {
                printf("  | %d |   ",i);
            }
            else
            {
                printf("  |   |   ");
            }


            if(i <= counters[0])
            {
                printf("  |*|       ");
            }
            else
            {
                printf("            ");
            }

            if(i <= counters[1])
            {
                printf("|*|       ");
            }
            else
            {
                printf("          ");
            }

            if(i <= counters[2])
            {
                printf("|*|     |\n");
            }
            else
            {
                printf("        |\n");
            }

        }
        printf("  |-------------------------------------|\n  | Edades (-18)   (19 a 35)   (+35)    |\n");
        printf("  |_____________________________________|\n\n\n\n");
    }
    return verify;
}


//XP2-3
/** \brief Ordena por nombre a un vector de personas, si son iguales ordena por edad sino por dni.
 *
 * \param per : vector de personas a ordenar.
 * \param  elements : cantidad de elementos del vector de personas.
 * \return
 *
 */

void sortPeople(ePerson per[], int elements)
{
    ePerson aux;
    int i;
    for( i = 0 ; i < elements - 1 ; i++)
    {
        for(int j = i+1 ; j < elements ; j++)
        {
            if(stricmp(per[j].name, per[i].name) < 0)
            {
                aux = per[i];
                per[i] = per[j];
                per[j] = aux;
            }
            else if(stricmp(per[j].name, per[i].name) == 0)
            {
                if(per[j].age > per[i].age)
                {
                    aux = per[i];
                    per[i] = per[j];
                    per[j] = aux;
                }
                else if(per[j].age == per[i].age)
                {
                    if(per[j].dni > per[i].dni)
                    {
                        aux = per[i];
                        per[i] = per[j];
                        per[j] = aux;
                    }
                }
            }
        }
    }
}


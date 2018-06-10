#ifndef XPERSON_H_INCLUDED
#define XPERSON_H_INCLUDED

//Declaracion de estructuras:

typedef struct
{
    char name[51];
    int age;
    long dni;
    int status;

}ePerson;

/*

#----------------------------------------------------------------------------------------------------------------------#
PROTOTIPOS DE FUNCIONES:
#----------------------------------------------------------------------------------------------------------------------#

*/

//FUNCIONES BASICAS:

void hardcode(ePerson per[]); //XP1-1
void initializePersons(ePerson per[],int elements); //XP1-2

//ABM DEPENDENCIAS:

int searchByDNI(ePerson per[], int elements, int dni);  //XP1-3
int searchSpace(ePerson per[],int elements);  //XP1-4
ePerson getPerson(void);  //XP1-5

//FUNCIONES PARA ALTA BAJA Y MODIFICACION:

int newPerson(ePerson per[], int elements);    //XP1-6
int deletePerson(ePerson per[],int elements);   //XP1-7
//int modifyPerson(ePerson per[],int elements);   //XP1-8

//FUNCIONES DE MUESTRA:

void showAPerson(ePerson per);   //XP1-9
void showPeople(ePerson per[],int elemets);   //XP2-1

//FUNCIONAS ADICIONALES:

int graph( ePerson people[], int elements );  //XP2-2
void sortPeople(ePerson per[], int elements); //XP2-3

#endif // XPERSON_H_INCLUDED

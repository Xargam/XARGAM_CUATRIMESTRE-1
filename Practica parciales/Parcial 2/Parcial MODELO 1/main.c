#include <stdio.h>
#include <stdlib.h>

/*
Desarrollar en ANSI C:
Una compa��a de servicios de marketing por correo electr�nico requiere una
aplicaci�n que permita depurar una lista de destinatarios, la cual se encuentran en un
archivo de texto del tipo csv. La aplicaci�n deber� permitir seleccionar el archivo de
destinatarios, el archivo de lista negra (personas que no deben recibir el mail) y al
elegir la opci�n depurar generar una nueva lista que contenga todos los destinatarios
que no se encuentran en la lista negra.
Opciones del sistema
1. CARGAR DESTINATARIOS: Se solicita al usuario el nombre del archivo de
destinatarios y se carga el arrayList de destinatarios.
2. CARGAR LISTA NEGRA: Se solicita al usuario el nombre del archivo de lista
negra y se carga el arrayList de destinatarios.
3. DEPURAR: Genera una nueva lista que contenga todos los destinatarios que
no se encuentran en la lista negra y elimina los destinatarios repetidos.
4. LISTAR : En esta opci�n se listan a las personas que les sera enviado el
correo.
Nota 1: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y
respetar las reglas de estilo de la c�tedra.
Nota 1: Se deber� utilizar la biblioteca arrayList.
*/

int main()
{
    int selection;
    xlkIndexGenerator("DEPURAR DESTINATARIOS",5,"1- Cargar destinataios.","2-Cargar lista negra.","3-Depurar.","4-Listar.","5-Salir.");
    switch(selection)
    {
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }
    return 0;
}

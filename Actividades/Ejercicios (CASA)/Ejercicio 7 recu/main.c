#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int i;
int nota;
char sexo;
int edad;
int acumulador = 0;
int flag = 0;
int flagMujer = 0;
int contador = 0;
int notaMin;
char sexoMin;
float promedio;
int contadorVarones619=0;

int Edad1Mujer;
int Nota1Mujer;

int EdadMin;
int NotaJoven;
char SexoJoven;

void pedirDatos();

char pedirSexo();
int pedirNota();
int pedirEdad();


void verificarNotaBajaSexo();
void verificarVarones619();
void verificarNotaSexoJoven();
void verificarDatosPrimeraMujer();

int main()
{
    for(i = 1; i<6 ; i++)
    {
        contador++;
        pedirDatos();
        acumulador += nota;
        verificarNotaBajaSexo();
        verificarVarones619();
        verificarNotaSexoJoven();
        verificarDatosPrimeraMujer();
        flag = 1;
    }

    promedio = (float)acumulador / contador;

    printf("a) El promedio de las notas es: %.2f\n", promedio);
    printf("b) La nota mas baja fue %d y el sexo de esa persona es: %c.\n", notaMin, sexoMin);
    printf("c) Hubo %d varones mayores a 18 con nota mayor a 5.\n", contadorVarones619);
    printf("d) El sexo del mas joven es %c y su nota %d\n", SexoJoven, NotaJoven);

    if(flagMujer == 0)
    {
        printf("e) No hubo ninguna mujer.");
    }
    else
    {
        printf("e) La edad de la primera mujer ingresada es %d y su nota es %d", Edad1Mujer, Nota1Mujer);
    }

    return 0;
}




















void pedirDatos()
{
    pedirSexo();
    pedirEdad();
    pedirNota();
}

char pedirSexo()
{
    setbuf(stdin, NULL);
    printf("Ingrese el sexo del alumno %d\n",i);
    scanf("%c", &sexo);
    sexo = tolower(sexo);

    while(sexo != 'f' && sexo != 'm')
    {
        setbuf(stdin, NULL);
        printf("Sexo invalido. Por favor reingrese:\n");
        scanf("%c", &sexo);
        sexo = tolower(sexo);
    }
    return 0;
}

int pedirEdad()
{
    printf("Ingrese edad del alumno %d\n",i);
    scanf("%d",&edad);
    setbuf(stdin, NULL);

    while(edad < 0 || edad > 150)
    {
        printf("Edad invalida. Por favor reingrese: \n");
        scanf("%d",&edad);
        setbuf(stdin, NULL);
    }

    return 0;
}

int pedirNota()
{
    printf("Ingrese la nota del alumno %d\n",i);
    scanf("%d",&nota);
    setbuf(stdin, NULL);

    while(nota < 0 || nota > 10)
    {
        printf("Nota invalida. Por favor reingrese:\n");
        scanf("%d",&nota);
        setbuf(stdin, NULL);
    }

    return 0;
}

void verificarNotaBajaSexo()
{
    if(flag == 0 || nota < notaMin)
    {
        notaMin = nota;
        sexoMin = sexo;
    }
}

void verificarVarones619()
{
    if(sexo == 'm' && edad > 18 && nota > 5)
    {
        contadorVarones619++;
    }
}

void verificarNotaSexoJoven()
{
    if(flag == 0 || edad < EdadMin)
    {
        EdadMin = edad;
        SexoJoven = sexo;
        NotaJoven = nota;
    }
}

void verificarDatosPrimeraMujer()
{
    if(sexo == 'f' && flagMujer == 0)
    {
        flagMujer = 1;
        Edad1Mujer = edad;
        Nota1Mujer = nota;
    }
}

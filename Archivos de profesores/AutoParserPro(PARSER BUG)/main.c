#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  TAM = 50;

typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    int anio;
    int estado;
} eAuto;

void mostrarAutos(eAuto**, int);
void mostrarAuto(eAuto*);
eAuto* new_Empleado();
eAuto* new_Auto_Param(int, char*, float);
void guardarAutos(eAuto**, int, char*);
int buscarLibre(eAuto**, int);
int cargarAutos(eAuto**, int*, char*);
void inicializarAutos(eAuto**, int);
eAuto* newArrayAutos(int);
int agrandarArray(eAuto**, int*);

int main()
{
    eAuto* flota;
    eAuto* unAuto;
    int cantidad;

    flota = newArrayAutos(TAM);

    if(flota == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(1);
    }

    cantidad = cargarAutos(flota, &TAM, "autos.csv");

    printf("Se cargaron %d autos\n", cantidad);

    mostrarAutos(flota, TAM);

    return 0;
}


void mostrarAuto(eAuto* unAuto)
{
    if(unAuto != NULL)
    {
        printf("%4d %15s %16s %15s %4d\n",  unAuto->id,  unAuto->marca,  unAuto->modelo,  unAuto->color,  unAuto->anio);
    }
}

void mostrarAutos(eAuto** autos, int tam)
{

    if(autos != NULL && tam > 0)
    {
        for(int i=0; i< tam; i++)
        {

            if( (*(autos+ i))->estado)
            {
                mostrarAuto( (*(autos+i)) );
            }
        }
    }
    else
    {
        printf("\nNo se pueden mostrar los autos\n");
    }

}

eAuto* new_Auto()
{

    eAuto* nuevoAuto;

    nuevoAuto = (eAuto*)malloc(sizeof(eAuto));
    if(nuevoAuto != NULL)
    {
        nuevoAuto->id = 0;
        strcpy(nuevoAuto->marca, "");
        strcpy(nuevoAuto->modelo, "");
        strcpy(nuevoAuto->color, "");
        nuevoAuto->anio = 0;
        nuevoAuto->estado = 0;
    }
    return nuevoAuto;

}



eAuto* new_Empleado_Param(int id, char* marca, char* modelo, char* color, int anio)
{

    eAuto* nuevoAuto;

    nuevoAuto = new_Auto();

    if(nuevoAuto != NULL)
    {
        nuevoAuto->id = id;
        strcpy(nuevoAuto->marca, marca);
        strcpy(nuevoAuto->modelo, modelo);
        strcpy(nuevoAuto->color, color);
        nuevoAuto->anio = anio;
        nuevoAuto->estado = 1;
    }
    return nuevoAuto;

}

void guardarautos(eAuto* autos, int tam, char* path)
{

    FILE* f;

    f = fopen(path, "w");

    if(f != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if( (autos + i)->estado)
            {
                fwrite( (autos+i), sizeof(eAuto), 1, f);
            }
        }
        fclose(f);
    }
}

int cargarAutos(eAuto** autos, int* tam, char* path)
{

    FILE* f;
    int indice;
    eAuto autoAuxiliar;
    int cant;
    int total = 0;
    int id;
    char marca[50];
    char modelo[50];
    char color[50];
    char idCad[20];
    char anioCad[20];
    int anio;

    f = fopen(path, "r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }



    while(!feof(f))
    {
        indice = buscarLibre(autos, *tam);
        if(indice == -1)
        {
            //printf("No hay mas lugar\n");
            agrandarArray(autos, tam);
            break;
        }
        else
        {
            cant = fscanf(f, "%[^,], %[^,], %[^,], %[^,], %[^\n] \n", idCad, marca, modelo, color, anioCad);

            if(cant != 5)
            {
                if(feof(f))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro\n");
                    break;
                }
            }


        autoAuxiliar.id = atoi(idCad);
        autoAuxiliar.anio = atoi(anioCad);
        strcpy(autoAuxiliar.marca, marca);
        strcpy(autoAuxiliar.modelo, modelo);
        strcpy(autoAuxiliar.color, color);
        autoAuxiliar.estado = 1;

            (*(*(autos+indice))) = autoAuxiliar;
            total++;
            //indice = buscarLibre(autos, tam);

        }
    }
    fclose(f);
    return total;
}

int buscarLibre(eAuto** autos, int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if( (*(autos+i))->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarautos(eAuto* autos, int tam)
{

    if(autos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            (autos+i)->estado = 0;
        }
    }
}

eAuto* newArrayAutos(int tam)
{

    eAuto* array;

    if(tam > 0)
    {
        array = (eAuto*) malloc(tam * sizeof(eAuto));

        if(array != NULL)
        {
            inicializarautos(array, tam);
        }
    }
    return array;
}

int agrandarArray(eAuto** autos, int* ptam){

  eAuto* pAux;
  int nuevoTam = (*ptam) + 20;
  int todoOk = 0;

  pAux = (eAuto*) realloc( (*autos) , nuevoTam * sizeof(*eAuto));

  if( pAux != NULL){
    autos = pAux;
    *ptam += 20;
    todoOk = 1;
  }

  return todoOk;

}



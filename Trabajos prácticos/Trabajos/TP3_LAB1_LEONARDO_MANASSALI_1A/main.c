#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xlook.h"
#include "xvalidate.h"
#include "xget.h"
#include "xMovies.h"
#include "xFile.h"

#define MOVFILE "movies.bin"
#define MOVHTML "movies.html"

int main()
{
    int quantity = 0;
    int option;
    int reading;
    int quit = 0;

    eMovies* movies = newMovie();
    eMovies** movies2 =(eMovies**) xfiNewDynamicArray2(1,sizeof(eMovies));
    eMovies* auxMovies = NULL;

    if( movies == NULL )
    {
        xlkShowMessage("Se produjo un error durante la reserva de memoria.",3);
    }
    fileSync(MOVFILE);
    movies2=(eMovies**)xfiFileLoader(MOVFILE,&quantity,sizeof(eMovies));
    for(int i = 0 ; i< quantity ; i++)
    {
        /*   char title[60];
        char genre[60];
        char description[300];
        char imageURL[300];
        int duration;
        int score;*/
        xlkSortPrintf(1,"%s,%s,%s,%d,%d,%d",6,movies2[i]->title,movies2[i]->genre,movies2[i]->description,movies2[i]->imageURL,movies2[i]->duration,movies2[i]->score, movies2[i]->status);
        system("pause");
    }
    exit(1);
    if( movies == NULL )
    {
        xlkShowMessage("Se produjo un error durante la apertura de un archivo.",3);
    }

    do
    {
        xlkIndexGenerator(" MovieSofware V3.0.0 - TP #3 - Leonardo Manassali 1A",6,"1* Agregar pelicula.","2* Borrar pelicula.","3* Modificar pelicula.","4* Mostrar peliculas.","5* Generar pagina web.","6* Salir.");
        if( getRangedInt(&option,1,6," -Seleccionar opcion: ","\n* Opcion invalida.\n\n") )
        {
            system("cls");
            switch(option)
            {
            case 1:

                printf("* Agregar nueva pelicula:\n\n");
                auxMovies = addMovie(movies,&quantity);
                if( auxMovies == NULL)
                {
                    printf("** Se produjo un error al agregar la pelicula.\n\n");
                }
                else
                {
                    printf("* La pelicula fue agregada exitosamente.\n\n");
                    movies = auxMovies;
                }
                break;
            case 2:
                if(quantity > 0)
                {
                    printf("* Eliminar una pelicula:\n\n");
                    reading = deleteMovie(movies,quantity);
                    if( reading == -1)
                    {
                        printf("* No se encontro ninguna pelicula para eliminar.\n\n");
                    }
                    else if( reading == 0)
                    {
                        printf("* Accion cancelada. No realizo ninguna eliminacion.\n\n");
                    }
                    else
                    {
                        printf("* La pelicula se elimino con exito.\n\n");
                    }
                }
                else
                {
                    printf("**No hay peliculas cargadas en el sistema.\n\n");
                }
                break;
            case 3:
                if(quantity > 0)
                {
                    reading = modifyMovie(movies,quantity);
                    if( reading == 1)
                    {
                        printf("* Se aplicaron las modificaciones con exito.\n\n");
                    }
                    else if( reading == 0)
                    {
                        printf("* No realizo ninguna modificacion.\n\n");
                    }
                    else
                    {
                        printf("** No se ha encontrado la pelicula que busca en el sistema.\n\n");
                    }
                }
                else
                {
                    printf("**No hay peliculas cargadas en el sistema.\n\n");
                }
                break;
            case 4:
                if(quantity > 0)
                {
                    showAllMovies(movies,quantity);
                }
                else
                {
                    printf("**No hay peliculas cargadas en el sistema.\n\n");
                }
                break;
            case 5:
                if(quantity > 0)
                {
                    reading = generateMoviesHTML(MOVHTML,movies,quantity);
                    if( reading == 1)
                    {
                        printf("* Se ha generado un archivo ""movies.html"" con las peliculas cargadas.\n\n");
                    }
                    else
                    {
                        printf("** Se produjo un error al generar el archivo ""movies.html"".\n\n");
                    }
                }
                else
                {
                    printf("**No hay peliculas cargadas en el sistema.\n\n");
                }
                break;
            case 6:
                quit = validateDualExit("* Esta seguro que desea salir? s/n : ","\n* Respuesta incorrecta.\n\n",'s','n');
                printf("\n\n");
                break;
            }
        }
        system("pause");
    }
    while( !quit );

    reading = saveMovies(MOVFILE,movies,quantity);
    if(reading == -1)
    {
        xlkShowMessage("Se produjo un error al escribir datos en un archivo.",2);
    }
    free(movies);
    return 0;
}

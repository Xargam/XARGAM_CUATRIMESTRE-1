#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xlook.h"
#include "xvalidate.h"
#include "xget.h"
#include "xstring.h"
#include "xMovies.h"

#define EMPTY 0
#define BUSY 1


//Prototipos de funciones:

//Funciones que manejan archivos de peliculas:




/** \brief Carga las PELICULAS de un archivo en un array de punteros a PELICULAS .
 *
 * \param filename : Nombre o ruta del archivo a revisar.
 * \param movies : Puntero que recibira las PELICULAS leidas del archivo.
 * \param quantity : La cantidad de PELICULAS leidas se registran en este parametro. El minimo valor es 1.
 * \return Devuelve un puntero a PELICULAS con los elementos leidos. En caso de error devuelve un puntero a NULL.
 *
 */

eMovies* loadMovies(char* filename, int* quantity)
{
    eMovies* auxMovies;
    eMovies* movies = NULL;

    int reading;
    int index = 0;
    *quantity = index;

    FILE* file = fopen(filename,"rb");

    if(file != NULL)
    {
        movies = newMovie();
        initializeArray(movies,1,0);
        if(movies != NULL)
        {
            while( !feof(file) )
            {
                reading = fread( &movies[index],sizeof(eMovies),1,file);
                if(reading != 1)
                {
                    if( feof(file) )
                    {
                        break;
                    }
                    else
                    {
                        movies = NULL;
                        break;
                    }
                }

                index++;

                if( index >= *quantity )
                {
                    if( (auxMovies = resizeArray(movies,index+1)) == NULL)
                    {
                        movies = NULL;
                        break;
                    }
                    *quantity = index+1;
                    movies = auxMovies;
                    initializeArray(movies,*quantity,index);
                }
            }
        }
        if( fclose(file) )
        {
            movies = NULL;
        }
    }
    return movies;
}



/** \brief Guarda los elementos de un puntero de PELICULAS en un archivo especifico.
 *
 * \param filename : Nombre o ruta del archivo donde guardar las PELICULAS del puntero.
 * \param movies : Puntero con PELICULAS a guardar.
 * \return Devuelve [1] si se guardaron las peliculas, [0] si no hubo peliculas que guardar o [-1] si hubo errores.
 *
 */

int saveMovies(char* filename,eMovies* movies, int quantity)
{
    int verify = 1;
    int reading;
    int i;

    if(quantity > 0)
    {
        FILE* file;
        file = fopen(filename,"wb");
        if(file == NULL)
        {
            verify = -1;
        }
        else
        {
            for( i = 0; i < quantity ; i++)
            {
                if( movies[i].status == BUSY)
                {
                    reading = fwrite(&movies[i],sizeof(eMovies),1,file);
                    if(reading != 1 )
                    {
                        verify = -1;
                        break;
                    }
                }

            }
        }
        if( fclose(file) )
        {
            verify = -1;
        }
    }
    else
    {
        verify = 0;
    }

    return verify;
}



/** \brief Genera un archivo html en el cual se puede observar una pagina web con las peliculas cargadas en el sistema.
 *
 * \param filename: Ruta o nombre del archivo html a generar.
 * \param movies: Puntero a peliculas que contiene datos a mostrar en el archivo html.
 * \param movies: cantidad de peliculas que contiene el puntero a peliculas.
 * \return Devuelve 1 si el archivo fue generado correctamente o 0 si se produjo un error.
 *
 */

int generateMoviesHTML(char* filename, eMovies* movies,int quantity)
{
    int verify = 1;
    int i;

    FILE* htmlFile;
    htmlFile= fopen(filename,"w");
    if(htmlFile != NULL)
    {
        char startString[]= {"<p><p><article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src="};
        for(i = 0 ; i < quantity ; i++)
        {
            if(movies[i].status == BUSY)
            {
                fprintf(htmlFile,"_______________________________________________________________________________________________________________________________________________________________________\n");
                fprintf(htmlFile,"_______________________________________________________________________________________________________________________________________________________________________\n");
                fprintf(htmlFile,"%s",startString);
                fprintf(htmlFile,"\'%s\'\n",movies[i].imageURL);
                fprintf(htmlFile,"alt=''>\n");
                fprintf(htmlFile,"</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n",movies[i].title);
                fprintf(htmlFile,"<li>Género:%s</li>\n",movies[i].genre);
                fprintf(htmlFile,"<li>Puntaje:%d</li>\n",movies[i].score);
                fprintf(htmlFile,"<li>Duración:%d</li>\n</ul>\n",movies[i].duration);
                fprintf(htmlFile,"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                fprintf(htmlFile,"<li>Sinopsis: %s</li>\n</article>\n",movies[i].description);
                fprintf(htmlFile,"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            }
        }
    }
    else
    {
        verify = 0;
    }
    if( fclose(htmlFile) )
    {
        verify = 0;
    }
    return verify;
}



//Funciones dinamicas para peliculas:



/** \brief Reserva espacio en la memoria para almacenar un puntero dinamico a PELICULAS.
 *
 * \param
 * \return Devuelve un puntero al espacio en memoria reservado.
 *
 */

eMovies* newMovie(void)
{
    eMovies* movie = (eMovies*)malloc(sizeof(eMovies));
    return movie ;
}



/** \brief Cambia el tamaño de un array de punteros.
 *
 * \param movies : Puntero a cambiar de tamaño.
 * \param newSize : Cantidad de elementos que tendra el nuevo puntero.
 * \return Devuelve un puntero a peliculas apuntando al espacio reservado.
 *
 */

eMovies* resizeArray(eMovies* movies, int newSize)
{
    eMovies* newArray = (eMovies*)realloc(movies,sizeof(eMovies)*newSize);
    return newArray;
}



/** \brief Inicializa el estado de un array de punteros a PELICULAS desde un indice especifico.
 *
 * \param quantity: Cantidad de elementos del array.
 * \param startIndex : Indice del primer elemento del array a inicializar.
 * \return
 *
 */

void initializeArray(eMovies* movies, int quantity, int startIndex)
{
    int i ;
    for(i = startIndex ; i < quantity ; i++)
    {
        movies[i].status = 0;
    }
}



//Funciones dependencia - ABM:



/** \brief Recorre un array de punteros a PELICULAS y busca un indice que no tenga datos cargados y lo devuelve.
 *
 * \param movies: Puntero a PELICULAS a revisar.
 * \param quantity: Tamaño del array.
 * \return Devuelve el primer indice libre encontrado, en caso de no haber espacio devuelve -1.
 *
 */

int findSpace(eMovies* movies, int quantity)
{
    int i;
    int freeIndex = -1;

    for( i = 0; i < quantity ; i++)
    {
        if( movies->status == 0 )
        {
            freeIndex = i;
            break;
        }

    }
    return freeIndex;
}



/** \brief Busca una pelicula en un array de punteros a peliculas a partir del titulo y devuelve el indice de la misma.
 *
 * \param movies: array de punteros a peliculas donde buscar una peliculas.
 * \param quantity: tamaño del array.
 * \param movieTitle: titulo de pelicila a buscar.
 * \return Devuelve -1 si la pelicula no se encuentra o un indice valido si encontro una pelicula.
 *
 */

int findMovie(eMovies* movies, int quantity, char* movieTitle )
{
    int i;
    int movieIndex = -1;
    for( i = 0; i < quantity ; i++ )
    {
        if( stricmp(movies[i].title, movieTitle) == 0 && movies[i].status == BUSY )
        {
            movieIndex = i;
            break;
        }
    }
    return movieIndex;
}



/** \brief Pide al usuario una pelicula valida.
 *
 * \param movies: Array de punteros a peliculas, necesario para validar que el titulo a agregar no se repita.
 * \return Devuelve un puntero a la pelicula que el usuario solicito.
 *
 */

eMovies* requestMovie(eMovies* movies, int quantity)
{
    eMovies* movie = (eMovies*) malloc(sizeof(eMovies));
    if( movie != NULL)
    {
        int number;
        char* string;

        do
        {
            string = get999String("* Ingrese el titulo de la pelicula: ",1);
            xstrCapsSpaceFixer(string);
            xstrCapsAdder(string);
            if( findMovie(movies, quantity,string) == -1)
            {
                if(!setTitle(movie,string))
                {
                    xlkShowMessage("** Se produjo un error al validar el titulo de la pelicula.Puede que sea muy largo o demasiado corto.",7);
                }
            }
            else
            {
                xlkShowMessage("** El titulo ya fue agregado al sistema.",7);
            }

        }
        while(!setTitle(movie,string) || findMovie(movies, quantity,string) > -1);
        do
        {
            string = get999String("* Ingrese el genero de la pelicula: ",1);
            if(!setGenre(movie,string))
            {
                xlkShowMessage("** Se produjo un error al validar el genero de la pelicula. Puede que sea muy largo o contenga caracteres invalidos.",7);
            }
        }
        while(!setGenre(movie,string));

        do
        {
            string = get999String("* Ingrese la descripcion de la pelicula: ",1);
            if(!setDescription(movie,string))
            {
                xlkShowMessage("** Se produjo un error al validar la descripcion de la pelicula.Puede que sea muy larga o demasiado corta",7);
            }
        }
        while(!setDescription(movie,string));
        do
        {
            string = get999String("* Ingrese el link de la imagen de la pelicula: ",1);
            if(!setURL(movie,string))
            {
                xlkShowMessage("** Se produjo un error al validar el link. Puede que sea muy largo o demasiado corto.",7);
            }
        }
        while(!setURL(movie,string));
        do
        {
            while( !getValidInt(&number,"* Ingrese la duracion de la pelicula en minutos: ","\n** El numero ingresado es erroneo.") );
            if(!setDuration(movie,number))
            {
                xlkShowMessage("** La duracion demasiado grande o muy pequenia.",7);
            }
        }
        while(!setDuration(movie,number));
        do
        {
            while( !getValidInt(&number,"* Ingrese el puntaje de la pelicula: ","\n** El numero ingresado es erroneo.") );
            if(!setScore(movie,number))
            {
                xlkShowMessage("** El puntaje de una pelicula debe ser un numero del 0 al 100.",7);
            }
        }
        while(!setScore(movie,number));
        movie->status = 1;
    }
    system("cls");
    return movie;
}



//Funciones para Alta, Baja y Modificacion:



/** \brief Añade una pelicula a un array de punteros.
 *
 * \param movies: Array de peliculas inicial.
 * \param quantity: cantidad de eleemntos del array.
 * \return Devuelve un puntero de Peliculas con la nueva pelicula agregada.
 *
 */

eMovies* addMovie(eMovies* movies,int *quantity)
{
    eMovies* auxMovies = NULL;
    eMovies* newMovie = NULL;

    if(*quantity == 0)
    {
        *quantity += 1;
    }

    int freeIndex = findSpace(movies, *quantity);
    if( freeIndex == -1)
    {
        auxMovies = resizeArray(movies, (*quantity + 30) );
        if( auxMovies != NULL)
        {
            movies = auxMovies;
            freeIndex = *quantity;
            initializeArray(movies, (*quantity + 30), *quantity );
            *quantity += 30;
        }
    }
    newMovie = requestMovie(movies, *quantity);
    if( newMovie != NULL)
    {
        movies[freeIndex] = *newMovie ;
    }
    else
    {
        movies = NULL;
    }

    return movies;
}



/** \brief Elimina una pelicula de un array de punteros.
 *
 * \param movies: Array de punteros en el que buscar una pelicula para eliminar.
 * \param quantity: Cantidad de elementos del array.
 * \return Devuelve [1] si el usuario elimino una pelicula, [0] si encontro una pelicula pero no la elimino o [-1] si no encontro una pelicula.
 *
 */

int deleteMovie(eMovies* movies, int  quantity)
{
    char movieTitle[60];
    int movieIndex;
    int userAction = -1;
    showAllMovies(movies,quantity);
    if( getRangedAlphaNumStr(movieTitle,1,59,"\n* Ingrese el titulo de la pelicula a eliminar: ","\n** El titulo ingresado es invalido.",1) )
    {
        if( (movieIndex = findMovie(movies, quantity, movieTitle)) != -1)
        {
            userAction = 0;
            system("cls");
            xlkCenterPrintf("ELIMINARA A LA SIGUIENTE PELICULA",1);
            showAMovie(&movies[movieIndex]);
            if( validateDualExit("\nDesea eliminar la pelicula? s/n: ","\nRespuesta invalida.\n\n",'s','n') )
            {
                userAction = 1;
                movies[movieIndex].status = 0;
            }
        }
    }
    system("cls");
    return userAction;
}



/** \brief Modifica los datos de una pelicula cargada en un array de punteros a peliculas.
 *
 * \param movies: Array de punteros en el que buscar una pelicula para modificar.
 * \param quantity: Cantidad de elementos del array.
 * \return Devuelve [1] si el usuario realizo una modificacion, [0] si encontro una pelicula pero no la elimino o [-1] si no encontro una pelicula.
 *
 */

int modifyMovie(eMovies* movies, int quantity)
{
    char movieTitle[60];
    int movieIndex;
    int userAction = -1;
    showAllMovies(movies,quantity);
    if( getRangedAlphaNumStr(movieTitle,1,59,"\n* Ingrese el titulo de la pelicula a modificar: ","\n** El titulo ingresado es invalido.",1) )
    {
        if( (movieIndex = findMovie(movies, quantity, movieTitle)) != -1)
        {
            int selection;
            int quit = 0;
            userAction = 0;
            char* string;
            int number;
            do
            {
                xlkHeadGenerator(0,"MODIFICAR PELICULA: ");
                showAMovie(&movies[movieIndex]);
                printf("\n");
                xlkIndexBodyGenerator(0,7,"1-Cambiar titulo.","2-Cambiar genero.","3-Cambiar descripcion.","4-Cambiar link de imagen.","5-Cambiar duracion.","6-Cambiar puntaje.","7-Volver.");
                if( getRangedInt(&selection,1,7," -Seleccionar opcion: ","\n** Opcion invalida.\n\n"))
                {
                    system("cls");
                    switch(selection)
                    {
                    case 1:
                        string = get999String("* Ingrese el nuevo titulo de la pelicula: ",1);
                        xstrCapsSpaceFixer(string);
                        xstrCapsAdder(string);
                        if( findMovie(movies,quantity,string) == -1)
                        {
                            if( !setTitle(&movies[movieIndex],string))
                            {
                                xlkShowMessage("** El titulo es invalido. No se realizo ninguna modificacion.",2);
                            }
                            else
                            {
                                xlkShowMessage("* El titulo ha sido actualizado.",2);
                                userAction = 1;
                            }
                        }
                        else
                        {
                            xlkShowMessage("** El titulo se encuentra en uso. No se realizo la modificacion.",2);
                        }
                        break;
                    case 2:
                        string = get999String("Ingrese el nuevo genero de la pelicula: ",1);
                        if( !setGenre(&movies[movieIndex],string) )
                        {
                            xlkShowMessage("** El genero es invalido. No realizaron modificaciones.",2);
                        }
                        else
                        {
                            xlkShowMessage("* El genero ha sido actualizado.",2);
                            userAction = 1;
                        }
                        break;
                    case 3:
                        string = get999String("Ingrese nueva descripcion de la pelicula: ",1);
                        if( !setDescription(&movies[movieIndex],string) )
                        {
                            xlkShowMessage("** La descripcion es invalida. No realizaron modificaciones.",2);
                        }
                        else
                        {
                            xlkShowMessage("* La descripcion ha sido actualizada.",2);
                            userAction = 1;
                        }
                        break;
                    case 4:
                        string = get999String("Ingrese nuevo link de la imagen de la pelicula: ",1);
                        if( !setURL(&movies[movieIndex],string) )
                        {
                            xlkShowMessage("** El link es invalido. No realizaron modificaciones.",2);
                        }
                        else
                        {
                            xlkShowMessage("* El link de la imagen de la pelicula ha sido actualizado.",2);
                            userAction = 1;
                        }
                        break;
                    case 5:
                        if( getValidInt(&number,"Ingrese nueva duracion de la pelicula: ","\nNumero invalido.") )
                        {
                            if( !setDuration(&movies[movieIndex],number) )
                            {
                                xlkShowMessage("** La duracion es invalida. No realizaron modificaciones.",2);
                            }
                            else
                            {
                                xlkShowMessage("* La duracion de la pelicula ha sido actualizada.",2);
                                userAction = 1;
                            }
                        }
                        break;
                    case 6:
                        if( getValidInt(&number,"Ingrese nuevo puntaje de la pelicula: ","\nNumero invalido.") )
                        {
                            if( !setScore(&movies[movieIndex],number) )
                            {
                                xlkShowMessage("** El puntaje es invalido. No realizaron modificaciones.",2);
                            }
                            else
                            {
                                xlkShowMessage("* El puntaje de la pelicula ha sido actualizado.",2);
                                userAction = 1;
                            }
                        }
                        break;
                    case 7:
                        quit = 1;
                        break;
                    }
                }
                else
                {
                    system("pause");
                }
            }
            while(quit == 0);

        }
    }
    system("cls");
    return userAction;
}



//Funciones de muestra:



/** \brief Muestra una pelicula cargada en el sistema.
 *
 * \param movie: Pelicula a mostrar.
 * \return
 *
 */

void showAMovie( eMovies* movie )
{
    if(movie != NULL)
    {
        xlkSortPrintf(1,"%s,%s,%s,%s,",4,"TITULO:","GENERO:","DURACION:","PUNTAJE:");
        xlkSortPrintf(0,"%s,%s,%d,%d",4,getTitle(movie), getGenre(movie),getDuration(movie),getScore(movie));
        xlkSortPrintf(1,"%s",1,"DESCRIPCION:");
        xlkSortPrintf(0,"%s,%s",1,getDescription(movie));
        xlkSortPrintf(1,"%s",1,"LINK IMAGEN:");
        xlkSortPrintf(3,"%s,%s",1,getURL(movie));
    }
}



/** \brief Muestra todas las peliculas de un array de punteros a peliculas.
 *
 * \param movies: Array de punteros a peliculas a mostrar.
 * \param quantity: Cantidad de elementos del array.
 * \return
 *
 */

void showAllMovies( eMovies* movies, int quantity)
{
    int i;
    if(movies != NULL)
    {
        system("cls");
        xlkCenterPrintf("LISTADO DE PELICULAS",1);
        for( i = 0 ; i < quantity ; i++)
        {

            if( movies[i].status == BUSY)
            {
                xlkCenterPrintf(" *****PELICULA***** ",1);
                showAMovie(&movies[i]);
                printf("\n\n\n");
            }

        }
    }

}


//Funciones de obtencion de datos:



/** \brief Recibe un puntero a PELICULA y devuelve el titulo de la misma.
 *
 * \param movie : Puntero a PELICULA donde buscar titulo a devolver.
 * \return Devuelve una cadena de caracteres con el titulo de la pelicula.
 *
 */

char* getTitle( eMovies* movie)
{
    char spaceChar = ' ';
    char* title = &spaceChar;
    if(movie != NULL)
    {
        title = movie->title;
    }
    return title;
}



/** \brief Recibe un puntero a PELICULA y devuelve el genero de la misma.
 *
 * \param movie : Puntero a PELICULA donde buscar genero a devolver.
 * \return Devuelve una cadena de caracteres con el genero de la pelicula.
 *
 */

char* getGenre( eMovies* movie)
{
    char spaceChar = ' ';
    char* genre = &spaceChar;
    if(movie != NULL)
    {
        genre = movie->genre;
    }
    return genre;
}



/** \brief Recibe un puntero a PELICULA y devuelve la descripcion de la misma.
 *
 * \param movie : Puntero a PELICULA donde buscar descripcion a devolver.
 * \return Devuelve una cadena de caracteres con la descripcion de la pelicula.
 *
 */

char* getDescription( eMovies* movie)
{
    char spaceChar = ' ';
    char* description = &spaceChar;
    if( movie != NULL)
    {
        description = movie->description;
    }
    return description ;
}



/** \brief Recibe un puntero a PELICULA y devuelve la URL de la misma.
 *
 * \param movie : Puntero a PELICULA donde buscar URL a devolver.
 * \return Devuelve una cadena de caracteres con la URL de la pelicula.
 *
 */

char* getURL( eMovies* movie)
{
    char spaceChar = ' ';
    char* url = &spaceChar;
    if(movie != NULL)
    {
        url = movie->imageURL;
    }
    return url;
}



/** \brief Recibe un puntero a PELICULA y devuelve el puntaje de la misma.
 *
 * \param movie : Puntero a PELICULA donde buscar puntaje a devolver.
 * \return Devuelve un entero con el puntaje de la pelicula o -1 en caso de error.
 *
 */

int getScore( eMovies* movie)
{
    int score = -1;
    if(movie != NULL)
    {
        score = movie->score;
    }
    return score;
}



/** \brief Recibe un puntero a PELICULA y devuelve la duracion de la misma.
 *
 * \param movie : Puntero a PELICULA donde buscar duracion a devolver.
 * \return Devuelve un entero con la duracion de la pelicula o -1 en caso de error.
 *
 */

int getDuration( eMovies* movie)
{
    int duration = -1;
    if(movie != NULL)
    {
        duration = movie->duration;
    }
    return duration;
}



//Funciones de seteo de datos:



/** \brief Valida rango y setea una cadena de caracteres como titulo en un puntero a PELICULAS pasado como parametro.
 *
 * \param movie : Puntero a PELICULA donde setear el titulo elegido.
 * \param title : Cadena de caracteres a setear.
 * \return Devuelve [1] si el seteo fue exitoso o [0] si no lo fue.
 *
 */

int setTitle( eMovies* movie, char* title )
{
    int verify = 1;
    xstrCapsSpaceFixer(title);
    xstrCapsAdder(title);
    if( movie == NULL || !validateStringRange(title, 1, 59) || !validateIsGraphicStr(title))
    {
        verify = 0;
    }
    else
    {
        strcpy( movie->title, title );
    }
    return verify;
}


//XM1-6
/** \brief Valida rango y setea una cadena de caracteres como genero en un puntero a PELICULAS pasado como parametro.
 *
 * \param movie : Puntero a PELICULA donde setear el genero elegido.
 * \param genre : Cadena de caracteres a setear.
 * \return Devuelve [1] si el seteo fue exitoso o [0] si no lo fue.
 *
 */

int setGenre( eMovies* movie, char* genre )
{
    int verify = 1;
    xstrCapsSpaceFixer(genre);
    if( movie == NULL || !validateStringRange(genre, 1, 59) || !validateIsGraphicStr(genre) )
    {
        verify = 0;
    }
    else
    {
        strcpy( movie->genre, genre );
    }
    return verify;
}


//XM1-7
/** \brief Valida rango y setea una cadena de caracteres como descripcion en un puntero a PELICULAS pasado como parametro.
 *
 * \param movie : Puntero a PELICULA donde setear la descripcion elegida.
 * \param descripcion : Cadena de caracteres a setear.
 * \return Devuelve [1] si el seteo fue exitoso o [0] si no lo fue.
 *
 */

int setDescription( eMovies* movie, char* description )
{
    int verify = 1;
    xstrCapsSpaceFixer(description);
    if( movie == NULL || !validateStringRange(description, 1, 299) || !validateIsGraphicStr(description) )
    {
        verify = 0;
    }
    else
    {
        strcpy( movie->description, description );
    }
    return verify;
}


//XM1-8
/** \brief Valida rango y setea una cadena de caracteres como URL en un puntero a PELICULAS pasado como parametro.
 *
 * \param movie : Puntero a PELICULA donde setear la URL (link imagen) elegida.
 * \param url : Cadena de caracteres a setear.
 * \return Devuelve [1] si el seteo fue exitoso o [0] si no lo fue.
 *
 */

int setURL( eMovies* movie, char* url  )
{
    int verify = 1;
    if(  movie == NULL || !validateStringRange( url, 3, 299) || !validateIsGraphicStr(url) )
    {
        verify = 0;
    }
    else
    {
        strcpy( movie->imageURL, url );
    }
    return verify;
}


//XM1-9
/** \brief Valida un entero y lo setea en un puntero a PELICULA como puntaje.
 *
 * \param movie : Puntero a PELICULA donde setear el puntaje elegido.
 * \param score : numero entero a setear.
 * \return Devuelve [1] si el seteo fue exitoso o [0] si no lo fue.
 *
 */

int setScore( eMovies* movie, int score  )
{
    int verify = 1;
    if( movie == NULL || !validateIntRange( score, 0, 100) )
    {
        verify = 0;
    }
    else
    {
        movie->score = score;
    }
    return verify;
}


//XM2-1
/** \brief Valida un entero y lo setea en un puntero a PELICULA como duracion.
 *
 * \param movie : Puntero a PELICULA donde setear la duracion elegida.
 * \param duration : numero entero a setear.
 * \return Devuelve [1] si el seteo fue exitoso o [0] si no lo fue.
 *
 */

int setDuration( eMovies* movie, int duration )
{
    int verify = 1;
    /*El rango de validacion se debe a que la pelicula mas corta de la historia menos un minuto y las mas largas cientos
    de horas*/
    if( movie == NULL || !validateIntRange( duration, 1, 32000)  )
    {
        verify = 0;
    }
    else
    {
        movie->duration= duration;
    }
    return verify;
}

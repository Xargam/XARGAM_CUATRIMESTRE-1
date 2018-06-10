#ifndef XMOVIES_H_INCLUDED
#define XMOVIES_H_INCLUDED

//Declaracion de estructuras:

typedef struct
{
    char title[60];
    char genre[60];
    char description[300];
    char imageURL[300];
    int duration;
    int score;
    int status;

} eMovies ;

//Funciones que manejan archivos de peliculas:

int fileSync(char* filename);
eMovies* loadMovies(char* filename, int* quantity);
int saveMovies(char* filename,eMovies* movies, int quantity);
int generateMoviesHTML(char* filename, eMovies* movies,int quantity);

//Funciones dinamicas para peliculas:

eMovies* newMovie(void);
eMovies* resizeArray(eMovies* movies, int newSize);
void initializeArray(eMovies* movies, int quantity, int startIndex);

//Funciones dependencia - ABM

int findSpace(eMovies* movies, int quantity);
int findMovie(eMovies* movies, int quantity, char* movieTitlee);
eMovies* requestMovie(eMovies* movies, int quantity);

//Funciones para Alta Baja y Modificacion:

eMovies* addMovie(eMovies* movies ,int *quantity);
int deleteMovie(eMovies* movies , int  quantity);
int modifyMovie(eMovies* movies, int quantity);


//Funciones de muestra:

void showAMovie( eMovies* movie );
void showAllMovies( eMovies* movies, int quantity);

//Funciones de obtencion de datos:

char* getTitle( eMovies* movie);
char* getGenre( eMovies* movie);
char* getDescription( eMovies* movie);
char* getURL( eMovies* movie);
int getScore( eMovies* movie);
int getDuration( eMovies* movie);

//Funciones de seteo de datos:

int setTitle( eMovies* movie, char* title );
int setGenre( eMovies* movie, char* genre );
int setDescription( eMovies* movie, char* description );
int setURL( eMovies* movie, char* url );
int setScore( eMovies* movie, int score );
int setDuration( eMovies* movie, int duration );

#endif // XMOVIES_H_INCLUDED





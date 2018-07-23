#ifndef XLOGS_H_INCLUDED
#define XLOGS_H_INCLUDED

//Declaracion de estructuras:

typedef struct
{
 char date[11];
 char time[6];
 int serviceId;
 int gravedad;
 char msg[65];

} sLog;

typedef struct
{
 int id;
 char name[33];
 char email[65];
} sService;

//Prototipos sLog:

//Muestra

void log_show(sLog* log);

//Constructor y destructor:

sLog* log_newLog(void);

//Setters:

int log_setDate( sLog* log , char* date );
int log_setTime( sLog* log , char* time );
int log_setServiceId( sLog* log , int id );
int log_setGravedad( sLog* log , int gravedad );
int log_setMsg( sLog* log , char* message );

//Getters

char* log_getDate( sLog* log );
char* log_getTime( sLog* log );
int log_getServiceId( sLog* log );
int log_getGravedad( sLog* log );
char* log_getMsg( sLog* log );


//Prototipos sServices:

// muerestra

void service_show(sService* service);

//Constructor y destructor:

sService* service_newService(void);

//Setters:

int service_setId( sService* service , int id );
int service_setName( sService* service , char* name );
int service_setEmail( sService* service , char* email );

//Getters

int service_getId( sService* service);
char* service_getName( sService* service );
char* service_getEmail( sService* service );


#endif // XLOGS_H_INCLUDED

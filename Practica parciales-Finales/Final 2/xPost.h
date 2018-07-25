#ifndef XMENSAJES_H_INCLUDED
#define XMENSAJES_H_INCLUDED

//Estructura

typedef struct
{
    int idMessage;
    char message[300];
    int popularidad;
    int idUser;

} sPost


int post_show(sPost* post)
{
    int verify;
    if( post != NULL )
    {
        xlkSortPrintf("%s,%s,%d,%d,%s",1,post->date,post->time,post->serviceId,post->gravedad,post->msg);
    }
}


//Constructor

sPost* post_newPost(void)
{
    sPost* post = (spost*) malloc(sizeof(spost));
    if(post != NULL)
    {
        strcpy( post->date, "" );
        strcpy( post->time, "" );
        strcpy( post->msg, "" );
        post->gravedad = 0;
        post->serviceId = 0;
    }
    return post;
}



//Setters



int post_setDate( sPost* post, char* date )
{
    int verify = 0;
    if( date != NULL && post != NULL)
    {
        if( validateStringRange(date,6,10) )
        {
            strcpy( post->date, date);
            verify = 1;
        }
    }
    return verify;
}



int post_setTime( sPost* post, char* time )
{
    int verify = 0;
    if( time != NULL && post != NULL)
    {
        if( validateStringRange(time,4,5) && validateIsCorrectTime(time,0) )
        {
            strcpy( post->time, time);
            verify = 1;
        }
    }
    return verify;
}


int post_setServiceId( sPost* post, int id )
{
    int verify = 0;
    if( post != NULL)
    {
        if( validateIntCondition(id,1,1) )
        {
            post->serviceId = id;
            verify = 1;
        }
    }
    return verify;
}



int post_setGravedad( sPost* post, int gravedad )
{
    int verify = 0;
    if( post != NULL)
    {
        if( validateIntRange(gravedad,0,9) )
        {
            post->gravedad = gravedad;
            verify = 1;
        }
    }
    return verify;
}



int post_setMsg( sPost* post, char* message )
{
    int verify = 0;
    if( post != NULL && message != NULL)
    {
        if( validateStringRange(message,1,64) )
        {
            strcpy(post->msg, message);
            verify = 1;
        }
    }
    return verify;
}



//Getters:



char* post_getDate( sPost* post )
{
    return post->date;
}



char* post_getTime( sPost* post )
{
    return post->time;
}



int post_getServiceId( sPost* post )
{
    return post->serviceId;
}



int post_getGravedad( sPost* post )
{
    return post->gravedad;
}



char* post_getMsg( sPost* post )
{
    return post->msg;
}



//ESTRUCTURA sServices

//Muestra


void service_show(sService* service)
{
    if( service != NULL )
    {
        xlkSortPrintf("%d,%s,%s",1,service->id,service->name,service->email);
    }
}


//Constructor y destructor:

sService* service_newService(void)
{
    sService* service = (sService*) malloc(sizeof(sService));
    if(service != NULL)
    {
        strcpy( service->name, "" );
        strcpy( service->email, "" );
        service->id = 0;
    }
    return service;
}

//Setters:

int service_setId( sService* service, int id )
{
    int verify = 0;
    if( service != NULL)
    {
        if( validateIntCondition(id,1,1) )
        {
            service->id = id;
            verify = 1;
        }
    }
    return verify;
}



int service_setName( sService* service, char* name )
{
    int verify = 0;
    if( name != NULL && service != NULL)
    {
        if( validateStringRange(name,1,32) )
        {
            strcpy( service->name, name);
            verify = 1;
        }
    }
    return verify;
}



int service_setEmail( sService* service, char* email )
{
    int verify = 0;
    if( email != NULL && service != NULL)
    {
        if( validateStringRange(email,4,64) )
        {
            strcpy( service->email, email);
            verify = 1;
        }
    }
    return verify;
}



//Getters



int service_getId( sService* service)
{
    return service->id;
}



char* service_getName( sService* service )
{
    return service->name;
}



char* service_getEmail( sService* service )
{
    return service->email;
}

#endif // XMENSAJES_H_INCLUDED

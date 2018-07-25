

void log_show(sLog* log)
{
    if( log != NULL )
    {
        xlkSortPrintf("%s,%s,%d,%d,%s",1,log->date,log->time,log->serviceId,log->gravedad,log->msg);
    }
}


//Constructor

sLog* log_newLog(void)
{
    sLog* log = (sLog*) malloc(sizeof(sLog));
    if(log != NULL)
    {
        strcpy( log->date, "" );
        strcpy( log->time, "" );
        strcpy( log->msg, "" );
        log->gravedad = 0;
        log->serviceId = 0;
    }
    return log;
}



//Setters



int log_setDate( sLog* log, char* date )
{
    int verify = 0;
    if( date != NULL && log != NULL)
    {
        if( validateStringRange(date,6,10) )
        {
            strcpy( log->date, date);
            verify = 1;
        }
    }
    return verify;
}



int log_setTime( sLog* log, char* time )
{
    int verify = 0;
    if( time != NULL && log != NULL)
    {
        if( validateStringRange(time,4,5) && validateIsCorrectTime(time,0) )
        {
            strcpy( log->time, time);
            verify = 1;
        }
    }
    return verify;
}


int log_setServiceId( sLog* log, int id )
{
    int verify = 0;
    if( log != NULL)
    {
        if( validateIntCondition(id,1,1) )
        {
            log->serviceId = id;
            verify = 1;
        }
    }
    return verify;
}



int log_setGravedad( sLog* log, int gravedad )
{
    int verify = 0;
    if( log != NULL)
    {
        if( validateIntRange(gravedad,0,9) )
        {
            log->gravedad = gravedad;
            verify = 1;
        }
    }
    return verify;
}



int log_setMsg( sLog* log, char* message )
{
    int verify = 0;
    if( log != NULL && message != NULL)
    {
        if( validateStringRange(message,1,64) )
        {
            strcpy(log->msg, message);
            verify = 1;
        }
    }
    return verify;
}



//Getters:



char* log_getDate( sLog* log )
{
    return log->date;
}



char* log_getTime( sLog* log )
{
    return log->time;
}



int log_getServiceId( sLog* log )
{
    return log->serviceId;
}



int log_getGravedad( sLog* log )
{
    return log->gravedad;
}



char* log_getMsg( sLog* log )
{
    return log->msg;
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

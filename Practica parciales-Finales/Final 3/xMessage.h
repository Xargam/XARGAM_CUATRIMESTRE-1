#ifndef XMESSAGE_H_INCLUDED
#define XMESSAGE_H_INCLUDED

typedef struct
{
    int messageId;
    char message[3501];
    int popularidad;
    int userId;

} sMessage;


sMessage* message_newMessage(void);

int message_setId( sMessage* message , int id );
int message_getId( sMessage* message );

int message_setMessage( sMessage* message , char* msg );
char* message_getMessage( sMessage* message );

int message_setUserId( sMessage* message , int userId );
int message_getUserId( sMessage* message );

int message_setPopularidad( sMessage* message , int popularidad );
int message_getPopularidad( sMessage* message );


#endif // XMESSAGE_H_INCLUDED

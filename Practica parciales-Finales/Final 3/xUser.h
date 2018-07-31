#ifndef XUSER_H_INCLUDED
#define XUSER_H_INCLUDED

typedef struct
{
    int userId;
    char nick[51];
    int popularidad;

} sUser;

sUser* user_newUser(void);

int user_setId( sUser* user , int id );
int user_getId( sUser* user );

int user_setNick(sUser* user, char* nick);
char* user_getNick(sUser* user);

int user_setPopularidad(sUser* user, int popularidad);
int user_getPopularidad(sUser* user);


#endif // XUSER_H_INCLUDED

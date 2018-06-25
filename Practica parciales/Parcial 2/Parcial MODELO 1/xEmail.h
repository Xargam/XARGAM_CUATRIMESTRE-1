#ifndef XEMAIL_H_INCLUDED
#define XEMAIL_H_INCLUDED

//DECLARACION DE ESTRUCTURAS:

typedef struct
{
    char name[100];
    char email[300];
    int status;

} eAdresseers ;

//BASICAS

eAdresseers* newAdresseer(int size);


#endif // XEMAIL_H_INCLUDED


#ifndef XEMAIL_H_INCLUDED
#define XEMAIL_H_INCLUDED

//DECLARACION DE ESTRUCTURAS:

typedef struct
{
    char name[300];
    char email[380];
    int status;

} eAdresseers ;

//PROTOTIPOS DE FUNCIONES

//PARSERS:

int addresseersParser(char* filePath , eDestinatarios** adresseers );

#endif // XEMAIL_H_INCLUDED


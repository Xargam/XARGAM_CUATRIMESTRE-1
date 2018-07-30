#ifndef XEMAIL_H_INCLUDED
#define XEMAIL_H_INCLUDED

//DECLARACION DE ESTRUCTURAS:

typedef struct
{
    char name[100];
    char email[300];
    int status;

} eDestinatarios ;

//BASICAS

eDestinatarios* xmailNewDestinatario(int size);
int xmailMostrarDestinatario(eDestinatarios* dest );
int xmailParser( char* filePath , arrayList* this  );
int xmailComparaEmail(void* dest1 ,void* dest2  );


#endif // XEMAIL_H_INCLUDED


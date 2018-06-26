#ifndef XCLIENTES_H_INCLUDED
#define XCLIENTES_H_INCLUDED

#define URGENTE 1
#define REGULAR 2

//Estructuras:

typedef struct
{
    long dni;
    int NumeroTurno;

} eClientes;


// FUNCIONES

int clientes_setTurno( eClientes* cliente, int turn , char* eMessage );
int clientes_setDni( eClientes* cliente, long dni, char* eMessage );

eClientes* clientes_pedirDatos(void);

eClientes* clientes_nuevoCliente(int cantidad);

int clientes_mostrarCliente(eClientes* cliente , int turn);




#endif // XCLIENTES_H_INCLUDED

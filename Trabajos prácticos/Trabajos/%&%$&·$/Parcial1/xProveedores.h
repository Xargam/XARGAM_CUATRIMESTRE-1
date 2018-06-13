#ifndef XPROVEEDORES_H_INCLUDED
#define XPROVEEDORES_H_INCLUDED

//Declaracion de estructuras:

typedef struct
{
    int codigoProveedor;
    char descripcion[51];
    int estado;

} eProveedores ;

//Funciones basicas:

void inicializarProveedores(eProveedores provs[], int provTam);

//ABM DEPENDENCIAS:

int buscarProveedor(eProveedores provs[], int provTam,int codigoProveedor);
int buscarLibreProveedores(eProveedores provs[], int provTam);
eProveedores pedirProveedor(void);

//ALTA, BAJA Y MODIFICACION:

int altaProveedor( eProveedores provs[], int provTam, int* codigoProveedor );
int bajaProveedor( eProveedores provs[], int provTam );
int modificarProveedor( eProveedores provs[], int provTam );

//FUNCIONES DE MUESTRA

void mostrarProveedor( eProveedores provVar );
void mostrarProveedores( eProveedores provs[] ,int provTam);

#endif // XPROVEEDORES_H



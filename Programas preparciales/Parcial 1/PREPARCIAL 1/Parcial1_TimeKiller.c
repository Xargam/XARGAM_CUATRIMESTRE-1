/*
*----------------------#METODO DE REDUCCION DEL 300% DEL TIEMPO DEL PARCIAL 1#-------------------------------------------*

*--------------------------------**ALTA BAJA MODIFICACION UNO A MUCHOS**-------------------------------------------------*


*--------------------------------------MODIFICACION DE ESTRCUTURAS-----------------------------------------------------*

USAR MATCH CASE Y WHOLE WORD!!!!!!!!!!!!!!

****ESTRUCTURA PRINCIPAL: eProductos
****ESTRUCTURA SECUNDARIA: eProveedores
****ESTRUCTURA ANIDADA A PRINCIPAL: eFecha

***MODIFICAR TODOS LOS PRINTFS QUE NOMBREN A LAS ESTRUCTURAS (REEMPLAZAR POR PALABRAS EN MAYUSCULA):

PRODUCTO
PRODUCTOS
PROVEEDOR
PROVEEDORES

***CAMBIAR CAMPOS DE TODAS LAS ESTRUCTURAS:

eProductos :
CAMBIAR LOS CAMPOS:

char descripcion[50] ;
char sexo ;
float importe ;
eFecha fechaIngreso ;
int codigoProveedor ;
int isBusy ;
int codigoProducto ;

eProveedores :
CAMBIAR LOS CAMPOS:

int codigoProveedor ;
char descripcion[50] ;
int isBusy ;

***MODIFICAR NOMBRAMIENTO DE CAMPOS EN TODOS LOS PRINTFS (REEMPLAZAR POR PALABRAS EN MAYUSCULA):
eProductos :

FECHA DE INGRESO
CODIGO DE PRODUCTO
CODIGO DE PROVEEDOR  //APLICA PARA LAS 2 ESTRUCTURAS YA QUE ES LA VARIABLE PUENTE.
SEXO
DESCRIPCION
IMPORTE
DIA
MES
ANIO

eProveedores :

DESCRIPCION
CODIGO DE PROVEEDOR


MODIFICAR CARGA DE DATOS A ESTRUCTURAS (NO USAR WHOLE WORD):

eProductos ESTRUCTURA PRINCIPAL:

.fechaIngreso.dia
.fechaIngreso.mes
.fechaIngreso.anio
.codigoProducto
.codigoProveedor
.importe
.descripcion

eProveedores ESTRUCTURA SECUNDARIA:

.descripcion
.codigoProveedor

CAMBIAR PARAMETROS DE FUNCIONES Y DOCUMENTACIONES

ESTRUCTURA PRINCIPAL:

prod[]   (SIN WHOLE WORD)
prodTam  (NO WHOLE WORD)
prodVar (NO WHOLE WORD)
prod     (WHOLE WORD )

ESTRUCTURA SECUNDARIA:

prov[] (SIN WHOLE WORD)
provTam (WHOLE WORD )
provVar (WHOLE WORD )
prov (WHOLE WORD )

TODAS LAS VARIABLES UTILIZADAS EN EL ABM:

LAS MAS GENERICAS:

indiceLibre
reg
verificacion
verif
indiceCoincidencia

NO GENERICAS:

descripcion
descripcion
indiceDelProducto
indiceDelProveedor
codigoDelProducto
codigoDelProveedor
indiceProductoRepetido
nuevoProducto
indiceProductoCodigo
codigoProductoRepetido

FUNCIONES:

harcodearProd  //XE1-1
harcodearProv //XE1-2
inicializarProductos //XE1-3
mostrarProductosPorProveedor //XE1-4
mostrarTodosLosProductos //XE1-5
mostrarProducto //XE1-6
buscarProducto //XE1-7
buscarIndiceLibreProd //XE1-8
pedirProducto //XE1-9
altaProducto //XE2-1
bajaProducto //XE2-2
modificarProducto //XE2-3
ordenarProductos //XE2-4
inicializarProveedores //XE2-5
mostrarTodosLosProveedores //XE2-6
mostrarProveedor  //XE2-7
buscarIndiceLibreProv //XE2-8
buscarProveedor //XE2-9
altaProveedor //XE3-
bajaProveedor //XE3-2
modificarProveedor //XE3-3
mostrarMenuProductos XE3-4
mostrarMenuProveedores XE3-5
*/

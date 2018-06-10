/*
*----------------------#METODO DE REDUCCION DEL 300% DEL TIEMPO DEL PARCIAL 1#-------------------------------------------*

*--------------------------------**ALTA BAJA MODIFICACION UNO A MUCHOS**-------------------------------------------------*


*--------------------------------------MODIFICACION DE ESTRCUTURAS-----------------------------------------------------*

USAR MATCH CASE SIEMPRE!!!!!!!!!!!!!!

****ESTRUCTURA PRINCIPAL: eProductos
****ESTRUCTURA SECUNDARIA: eProveedores
****ESTRUCTURA ANIDADA A PRINCIPAL: eFecha

***MODIFICAR TODOS LOS PRINTFS QUE DESCRIPCIONN A LAS ESTRUCTURAS (REEMPLAZAR POR PALABRAS EN MAYUSCULA):

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

eProveedores:
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

eProveedores:

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

prod[]   (NO WHOLE WORD)
prodTam  (NO WHOLE WORD)
prodVar (NO WHOLE WORD)
prod   (WHOLE WORD )

ESTRUCTURA SECUNDARIA:

prov[] (NO WHOLE WORD)
provTam (NO WHOLE WORD )
secVar (NO WHOLE WORD )
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
LegajoDelEmpleado
idDelSector
indiceEmpleadoRepetido
nuevoEmpleado
indiceEmpleadoLegajo
legajoEmpleadoRepetido

FUNCIONES:

harcodearEmp  //XE1-1
harcodearSec //XE1-2
inicializarEmpleados //XE1-3
mostrarEmpleadosPorSector //XE1-4
mostrarTodosLosEmpleados //XE1-5
mostrarEmpleado //XE1-6
buscarEmpleado //XE1-7
buscarIndiceLibreEmp //XE1-8
pedirEmpleado //XE1-9
altaEmpleado //XE2-1
bajaEmpleado //XE2-2
modificarEmpleado //XE2-3
ordenarEmpleados //XE2-4
inicializarSectores //XE2-5
mostrarTodosLosSectores //XE2-6
mostrarSector  //XE2-7
buscarIndiceLibreSec //XE2-8
buscarSector //XE2-9
altaSector //XE3-
bajaSector //XE3-2
modificarSector //XE3-3
mostrarMenuEmpleados XE3-4
mostrarMenuSectores XE3-5
*/

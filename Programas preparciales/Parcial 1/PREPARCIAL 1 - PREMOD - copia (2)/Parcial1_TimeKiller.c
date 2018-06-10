/*
*----------------------#METODO DE REDUCCION DEL 300% DEL TIEMPO DEL PARCIAL 1#-------------------------------------------*

*--------------------------------**ALTA BAJA MODIFICACION UNO A MUCHOS**-------------------------------------------------*


*--------------------------------------MODIFICACION DE ESTRCUTURAS-----------------------------------------------------*

USAR MATCH CASE SIEMPRE!!!!!!!!!!!!!!

****ESTRUCTURA PRINCIPAL: eEmpleados
****ESTRUCTURA SECUNDARIA: eSectores
****ESTRUCTURA ANIDADA A PRINCIPAL: eFecha

***MODIFICAR TODOS LOS PRINTFS QUE NOMBREN A LAS ESTRUCTURAS (REEMPLAZAR POR PALABRAS EN MAYUSCULA):

EMPLEADO
EMPLEADOS
SECTOR
SECTORES

***CAMBIAR CAMPOS DE TODAS LAS ESTRUCTURAS:

eEmpleados :
CAMBIAR LOS CAMPOS:

char nombre[50] ;
char sexo ;
float sueldo ;
eFecha fechaIngreso ;
int idSector ;
int isBusy ;
int legajo ;

eSectores:
CAMBIAR LOS CAMPOS:

int idSector ;
char descripcion[50] ;
int isBusy ;

***MODIFICAR NOMBRAMIENTO DE CAMPOS EN TODOS LOS PRINTFS (REEMPLAZAR POR PALABRAS EN MAYUSCULA):
eEmpleados :

FECHA DE INGRESO
LEGAJO
ID DE SECTOR  //APLICA PARA LAS 2 ESTRUCTURAS YA QUE ES LA VARIABLE PUENTE.
SEXO
NOMBRE
SUELDO
DIA
MES
ANIO

eSectores:

DESCRIPCION
ID DE SECTOR


MODIFICAR CARGA DE DATOS A ESTRUCTURAS (NO USAR WHOLE WORD):

eEmpleados ESTRUCTURA PRINCIPAL:

.fechaIngreso.dia
.fechaIngreso.mes
.fechaIngreso.anio
.legajo
.idSector
.sueldo
.nombre

eSectores ESTRUCTURA SECUNDARIA:

.descripcion
.idSector

CAMBIAR PARAMETROS DE FUNCIONES Y DOCUMENTACIONES

ESTRUCTURA PRINCIPAL:

emp[]   (NO WHOLE WORD)
empTam  (NO WHOLE WORD)
empVar (NO WHOLE WORD)
emp   (WHOLE WORD )

ESTRUCTURA SECUNDARIA:

sec[] (NO WHOLE WORD)
secTam (NO WHOLE WORD )
secVar (NO WHOLE WORD )
sec (WHOLE WORD )

TODAS LAS VARIABLES UTILIZADAS EN EL ABM:

LAS MAS GENERICAS:

indiceLibre
reg
verificacion
verif
indiceCoincidencia

NO GENERICAS:

descripcion
nombre
indiceDelEmpleado
indiceDelSector
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

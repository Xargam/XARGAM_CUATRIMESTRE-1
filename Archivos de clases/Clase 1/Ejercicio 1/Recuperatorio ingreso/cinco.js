function Mostrar()
{var dia
 dia = prompt("ingrese el dia");
 switch(dia)
 {
    case "lunes":    
    case "martes":
    case "miercoles":
    case "jueves":
    case "viernes":
    alert("a trabajar");
    break;

    case "sabado":
    case "domingo":
    alert("buen finde");
    break;

    default:
    alert("no es una dia valido");


 }   

}

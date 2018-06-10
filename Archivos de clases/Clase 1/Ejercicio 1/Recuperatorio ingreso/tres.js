function Mostrar()
{var precio;
 var porcentaje;
 var descuento;   
 var IVA=20
 var resultado;
 var resultadoconIVA
 var precioFinal
 precio = parseInt(prompt("ingrese precio"));
 porcentaje = parseInt(prompt("ingrese porcentaje"));
 
 descuento = parseInt(precio*porcentaje/100);
 resultado = parseInt(precio-descuento);
 alert("el descuento fue del "+ descuento +", "+"el precio con descuento fue "+ resultado +" y el iva fue "+ IVA +"%");
 resultadoconIVA = resultado*20/100;
 precioFinal = resultadoconIVA+resultado;
 document.getElementById("elPrecioFinal").value=precioFinal;


}

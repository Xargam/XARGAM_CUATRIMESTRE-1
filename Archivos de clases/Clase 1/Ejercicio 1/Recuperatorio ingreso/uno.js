
function Mostrar()
{var base;
 var altura;   
 var perimetro; 
 var superficie;

 altura = parseInt(prompt("ingrese altura"));
 base = parseInt(prompt("ingrese base"));
 
 superficie = parseInt(base*3);
 perimetro =base*3+altura*3;
 
 alert("la superfice del triangulo es "+ superficie +" y el perimetro del triangulo es "+ perimetro);

}


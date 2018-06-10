function Mostrar()
{var num1;
 var num2;
 var cuenta;
 var cuenta2;
 num1 =prompt("ingrese un numero");
 num2 =prompt("ingrese otro numero");
 if(num1==num2)
 {
    alert(num1+num2);
 }   
 else if(parseInt(num1)>parseInt(num2)) 
 {   
    cuenta = num1/num2;
    alert(cuenta);
 }
 else
 {
    cuenta2 =parseInt(num1)+parseInt(num2);
    alert(cuenta2);
 }
if(cuenta2<50)
{
    alert("la suma es "+cuenta2+" y es menor a 50");
}
}

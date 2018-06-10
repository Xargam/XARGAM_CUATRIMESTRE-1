function Mostrar()
{var notas
    notas = document.getElementById("laHora").value;
    
    switch(notas)
    {
       case "0":
       case "1":
       case "2":
       case "3":
       alert("la proxima se puede");
       break;
   
       case "4":
       case "5":
       case "6":
       alert("raspando");
       if(notas<="5")
       {
           alert("debes preocuparte mas");
       }
       break;

       case "7":
       case "8":
       case "9":
       case "10":
       alert("aprobo");
       if(notas>="8") 
       {
           alert("muy bien");
       }
       break; 
      
    default:
    alert("no es una nota valida");
    break;
}
}


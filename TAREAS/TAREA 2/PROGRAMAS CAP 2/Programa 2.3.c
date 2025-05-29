/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

 #include <stdio.h>
 /* Promedio curso. 
El programa, al recibir como dato el promedio de un alumno en un curso 
➥universitario, escribe aprobado si su promedio es mayor o igual a 6, o 
➥reprobado en caso contrario.
 PRO: variable de tipo real.  */
 void main(void)
 {
 float PRO;
 printf("Ingrese el promedio del alumno: ");
 scanf("%f", &PRO);
 
 if (PRO >= 6.0)
  printf("\nAprobado");
 else
  printf("\nReprobado");
 }
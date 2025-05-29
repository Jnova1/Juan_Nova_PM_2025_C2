/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

 #include <stdio.h>
 /* Promedio curso.
 El programa, al recibir como dato el promedio de un alumno en un curso
 niversitario, escribe aprobado si su promedio es mayor o igual a 6.
 PRO: variable de tipo real. */
 
 void main(void)
 {
     float PRO;
     printf( "ingrse el promedio del alumno ");
     scanf("%f" , &PRO);
     if (PRO >= 6)
     printf("\nAprobado");
 }
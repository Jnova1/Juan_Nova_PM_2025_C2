/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
 #include <stdio.h>
 /*  Promedio de sueldos. 
El programa, al recibir como datos seis sueldos de un empleado, calcula tanto el
 ➥ingreso total como el promedio mensual. 
 
 CLA: variable de tipo entero.
 SU1, SU2, SU3, SU4, SU5, SU6, ING, PRO: variables de tipo real.  */
 
 int main(void) {
    int CLA;
    float SU1, SU2, SU3, SU4, SU5, SU6, ING, PRO;

    printf("Ingrese la clave del empleado y los 6 sueldos:\n");
    scanf("%d %f %f %f %f %f %f", &CLA, &SU1, &SU2, &SU3, &SU4, &SU5, &SU6);

    ING = SU1 + SU2 + SU3 + SU4 + SU5 + SU6;
    PRO = ING / 6;

    printf("\n%d %.2f %.2f\n", CLA, ING, PRO);

    return 0;
}
#include <stdio.h>

/* busqueda binaria */

const int MAX=100;

void lectura(int[], int);                    /* prototipos de funciones*/
int binaria(int [], int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM>MAX || TAM<1);           /* se verifica que el tamnao del arreglo sea correcto */
    lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = binaria(VEC, TAM, ELE);          /* se llama a la funcion que busca en el arreglo. */

    if (RES)
        /* si RES tiene valor verdadero -diferente de 0-, se escribe la posicion en la que se encontro el elemento. */
        printf("\nEl elemento se encuentra en la posicion: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");
}

void lectura(int A[], int T)
/* la funcion lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

int binaria(int A[], int T, int E)
/* esta funcion se utiliza para realizar una busqueda binaria del elemto E en el arreglo unidimensional A de T elementos. si se encuentra el elemento la funcion regresa la posicion correspondiente.
en caso contrario, regresa 0 */

{
    int ELE, IZQ = 0, CEN, DER = T-1, BAN = 0;
    while ((IZQ <= DER) && (!BAN))
    {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            BAN = CEN;
        else
            if (E > A[CEN])
                IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }
    return (BAN);
}

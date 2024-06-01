#include <stdio.h>
#include <stdlib.h>

const char nombreDeArchivo[] = {"Archivito"};

int factorial (int x);
int potencia(int x, int i);
void mostrarArregloConRecursion(int arr[], int dim, int i);
void mostrarArregloConRecursionInversa(int arr[], int dim, int i);
int sumarArreglosConRecursion(int arr[], int dim, int i);
int buscarMenorConRecursividad(int arr[], int dim, int i, int menor);
void cargarArchivito(int dato);
int cargarNumero();
int buscarMenorEnUnArchivoPrincipal();
int buscarMenorConRecursividadEnUnArchivo(FILE * buff, int i, int menor);
void mostrarArchivo();
int buscarMenorEnUnArchivoPrincipal();
void buscarMenorEnArchivo(FILE* buff);
int capicuasExpress(int a[], int i, int validos);
void mostarArchivoRecursivoPrincipal();
void mostrarArchivoConRecursividad(FILE * buff);

int main()
{
    /*
    int x = 10;
    int factoria = factorial(x);
    printf("%d", factoria);
    */

    /*
    int x = 2;
    int poten = potencia(x, 0);
    printf("%d", poten);
    */

    /*
    int dim = 5;
    int array[5] = {1,2,3,4,5};
    mostrarArregloConRecursion(array, dim, 0);
    */
    /*
    int dim = 5;
    int array[5] = {1,2,3,4,5};
    int rta = sumarArreglosConRecursion(array, dim, 0);
    printf("%d", rta);
    */
    /*
    int dim = 5;
    int array[5] = {10, 2, 3, 4, 1};
    int menor = buscarMenorConRecursividad(array, dim, 0, 999);
    printf("%d\n", menor);
    */
    //mostrarArchivo();

    /*
    int menor = buscarMenorEnUnArchivoPrincipal();
    printf("%d", menor);
    */

    mostarArchivoRecursivoPrincipal();


    return 0;
}

int factorial (int x)
{
    int rta;
    if ( x == 0) rta = 1;
    else rta = x * factorial (x-1) ;
    return rta;
}

int potencia(int x, int i)
{
    int rta;
    if(i == x)
    {
        i = 0;
    }
    else
    {
        rta = x * x;
        potencia(x, i+1);
    }
    return rta;
}

void mostrarArregloConRecursion(int arr[], int dim, int i)
{
    if (i >= dim)
    {
        printf("\n");
    }
    else
    {
        printf("|%d|", arr[i]);
        mostrarArregloConRecursion(arr, dim, i+1);
    }
}
void mostrarArregloConRecursionInversa(int arr[], int dim, int i)
{
    if (i >= dim)
    {
        i = 0;
    }
    else
    {
        mostrarArregloConRecursion(arr, dim, i-1);
        printf("|%d|", arr[i]);
    }
}

int sumarArreglosConRecursion(int arr[], int dim, int i)
{
    int rta = 0;
    if (i >= dim)
    {
        i = 0;
    }
    else
    {
        rta += arr[i] + sumarArreglosConRecursion(arr, dim, i+1);
    }
    return rta;
}

int buscarMenorConRecursividad(int arr[], int dim, int i, int menor)
{
    if (i >= dim)
    {
        system("cls");
    }
    else
    {
        if (arr[i] < menor)
        {
            menor = arr[i];
        }
        return buscarMenorConRecursividad(arr, dim, i + 1, menor);
    }
    return menor;
}

void cargarArchivito(int dato)
{
    FILE* buff;

    buff = fopen(nombreDeArchivo, "ab");

    if (buff)
    {
        fwrite(&dato, sizeof(int), 1, buff);
    }


    fclose(buff);
    printf("Se cerro\n");
}

int cargarNumero()
{
    int dato = 0;
    printf("Que numero queries cargar?\n");
    scanf("%d", &dato);
    return dato;
}

int buscarMenorEnUnArchivoPrincipal()
{
    int menor = 0;
    FILE * buff = fopen(nombreDeArchivo, "r+b");

    if(buff)
    {
        fseek(buff, sizeof(int), SEEK_SET);
        //menor = buscarMenorConRecursividadEnUnArchivo(buff, 0, 99999);
    }

    fclose(buff);
    return menor;
}


void mostrarArchivo()
{
    FILE* buff;
    int aux;
    buff = fopen(nombreDeArchivo, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(int), 1, buff)) > 0)
        {
            printf("Contenido del archivo: %d\n", aux);
        }
    }

    fclose(buff);
}

int capicuasExpress(int a[], int i, int validos)
{
    int rta;
    if (i < validos)
    {
        if (a[i] == a[validos-1])
        {
            rta = capicuasExpress(a, i+1, validos-1);
        }
        else
        {
            rta = 0;
        }
    }
    else
    {
        rta = 1;
    }
    return rta;
}




void invertir(FILE * buff, int posUlt, int posPrim)
{
    int ppio, fin;

    if (posPrim < posUlt){
        fseek(buff, sizeof(int) * posUlt,0);
        fread(&fin, sizeof(int),1, buff);

        fseek(buff, sizeof(int) * posPrim,0);
        fread(&ppio, sizeof(int),1, buff);

        fseek(buff, sizeof(int) * posPrim,0);
        fwrite(fin, sizeof(int), 1, buff);

        fseek(buff, sizeof(int) * posUlt,0);
        fwrite(ppio, sizeof(int), 1, buff);
    }
}

void mostarArchivoRecursivoPrincipal(){
    FILE * buff = fopen(nombreDeArchivo, "rb");

    if (buff){
        mostrarArchivoConRecursividad(buff);
    }
    fclose(buff);
}

void mostrarArchivoConRecursividad(FILE * buff){
    int valor;
    if (fread(&valor, sizeof(int), 1, buff) > 0){
        mostrarArchivoConRecursividad(buff);
        printf("|%d|", valor);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 5

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;

} eEmpleado;

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[],int tam);
void modificarEmpleado(eEmpleado vec[],int tam);
void ordenarEmpleados(eEmpleado vec[],int tam);


int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM]={{1234, "Juan", 'm', 30000, 1},{2222, "Ana", 'f', 32000, 1}, {2211, "Jorge", 'm', 28000, 1},{5000,"Ramiro",'m',15000,1},{1015,"Belen",'f',27500,1}};
    //inicializarEmpleados(lista, TAM);


    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");

            mostrarEmpleados(lista, TAM);
            bajaEmpleado(lista,TAM);
            printf("\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");

            mostrarEmpleados(lista,TAM);
            modificarEmpleado(lista,TAM);
            printf("\n");
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            ordenarEmpleados(lista,TAM);
            system("pause");
            break;

        case 5:
            printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eEmpleado emp){

    printf("   %d       %10s     %c    %.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);

}

void mostrarEmpleados(eEmpleado vec[], int tam){
    int contador = 0;
    int i;

    printf(" Legajo   Nombre  Sexo  Sueldo\n\n");
    for(i=0; i < tam; i++){
        if(vec[i].ocupado == 1){
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }

    if( contador == 0){
        printf("\nNo hay empleados que mostrar\n\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam){

    int indice = -1;
    int i;

     for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0){
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo){

    int indice = -1;
    int i;

     for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo){
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam){

int indice;
int legajo;
int esta;


indice = buscarLibre(vec, tam);

if( indice == -1){

    printf("\nNo hay lugar en el sistema\n");
}
else{
     printf("Ingrese legajo: ");
     scanf("%d", &legajo);

     esta = buscarEmpleado(vec, tam, legajo);

     if( esta != -1){
        printf("Existe un empleado de legajo %d en el sistema\n", legajo);
        mostrarEmpleado(vec[esta]);
     }
     else{
        vec[indice].legajo = legajo;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(vec[indice].nombre);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &vec[indice].sexo );

        printf("Ingrese sueldo: ");
        scanf("%f", &vec[indice].sueldo );

        vec[indice].ocupado = 1;

        printf("\nAlta empleado exitosa!!!\n\n");

     }
 }
}

void bajaEmpleado(eEmpleado vec[],int tam)
{
    int i, aux;
    char auxrta;
    int flag = 0;

    printf("Ingrese legajo del empleado a dar de baja:");
    scanf("%d",&aux);

    for(i=0;i<tam;i++)
    {
        if(vec[i].legajo == aux)
        {
            flag = 1;
            mostrarEmpleado(vec[i]);

            printf("Desea dar de baja el empleado? s/n\n\n");
            fflush(stdin);
            auxrta = getch();

            if(auxrta == 's' || auxrta == 'S')
            {
                vec[i].ocupado = 0;
                printf("Baja realizada con exito\n\n");
                break;

            }
            else
            {
                printf("Baja cancelada\n\n");
                break;

            }
        }
    }

    if(flag == 0)
    {
        printf("\nNo se ha encontrado un empleado correspondiente al legajo ingresado\n\n");
    }
}

void modificarEmpleado(eEmpleado vec[],int tam)
{
    int auxLegajo;
    int i;
    char auxrta;

    printf("Ingrese legajo del empleado que desea modificar sueldo:");
    scanf("%d",&auxLegajo);

    for(i=0;i<tam;i++)
    {
        if(vec[i].legajo == auxLegajo)
        {
            mostrarEmpleado(vec[i]);

            printf("Seguro desea modificar el sueldo del empleado seleccionado? s/n\n\n");
            fflush(stdin);
            auxrta = getch();

            if(auxrta == 's' || auxrta == 'S')
            {
                printf("Ingrese nuevo sueldo:");
                scanf("%f",&vec[i].sueldo);
                printf("Modificacion realizada con exito\n\n");
                break;
            }
            else
            {
                printf("Modificacion cancelada\n\n");
                break;
            }
        }
    }
}


void ordenarEmpleados(eEmpleado vec[],int tam)
{
   eEmpleado aux;
      int i,j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
           if(vec[i].sueldo < vec[j].sueldo)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

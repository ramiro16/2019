#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "empleado.h"

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

    printf("%d%10s%5c%10.2f%7d/%d/%d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo,emp.fechaNac.dia,emp.fechaNac.mes,emp.fechaNac.anio);

}

void mostrarEmpleados(eEmpleado vec[], int tam){
    int contador = 0;
    int i;

    printf(" Legajo   Nombre  Sexo  Sueldo   Fecha de Nac.\n\n");
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

        printf("Ingrese fecha de nacimiento\n");
        printf("Dia:");
        scanf("%d",&vec[indice].fechaNac.dia);
        printf("Mes:");
        scanf("%d",&vec[indice].fechaNac.mes);
        printf("Anio:");
        scanf("%d",&vec[indice].fechaNac.anio);


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

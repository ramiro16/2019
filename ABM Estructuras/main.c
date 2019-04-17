#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"

#define TAM 5

/*
-Listar Sectores que tengan al menos 1 empleado
-Listar Empleados por sectores (Tomar sector y mostrar empleados)
-Tomar empleado y mostrar datos y sector
-Ordenamiento
*/

int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM]={{1234, "Juan", 'm', 30000, 1,{16,8,1997}},{2222, "Ana", 'f', 32000, 1,{1,12,1977}}, {2211, "Jorge", 'm', 28000, 1,{25,12,1990}},{5000,"Ramiro",'m',15000,1,{14,3,2001}},{1015,"Belen",'f',27500,1,{29,11,1957}}};
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
            printf("\n");
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

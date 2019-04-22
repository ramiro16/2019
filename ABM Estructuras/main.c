#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"

#define TAM 5
#define TAMS 4

/*
-Listar Sectores que tengan al menos 1 empleado
-Listar Empleados por sectores (Tomar sector y mostrar empleados)
-Tomar empleado y mostrar datos y sector
-Ordenamiento
*/

void mostrarSectores(eSector[],eEmpleado[],int tamS,int tamE);

int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM]={{1234, "Juan", 'm', 30000, 1,{16,8,1997},2},{2222, "Ana", 'f', 32000, 1,{1,12,1977},1}, {2211, "Jorge", 'm', 28000, 1,{25,12,1990},3},{5000,"Ramiro",'m',15000,1,{14,3,2001},4},{1015,"Belen",'f',27500,1,{29,11,1957},4}};
    eSector listaS[TAMS]={{1,"RR.HH"},{2,"ADMIN"},{3,"SOPORTE"},{4,"OTROS"}};
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
            mostrarSectores(listaS,lista,TAMS,TAM);
            printf("\n");
            system("pause");
            break;

        case 7:
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

void mostrarSectores(eSector listaS[],eEmpleado listaE[],int tamS,int tamE)
{
    int i,j;

    printf("Sectores con al menos 1 empleado:\n\nID SECTOR\tNOMBRE\n\n");

    for(i=0;i<tamS;i++)
    {
        for(j=0;j<tamE;j++)
        {
            if(listaE[j].ocupado == 1 && listaE[j].idSector == listaS[i].id)
            {
                printf("%d\t%s\n",listaS[i].id,listaS[i].desc);
            }
        }
    }
}

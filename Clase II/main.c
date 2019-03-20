#include <stdio.h>
#include <stdlib.h>

//De 0 a 6 "a dormir", de 7 a 9 "buenos dias", resto (de 10 a 23) "cualquier cosa"

int main()
{
   // int dato = 0;
    char opcion;

    /*while(dato < 10)
    {
        //dato++;
        printf("Dato vale: %d\n",dato+1);
        dato++;

    }


    do
    {

     dato++;
     printf("Dato vale: %d\n",dato);

    }while(dato < 10);


    for(dato=0;dato<10;dato++)
    {
        printf("Dato vale: %d\n",dato+1);
    }

    printf("Fuera del for dato vale: %d", dato);*/

    printf("Ingrese opcion:");
    fflush(stdin);
    scanf("%c",&opcion);

 /* switch(opcion)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf("A dormir!");
            break;
        case 7:
        case 8:
        case 9:
            printf("Buenos dias!");
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
            printf("Como estamos?");
            break;
        default:
            printf("Opcion invalida!");
            break;

    }


    switch(opcion)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            printf("A dormir!");
            break;
        case '7':
        case '8':
        case '9':
            printf("Buenos dias!");
            break;
        case '10':
        case '11':
        case '12':
        case '13':
        case '14':
        case '15':
        case '16':
        case '17':
        case '18':
        case '19':
        case '20':
        case '21':
        case '22':
        case '23':
            printf("Como estamos?");
            break;
        default:
            printf("Opcion invalida!");
            break;

    }*/



    return 0;
}

typedef struct
{
    int id;
    char desc[31];
}eSector;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha fechaNac;
    int idSector;

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

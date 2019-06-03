#include "Employee.h"
#include <stdlib.h>
#include <string.h>

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo > 0 && sueldo < 100000)
    {
        this-> sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;

}
int employee_getSueldo(Employee* this, int* sueldo)
{
    int todoOk = 0;

    if(this != NULL && sueldo != NULL)
    {

        *sueldo = this->sueldo;

        todoOk = 1;
    }

    return todoOk;

}

Employee* employee_new()
{
    Employee* newEmpleado = (Employee*) malloc(sizeof(Employee));


    if(newEmpleado != NULL)
    {
        newEmpleado->id = 0;
        strcpy(newEmpleado->nombre,"");
        newEmpleado->horasTrabajadas = 0;
        newEmpleado->sueldo = 0;
    }

    return newEmpleado;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmpleado = (Employee*) malloc(sizeof(Employee));
    int todoOk = 0;

    if(newEmpleado != NULL)
    {
        newEmpleado->id= atoi(idStr);
        strcpy(newEmpleado->nombre,nombreStr);
        newEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);

        if( employee_setId(newEmpleado,atoi(idStr)) == 1)
        {
            if(employee_setNombre(newEmpleado,nombreStr) == 1)
            {
                if(employee_setHorasTrabajadas(newEmpleado,horasTrabajadasStr) == 1)
                {
                    if(employee_setSueldo(newEmpleado,sueldoStr) == 1)
                    {
                       todoOk = 1;
                    }
                }
            }
        }

        if(todoOk == 0)
        {
            free(newEmpleado);
            newEmpleado = NULL;
        }
        //newEmpleado->sueldo = atoi(sueldoStr);
    }

    return newEmpleado;



}


int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if( this != NULL && id > 0)
    {
        this-> id = id;
        todoOk = 1;
    }

    return todoOk;

}
int employee_getId(Employee* this, int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {

        *id = this->id;

        todoOk = 1;
    }

    return todoOk;

}


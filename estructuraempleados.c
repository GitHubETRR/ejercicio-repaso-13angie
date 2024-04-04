#include <stdio.h>
#define cantcaracteres 50
#define maxempleados 5

//definir una estructura llamada empleado con: nombre, edad, salario

typedef struct{
  char nombre [cantcaracteres];  
  unsigned int edad;
  float salario;
}datos;

//declarar vector de hasta 5 empleados, funciones : ingresardatos, procesardatos,mostrardatos

void menu(datos[]);
void ingresardatos(datos[], int);
void procesardatos(datos[], int);
void mostrardatos(datos[], int);


int main (void){
  datos empleado[maxempleados];
  menu(empleado);
}

void menu (datos empleado[]){
    int opcionelegida, cantempleados;
    printf("\n----Men%c----\nBienvenido al programa.\nAqu%c podr%c ingresar y mostrar la informaci%cn de sus empleados.\nPor favor, ingrese 1, 2 o 3 de acuerdo a su necesidad.\n\n", 163, 161, 160, 162);
    do{
        printf("1. Ingresar datos del empleado.\n");
        //ingresar datos
        printf("2. Mostrar informaci%cn relevante.\n", 162);
        //Procesar y Mostrar datos
        printf("3. Salir del programa.\n");
        //salida
        do{
            printf("ingrese su opci%cn: ", 162);
            scanf("%i", &opcionelegida);
            if (opcionelegida != 1 && opcionelegida != 2 && opcionelegida != 3){
                printf("La opci%cn que usted ingres%c no est%c permitida. Por favor, ingrese 1, 2 o 3 cual sea su preferencia.\n", 162, 162, 160);
            }
        } while (opcionelegida != 1 && opcionelegida != 2 && opcionelegida != 3);
        if (opcionelegida >= 1 && opcionelegida <= 3) {
            switch (opcionelegida){
                case 1:
                printf("\nCu%cntos empleados quiere ingresar%c. El m%cximo es cinco.\n", 160, 63, 160);
                do{
                printf("Cantidad de empleados a ingresar: ");
                scanf("%i", &cantempleados);
                if (cantempleados > maxempleados && cantempleados < 0){
                    printf("Cantidad no permitida. Por favor, ingrese un valor entre 1 y 5.\n");
                }
                } while (cantempleados > maxempleados && cantempleados < 0);
                ingresardatos(empleado, cantempleados);
                break;
                case 2:
                procesardatos(empleado, cantempleados);
                mostrardatos(empleado, cantempleados);
                break;
            }
        }
    } while (opcionelegida != 3);
}
void ingresardatos(datos empleado [], int cantempleados){
    for (int i = 0; i < cantempleados; i++){
        printf("Empleado N%c %i.\n", 167, i+1);
        printf("Nombre del empleado: ");
        scanf("\n%[^\n]s", &empleado[i].nombre);
        do{
             printf("Edad del empleado: ");
            scanf("%i", &empleado[i].edad);
            if (empleado[i].edad < 0){
                printf("Se debe ingresar una edad con un valor mayor a cero. Por favor, vuelva a intentarlo.\n");
            }
        } while (empleado[i].edad < 0);
        do{
            printf("Salario del empleado: ");
            scanf("%f", &empleado[i].salario);
            if (empleado[i].salario < 1){
                printf("Se debe ingresar un salario con un valor mayor a uno. Por favor, vuelva a intentarlo.\n");
            }  
        } while ((empleado[i].salario < 1));
        printf("\n");
    }
    printf("\nDatos ingresados de forma correcta.\n");
    printf("-----------------------------------------------------------------------------------\n");
}

void procesardatos(datos empleado[], int cantempleados){
    float prom = 0, prom2;
    int mayor = 0;
    for (int i = 0; i < cantempleados; i++){
        prom += empleado[i].salario;
    }
    prom /= cantempleados;
    prom2 = prom / empleado[0].salario;
    printf("\nEl promedio de salarios es de: %c%f\n",36, prom);
    if (prom2 != 1) {
        for (int i = 0; i < cantempleados; i++){
            if(empleado[i].salario > mayor){
                mayor = i;
            }
        }
        printf("El empleado con el mayor salario es: %s, con un valor de %c%f\n", empleado[mayor].nombre, 36, empleado[mayor].salario);
    } else {
        printf("Todos los salarios son iguales, con un valor de %f\n", empleado[0].salario);
    }
    printf("-----------------------------------------------------------------------------------\n");
}
void mostrardatos(datos empleado[], int cantempleados){
    for (int i = 0; i < cantempleados; i++){
        printf("Empleado %d: Nombre: %s, edad: %i, salario: %c%f\n", i + 1, empleado[i].nombre, empleado[i].edad, 36, empleado[i].salario);
    }
    printf("-----------------------------------------------------------------------------------\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct compu{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef compu;

compu ingresar();
compu ingresarAleatorio();
void mostrar(compu computadora);

int main(){
    compu *PC = malloc(5 * sizeof(compu));
    int opcion;

    puts("Ingresar 1 para mostrar datos aleatorio, 2 para ingresar por el usuario");
    scanf("%d", &opcion);
    for(int i = 0; i < 5; i++){
        if(opcion == 2) *(PC + i) = ingresar();
        if(opcion == 1) *(PC + i) = ingresarAleatorio();
        mostrar(*(PC + i));
        printf("\n");
    }

    free (PC);
    return 0;
}

compu ingresar(){
    compu computadora;

    puts("Ingrese la velocidad de procesamiento en GHz:");
    scanf("%d", &computadora.velocidad);

    puts("Ingrese el anio de fabricacion:");
    scanf("%d", &computadora.anio);
    
    puts("Ingrese la cantidad de nucleos:");
    scanf("%d", &computadora.cantidad);

    puts("Ingrese el tipo de procesador:");
    computadora.tipo_cpu = malloc(50 * sizeof(char));
    scanf("%s", computadora.tipo_cpu);

    return computadora;
}

compu ingresarAleatorio(){
    compu computadora;
    int numAleatorio;
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    computadora.velocidad = 1 + rand() % 3;
    computadora.anio = 2000 + rand() % 17;
    computadora.cantidad = 1 + rand() % 4;
    numAleatorio = rand() % 6;
    computadora.tipo_cpu = malloc(strlen(tipos[numAleatorio]));
    strcpy(computadora.tipo_cpu, tipos[numAleatorio]);

    return computadora;
}

void mostrar(compu computadora){

    printf("Velocidad del procesador en GHz: %d\n", computadora.velocidad);
    printf("Anio de fabricacion: %d\n", computadora.anio);
    printf("Cantidad de nucleos: %d\n", computadora.cantidad);
    printf("Tipo de procesador: %s\n", computadora.tipo_cpu);

    return;
}
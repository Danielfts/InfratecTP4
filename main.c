// Juan Esteban Lopez Ulloa
// 202021417
// je.lopezu1@uniandes.edu.co

#include <stdio.h>
#include <stdlib.h>

int reversarInt(int num){
    int resultado = 0;
    int bits = sizeof(num) * 8; // Se saba el numero total de los bits que contiene un numero del arreglo
    for(int i = 0; i < bits; i++){ // Bucle que permite recorrer los numeros bit a bit.
        resultado = (resultado << 1) | (num & 1); // Se hace el nuevo numero bit a bit desplazandolo a la izquierda y poniendo el bit menos significativo del nuemro original
        num >>= 1;
    }
    return resultado;
}

void invertirVector(int* vector, int n){
    for(int i = 0; i < n; i++){
        vector[i] = reversarInt(vector[i]);
    }
}

int main(){
    int n;
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Error: el tamaño del vector debe ser mayor que 0.\n");
        return 1;
    }
    int* vector = (int*) calloc(n, sizeof(int));
    printf("Ingrese los elementos del vector (separados por espacio):\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &vector[i]);
    }
    invertirVector(vector, n);
    printf("El vector invertido es:\n");
    for (int i = n-1; i >= 0; i--) {
    printf("0x%02X ", vector[i]);
}
    //printf("Oprima una tecla para continua terminar el programa ... ");
    printf("\n");
    free(vector);
    return 0;
}

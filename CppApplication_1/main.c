/* 
 * File:   main.c
 * Author: Guillermo Rojas, Patricio Espinoza, Ricardo Soto.
 *
 * Created on 15 de abril de 2013, 20:34
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct {
    int matriz [10][4];
}matrix;

void fill_matrix (matrix* generic_matrix, int resources_value, int process_value){
    int i, j, values;
    for (i=0; i<process_value; i++)
        for (j=0; j<resources_value; j++){
        
            printf("Escriba un valor para el recurso R",j"Y el proceso P", i); /*Crear las excepciones para valores monstruosos*/
            scanf("%d",&values);
            generic_matrix->matriz[i][j];
        }        
    
}

void need_matrix(matrix need, matrix maximum, matrix assigned, int resources_value, int process_value){
    int i, j;
    for (i=0; i<process_value; i++);
        for (j=0; j<resources_value; j++);
        need->matriz[i][j]=maximum.matriz[i][j]-assigned.matriz[i][j];
}

int main(int argc, char** argv) {
    int resources_value, process_value;
    matrix assigned, maximum, need;
    printf("Escriba Cantidad de Recursos. Máximo 4"); /*Crear las excepciones*/
    scanf("%d", &resources_value);
    printf("Escriba Cantidad de Procesos. Máximo 10"); /*Crear las excepciones*/
    scanf("%d", &process_value);
    
    
    
    
    return (EXIT_SUCCESS);
}


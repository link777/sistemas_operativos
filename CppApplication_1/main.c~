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

void fill_matrix (matrix* generic_matrix, int resources_quantity, int process_quantity){
    int i, j, values;
    for (i=0; i<process_quantity; i++)
        for (j=0; j<resources_quantity; j++){
        
            printf("Escriba un valor para el recurso R",j);printf("Y el proceso P", i); /*Crear las excepciones para valores monstruosos*/
            scanf("%d",&values);
            generic_matrix->matriz[i][j];
        }        
    
}

void need_matrix(matrix* need, matrix maximum, matrix assigned, int resources_quantity, int process_quantity){
    int i, j;
    for (i=0; i<process_quantity; i++);
        for (j=0; j<resources_quantity; j++);
        need->matriz[i][j]=maximum.matriz[i][j]-assigned.matriz[i][j];
}

void fill_disponibility(int* disponibility, int resources_quantity){
    int i=0, value_disponibility; 
    do{
        printf("Escriba un valor para el recurso R", i);
        scanf("%d", &value_disponibility);
        disponibility[i]= value_disponibility;
        i++;
    } while (i<resources_quantity);
    
}
void select_from_maximum (matrix assigned, int* disponibility, int resources_quantity, int process_quantity, int* auxiliar){
    int i, j, aux=0, auxiliar[resources_quantity];
    for(j=0; j<process_quantity; j++){
        for(i=0; i<resources_quantity; i++)
              aux = aux+assigned.matriz[i][j];
        int auxiliar[j]= aux;
    }
}

void first_step(int* disponibility, int* auxiliar, int resources_quantity ){
    int i; 
    for(i=0; i<resources_quantity; i++){
        disponibility[i]= disponibility[i]- auxiliar[i];
    }
}

void matching_need (int* disponibility, matrix need){
    
}

int main(int argc, char** argv) {
    int resources_quantity, process_quantity,i=0;
    matrix assigned, maximum, need;
    printf("Escriba Cantidad de Recursos. Máximo 4"); /*Crear las excepciones con do-while*/
    scanf("%d", &resources_quantity);
    int disponibility[resources_quantity];
    int auxiliar[resources_quantity];
    printf("Escriba Cantidad de Procesos. Máximo 10"); /*Crear las excepciones con do-while*/
    scanf("%d", &process_quantity);
    
    
    
    
    
    return (EXIT_SUCCESS);
}



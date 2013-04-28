/* 
 * File:   main.c
 * Author: Guillermo Rojas, Patricio Espinoza, Ricardo Soto.
 * Ta listo, hay que puro programarlo.
 *
 * Created on 15 de abril de 2013, 20:34
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


typedef struct {
    int matriz [5][10]; /*Procesos x recursos y un proceso(casilla)extra como bandera 
                         *para saber si es el mínimo, cuàntos mínimos hay
                         * y si hay más de uno, el que libera más recursos*/
} matrix;

void fill_matrix(matrix* generic_matrix, int resources_quantity, int process_quantity) {
    int i, j, values;
    for (i = 0; i < process_quantity; i++)
        for (j = 0; j < resources_quantity; j++) {

            printf("Escriba un valor para el recurso R", j);
            printf("Y el proceso P", i); /*Crear las excepciones para valores 
                                          * monstruosos*/
            scanf("%d", &values);
            generic_matrix->matriz[i][j];
        }

}

void fill_need_matrix(matrix* need, matrix maximum, matrix assigned, int resources_quantity, int process_quantity) {
    int i, j;
    for (i = 0; i < process_quantity; i++);
    for (j = 0; j < resources_quantity; j++);
    need->matriz[i][j] = maximum.matriz[i][j] - assigned.matriz[i][j];
}

void fill_disponibility(int* disponibility, int resources_quantity) {
    int i = 0, value_disponibility;
    do {
        printf("Escriba un valor para el recurso R", i);
        scanf("%d", &value_disponibility);
        disponibility[i] = value_disponibility;
        i++;
    } while (i < resources_quantity);

}

void sumadelvalordelosrecursosporprocesos(matrix assigned, int* aux, int resources_quantity, int process_quantity) {
    int i, j, aux = 0, auxiliar[4];
    for (j = 0; j < process_quantity; j++) {
        for (i = 0; i < resources_quantity; i++)
            aux = aux + assigned.matriz[i][j];
        auxiliar[j] = aux;
    }
}

void disponibility_i(int* disponibility, int aux, int resources_quantity) {
    int i;
    for (i = 0; i < resources_quantity; i++)
        disponibility[i] = disponibility[i] - aux[i];
}

void flaging_candidates(matrix need, int* disponibility, int resources_quantity, int process_quantity) {
    int i, j, cont = 0;
    for (i = 0; i < process_quantity; i++) {
        for (j = 0; j < resources_quantity; j++) {
            if (need.matriz[i][j] == 0) {
                cont++;
            }
            if (need.matriz[i][j] < disponibility[j]) {
                j++;
                if (j == resources_quantity && cont != resources_quantity)
                    need.matriz[i][5] = 1; /*fijo, para que siempre preguntemos 
                                            * por el mismo valor*/
            } else {
                j = j + disponibility; /*Para salirnos del ciclo*/
            }
        }

    }
}

void flagging_ideal_maximum(matrix* need, matrix maximum, int process_quantity, int resources_quantity) {
    int i, j, ideal[5], test[5], x, sum = 0, aux = 0;
    for (i = 0; i < process_quantity; i++) {
        if (need->matriz[i][5] == 1) { /*¿Es un candidato? Si lo es, 
                                        * cópielo en un vector auxiliar*/
            for (x = 0; x < process_quantity; x++) {
                ideal[x] = need->matriz[i][x]; /*Llena un vector ideal con el 
                                                * primero que encuentre*/
                sum = sum + ideal[x];
                x = x + process_quantity; /*me aseguro que elija sólo 1 candidato*/
            }
            i = i + process_quantity; /*para salirme del ciclo*/
        }
    }
    for (i = 0; i < process_quantity; i++)
        if (need->matriz[i][5] == 1) { /*¿Es un candidato? Si lo es, cópielo en 
                                        * un vector auxiliar*/
            for (x = 0; x < process_quantity; x++) {
                test[x] = need->matriz[i][x]; /*Llena un vector ideal con el 
                                               * primero 
                                               * que encuentre*/
                aux = aux + test[x];
            }
            if (aux < sum)
                sum = aux; /*Si es menor, elija éste*/
            else
                need->matriz[i][5] = 0; /*Si libera menos recursos, bajo la bandera*/
        }


}

void asdf(matrix* assigned, matrix maximum, matrix* need, int resources_quantity, int process_quantity, int* disponibility) {
    int i, j, k, suma[resources_quantity], resta[resources_quantity];
    for (i = 0; i < process_quantity; i++) { /*Dónde está la bandera*/
        if (need->matriz[i][5] == 1) { /*Sólo hay una bandera*/
            for (j = 0; j < process_quantity; j++) { /*Acá está la magia*/
                resta[j] = maximum.matriz[i][j] - assigned->matriz[i][j];
                assigned->matriz[i][j] = maximum.matriz[i][j]; /*Cambio los valores 
                                                                * de la matriz de 
                                                                * asignados por los de 
                                                                * la matriz de máximos*/
                need->matriz[i][j] = 0; /*Lleno con ceros la matriz de necesidad, */

            }

            /*Acá podría ir un print que muestre este procedimiento de restar 
             * la diferencia y luego la suma del maximo, para obtener un nuevo 
             vector de disponibilidad en el tiempo ti*/
            for (k = 0; k < resources_quantity; k++)
                disponibility[k] = disponibility[k] - resta[k];
            for (k = 0; k < resources_quantity; k++)
                disponibility[k] = disponibility[k] + maximum.matriz[i][k];

        }
    }
}

void choosing_candidates(matrix* need, matrix maximum, int process_quantity, int resources_quantity) {
    int j, i, cont = 0;
    for (i = 0; i < process_quantity; i++)
        if (need->matriz[i][5] = 1)
            cont++;
    if (cont == 0)
        printf("No es posible realizar el algoritmo del banquero. El sistema es inestable.\n No existen los recursos suficientes");
    if (cont == 1)
        j = 1;
    else {
        flagging_ideal_maximum(matrix* need, matrix maximum, int process_quantity, int resources_quantity);
    }



}

int main(int argc, char** argv) {
    int resources_quantity, process_quantity, i = 0;
    matrix assigned, maximum, need;
    printf("Escriba Cantidad de Recursos. Máximo 4"); /*Crear las excepciones con do-while*/
    scanf("%d", &resources_quantity);
    int disponibility[resources_quantity];
    int auxiliar[resources_quantity];
    printf("Escriba Cantidad de Procesos. Máximo 10"); /*Crear las excepciones con do-while*/
    scanf("%d", &process_quantity);

    /*Falta hacer en el programa principal un menú para llenar las matrices
     *  con sus respectivas invocaciones y parámetros. Hacer unos printf que dibuje 
     las matrices paso por paso, con la función sleep(n) donde n es tomado en segundos
     hacer un procedimiento condición de término*/





    return (EXIT_SUCCESS);
}



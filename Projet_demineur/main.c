//
//  main.c
//  Projet_demineur
//
//  Created by Paul-Henri on 08/12/2016.
//  Copyright © 2016 Paul-Henri Zimmerlin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define BOMBES 20

void afficher_tableau(int a[N][N]);

int main(int argc, const char * argv[]) {
    int tableau_complet[N][N];
    int bombes_placees = 0, max_colonne = 0, max_ligne = 0;
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(bombes_placees < BOMBES){
                tableau_complet[i][j] = 9;
                bombes_placees++;
                max_colonne = i;
                max_ligne = j;
            }
            else tableau_complet[i][j] = 0;
        }
    }
    for (int i = 0; i <= max_colonne; i++){
        for (int j = 0; j <= max_ligne; j++){
            int var_temp;
            int i_alea = rand() % N;
            int j_alea = rand() % N;
            var_temp = tableau_complet[i_alea][j_alea];
            tableau_complet[i_alea][j_alea] = tableau_complet[i][j];
            tableau_complet[i][j] = var_temp;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(tableau_complet[i][j] == 9){
                if(tableau_complet[i-1][j] != 9 && (i-1) >= 0) tableau_complet[i-1][j]++;
                if(tableau_complet[i-1][j-1] != 9 && (i-1) >= 0 && (j-1) > 0) tableau_complet[i-1][j-1]++;
                if(tableau_complet[i-1][j+1] != 9 && (i-1) >= 0 && (j+1) < N) tableau_complet[i-1][j+1]++;
                if(tableau_complet[i][j-1] != 9 && (j-1) >= 0) tableau_complet[i][j-1]++;
                if(tableau_complet[i][j+1] != 9 && (j+1) < N) tableau_complet[i][j+1]++;
                if(tableau_complet[i+1][j] != 9 && (i+1) < N) tableau_complet[i+1][j]++;
                if(tableau_complet[i+1][j-1] != 9 && (i+1) < N && (j-1) >= 0) tableau_complet[i+1][j-1]++;
                if(tableau_complet[i+1][j+1] != 9 && (i+1) < N && (j+1) < N) tableau_complet[i+1][j+1]++;
            }
        }
    }
    afficher_tableau(tableau_complet);
    return 0;
}

void afficher_tableau(int a[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

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

void afficher_tableau_entier(int a[N][N]);
void afficher_tableau_char(char a[N][N]);

int main(int argc, const char * argv[]) {
    int tableau_complet[N][N];
    int bombes_placees = 0, max_colonne = 0, max_ligne = 0, x, y, tentative = 0, perdu = 0;
    char tableau_user[N][N];
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
            tableau_user[i][j] = 'X';
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
    afficher_tableau_char(tableau_user);
    do {
        printf("Quelle case souhaitez-vous découvrir ?\n");
        scanf("%d %d", &x, &y);
        switch (tableau_complet[x][y]) {
            case 0:
                tableau_user[x][y] = '0';
                break;
            case 1:
                tableau_user[x][y] = '1';
                break;
            case 2:
                tableau_user[x][y] = '2';
                break;
            case 3:
                tableau_user[x][y] = '3';
                break;
            case 4:
                tableau_user[x][y] = '4';
                break;
            case 5:
                tableau_user[x][y] = '5';
                break;
            case 6:
                tableau_user[x][y] = '6';
                break;
            case 7:
                tableau_user[x][y] = '7';
                break;
            case 8:
                tableau_user[x][y] = '8';
                break;
            case 9:
                tableau_user[x][y] = 'O';
                perdu = 1;
            default:
                break;
        }
        tentative++;
        afficher_tableau_char(tableau_user);
        printf("\n");
        //afficher_tableau_entier(tableau_complet);
        //printf("\n\n");
    } while ((N*N) - tentative != BOMBES && perdu != 1);
    
    if(perdu == 0)printf("Félicitations, vous avez gagné !\n");
    else printf("Vous avez perdu :(\n");
    //afficher_tableau_entier(tableau_complet);
    //afficher_tableau_char(tableau_user);
    return 0;
}

void afficher_tableau_entier(int a[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void afficher_tableau_char(char a[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}

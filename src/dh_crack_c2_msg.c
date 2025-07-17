#include"Headers.h"
/// \brief main pour le module dh_crack_c2
/// \file dh_crack_c2_msg.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021

#include"Headers.h"
void xor(char *clef,int nb_clef,char *texte,char *texte_uncrypt){
    /// \brief effectue le xor des differentes clefs avec le texte crypté de base
    /// \param[in] clef,nb_clef,texte,texte_uncrypt
    /// \param[out ] texte_uncrypt
    /// \return void
    long taille_texte= strlen(texte);
    int i=0;
    while(i<taille_texte){
        texte_uncrypt[i]=texte[i]^clef[i%nb_clef];
        i++;
    }
    texte_uncrypt[i]='\0';
}

void combi_2x (char clef[][10],int *taille_clef, FILE *fich){
    /// \brief Toutes les combinaisons de clefs de taille 2
    /// \param[in] clef,taille_clef,fich
    /// \param[out ] fich
    /// \return void
    for(int i=0;i<taille_clef[0];i++){
       for(int j=0;j<taille_clef[1];j++){
                        fprintf(fich,"%d",clef[0][i]);
                        fprintf(fich,"%d ",clef[1][j]);
       }
    }
}
void combi_3x(char clef[][10],int *taille_clef,FILE *fich){
    /// \brief Toutes les combinaisons de clefs de taille 3
    /// \param[in] clef,taille_clef,fich
    /// \param[out ] fich
    /// \return void
    for(int i=0;i<taille_clef[0];i++){
       for(int j=0;j<taille_clef[1];j++){
           for(int k=0;k<taille_clef[2];k++){

                        fprintf(fich,"%d",clef[0][i]);
                        fprintf(fich,"%d",clef[1][j]);
                        fprintf(fich,"%d ",clef[2][k]);
           }
       }
    }
}

void combi_4x(char clef[][10],int *taille_clef, FILE *fich){
    /// \brief Toutes les combinaisons de clefs de taille 4
    /// \param[in] clef,taille_clef,fich
    /// \param[out ] fich
    /// \return void
    for(int i=0;i<taille_clef[0];i++){
       for(int j=0;j<taille_clef[1];j++){
           for(int k=0;k<taille_clef[2];k++){
                for(int l=0;l<taille_clef[3];l++){
                        fprintf(fich,"%d",clef[0][i]);
                        fprintf(fich,"%d",clef[1][j]);
                        fprintf(fich,"%d",clef[2][k]);
                        fprintf(fich,"%d ",clef[3][l]);
                }
            }
        }
    }    
} 


void combi_5x(char clef[][10],int *taille_clef, FILE *fich){
    /// \brief Toutes les combinaisons de clefs de taille 5
    /// \param[in] clef,taille_clef,fich
    /// \param[out ] fich
    /// \return void
    for(int i=0;i<taille_clef[0];i++){
       for(int j=0;j<taille_clef[1];j++){
           for(int k=0;k<taille_clef[2];k++){
                for(int l=0;l<taille_clef[3];l++){
                    for(int m=0;m<taille_clef[4];m++){
                        fprintf(fich,"%d",clef[0][i]);
                        fprintf(fich,"%d",clef[1][j]);
                        fprintf(fich,"%d",clef[2][k]);
                        fprintf(fich,"%d",clef[3][l]);
                        fprintf(fich,"%d ",clef[4][m]);

                    }
                }
            }
        }
    }    
}
void combi_6x(char clef[][10],int *taille_clef, FILE *fich){
    /// \brief Toutes les combinaisons de clefs de taille 6
    /// \param[in] clef,taille_clef,fich
    /// \param[out ] fich
    /// \return void
    for(int i=0;i<taille_clef[0];i++){
       for(int j=0;j<taille_clef[1];j++){
           for(int k=0;k<taille_clef[2];k++){
                for(int l=0;l<taille_clef[3];l++){
                    for(int m=0;m<taille_clef[4];m++){
                        for(int n=0;n<taille_clef[5];m++){
                        fprintf(fich,"%d",clef[0][i]);
                        fprintf(fich,"%d",clef[1][j]);
                        fprintf(fich,"%d",clef[2][k]);
                        fprintf(fich,"%d",clef[3][l]);
                        fprintf(fich,"%d ",clef[4][m]);
                        fprintf(fich,"%d ",clef[5][m]);
                        }
                    }
                }
            }
        }
    }    
}

void combi_7x(char clef[][10],int *taille_clef, FILE *fich){
    /// \brief Toutes les combinaisons de clefs de taille 7
    /// \param[in] clef,taille_clef,fich
    /// \param[out ] fich
    /// \return void
    for(int i=0;i<taille_clef[0];i++){
       for(int j=0;j<taille_clef[1];j++){
           for(int k=0;k<taille_clef[2];k++){
                for(int l=0;l<taille_clef[3];l++){
                    for(int m=0;m<taille_clef[4];m++){
                        for(int n=0;n<taille_clef[5];m++){
                             for(int o=0;o<taille_clef[6];m++)
                        fprintf(fich,"%d",clef[0][i]);
                        fprintf(fich,"%d",clef[1][j]);
                        fprintf(fich,"%d",clef[2][k]);
                        fprintf(fich,"%d",clef[3][l]);
                        fprintf(fich,"%d ",clef[4][m]);
                        fprintf(fich,"%d ",clef[5][m]);
                        fprintf(fich,"%d ",clef[6][m]);
                        }
                    }
                }
            }
        }
    }    
}


void combinaisons(char clef[][10],int *taille_clef,int nb_clef,char keys[][nb_clef],int nb_clef_potentielle){
    /// \brief permet le lancement des différentes combinaisons de clefs possible  à partir du nombre de CLEF(seul méthode trouver pour effectuer le produit cartésien de N liste)
    /// \param[in] clef,taille_clef,nb_clef,key,nb_clef,nb_clef_potentielle
    /// \param[out] keys
    /// \return void
    FILE *fich1=fopen("fichier_clef.txt","w");
    if(fich1==NULL){
        fprintf(stderr,"\n Erreur: impossible de lire le fichier fichier_clef.txt \n");
        exit (1);
    }
    char c[nb_clef];
    int i=0;
    if (nb_clef ==2) combi_2x (clef,taille_clef,fich1);
    else if (nb_clef==3) combi_3x (clef,taille_clef,fich1);
    else if (nb_clef==4) combi_4x (clef,taille_clef,fich1);
    else if (nb_clef==5) combi_5x (clef,taille_clef,fich1);
    else if (nb_clef==6) combi_6x (clef,taille_clef,fich1);
     else if (nb_clef==7) combi_7x (clef,taille_clef,fich1);
    fclose(fich1);
    FILE *fich2=fopen("fichier_clef.txt","r");
    if(fich2==NULL){
        fprintf(stderr,"\n Erreur: impossible de lire le fichier fichier_clef.txt \n");
        exit (1);
    }
    while(fscanf(fich2,"%s",c)!= EOF){
        strcpy(keys[i],c);
        i++;
    }
    fclose(fich2);
}

void analyse_freq(SCORE *freq,char *texte_uncrypt){
    /// \brief attribue les différentes frequences des lettres à une clé candidate
    /// \param[in] freq, texte_uncrypt
    /// \param[out] freq
    /// \return void
    for(int i=0;i<strlen(texte_uncrypt);i++){
        int j=0;
        if (isalpha(texte_uncrypt[i])){
            while(freq[j].car!=tolower(texte_uncrypt[i]) && j<25) j++ ;
        }
        if (j<25){
            (freq[j].score)++;
        }
    }
}
int calcul_distance(SCORE *freq,int distance_th){
    /// \brief calcul la distance entre freq et freq_th
    /// \param[in] freq, distance_th
    /// \return distance
    int distance=0;
    for(int i=0;i<26;i++){
        distance+=freq[i].score;
    }
    return distance_th-distance;
}


int dh_crack_c2 (char *texte,int nb_clef,int *taille_clef,char clef[][10]) {
    /// \brief la fonction dh_crack_c2 implémente l'algorithme du module C2
    /// \param[in] 1 tableau de caractère (texte), 1 tableau d'entiers(taille_clef), 1 tableaux à double dimensions d'entiers (clef) et 1 entier(nb_clef)
    /// \return 0
    int nb_clef_potentielle=1;
    int indice_distance_min,distance_min;
     for(int i=0;i<nb_clef;i++) nb_clef_potentielle*=taille_clef[i];
    char keys[nb_clef_potentielle] [nb_clef] ;
    combinaisons(clef,taille_clef,nb_clef,keys,nb_clef_potentielle);
    char texte_uncrypt[LONGMAX];
    SCORE freq[]={{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0},{'y',0},{'z',0}};
    xor(keys[0],nb_clef,texte,texte_uncrypt);
    analyse_freq(freq,texte_uncrypt);
    indice_distance_min=0;
    distance_min=calcul_distance(freq,SOMME_TH);
    for(int i=1;i<nb_clef_potentielle;i++){
        int distance;
        SCORE freq[]={{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0},{'y',0},{'z',0}};
        xor(keys[i],nb_clef,texte,texte_uncrypt);
        analyse_freq(freq,texte_uncrypt);
        distance=calcul_distance(freq,SOMME_TH);
        if(distance<distance_min){
            indice_distance_min=i;
        }
    }
    printf("%d combinaisons de clefs possibles\n",nb_clef_potentielle);
    printf("la clef ayant obtenue le meilleur score statistique est ");
    for(int i=0;i<nb_clef;i++) printf("%c",keys[indice_distance_min][i]);
    printf("\n");
  
    

return 0;
}

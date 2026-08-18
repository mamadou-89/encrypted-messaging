#include"Headers.h"
/// \brief main pour le module dh_crack_c1
/// \file dh_crack_c1.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021

void supprimer_elts(char clef[][10],int i,int k,int m){

    /// \brief la fonction supprimer_elts permet de supprimer un élément d'un tableau static
    /// \param[in] un tableau à deux dimensions d'entiers (clef), et trois en entiers (i,m,k) permettant de situer la suppression  dans le tableau
    /// \param[out] clef
    /// \return void
    
    char inter;
    for (int j=k;j<m;j++){
        inter=clef[i][j];
        clef[i][j]=clef[i][j+1];
        clef[i][j+1]=inter;
    }

}

bool verif(char clef,int taille_texte,int *taille_clef,int numero_clef,char *texte,int nb_clef){

    /// \brief la fonction verif permet de verifier si la clef choisi peut être ajouter à la liste des clef potentielles
    /// \param[in] 1 tableau de caractère(texte), 1 tableau d'entiers(taille_clef), 3 entiers(taille_texte,numero_clef,nb_clef) et 1 caractère(clef) 
    /// \return true or false

    int j=numero_clef;
    while(j<taille_texte){
        if (clef=='0' && numero_clef==0){
            taille_clef[numero_clef]=taille_clef[numero_clef]-1;
            return false;
        }
        else if (isalnum(clef^texte[j])!=0 || ispunct(clef^texte[j])!=0 || isspace(clef^texte[j])!=0 ) j+=nb_clef;
        else {
            taille_clef[numero_clef]=taille_clef[numero_clef]-1;
            return false;
        }
    }
    return true;
}
int dh_crack_c1(char *texte,int nb_clef,int *taille_clef, char clef[][10]){

    /// \brief la fonction dh_crack_c1 implémente l'algorithme du module C1
    /// \param[in] 1 tableau de caractère (texte), 1 tableau d'entiers(taille_clef), 1 tableaux à double dimensions d'entiers (clef) et 1 entier(nb_clef)
    /// \return 0

    // initialisation de clef[taille_clef][max_caractères]
    for(int i=0;i<nb_clef;i++){
        for(int j=0;j<10;j++) clef[i][j]=j;
    }
    int taille_texte=strlen(texte);

    for (int i=0;i<nb_clef;i++){
        for (int k=0;k<10;k++){
            if (!verif(k+'0',taille_texte,taille_clef,i,texte,nb_clef)){
                supprimer_elts(clef,i,k,taille_clef[i]);
            }
        }
    }


for (int i=0;i<nb_clef;i++){
    printf("[");
    for(int j=0;j<taille_clef[i];j++){
        printf("%d,",clef[i][j]);
        }
        printf("]\n");
    }


return 0;
}

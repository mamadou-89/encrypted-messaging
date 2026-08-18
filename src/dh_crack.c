#include"Headers.h"
/// \brief main pour le module dh_crack
/// \file dh_crack.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021

int main(int argc,char **argv ){

    /// \brief permet de lancer la commande dh_crack suivie de ses arguments
    /// \param[in] argc et argv
    /// \return 0
    
    char fichier[TAILLE]="NULL",crack[TAILLE]="NULL",key[TAILLE]="NULL";
    char c,texte[LONGMAX];
    balise_crack(argc,argv,fichier,crack,key);
    FILE *fich;
    int compteur=0;
    if((fich=fopen(fichier,"r"))==NULL){
    fprintf(stderr,"le fichier %s n'est pas accessible",fichier);
    exit(-1);
    }
    while((fread(&c,sizeof(char),1,fich))==1){
    texte[compteur]=c;
    compteur++;
    }
    fclose(fich);
    texte[compteur]='\0';
    int nb_clef=atoi(key);
    // Déclaration statique du tableau clef
    char clef [nb_clef][10];
    int taille_clef[nb_clef];
    for (int i=0;i<nb_clef;i++) taille_clef[i]=10;
    
    if (strcmp(crack,"c1")==0){
        dh_crack_c1(texte,nb_clef,taille_clef,clef);
    }
     else if (strcmp(crack,"all")==0){
        dh_crack_c1(texte,nb_clef,taille_clef,clef);
        dh_crack_c2(texte,nb_clef,taille_clef,clef);
    }
    return 0;
}
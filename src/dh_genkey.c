#include "Headers.h"
/// \brief main pour le module dh_genkey
/// \file dh_genkey.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021

int main(int argc,char **argv){
    
    /// \brief permet le lancement de la commande dh_genkey suivie de ses arguments
    /// \param[in] argc et argv
    /// \return 0

    FILE *f=NULL;
    char fichier[TAILLE]="NULL";
    long clef_commune;
   FILE *logfp=fopen("debug.txt","w");
    balise_key(argc,argv,fichier);
    srand (time (NULL));
    //création de p,g,a,b
  
    int cpt;
    long premier = genPrimeSophieGermain(MIN_PRIME,MAX_PRIME,&cpt);
    long a=random_long(1,premier-1);
    long b=random_long(1,premier-1);
    long generateur = seek_generator(rand()%101,premier); // exemple 100
    long ordre = puissance_mod_n (generateur, premier-1, premier); // generateur^{premier -1} (mod premier)
    assert (generateur != -1);


    // affichage sur l'écran
    if (strcmp(fichier,"stdout")==0){
        
        fprintf(logfp,"\nGénération de la clef partagée\n");
        fprintf(logfp,"Premier (Sophie Germain) = %ld\n",premier);
        printf("Premier (Sophie Germain) = %ld\n",premier);
        fprintf(logfp,"Générateur = %ld ordre = %ld\n",generateur,ordre);
        printf("Générateur = %ld ordre = %ld\n",generateur,ordre);
        clef_commune= Diffie_Hellman(a,b,generateur, premier);
        printf("Clef_commune = %ld de taille %d\n",clef_commune,nb_digit_base10(clef_commune));
        
    }
    else{

        // affichage dans un fichier donnée en paramètre
        if((f=fopen(fichier,"w"))==NULL){
            fprintf(stderr,"\n Erreur: impossible d'écrire sur le fichier %s\n",fichier);
            exit (1);
        }
        fprintf(logfp,"\nGénération de la clef partagée\n");
        fprintf(logfp,"Premier (Sophie Germain) = %ld\n",premier);
        fprintf(f,"Premier (Sophie Germain) = %ld\n",premier);
        fprintf(logfp,"Générateur = %ld ordre = %ld\n",generateur,ordre);
        fprintf(f,"Générateur = %ld ordre = %ld\n",generateur,ordre);
        clef_commune= Diffie_Hellman(a,b,generateur, premier);
        fprintf(f,"Clef_commune = %ld de taille %d\n",clef_commune,nb_digit_base10(clef_commune));
        fclose(f);
    }
    
    fclose(logfp);

    return 0;
}

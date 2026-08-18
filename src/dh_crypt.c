#include"Headers.h"
/// \brief main pour le module dh_crypt(xor uniquement)
/// \file dh_crypt.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021

int main (int argc, char *argv[]){
    
    /// \brief permet le lancement de la commande dh_crypt suivie de ses argumments
    /// \param[in] argc et argv
    /// \return 0
    
    char fichier_init[TAILLE]="NULL",fichier_crypt[TAILLE]="NULL",key[TAILLE]="NULL";
    char crypt,c;
    FILE *f1=NULL,*f2=NULL;
    int i=0;
    balise_xor(argc,argv,fichier_init,fichier_crypt,key);
    int taille_key=strlen(key);
    // vérification et ouverture des fichiers d'entrées
    f1=fopen(fichier_init,"rb");
    if(f1==NULL){
        fprintf(stderr,"\n Erreur: impossible de lire le fichier %s\n",fichier_init);
        exit (1);
    }
    f2=fopen(fichier_crypt,"wb");
    if(f2==NULL){
         fprintf(stderr,"\n Erreur: impossible d'écrire ou de créer le fichier %s\n",fichier_crypt);
         exit(2);
    }
    // Cryptage du message directemet par la méthode xor
    while((fread(&c,sizeof(char),1,f1) == 1)){
        crypt=c^key[i%taille_key];
        fwrite(&crypt,sizeof(char),1,f2);
        i++;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
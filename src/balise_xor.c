#include"Headers.h"
/// \brief balise pour le module dh_crypt(xor uniquement)
/// \file balise_xor.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021

void balise_xor(int argc, char *argv[],char *chaine1,char *chaine2,char *chaine3){
    /// \brief stocke les différents arguments passés par la ligne de commande pour le module dh_crack
	/// \param[in] 3 pointeurs de chaines de caractères vide: chaine1, chaine2, chaine3
    /// \param[out]  chaine1 (nom_fichier de départ),chaine2(nom_fichier de destination),chaine3(clef)
	/// \return void
	
	int option;
	char mode[TAILLE];
// chaine1,chaine2,chaine3 correspondent ici respectivement au fichier de départ,au fichier d'écriture et à la clef choisi pour le cryptage.
    if(strcmp(argv[1],"-h")==0){
        printf("-i suivie du nom du fichier contenant le message crypté\n -m suivie de la méthode de cryptage \n -k suivie de la taille de la clef \n -m suivie de la methode de chiffrement (c1 ou c2 )\n-h affichant l aide des commandes. Cette option, si elle est presente, annule toutes les autres.\n");
        exit(EXIT_SUCCESS);
    }
    if (argc<9){
        fprintf(stderr,"la commande dh_crypt exige 8 arguments pour pouvoir s'éxécuter,veuillez relancer avec les bon arguments\n");
        exit(-1);
    }
    while((option=getopt(argc,argv,"i:o:k:m:h"))!=-1){
        switch (option){
            case 'i':
                strcpy (chaine1,optarg);
                break;
            case 'o':
                strcpy (chaine2,optarg);
                break;
            case 'k':
                strcpy (chaine3,optarg);
                break;
            case 'm' :
                strcpy (mode,optarg);
                break;
            case 'h':
            printf("-i suivie du nom du fichier contenant le message a chiffrer\n -o suivie du nom du fichier ou l on va ecrire le chiffre \n -k suivie de la clef \n -m suivie de la methode de chiffrement : xor ou cbc-crypt(attention la methode cbc n'est pas presente) suivie du vecteur d’initialisation, ou cbc-uncrypt suivie egalement du vecteur d’initialisation -h affichant l aide des commandes. Cette option, si elle est presente, annule toutes les autres.\n");
            exit(EXIT_SUCCESS);
            default:
            fprintf (stderr,"Mauvais argument saisi veuillez relancer le programme avec les bons arguments");
            exit(2);
        }
    }
        if (strcmp(chaine1,"NULL")==0){
           fprintf(stderr,"la commande dh_crypt nécéssite comme paramètre un fichier sur lequel le message à crypter doit être lu à l'aide de l'argument -i , veuillez relancer le programme avec les bons arguments\n");
            exit (EXIT_FAILURE);
    }
        else if(strcmp(chaine3,"NULL")==0){
            fprintf(stderr,"la commande dh_crypt nécéssite comme paramètre une clef qui doit être saisie à l'aide de l'argument -k , veuillez relancer le programme avec les bons arguments\n");
            exit (EXIT_FAILURE);
        }
        else if(strcmp(chaine2,"NULL")==0){
            fprintf(stderr,"la commande dh_crypt nécéssite comme paramètre un fichier vers lequel le message crypté sera écrit à l'aide de l'argument -o , veuillez relancer le programme avec les bons arguments\n");
            exit (EXIT_FAILURE);
    }
        else if(strcmp(mode,"cbc-uncrypt")==0){
        fprintf(stderr,"le module cbc n'a pas été implémenter pour la commande dh_crypt, veuillez relancer le programme avec le xor\n");
        exit (EXIT_FAILURE);
    }
    else if(strcmp(mode,"xor")!=0){
        fprintf(stderr,"la commande dh_crypt ne peut s'éxécuter qu'avec le mode xor,veuillez relancer le programme avec les bons arguments\n");
        exit (EXIT_FAILURE);    
    }
}
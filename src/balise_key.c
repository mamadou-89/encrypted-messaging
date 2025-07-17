#include"Headers.h"
/// \brief balise pour le module dh_genkey
/// \file balise_key.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021

void balise_key(int argc, char *argv[],char *chaine1){
	int option;
	/// \brief stocke les différents arguments passés par la ligne de commande pour le module dh_genkey
	/// \param[in] 1 pointeurs de chaines de caractères vide: chaine1
	/// \param[out] chaine1(nom_fichier)
	/// \return void
	
	// chaine1 corresponds au fichier dans lequel seront écrits les résultats de l'échange de clefs.
	if (argc==1) strcpy (chaine1,"stdout");
	else if (argc!=3 && argc!=1 && argc!=4 && argc!=2 ){
	fprintf(stderr,"la commande dh_genkey exige 1 argument  ou  aucun  pour pouvoir s'éxécuter,veuillez relancer avec les bon arguments\n");
	exit(-1);
		}
	else if(strcmp(argv[1],"-h")==0){
		printf("-i suivie du nom du fichier contenant le message crypté\n -m suivie de la méthode de cryptage \n -k suivie de la taille de la clef \n -m suivie de la methode de chiffrement (c1 ou c2 )\n-h affichant l aide des commandes. Cette option, si elle est presente, annule toutes les autres.\n");
		exit(EXIT_SUCCESS);
	}
	
	else {
		while((option=getopt(argc,argv,"o:h"))!=-1){
			switch (option){
				case 'o':
					strcpy (chaine1,optarg);
					break;
				case 'h':
				printf(" -o suivie d’un nom de fichier ou les résultats seront écrits\n -h affichant l aide des commandes. Cette option, si elle est presente, annule toutes les autres.\n");
				exit(EXIT_SUCCESS);
				default:
				fprintf (stderr,"Mauvais argument saisi veuillez relancer le programme avec les bons arguments");
				exit(-1);
				
			}
		}
			if(strcmp(chaine1,"NULL")==0){
            fprintf(stderr,"la commande dh_genkey nécéssite comme paramètre un fichier sur lequel les informations calculés doivent être écrites,saisie à l'aide de l'argument -o , veuillez relancer le programme avec les bons arguments\n");
            exit (-1);
    		}
		}

}

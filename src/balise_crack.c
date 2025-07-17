#include"Headers.h"

/// \brief balise pour le module dh_crack
/// \file balise_crack.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021


void balise_crack (int argc, char *argv[],char *chaine1,char *chaine2,char *chaine3){
	/// \brief stocke les différents arguments passés par la ligne de commande pour le module dh_crack
	/// \param[in] 3 pointeurs de chaines de caractères vide: chaine1,chaine2, chaine3
	/// \param [out] chaine1(nom_fichier),chaine2(méthode_choisie),chaine3(taille_clef)
	/// \return void
	
	int option;
	// chaine1,chaine2,chaine3 correspondent ici respectivement au fichier contenant le message crypté, à la méthode de crackage chosi et la taille de la clef.
	if(strcmp(argv[1],"-h")==0){
			printf("-i suivie du nom du fichier contenant le message crypté\n -m suivie de la méthode de cryptage \n -k suivie de la taille de la clef \n -m suivie de la methode de chiffrement (c1 ou c2 )\n-h affichant l aide des commandes. Cette option, si elle est presente, annule toutes les autres.\n");
			exit(EXIT_SUCCESS);
	}
	if (argc<7){
	fprintf(stderr,"la commande dh_crack exige 6 argument pour pouvoir s'éxécuter,veuillez relancer avec les bon arguments\n");
	exit(-1);
	}
	while((option=getopt(argc,argv,"i:m:k:h"))!=-1){
		switch (option){
			case 'i':
				strcpy (chaine1,optarg);
				break;
			case 'm':
				strcpy (chaine2,optarg);
				break;
			case 'k':
				strcpy (chaine3,optarg);
				break;
			case 'h':
			printf("-i suivie du nom du fichier contenant le message crypté\n -m suivie de la méthode de cryptage \n -k suivie de la taille de la clef \n -m suivie de la methode de chiffrement (c1 ou c2 )\n-h affichant l aide des commandes. Cette option, si elle est presente, annule toutes les autres.\n");
			exit(EXIT_SUCCESS);
			default:
			fprintf (stderr,"Mauvais argument saisi veuillez relancer le programme avec les bons arguments");
			exit(-1);
			
		}
	}
		if(strcmp(chaine1,"NULL")==0){
		fprintf(stderr,"la commande dh_crack nécéssite comme paramètre un fichier sur lequel le message crypter doit être lu à l'aide de l'argument -i , veuillez relancer le programme avec les bons arguments\n");
		exit (EXIT_FAILURE);
}
	else if(strcmp(chaine3,"NULL")==0){
		fprintf(stderr,"la commande dh_crack nécéssite comme paramètre la taille de la clef qui doit être saisie à l'aide de l'argument -k , veuillez relancer le programme avec les bons arguments\n");
		exit (EXIT_FAILURE);
	}
	else if ( strcmp(chaine2,"NULL")==0 || ( strcmp(chaine2,"c1")!=0 && strcmp(chaine2,"all")!=0)){
		fprintf(stderr,"la commande dh_crack nécéssite comme paramètre la méthode de crack voulu (c1 ou all) donné à l'aide de l'argument -m , veuillez relancer le programme avec les bons arguments\n");
		exit (-1);
}
}
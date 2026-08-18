#ifndef DH_H
#define DH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <ctype.h> // opérations sur les caractères
#include <getopt.h>
#include <unistd.h>

#define MAX_PRIME 4294967296/1000 // 2^32 = sqrt(2^64)
#define MIN_PRIME 100
#define MAX_FACTEURS 10 // nb max de facteurs premiers d'un nombre
#define BLOCK_SIZE 16 // taille des blocs pour CBC
#define LONGMAX 10000
#define ERROR -1
#define END -1
#define TAILLE 260 // la taille d'un paramètre  d'un nom  fichier et d'un chemin d'accès est estimé a 260 octets pour le projet
#define SOMME_TH  88 // qui represente la somme théorique de toute les fréquences des lettres d'un texte en anglais

extern FILE *logfp; // fichier pour le debug
typedef unsigned char byte; // octet
typedef byte block_t[BLOCK_SIZE]; // bloc CBC : un octet par case

void balise_xor (int argc, char *argv[],char *chaine1, char *chaine2, char *chaine3);
void balise_key (int argc, char *argv[],char *chaine1);
void balise_crack (int argc, char *argv[],char *chaine1, char *chaine2, char *chaine3);
int dh_crack_c1(char *texte,int nb_clef, int *taille_clef,char clef[][10]);
int dh_crack_c2(char *texte,int nb_clef,int *taille_clef,char clef[][10]);


long random_long(long min,long max);
int rabin (long a, long n) ;
long puissance_mod_n (long a, long e, long n);
long generePremierRabin(long min,long max,int *cpt);
long seek_generator(long start,long p);
int nb_digit_base10(long n);
long generate_shared_key(long min,long max);
long genPrimeSophieGermain(long min,long max,int *cpt);
long xchange_shared_key(long generateur, long premier);
long int_pow(long a, long e);
int Diffie_Hellman (long a,long b,long generateur,long premier);

typedef struct {

/// \struct SCORE pour la construction des fréquences constituant le tableau des fréquences théoriques Freq_th
    char car;
    int score;
} SCORE ;

#endif










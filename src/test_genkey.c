#include"Headers.h"
/// \brief Test pour le module dh_genkey
/// \file test_genkey.c
/// \author Djibo.S Mamadou
/// \date 10 janvier 2021
int test_genkey(){
    /// \brief fonction lançant les differents test prédefinies

    if (xchange_shared_key(5,23)!=2) exit(-1);
    if (Diffie_Hellman(2999297,97318,5,3569927)!=2975212) exit(-1);
    if (Diffie_Hellman(1340147,67067,5,4796423)!=32652) exit(-1);
    if (Diffie_Hellman(2121333,158477,5,3687287)!=2516699) exit(-1);
}
int main(void){
    /// \brief main de la fonction de test
    test_genkey();
    return 0;
}
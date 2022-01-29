//
//  evaluateur.h
//  arbreV2
//
//  Created by Nicolas on 23/11/2020.
//

#ifndef evaluateur_h
#define evaluateur_h

#include <stdio.h>
#include "binTree.h"


/**
 * Retourne la valeur de l'image associe à x pour la fonction.
 * @param tree L'abre représentant le code postfixé
 * @param x L'abcse donné pour réaliser le calcul
 * @param error entier qui signifie si "l'image existe". 0 si pas de pb de def et 1 si pb
 */
float treeToFunction(Node * tree, float x, int * error);


/**
 * Retourne la taille du tableau
 * @param borneInf La borne inférieur de l'interval
 * @param borneSup La borne supérieur de l'interval
 * @param pas Indique l'intervalle de calcul des images de la fonction
 * @param erreur Modifie la valeur du int en fonciton de l'erreur
 */
int tailleTableauImage(int borneInf, int borneSup, float pas, int * erreur);


/**
 * Retourne l'ensemble des points à tracer
 * @param tree L'abre représentant le code postfixé
 * @param borneInf La borne inférieur de l'interval
 * @param pas Indique l'intervalle de calcul des images de la fonction
 * @param erreur Modifie la valeur du int en fonciton de l'erreur
 */
float * creationInterval(Node * tree, int borneInf, float pas, int * erreur, int tailleTableau);

//a jarter ?
void afficheValeurSurIntervalle(float tab [] , int sizeTab);



#endif /* evaluateur_h */

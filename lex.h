#ifndef lex_h
#define lex_h
#include "jeton.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



/**
 * @brief Retourne un entier correspondant à la taille de la chaine de caractère. Ne prends pas en compte '\0'. Passer ab en paramtre retourne 2.
 * @param valeur String a tester
 */
int tailleChaineCharactere(char * valeur);

/**
 * @brief Parcourt la chaine de caractere et affiche son contenu
 * @param string String a afficher
 * @param taillechaine taille de la chaine de string
 */
void afficheString(char * string, int taillechaine);

/**
 * @brief Retourne true si le charactere est un chiffre, un operateur, une variable ou une fonction
 * @param saisieUtilisateur charactere a tester
 */
bool caractereUnique(char saisieUtilisateur);

/**
 * @brief Retourne le type du token associé au charactere c
 * @param c charactere a tester
 */
int typeToken(char c);

/**
 * @brief Retourne la valeur du token de type OPERATOR a partir d'un charactere. Il faut au préalable avoir tester le type du token.
 * @param c charactere a tester
 */
int valeurOperateur(char c);

/**
 * @brief Retourne le premier reel rencontre a partir d'une chaine de caractere globale (nomme saisie) et a partir de l'indice ayant pour valeur curentCursor.
 * @param saisie Chaine de caractere a partir de laquelle on va extraire le reel
 * @param curentCursor Indice a partir duquel on va extraire le reel
 * @param tailleSaisie Taille de la chaine de caractere nomme saisie.
 */
char * extractReelAndMoveCursor(char * saisie, int * curentCursor, int tailleSaisie);


/**
 * @brief Retourne 1 si la chaine de caractere est un reel, 0 sinon.
 * @param reelAtester Chaine de caractere a tester
 * @param tailleReel Taille de la chaine de caractere nome reelAtester
 */
int verificationReel(char * reelAtester, int tailleReel);

/**
 * @brief Retourne la premiere suite de charactere rencontre a partir d'une chaine de caractere globale (nomme saisie) et a partir de l'indice ayant pour valeur curentCursor.
 * @param saisie Chaine de caractere a partir de laquelle on va extraire le reel
 * @param curentCursor Indice a partir duquel on va extraire le reel
 * @param tailleSaisie Taille de la chaine de caractere nomme saisie.
 */
char * extractFctAndMoveCursor(char * saisie, int * curentCursor, int tailleSaisie);

/**
 * @brief Retourne la valeur de l'ENUM associé au nom de la fonction. Il faut au préalable vérifier que le type du token est une fonction
 * @param nomFonction Nom de la fonction a creer
 * @param erreur Entier correspondant au code erreur
 */
int giveValueFonction(char * nomFonction, int * erreur);

/**
 * @brief Cree la liste de token a partir de la chaine de la saisie utilisateur
 * @param saisieUtilisateur Chaine de caractere a transformer en liste de token
 * @param erreurG1 Entier correspondant au code erreur
 */
Token * creationArrayToken(char * saisieUtilisateur, int * erreurG1);




#endif /* lex_h */

/**
 * @file binTree.h
 * @brief Pour la gestion des arbres binaires
 *
 * @author Arthur.M Nicolas.L Guillaume.D Alexandre.T
 * @version 1.0
 * @date novembre 2020
 */
#ifndef binTree_h
#define binTree_h

#include <stdio.h>
#include "jeton.h"


/**
 * @struct Str_Node
 * @brief Structure d'un noeud
 *
 * Un noued est compos� d'une donn�e data
 * ainsi que des pointeurs sur ses fils gauche (left) et droit (right)
 * On peut �galement indiquer si il est vide ou non avec isEmpty
 */
typedef struct Str_Node Node;
struct Str_Node
{
    int isEmpty;
    Token data;
    Node * left;
    Node * right;
};


/**
 * @fn Node * free_binTree(Node *bt)
 * @brief Pour supprimer l'arbre de la m�moire
 *
 * @param bt La racine de l'arbre
 * @return Renvoi 0 si la lib�ration s'est bien faite.
 */
Node * free_binTree(Node *bt);


/**
 * @fn Node * create_Node(Token data)
 * @brief Pour cr�er un noeud sans fils
 *
 * @param data La data � mettre en racine du noeud
 * @return Node pointeur sur le noeud cr��
 */
Node * create_Node(Token data);

/**
 * @fn Node * createNode(Token data, Node *right, Node *left)
 * @brief Pour cr�er un noeud avec deux fils gauche et droit
 *
 * @param data La data � mettre en racine du noeud
 * @param right Pointeur sur le fils droit
 * @param left Pointeur sur le fils gauche
 * @return Pointeur sur le noeud cr��
 */
Node * createNode(Token data, Node *right, Node *left);


/**
 * @fn void afficheNode(Node * self)
 * @brief Pour afficher l'arbre
 *
 * @param self Pointeur sur l'arbre � afficher
 * @retval None
 */
void afficheNode(Node * self);

/**
 * @fn void afficheIntermediaire(Node * self, int var)
 * @brief Pour afficher la racine et les fils gauche et droit d'un noeud
 * La fonction s'occupe de parcourir l'arbre de droite � gauche
 * Elle est appel�e indirectement en utilisant la fonction afficheNode
 *
 * @param self Pointeur sur l'arbre � afficher
 * @param var Une variable pour g�rer le d�calage lors de l'affichage
 * @retval None
 */
void afficheIntermediaire(Node * self, int var);


/**
 * @fn Node * createNodeFromArray(Token self [])
 * @brief Pour cr�er un arbre � partir d'un tableau de extractionArrayToken self Le tableau de Token � trasformer en arbre binaire
 * @retval Le pointeur sur l'arbre cr��
 */
Node * createNodeFromArray(Token self [], int *erreur);

/**
 * @fn void insererToken(Node ** self, Token * tokenInserer)
 * @brief Pour ins�rer un Jeton dans un arbre binaire
 *
 * @param self L'arbre dans lequel inserer le jeton
 * @param tokenInserer Le jeotn � inserer
 * @retval None
 */
void insererToken(Node ** self, Token * tokenInserer);


/**
 * @fn void afficheArrayToken(Token self [])
 * @brief Pour afficher la liste de jetons extraite d'un tableau
 *
 * @param self Le tableau de jetons � afficher
 * @retval None
 */
void afficheArrayToken(Token self []);

/**
 * @fn int getSizeArrayToken(Token self [])
 * @brief Pour connaitre le nombre de jetons dans un tableau de jetons
 *
 * @param self Le tableau de jetons � compter
 * @retval Le nombre de jetons dans le tableau
 */
int getSizeArrayToken(Token self []);
/**
 * @fn Token * extractionArrayToken(Token self [], int debut, int fin)
 * @brief Permet d'extraire un nombre donn� de jetons dans un tableau
 *
 * @param self Le tableau dans lequel extraire les jetons
 * @param debut un entier correspondant � l'indice du premier jeton � extraire
 * @param fin un entier correspondant � l'indice du dernier jeton � extraire
 * @retval Un tableau des jetons extraits
 */
Token * extractionArrayToken(Token self [], int debut, int fin, int *erreur);

/**
 * @fn void suppressionInterieurListeToken(Token self [], int debut, int fin)
 * @brief Pour supprimer un nombre donn� de jetons dans un tableau
 *
 * @param self Le tableau dans lequel supprimer les jetons
 * @param debut un entier correspondant � l'indice du premier jeton � extraire
 * @param fin un entier correspondant � l'indice du dernier jeton � extraire
 * @retval None
 */
void suppressionInterieurListeToken(Token self [], int debut, int fin, int *erreur);


/**
 * @fn int trouverIndiceParentheseCorrespondante(Token self [], int parOuverte)
 * @brief Pour trouver l'indice d'une paranth�se fermante correspondant � la paranth�s ouvrante entr�e en param�tre
 *
 * @param self Le tableau de jetons dans lequel chercher les paranth�ses
 * @param parOuverte L'indice de la paranth�se ouvrante dont on veut chercher la paranth�se fermante correspondante
 * @retval L'indice de la paranth�se fermante dans le tableau ou -1 si celle-ci n'a pas �t� trouv�
 */
int trouverIndiceParentheseCorrespondante(Token self [], int parOuverte);

/**
 * @fn void supprimerValeurExtremite(Token self [])
 * @brief Pour supprimer la premi�re et la derni�re valeurs d'un tableau de jetons
 *
 * @param self Le tableau � emputer
 * @retval None
 */
void supprimerValeurExtremite(Token self []);

/**
 * @fn void supprimerToutesLesParenthesesExtremite(Token self [])
 * @brief Pour supprimer toutes les paranth�ses superflues d'un tableau de jetons
 *
 * @param self Le tableau dans lequel supprimer les paranth�ses superflues
 * @retval None
 */
void supprimerToutesLesParenthesesExtremite(Token self []);

/**
 * @fn int len_bintree(Node *bt)
 * @brief Pour connaitre la taille d'un arbre binaire
 *
 * @param bt L'arbre en question
 * @retval Nombre de noeuds dans l'arbre
 */
int len_bintree(Node *bt);

#endif /* binTree_h */



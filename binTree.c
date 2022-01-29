#include <stdio.h>
#include <stdlib.h>
#include "binTree.h"
#include "jeton.h"
#include "Erreurs.h"


Node * create_Node(Token data)
{
    Node *aNode = malloc(sizeof(Node));

    aNode->isEmpty = 0;
    aNode->data = data;
    aNode->left = NULL;
    aNode->right = NULL;

    return aNode;
}

Node * createNode(Token data, Node * sf, Node * sr) //sf: sonLeft; sr: sonRight
{
    Node * aNode = malloc(sizeof(Node));

    aNode->isEmpty = 0;
    aNode->data = data;
    aNode->left = sf; //pointeur sur le fils gauche
    aNode->right = sr; //pointeur sur le fils droit

    return aNode;
}

void afficheIntermediaire(Node * self, int var)
{
    if(self != NULL)
    {
        var++;
        afficheIntermediaire(self->right, var);
		/*gestion de l'affichage (décalages)*/
        for (int i=0; i<var; i++)
			printf("\t\t");
        afficheJeton(self->data);
		printf("\n\n");
		/************************************/
        afficheIntermediaire(self->left, var);
    }
}

void afficheNode(Node * self)
{
    if(self == NULL)
    {
        printf("Le noeud a afficher est NULL\n");
    }
    afficheIntermediaire(self, -1);
}

void afficheArrayToken(Token self [])
{
    int cpt = 0;
    while(self[cpt].type != FIN)
    {
        afficheJeton(self[cpt]);
		printf("\t"); //gestion de l'affichage (décalages)
        cpt++;
    }
    printf("\n");
}

int getSizeArrayToken(Token self [])
{
    int cpt = 0;
    do
    {
        cpt++;
    }while(self[cpt].type != FIN);
    cpt++; //pour compter le dernier Token Fin
    return(cpt);
}

//prend valeur entre 0 et tailleListeToken - 2, car le dernier token est le token fin, il ne peut pas être prit en compte
// tailleListeToken - 2 car tailleListeToken - 1 correspond a TokenFin
Token * extractionArrayToken(Token self [], int debut, int fin, int *erreur)
{
    Token * retour = calloc(fin - debut + 2, sizeof(Token)); // +2 car une place pour le jeton fin et car on prend le(s) token(s) entre les valeur debut et fin.

    int sizeArray = getSizeArrayToken(self);
    if(debut < 0 || debut > fin || fin >= sizeArray-1) //debut > fin, car debut = fin autorisé pour prendre une valeur | fin >= sizeArray-1 car si = on prends comme deuxième borne le token FIN, et ce n'est pas autorisé
    {
        *erreur = 3;
        //exit(3);
    }
    else
    {
        int cptListePrincipale, cptretour = 0;
        for(cptListePrincipale = debut; cptListePrincipale <= fin; cptListePrincipale++)
        {
            retour[cptretour] = self[cptListePrincipale];
            cptretour++;
        }
        Token tfin;
        tfin.type = FIN;
        retour[cptretour] = tfin;//creationToken("fin", "d");
    }
    return retour;
}

void suppressionInterieurListeToken(Token self [], int debut, int fin, int *erreur)
{
    int sizeArray = getSizeArrayToken(self);
    if(debut < 0 || debut > fin || fin >= sizeArray-1) //debut > fin, car debut = fin autorisé pour prendre une valeur | fin >= sizeArray-1 car si = on prends comme deuxième borne le token FIN, et ce n'est pas autorisé
    {
        *erreur = 3;
    }
    int cptListePrincipale;
    for(cptListePrincipale = debut; cptListePrincipale < sizeArray; cptListePrincipale++)
    {
        if(cptListePrincipale + fin - debut < sizeArray - 1 )
        {
            self[ cptListePrincipale ] = self[ cptListePrincipale + fin - debut + 1 ];
        }
    }
    self[(sizeArray-1)-(fin-debut+1)].type = FIN; //sizeArrat-1 car getSizeArrayToken compte le token FIN; (fin-debut+1) car on retire fin-debut+1 element
}


int trouverIndiceParentheseCorrespondante(Token self [], int indParOuverte)
{
    int sizeArray = getSizeArrayToken(self);
    int cpt, nbParOuverteRencontre = 0;
    for (cpt = indParOuverte + 1; cpt < sizeArray - 1; cpt++)
    {
        if(self[cpt].type == PAR_O)
            nbParOuverteRencontre += 1;
        else if(self[cpt].type == PAR_F)
        {
            if (nbParOuverteRencontre == 0)
                return cpt;
            else
                nbParOuverteRencontre -= 1;
        }
    }
    return -1;
}

void supprimerValeurExtremite(Token self [])
{
    int sizeArray = getSizeArrayToken(self);
    int cpt;
    for(cpt = 0; cpt < sizeArray - 3; cpt ++)
    {
        self[cpt] = self[cpt + 1];
    }
    self[cpt].type = FIN;
}

void supprimerToutesLesParenthesesExtremite(Token self [])
{
    while(trouverIndiceParentheseCorrespondante(self, 0) == getSizeArrayToken(self) - 2) //tant que les extremité du token sont des parenthèses
       // getSize -> n element; self[n-1] dernier; self[n-1]=FIN; --> n-2
	   supprimerValeurExtremite(self);
}

Node * createNodeFromArray(Token self [], int *erreur)
{
    int cpt, nbOperande = 0, nbParentheses = 0;
    Node * aNode = malloc(sizeof(Node));
    aNode->isEmpty = 1;

    *erreur = 0; // 0 quand pas d'erreur

    /*detection des erreurs basiques*/
    for(cpt=0;cpt<getSizeArrayToken(self);cpt++)
    {
        /*pb de parenthèses*/
        if(self[cpt].type == NO_TOKEN)
            *erreur = 1;
        if(self[cpt].type == PAR_O)
            nbParentheses++;
        else if(self[cpt].type == PAR_F)
            nbParentheses--;
        /*deux réels / variables à la suite (sans opérateur entre les deux)*/
        if((self[cpt].type == REEL || self[cpt].type == VARIABLE) && (self[cpt+1].type == REEL || self[cpt+1].type == VARIABLE))
            //catch_Erreur_G2(4, erreur, messageEr); //"Deux réels ou variables se suivent sans opérateur.\n\n Rappel : 3x -> interdit\n 3*x -> autorisé"
            *erreur =4;
        /*si il y a deux opérateurs à la suite*/
        if(self[cpt].type == OPERATEUR && self[cpt+1].type == OPERATEUR)
            *erreur = 6; //"Deux operateurs se suivent.\n\n ex : 3++5\n ou 3+*5"
        if(self[cpt].type == FONCTION && self[cpt+1].type != PAR_O)
            *erreur = 7; //si "cos+2" au lieu de "cos("
    }
    if(nbParentheses != 0)
        *erreur = 5; //"Erreur de parenthèses,\n\n Rappel : 3+x+5 -> interdit\n ((3+x)+5) -> autorisé"

    if(*erreur != 0) //Si une erreur a été détectée
    {
        //  exit(*erreur);
        Token noToken;
        noToken.type = FIN;
        aNode = create_Node(noToken);
        return aNode;
    }

    cpt = 0;
    supprimerToutesLesParenthesesExtremite(self);
    //afficheArrayToken(self);
    if(self[0].type == REEL || self[0].type == VARIABLE ) //pas le droit opérateur, reste implémenter fct
    {
        //printf("creation du noed a partir du token :\n");
        //afficheJeton(self[0]); printf("\n");
        aNode = create_Node(self[0]);
        aNode->isEmpty = 0;
        cpt++;
    }
    else if(self[0].type == OPERATEUR || self[0].type == PAR_F) //cas type erreur & no_token traité par le groupe 1 pendant la création de la liste ?
    {
        *erreur = 2; //"Erreur de construction, trop d'opérande à la suite"
        //exit(2);
        Token noToken;
        noToken.type = FIN;
        aNode = create_Node(noToken);
        return aNode;
    }

    while(self[cpt].type != FIN)
    {
        if(self[cpt].type == PAR_O)
        {
            int parFermeCorrespondant = trouverIndiceParentheseCorrespondante(self, cpt);
            Token * arrayTokenAcreer = extractionArrayToken(self, cpt, parFermeCorrespondant, erreur);
            suppressionInterieurListeToken(self, cpt, parFermeCorrespondant, erreur); //cpt += size(tokerAcrrer) - 1|2

            Node * nouveauNode = createNodeFromArray(arrayTokenAcreer, erreur);
            if(aNode->isEmpty)
            {
                aNode = nouveauNode;
                //afficheArrayToken(self);
            }
            else if(self[cpt].type == FIN)
            {
                aNode->right = nouveauNode;
            }
            else
            {
                //afficheArrayToken(self);
                aNode = createNode(aNode->data, aNode->left, nouveauNode);
            }
        }
        else if(self[cpt].type == FONCTION)
        {
            int parFermeCorrespondant = trouverIndiceParentheseCorrespondante(self, cpt+1);
            Token * arrayTokenAcreer = extractionArrayToken(self, cpt+1, parFermeCorrespondant, erreur);
            Node * nouveauNodeParenthese = createNodeFromArray(arrayTokenAcreer, erreur);
            Node * nouveauNode = createNode(self[cpt], nouveauNodeParenthese, NULL);
            suppressionInterieurListeToken(self, cpt, parFermeCorrespondant, erreur); //cpt += size(tokerAcrrer) - 1|2
            if(aNode->isEmpty)
            {
                aNode = nouveauNode;
                //afficheArrayToken(self);
            }
            else if(self[cpt].type == FIN)
            {
                aNode->right = nouveauNode;
            }
            else
            {
                //afficheArrayToken(self);
                aNode = createNode(aNode->data, aNode->left, nouveauNode);
            }
        }
        else
        {
            if(self[cpt].type == OPERATEUR)
            {
                nbOperande++;
                if(nbOperande > 1)
                {
                    *erreur = 1;

                    Token noToken;
                    noToken.type = FIN;
                    aNode = create_Node(noToken);
                    return aNode;
                    //exit(1);
                }
            }

            insererToken(&aNode, &self[cpt]);
            cpt++;
        }
    }
    return aNode;
}


void insererToken(Node ** self, Token * tokenInserer)
{
    //afficheNode(*self); afficheNode(((*self)->right)); afficheJeton(*tokenInserer);
    if(*self == NULL)
        *self = create_Node(*tokenInserer);
    else
    {
        if((*self)->data.type == OPERATEUR)
        {
            if(tokenInserer->type == OPERATEUR)
            {
                *self = createNode(*tokenInserer, *self, NULL);
            }
            else //si racine est un opérateur et que le token a insérer est un réel / variable
            {
                (*self)->right = create_Node(*tokenInserer);
            }
        }
        else //si type racine de l'arbre est reel / var
        {
            *self = createNode(*tokenInserer, *self, NULL);
        }
    }
}

Node * free_binTree(Node * bt)
{
    if(bt) //vérifie si le noeud est vide
    {
        bt->left = free_binTree(bt->left);
        bt->right = free_binTree(bt->right);
        free(bt);
    }
    return NULL;
}

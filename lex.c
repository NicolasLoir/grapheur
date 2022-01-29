#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"
#include "jeton.h"



int tailleChaineCharactere(char * valeur)
{
    int i;
    i = 0;
    while (valeur[i] != '\0')
        ++i;
    return i;
}

void afficheString(char * string, int taillechaine)
{
    //printf("Taille chaine: %d\n", taillechaine);
    for (int i = 0; i < taillechaine; i++)
    {
        printf("%c \t", string[i]);
    }
    printf("\n");

}

bool caractereUnique(char saisieUtilisateur)
{
    if ((saisieUtilisateur <= '9' && saisieUtilisateur >= '0') || saisieUtilisateur =='x' || saisieUtilisateur == '(' || saisieUtilisateur == ')' || saisieUtilisateur == '+' || saisieUtilisateur == '-' || saisieUtilisateur == '*' || saisieUtilisateur == '/' || saisieUtilisateur == '^')
    {
        return true;
    }
    else
    {
         return false;
    }
}


int typeToken(char c)
{
    int typeToken;

    if (c <= '9' && c >= '0')
        typeToken = REEL;
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        typeToken = OPERATEUR;
    else if (c =='x')
        typeToken = VARIABLE;
    else if (c == '(')
        typeToken = PAR_O;
    else if (c == ')')
        typeToken = PAR_F;
    else
        typeToken = ERREUR;

    return typeToken;
}

int valeurOperateur(char c)
{
    int valeur;
    if (c == '+')
    {
        valeur = ADD;
    }
    else if (c == '-')
    {
        valeur = SUBSTRACT;
    }
    else if (c == '*')
    {
        valeur = MULTIPLY;
    }
    else if (c == '/')
    {
        valeur = DIVIDE;
    }
    else if (c == '^')
    {
        valeur = POW;
    }
    else
    {
        valeur = ERREUR;
    }
    return valeur;
}

//a partir de saisie, a l'indice curentCursor, la fonction extrait une chaine de caractere, tant qu'on est pas a la fin et tant que c'est des chiffre et/ou des points
char * extractReelAndMoveCursor(char * saisie, int * curentCursor, int tailleSaisie) // 1.0.2 -> fonction accepte et retourne la valeur
{
    char * retour = malloc(sizeof(char) * (tailleSaisie - *curentCursor)); //ne peut pas contenir plus de lettres que tailleSaisie - curentCursor
    int cptSaisie = *curentCursor, cptRetour = 0;

    int chiffreOuPoints = (saisie[cptSaisie] >= '0' && saisie[cptSaisie] <= '9') || saisie[cptSaisie] == '.'; //boolen

    while (cptSaisie < tailleSaisie && chiffreOuPoints) {
        retour[cptRetour] = saisie[cptSaisie];
        cptRetour++;
        cptSaisie++;
        chiffreOuPoints = (saisie[cptSaisie] >= '0' && saisie[cptSaisie] <= '9') || saisie[cptSaisie] == '.';
    }
    retour[cptRetour] = '\0';
    *curentCursor = cptSaisie-1;
    return retour;
}

int verificationReel(char * reelAtester, int tailleReel)
{
    int cpt;
    int nbPoints = 0;
    for (cpt = 0; cpt < tailleReel; cpt++)
    {
        if (reelAtester[cpt] == '.')
            nbPoints++;
    }
    int estUnReel = nbPoints <= 1 && reelAtester[tailleReel-1] != '.'; // justification && reelAtester[tailleReel-1] != '.': 1.0 est un rŽel mais pas 1.
    return estUnReel;
}

char * extractFctAndMoveCursor(char * saisie, int * curentCursor, int tailleSaisie)
{
    char * retour = malloc(sizeof(char) * 5); //car la fonction la plus grande est "sqrt" -> 4 char + 1 pour "\0" = 5
    int cptSaisie = *curentCursor, cptRetour = 0;
    int tailleRetour;
    int estUneFonction = (saisie[cptSaisie] >= 'a' && saisie[cptSaisie] <= 'z'); //boolen

    while (cptSaisie < tailleSaisie && estUneFonction)
    {
        retour[cptRetour] = saisie[cptSaisie];
        cptRetour++;
        cptSaisie++;
        estUneFonction = (saisie[cptSaisie] >= 'a' && saisie[cptSaisie] <= 'z');

    }
    retour[cptRetour] = '\0';
    *curentCursor = cptSaisie-1;
    tailleRetour = tailleChaineCharactere(retour);

    return retour;
}

int giveValueFonction(char * nomFonction, int * erreur)
{
    int valueFct = -1; //initialise avec une erreur
    if(strcmp(nomFonction, "sin") == 0)
    {
        valueFct = SIN;
    }
    if ((strcmp(nomFonction, "abs")) == 0)
    {
        valueFct = ABS;
    }
    else if ((strcmp(nomFonction, "cos")) == 0)
    {
        valueFct = COS;
    }
    else if ((strcmp(nomFonction, "tan")) == 0)
    {
        valueFct = TAN;
    }
    else if ((strcmp(nomFonction, "exp")) == 0)
    {
        valueFct = EXP;
    }
    else if ((strcmp(nomFonction, "sqrt")) == 0)
    {
        valueFct = SQRT;
    }
    else if ((strcmp(nomFonction, "log")) == 0)
    {
        valueFct = LOG10;
    }
    else if((strcmp(nomFonction, "ln")) == 0)
    {
        valueFct = LN;
    }
    else if((strcmp(nomFonction, "arccos")) == 0)
    {
        valueFct = ARCCOS;
    }
    else if((strcmp(nomFonction, "arcsin")) == 0)
    {
        valueFct = ARCSIN;
    }
    else if((strcmp(nomFonction, "arctan")) == 0)
    {
        valueFct = ARCTAN;
    }
    else if((strcmp(nomFonction, "sg")) == 0)
    {
        valueFct = SG;
    }
    else if((strcmp(nomFonction, "cosh")) == 0)
    {
        valueFct = COSH;
    }
    else if((strcmp(nomFonction, "sinh")) == 0)
    {
        valueFct = SINH;
    }
    else if((strcmp(nomFonction, "tanh")) == 0)
    {
        valueFct = TANH;
    }
    else
    {
        *erreur=8;
    }
    return valueFct;
}


Token * creationArrayToken(char * saisieUtilisateur, int *erreurG1) //1+2[FIN]
{
    *erreurG1 = 0;
    int taillechaine = tailleChaineCharactere(saisieUtilisateur);
    Token * liste = malloc( sizeof(Token) * (taillechaine + 1)); // +1 car si que des entiers et operateur, il faut une place en plus pour le token fin

    //------ MODELE FONCTION parcoursChaine ------
    Token nouveauToken;
    int nbTokenInserer = 0;
    for (int i = 0; i < taillechaine; i++)
    {
        char charEnCours = saisieUtilisateur[i];
        //printf("%c \t", charEnCours);
        if (caractereUnique(charEnCours) )
        {
            int typeT = typeToken(charEnCours);
            nouveauToken.type = typeT;
            if (typeT == REEL)
            {
                char * valeurReel = extractReelAndMoveCursor(saisieUtilisateur, &i, taillechaine);
                int tailleValeurReel = tailleChaineCharactere(valeurReel);

                if (verificationReel(valeurReel, tailleValeurReel))
                {
                    nouveauToken.value.reel = (float)strtod(valeurReel,NULL);
                }
                else
                {   nouveauToken.type = ERREUR;
                    *erreurG1 = 7;
                    break;
                }

            }
            else if (typeT == OPERATEUR)
               nouveauToken.value.operateur = valeurOperateur(charEnCours);

        }
        else if (saisieUtilisateur[i] >= 'a' && saisieUtilisateur[i] <= 'z')
        {


                    nouveauToken.type = FONCTION;
                    char * nomFonction = extractFctAndMoveCursor(saisieUtilisateur, &i, taillechaine);
                    nouveauToken.value.fonction = giveValueFonction(nomFonction, erreurG1);



         }

        liste[nbTokenInserer] = nouveauToken;
        nbTokenInserer++;
    }
    // --- FIN MODELE FONCTION ---

    //ajout du token de fin
    nouveauToken.type = FIN;
    liste[nbTokenInserer] = nouveauToken;

    return liste;
}





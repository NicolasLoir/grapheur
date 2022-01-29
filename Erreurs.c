
#include <stdio.h>
#include "Erreurs.h"

int digits_only(char s[])
{
    int i=0, err=0;
    while(s[i])
    {
        if (isdigit(s[i]) == 0 && s[i] != '-')
            err++;
        i++;
    }
    if(err) //si la chaine ne comporte pas que des chiffres
        return 1;
    else
        return 0;
}

void catch_Erreur_G3_tailleTableauImage(int type, char *messageEr)
{
    int i = 0;
    switch (type) {
        case 0: ;
            char messTemp0[] = {'R','A','S','\0'};
            for(i=0; messTemp0[i] != '\0'; i++)
                messageEr[i] = messTemp0[i];
            messageEr[i] = '\0';
            break;
        case 1: ;
            char messTemp1[] = "Le pas doit être superieur a 0\n";
            for(i=0; messTemp1[i] != '\0'; i++)
                messageEr[i] = messTemp1[i];
            messageEr[i] = '\0';
            break;
        case 2: ;
            char messTemp2[] = "La borne inferieure doit etre plus petite que la borne superieure\n";
            for(i=0; messTemp2[i] != '\0'; i++)
                messageEr[i] = messTemp2[i];
            messageEr[i] = '\0';
            break;
        case 3: ;
            char messTemp3[] = "Le pas doit etre inferieur a borneSup - borneInf\n";
            for(i=0; messTemp3[i] != '\0'; i++)
                messageEr[i] = messTemp3[i];
            messageEr[i] = '\0';
            break;
        default : ;
            char messErr[] = "Erreur inconnue...\n";
            for(i=0; messErr[i] != '\0'; i++)
                messageEr[i] = messErr[i];
            messageEr[i] = '\0';
            break;
    }
}

void catch_Erreur_G3_treeToFunction(int type, char *messageEr)
{
    int i = 0;
    switch (type) {
        case 0: ;
            char messTemp0[] = {'R','A','S','\0'};
            for(i=0; messTemp0[i] != '\0'; i++)
                messageEr[i] = messTemp0[i];
            messageEr[i] = '\0';
            break;
        case 1: ;
            char messTemp1[] = "Erreur fg et fd vide, ont doit être sur un reel ou une variable: pb de construction";
            for(i=0; messTemp1[i] != '\0'; i++)
                messageEr[i] = messTemp1[i];
            messageEr[i] = '\0';
            break;
        case 2: ;
            char messTemp2[] = "Impossible de diviser par 0";
            for(i=0; messTemp2[i] != '\0'; i++)
                messageEr[i] = messTemp2[i];
            messageEr[i] = '\0';
            break;
        case 3: ;
            char messTemp3[] = "Erreur dans l'enumeration";
            for(i=0; messTemp3[i] != '\0'; i++)
                messageEr[i] = messTemp3[i];
            messageEr[i] = '\0';
            break;
        case 4: ;
            char messTemp4[] = "ln est defini sur ]0;+infini[ uniquement";
            for(i=0; messTemp4[i] != '\0'; i++)
                messageEr[i] = messTemp4[i];
            messageEr[i] = '\0';
            break;
        case 5: ;
            char messTemp5[] = "tan(x) n'est pas defini pour cos(x) = 0";
            for(i=0; messTemp5[i] != '\0'; i++)
                messageEr[i] = messTemp5[i];
            messageEr[i] = '\0';
            break;
        case 6: ;
            char messTemp6[] = "sqrt est defini sur [0;+infini[ sur R";
            for(i=0; messTemp6[i] != '\0'; i++)
                messageEr[i] = messTemp6[i];
            messageEr[i] = '\0';
            break;
        case 7: ;
            char messTemp7[] = "log10 est defini sur ]0;+infini[ uniquement";
            for(i=0; messTemp7[i] != '\0'; i++)
                messageEr[i] = messTemp7[i];
            messageEr[i] = '\0';
            break;
        case 8: ;
            char messTemp8[] = "arccos(x) est defini sur [-1 ; 1] uniquement";
            for(i=0; messTemp8[i] != '\0'; i++)
                messageEr[i] = messTemp8[i];
            messageEr[i] = '\0';
            break;
        case 9: ;
            char messTemp9[] = "arcsin(x) est defini sur [-1 ; 1] uniquement";
            for(i=0; messTemp9[i] != '\0'; i++)
                messageEr[i] = messTemp9[i];
            messageEr[i] = '\0';
            break;
        case 10: ;
            char messTemp10[] = "Erreur dans l'enumeration";
            for(i=0; messTemp10[i] != '\0'; i++)
                messageEr[i] = messTemp10[i];
            messageEr[i] = '\0';
            break;
        case 11: ;
            char messTemp11[] = "Erreur de construction, on doit trouver que des fonction, operateurs & reel";
            for(i=0; messTemp11[i] != '\0'; i++)
                messageEr[i] = messTemp11[i];
            messageEr[i] = '\0';
            break;
        default : ;
            char messErr[] = "Erreur inconnue...\n";
            for(i=0; messErr[i] != '\0'; i++)
                messageEr[i] = messErr[i];
            messageEr[i] = '\0';
            break;
    }
}

void catch_Erreur_G2(int type, char *messageEr)
{
    int i=0;

    switch(type)
    {
        case 0: ;
            char messTemp0[] = {'R','A','S','\0'};
            for(i=0; messTemp0[i] != '\0'; i++)
                messageEr[i] = messTemp0[i];
            messageEr[i] = '\0';
            break;
        case 1: ;
            char messTemp1[] = "L'arbre binaire est vide\n";
            for(i=0; messTemp1[i] != '\0'; i++)
                messageEr[i] = messTemp1[i];
            messageEr[i] = '\0';
            break;
        case 2: ;
            char messTemp2[] = "Erreur de construction, trop d'operande a la suite\n";
            for(i=0; messTemp2[i] != '\0'; i++)
                messageEr[i] = messTemp2[i];
            messageEr[i] = '\0';
            break;
        case 3: ;
            char messTemp3[] = "Erreur(s) sur les bornes de la fonction 'extractionArrayToken' ou 'suppressionInterieurListeToken'\n";
            for(i=0; messTemp3[i] != '\0'; i++)
                messageEr[i] = messTemp3[i];
            messageEr[i] = '\0';
            break;
        case 4: ;
            char messTemp6[] = "Deux reels ou variables se suivent sans operateur.\n\nRappel : 3x -> interdit\n 3*x -> autorise\n";
            for(i=0; messTemp6[i] != '\0'; i++)
                messageEr[i] = messTemp6[i];
            messageEr[i] = '\0';
            break;
        case 5: ;
            char messTemp5[] = "Erreur de parentheses,\n\nRappel : 3+x+5 -> interdit\n\t((3+x)+5) -> autorise\n";
            for(i=0; messTemp5[i] != '\0'; i++)
                messageEr[i] = messTemp5[i];
            messageEr[i] = '\0';
            break;
        case 6: ;
            char messTemp7[] = "Deux operateurs se suivent.\n\n\tex : 3++5, ou encore 3+*5, etc...\n";
            for(i=0; messTemp7[i] != '\0'; i++)
                messageEr[i] = messTemp7[i];
            messageEr[i] = '\0';
            break;
        case 7: ;
            char messTemp8[] = "Une fonction n'est pas suivie d'une paranthese ouvrante";
            for(i=0; messTemp8[i] != '\0'; i++)
                messageEr[i] = messTemp8[i];
            messageEr[i] = '\0';
            break;
        default : ;
            char messErr[] = "Erreur inconnue...\n";
            for(i=0; messErr[i] != '\0'; i++)
                messageEr[i] = messErr[i];
            messageEr[i] = '\0';
            break;
    }
}

void catch_Erreur_G1(int type, char *messageEr)
{
   int i=0;

    switch(type)
    {
        case 0: ;
            char messTemp0[] = {'R','A','S','\0'};
            for(i=0; messTemp0[i] != '\0'; i++)
                messageEr[i] = messTemp0[i];
            messageEr[i] = '\0';
            break;
        case 7: ;
            char messTemp1[] = "Le nombre saisi n'est pas un reel\n";
            for(i=0; messTemp1[i] != '\0'; i++)
                messageEr[i] = messTemp1[i];
            messageEr[i] = '\0';
            break;
        case 8: ;
            char messTemp2[] = "La fonction saisie n'est pas correcte\n";
            for(i=0; messTemp2[i] != '\0'; i++)
                messageEr[i] = messTemp2[i];
            messageEr[i] = '\0';
            break;
        default :
            messageEr = "Erreur inconnue...\n";
            break;
    }
}

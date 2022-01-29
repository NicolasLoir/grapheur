#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "jeton.h"


void afficheJeton(Token self)
{
    switch (self.type)
    {
        case 0:
          printf("%.2f", self.value.reel); //%.2f limite a 2 l'affichage des nombres après la virgule
          break;
        case 1:
            printf("%s", giveTypeOperateur(self.value.operateur));
            break;
        case 2:
            printf("%s", giveTypeFonction(self.value.fonction));
            break;
        case 3:
            printf("ERREUR");
            break;
        case 4:
            printf("(");
            break;
        case 5:
            printf(")");
            break;
        case 6:
            printf("x");
            break;
        case 7:
            printf("FIN");
            break;
        default:
          printf("NO_TOKEN"); //Si erreur de frappe la value affiché sera NO_TOKEN
          break;
    }
    //printf("\n");
}

char * giveTypeToken(type_token self)
{
    char * type[] = {"REEL", "OPERATEUR", "FONCTION", "ERREUR", "PAR_O", "PAR_F", "VARIABLE", "FIN", "NO_TOKEN"};
    return(type[self]);
}

char * giveTypeOperateur(operateur_value self)
{
    char * arrayOperateur[] = {"*", "+", "/", "-", "^"}; //{"MULTIPLY", "ADD", "DIVIDE", "SUBSTRACT"}
    return (arrayOperateur[self]);
}

char * giveTypeFonction(fonction_value self)
{
    char * arrayFct [] = {"COS", "SIN", "TAN", "ARCCOS", "ARCSIN", "ARCTAN", "LN", "EXP", "SG", "SQRT", "ABS", "COSH", "SINH", "TANH", "LOG10"};
    return (arrayFct[self]);
}

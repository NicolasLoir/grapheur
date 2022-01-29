//
//  evaluateur.c
//  arbreV2
//
//  Created by Nicolas on 23/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "evaluateur.h"
#include "Erreurs.h"





float treeToFunction(Node * tree, float x, int * error) 
{
    float image_de_X = 777.77;
    *error = 0; //par defaut
    if (tree->left == NULL && tree->right == NULL) //on est sur un reel ou une variable
    {
        if (tree->data.type == REEL)
        {
            image_de_X = tree->data.value.reel; //A tester
        }
        else if (tree->data.type == VARIABLE)
        {
            image_de_X = x;
        }
        else
        {
           // messageErreurEvaluateur = "Erreur fg et fd vide, ont doit être sur un reel ou une variable: pb de construction";
            *error = 1; //cf fct catch_Erreur_G3 dans Erreurs.c
        }
    }
    else if (tree->data.type == OPERATEUR)
    {
        switch (tree->data.value.operateur) { //FG OPERATEUR FD
            case DIVIDE:
                if (treeToFunction(tree->right, x, error) == 0)
                {
                    //*messageErreurEvaluateur = "Impossible de diviser par 0";
                    *error = 2;
                }
                else
                {
                    image_de_X = treeToFunction(tree->left, x, error) / treeToFunction(tree->right, x, error);
                }
                break;
            case ADD:
                image_de_X = treeToFunction(tree->left, x, error) + treeToFunction(tree->right, x, error);
                break;
            case SUBSTRACT:
                image_de_X = treeToFunction(tree->left, x, error) - treeToFunction(tree->right, x, error);
                break;
            case MULTIPLY:
                image_de_X = treeToFunction(tree->left, x, error) * treeToFunction(tree->right, x, error);
                break;
            case POW://POW OU PUIS
                image_de_X = pow(treeToFunction(tree->left, x, error), treeToFunction(tree->right, x, error));
                break;
            default:
                //messageErreurEvaluateur = "Erreur dans l'énumération";
                *error =  3;
                break;
        }
    }
    else if (tree->data.type == FONCTION)
    {
        switch (tree->data.value.fonction) {
            case LN:
                if (treeToFunction(tree->left, x, error) <= 0)
                {
                    //messageErreurEvaluateur = "ln est défini sur ]0;+infini[ uniquement";
                    *error =  4;
                }
                else
                {
                    image_de_X = logf(treeToFunction(tree->left, x, error)); //ce qui est à dans les parenthèses de LN soit positif. Idem LOG2, LOG10
                }
                break;
            case COS:
                image_de_X = cosf(treeToFunction(tree->left, x, error));
                break;
            case SIN:
                image_de_X = sinf(treeToFunction(tree->left, x, error));
                break;
            case TAN:
                if (cosf(treeToFunction(tree->left, x, error)) == 0)
                {
                    //messageErreurEvaluateur = "tan(x) n'est pas défini pour cos(x) = 0";
                    *error =  5;
                }
                else
                {
                    image_de_X = tanf(treeToFunction(tree->left, x, error)); //tan : interdit pour multiple impaire de PI/2 (2k+1) * (PI/2)
                }
                break;
            case EXP:
                image_de_X = expf(treeToFunction(tree->left, x, error));
                break;
            case SQRT:
                if (treeToFunction(tree->left, x, error) < 0)
                {
                    //messageErreurEvaluateur = "sqrt est défini sur [0;+infini[ sur R";
                    *error =  6;
                }
                else
                {
                    image_de_X = sqrtf(treeToFunction(tree->left, x, error));//tree->left doit être positif
                }
                break;
            case ABS:
                image_de_X = fabsf(treeToFunction(tree->left, x, error));
                break;
            case LOG10:
                if (treeToFunction(tree->left, x, error) <= 0)
                    {
                        
                        //messageErreurEvaluateur = "log10 est défini sur ]0;+infini[ uniquement";
                        *error =  7;
                    }
                else
                    {
                        image_de_X = log10f(treeToFunction(tree->left, x, error));//tree->left doit être positif
                    }
                break;
            case ARCCOS:
                if (treeToFunction(tree->left, x, error) < -1 && treeToFunction(tree->left, x, error) > 1)
                {
                    //messageErreurEvaluateur = "arccos(x) est défini sur [-1 ; 1] uniquement";
                    *error =  8;
                }
                else
                {
                    image_de_X = acosf(treeToFunction(tree->left, x, error)); // [-1 ; 1]
                }
                break;
            case ARCSIN:
                if ((treeToFunction(tree->left, x, error) < -1) && (treeToFunction(tree->left, x, error) > 1))
                {
                    //messageErreurEvaluateur = "arcsin(x) est défini sur [-1 ; 1] uniquement";
                    *error = 9;
                }
                else
                {
                    image_de_X = asinf(treeToFunction(tree->left, x, error));// [-1 ; 1]
                }
                break;
            case ARCTAN:
                image_de_X = atanf(treeToFunction(tree->left, x, error));
                break;
            case COSH:
                image_de_X = coshf(treeToFunction(tree->left, x, error));
                break;
            case SINH:
                image_de_X = sinhf(treeToFunction(tree->left, x, error));
                break;
            case TANH:
                image_de_X = tanhf(treeToFunction(tree->left, x, error));
                break;
            default:
                //messageErreurEvaluateur = "Erreur dans l'énumération";
                *error = 10;
                break;
        }
    }
    else
    {
        //messageErreurEvaluateur = "Erreur de construction, on doit trouver que des fonction, opérateurs & reel\n";
        *error = 11;
    }
    return image_de_X;
}

int tailleTableauImage(int borneInf, int borneSup, float pas, int * erreur)
{
    int tailleTab = 0;
    *erreur = 0;
    if (pas <= 0)
        *erreur = 1;
    else if (borneSup < borneInf)
        *erreur = 2;
    else if (pas > borneSup - borneInf)
        *erreur = 3;
    else
        tailleTab = ceil((borneSup - borneInf) / pas) + 1;//ceil = arrondi valeur au dessus ; +1 pour rajouter borneSup dans le tableau
    return tailleTab;
}


float * creationInterval(Node * tree, int borneInf, float pas, int * erreur, int tailleTableau)
{
    *erreur = 0;
    int i = 0;
    float antX = 0, imX = 0;
    float * retour = malloc(sizeof(float) * tailleTableau);
    for (i = 0; i < tailleTableau; i++)
    {
        antX = borneInf + (i * pas);
        imX = treeToFunction(tree, antX, erreur);
        if (*erreur != 0)
        {
            char messageEr [100];
            catch_Erreur_G3_treeToFunction(*erreur, messageEr);// modifie messageEr
            printf("Erreur : %i-> %s\n", *erreur, messageEr);// affiche erreur
            break;  
        }
        else
        {
            retour[i] = imX;
        }
    }
    return retour;
}
//A jarter ?
void afficheValeurSurIntervalle(float tab [] , int sizeTab)
{
    int i = 0;
    for (i = 0; i < sizeTab; i++)
        printf("%f\t", tab[i]);
        
    printf("\n");
}


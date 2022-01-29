#include <stdio.h>

#include "jeton.h"
#include "binTree.h"
#include "evaluateur.h"
#include "lex.h"
#include "Erreurs.h"


#define SIZE_BUFFER 1000

/**
  *@fn int main(int argc, const char * argv[])
  *@brief Entrée du programme
  *
  *@return 0 -> Arrêt normal du programme
  */

int main(int argc, const char * argv[]) {
    //typeToken REEL, OPERATEUR, FONCTION, ERREUR, PAR_O, PAR_F, VARIABLE, FIN, NO_TOKEN
    //valeurReel: double
    //valeurOperateur MULTIPLY, ADD, DIVIDE, SUBSTRACT
    //valeurFonction COS, SIN, TAN, ARCCOS, ARCSIN, ARCTAN, LN, EXP, SG, SQRT, ABS, COSH, SINH, TANH, LOG2, LOG10


    //------------------------------------------------ DEF VAR MAIN--------------------------------------
    int erreurG1 = 0, erreurG2 = 0, erreurG3 = 0;
    char messageEr[100];
    //"log(cos(3+(ln(10+x)*5))/sin(x*x))"
    char chaine[SIZE_BUFFER] = "log(cos(3+(ln(10+x)*5))/sin(x*x))";


    //------------------------------------------------ PARTIE 1 -------------------------------------------

    Token * liste_token = creationArrayToken(chaine, &erreurG1);
    while (erreurG1 != 0)
    {
        catch_Erreur_G1(erreurG1, messageEr); // modifie messageEr
        printf("Erreur : %i-> %s\n", erreurG1, messageEr);// affiche erreur

        printf("Entrez une nouvelle expression: ");
        scanf("%s", chaine);

        printf("Nouvelle valeur: %s\n\n", chaine);

        liste_token = creationArrayToken(chaine,&erreurG1);
    }
    afficheArrayToken(liste_token);


    //------------------------------------------------ PARTIE 2 -------------------------------------------

    Node * arbre_token = createNodeFromArray(liste_token, &erreurG2);
    while (erreurG2 != 0)
    {
        catch_Erreur_G2(erreurG2, messageEr); // modifie messageEr
        printf("Erreur : %i-> %s\n", erreurG2, messageEr);// affiche erreur

        printf("Entrez une nouvelle expression: ");
        scanf("%s", chaine);

        printf("Nouvelle valeur: %s\n\n", chaine);

        liste_token = creationArrayToken(chaine, &erreurG1);
        arbre_token = createNodeFromArray(liste_token, &erreurG2);
    }
    afficheNode(arbre_token);


    //------------------------------------------------ PARTIE 3 -------------------------------------------

    // -- Test treeToFunction --
    float val_X = 1;
    float f_X = treeToFunction(arbre_token, val_X, &erreurG3);
    while (erreurG3 != 0) {
        catch_Erreur_G3_treeToFunction(erreurG3, messageEr);// modifie messageEr
        printf("Erreur : %i-> %s\n", erreurG3, messageEr);// affiche erreur

        /*permet de vérifier que la saisie utilisateur est bien composé de chiffre(s)*/
        do
        {
            printf("Entrez une nouvelle valeur: ");
            scanf("%s", chaine);
        }while(digits_only(chaine));
        /*fin*/
        val_X = (float)strtod(chaine,NULL); //convert char * in float
        f_X = treeToFunction(arbre_token, val_X, &erreurG3);
    }

    // -- Test tailleTableauImage -- //
    int borneInf = -1, borneSup = 2;
    float pas = 4;
    int tailleTableau = tailleTableauImage(borneInf, borneSup, pas, &erreurG3);
    float * tab = NULL;
    int erreurCreationInterval = 0;
    do{ //pour passer au moins une fois dans toutes ces fonctions
        if (erreurCreationInterval)
        {
            printf("\nATTENTION : Erreur dans lors de la construction des images de la fonction. Verifier domaine de def et division par 0 !!!\n");
            erreurG3 = 3;
        }
        else
        {
            catch_Erreur_G3_tailleTableauImage(erreurG3, messageEr);// modifie messageEr
            printf("Erreur : %i-> %s\n", erreurG3, messageEr);// affiche erreur
        }

        switch(erreurG3)
        {
            case 1:
                /*permet de vérifier que la saisie utilisateur est bien composé de chiffre(s)*/
                do
				{
				    printf("Entrez une nouvelle valeur pour le pas: ");
					scanf("%s", chaine);
				}while(digits_only(chaine));
				/*fin*/
                pas = (float)strtod(chaine,NULL); //convert char * in float
                break;
            case 2:
                do
				{
				    printf("Entrez une nouvelle valeur pour borneInf: ");
					scanf("%s", chaine);
				}while(digits_only(chaine));
                borneInf = (int)strtod(chaine,NULL);
                do
				{
				    printf("Entrez une nouvelle valeur pour borneSup: ");
					scanf("%s", chaine);
				}while(digits_only(chaine));
                borneSup = (int)strtod(chaine,NULL);
                break;
            case 3:
                do
				{
				    printf("Entrez une nouvelle valeur pour le pas: ");
					scanf("%s", chaine);
				}while(digits_only(chaine));
                pas = (float)strtod(chaine,NULL); //convert char * in float
                do
				{
				    printf("Entrez une nouvelle valeur pour borneInf: ");
					scanf("%s", chaine);
				}while(digits_only(chaine));
                borneInf = (int)strtod(chaine,NULL);
                do
				{
				    printf("Entrez une nouvelle valeur pour borneSup: ");
					scanf("%s", chaine);
				}while(digits_only(chaine));
                borneSup = (int)strtod(chaine,NULL);
                break;
        }
        tailleTableau = tailleTableauImage(borneInf, borneSup, pas, &erreurG3);

        if (erreurG3 == 0)
        {
            printf("pas= %f, borneInf=%d, borneSup=%d, tailleTableau=%d\n",pas, borneInf, borneSup, tailleTableau);

            // -- Test tailleTableauImage --
            tab = creationInterval(arbre_token, borneInf, pas, &erreurG3, tailleTableau);
            if (erreurG3 != 0)
                erreurCreationInterval = 1;
            else
                afficheValeurSurIntervalle(tab, tailleTableau);
        }
    } while(erreurG3 != 0);


    //--------------------------------------------- LIBERER MEMOIRE ---------------------------------------

    free(liste_token);
    free_binTree(arbre_token);


    return 0;
}

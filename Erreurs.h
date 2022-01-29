#ifndef erreurs_h
#define erreurs_h

int digits_only(char s[]);

void catch_Erreur_G1(int type, char *messageEr);

void catch_Erreur_G2(int type, char *messageEr);

//Modifie la valeur de messageEr en fonction du type d'erreur
void catch_Erreur_G3_treeToFunction(int type, char *messageEr);

void catch_Erreur_G3_tailleTableauImage(int type, char *messageEr);

#endif // erreurs_h

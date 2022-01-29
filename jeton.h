/**
 * @file jeton.h
 * @brief Pour la gestion des jetons
 * Implémentation des types de jetons et des fonctions pour les manipuler
 *
 * @author Arthur.M Nicolas.L Guillaume.D Alexandre.T
 * @version 1.0
 * @date novembre 2020
 */
#ifndef jeton_h
#define jeton_h


/**
 * @enum Enum_Operateur_Value
 * @brief Definition des valeurs d'opérateurs possibles
 */
enum Enum_Operateur_Value
{
    MULTIPLY,
    ADD,
    DIVIDE,
    SUBSTRACT,
    POW
};
typedef enum Enum_Operateur_Value operateur_value;

/**
 *@enum Enum_Fonction_value
 *@brief Definition des valeurs de fonctions possibles
 */
enum Enum_Fonction_value
{
    COS, SIN, TAN,
    ARCCOS, ARCSIN, ARCTAN,
    LN,
    EXP,
    SG,
    SQRT,
    ABS,
    COSH, SINH, TANH,
    LOG10
};
typedef enum Enum_Fonction_value fonction_value;

/**
 *@union Union_value_token
 *@brief Definition des valeurs de tokens possibles
 */
union Union_value_token{
    float reel;
    operateur_value operateur;
    fonction_value fonction;
};
typedef union Union_value_token value_token;

/**
 *@enum Enum_Type_Token
 *@brief Defintion des types de jetons possibnles
 */
enum Enum_Type_Token
{
    REEL,
    OPERATEUR,
    FONCTION,
    ERREUR,
    PAR_O, PAR_F,
    VARIABLE,
    FIN,
    NO_TOKEN
};
typedef enum Enum_Type_Token type_token;

/**
 *@struct Str_Token
 *@brief Creation de la structure Token
 */
typedef struct Str_Token Token;
struct Str_Token{
    type_token type;
    value_token value;
};


/**
 * @brief Affiche le type et la valeur du Token passé en paramètre. Utilie les fonctions giveTypeToken, giveTypeOperateur et giveTypeFonction
 * @param self Le token observé
 */
void afficheJeton(Token self);

/**
 * @brief Retourne un mot correspondant au type de token observé
 * @param self Le type de token observé
 */
char * giveTypeToken(type_token self);

/**
 * @brief Retourne un mot correspondant au type d'operateur observé
 * @param self Le type d'opérateur observé
 */
char * giveTypeOperateur(operateur_value self);

/**
 * @brief Retourne un mot correspondant au type de fonction observé
 * @param self Le type de fonction observé
 */
char * giveTypeFonction(fonction_value self);


#endif /* jeton.h */

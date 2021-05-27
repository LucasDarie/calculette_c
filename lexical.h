#include<stdio.h>
typedef enum CodToken codeToken;
enum CodToken{
	AFFECT,
	PRINT,
	PTVIRG,
	PLUS,
	MOINS,
	PARGAUCHE,
	PARDROITE,
 	ID,
	NB,
	FIN,
	ERREURLEX
};

struct t_Token{
	codeToken code;
	char* lexem;
};
typedef struct t_Token Token;
Token nextToken(FILE *source);
/*precondition : le fichier source est supposé ouvert*/
/*retourne le code du prochain token à partir de la position courante dansle fichier, FIN si 
on arrive en fin de fichier, ERREURLEX s’il n’y a pasde token;*/
/*après l’appel, la position courante dans le fichier correspond au premiercaractère suivant le lexème associé au token reconnu*/
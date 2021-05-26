#include<stdio.h>
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
	ERREURLEX; 
}
typedef enum CodToken codeToken;

struct t_Token{
	codeToken code;
	int attribut;
};
typedef struct t_Token Token;
Token nextToken(FILE *source);
/*precondition : le fichier source est supposé ouvert*/
/*retourne le code du prochain token à partir de la position courante dansle fichier, FIN si 
on arrive en fin de fichier, ERREURLEX s’il n’y a pasde token;*/
/*après l’appel, la position courante dans le fichier correspond au premiercaractère suivant le lexème associé au token reconnu*/
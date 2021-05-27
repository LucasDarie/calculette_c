#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "lexical.h"

Token nextToken(FILE *source) {
	int etat = 0;
	Token leToken;
	char c = getc(source);
	char tampon_id[40];
	int indice_tampon_id = 0;
	int fini = (c == EOF);

	while (!fini) {
		switch (etat) {
		case 0:
			while ((c != EOF) && (isspace(c)))
				c = getc(source);
			if (c == EOF) {
				leToken.code = FIN;
				leToken.lexeme = NULL;
				return leToken;
			}
			switch (c) {
			case '(':
				leToken.code = PARGAUCHE;
				leToken.lexeme = (char *)malloc(2);
				strcpy(leToken.lexeme, "(");
				fini = 1;
				break;
			case ')':
				leToken.code = PARDROITE;
				leToken.lexeme = (char *)malloc(2);
				strcpy(leToken.lexeme, ")");
				fini = 1;
				break;
			case ':':
				etat = 3;
				c = getc(source);
				break;
			case '+':
				leToken.code = PLUS;
				leToken.lexeme = (char *)malloc(2);
				strcpy(leToken.lexeme, "+");
				fini = 1;
				break;
			case '-':
				leToken.code = MOINS;
				leToken.lexeme = (char *)malloc(2);
				strcpy(leToken.lexeme, "-");
				fini = 1;
				break;
			case ';':
				leToken.code = PTVIRG;
				leToken.lexeme = (char *)malloc(2);
				strcpy(leToken.lexeme, ";");
				fini = 1;
				break;

			default:
				if ((c > '0') && (c <= '9')) {
					etat = 2;
					tampon_id[indice_tampon_id] = c;
					indice_tampon_id++;
					c = getc(source);
				}
				else if (isalpha(c))
				{
					etat = 1;
					tampon_id[indice_tampon_id] = c;
					indice_tampon_id++;
					c = getc(source);
				}
				else
				{ /* un caractère interdit sur l'entrée */
					leToken.code = ERREURLEX;
					leToken.lexeme = NULL;
					fini = 1;
				}
			}
			break;

		case 1: /* cas d'un identificateur*/
			if (isalpha(c) || isdigit(c))
			{
				tampon_id[indice_tampon_id] = c;
				indice_tampon_id++;
				c = getc(source);
			}
			else
			{ /* on a trouve un identificateur ou un print*/
				tampon_id[indice_tampon_id] = '\0';
				if (indice_tampon_id == 5 && strcmp("print", tampon_id) == 0){
					leToken.code = PRINT;
					leToken.lexeme = (char *)malloc(6);
					strcpy(leToken.lexeme, "print");
				}
				else{
					leToken.code = ID;
					leToken.lexeme = (char *)malloc(indice_tampon_id + 1);
					strcpy(leToken.lexeme, tampon_id);
				}
				fini = 1;
				ungetc(c, source);
			}
			break;

		case 2: /* cas d'un nombre */
			if (isdigit(c)) {
				tampon_id[indice_tampon_id] = c;
				indice_tampon_id++;
				c = getc(source);
			}
			else{
				leToken.code = NB;
				tampon_id[indice_tampon_id] = '\0';
				leToken.lexeme = (char *)malloc(indice_tampon_id + 1);
				strcpy(leToken.lexeme, tampon_id);
				ungetc(c, source);
				fini = 1;
			}
			break;

		case 3: /* cas du :=*/
			if (c == '='){
				leToken.code = AFFECT;
				leToken.lexeme = (char *)malloc(3);
				strcpy(leToken.lexeme, ":=");
				fini = 1;
			}
			else{
				leToken.code = ERREURLEX;
				leToken.lexeme = NULL;
				fini = 1;
			}
			break;
		default:;
		}
	}
	return leToken;
}
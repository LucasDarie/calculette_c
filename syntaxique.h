#include "lexical.h"

#include <stdio.h>
#include <stdlib.h>

FILE * source;
Token tokenCourant;
int prog(void);
/*
 - source initialisé au fichier à analyser
 - tokenCourant initialisé au premier token du fichier
 post : analyse le fichier source; si OK retourne EXIT_SUCCESS,
        sinon retourne EXIT_FAILURE
*/
#include "lexical.c"

#include <stdio.h>
#include <stdlib.h>

FILE * source;
Token tokenCourant;
int prog(void);
/*
 - source initialis√© au fichier √† analyser
 - tokenCourant initialis√© au premier token du fichier
 post : analyse le fichier source; si OK retourne EXIT_SUCCESS,
        sinon retourne EXIT_FAILURE
*/
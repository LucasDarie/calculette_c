#include "syntaxique.h"

static void inst(void);
static void suiteInst(void);
static void expr(void);
static void atome(void);
static void resteExpr(void);

void displayCode(codeToken code){
    switch (code)
    {
    case AFFECT :
        printf("AFFECT\n");
        break;
	case PRINT :
	    printf("PRINT\n");
        break;
	case PTVIRG :
	    printf("PTVIRG\n");
        break;
	case PLUS :
	    printf("PLUS\n");
        break;
	case MOINS :
	    printf("MOINS\n");
        break;
	case PARGAUCHE :
	    printf("PARGAUCHE\n");
        break;
	case PARDROITE :
	    printf("PARDROITE\n");
        break;
 	case ID :
 	    printf("ID\n");
         break;
	case NB :
	    printf("NB\n");
        break;
	case FIN :
	    printf("FIN\n");
        break;
	case ERREURLEX :
	    printf("ERREURLEX\n");
        break;
    default:
        printf("default\n");
        break;
    }
}

static void erreur(codeToken code){
    printf("erreur sur : ");
    displayCode(code);
    /*switch (code){
    case :
        break;
    
    default:
        break;
    }
    affiche un message precisant l'erreur
    */
}

static void Accepter(codeToken code){
    if(tokenCourant.code == code){
        printf("accepté : ");
        displayCode(tokenCourant.code);
        tokenCourant = nextToken(source);
        printf("newCode =");
        displayCode(tokenCourant.code);
    }
    else{
        erreur(code);
    }
}

int prog(void){
    displayCode(tokenCourant.code);
    inst();
    suiteInst();
    if(tokenCourant.code == FIN) return EXIT_SUCCESS;
    else return EXIT_FAILURE;
}

void inst(){
    switch(tokenCourant.code){
        case ID :
            Accepter(ID);
            Accepter(AFFECT);
            expr();
            Accepter(PTVIRG);
            break;
        case PRINT :
            Accepter(PRINT);
            expr();
            Accepter(PTVIRG);
            break;
        default:
            erreur(tokenCourant.code);
    }
}

static void suiteInst(){
    if(tokenCourant.code == ID || tokenCourant.code == PRINT){
        inst();
        suiteInst();
    }
}

static void expr(void){
    atome();
    resteExpr();
}

static void atome(void){
    switch(tokenCourant.code){
        case ID :
            Accepter(ID);
            break;
        case NB :
            Accepter(NB);
            break;
        case PARGAUCHE :
            Accepter(PARGAUCHE);
            expr();
            Accepter(PARDROITE);
            break;
        default:
            erreur(tokenCourant.code);
    }
}

static void resteExpr(){
    switch(tokenCourant.code){
        case PLUS :
            Accepter(PLUS);
            atome();
            resteExpr();
            break;
        case MOINS :
            Accepter(MOINS);
            atome();
            resteExpr();
            break;
        default:
            return;
    }
}
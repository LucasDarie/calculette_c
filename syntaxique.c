#include "syntaxique.h"

static void inst(void);
static void suiteInst(void);
static void expr(void);
static void atome(void);
static void resteExpr(void);

static void erreur(codeToken code){
    printf("erreur sur : %d", code);
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
    if(tokenCourant.code == code)
        tokenCourant = nextToken(source);
    else{
        erreur(code);
    }
}

int prog(void){
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
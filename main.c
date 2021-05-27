#include "syntaxique.c"

int main(int argc, char const *argv[]){
    if (argc < 2){
        printf("Synthax : ./%s <file>\n", argv[0]);
    }
    source = fopen("./calcul.txt", "r");
    tokenCourant = nextToken(source);
    int exit_status = prog();
    if(exit_status == EXIT_FAILURE){
        printf("C'EST NON !\n");
    }
    else{
        printf("YOUPI LA CULCULETTE\n");
    }
    fclose(source);
    return 0;
}

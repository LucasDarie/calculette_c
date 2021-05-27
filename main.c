#include "syntaxique.c"

int main(int argc, char const *argv[]){
    if (argc < 2){
        printf("Synthax : ./%s <file>", argv[0]);
    }
    source = fopen("./calcul.txt", "r");
    prog();
    return 0;
}

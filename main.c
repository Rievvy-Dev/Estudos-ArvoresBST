//Este arquivo é apenas para a inicialização do programa
//Deverá conter apenas um menu simples para testes das funções implementadas no arquivo bst.c

#include "bst.h"
#include "bst.c"
#include <stdio.h>

int main (int argc, char *argv[]) {
    Tree new, aux;
    new = NULL;
    aux = NULL;
    int option, value;
    
    while (option != 99) {
        scanf("%d", &option);
        switch (option) {
            case 1:
                scanf("%d", &value);
                new = insertNode(new, value);
                break;
            case 2:
                preOrder(new);
                printf("\n");
                break;
            case 3:
                inOrder(new);
                printf("\n");
                break;
            case 4:
                posOrder(new);
                printf("\n");
                break;
            case 5:
                descending(new);
                printf("\n");
                break;
            case 6:
                printf("Search a node: ");
                scanf("%d", &value);
                aux = searchNode(new, value);
                printf("%d\n", aux->value);
                break;
            case 7:
                printf("The highest value is: %d\n", highestValue(new));
                break;
            case 8:
                scanf("%d", &value);
                new = deleteNode(new, value);
                break;
            case 99:
                exit(0);
        }
    }
    
    return 0;
}

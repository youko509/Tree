#include "bt.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    Tree * tree =createTree(createTree(createTree(NULL,createTree(newTree(5),newTree(23),3),13),NULL,41),createTree(newTree(7),createTree(newTree(19),NULL,11),2),37);
    int choix;
    
    printf("Choissisez une fonction pour effectuer sur l'arbre binaire\n");
    printf("1  - Determiner la racine de l'arbre\n");
    printf("2  - Determiner la hauteur de l'arbre\n");
    printf("3  - Determiner la taille de l'arbre\n");
    printf("4  - Determiner la liste des feuilles de l'arbre\n");
    printf("5  - Inserer un noeud dans l'arbre\n");
    printf("6  - Determiner la liste des feuilles interne de l'arbre\n");
    printf("7  - De supprimer un noeud de l'arbre\n");
    printf("8  - D'afficher l'arbre en ordre infixe\n");
    printf("9  - D'afficher l'arbre en ordre prefixe\n");
    printf("10 - D'afficher l'arbre en ordre postfixe\n");
    scanf("%d",&choix);

    switch(choix){

        case 1:
            printf("La racine de l'arbre est : \n");
            findRoot(tree);
            break;
        case 2:
            printf("La hauteur de l'arbre est : %d\n",findHeight(tree));
            break;
        case 3:
            printf("La taille de l'arbre est : %d\n",findsize(tree));
            break;
        case 4:
            printf("la liste des feuilles est \n");
            listleafs(tree);
            break;
        case 5:
            insertOnLeafs(tree);
            break;
        case 6:
            listNodes(tree);
            break;
        case 7:
            cleanNode(tree);
            displayPrefixe(tree);
            break;
        case 8:
            displayInfixe(tree);
            break;
        case 9:
            displayPrefixe(tree);
            break;
        default:
            displayPostfixe(tree);
            break;
    }
   
    return 0;
}
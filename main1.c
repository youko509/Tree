#include "bt.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    // Tree T[10] ={{23,-1,-1},{2,4,5},{3,3,0},{5,-1,-1},{7,-1,-1},{11,9,-1},{13,-1,2},{37,8,1},{41,6,-1},{19,-1,-1}};
    // findRoot(T);
    Tree * tree =createTree(createTree(createTree(NULL,createTree(newTree(5),newTree(23),3),13),NULL,41),createTree(newTree(7),createTree(newTree(19),NULL,11),2),37);
    
    displayInfixe(tree);
    
    clean(tree);
    
    return 0;
}
#ifndef FONCTION
#define FONCTION
#include <stdbool.h>
typedef struct Tree
{
    int value;
    struct Tree * left;
    struct Tree * right;
    struct Tree * parent;
}Tree; 

Tree *newTree(int x);
void clean(Tree *t);
void cleanNode(Tree *t);
Tree *createTree(Tree *left, Tree *right, int node);
void displayPostfixe(Tree * t);
void displayPrefixe(Tree * t);
void listleafs(Tree *tr);
Tree *insertOnLeafs(Tree *t);
Tree *listNodes(Tree *t);
void findRoot(Tree *t);
int findsize(Tree *t);
void displayInfixe(Tree * t);
int findHeight(Tree *t);
#endif 
#ifndef FONCTION
#define FONCTION

typedef struct Tree
{
    int value;
    struct Tree * left;
    struct Tree * right;
    struct Tree * parent;
}Tree; 
Tree *newTree(int x);
void clean(Tree *t);
Tree *createTree(Tree *left, Tree *right, int node);
void displayPostfixe(Tree * t);
void displayPrefixe(Tree * t);
void listleafs(Tree *tr);
Tree *insertOnLeafs(Tree *t, int v1, int v2);
Tree *listNodes(Tree *t);
void findRoot(Tree *t);
int findsize(Tree *t);
#endif 
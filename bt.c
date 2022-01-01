#include "bt.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Tree *newTree(int x){
    Tree *tr = malloc(sizeof(*tr));

    if(tr == NULL){
        printf("Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
    tr->value=x;
    tr->left=NULL;
    tr->right=NULL;
    tr->parent=NULL;

    return tr;
}
void clean(Tree *t){
    if (t==NULL)
        return;
    clean(t->left);
    clean(t->right);
    free(t);    
}
Tree *createTree(Tree *left, Tree *right, int node){

    Tree *t =newTree(node);
    t->left=left;
    t->right=right;
    if(left!=NULL)
        left->parent=t;
    if(right !=NULL)
        right->parent=t;
    return t;       
}
void displayPrefixe(Tree * t){
    if(t==NULL)
        return;

     
    if(t->parent !=NULL){
        printf("(%d) -> (%d)\n",t->parent->value,t->value);
    }else{
        printf("(%d)\n", t->value);
    }

    if(t->left !=NULL)
        displayPrefixe(t->left);  
    if(t->right !=NULL)
        displayPrefixe(t->right);      
}
void displayPostfixe(Tree * t){
    if(t==NULL)
        return;

        
    if(t->parent !=NULL){
        printf("(%d) -> (%d)\n",t->parent->value,t->value);
    }else{
        printf("(%d)\n", t->value);
    }

    if(t->right !=NULL)
        displayPrefixe(t->right); 

    if(t->left !=NULL)
        displayPrefixe(t->left);  
         
}
void listleafs(Tree *t){
    if(t == NULL)
        return;
    if(t->left !=NULL){ 
        listleafs(t->left);    
    }
    if(t->right !=NULL){
        listleafs(t->right);    
    }
     if(t->right ==NULL & t->left == NULL  ){
            printf("(%d) -> (%d)\n",t->parent->value,t->value);
     }
}

Tree *insertOnLeafs(Tree *t,int v1,int v2){
    if(t == NULL)
        return 0;
    if(t->left !=NULL){ 
        listleafs(t->left);    
    }
    if(t->right !=NULL){
        listleafs(t->right);    
    }
    if(t->right ==NULL & t->left == NULL  ){
       createTree(newTree(v1),newTree(v2),t->value);     
    }else{
        printf("it's not a leafs");
    }
    return t;
}

Tree *findleafs(Tree *t){
    if(t == NULL)
        return 0;
    if(t->left !=NULL){ 
        listleafs(t->left);    
    }
    if(t->right !=NULL){
        listleafs(t->right);    
    }
     if(t->right ==NULL & t->left == NULL  ){
            printf("(%d) -> (%d)\n",t->parent->value,t->value);
    }
    return t;
    
}

Tree *listNodes(Tree *t){
    
    if(t == NULL)
        return 0;
    if(t->left !=NULL){ 
        listNodes(t->left);    
    }
    if(t->right !=NULL){
        listNodes(t->right);    
    }
    
    if(t->right !=NULL || t->left != NULL  ){
        printf("(%d) -> (%d)\n",t->parent->value,t->value);
    }
    return t;
}

void findRoot(Tree *t){
    if(t->parent ==NULL){
        printf("(%d)\n", t->value);
    }
}
int findsize(Tree *t){
    if(t == NULL)
        return 0;
    return (findsize(t->left)+findsize(t->right)+1);    
}

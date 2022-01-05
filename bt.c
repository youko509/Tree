#include "bt.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#include <stdbool.h>
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
    
    if(t == NULL){
       
        return ;
    }
    clean(t->left);
    clean(t->right);
    free(t);    
}
void cleanNode(Tree *t){
    int choice;
    if(t == NULL){
       
        return ;
    }
     if(t->parent !=NULL  ){
        
        if(t == NULL){
                printf("bad\n");
                
            return ;
            }
        printf("voulez-vous supprimer ce noeud %d ?\n tapez 1 pour confirmer\n",t->value);
        scanf("%d",&choice);

        if(choice==1){
            t->parent =NULL; 
            if(t->left !=NULL){
                 
                clean(t->left);
            }
            if(t->right !=NULL){
                
                clean(t->right);
            }
            free(t);
            return ;
        }
           
    } 
    
    if(t->left !=NULL){ 
        cleanNode(t->left);
    }
    if(t->right !=NULL){
        cleanNode(t->right);    
    }
        
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

    if(t == NULL){
        
        return ;
    }

    if(t->parent !=NULL){
        printf(" (%d) ->(%d)\n",t->parent->value,t->value);
    }else{
        printf("(%d)\n", t->value);
    }

    if(t->left !=NULL && t->left->value>0)
        displayPrefixe(t->left);  
    if(t->right !=NULL && t->right->value>0)
        displayPrefixe(t->right);      
}
void displayPostfixe(Tree * t){

    if(t == NULL){
        
        return ;
    }

    if(t->parent !=NULL){
        printf("(%d) -> (%d)\n",t->parent->value,t->value);
    }else{
        printf("(%d)\n", t->value);
    }

    if(t->right !=NULL)
        displayPostfixe(t->right); 

    if(t->left !=NULL)
        displayPostfixe(t->left);  
         
}
void listleafs(Tree *t){

   if(t == NULL){
        printf("L'arbre est vide");
        return ;
    }

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

Tree *insertOnLeafs(Tree *t){
    int choice;
    
    if(t == NULL){
        printf("L'arbre est vide");
        return 0;
    }

    if(t->right ==NULL && t->left == NULL  ){
        int v1,v2;
        printf("voulez-vous inserer un noeud a la feuille %d ?\n tapez 1 pour confirmer",t->value);
        scanf("%d",&choice);

        if(choice==1){
            printf("enter la valeur 1\n");
            scanf("%d",&v1);

            printf("enter la valeur 2\n");
            scanf("%d",&v2);
            
            Tree *tr1=newTree(v1);
            Tree *tr2=newTree(v2);
            t->left=tr1;
            t->right=tr2;

            if(tr1!=NULL)
                tr1->parent=t;
            if(tr2 !=NULL)
                tr2->parent=t;

            printf("value : %d\n",t->right->value);
            printf("parent : %d\n",t->parent->value);

        }
           
    } 
    
    if(t->left !=NULL){ 
        insertOnLeafs(t->left);
    }
    if(t->right !=NULL){
        insertOnLeafs(t->right);    
    }
    return t;
}


Tree *listNodes(Tree *t){
    
    if(t == NULL){
        printf("L'arbre est vide");
        return 0;
    }
    if(t->left != NULL){ 
        listNodes(t->left);    
    }
    if(t->right != NULL){
        listNodes(t->right);    
    }
    if(t->right != NULL || t->left != NULL  ){
        printf("(%d)",t->value);
    }
    printf("\n");
    return t;
}

void findRoot(Tree *t){
    if(t == NULL){
        printf("L'arbre est vide");
        return ;
    }
    if(t->parent == NULL){
        printf("(%d)\n", t->value);
    }

}
int findsize(Tree *t){
    if(t == NULL){
        printf("L'arbre est vide");
        return 0;
    }
    return (findsize(t->left)+findsize(t->right)+1);

}

void displayInfixe(Tree * t){

    if(t == NULL){
        
        return ;
    }
    
    if(t->left !=NULL)
        displayInfixe(t->left);
    printf("(%d)\n", t->value);      
    if(t->right !=NULL)
        displayInfixe(t->right); 

   
    
}
int findHeight(Tree *t){

    int leftHeight, rightHeight;
    if(t == NULL){
        return 0;
    }else{
        leftHeight= findHeight(t->left);
        rightHeight = findHeight(t->right);
        if(leftHeight>rightHeight){
            return (leftHeight+1);
        }else{
            return (rightHeight+1);
        }
    }

}

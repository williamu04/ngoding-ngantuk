#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *kiri;
    struct node *kanan;
};

void fungsiX(struct node *root){
    if (root == NULL) return;
    fungsiX(root->kiri);
    printf("%d ->", root->item);
    fungsiX(root->kanan);
}

struct node* buatNode(value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->kiri = NULL;
    newNode->kanan = NULL;

    return newNode;
}

struct node *insertKiri(struct node *root, int value) {
    root->kiri = buatNode(value);
    return root->kiri;
}

struct node *insertKanan(struct node *root, int value) {
    root->kanan = buatNode(value);
    return root->kanan;
}


int main(){
    struct node *root = buatNode(1);
    insertKiri(root, 2);
    insertKanan(root, 3);
    insertKiri(root->kiri, 4);
    insertKiri(root->kanan, 5);

    printf("Tree : \n");
    fungsiX(root);
}

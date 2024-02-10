#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void fungsi1(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void fungsi2 (struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
    return; 
}

void printList(struct Node *node){
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }   
}

int main(){
    struct Node *head = NULL;
    fungsi2(&head, 1);
    fungsi1(&head, 2);
    fungsi1(&head, 3);
    fungsi2(&head, 4);
    printf("Linked list: ");
    printList(head);
}
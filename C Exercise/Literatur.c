#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void printPostorder(struct node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

void printInorder(struct node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);  
    printInorder(node->right);
}

void printPreorder(struct node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);  
    printPreorder(node->left);  
    printPreorder(node->right);
}    

int main() {
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 

    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);

    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);  

    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);

    getchar();
    return 0;
}




// #include <stdio.h>
// #define SIZE 100

// void enqueue(int);
// void dequeue();
// void display();

// int queue[SIZE];
// int rear = - 1;
// int front = - 1;

// int main() {
//     enqueue(1);
//     enqueue(2);
//     enqueue(3);
//     display();
//     dequeue();
//     display();
//     return 0;
// }

// void enqueue(int item) {
//     if (rear == SIZE - 1)
//         printf("Queue Overflow \n");
//     else {
//         if (front == - 1)
//             front = 0;
//         rear = rear + 1;
//         queue[rear] = item;
//     }
// }

// void dequeue() {
//     if (front == - 1 || front > rear) {
//         printf("Queue Underflow \n");
//         return ;
//     } else {
//         printf("Element deleted from queue is : %d\n", queue[front]);
//         front = front + 1;
//     }
// }

// void display() {
//     if (front == - 1)
//         printf("Queue is empty \n");
//     else {
//         printf("Queue is : \n");
//         for (int i = front; i <= rear; i++)
//             printf("%d ", queue[i]);
//         printf("\n");
//     }
// }






// #include <stdio.h>
// #define SIZE 4

// int stack[SIZE];
// int top = -1;

// void push(int item) {
//     if(top == SIZE - 1) {
//         printf("Stack Overflow \n");
//     } else {
//         top = top + 1;
//         stack[top] = item;
//     }
// }

// void pop() {
//     if(top == -1) {
//         printf("Stack Underflow \n");
//     } else {
//         printf("Popped element: %d\n", stack[top]);
//         top = top - 1;
//     }
// }

// void display() {
//     if(top == -1) {
//         printf("Stack is empty \n");
//     } else {
//         printf("Stack is : \n");
//         for(int i = top; i >= 0; i--) {
//             printf("%d ", stack[i]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     push(1);
//     push(2);
//     push(3);
//     display();
//     pop();
//     display();
//     return 0;
// }




// #include <stdlib.h>
// #include <stdio.h>

// struct node {
//     int data;
//     struct node *next;
// };

// int main() {
//     struct node *head;
//     struct node *one = NULL;
//     struct node *two = NULL;
//     struct node *three = NULL;

//     one = malloc(sizeof(struct node));
//     two = malloc(sizeof(struct node));
//     three = malloc(sizeof(struct node));

//     one->data = 1;
//     two->data = 2;
//     three->data = 3;

//     one->next = two;
//     two->next = three;
//     three->next = NULL;

//     head = one;

//     while(head != NULL) {
//         printf("%d ", head->data);
//         head = head->next;
//     }

//     return 0;
// }

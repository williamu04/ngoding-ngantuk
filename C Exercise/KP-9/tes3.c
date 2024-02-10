#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int print(){
    return intArray[front];
}

bool isEmpty(){
    return itemCount == 0;
}

bool isFull(){
    return itemCount == MAX;
}

void fungsi1(int data) {
    if(!isFull()) {
        if(rear == MAX-1) {
            rear = -1;            
        }       

        intArray[++rear] = data;
        itemCount++;
    }
}

int fungsi2(){
    int data = intArray[front++];
    if (front == MAX)
    {
        front = 0;
    }
    itemCount--;
    return data;
}

int main(){
    for (int x = 1; x <= 10; x++)
    {
        fungsi1(x);
        if (x%2 == 0)
        {
            fungsi2(x);
        }
    }
    printf("Elemen terdepan: %d\n", print());
    printf("-------------------\n");
    printf("Queue: ");

    while (!isEmpty())
    {
        int n = fungsi2();
        printf("%d ", n);
    }
}
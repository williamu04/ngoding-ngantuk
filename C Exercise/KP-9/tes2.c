#include <stdio.h>
int MAXSIZE = 4;
int stack[5];
int top = -1;

int isEmpty(){
    if (top == -1)
    {
        return 1;
        /* code */
    } else {
        return 0;
    }
}

int isFull(){
    if (top == MAXSIZE)
    {
        return 1;
    } else {
        return 0;
    }
}

int fungsi1(int data){
    if(!isFull()){
        top+=1;
        stack[top] = data;
    } else{
        return 0;
    }
}

int fungsi2(){
    int data;
    if(!isEmpty()){
        data = stack[top];
        top-=1;
        return data;
    } else {
        return 0;
    }
}

int main(){
    fungsi1(1);
    fungsi1(2);
    fungsi1(3);
    fungsi2(4);
    fungsi1(5);
    fungsi2(6);
    fungsi1(7);
    fungsi1(8);
    fungsi1(9);
    fungsi2(10);
    printf("Elemen tertinggi: %d\n", stack[top]);
    printf("Elemen: \n");
    while (!isEmpty())
    {
        int data = fungsi2();
        printf("%d\n", data);
    }
    printf("Stack full: %s\n", isFull()?"true":"false");
    printf("Stack empty: %s\n", isEmpty()?"true":"false");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void EnQueue(int data);
void DeQueue();
void QueueFront();
void QueueRear();
void display();

int main() {
    int choice;
    while (1) {
        printf("MENU\n");
        printf("1.EnQueue\n");
        printf("2.DeQueue\n");
        printf("3.QueueFront\n");
        printf("4.QueueRear\n");
        printf("5.Display\n");
        printf("6.Exit\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the number you want to EnQueue:\n");
            int data;
            scanf("%d", &data);
            EnQueue(data);
            display();
            break;
        case 2:
            DeQueue();
            display();
            break;
        case 3:
            QueueFront();
            break;
        case 4:
            QueueRear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

void EnQueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("EnQueued %d successfully\n", data);
    }
}

void DeQueue() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        int val = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("DeQueued element is %d\n", val);
    }
}

void QueueFront() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("The value at front of queue is %d\n", queue[front]);
    }
}

void QueueRear() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("The value at rear of the queue is %d\n", queue[rear]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Elements in the queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

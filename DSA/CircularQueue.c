#include <stdio.h>
#define MAX 4


int front = -1, rear = -1;
int queue[MAX];

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insert(int num) {
    if (isFull()) {
        printf("Overflow\n");
        return isFull();
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = num;
}

int delete_element() {
    int val;
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        printf("The deleted element is %d",val);
        front++;
    }
    
    return val;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    }
    printf("Peeked element: %d\n", queue[front]);
    return queue[front];
}


void display() {
    int i;
    printf("\n");
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice = 1;
    while (choice) {
        printf("\nEnter operation - \n1.Insert \n2.Delete \n3.Peek \n4.Display \n0.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                int data;
                scanf("%d", &data);
                insert(data);
                display();
                break;
            case 2:
                delete_element();
                display();
                break;
            case 3:
                peek();
                display();
                break;
            case 4:
                display();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}

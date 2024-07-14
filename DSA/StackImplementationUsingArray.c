// #include<stdio.h>
// #include<conio.h>
// #define MAX 10
// int st[MAX], top=-1;
// void push(int x);
// void pop();
// int peak();
// void display();
// void main()
// {
//     int ch,x;
    
//     do{
//         printf("1. Push \n 2. Pop \n 3.Peak \n 4. Display \n 5. Exit \n");
//         scanf("%d",&ch);
        
//         switch (ch)
//         {
//         case 1:
//             printf("Enter a number to Push into Stack:\n");
//             scanf("%d",&x);
//             push(x);
//             display();
//             break;

//         case 2:
//             pop();
//             display();
//             break;

//         case 3 :
//             x=peak();
//             if(x == -1)
//             {
//                 printf("Stack is Empty");
//             }
//             else{
//                 printf("Peaked Element is %d",x);
//             }
//             break;

//         case 4:
//             display();
//             break;
//         }


//     } while(ch != 5);
//        getch();  
//     }
    
//     void push(int x)
//     {
//         if (top == MAX-1)
//         printf("Stack Overflow\n");
//         else{
//             st[++top]=x;
//         }
//     }

//     void pop()
//     {
//         if (top == -1)
//         printf("Stack Underflow\n");
//         else{
//             printf("Popped-Element is %d\n", st[top--]);
//         }
//     }

//     int peak()
//     {
//         if( top == -1){
//             return -1;
//         }
//         else{
//             return st[top];
//         }
//     }

//     void display() {
//         int i;
//         if(top == -1){
//             printf("Stack is Empty\n");
//         }
//         else{
//             for(i=top; i>=0; i--)
//             {
//                 printf("Elements in the stack are %d\n",st[i]);
//             }
//         }
//     }


        
#include<stdio.h>
// #include<conio.h>
#define MAX 10
int st[MAX], top=-1;
void push(int x);
void pop();
int peak();
void display();
void main()
{
    int choice,x;
    
    do{
        printf("\n1. Push \n 2. Pop \n 3.Peak \n 4. Display \n 5. Exit \n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter a number to Push into Stack:\n");
            scanf("%d",&x);
            push(x);
            display();
            break;

        case 2:
            pop();
            display();
            break;

        case 3 :
            x=peak();
            if(x == -1)
            {
                printf("Stack is Empty");
            }
            else{
                printf("Peaked Element is %d",x);
            }
            break;

        case 4:
            display();
            break;
        }


    } while(choice != 5);
    //   getch();  
    return;
    }
    
    void push(int x)
    {
        if (top == MAX-1)
        printf("Stack Overflow\n");
        else{
            st[++top]=x;
        }
    }

    void pop()
    {
        if (top == -1)
        printf("Stack Underflow\n");
        else{
            printf("Popped-Element is %d\n", st[top--]);
        }
    }

    int peak()
    {
        if( top == -1){
            return -1;
        }
        else{
            return st[top];
        }
    }

    void display() {
        int i;
        if(top == -1){
            printf("Stack is Empty\n");
        }
        else{
        //     for(i=top; i>=0; i--)
        //     {
        //         printf("Elements in the stack are %d->",st[i]);
        //     }
        // }
        printf("Elements in the stack are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d->", st[i]);
    }
}
}
        

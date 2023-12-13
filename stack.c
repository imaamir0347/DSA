#include <stdio.h>
#include <stdlib.h>
#define max 10
int stack[max];
int top=-1;
void push();
void pop();
void display();
void peek();


void main()
{
    int choice;
    do
    {
        printf("\n*****MENUU*****\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK VALUE\n5.EXIT");
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            PEEK();
            break;
        case 5:
            exit(0);
        default:
            printf("Input Valid Choice!");
        }
    }
    while(choice!=0);
}

void push()
{
    int item;
    printf("Enter the element to be pushed.");
    scanf("%d",&item);
    if(top==max-1)
        printf("Sack is Overflow.");
    else
    {
        top++;
        stack[top]=item;
    }

}
void pop()
{
    int item;
    if(top==-1)
    {

        printf("Underflow.");

    }
    else
    {
        item=stack[top];
        top--;
        printf("\n%d is successfully Deleted.",item);
    }


}
void DISPLAY()
{
    if(top==-1)
    {


        printf("Stack Empty!");
    }
    else
    {
        printf("Stack:-");
        for(int i=top; i>=0; i--)
        {
            printf("%d ",stack[i]);
        }
    }

}
void PEEK()
{
    if(top==-1)
    {

        printf("Stack Empty!");
    }
    else
    {
       printf("Peek Value:-");
        printf("%d ",stack[top]);
    }
}






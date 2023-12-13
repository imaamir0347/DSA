#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
int length=1;
void createlist()
{
    int size;
    struct node *newnode,*temp;
    head=malloc(sizeof(struct node));
    printf("Enter the size of the List:");
    scanf("%d",&size);
    printf("Enter Data:");
    scanf("%d",&head->value);
    tail=temp=head;
    head->prev=NULL;
    head->next=NULL;
    for(int i=2; i<=size; i++)
    {
        newnode=malloc(sizeof(struct node));
        printf("Enter Data:");
        scanf("%d",&newnode->value);
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;
        newnode->next=head;
        length++;
    }
    tail=newnode;
    head->prev=tail;
}
void display(struct node *ptr)
{
    if(head==NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        printf("List:-");
        while(ptr->next!=head)
        {
            printf("%d-->",ptr->value);
            ptr=ptr->next;

        }
        printf("%d-->",ptr->value);
    }
}
void traverse(struct node *ptr)
{
    if(head==NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        printf("List:-");
        while(ptr->prev!=tail)
        {
            printf("%d-->",ptr->value);
            ptr=ptr->prev;

        }
        printf("%d-->",ptr->value);
    }
}
void insertnode()
{
    int choice;
    printf("Menu For Insertion\n1.Insert at First\n2.Insert at Last\n3.Insert after a specific node\n4.Insert before a specific node");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        insertatbegin();
        break;
    case 2:
        insertatend(head);
        break;
    case 3:
        insertafter(head);
        break;
    case 4:
        insertbefore(head);
        break;
    default:
        printf("Invalid Choice!");
    }

}
void insertatbegin()
{
    struct  node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d",&newnode->value);
    if(head==NULL)
    {
        head=tail=newnode;
        head->next=NULL;
        head->prev=NULL;
        length++;
        printf("Inserted Successfully.");
    }
    else
    {
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        length++;
        printf("Inserted Successfully.");
    }
}
void insertatend(struct node *ptr)
{
    if(head==NULL)
    {
        printf("List is Empty!");
        return;
    }
    struct  node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("\nEnter Data:");
    scanf("%d",&newnode->value);
    newnode->next=head;
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
    length++;
    printf("Inserted Successfully.");
}
void insertafter(struct node *ptr)
{
    if(head==NULL)
    {
        printf("List is Empty!");
        return;
    }
    struct  node *newnode;
    int i=1,pos;
    newnode=malloc(sizeof(struct node));
    printf("Enter the position after which you want to insert:");
    scanf("%d",&pos);
    if(pos==length)
    {
        insertatend(head);
    }
    else
    {
        while(i<pos)
        {
            ptr=ptr->next;
            i++;
        }
        printf("\nEnter Data:");
        scanf("%d",&newnode->value);
        newnode->next=ptr->next;
        newnode->prev=ptr;
        ptr->next->prev=newnode;
        ptr->next=newnode;
        length++;
        printf("Inserted Successfully.");
    }
}
void insertbefore(struct node *ptr)
{
    if(head==NULL)
    {
        printf("List is Empty!");
        return;
    }
    struct  node *newnode;
    int i=1,pos;
    newnode=malloc(sizeof(struct node));
    printf("Enter the position before which you want to insert:");
    scanf("%d",&pos);
    if(pos==1)
    {
        insertatbegin();
    }
    else
    {
        while(i<pos-1)
        {
            ptr=ptr->next;
            i++;
        }
        printf("\nEnter Data:");
        scanf("%d",&newnode->value);
        newnode->next=ptr->next;
        newnode->prev=ptr;
        ptr->next->prev=newnode;
        ptr->next=newnode;
        length++;
        printf("Inserted Successfully.");
    }
}
void deletenode()
{

    int choice;
    if(head==NULL)
    {
        printf("List is Empty!");
        return;
    }
    printf("Menu For Deletion\n1.Delete First Node\n2.Delete Last Node \n3.Delete a specific Node");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        deletefront();
        break;
    case 2:
        deletelast();
        break;
    case 3:
        deletepos(head);
        break;
    default:
        printf("Invalid Choice");
    }

}


void deletefront()
{
    struct node *temp;
    temp=head;
    head=head->next;
    head->prev=tail;
    free(temp);
    printf("Deleted successfully.");
}
void deletelast()
{
    struct node *temp;
    temp=tail;
    tail=tail->prev;
    tail->next=head;
    free(temp);
    printf("Deleted successfully.");
}
void deletepos(struct node *ptr)
{
    struct node *temp;
    int i=1,pos;
    printf("Enter the position of node you want to delete:");
    scanf("%d",&pos);
    while(i<pos)
    {
        temp=ptr;
        ptr=ptr->next;
        i++;
    }
    temp->next=ptr->next;
    ptr->next->prev=temp;
    free(ptr);
    printf("Deleted successfully.");
}
void searching(struct node *ptr)
{
    int item,flag=0;
    printf("Enter Data You Want to Search:");
    scanf("%d",&item);
    while(ptr!=NULL)
    {
        if(ptr->value==item)
        {
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1)
    {
        printf("%d is present in the list.",item);

    }
    else
    {
        printf("%d is not present in the list.",item);
    }
}
void main()
{
    int choice;
    do
    {
        printf("\n*****Menu*****\n1.Create Linked list\n2.Insertion\n3.Deletion\n4.Display\n5.Searching\n6.Traverse from Back\n7.Exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            createlist();
            break;
        case 2:
            insertnode();
            break;

        case 3:
            deletenode();
            break;
        case 4:
            display(head);
            break;
        case 5:
            searching(head);
            break;
        case 6:
            traverse(tail);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid Choice!");
        }
    }
    while(choice!=0);
}








/*
This code is used to create a SINGLY LINKED LIST. The main terms that are used in the code are explaind below:

*IMPORTANT BUILT_IN FUNCTIONS & COMMANDS*

malloc: This is a built-in command and helps you to allocate memory. It has 'void' return type. 
NULL  : When a pointer is defined it has a garbage value. Just to make sure that is no garbage value, we assign NULL to the 
        pointer.
free  : This command is used to free the space of the deleted node from the memory. If we are using a very long list, them this 
        command must be used in order to stay away from the trouble of memory shortage.

If you have any suggestion amd correction, then you are most welcomed. Your contriution will help lot of other people.
If you fouond this code helpful, please leave your valuable comment.

Thank You !
*/





#include<stdlib.h>
#include<stdio.h>

struct node{                                    // Defining the NODE
    int data;                                   
    struct node* next;
};

struct node* START = NULL;

int main()
{
    int number, choice, pos;
    do{                                         // ENTER the number from 1 to 9
    printf("\n1. Create List");                  
    printf("\n2. Display List");                    
    printf("\n3. Insert at START");                
    printf("\n4. Insert at Position");
    printf("\n5. Delete from END");
    printf("\n6. Delete from START");
    printf("\n7. Delete from Position");
    printf("\n8. Reverse the List");
    printf("\n9. EXIT");
    printf("\nEnter Your Choice  : "); 
    scanf("%d", &choice);                       // Used to take the USERS's choice as an input
switch(choice){                                 // Switch statement used to match the ENTERED value
case 1:
    printf("Enter the number :  ");
    scanf("%d", &number);
    createList(number);                      
    break;
case 2:
    display();                               
    break;
case 3:
    printf("Enter the number :  ");
    scanf("%d", &number);
    insertAtBeginning(number);                 
    break;
case 4:
    printf("Enter the Position :  ");
    scanf("%d", &pos);
    printf("Enter the Number :  ");
    scanf("%d", &number);
    insertAtPosition(pos, number);
    break;
case 5:
    deleteFromLast();
    break;
case 6:
    deleteFromStart();
    break;
case 7:
    printf("Enter the Position :  ");
    scanf("%d", &pos);
    deletefromPosition(pos);
    break;
case 8:
    reverseList();
    break;
case 9:
    exit(0);
    break;
default:                                        // If the user enters value, apart from '1' to '9'
    printf("Enter valid choice");
}
}while(1);
}
void createList(int value)                      // Function to create the list
{
    struct node *temp, *q;
if (START == NULL)                              // If the code is running First time
{
    START = (struct node*)malloc(sizeof(struct node));
    START->data = value;
    START->next = NULL;
}
else
{
    temp = (struct node*)malloc(sizeof(struct node));
    temp=START;
while(temp->next!=NULL)                         // Find the LAST node of the LIST
{
    temp = temp->next;
}
q = (struct node*)malloc(sizeof(struct node));
q->data=value;
q->next=NULL;
temp->next=q;
}
}

void display()                                  // Function which is used to display the LIST
{
    struct node* q;
    if (START == NULL)                          // Check weather the LIST is empty or NOT 
{
    printf("\nList is Empty\n");
}
else{
    for(q=START; q!=NULL;q=q->next)             // Traverse through the whole LIST
    {
        printf("%d\t", q->data);
    }
    printf("\n");
}
}


void insertAtBeginning(val)                     // This function helps to INSERT the node at START
{
   struct node *p;
   p= (struct node*)malloc(sizeof(struct node)); // Create a NEW node
   p->data=val;
   p->next=START;
   START=p;
}

void insertAtPosition(int val, int value)        // This function helps to insertg a node at a specific position
{
    struct node *p, *traverse;
    traverse = START;
    for(int i=1;i<val-1;i++)                     // This loop helps to find the index of the node where we want to add the node
    {
        traverse=traverse->next;                 // Traversing through the list
    }
    p= (struct node*)malloc(sizeof(struct node));
    p->data=value;
    p->next=traverse->next;
    traverse->next=p;
}

void deleteFromLast()                           // This function, when called, deletes the LAST node of the LIST. 
{
    struct node *temp;
    temp=START;
    while(temp->next->next!=NULL)               // This loop executes untill the LAST node is not found. The LAST node is the node
    {                                           // which has NULL in its next part.
        temp=temp->next;    
    }

    free(temp->next);
    temp->next=NULL;
}

void deleteFromStart()                          // This fuction deletes a node from the START
{
    struct node *temp;
    temp = START->next;                         // To delete a node from STRAT, we simply replace the address of 1st node with 
    free(START);                                // the second node in the HEAD.
    START=temp;                                 
}

void deletefromPosition(int val)                // Function to delete the node from a specific position
{
    struct node *temp, *q;
    temp = START;
    for(int i=1;i<val-1;i++)                    // This loop helps to find the index of the node that we want to delete
    {
        temp = temp->next;
    }
    q=temp->next->next;
    free(temp->next);
    temp->next=q;

}

void reverseList()                              // Function to Reverse the List
{
    struct node *prev, *current, *nextt;        // intializing the node pointers 
    prev = NULL;
    current = START;
    while(current!=NULL)                       // This loop swaps the two nodes when executed 1 time. This loop executes as same number
    {                                          // of times as the length of the LIST
        nextt = current->next;                 
        current->next=prev;
        prev = current;
        current = nextt;
    }
    START= prev;

}

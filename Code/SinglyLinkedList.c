#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *First = NULL , *Last = NULL , *Curr = NULL , *tmp = NULL ;

bool isempty();
void insertFirst();
void insertLast();
void insertAfter();
void traverse();
void deleteFirst();
void deleteLast();
void deletePerticuler();

int main() {
    int ch = -1;
    while(ch != 0) {
        printf("\n\n+-------------------------+");
        printf("\n|        Choices          |");
        printf("\n+-------------------------+");
        printf("\n| 1).Insert First         |");
        printf("\n| 2).Insert Last          |");
        printf("\n| 3).Insert after         |");
        printf("\n| 4).Delete First         |");
        printf("\n| 5).Delete Last          |");
        printf("\n| 6).Delete perticular    |");
        printf("\n| 7).Traverse             |");
        printf("\n| 0).Exit                 |");
        printf("\n+-------------------------+");
        printf("\n\nEnter your choice = ");
        scanf("%d",&ch);

        switch (ch) {
        case 1 :
            insertFirst() ;
            break ;
        
        case 2 :
            insertLast();
            break ;

        case 3 :
            insertAfter();
            break ;

        case 4 :
            deleteFirst();
            break;

        case 5 :
            deleteLast();
            break ;

        case 6 :
            deletePerticuler();
            break ;

        case 7 :
            traverse();
            break ;

        case 0 :
            printf("\nExiting........\n");
            break ;

        default :
            printf("\nEnter valid choice ! ");
            break ;
        }
    }
    return 0 ;
}

bool isempty() {
    return First == NULL;
}

void insertFirst() {
    tmp = (struct Node*) malloc( sizeof(struct Node) );     
    printf("Enter element You want to insert first = ");
    scanf("%d" , &tmp->data );
    printf("\nElement %d inserted successfully at First Pos. " , tmp->data);
    printf("\n===============================================");
    tmp->next = First ;

    if(isempty()) {                                 //Checks if Link List is empty? 
        First = Last = tmp ;                        //if yes then First and Last will points tmp 
    } else {
        First = tmp ;                               //else only First will point tmp
    }
}

void insertLast() {
    tmp = (struct Node*) malloc( sizeof(struct Node) );
    printf("Enter element You want to insert Last = ");
    scanf("%d" , &tmp->data);
    printf("\nElement %d inserted successfully at Last Pos. " , tmp->data);
    printf("\n===============================================");
    tmp->next = NULL ;

    if(isempty()) {                                 //Checks if Link List is empty? 
        First = Last = tmp ;                        //if yes then First and Last will points tmp
    } else {
        Last->next = tmp ;                          //else tmp will be Linked with old Last Node and now LAst will point tmp 
        Last = tmp ;
    }
}

void insertAfter() {            
    if(isempty()) {                                 //Checks if Link List is empty? 
        printf("\n+----------------------------------------+");
        printf("\n| Linked List is empty                   |");
        printf("\n| Insert After Operation can't be done . |");
        printf("\n+----------------------------------------+");
        return ;
    }
    int index , cnt = 1 ;
    Curr = First ;
    printf("\nAfter which index you want to insert data = ");
    scanf("%d" , &index);
    while(Curr->next != NULL && cnt < index) {      //Loop will break at Last Node or at cnt == index
        Curr = Curr->next ;
        cnt ++ ;
    }
    if(cnt == index) {                              //Checks if index entered by user is available in Linked List or not?
        tmp = (struct Node*)malloc(sizeof(struct Node)) ;
        printf("Enter element you want to insert = ") ;
        scanf("%d" , &tmp->data) ;                  //if Yes then assign data to the tmp
        printf("\nElement %d inserted successfully at %d Pos. " , tmp->data , index+1);
        printf("\n===============================================");
        tmp->next = Curr->next ;                    //and Links Curr's Next Node with tmp and Link tmp with Curr
        Curr->next = tmp ;
        if(Curr == Last) {                          //Checks If entered index no. is the last Node of Linked List 
            Last = tmp ;                            //if yes then Last will point to tmp
        }
    } else {                                        //index is not available in Linked List
        printf("\n%d index is not found in Linked List . " , index);
        printf("\n=======================================");
    }
}

void traverse() {
    if(isempty()) {                                 //Checks if Link List is empty? 
        printf("\n+------------------------+");
        printf("\n| Linked List is empty . |");
        printf("\n+------------------------+");
        return ;
    }
    Curr = First ;
    printf("\nLinked List : ");
    while(Curr != NULL) {
        printf("| %d |-->" , Curr->data);
        Curr = Curr->next ;
    }
    printf(" /\n");
}

void deleteFirst() {
    if(isempty()) {                                 //Checks if Link List is empty? 
        printf("\n+----------------------------------------+");
        printf("\n| Linked List is empty                   |");
        printf("\n| Delete First Operation can't be done . |");
        printf("\n+----------------------------------------+");
        return ;
    }
    tmp = First ;
    printf("\nData %d deleted from linked list " , tmp->data);
    printf("\n=================================");
    if(First == Last) {                             //Checks if Linked List Having only one Node or not?
        First = Last = NULL ;                       //If yes then Linked List will be empty
    } else {
        First = First->next ;                       //Else First will point Old First pointer's next Node
    }
    free(tmp) ;
}

void deleteLast() {
    if(isempty()) {                                 //Checks if Link List is empty? 
        printf("\n+----------------------------------------+");
        printf("\n| Linked List is empty                   |");
        printf("\n| Delete Last Operation can't be done .  |");
        printf("\n+----------------------------------------+");
        return ;
    }
    tmp = Last ;
    printf("\nData %d deleted from linked list ",tmp->data) ;
    printf("\n=================================");
    if(First == Last) {                             //Checks if Linked List Having only one Node or not?
        First = Last = NULL ;                       //If yes then Linked List will be empty
    } else {
        Curr = First ;
        while(Curr->next != Last) {
            Curr = Curr->next ;
        }
        Curr->next = NULL ;     
        Last = Curr ;                               //Else Last will point Old Last pointer's previous Node
    }
    free(tmp) ;
}

void deletePerticuler() {
    if(isempty()) {                                 //Checks if Link List is empty? 
        printf("\n+---------------------------------------------+");
        printf("\n| Linked List is empty                        |");
        printf("\n| Delete Perticular Operation can't be done . |");
        printf("\n+---------------------------------------------+");
        return ;
    }
    int index , cnt = 1 ;
    printf("Enter which index you want to delete from Linked List = ");
    scanf("%d" , &index);
    tmp = First ;
    while(tmp->next != NULL && cnt < index) {
        cnt++ ;
        Curr = tmp ;
        tmp = tmp->next ;
    }
    if(cnt == index) {                              //Checks if index entered by user is available or not?
        printf("\nElement %d deleted from Linked List . ",tmp->data);   //If yes then,
        printf("\n======================================");
        if(First == Last) {                         //Checks if Linked List Having only one Node or not?
            First = Last = NULL ;                   //If yes then Linked List will be empty
        } else if(tmp == First) {                   //Checks if user want to delete First Node?
            First = First->next ;                   //If yes then First will points old First's next Node
        } else if(tmp == Last) {                    //Checks if user want to delete Last Node?
            Curr->next = NULL ;                     //If yes then Last will points to old Last's previous Node
            Last = Curr ;
        } else {                                    //User wants to delete Node in between First and Last
            Curr->next = tmp->next ;
        }
    } else {        //Index is not available.
        printf("\n%d index not found in Linked List . ",index);
        printf("\n====================================");
    }
    free(tmp);
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for train coach node
struct Node {
    int coachNumber;          // Unique coach number
    char coachType[20];       // Type of coach (AC, Sleeper, General)
    int capacity;             // Total number of seats in the coach
    int occupiedSeats;        // Currently occupied seats
    struct Node* next;        // Pointer to the next coach in the train
} *First = NULL, *Last = NULL, *Curr = NULL, *tmp = NULL;

// Function declarations
bool isempty();
bool isCoachNumberUnique(int number);
bool isValidCoachType(char *type);
void insertFirst();
void insertLast();
void traverse();
void deleteFirst();
void deleteLast();

int main() {
    int ch = -1;
    while (ch != 0) {
        printf("\n\n+------------------------+");
        printf("\n|        Choices         |");
        printf("\n+------------------------+");
        printf("\n| 1).Insert First        |");
        printf("\n| 2).Insert Last         |");
        printf("\n| 3).Delete First        |");
        printf("\n| 4).Delete Last         |");
        printf("\n| 5).Traverse            |");
        printf("\n| 0).Exit                |");
        printf("\n+------------------------+");
        printf("\n\nEnter your choice = ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            insertFirst();
            break;
        case 2:
            insertLast();
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            traverse();
            break;
        case 0:
            printf("\nExiting........\n");
            break;
        default:
            printf("\nEnter valid choice!\n");
            break;
        }
    }
    return 0;
}

// Check if the list is empty
bool isempty() {
    return First == NULL;
}

// Check if the coach number is unique
bool isCoachNumberUnique(int number) {
    Curr = First;
    while (Curr != NULL) {
        if (Curr->coachNumber == number) {
            return false;  // Coach number is not unique
        }
        Curr = Curr->next;
    }
    return true;  // Coach number is unique
}

// Check if the coach type is valid
bool isValidCoachType(char *type) {
    return (strcmp(type, "AC") == 0 || strcmp(type, "Sleeper") == 0 || strcmp(type, "General") == 0);
}

// Insert a coach at the beginning
void insertFirst() {
    // Allocate memory for the new node
    tmp = (struct Node*)malloc(sizeof(struct Node));

    // Take input for the new node's fields directly into tmp
    do {
        printf("Enter coach number: ");
        scanf("%d", &tmp->coachNumber);
        if (!isCoachNumberUnique(tmp->coachNumber)) {
            printf("\nError: Coach number must be unique!\n");
        }
    } while (!isCoachNumberUnique(tmp->coachNumber));

    do {
        printf("Enter coach type (AC, Sleeper, General): ");
        scanf("%s", tmp->coachType);
        if (!isValidCoachType(tmp->coachType)) {
            printf("\nError: Invalid coach type! Please enter 'AC', 'Sleeper', or 'General'.\n");
        }
    } while (!isValidCoachType(tmp->coachType));

    do {
        printf("Enter coach capacity (0-70): ");
        scanf("%d", &tmp->capacity);
        if (tmp->capacity < 0 || tmp->capacity > 70) {
            printf("\nError: Coach capacity must be between 0 and 70.\n");
        }
    } while (tmp->capacity < 0 || tmp->capacity > 70);

    do {
        printf("Enter number of occupied seats: ");
        scanf("%d", &tmp->occupiedSeats);
        if (tmp->occupiedSeats < 0 || tmp->occupiedSeats > tmp->capacity) {
            printf("\nError: Occupied seats must be non-negative and less than or equal to the capacity.\n");
        }
    } while (tmp->occupiedSeats < 0 || tmp->occupiedSeats > tmp->capacity);

    // Insert the node at the beginning
    tmp->next = First;
    if (isempty()) {
        First = Last = tmp;
    } else {
        First = tmp;
    }

    printf("\nCoach %d inserted successfully at First Pos.\n", tmp->coachNumber);
    printf("===============================================");
}

// Insert a coach at the end
void insertLast() {
    // Allocate memory for the new node
    tmp = (struct Node*)malloc(sizeof(struct Node));

    // Take input for the new node's fields directly into tmp
    do {
        printf("Enter coach number: ");
        scanf("%d", &tmp->coachNumber);
        if (!isCoachNumberUnique(tmp->coachNumber)) {
            printf("\nError: Coach number must be unique!\n");
        }
    } while (!isCoachNumberUnique(tmp->coachNumber));

    do {
        printf("Enter coach type (AC, Sleeper, General): ");
        scanf("%s", tmp->coachType);
        if (!isValidCoachType(tmp->coachType)) {
            printf("\nError: Invalid coach type! Please enter 'AC', 'Sleeper', or 'General'.\n");
        }
    } while (!isValidCoachType(tmp->coachType));

    do {
        printf("Enter coach capacity (0-70): ");
        scanf("%d", &tmp->capacity);
        if (tmp->capacity < 0 || tmp->capacity > 70) {
            printf("\nError: Coach capacity must be between 0 and 70.\n");
        }
    } while (tmp->capacity < 0 || tmp->capacity > 70);

    do {
        printf("Enter number of occupied seats: ");
        scanf("%d", &tmp->occupiedSeats);
        if (tmp->occupiedSeats < 0 || tmp->occupiedSeats > tmp->capacity) {
            printf("\nError: Occupied seats must be non-negative and less than or equal to the capacity.\n");
        }
    } while (tmp->occupiedSeats < 0 || tmp->occupiedSeats > tmp->capacity);

    // Insert the node at the end
    tmp->next = NULL;
    if (isempty()) {
        First = Last = tmp;
    } else {
        Last->next = tmp;
        Last = tmp;
    }

    printf("\nCoach %d inserted successfully at Last Pos.\n", tmp->coachNumber);
    printf("===============================================");
}

// Traverse and display all coaches
void traverse() {
    if (isempty()) {
        printf("\nLinked List is empty.\n");
        return;
    }
    Curr = First;
    printf("\nLinked List: ");
    while (Curr != NULL) {
        printf("\n| Coach Number: %d, Type: %s, Capacity: %d, Occupied: %d |", 
            Curr->coachNumber, Curr->coachType, Curr->capacity, Curr->occupiedSeats);
        printf("\n\t\t\t||");
        printf("\n\t\t\t\\/");  // Visual representation of the linked list traversal
        Curr = Curr->next;
    }
    printf("\n\t\t\tNULL\n"); // End of the linked list
}

// Delete the first coach
void deleteFirst() {
    if (isempty()) {
        printf("\nNo coaches to delete.\n");
        return;
    }

    tmp = First;
    printf("\nDeleting Coach Number %d...\n", First->coachNumber);
    if (First == Last) {  // If there's only one node
        First = Last = NULL;
    } else {
        First = First->next;
    }
    free(tmp);

    printf("First coach deleted successfully.\n");
    printf("===============================================");
}

// Delete the last coach
void deleteLast() {
    if (isempty()) {
        printf("\nNo coaches to delete.\n");
        return;
    }

    if (First == Last) {  // If there's only one node
        printf("\nDeleting Coach Number %d...\n", First->coachNumber);
        free(First);
        First = Last = NULL;
    } else {
        Curr = First;
        while (Curr->next != Last) {  // Traverse to the second last node
            Curr = Curr->next;
        }
        printf("\nDeleting Coach Number %d...\n", Last->coachNumber);
        free(Last);
        Last = Curr;
        Last->next = NULL;
    }

    printf("Last coach deleted successfully.\n");
    printf("===============================================");
}

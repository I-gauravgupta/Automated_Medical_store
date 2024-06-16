#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a medicine
struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Medicine *next;
};

struct Medicine *head = NULL; // Head of the linked list

// Function to add a new medicine to the inventory
void addMedicine(int id, const char *name, int quantity, float price) {
    struct Medicine *newMedicine = (struct Medicine *)malloc(sizeof(struct Medicine));
    if (newMedicine == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newMedicine->id = id;
    strcpy(newMedicine->name, name);
    newMedicine->quantity = quantity;
    newMedicine->price = price;
    
    if (head == NULL) {
        head = newMedicine;
    } else {
        // struct Medicine *temp = head;
        newMedicine->next = head;
        head = newMedicine;
    }

    printf("Medicine added successfully.\n");
}

// Function to display all medicines in inventory
void displayMedicines() {
    struct Medicine *temp = head;
    if (temp == NULL) {
        printf("No medicines in inventory.\n");
        return;
    }

    printf("Medicine Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    while (temp != NULL) {
        printf("%d\t%s\t%d\t\t$%.2f\n", temp->id, temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

// Function to search for a medicine by ID
struct Medicine *findMedicine(int id) {
    struct Medicine *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to sell a medicine
void sellMedicine(int id, int quantity) {
    struct Medicine *med = findMedicine(id);
    if (med != NULL) {
        if (med->quantity >= quantity) {
            med->quantity -= quantity;
            printf("Sold %d units of %s. Remaining quantity: %d\n", quantity, med->name, med->quantity);
        } else {
            printf("Insufficient quantity of %s in inventory.\n", med->name);
        }
    } else {
        printf("Medicine not found.\n");
    }
}

// Main function
int main() {
    addMedicine(1, "Paracetamol", 100, 2.5);
    addMedicine(2, "Ibuprofen", 50, 3.0);
    addMedicine(3, "Aspirin", 75, 1.8);

    int choice, id, quantity;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Display Medicines\n");
        printf("2. Sell Medicine\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMedicines();
                break;
            case 2:
                printf("Enter medicine ID: ");
                scanf("%d", &id);
                printf("Enter quantity to sell: ");
                scanf("%d", &quantity);
                sellMedicine(id, quantity);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
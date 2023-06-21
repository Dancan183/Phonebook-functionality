#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
};

void addContact(struct Contact contacts[], int* count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter contact name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline character

    printf("Enter contact phone number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline character

    contacts[*count] = newContact;
    (*count)++;

    printf("Contact added successfully.\n");
}

void searchContact(struct Contact contacts[], int count, const char* searchName) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayAllContacts(struct Contact contacts[], int count) {
    if (count == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("All contacts:\n");

    for (int i = 0; i < count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;
    char searchName[50];

    do {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                printf("Enter the name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character
                searchContact(contacts, contactCount, searchName);
                break;
            case 3:
                displayAllContacts(contacts, contactCount);
                break;
            case 4:
                printf("Exiting phonebook. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

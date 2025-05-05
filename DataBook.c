#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure to store employee entry data
struct EntryData {
    int employeeID;
    char name[50];
    char entryTime[6]; // Time in HH:MM format
    char exitTime[6];  // Time in HH:MM format
};

// Function to display the menu
void displayMenu() {
    printf("\n--- Office Entry Data Book ---\n");
    printf("1. Add Entry\n");
    printf("2. Display All Entries\n");
    printf("3. Search Entry by ID\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to add entry data
void addEntry(struct EntryData* entries, int* count) {
    if (*count >= MAX_ENTRIES) {
        printf("Maximum entries reached.\n");
        return;
    }

    struct EntryData newEntry;

    printf("\nEnter Employee ID: ");
    scanf("%d", &newEntry.employeeID);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", newEntry.name); // To allow spaces in name

    printf("Enter Entry Time (HH:MM): ");
    scanf("%s", newEntry.entryTime);

    printf("Enter Exit Time (HH:MM): ");
    scanf("%s", newEntry.exitTime);

    entries[*count] = newEntry;
    (*count)++;

    printf("Entry added successfully.\n");
}

// Function to display all entries
void displayEntries(struct EntryData* entries, int count) {
    if (count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n--- Employee Entry Data ---\n");
    printf("Employee ID\tName\t\tEntry Time\tExit Time\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t%s\t%s\n", entries[i].employeeID, entries[i].name, entries[i].entryTime, entries[i].exitTime);
    }
}

// Function to search entry by Employee ID
void searchEntryByID(struct EntryData* entries, int count) {
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (entries[i].employeeID == id) {
            printf("\n--- Employee Entry Data ---\n");
            printf("Employee ID: %d\n", entries[i].employeeID);
            printf("Name: %s\n", entries[i].name);
            printf("Entry Time: %s\n", entries[i].entryTime);
            printf("Exit Time: %s\n", entries[i].exitTime);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    struct EntryData entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                displayEntries(entries, count);
                break;
            case 3:
                searchEntryByID(entries, count);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

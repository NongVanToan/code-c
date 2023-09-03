#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Cấu trúc dữ liệu để lưu trữ thông tin liên hệ
struct Contact {
    char name[50];
    char phone[20];
    char address[100];
};

// Hàm thêm thông tin liên hệ mới vào tập tin danh bạ
void addContact(FILE* file) {
    struct Contact contact;

    printf("Enter name: ");
    fgets(contact.name, sizeof(contact.name), stdin);
    contact.name[strcspn(contact.name, "\n")] = '\0'; // Xóa ký tự newline

    printf("Enter phone number: ");
    fgets(contact.phone, sizeof(contact.phone), stdin);
    contact.phone[strcspn(contact.phone, "\n")] = '\0'; // Xóa ký tự newline

    printf("Enter address: ");
    fgets(contact.address, sizeof(contact.address), stdin);
    contact.address[strcspn(contact.address, "\n")] = '\0'; // Xóa ký tự newline

    fprintf(file, "%s|%s|%s\n", contact.name, contact.phone, contact.address);
    printf("\nContact added successfully!\n\n");
}

// Hàm hiển thị toàn bộ danh sách liên hệ từ tập tin
void displayContacts(FILE* file) {
    struct Contact contact;
    int contactCount = 0;

    printf("Contact List:\n");

    while (fscanf(file, "%s|%s|%s\n", contact.name, contact.phone, contact.address) != EOF) {
        printf("%d. Name: %s\n   Phone: %s\n   Address: %s\n\n", ++contactCount, contact.name, contact.phone, contact.address);
    }

    if (contactCount == 0) {
        printf("No contacts found.\n\n");
    }
}

// Hàm tìm kiếm thông tin liên hệ dựa trên tên
void searchContact(FILE* file) {
    struct Contact contact;
    char searchName[50];
    int contactCount = 0;
    int found = 0;

    printf("Enter name to search for: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Xóa ký tự newline

    printf("\nContact found:\n");

    while (fscanf(file, "%s|%s|%s\n", contact.name, contact.phone, contact.address) != EOF) {
        if (strcmp(contact.name, searchName) == 0) {
            printf("Name: %s\nPhone: %s\nAddress: %s\n\n", contact.name, contact.phone, contact.address);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found with the name '%s'.\n\n", searchName);
    }
}

int main() {
    FILE* file = fopen("contacts.txt", "a+");

    if (file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }

    int choice;

    while (1) {
        printf("Welcome to the Contact Manager!\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự newline

        printf("\n");

        switch (choice) {
            case 1:
                addContact(file);
                break;
            case 2:
                displayContacts(file);
                break;
            case 3:
                searchContact(file);
                break;
            case 4:
                fclose(file);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    fclose(file);

    return 0;
}
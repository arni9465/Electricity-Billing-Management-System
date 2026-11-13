
#include <stdio.h>
#include <stdlib.h>

struct Customer {
    int id;
    char name[100];
    int units;
    float bill;
};

float calculateBill(int units) {
    float amount = 0;

    if (units <= 100) {
        amount = units * 3;
    }
    else if (units <= 200) {
        amount = 100 * 3 + (units - 100) * 5;
    }
    else if (units <= 300) {
        amount = 100 * 3 + 100 * 5 + (units - 200) * 7;
    }
    else {
        amount = 100 * 3 + 100 * 5 + 100 * 7
                 + (units - 300) * 8;
    }

    return amount + 50;
}

void addBill() {
    struct Customer c;

    printf("\nEnter Customer ID: ");
    scanf("%d", &c.id);

    printf("Enter Customer Name: ");
    scanf(" %99[^\n]", c.name);

    printf("Enter Units Consumed: ");
    scanf("%d", &c.units);

    if (c.units < 0) {
        printf("Invalid units.\n");
        return;
    }

    c.bill = calculateBill(c.units);

    FILE *fp = fopen("bills.txt", "a");

    if (fp == NULL) {
        printf("Error saving bill.\n");
        return;
    }

    fprintf(fp, "%d|%s|%d|%.2f\n",
            c.id, c.name, c.units, c.bill);

    fclose(fp);

    printf("\n----- ELECTRICITY BILL -----\n");
    printf("Customer ID: %d\n", c.id);
    printf("Customer Name: %s\n", c.name);
    printf("Units Consumed: %d\n", c.units);
    printf("Total Bill: Rs. %.2f\n", c.bill);
}

void viewBills() {
    struct Customer c;
    FILE *fp = fopen("bills.txt", "r");

    if (fp == NULL) {
        printf("\nNo bills found.\n");
        return;
    }

    printf("\n----- SAVED CUSTOMER BILLS -----\n");

    while (fscanf(fp, "%d|%99[^|]|%d|%f",
                  &c.id, c.name, &c.units, &c.bill) == 4) {
        printf("\nID: %d\nName: %s\nUnits: %d\nBill: Rs. %.2f\n",
               c.id, c.name, c.units, c.bill);
    }

    fclose(fp);
}

void searchBill() {
    struct Customer c;
    int searchID, found = 0;

    printf("\nEnter Customer ID to search: ");
    scanf("%d", &searchID);

    FILE *fp = fopen("bills.txt", "r");

    if (fp == NULL) {
        printf("\nNo bills found.\n");
        return;
    }

    while (fscanf(fp, "%d|%99[^|]|%d|%f",
                  &c.id, c.name, &c.units, &c.bill) == 4) {
        if (c.id == searchID) {
            printf("\n----- CUSTOMER BILL FOUND -----\n");
            printf("ID: %d\nName: %s\nUnits: %d\nBill: Rs. %.2f\n",
                   c.id, c.name, c.units, c.bill);
            found = 1;
        }
    }

    if (!found) {
        printf("\nCustomer ID not found.\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n===== ELECTRICITY BILLING SYSTEM =====\n");
        printf("1. Add Customer Bill\n");
        printf("2. View All Bills\n");
        printf("3. Search Customer Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addBill();
                break;
            case 2:
                viewBills();
                break;
            case 3:
                searchBill();
                break;
            case 4:
                printf("\nThank you for using the system.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

#include <stdio.h>
#include <string.h>

/*Global account data*/
int    ids[100];
char   names[100][50];
double balances[100];
int    numAccounts = 0;

/*Functions*/
void createAccount(char name[], double initialDeposit);
void deposit(int id, double amount);
void displayAccount(int id);
void displayAll();
int  findAccount(int id);
void printMenu();

int main() {
    int choice;
    int id;
    double amount;
    char name[50];

    printf("Welcome to Procedural Programming 1310-010 National Bank\n");
    printf("----------------------------------------------------------\n\n");

    do {
        printMenu();
        printf("Choice: ");
        scanf("%d", &choice);
/*UI Selection Option Functions*/
        if (choice == 1) {
            printf("Name: ");
            scanf(" %[^\n]", name);
            printf("Initial deposit: $");
            scanf("%lf", &amount);
            createAccount(name, amount);

        } else if (choice == 2) {
            printf("Account ID: ");
            scanf("%d", &id);
            printf("Amount: $");
            scanf("%lf", &amount);
            deposit(id, amount);

        } else if (choice == 3) {
            printf("Account ID: ");
            scanf("%d", &id);
            displayAccount(id);

        } else if (choice == 4) {
            displayAll();

        } else if (choice == 5) {
            printf("Exiting. Goodbye!\n");
/* Invalid Input Handling*/
        } else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
/*Create UI*/
void printMenu() {
    printf("\n-----------------------------\n");
    printf("  1. Open new account\n");
    printf("  2. Deposit\n");
    printf("  3. View account\n");
    printf("  4. View all accounts\n");
    printf("  5. Exit\n");
    printf("-----------------------------\n");
}

/*Find index of account by ID, returns -1 if not found*/
int findAccount(int id) {
    for (int i = 0; i < numAccounts; i++) {
        if (ids[i] == id)
            return i;
    }
    return -1;
}

/*Create a new account*/
void createAccount(char name[], double initialDeposit) {
    if (numAccounts >= 100) {
        printf("Error: maximum number of accounts reached.\n");
        return;
    }
    ids[numAccounts] = numAccounts + 1001;
    strncpy(names[numAccounts], name, 49);
    names[numAccounts][49] = '\0';
    balances[numAccounts] = initialDeposit;
    printf("Account created! ID: %d, Name: %s, Balance: $%.2f\n",
           ids[numAccounts], names[numAccounts], balances[numAccounts]);
    numAccounts++;
}

/*Deposit into an account*/
void deposit(int id, double amount) {
    int i = findAccount(id);
    if (i == -1) {
        printf("Error: account %d not found.\n", id);
        return;
    }
    balances[i] += amount;
    printf("Deposited $%.2f. New balance: $%.2f\n", amount, balances[i]);
}

/*Display a single account*/
void displayAccount(int id) {
    int i = findAccount(id);
    if (i == -1) {
        printf("Error: account %d not found.\n", id);
        return;
    }
    printf("ID: %d | Name: %s | Balance: $%.2f\n",
           ids[i], names[i], balances[i]);
}

/*Display all accounts*/
void displayAll() {
    if (numAccounts == 0) {
        printf("No accounts on file.\n");
        return;
    }
    printf("\n%-8s %-20s %s\n", "ID", "Name", "Balance");
    printf("-------------------------------------------\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%-8d %-20s $%.2f\n", ids[i], names[i], balances[i]);
    }
}

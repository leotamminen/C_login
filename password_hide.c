#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20

// Program reads both username and password from passwords.csv file, compares them with the user's input.
// login is allowed only if both match. The program then lets the user view decrypted content of secret.txt.

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} UserInfo;

// Function to decrypt text using Caesar cipher
void caesarDecrypt(FILE *encryptedFile, int shift) {
    int ch;
    while ((ch = fgetc(encryptedFile)) != EOF) {
        char decryptedChar = ch;

        if (decryptedChar >= '!' && decryptedChar <= '~') {
            decryptedChar = ((decryptedChar - '!' - shift + 94) % 94) + '!';
        }

        putchar(decryptedChar);
    }
}

// Function to perform actions after successful login
void loggedInActions(const char *username) {
    printf("\nWelcome, %s!\n", username);

    FILE *secretFile = fopen("secret.txt", "r");

    if (secretFile == NULL) {
        printf("Error opening the secret file.\n");
        exit(1);
    }

    printf("Here's the decrypted content of secret.txt:\n");

    // Assuming the shift is 1 for Caesar decryption
    caesarDecrypt(secretFile, 1);

    fclose(secretFile);

    printf("\nPress Enter to log out...");
    fflush(stdin); // Clear the input buffer
    getchar();    // Wait for Enter key press
}

// Function to handle login
int login() {
    char ch;
    char username[MAX_LENGTH], pass[MAX_LENGTH];

    printf("Enter your username : ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove the newline character from the username

    printf("Enter your password : ");
    int i = 0;

    while (1)
    {
        ch = getch();

        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8) // Handle Backspace
        {
            if (i > 0)
            {
                i--;
                printf("\b \b"); // Move the cursor back and erase the character
            }
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }

    printf("\nYou entered:\nUsername: %s\nPassword: %s\n", username, pass);

    FILE *ptr;
    ptr = fopen("passwords.csv", "r");

    if (ptr == NULL)
    {
        printf("Error opening the file.\n");
        exit(1);
    }

    UserInfo user;
    int match_found = 0;

    while (fscanf(ptr, "%[^,],%s\n", user.username, user.password) == 2)
    {
        if (strcmp(username, user.username) == 0 && strcmp(pass, user.password) == 0)
        {
            match_found = 1;
            break;
        }
    }

    fclose(ptr);

    if (match_found)
    {
        printf("\n\n******LOGIN SUCCESSFUL******\n");
        loggedInActions(username); // Call the function with actions for logged-in user
        return 1; // Return 1 to indicate successful login
    }
    else
    {
        printf("\n\n******INCORRECT USERNAME OR PASSWORD******\n");
        printf("Press Enter to try again...");
        while (getchar() != '\n'); // Wait for Enter key press
        system("cls");
        return 0; // Return 0 to indicate unsuccessful login
    }
}

int main() {
    int isLoggedIn = 0;

    do {
        isLoggedIn = login();
    } while (!isLoggedIn);

    return 0;
}
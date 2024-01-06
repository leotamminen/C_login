#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20

// Program reads both username and password from password.txt file, compares them with the user's input. 
// login is allowed only if both match. The program waits for the user to press Enter before exiting.

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} UserInfo;

int main()
{
    system("cls");
    char ch;
    char username[MAX_LENGTH], pass[MAX_LENGTH];

start:
    printf("Enter your username : ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';  // Remove the newline character from the username

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
        else if (ch == 8)  // Handle Backspace
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");  // Move the cursor back and erase the character
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
        printf("Press Enter to exit...");
        while (getchar() != '\n');  // Wait for Enter key press
    }
    else
    {
        printf("\n\n******INCORRECT USERNAME OR PASSWORD******\n");
        printf("Press Enter to try again...");
        while (getchar() != '\n');  // Wait for Enter key press
        system("cls");
        goto start;
    }

    return 0;
}

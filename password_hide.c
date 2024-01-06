#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20

// Program reads both username and password from password.txt file, compares them with the user's input.
// login is allowed only if both match. The program waits for the user to press Enter before exiting.

int main()
{
    system("cls");
    char ch;
    char username[MAX_LENGTH], pass[MAX_LENGTH], saved_username[MAX_LENGTH], saved_pass[MAX_LENGTH];

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
    ptr = fopen("password.txt", "r");

    if (ptr == NULL)
    {
        printf("Error opening the file.\n");
        exit(1);
    }

    // Read the username and password from the file
    fscanf(ptr, "%s", saved_username);
    fscanf(ptr, "%s", saved_pass);
    fclose(ptr);

    int user_cmp = strcmp(username, saved_username);
    int pass_cmp = strcmp(pass, saved_pass);

    if (user_cmp == 0 && pass_cmp == 0)
    {
        printf("\n\n******LOGIN SUCCESSFUL******\n");
        printf("Press Enter to exit...");
        getchar(); // Wait for Enter key press
    }
    else
    {
        printf("\n\n******INCORRECT USERNAME OR PASSWORD******\n");
        goto start;
    }

    return 0;
}

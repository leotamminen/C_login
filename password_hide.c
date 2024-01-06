#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    system("cls");
    char ch;
    char pass[20], saved_pass[20];

start:
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
        else
            pass[i++] = ch;
        printf("*");
    }

    printf("\nYou entered : %s\n", pass);

    FILE *ptr;
    ptr = fopen("password.txt", "r");

    if (ptr == NULL)
    {
        printf("Error opening the file.\n");
        exit(1);
    }

    fscanf(ptr, "%s", saved_pass);
    fclose(ptr);

    printf("Password %s\n", saved_pass);

    int l = strcmp(pass, saved_pass);

    if (l == 0)
    {
        printf("\n\n******LOGIN SUCCESSFUL******\n");
        printf("Press Enter to exit...");
        getchar(); // Wait for Enter key press
    }
    else
    {
        printf("\n\n******INCORRECT PASSWORD******\n");
        goto start;
    }

    return 0;
}

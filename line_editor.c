
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int count = 0;

// Read an integer safely
int readInt(const char *message, int *value)
{
    char input[100];
    char *end;

    while (1)
    {
        printf("%s", message);

        if (fgets(input, sizeof(input), stdin) == NULL)
            return 0;

        long number = strtol(input, &end, 10);

        while (isspace((unsigned char)*end))
            end++;

        if (end != input && *end == '\0')
        {
            *value = (int)number;
            return 1;
        }

        printf("Invalid input! Enter a number.\n");
    }
}

// Read a line of text
void readText(char text[])
{
    if (fgets(text, MAX_LENGTH, stdin) != NULL)
    {
        text[strcspn(text, "\n")] = '\0';
    }
}

// Insert a line
void insertLine()
{
    int position;

    if (count == MAX_LINES)
    {
        printf("Document is full!\n");
        return;
    }

    if (!readInt("Enter line number: ", &position))
        return;

    if (position < 1 || position > count + 1)
    {
        printf("Invalid line number!\n");
        return;
    }

    for (int i = count; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    readText(lines[position - 1]);

    count++;

    printf("Line inserted successfully!\n");
}

// Delete a line
void deleteLine()
{
    int position;

    if (count == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    if (!readInt("Enter line number to delete: ", &position))
        return;

    if (position < 1 || position > count)
    {
        printf("Invalid line number!\n");
        return;
    }

    for (int i = position - 1; i < count - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    count--;

    printf("Line deleted successfully!\n");
}

// Display all lines
void displayLines()
{
    if (count == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

// Save document to file
void saveFile()
{
    FILE *fp = fopen("document.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to save file!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s\n", lines[i]);
    }

    fclose(fp);

    printf("Document saved successfully!\n");
}

// Load document from file
void loadFile()
{
    FILE *fp = fopen("document.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    count = 0;

    while (count < MAX_LINES &&
           fgets(lines[count], MAX_LENGTH, fp) != NULL)
    {

        lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
    }

    fclose(fp);

    printf("Document loaded successfully!\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== SIMPLE LINE EDITOR =====\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Save File\n");
        printf("5. Load File\n");
        printf("6. Exit\n");

        if (!readInt("Enter your choice: ", &choice))
            break;

        switch (choice)
        {
        case 1:
            insertLine();
            break;

        case 2:
            deleteLine();
            break;

        case 3:
            displayLines();
            break;

        case 4:
            saveFile();
            break;

        case 5:
            loadFile();
            break;

        case 6:
            printf("Thank you for using Line Editor!\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

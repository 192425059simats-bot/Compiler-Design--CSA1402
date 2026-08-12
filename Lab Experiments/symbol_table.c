#include <stdio.h>
#include <string.h>

#define MAX 100

struct Symbol
{
    char name[30];
    char type[20];
    int address;
};

struct Symbol table[MAX];
int count = 0;

void insert()
{
    char name[30], type[20];
    int address;

    printf("Enter symbol name: ");
    scanf("%s", name);

    printf("Enter data type: ");
    scanf("%s", type);

    printf("Enter address: ");
    scanf("%d", &address);

    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    table[count].address = address;

    count++;

    printf("Symbol inserted successfully.\n");
}

void display()
{
    int i;

    printf("\nSymbol Table\n");
    printf("--------------------------------\n");
    printf("Name\tType\tAddress\n");
    printf("--------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%s\t%s\t%d\n",
               table[i].name,
               table[i].type,
               table[i].address);
    }
}

void search()
{
    char name[30];
    int i;

    printf("Enter symbol to search: ");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            printf("Symbol found!\n");
            printf("Name    : %s\n", table[i].name);
            printf("Type    : %s\n", table[i].type);
            printf("Address : %d\n", table[i].address);
            return;
        }
    }

    printf("Symbol not found.\n");
}

void deleteSymbol()
{
    char name[30];
    int i, j;

    printf("Enter symbol to delete: ");
    scanf("%s", name);

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            for (j = i; j < count - 1; j++)
                table[j] = table[j + 1];

            count--;

            printf("Symbol deleted successfully.\n");
            return;
        }
    }

    printf("Symbol not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- SYMBOL TABLE ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteSymbol();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 20 // Changed from 10 to 20 to match array size

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX]; // Changed to use MAX for array size
int n, pos, e, i; // Removed unnecessary variables 'a', 'p', 'f'

int main()
{
    int ch;
    char g = 'y';
    
    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Enter the correct choice!\n");
        }

        printf("\nDo you want to continue (y/n)?: ");
        scanf(" %c", &g); // Added space before %c to consume newline

    } while(g == 'y' || g == 'Y');

    return 0;
}

void create() 
{
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    
    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &b[i]);
    }
}

void deletion() 
{
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid position!\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("\nThe elements after deletion:\n");
    display();
}

void search() 
{
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Element %d found at position %d.\n", e, i + 1);
            return; // Added return to stop searching once found
        }
    }

    printf("Element %d not found in the list.\n", e);
}

void insert() 
{
    printf("\nEnter the position you need to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos > n + 1 || pos <= 0) {
        printf("\nInvalid position!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &e);

    for (i = n - 1; i >= pos - 1; i--) {
        b[i + 1] = b[i];
    }
    b[pos - 1] = e;
    n++;

    printf("\nThe list after insertion:\n");
    display();
}

void display() 
{
    printf("\nThe elements in the list are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    int size;
    MenuChoice choice;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *array = (int *) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    array = generate_random_array(array, size);

    do {
        display_menu();
        printf("Your choice: ");

        int input;
        scanf("%d", &input);
        choice = (MenuChoice)input;

        if (choice >= SELECTION_SORT && choice <= HEAP_SORT) {
            run_menu(choice, array, size);
        } else if (choice == EXIT_PROGRAM) {
            printf("Exiting the program...\n");
        } else {
            printf("Invalid choice!\n");
        }

    } while (choice != EXIT_PROGRAM);

    free(array);
    return 0;
}

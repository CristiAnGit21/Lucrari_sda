#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define SUCCESS_FREE_MEMORY 0
#define FREE_MEMORY_FAILED -1
#define FAILED_FUNCTION -1

int allocate_person_array(Person **array, int count) {
    *array = (Person *)malloc(count * sizeof(Person));
    if (*array == NULL) {
        return FAILED_FUNCTION;
    }
    return 0;
}
void read_person_data(Person *p, int index) {
    printf("name #%d: ", index + 1);
    scanf("%s", p->name);
}
void free_person_array(Person **array, int *count) {
    if (*array != NULL) {
        free(*array);
        *array = NULL;
        *count = 0;
    }
}

int insert_name(Person **array, int *count) {
    free_person_array(array, count);

    printf("How many persons?: ");
    scanf("%d", count);

    if (allocate_person_array(array, *count) == FAILED_FUNCTION) {
        return FAILED_FUNCTION;
    }

    for (int i = 0; i < *count; i++) {
        read_person_data(&(*array)[i], i);
    }

    return 0;
}

void display_person(Person *person) {
    if(person != NULL) {
        printf("Name: %s\n", person->name);
    }
}

int display_persons(Person *array, int count) {
    if(count == 0 || array == NULL) {
        return FAILED_FUNCTION;
    }
    for(int i = 0; i < count; i++) {
        display_person(&array[i]);
    }
    return 0;
}

int search_name(const Person *array, int count) {
    if(count == 0 || array == NULL) {
        return FAILED_FUNCTION;
    }
    char nume[50];
    printf("searched name: ");
    scanf("%s", nume);
    for(int i = 0; i < count; i++) {
        if(strcmp(array[i].name, nume) == 0) {
            return i;
        }
    }
    return -1;
}
void swap_name(Person *first, Person *second) {
    Person temp = *first;
    *first = *second;
    *second = temp;
}

int sort_by_name(Person *array, int count) {
    if(count == 0 || array == NULL) {
        return FAILED_FUNCTION;
    }
    for(int i = 0; i < count-1; i++) {
        for(int j = 0; j < count-i-1; j++) {
            if(strcmp(array[j].name, array[j+1].name) > 0) {
                swap_name(&array[i], &array[j]);

            }
        }
    }
    printf("sort is complete!\n");
    return 0;
}


int get_insert_position(int count) {
    int pos;
    printf("position (0-%d): ", count);
    scanf("%d", &pos);

    if (pos < 0 || pos > count) {
        return FAILED_FUNCTION;
    }
    return pos;
}

int resize_array(Person **array, int new_size) {
    *array = realloc(*array, new_size * sizeof(Person));
    if (*array == NULL) {
        return FAILED_FUNCTION;
    }
    return 0;
}

void shift_elements(Person *array, int count, int pos) {
    for (int i = count; i > pos; i--) {
        array[i] = array[i - 1];
    }
}

int insert_at_position(Person **array, int *count) {
    int pos = get_insert_position(*count);

    if (resize_array(array, *count + 1) == 0) {
        return FAILED_FUNCTION;
    }

    shift_elements(*array, *count, pos);
    insert_at_end(array, count);

    (*count)++;
    return 0;
}

int get_delete_position(int count) {
    int pos;
    printf("position (0-%d): ", count - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= count) {
        return -1;
    }
    return pos;
}

void shift_elements_left(Person *array, int count, int pos) {
    for (int i = pos; i < count - 1; i++) {
        array[i] = array[i + 1];
    }
}

int delete_at_position(Person **array, int *count) {
    int pos = get_delete_position(*count);
    if (pos == -1) {
        return FAILED_FUNCTION;
    }

    shift_elements_left(*array, *count, pos);
    (*count)--;

    if (*count > 0) {
        if (resize_array(array, *count) == FAILED_FUNCTION) {
            return FAILED_FUNCTION;
        }
    } else {
        free(*array);
        *array = NULL;
    }
    return 0;
}

int free_array(Person **array, int *count) {
    if(*array != NULL) {
        free(*array);
        *array = NULL;
        *count = 0;
        return SUCCESS_FREE_MEMORY;
    }
    return FREE_MEMORY_FAILED;
}

void print_menu(void) {
    printf("\nMenu:\n");
    printf("1. Read elements\n");
    printf("2. Display elements\n");
    printf("3. Search element\n");
    printf("4. Sort elements\n");
    printf("5. Insert at final\n");
    printf("6. Insert at the beginning\n");
    printf("7. Insert at the position\n");
    printf("8. Delete from position\n");
    printf("9. Free memory\n");
    printf("0. Exit\n");
}

void run_menu() {
    Person *people = NULL;
    int count = 0;
    int choice;

    do {
        print_menu();
        printf("Option: ");
        scanf("%d", &choice);

        switch(choice) {
            case INSERT_NAME:
                insert_name(people, &count);
            break;
            case DISPLAY_PERSONS:
                display_persons(people, count);
            break;
            case SEARCH_NAME: {
                int pos = search_name(people, count);
                if (pos != -1) {
                    printf("Found at position %d\n", pos);
                } else {
                    printf("Error at searched position\n");
                }
                break;
            }
            case SORT_BY_NAME:
                sort_by_name(people, count);
            break;
            case INSERT_AT_END:
                insert_at_end(&people, &count);
            break;
            case INSERT_AT_START:
                insert_at_start(&people, &count);
            break;
            case INSERT_AT_POSITION:
                insert_at_position(&people, &count);
            break;
            case DELETE_AT_POSITION:
                delete_at_position(&people, &count);
            break;
            case FREE_ARRAY:
                free_array(&people, &count);
            break;
            case EXIT:
                printf("Exit...\n");
            break;
            default:
                printf("Invalid option. Please try again.\n");
            break;
        }
    } while (choice != EXIT);

    free_array(&people, &count);

}

int insert_at_end(Person **array, int *count) {
    if (resize_array(array, *count) == FAILED_FUNCTION) {
        return FAILED_FUNCTION;
    }

    read_person_data(array[*count], *count);

    (*count)++;
    return 0;
}
void shift_elements_right_from_start(Person *array, int count) {
    for (int i = count; i > 0; i--) {
        array[i] = array[i - 1];
    }
}
int insert_at_start(Person **array, int *count) {
    if (resize_array(array, *count) == 0) {
        return FAILED_FUNCTION;
    }

    shift_elements_right_from_start(*array, *count);
    read_person_data(array[*count], *count);

    (*count)++;
    return 0;
}
//
// Created by Cristian on 22.03.2025.
//


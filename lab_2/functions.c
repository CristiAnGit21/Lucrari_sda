//
// Created by Cristian on 02.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define FAILED_FUNCTION -1

Node *create_node() {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->iPhone = (IPhone *) malloc(sizeof(IPhone));
    new_node->iPhone->model = (char *) malloc(50 * sizeof(char));
    printf("Enter ID: ");
    scanf("%d", &new_node->iPhone->Id);
    printf("Enter Model: ");
    scanf("%s", new_node->iPhone->model);
    printf("Enter Year: ");
    scanf("%d", &new_node->iPhone->year);

    new_node->next = NULL;
    return new_node;
}

int print_list(LinkedList *list) {
    Node *current = list->head;
    int position = 1;
    printf("\nIphone list:\n");
    while (current != NULL) {
        printf("Iphone nr.%d\n ID: %d\n Model: %s\n Year: %d\n\n",
               position, current->iPhone->Id, current->iPhone->model, current->iPhone->year);
        current = current->next;
        position++;
    }
    return FAILED_FUNCTION;
}

void insert_at_beginning(LinkedList *list, Node *new_node) {
    new_node->next = list->head;
    list->head = new_node;
}

void insert_at_end(LinkedList *list, IPhone *new_phone) {
    Node *new_node = create_node();
    new_node->iPhone = new_phone;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void swap_models(IPhone *model_1, IPhone *model_2) {
    char *temp = model_1->model;
    model_1->model = model_2->model;
    model_2->model = temp;
}

int sort_model(LinkedList *list) {
    if (list->head == NULL || list->head->next == NULL) {
        return FAILED_FUNCTION;
    }
    for (Node *i = list->head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->iPhone->model, j->iPhone->model) > 0) {
                swap_models(i->iPhone, j->iPhone);
            }
        }
    }
    return 0;
}

void free_list(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        IPhone *temp = current;
        current = current->next;
        free(temp->model);
        free(temp);
    }
}

int search_by_name(LinkedList *list, char searched_name[]) {
    Node *current = list->head;
    int position = 1;
    while (current != NULL) {
        if (strcmp(current->iPhone->model, searched_name) == 0) {
            return position;
        }
        current = current->next;
    }
    return FAILED_FUNCTION;
}

int insert_by_position(LinkedList *list, Node *newPhone, int position) {
    if (position < 1) {
        return FAILED_FUNCTION;
    }
    if (position == 1) {
        insert_beginning(list->head, newPhone);
    } else {
        Node *current = list->head;
        int i = 1;
        while (current != NULL && i < position - 1) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            return FAILED_FUNCTION;
        }
        newPhone = current->next;
        current->next = newPhone;
    }
    return 0;
}

int delete_at_position(LinkedList *list, int position) {
    if (list->head == NULL) {
        return FAILED_FUNCTION;
    }
    if (position < 1) {
        return FAILED_FUNCTION;
    }

    Node *temp = list->head;
    if (position == 1) {
        list->head = (list->head)->next;
        free(temp->iPhone->model);
        free(temp);
    } else {
        Node *prev = NULL;
        int i = 1;
        while (temp != NULL && i < position) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            return FAILED_FUNCTION;
        }
        prev->next = temp->next;
        free(temp->iPhone->model);
        free(temp);
    }
    return 0;
}

void inverse_list(LinkedList *list) {
    Node *prev = NULL, *current = list->head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

void erase_list(LinkedList *list) {
    free_list(list->head);
    list->head = NULL;
}
void print_menu(void) {
    printf("\nMENU:\n");
    printf("\n1. Read phone\n");
    printf("2. Display list\n");
    printf("3. Search phone by name\n");
    printf("4. Free list memory\n");
    printf("5. Sort list\n");
    printf("6. Insert at the beginning\n");
    printf("7. Insert at the end\n");
    printf("8. Insert at position\n");
    printf("9. Delete phone from a position\n");
    printf("10. Inverse list\n");
    printf("11. Erase list\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}
void run_menu() {
    LinkedList list = {NULL};
    int choice, position;
    do {
        char searchModel[50];
        print_menu();
        printf("Option: ");
        scanf("%d", &choice);

        switch ((MenuOption) choice) {
            case READ_PHONE:
                insert_end(&list, create_node());
                break;
            case DISPLAY_LIST:
                print_list(&list);
                break;
            case SEARCH_PHONE:
                printf("Enter model to search: ");
                scanf("%s", searchModel);
                position = search_name(&list, searchModel);
                if (position != -1) {
                    printf("Phone found at position: %d\n", position);
                } else {
                    printf("Phone not found.\n");
                }
                break;
            case FREE_MEMORY:
                free_list(&list);
                printf("List freed.\n");
                break;
            case SORT_LIST:
                sort_model(&list);
                printf("List sorted.\n");
                break;
            case INSERT_BEGINNING:
                insert_beginning(&list, create_node());
                break;
            case INSERT_END:
                insert_end(&list, create_node());
                break;
            case INSERT_POSITION:
                printf("Enter position: ");
                scanf("%d", &position);
                insert_position(&list, create_node(), position);
                break;
            case DELETE_POSITION:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_position(&list, position);
                break;
            case INVERSE_LIST:
                inverse_list(&list);
                printf("List reversed.\n");
                break;
            case ERASE_LIST:
                erase_list(&list);
                printf("List erased.\n");
                break;
            case EXIT:
                printf("Exiting...\n");
                free_list(&list);
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (choice != EXIT);
}

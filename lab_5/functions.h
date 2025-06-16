//
// Created by Cristian on 16.05.2025.
//
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef enum {
    SELECTION_SORT = 1,
    INSERTION_SORT,
    BUBBLE_SORT,
    MERGE_SORT,
    QUICK_SORT,
    HEAP_SORT,
    EXIT_PROGRAM
} MenuChoice;

void display_menu();

int* generate_random_array(int *array, int size);

void display_array(const int *array, int size);

void selection_sort(int array[], int size);

void insertion_sort(int array[], int size);

void bubble_sort(int array[], int size);

void merge_sort(int array[], int left, int right);

void quick_sort(int array[], int low, int high);

void heap_sort(int array[], int size);

void display_menu();

void run_menu(MenuChoice choice, int *array, int size);
#endif

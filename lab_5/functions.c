//
// Created by Cristian on 16.05.2025.
//
#include "functions.h"
#include <stdio.h>

/**
 * @file sorting_algorithms.c
 * @brief Implementation of various sorting algorithms and execution time measurement.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @brief Swaps the values of two integers.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Generates a random integer array with values between 0 and 999.
 * @param arr Pointer to the array to be filled.
 * @param size The number of elements in the array.
 * @return Pointer to the filled array.
 */
int* generate_random_array(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 1000;
    return arr;
}

/**
 * @brief Displays the contents of an integer array.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 */
void display_array(const int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/**
 * @brief Sorts an array using Selection Sort.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 */
void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i)
            swap(&arr[i], &arr[min_idx]);
    }
}

/**
 * @brief Sorts an array using Insertion Sort.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 */
void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

/**
 * @brief Sorts an array using Bubble Sort.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 */
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

/**
 * @brief Merges two sorted subarrays.
 * @param arr The main array.
 * @param left The starting index of the left subarray.
 * @param mid The ending index of the left subarray.
 * @param right The ending index of the right subarray.
 */
void merge(int *arr, int left, int mid, int right) {
    int i, j;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; int k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

/**
 * @brief Sorts an array using Merge Sort.
 * @param arr Pointer to the array.
 * @param left The starting index.
 * @param right The ending index.
 */
void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * @brief Partitions the array for Quick Sort using the last element as pivot.
 * @param arr Pointer to the array.
 * @param low The starting index.
 * @param high The ending index.
 * @return The partition index.
 */
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/**
 * @brief Sorts an array using Quick Sort.
 * @param arr Pointer to the array.
 * @param low The starting index.
 * @param high The ending index.
 */
void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

/**
 * @brief Maintains the heap property for Heap Sort.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 * @param root The root index of the heap/subtree.
 */
void heapify(int *arr, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, size, largest);
    }
}

/**
 * @brief Sorts an array using Heap Sort.
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 */
void heap_sort(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/**
 * @brief Displays the sorting algorithm menu.
 */
void display_menu() {
    printf("\nChoose the sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("7. Exit\n");
}

/**
 * @brief Executes the selected sorting algorithm and displays the result and execution time.
 * @param choice Sorting algorithm to use.
 * @param array The original array to sort.
 * @param size Number of elements in the array.
 */
void run_menu(MenuChoice choice, int *array, int size) {
    int *temp_array = (int*) malloc(size * sizeof(int));
    if (temp_array == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < size; i++)
        temp_array[i] = array[i];

    clock_t start, end;

    switch (choice) {
        case SELECTION_SORT:
            start = clock();
            selection_sort(temp_array, size);
            end = clock();
            break;
        case INSERTION_SORT:
            start = clock();
            insertion_sort(temp_array, size);
            end = clock();
            break;
        case BUBBLE_SORT:
            start = clock();
            bubble_sort(temp_array, size);
            end = clock();
            break;
        case MERGE_SORT:
            start = clock();
            merge_sort(temp_array, 0, size - 1);
            end = clock();
            break;
        case QUICK_SORT:
            start = clock();
            quick_sort(temp_array, 0, size - 1);
            end = clock();
            break;
        case HEAP_SORT:
            start = clock();
            heap_sort(temp_array, size);
            end = clock();
            break;
        case EXIT_PROGRAM:
            printf("Exiting the program...\n");
            free(temp_array);
            return;
        default:
            printf("Invalid choice!\n");
            free(temp_array);
            return;
    }

    printf("Sorted array:\n");
    display_array(temp_array, size);

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", cpu_time_used);

    free(temp_array);
}

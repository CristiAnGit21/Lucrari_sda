//
// Created by Cristian on 22.03.2025.
//
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "struct.h"
int insert_name(Person **array, int *count);

void display_person(Person *person);

int display_persons(Person *array, int count);

int search_name(const Person *array, int count);

int sort_by_name(Person *array, int count);

int insert_at_end(Person **array, int *count);

int insert_at_start(Person **array, int *count);

int get_insert_position(int count);

int resize_array(Person **array, int new_size);

void shift_elements(Person *array, int count, int pos);

int insert_at_position(Person **array, int *count);

int get_delete_position(int count);

void shift_elements_left(Person *array, int count, int pos);

int delete_at_position(Person **array, int *count);

int free_array(Person **array, int *count);

void print_menu(void);

void run_menu ();


#endif //FUNCTIONS_H

//
// Created by Cristian on 02.04.2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"

IPhone* create_phone();

int print_list(LinkedList *list);

void insert_beginning(LinkedList *list, IPhone *new_phone);

void insert_end(LinkedList *list, IPhone *new_phone);

void swap_models(IPhone *model_1, IPhone *model_2)

int sort_model(LinkedList *list);

void free_list(LinkedList *list);

int search_name(LinkedList *list, char searched_name[]);

int insert_position(LinkedList *list, IPhone *new_phone, int position);

int delete_position(LinkedList *list, int position);

void inverse_list(LinkedList *list);

void erase_list(LinkedList *list);

void run_menu();

#endif // FUNCTIONS_H

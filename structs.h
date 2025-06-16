//
// Created by Cristian on 02.04.2025.
//
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct IPhone {
    int Id;
    char *model;
    int year;

} IPhone;

typedef struct Node {
    IPhone *iPhone;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

typedef enum {
    EXIT =0,
    READ_PHONE =1,
    DISPLAY_LIST=2,
    SEARCH_PHONE=3,
    FREE_MEMORY=4,
    SORT_LIST=5,
    INSERT_BEGINNING=6,
    INSERT_END=7,
    INSERT_POSITION=8,
    DELETE_POSITION=9,
    INVERSE_LIST=10,
    ERASE_LIST=11
} MenuOption;

#endif // STRUCTS_H

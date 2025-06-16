//
// Created by Cristian on 03.05.2025.
//
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct book {
    char *title;
    char *author;
    int year;
    int pages;
} Book;

typedef struct Node {
    int key;
    struct book book_info;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinaryTree {
    Node *root;
} BinaryTree;

enum CHOICE {
    EXIT = 0,
    READ_TREE,
    PRINT_TREE,
    SEARCH_NODE,
    SVD,
    VSD,
    SDV,
    BSF,
    DSF,
    TREE_BALANCE,
    TREE_MIRROR,
    CLEAN_TREE,
    FREE_MEMORY
};

#endif //STRUCTS_H

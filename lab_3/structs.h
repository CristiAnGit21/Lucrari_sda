//
// Created by Cristian on 29.04.2025.
//
#ifndef STRUCTS_H
#define STRUCTS_H
/**
 * @struct Node
 * @brief Represents a node in a binary tree.
 *
 * Each node contains an integer key and pointers to its
 * left and right child nodes.
 */
typedef struct Node {
    int key;               /**< The value stored in the node. */
    struct Node *left;     /**< Pointer to the left child node. */
    struct Node *right;    /**< Pointer to the right child node. */
} Node;

/**
 * @enum menu_choice
 * @brief Enumerates the menu options for interacting with the binary tree.
 *
 * Each value corresponds to an action the user can perform
 * via the console-based menu system.
 */
enum menu_choice {
    EXIT,                   /**< Exit the program. */
    READ_TREE,              /**< Insert nodes into the tree. */
    DISPLAY_TREE,           /**< Display the tree using pre-order traversal. */
    CALCULATE_DEPTH_TREE,   /**< Calculate the depth (height) of the tree. */
    SEARCH_NODE,            /**< Search for a node with a specific key. */
    CALCULATE_DEPTH_NODE,   /**< Calculate the depth of a specific node. */
    CALCULATE_HEIGHT_NODE,  /**< Calculate the height of a specific node. */
    DISPLAY_LEAF,           /**< Display all leaf nodes in the tree. */
    CLEAN_TREE,             /**< Delete the entire tree. */
    FREE_MEMORY             /**< Free memory used by the tree. */
};

#ifndef STRUCTS_H
#define STRUCTS_H

#endif //STRUCTS_H
#endif // STRUCTS_H

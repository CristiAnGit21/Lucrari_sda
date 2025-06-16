//
// Created by Cristian on 29.04.2025.
//
#include "structs.h"

/**
 * @brief Creates a new tree node.
 *
 * Dynamically allocates memory for a new node, sets its key value,
 * and initializes left and right child pointers to NULL.
 *
 * @param key The integer value to store in the node.
 * @return A pointer to the newly created node.
 */
Node* create_node(int key);

/**
 * @brief Inserts a node into a binary search tree (BST).
 *
 * Places the node in the correct position according to BST rules:
 * smaller values go to the left, larger to the right.
 *
 * @param root The root of the tree.
 * @param key The value to insert.
 * @return The root of the updated tree.
 */
Node* insert_node_in_tree(Node* root, int key);

/**
 * @brief Performs a pre-order traversal of the tree.
 *
 * Visits and prints the nodes in the order: root → left → right.
 *
 * @param root The root of the tree or subtree.
 */
void pre_order_traversal(const Node* root);

/**
 * @brief Calculates the maximum depth (height) of the tree.
 *
 * The depth is the number of levels from root to the deepest leaf.
 *
 * @param root The root of the tree.
 * @return The depth (height) of the tree.
 */
int tree_depth(const Node* root);

/**
 * @brief Searches for a node with a given key in the tree.
 *
 * Performs binary search in a BST to find the node.
 *
 * @param root The root of the tree.
 * @param key The value to search for.
 * @return A pointer to the node if found, or NULL if not found.
 */
Node* search(Node* root, int key);

/**
 * @brief Calculates the depth (level) of a node with a specific key.
 *
 * The depth is computed recursively, starting from level 0.
 *
 * @param root The root of the tree.
 * @param key The key of the node to find.
 * @param depth The current depth (should be 0 at the initial call).
 * @return The depth of the node, or -1 if the node is not found.
 */
int node_depth(const Node* root, int key, int depth);

/**
 * @brief Gets the height of a node with the given key.
 *
 * Searches for the node and calculates the height of its subtree.
 *
 * @param root The root of the tree.
 * @param key The key of the node.
 * @return The height of the node, or -1 if the node is not found.
 */
int get_node_height(Node* root, int key);

/**
 * @brief Prints all leaf nodes in the tree.
 *
 * Leaf nodes are those without any children.
 *
 * @param root The root of the tree.
 */
void print_leaves(const Node* root);

/**
 * @brief Deletes the entire tree and frees memory.
 *
 * Recursively deallocates all nodes in the tree.
 *
 * @param root The root of the tree.
 */
void delete_tree(Node* root);

/**
 * @brief Prints the main menu to the console.
 *
 * Displays available options for the user.
 */
void print_menu();

/**
 * @brief Runs the menu loop and handles user interaction.
 *
 * Waits for user input and calls corresponding tree operations.
 */
void run_menu();

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#endif //FUNCTIONS_H

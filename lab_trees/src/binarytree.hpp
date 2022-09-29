/**
 * @file binarytree.hpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subroot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subroot) const
{
    // Base case
    if (subroot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subroot->left), height(subroot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subroot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subroot) const
{
    // Base case - null node
    if (subroot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subroot->left);

    // Print this node
    std::cout << subroot->elem << ' ';

    // Print right subtree
    printLeftToRight(subroot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
swich(root);
}
 template <typename T>
 void BinaryTree<T>::swich(Node* a) {
    if (a==NULL) {
        return;
    }
    swich (a->left);
    swich (a->right);
    Node * ptr1 = a->left;
    a->left = a->right;
    a-> right = ptr1;
    return;
 }

/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    
    bool isordered = true;
    if (!root) {
        return isordered;
    }
    InorderTraversal<T> traversal(root);
    int prev_val = (*traversal.begin())->elem;
    for (TreeTraversal<int>::Iterator it = traversal.begin(); it != traversal.end(); ++it) {
        if (prev_val < (*it)->elem) {
            prev_val = (*it)->elem;
            isordered = true;
        } else if (prev_val > (*it)->elem) {
            isordered = false;
            break;
        }
    }
    return isordered;
          
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
  bool isordered = true;
    if (!root) {
        return isordered;
    }
    InorderTraversal<T> traversal(root);
    int prev_val = (*traversal.begin())->elem;
    for (TreeTraversal<int>::Iterator it = traversal.begin(); it != traversal.end(); ++it) {
        if (prev_val < (*it)->elem) {
            prev_val = (*it)->elem;
            isordered = true;
        } else if (prev_val > (*it)->elem) {
            isordered = false;
            break;
        }
    }
    return isordered;

}


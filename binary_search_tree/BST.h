// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 7: Binary Search Tree
// last modified: 4/16/17
// BST.h
// Binary Search Tree interface file
// working/tested

#ifndef __BST_H
#define __BST_H

#include "TreeNode.h"

// Binary search tree (BST) class implements standard BST functions 
// with O(h) worst-case time; where h is the height of the tree.
// Some public functions (Min, Max, Predecessor, and Successor) 
// allocate an integer with "new", and therefore must be de-allocated
// by the user. This implementation is built for data sets with 
// distinct integer keys only.
class BST {

 public:
  BST();
  ~BST();
  // Search returns true node with matching key is found 
  // in the BST, false if not.
  bool Search(int key);
  // Inserts node with key into BST
  void Insert(int key);
  // If node with key is present in BST, Delete(int) deletes 
  // the node and returns true; if node with key is not present,
  // returns false.
  bool Delete(int key);
  // Returns pointer to newly allocated integer containing the 
  // minimum key found in the BST. Returns null for empty tree.
  int* Min();
  // Returns pointer to newly allocated integer containing the 
  // maximum key found in the BST. Returns null for empty tree.
  int* Max();
  // Returns pointer to newly allocated integer containing the 
  // predecessor of key. Returns null if predecessor doesn't
  // exist, and for empty tree.
  int* Predecessor(int key);
  // Returns pointer to newly allocated integer containing the 
  // successor of key. Returns null if predecessor doesn't
  // exist, and for empty tree.
  int* Successor(int key);
  // Prints keys contained in BST via inorder traversal
  void InorderTraversal();
  // Prints keys contained in BST via preorder traversal
  void PreorderTraversal();
  // Prints keys contained in BST via postorder traversal
  void PostorderTraversal();

 private:
  // Searches for element with key in sub-tree rooted at node x.
  // For most applications this function is called with x == root.
  // Returns pointer to node found; null if node is not found.
  TreeNode* Search(TreeNode* x, int key);
  // Inserts node into BST while maintaining the BST property.
  void Insert(TreeNode* x);
  // Deletes node while maintaining the BST property.
  void Delete(TreeNode* x);
  // Returns node that contains minimum key in the BST; null for 
  // empty tree.
  TreeNode* Min(TreeNode* x);
  // Returns node that contains maximum key in the BST; null for 
  // empty tree.
  TreeNode* Max(TreeNode* x); 
  // Returns predecessor of node x; null if no predecessor exists,
  // or empty tree. 
  TreeNode* Predecessor(TreeNode* x);
  // Returns successor of node x; null if no successor exists,
  // or empty tree. 
  TreeNode* Successor(TreeNode* x);
  // Prints key values of sub-tree rooted at x via inorder traversal
  void InorderTraversal(TreeNode* x);
  // Prints key values of sub-tree rooted at x via preorder traversal
  void PreorderTraversal(TreeNode* x);
  // Prints key values of sub-tree rooted at x via postorder traversal
  void PostorderTraversal(TreeNode* x);
  // Deletes all nodes of sub-tree rooted at x via postorder traversal
  void clearTree(TreeNode* x);
  TreeNode* root;
};

#endif

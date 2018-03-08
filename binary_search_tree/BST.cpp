// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 7: Binary Search Tree
// last modified: 4/16/17
// BST.cpp
// Binary Search Tree implementation file
// working/tested

#include <iostream>
#include "TreeNode.h"
#include "BST.h"

using std::cout;
using std::endl;

BST::BST() : root(0) { ; }

BST::~BST() { 
  clearTree(root);
}

bool BST::Search(int key) {
  TreeNode* found = Search(root, key);
  if (found == 0) return false;
  return true;
}

void BST::Insert(int key) {
  TreeNode* x = new TreeNode;
  x->key = key;
  Insert(x);
}

bool BST::Delete(int key) {
  TreeNode* found = Search(root, key);
  if (found == 0) return false;
  Delete(found);
  return true;
}

int* BST::Min() { 
  TreeNode* minNode = Min(root);
  if (minNode == 0) return 0; // return null pointer if tree is empty
  return new int(minNode->key);
}


int* BST::Max() {
  TreeNode* maxNode = Max(root);
  if (maxNode == 0) return 0; // return null pointer if tree is empty
  return new int(maxNode->key);
}

int* BST::Predecessor(int key) {
  TreeNode* temp = Search(root, key); 
  if (temp == 0) return 0;  // return null if key not found
  temp = Predecessor(temp);
  if (temp == 0) return 0; // return null if predecessor doesn't exist  
  return new int(temp->key); 
}

int* BST::Successor(int key) {
  TreeNode* temp = Search(root, key); 
  if (temp == 0) return 0;  // return null if key not found
  temp = Successor(temp);
  if (temp == 0) return 0; // return null if successor doesn't exist  
  return new int(temp->key); 
}

void BST::InorderTraversal() {InorderTraversal(root); cout << endl;}

void BST::PreorderTraversal() {PreorderTraversal(root); cout << endl;}

void BST::PostorderTraversal() {PostorderTraversal(root); cout << endl;}

TreeNode* BST::Search(TreeNode* x, int key) {
  if (x == 0 || x->key == key)
    return x;
  if (key < x->key)
    return Search(x->left, key);
  else
    return Search(x->right, key);
}

void BST::Insert(TreeNode* x) {
  TreeNode *prev, *temp;
  prev = 0; temp = root;
  while (temp != 0) {
    prev = temp;
    if (x->key < temp->key) {
      temp = temp->left;
    }
    else
      temp = temp->right;
  }
  x->parent = prev;
  if (prev == 0) {root = x; return;}
  if (x->key < prev->key)
    prev->left = x;
  else
    prev->right = x;
}

void BST::Delete(TreeNode* x) {
  TreeNode *target, *temp;
  target = temp = 0;
  if (x->left == 0 || x->right == 0) // if x has 0 or one child
    target = x;                      // node x will be deleted
  else                   // x has 2 children
    target = Successor(x); // x's successor node is deleted after swapping key
  if (target->left != 0) // temp is null or
    temp = target->left; // points to the one child
  else
    temp = target->right;
  if (temp != 0)         
    temp->parent = target->parent;
  if (target->parent == 0)
    root = temp;
  else {
    if (target == target->parent->left)
      target->parent->left = temp;
    else
      target->parent->right = temp;
  }
  if (target != x) 
    x->key = target->key;
  delete target;
}

TreeNode* BST::Min(TreeNode* x) {
  if (x == 0) return 0;
  while (x->left != 0)
    x = x->left;
  return x;
}

TreeNode* BST::Max(TreeNode* x) {
  if (x == 0) return 0;
  while (x->right != 0)
    x = x->right;
  return x;
}

TreeNode* BST::Predecessor(TreeNode* x) {
  //precondition: x != NULL
  if (x->left != 0)
    return Max(x->left);
  TreeNode* temp = x->parent;
  while (temp !=0 && x == temp->left) {
    x = temp;
    temp = temp->parent;
  }
  return temp;
}

TreeNode* BST::Successor(TreeNode* x) {
  //precondition: x != NULL
  if (x->right != 0)
    return Min(x->right);
  TreeNode* temp = x->parent;
  while (temp != 0 && x == temp->right) {
    x = temp;
    temp = temp->parent;
  }
  return temp;
}

void BST::InorderTraversal(TreeNode* x) {
  if (x == 0) return; // if tree is empty, return
  InorderTraversal(x->left);
  cout << x->key << ' ';
  InorderTraversal(x->right);
}

void BST::PreorderTraversal(TreeNode* x) {
  if (x == 0) return; // if tree is empty, return
  cout << x->key << ' ';
  PreorderTraversal(x->left);
  PreorderTraversal(x->right);
}

void BST::PostorderTraversal(TreeNode* x) {
  if (x == 0) return; // if tree is empty, return
  PostorderTraversal(x->left);
  PostorderTraversal(x->right);
  cout << x->key << ' ';
}

void BST::clearTree(TreeNode* x) {
  if (x==0) return; // if tree is empty, return
  clearTree(x->left);
  clearTree(x->right);
  delete x;
}

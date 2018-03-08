// Jon Hays
// mightyfancy@gmail.com
// jhays
// assignment 7: Binary Search Tree
// last modified: 4/16/17
// TreeNode.h
// TreeNode interface/implementation file (complete class)
// working/tested

#ifndef __TREENODE_H
#define __TREENODE_H

// TreeNode class — each TreeNode contains an integer data 
// variable (key) and "links" (pointers) to the nodes
// parent, right child, and left child. 
class TreeNode {
  friend class BST;
 public:
  TreeNode() {left = right = parent = 0; key = 0;}
 private:
  int key;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
};


#endif

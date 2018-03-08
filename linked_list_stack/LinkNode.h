// Jon Hays
// jhays
// mightyfancy@gmail.com
// LinkNode.h
// assignment 1 (Linked List)
// LinkNode class interface/implementation file (complete class)
// working/tested

#ifndef LINKNODE_H
#define LINKNODE_H

// Adapted from MonsterNode.h by Jon Hays (CS-19)
class LinkNode {
  friend class List;
 public:
  // Default constructor initializes node to null
  LinkNode() {next = 0; data = "";}
  
 private:
  LinkNode* next;
  std::string data;
  
};


#endif

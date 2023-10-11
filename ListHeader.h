#include <iostream>
#include <string>
using namespace std;

class LinkedList {
private:

  typedef struct node{
    string item;
    node* next;
  } *nodePtr;

  nodePtr head;
  nodePtr tail;
  int num_items;


public:
  LinkedList();
  void push_front(string s);
  void push_back(string s);
  void pop_front();
  void pop_back();
  node front(){return *head;};
  node back(){return *tail;};
  bool empty();
  void insert(int index, const string& item);
  bool remove(int index);
  int find(const string item);
};
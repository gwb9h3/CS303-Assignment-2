#include "ListHeader.h";
using namespace std;

LinkedList::LinkedList(){ // This is the constructor for the list
  head = NULL;
  tail = NULL;
  num_items = 0;
}
void LinkedList::push_front(string s){ // This function pushes a new node to the front
  node* tempNode = new node;
  tempNode ->  item = s;
  tempNode -> next = head;
  head = tempNode;
  num_items ++;
}

void LinkedList::push_back(string s){ // This function pushes a new node to the back
  node* tempNode = new node;
  tempNode ->  item = s;
  tempNode -> next = NULL;
  if(tail == NULL){
    head = tempNode;
    tail = tempNode;
  }
  else{
    tail -> next = tempNode;
    tail = tempNode;
  }
  num_items ++;
}

void LinkedList::pop_front(){ // This function removes the first node in the list
  node* tempNode = new node;
  if (head == NULL){
    return;
  }
  else if(head -> next == NULL){ 
    tempNode -> next = head;
    head = NULL;
    delete tempNode;
    num_items --;
  }
  else{
    tempNode -> next = head;
    head = head -> next;
    delete tempNode;
    num_items --;
  }
}

void LinkedList::pop_back(){ // This function removes the last node in the list
  if (tail == NULL){
    return;
  }
  else if(head -> next == NULL){
    delete head;
    head = NULL;
    tail = NULL;
    num_items --;
  }
  else{
    node* tempNode = new node;
    tempNode -> next = head;
    while(tempNode -> next != tail){
      tempNode = tempNode -> next;
    }
    delete tail;
    tail = tempNode;
    tail -> next = NULL;
    num_items --;
  }
}

bool LinkedList::empty(){
  if (head == NULL){
    return true;
  }
  else{
    return false;
  }
}

void LinkedList::insert(int index, const string &item){ // This function inserts a new node at a given index
  if (index < 0){
    return;
  }
  else if (index == 0){
    push_front(item);
  }
  else if(head == NULL){
    return;
  }
  else{
    node* tempNode = new node;
    tempNode -> item = item;
    node* position = head;
    int i = 0;
    while(position != nullptr && i <= index - 1){
      position = position -> next; 
      i++;
    }
    if (position == NULL){
      push_back(item);
      return;
    }
    else{
      tempNode -> next = position -> next;
      position -> next = tempNode;
      num_items ++;
    }
  }
}

bool LinkedList::remove(int index){ // This function removes a node at a given index
  if (index < 0){
    return false;
  }
  if (index == 0){
    pop_front();
    return true;
  }
  int i = 0;
  node* position = head;
  while(position != NULL && i <= index -1){
    position = position -> next;
    i++;
  }
  if(position == NULL || position -> next == NULL){
    return false;
  }
  node*tempNode = position -> next;
  position -> next = position -> next -> next;
  delete tempNode;
  num_items --;
  return true;
}

int LinkedList::find(const string item){ // This function finds the index of a given item in the list
  node* position = head;
  int i = 0;
  while(position != NULL){
    if(position -> item == item){
      return i;
    }
  }
  return i;
}
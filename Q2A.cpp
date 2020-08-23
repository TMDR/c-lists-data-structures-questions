//Ravneet Kaur
//CS276
//Assignment 1
//Question 2 a



#include<iostream> //predefined library
#include<conio.h>
using namespace std;

struct Node //create a node so that the list can be created
{
 int data;
 Node* link;
};
Node* front = NULL;
Node* rear = NULL;

bool contains(Node* a){//return true if the queue contains a node a
  if (a==NULL) {//return false if empty
    return false;
  }
  Node* temp = front;
  while (temp!=rear) {//iterate over all nodes in queue but rear
    if (temp == a) {//if a temp (some node other than rear) is a then return true the queue contains it!!
      return true;
    }
    temp=temp->linkA;
  }
  if (temp == a) {//we denied rear in the last iteration so here we are checking it!!!!!
    return true;
  }//if we came here so we never found it we are returning false!!
  return false;
}

void swapAdjacent(Node* a,Node* b){//depending on b is next to a in the queue
  if (a->link!=b) {//if b is not next to a so we won't do anything
    return;
  }
  if (contains(a) && contains(b)) {//if a and b are in that queue continue
    Node* beforeA=front;
    Node* afterB=rear;
    if (b == rear) {//if b is the last one we can't use b->link because it belongs  to null it will ruin the function
      while (beforeA->link != a) {//getting before A
        beforeA = beforeA->linkA;
      }
      beforeA->link = b;//before a was having a next to it then set it to b
      b->link=a;//b have a next to it then
      a->link=NULL;// and a becomes the last one so null is next to it
      rear = a;//rear is the last one so it is a (it was b)
      return;
    }
    while (afterB->linkB != b) {//if b is not the last one go get after b it is not nulll
      afterB = afterB->linkB;
    }
    if (a == front) {//if a is the first node then
      a->link=b->link->link;//what was after b (you can set after b rather than b->link->link) now is after a
      b->link=a;//the next of b is a
      front = b;//b is the new front
      return;
    }
    while (beforeA->linkA != a) {
      beforeA = beforeA->linkA;
    }
    beforeA->link=b;//before a was before a >_< now it is before b
    b->link=a;//next to b was a random node wich is after b now a is next to a
    a->link=afterB;//after a  is what was after b
  }
}

//Ravneet Kaur
//CS276
//Assignment 1
//Question 2 b



#include<iostream> //predefined library
#include<conio.h>
using namespace std;

struct Node //create a node so that the list can be created
{
 int data;
 Node* linkA;//link after
 Node* linkB;//link before
};
Node* front = NULL;
Node* rear = NULL;

bool contains(Node* a){//same as Q2 A
  if (a==NULL) {
    return false;
  }
  Node* temp = front;
  while (temp!=rear) {
    if (temp == a) {
      return true;
    }
    temp=temp->linkA;
  }
  if (temp == a) {
    return true;
  }
  return false;
}

void swapAdjacent(Node* a,Node* b){//same cases than Q2 B
  if (a->link!=b) {
    return;
  }
  if (contains(a) && contains(b)) {
    Node* beforeA=front;
    Node* afterB=rear;
    if (b == rear) {
      while (beforeA->linkA != a) {
        beforeA = beforeA->linkA;
      }
      beforeA->linkA = b;//a was linked to a previous node named before A  so if i am gonna change a to b beforeA is linked to b amd b is linked back to beforeA
      b->linkA=a;//b is linked to a
      b->linkB = beforeA;//see the two steps before
      a->linkA=NULL;//a is the last one so it is linked to NULL
      a->linkB=b;//b becomes before a so a is linked back to b
      rear = a;
      return;
    }
    while (afterB->linkB != b) {
      afterB = afterB->linkB;
    }
    if (a == front) {
      front=b;//b becomes in the place of a so it becomes the front
      a->linkA=b->linkA;//what was after b is now after b and a
      a->linkB=b;//b is is before a but still that was after a still the same as after b
      b->linkA=a;//after b becomes a
      b->linkB=NULL;//before b we find nothing so linkB is NULL
      return;
    }
    while (beforeA->linkA != a) {
      beforeA = beforeA->linkA;
    }
    beforeA->linkA = b;//what was after before A now is b it was a of course
    b->linkB = beforeA;//before b is what was before a
    b->linkA = a;//after b was afterB now is a
    a->linkB = b;//before a was beforeA is now b
    a->linkA = afterB;//after a was afterA now is what was after B
    afterB->linkB = a;//previous to after b was b now is a
  }
}

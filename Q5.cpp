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

bool contains(Node* a){//same as always
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

void swapAdjacent(Node* a,Node* b){//same as Q2B
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
      beforeA->linkA = b;
      b->linkA=a;
      b->linkB = beforeA;
      a->linkA=NULL;
      a->linkB=b;
      return;
    }
    while (afterB->linkB != b) {
      afterB = afterB->linkB;
    }
    if (a == front) {
      front=b;
      a->linkA=b->linkA;
      a->linkB=b;
      b->linkA=a;
      b->linkB=NULL;
      return;
    }
    while (beforeA->linkA != a) {
      beforeA = beforeA->linkA;
    }
    beforeA->linkA = b;
    b->linkB = beforeA;
    b->linkA = a;
    a->linkB = b;
    a->linkA = afterB;
    afterB->linkB = a;
  }
}

void reverse(){//here we can reverse the list
  Node* TheRear=rear;//save the rear pointer because it is gonna be front
  Node* finishSwap=NULL;
  Node* temp;
  Node* Front = front;//save front pointer because it is going to be rear
  while (front != TheRear) {//iterate until the old rear pointer becomes the Front
    temp = Front;//take the front pointer in the temp
    Front = Front->linkA;//here we can iterate to select the begining of temp in the next iteration because when the last front will become previous to the last rear we set it to begin in it the iteration
    while (temp->linkA != finishSwap) {//first time we set the first node to the rear (when the next of it is null)
      swapAdjacent(temp, temp->linkA);//swap the Front and the next of it until it becomes to the last swapped (finishSwap)
    }
    finishSwap = temp;//set finish  swap to the last swapped
  }
}

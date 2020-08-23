//Ravneet Kaur
//CS276
//Assignment 1
//Question 4



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

int size() //to find the size of the linked list
{
 int count=0; //we initialize the count to 0
 struct Node* current=front; //Intialize current
 while(current!=NULL) //the loops continues till we reach the end of the list
  {
     count++;
     current = current-> link;
  }
  return count; //return the variable count that tells the size
}

void add(int x) //function to add an element to the list
{
Node* ptr= new Node();
ptr->data =x;
ptr->link= NULL;

if (front== NULL) //if the list is empty, x is the only element in the list
 {
 front= ptr;
 rear=ptr;
 }
else // otherwise the element is just added to the list
 {
rear->link= ptr;
rear=ptr;
 }
}

void remove(){//to remove a random element from a queue
  int  index = rand() % size();//generate a random number between 0 and the size of the queue
  Node* temp = front;
  if (index == 0) {
    Node* l = front;
    front = front->link;//if the element is the first we can't get before it
    free(l);
    return;
  }
  for (int i = 0; i < index-1; i++) {
    temp = temp->link;//temp is before the element to remove
  }
  Node* l =temp->link; 
  temp->link=temp->link->link;//we unlink the element to remove
  free(l);
}

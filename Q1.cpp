//Ravneet Kaur
//CS276
//Assignment 1
//Question 1



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

bool isempty() //function to check if the list is empty
{
if (front==NULL && rear==NULL)
return true;
else
return false;
}

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



void deleteMin() //Function to delete the minimum element from the queue
{
if( isempty() )
 cout<<"Queue is empty"; //we check if the queue is empty
else
 if(front==rear) //in case there is only one element in the list
   {
   free(front); //free the space because we do not want to use the memory
   front= rear = NULL;
   }
else
 {//heree to delete the minmum if there is more than one node
    Node* temp=front;//to iterate through nodes
     int min=front->data;//minimum is first the front data that is to compare it with otheres in case we found the minimum
     Node* minn=front;//minn is the node that precedes the one that have the min value of course so i can change the link to skip the minimum to delete it after that
  while(temp->link!= NULL)//while we iterate all nodes but the last one
    {
    if (min > temp->link-> data){//if the link of the node i am stepping at is worth to be minimum replace the minimum by it that iteration goes to comparate all nodes but the hront
      // because i already have it as minimum so minn will stay front if it is the minimum
      min = temp->link-> data;
      minn=temp;
    }
    temp= temp->link;
    }
    Node* freee=minn->link;//here to free the minimum after unlinking it from the queue
    minn->link=minn->link->link;//unlinking the minimum
    free(freee);//free the minimum from the memory
  }
}

void Print() //creating a function to print the list
  {
    if (front == NULL) {
      std::cout << "it is null" << '\n';
      return;
    }
  Node* temp1= front; //create a pointer that points to the front of the list
  while(temp1!=NULL)
  {
  cout<<" "<< temp1-> data;
  temp1= temp1->link;
  }
  cout<<endl;
  }
//prints the list from the beginning

void push(int x){//same as add i made it my way
  Node* temp=front;
  if (front==NULL) {//if it is empty make the new node the front
      front = new Node();
      front->data = x;
      front->link=NULL;
      rear = front;
      return;
  }
  while (temp->link!=NULL) {//here to iterate to the rear you can just delete it you have rear defined
    temp=temp->link;
  }
  Node* result = new Node();
  result->data = x;
  result->link = NULL;
  temp->link = result;
  rear = result;
}

void pop(){//pop removes from the beginning!!
  if (front == NULL) {//if empty so return nothing to do
    return;
  }
  Node* temp = front;
  front = front->link;//unlinking front by changing it to the link of it
  free(temp);//freeing the old front from the memory
}

int main() //main function
{
  front=NULL; //Empty list
  int num;
  int v;
  char prompt;
  cout<<"Please enter the numbers that you wish to see in the list."<<endl; //making the program user friendly by prompting to enter the numbers of user's choice
  cin>>num;
  add(num);
  bool boo=true;
  for (int i = 0; i < 10; i++) {
    Print();
    std::cout << "here is pushing " << i << '\n';
    push(i);
  }
  while(boo)
  {
    std::cout << "continue? y : n" << '\n';
    cin >> prompt;
    if (prompt=='y') {
      std::cin>>num;
      add(num);
    }
    else if (prompt == 'n'){
      boo=false;
    }
  }
  char c;
  cout<<"Enter x to remove an element and y for adding an element"<<endl; //Prompt the user to enter two character to remove or add elements to the list
  cin>>c;
  if(c=='x') //if the user enters x, we implement deleteMin function
  {
    deleteMin();
    Print();
  }
  else if(c=='y') //if the user enters y, we implement the add function
     {
        cout<<"Please enter the number that you want to add:"<<endl; //Prompt the user to enter the number they wish to add
        std::cin>>v;
        add(v);
        Print();
      }
   else //in case the user enters a character other than x or y
     {
       cout<<"Invalid entry"<<endl;
     }
     for (int i = 0; i < 10; i++) {
       Print();
       std::cout << "here is pop!!! " << '\n';
       pop();
     }
  return 0;
}

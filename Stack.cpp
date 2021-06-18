#include<iostream>
#include"Stack.h"
using namespace std;

  //pushes element on to the stack
bool Stack::push(int item)
   {
      if (top >= (MAX-1)) {
      cout << "Stack Overflow!!!";
      return false;
   }
else {
   myStack[++top] = item;
   cout<<item<<endl;
   return true;
   }
}
 
//removes or pops elements out of the stack
int Stack::pop()
{
   if (top < 0) {
      cout << "Stack Underflow!!";
      return 0;
   }
else {
       int item = myStack[top--];
      return item;
   }
}
 
//check if stack is empty
bool Stack::isEmpty()
{
   return (top < 0);
}


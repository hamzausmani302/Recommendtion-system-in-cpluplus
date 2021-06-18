class Stack
{
   int top;
   int MAX;
   public:
   int *myStack; //stack array
 
   Stack() { top = -1; MAX=100; myStack = new int[MAX] ;  }
   bool push(int x);
   int pop();
   bool isEmpty();
};
 
 

#include<iostream>
#include<stdlib.h>
using namespace std;


class SNode{
	public:
	int value;
	SNode *next;
	SNode(){
		next = NULL;
	}
	SNode(int el){
		next= NULL;
		value = el;	
	}
};


class STACK{
	SNode *front ,*rear;	
	public:
		STACK(){
			front = rear = NULL;
		}
		
		void push(int el){
			SNode *newnode = new SNode(el);
			if(front == NULL && rear == NULL){
				front =rear = newnode;
				return ;
			}
			rear->next = newnode;
			rear = newnode;
			
		}
		SNode *getprev(SNode *node){
			SNode *ptr = front;
			while(ptr->next != node){
				ptr= ptr->next;
			}
			return ptr;
		}
		SNode* pop(){
			if(front==NULL && rear == NULL){
				return NULL;	
			}
			if(front == rear){
				SNode *temp = front;
				front = NULL;
				rear = NULL;
				return temp;
			}
			SNode *prev = this->getprev(rear);	
			rear = prev;
			rear->next= NULL;			
		}
		void display(){
			SNode *ptr = front;
			while(ptr != NULL){
				cout << ptr->value<< " ";
				ptr= ptr->next;
			}
			cout << endl;
		}
};








template<class T>
class Node{         //node class for linked list
    public:
    T data;
    Node<T>* next;
};
template<class T>
class Queue{
	Node<T>* head;
	Node<T>* tail;
	int rear;	
	public:
		Queue()
		{
			head = NULL;
			tail = NULL;
			rear = 0;
		}
		
		void display(){
			Node<T> *ptr = head;
			while(ptr != NULL){
				
				cout << "					ITEM NAME					" << "				PRICE					" <<endl;
				cout << ptr->data.getName() ;
				for(int i = 30 - ptr->data.getName().length() ; i>= 0 ;i--){
					cout <<" ";
				}
				ptr = ptr->next;
			}
		}
		
		void enque(T el)
		{
			Node<T>* temp = head;
			Node<T>* newnode = new Node<T>();
			newnode->next = NULL;
			newnode->data = el;
			
			if(head == NULL && tail == NULL)
			{
		
				head = newnode;
				tail = newnode;
				rear++;
			}
			else{
				
				tail->next = newnode;
				tail = newnode;
				rear++;
			}
						
		}
		
		void deque()
		{
			if(empty())
			{
				cout << "queue is empty" << endl;
				return ;
			}
			else{
				
				Node<T>* temp = head;
				head = head->next;
				Node<T>* el = temp;
				temp->next = NULL;
				free(temp);
				rear--;
				
			}
			
		}
		int size()
		{
			return rear;
		}
		T front()
		{
			if(!empty()){
				return head->data;
				
			}
		}
		int empty()
		{
			if(size() == 0)
			{
				return 1;
			}
			else{
				return 0;
			}
		}	
};

int main()
{
	Queue<int> q;
	q.enque(1);
	q.enque(5);
	q.enque(6);
	q.enque(7);
	cout << q.front()<<endl;
	cout << q.size()<<endl;
 q.deque() ;
 q.deque() ;
 cout << q.front();
q.deque();
// q.deque();
	cout << q.size();
	cout << q.front();
	q.deque();
//	cout << q.size();
	
		q.front();
	cout << q.front();
}

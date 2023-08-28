//STACK : LIFO
// //  STACK USING ARRAY 
// class Stack{
// 	int size;
// 	int top;
// 	int *s;

// public:
// 	void push(int element);//time complexity is O(1)
// 	void pop();//time complexity is O(1)

// };
// //  STACK USING LINKED LIST 
// class Node{
// 	int data;
// 	Node *next;
// };
// class Stack{
// 	Node *top;
// 	int size

// public:
// 	void push(int element);
// 	void pop();
// 	int top();
// 	int size();
// 	bool empty;
// };

// //QUEUES : FIFO
// class Queue{
// 	int size;
// 	int front;
// 	int back;
// 	int *q;

// public:
// 	void enqueue(int element);
// 	int  dequeue();//all of them are O(1) operations
// 	int front();
// 	int back();
// 	int size();
// 	bool empty();

// };
// class Node{
// 	int data;
// 	Node *next;
// };
// class Queue{ 
// 	Node *front;
// 	Node *back;
// 	int size;

// public:
// 	void enqueue(int element);
// 	int  dequeue();
// 	int front();
// 	int back();
// 	int size();
// 	bool empty();
// }

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
	stack<int> s;
	// stack<char> s1;
	// stack<vector<int>> v;
	stack<int> s1;
	queue<int> q;
	q.push(3);
	q.pop();
	q.size();
	q.empty();
	q.front();
	q.back();

}

//infix, postfix and prefix expressions
//implementing a text editor using two stack model
//deque(double ended queues)
//Priority queues










#include <iostream>
#include <string>
#include <stdio.h>

#define SIZE 100

using namespace std;

class StackPointer{
	private :
		class Node{
			public :
				char data;
				Node *link;
				
			Node(int data){
				this->data = data;
				link = NULL;
			}
		};
		
		Node *top;
		int count;
	
	public :
		StackPointer();
		~StackPointer();
		void push(char value);
		char pop();		
		int size();
		bool isEmpty();
		bool isOperator(char a);
		int priority(char a);	
		bool precedence(char a, char b);
		string infixToPostfix();	
};

StackPointer::StackPointer(){
	top = NULL;
	count = 0;
}

StackPointer::~StackPointer(){
	for(Node *temp=top; temp!=NULL; top=top->link){
		delete temp;
		temp = NULL;
	}
	top = NULL;
}

void StackPointer::push(char value){
	Node *n = new Node(value);
		if(isEmpty()){
			top = n;
		}
		else{
			n->link = top;
			top = n;
		}
	count++;
}

char StackPointer::pop(){
	Node *temp;
	char x;
	x = top->data;
		if(isEmpty()){
			top = NULL;
		}
		else
		{
			temp = top;
			top = top->link;
			count--;
			delete temp;
		}
	return x;
}

int StackPointer::size(){
	return count;
}

bool StackPointer::isEmpty(){
	if(count == 0){
		return true;
	}
	return false;
}

// Verify whether is symbol or not. 
bool StackPointer::isOperator(char a){
	if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^' || a=='(' || a==')'){
		return true;
	}
	return false;
}

// Get weight of an operator. An operator with higher weight will have higher precedence.
int StackPointer::priority(char a){
	int temp = 0;
		if(a=='(' || a==')')
			temp = 4;
		if(a=='^')
			temp = 3;
		if(a=='*' || a=='/')
			temp = 2;
		if(a=='+' || a=='-')
			temp = 1;		
	return temp;	
}

bool StackPointer::precedence(char a, char b){
	int weight1 = priority(a);
	int weight2 = priority(b);
	
	if(weight1 >= weight2){
		return true;
	}
	return false;
}

/*
	Stack is empty => PUSH(operator)
	Operator having Higher priority => PUSH(operator)
	Operator having same priority => POP(operators), PUSH(new operator)
	Operator having low priority => POP(operators), PUSH(new operator)
	No more operands => POP(operators)	
*/

string StackPointer::infixToPostfix(){
	char infix[SIZE];
	string postfix = " ";
	
	cout << "Enter an arithmetic expression in Infix : ";
	cin >> infix;
	 
	for(int i=0; i<infix[i]!='\0'; i++){ // Scanning each character from left.
		if(!isOperator(infix[i])){					
			postfix += infix[i]; // Add character to the Postfix String.
		}	
		else if(infix[i]=='('){
			push(infix[i]); // Push on Stack
		}	
		else if(infix[i]==')'){
			while(!isEmpty() && top->data != '('){
				postfix += pop(); // Add symbol to the Postfix String.
			}
			pop(); // Popping next operator.
		}
		else{ // Character is symbol.
			if(isEmpty()){
				push(infix[i]);
			}
			else if(isOperator(infix[i])){
				while(!isEmpty() && top->data != '(' && precedence(top->data, infix[i])){
					postfix += pop();
				}
			push(infix[i]);
			}
		}
	}
	for(int i=0; i<infix[i]!='\0'; i++){
		if(isEmpty()){
			break;
		}
		postfix += pop();
	}
return postfix;
}

int main(){
	StackPointer s;
	int num;
	
	do{
		cout << endl;
		cout << "========================" << endl;
		cout << " 1. Infix expression    " << endl;
		cout << " 0. Exit                " << endl;
		cout << "========================" << endl;
		cout << ">> ";
		cin >> num;
	
		if(num == 1){
			cout << "Arithmetic expression in Postfix : " << s.infixToPostfix() << endl;			
		}					
	}while(num!=0);
	
}

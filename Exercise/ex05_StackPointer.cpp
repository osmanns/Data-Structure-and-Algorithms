#include <iostream>

using namespace std;

class StackPointer{
	private :
		class Node{
			public :
				int data;
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
		void push(int value);
		int pop();
		void show();
		int size();
		bool isEmpty();
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

void StackPointer::push(int value){
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

int StackPointer::pop(){
	if(isEmpty()){
		cout << "\nThe list is empty.\n" << endl;	
	}
	else{
		cout << "\nPop ! ! !" << endl;
		cout << top->data << endl << endl;
		count--;
		Node *temp = top;		
		top = temp->link;	
			return temp->data;
			
		delete temp;
		temp = NULL;	
	}
}

void StackPointer::show(){
	cout << "List : ";
	for(Node *temp=top; temp!=NULL; temp=temp->link){
		cout << temp->data << " ";		
		//temp=temp->link;
	}
	cout << endl;
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

int main(){
	StackPointer link;
	int num, value;
	
	do{
		cout << "===================" << endl;
		cout << " 1. Push           " << endl;
		cout << " 2. Pop      		" << endl;
		cout << " 3. Show           " << endl;
		cout << " 0. Exit           " << endl;
		cout << "===================" << endl;
		cout << ">> ";
		cin >> num;
		
		if(num==1){
			cout << "Enter value >> ";
			cin >> value;
			link.push(value); 
		}
		else if(num==2){
			link.pop(); 
		}
		else if(num==3){
			link.show();
		}
	}while(num!=0);
	
}

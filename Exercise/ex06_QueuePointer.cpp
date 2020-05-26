#include <iostream>

using namespace std;

class QueuePointer{
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
		
		int count;
		Node *font;
		Node *back;
	
	public :
		QueuePointer();
		~QueuePointer();
		void enqueue(int value);
		int dequeue();
		void show();
		bool isEmpty();
};

QueuePointer::QueuePointer(){
	count = 0;
	font = NULL;
	back = NULL;
	
}

QueuePointer::~QueuePointer(){
	for(Node *temp=font; temp!=NULL; font=font->link){
		delete temp;
		temp = NULL;
	}
	font = NULL;
	back = NULL;
}

void QueuePointer::enqueue(int value){	
	Node *n = new Node(value);	
		if(isEmpty()){
			font = n;
			back = n;
		}	
		else{
			back->link = n;
			back = n;			
		}
		count++;
}

int QueuePointer::dequeue(){
	if(isEmpty()){
		cout << "Queue is empty." << endl;
	}
	else{
		Node *temp = font;
		count--;
		font = font->link;
			return temp->data;
		
		delete temp;
		temp = NULL;
	}
}

void QueuePointer::show(){
	cout << "Queue : ";
	if(isEmpty()){
		cout << "Queue is empty." << endl;
	}
	else{
		for(Node *temp=font; temp!=NULL; temp=temp->link){
			cout << temp->data << " ";
			//temp = temp->link;
		}
	}
	cout << endl;
}

bool QueuePointer::isEmpty(){
	if(count == 0){
		return true;
	}
	return false;
}

int main(){
	int num, value;
	QueuePointer p;
	
	do{
		cout << "===================" << endl;
		cout << " 1. Enqueue        " << endl;
		cout << " 2. Dequeue      	" << endl;
		cout << " 3. Show           " << endl;
		cout << " 0. Exit           " << endl;
		cout << "===================" << endl;
		cout << ">> ";
		cin >> num;
		
		if(num==1){
			cout << "Enter value >> ";
			cin >> value;
			p.enqueue(value); 
		}
		else if(num==2){
			p.dequeue(); 
		}
		else if(num==3){
			p.show();
		}
	}while(num!=0);
}

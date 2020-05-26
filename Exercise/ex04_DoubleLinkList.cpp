#include <iostream>
#include <stdbool.h>
using namespace std;

class DbLinkedList{
	private :
		class Node{
			public :
				Node *link;
				Node *plink; //+
				int data;	
			
				Node(int data){
					this->data = data;
					link = NULL;
					plink = NULL; //+
				}
		};
		
		Node *head;
		Node *tail;
		int count;
		
	public :
		DbLinkedList();
		~DbLinkedList();	
		void add(int value);
		void add(int index, int value);
		void show();
		void show_backward(); //+
		int size();
		bool isEmpty();
		bool find(int value);
		int set(int index, int data);
		int get(int index);
		void remove(int value);
};

DbLinkedList::DbLinkedList(){
	head = NULL;
	tail = NULL;
	count = 0;
}

DbLinkedList::~DbLinkedList(){
	for(int i=1; i<this->count; i++){
		Node *tmp = this->head;
		this->head = this->head->link;
		delete tmp;
		tmp =  NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}

void DbLinkedList::add(int value){
	Node *newNode = new Node(value);
		if(isEmpty()){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->link = newNode;
			newNode->plink = tail; //+
			tail = newNode;	
		}
		count++;
}

void DbLinkedList::add(int index, int value){
	Node *newNode = new Node(value);
	
	if(isEmpty()){
		head = newNode;
		tail = newNode;
		count++;
	}
	else{
		if(index>0 && index<=size()){
			if(index == 1){
				newNode->link = head;
				head->plink = newNode; //+
				head = newNode;
			}
			else{
				Node *temp = head;
				Node *ptemp = head;
					for(int i=1; i<index; i++){
						
						if(i>1){
							temp = temp->link;
						}
						temp = temp->link;
					}
					ptemp = temp->plink; //+
					newNode->link = temp;
					temp->plink = newNode; //+
					ptemp->link = newNode;
					newNode->plink = ptemp; //+
			}
			count++;
		}
		else{
			cout << "Index out of scpoe....\n";
		}
	}
}

void DbLinkedList::show(){
	cout << "Value in LinkedList : ";
		if(isEmpty()){
			cout << "No Data ...";
		}	
		else{				
			for(Node *temp = head;temp != NULL;temp = temp->link){
				cout << temp->data << " "; 
			}
		}
		cout << endl;
}

void DbLinkedList::show_backward(){
	cout << "Backward Value in LinkedList : ";
		if(isEmpty()){
			cout << "No Data ...";
		}	
		else{				
			for(Node *temp = tail;temp != NULL;temp = temp->plink){
				cout << temp->data << " "; 
			}
		}
		cout << endl;
}

int DbLinkedList::size(){
	return count;
}

bool DbLinkedList::isEmpty(){
	if(this->size() == 0){
		return true;
	}	
	else{
		return false;
	}
}

bool DbLinkedList::find(int data){
	Node *temp=head;
		for(int i=1; i<=count; i++){
			if(temp->data == data){
				cout << data << " Found.....\n";
				return true;
				break;
			}
			temp = temp->link;
		}				
		cout << data << " Not Found.....\n";
		return false;

/*
	for(Node *tmp = head;tmp != NULL;tmp = tmp->link){
		if(tmp->data == value){
			cout << "Value " << value << " is Found ...!!" << endl;
			return true;
		}
	}
	cout << "VaLue " << value << " Not Found ...!!" << endl; 
	return false;	
*/
}

int DbLinkedList::set(int index, int data){
	if(isEmpty()){
		cout << "No Data ......\n";
	}
	else{
		if(index>0 && index<=size()){
			Node *temp = head;
				for(int i=1; i<index; i++){
					temp = temp->link;
				}
				temp->data = data;	
		}
		else{
			cout << "Out of index\n";
		}
	}
}

int DbLinkedList::get(int index){
	if(isEmpty()){
		cout << "No Data ......\n";
	}
	else{
		if(index>0 && index<=size()){
			Node *temp = head;
				for(int i=1; i<index; i++){
					temp = temp->link;
				}
				return temp->data;	
		}
	}
}

void DbLinkedList::remove(int value){
	int round = 1;
	Node *ptemp;
		
		for(Node *temp = head; temp !=NULL; temp = temp->link){
			if(round == 1){
				ptemp = temp;
				if(temp->data == value){
					if(temp == head && temp == tail){
						delete temp;
						head = NULL;
						tail = NULL;
					}
					else if(temp == head){
						head = head->link;
						head->plink = NULL; //+
						delete temp;
					}
					count--;
					break;
				}
			}
				else{
					if(temp->data == value){
						ptemp = temp->plink; //+
						if(temp == tail){
							tail = ptemp;
							tail->link = NULL;
							delete temp;
						}
						else{
							ptemp->link = temp->link;
							temp->link->plink = ptemp; //+
							delete temp;
						}
						count--;
						break;
					}
					/*
					else{
						petmp = temp;
					}
					*/
				}		
			round++;
		}
}

int main(){
	DbLinkedList x;
	
	int num;
	int value, index;
	
	do{
		cout << "===================" << endl;
		cout << " 1. Add            " << endl;
		cout << " 2. Add/Index      " << endl;
		cout << " 3. Get            " << endl;
		cout << " 4. Set            " << endl;
		cout << " 5. Remove         " << endl;
		cout << " 6. Get size       " << endl;
		cout << " 7. Find           " << endl;
		cout << " 8. Show           " << endl;
		cout << " 9. Show Backward  " << endl;
		cout << " 10. Exit          " << endl;
		cout << "===================" << endl;
		cout << " >> ";
		cin >> num;

		if(num == 1){
			cout << "Enter value >> ";
			cin >> value;
			x.add(value);
		}else if(num == 2){
			cout << "Enter index >> ";
			cin >> index;
			cout << "Enter value >> ";
			cin >> value;
			x.add(index, value);
		}else if(num == 3){
			cout << "Enter index >> ";
			cin >> index;
			cout << "Data is: " << x.get(index) << endl;
		}else if(num == 4){
			cout << "Enter index >> ";
			cin >> index;
			cout << "Enter value >> ";
			cin >> value;
			x.set(index, value);
		}else if(num == 5){
			cout << "Enter value >> ";
			cin >> value;
			x.remove(value);
		}else if(num == 6){
			cout << "Size >> " << x.size() << endl;
		}else if(num == 7){
			cout << "Enter value >> ";
			cin >> value;
			x.find(value);
		}else if(num == 8){
			x.show();
		}
		else if(num == 9){
			x.show_backward();
		}
	}while(num != 10);
}


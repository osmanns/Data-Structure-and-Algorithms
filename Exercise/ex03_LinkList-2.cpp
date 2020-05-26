#include <iostream>
#include <stdbool.h>

using namespace std;

class LinkedList{

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
		
		Node *head;
		Node *tail;
		int count;
	
	public :
		LinkedList();
		~LinkedList(void);
		void add(int value);
		void add(int index, int value);
		int get(int index); // get value at index
		int set(int index, int value); // set value in index
		void remove(int value);
		int size();
		void show();
		bool find(int data); 
		bool isEmpty();		
};

LinkedList::LinkedList(){
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

LinkedList::~LinkedList(void){
	for(int i = 1; i < this->count; i++){
		Node *tmp = this->head;
			this->head = this->head->link;
		delete tmp;
	tmp = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}
	
void LinkedList::add(int value){
	Node *New = new Node(value);
	if(this->isEmpty()){
		head = New;
		tail = New;
	}else{
		tail->link = New;
		tail = New;
	}
	count++;		
}

void LinkedList::add(int index, int value){
	Node *n = new Node(value);
	
	if(isEmpty()){
		head = n;
		tail = n;
		count++;
	}
	else{
		if(index>0 && index<=size()){
			if(index == 1){
				n->link = head;
				head = n;
			}
			else{
				Node *temp = head;
				Node *ptemp = head;
					for(int i=1; i<index; i++){			
						if(i>1){
							ptemp = temp;
						}
						temp = temp->link;
					}			
					n->link = temp;				
					ptemp->link = n;				
			}
		count++;
		}
		else{
			cout << "Index out of scpoe....\n";
		}
	}
}

int LinkedList::get(int index){
	Node *temp = head;
	if(isEmpty()){
		cout << "No Data ! ! !" << endl;
	}	
		for(int i=1; i<=count; i++){
			if(i == index){
				return temp->data;	
			}
		temp = temp->link;
		}
}
		
int LinkedList::set(int index, int value){
	Node  *temp = head;
		for(int i=1; i<=count; i++){
			if(i == index){
				temp->data = value;
			}
		temp = temp->link;
	}
}
	
void LinkedList::remove(int value){
	int round = 1;
	Node *ptmp;
		
		for(Node *tmp = head; tmp !=NULL; tmp = tmp->link){
			if(round == 1){
				ptmp = tmp;
				if(tmp->data == value){
					if(tmp == head && tmp == tail){
						delete tmp;
						head = NULL;
						tail = NULL;
					}
					else if(tmp == head){
						head = head->link;
						delete tmp;
					}
					count--;
					break;
				}
			}
			else{
				if(tmp->data == value){
					if(tmp == tail){
						tail = ptmp;
						tail->link = NULL;
						delete tmp;
					}
					else{
						ptmp->link = tmp->link;
						delete tmp;
					}
						count--;
						break;
				}
				else{
					ptmp = tmp;
				}
			}		
		round++;
		}
}

int LinkedList::size(){
	return count;
}		

void LinkedList::show(){
	cout << "Value in LinkList : ";
		if(this->isEmpty()){
			cout << "No Data ...";
		}else{
				for(Node * temp = head; temp !=NULL; temp = temp->link){
					cout << temp->data << " "; 
		}
	}
	cout << endl;
}

bool LinkedList::find(int data){
	Node *temp = head;
		for(int i=0; i<count; i++){
			if(data == temp->data){
				cout << data << " Found\n";	
				return true;
			}
			temp = temp->link;			
		}
	cout << data << " Not Found\n";
	return false;
}

bool LinkedList::isEmpty(){
	if(count == 0){
		return true;
	}else{
		return false;
	}
}

int main(){
	LinkedList x;
	int num;
	int value, index;
	
	do{
		cout << "===================" << endl;
		cout << " 1. Add            " << endl;
		cout << " 2. Add/Index      " << endl;
		cout << " 3. Get            " << endl;
		cout << " 4. Set            " << endl;
		cout << " 5. Remove         " << endl;		
		cout << " 6. Find           " << endl;
		cout << " 7. Get size       " << endl;
		cout << " 8. Show           " << endl;
		cout << " 0. Exit          " << endl;
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
			cout << "Enter value >> ";
			cin >> value;
			x.find(value);
		}else if(num == 7){
			cout << "Size >> " << x.size() << endl;
			
		}else if(num == 8){
			x.show();
		}
	}while(num != 0);
}

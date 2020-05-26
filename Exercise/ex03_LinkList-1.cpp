#include <iostream>
#include <stdbool.h>
using namespace std;

class LinkedList{
	private :
		class Node{
			public :
				Node *link;
				int data;	
			
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
		~LinkedList();
		int size();
		bool isEmpty();
		void add(int value);
		void add(int index, int value);
		void show();
		bool find(int value);
		int set(int index, int data); // get value at index
		int get(int index); // set value in index
		void remove(int value);
};

LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
	count = 0;
}

LinkedList::~LinkedList(){
	for(int i=1; i<this->count; i++){
		Node *tmp = this->head;
		this->head = this->head->link;
		delete tmp;
		tmp =  NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}

LinkedList::size(){
	return count;
}

bool LinkedList::isEmpty(){
	if(this->size() == 0){
		return true;
	}	
	else{
		return false;
	}
}

void LinkedList::add(int value){
	Node *newNode = new Node(value);
		if(isEmpty()){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->link = newNode;
			tail = newNode;	
		}
		count++;
}

void LinkedList::add(int index, int value){
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
				head = newNode;
			}
			else{
				Node *tmp = head;
				Node *ptmp = head;
					for(int i=1; i<index; i++){
						if(i>1){
							ptmp = tmp;
						}
						tmp = tmp->link;
					}
					newNode->link = tmp;
					ptmp->link = newNode;
			}
			count++;
		}
		else{
			cout << "Index out of scpoe....\n";
		}
	}
}

void LinkedList::show(){
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

bool LinkedList::find(int data){
	Node *tmp=tail;
		for(int i=1; i<count; i++){
			if(tmp->data == data){
				cout << "true" << data << "Found.....\n";
				return true;
			}
			//tmp = tmp->link;
		}				
		cout <<"false" << data << "Not Found.....\n";
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

int LinkedList::set(int index, int data){
	if(isEmpty()){
		cout << "No Data ......\n";
	}
	else{
		if(index>0 && index<=size()){
			Node *tmp = head;
				for(int i=1; i<index; i++){
					tmp = tmp->link;
				}
				tmp->data = data;	
		}
		else{
			cout << "Out of index\n";
		}
	}
}

int LinkedList::get(int index){
	if(isEmpty()){
		cout << "No Data ......\n";
	}
	else{
		if(index>0 && index<=size()){
			Node *tmp = head;
				for(int i=1; i<index; i++){
					tmp = tmp->link;
				}
				return tmp->data;	
		}
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

int main(){
	LinkedList obj_linklist;
	obj_linklist.add(5);
	obj_linklist.add(10);
	obj_linklist.add(15);
	obj_linklist.add(20);
	obj_linklist.add(25);
	obj_linklist.show();
	obj_linklist.remove(5);
	obj_linklist.remove(25);
	obj_linklist.remove(15);
	obj_linklist.show();
	obj_linklist.find(15);
	obj_linklist.find(20);
	obj_linklist.add(1,35);
	obj_linklist.add(2,65);
	obj_linklist.show();
	obj_linklist.set(2,75);
	obj_linklist.show();
	
}


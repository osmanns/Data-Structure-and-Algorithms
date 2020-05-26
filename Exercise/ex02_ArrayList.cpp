 #include <iostream>
#include <stdbool.h>
using namespace std;

class ArrayList{
	private :
		int capacity; //length of the actual array
		int count; //number  of the elements the list contains
		int *item;
		int *arry;
	public :
		//constructor
		ArrayList(int size);
		//deconstructor
		~ArrayList();
		//modifiers
		void add(int value);
		void add(int index, int value);
		int set(int index, int value);
		int remove(int index);
		//accessor
		int get(int index);		
		int indexOf(int value);
		int size();
		int max_size();
		bool isEmpty();
		bool isFull();
		void show();
		
};

ArrayList::ArrayList(int size){
	if(size <= 0){
		capacity = 100;
	}
	else
		capacity = size;
	count = 0;
	item = NULL;	
	arry = new int[size];
		for(int i=0; i<size; i++){
			size = 0;
		}
}

ArrayList::~ArrayList(){
	delete[] arry;
}

void ArrayList::add(int value){
	if(isFull()){
		cout << "The list is full." << endl;
	}
	else 
		arry[count] = value;
		count++;
}	

void ArrayList::add(int index, int value){
	//if(index < 0 || index >= capacity)
	if(isFull()){
		cout << "The list is full." << endl;
	}
	else if(index < 0 || index >= capacity){
		cout << "The position is out of range." << endl;
	}

	else{
		for(int i=capacity; i>=index; i--){
			arry[i+1] = arry[i];		
		}
		arry[index] = value;
		count++;
	}
	
}

int ArrayList::get(int index){
	if(index <= capacity)
		return arry[index];		
}

int ArrayList::set(int index, int value){
	if(index < 0 || index >= count)
		cout << "The position is out of range." << endl;
	else
		arry[index] = value;		
}

int ArrayList::remove(int index){
	if(index > count){
		cout << "No  index." << endl;
	}
	else{
		for(int i=index; i<capacity; i++){
			arry[i] = arry[i+1];
		}
		count--;
	} 
}

int ArrayList::indexOf(int value){
	for(int i=0; i<=capacity; i++){
		if(arry[i] == value){
			item = &arry[i];
				return i;
		}
	}
		return -1;
		
}

int ArrayList::size(){
	return count;		
}

int ArrayList::max_size(){
	return capacity;	
}

bool ArrayList::isEmpty(){
	if(count == 0) // if(size() == 0)
		return true;

	else
		return false;
}

bool ArrayList::isFull(){
	if(size() == max_size())
		return true;	
	else 
		return false;
}

void ArrayList::show(){
	for(int i=0; i<count; i++){
		cout << "[" << i << "]"<< arry[i] << "  ";
	}	
	cout << endl << endl;;	
}


int main(void){
	ArrayList *arry = new ArrayList(10); 
	
	arry->add(1); 
	arry->add(3);
	arry->add(5); 
	arry->add(7); 
	arry->add(9);
	arry->show();
	arry->add(3, 9);
	arry->show();
	arry->remove(0);
	arry->show();
	arry->add(5); 
	arry->add(7);
	arry->remove(3);
	arry->show();
	 
	cout << "Search 5 in index : " << arry->indexOf(5) << endl;
	cout << "Search 3 in index : " << arry->indexOf(3) << endl;
	cout << "Capacity : " << arry->max_size() 
		 << " Count : " << arry->size() << endl;
		 
	return 0;
}

#include <iostream>

using namespace std;

class StackArray{
	private :
		int *arr_stack;
		int max;
		int top;
	
	public :
		StackArray(int size);
		~StackArray();
		void push(int value);
		int pop();
		void show();
		bool isFull();
		bool isEmpty();
};

StackArray::StackArray(int size){
	arr_stack = new int[size];
	max = size;
	top = -1;
}

StackArray::~StackArray(){
	delete [] arr_stack;
}

void StackArray::push(int value){
	
	if(isFull()){
		cout << "\nThe list is full.\n" << endl;
	}
	else{
		++top;
		arr_stack[top] = value;	
	}
}

int StackArray::pop(){
	if(isEmpty()){
		cout << "\nThe list is empty.\n" << endl;
	}
	else{
		cout << "\nPop ! ! !" << endl;
		cout << arr_stack[top] << endl << endl;
		top--;
	}
}

void StackArray::show(){
	cout << "List : ";
	for(int i=0; i<=top; i++){
		cout << arr_stack[i] << " ";
	}
	cout << endl;
}

bool StackArray::isFull(){
	if(top == max-1){
		return true;
	}
	else
		return false;
}

bool StackArray::isEmpty(){
	if(top == -1){
		return true;
	}
	else 
		return false;
}

int main(){
	int size, num, value;
	cout << "Input max size >> ";
	cin >> size;
	
	StackArray arr(size);
	
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
			arr.push(value); 
		}
		else if(num==2){
			arr.pop(); 
		}
		else if(num==3){
			arr.show();
		}
	}while(num!=0);
}

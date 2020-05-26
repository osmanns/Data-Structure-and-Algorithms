#include <iostream>

using namespace std;

class QueueArray{
	private :
		int *arr_queue;
		int max, count, font, back;
	
	public :
		QueueArray(int size);
		~QueueArray();
		void enqueue(int value);
		int dequeue();
		void show();
		bool isFull();
		bool isEmpty();
};

QueueArray::QueueArray(int size){
	arr_queue = new int[size];
	max = size;
	count = 0;
	font = 0;
	back = 0;
}

QueueArray::~QueueArray(){
	delete []arr_queue;
}

void QueueArray::enqueue(int value){
	if(isFull()){
		cout << "\nThe Queue is full.\n" << endl;
	}
	else{
		
		if(isEmpty()){
			font = 0;
			back = 0;
			arr_queue[back] = value;		
		}
		else if(back == max-1 && !isEmpty()){
			back = 0;
			arr_queue[back] = value;
		}
		else{
			++back;
			arr_queue[back] = value;
		}
		count++;	
			
	}	
}

int QueueArray::dequeue(){
	if(isEmpty()){
		cout << "\nThe Queue is empty.\n" << endl;
	}
	else{
		count--;				
	 	if(font == max-1 && !isEmpty()){
			return arr_queue[font];	
			font = 0;
		}		
		else{		
			return arr_queue[font];	
			font++;			
		}	
	}
}

void QueueArray::show(){
	cout << "Queue : ";
	if(isEmpty()){
		cout << "Queue is empty." << endl;
	}
	int n;
	n = font;
	for(int i=0; i<count; i++){
		cout << arr_queue[n++] << " ";
	}	
	cout << endl;	
}

bool QueueArray::isFull(){
	if(count == max){
		return true;
	}
	return false;
}

bool QueueArray::isEmpty(){
	if(count == 0){
		return true;
	}
	return false;
}

int main(){
	int size, num, value;
	cout << "Input max size >> ";
	cin >> size;
	
	QueueArray arr(size);
	
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
			arr.enqueue(value); 
		}
		else if(num==2){
			arr.dequeue(); 
		}
		else if(num==3){
			arr.show();
		}
	}while(num!=0);
}

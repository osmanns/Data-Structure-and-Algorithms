#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class SortingArray{
	private :
		int *arr;
		int size;
		
	public :
		SortingArray(int size);
		~SortingArray();
		int insertion();
		int selection();
		int bubble();
		int random();
		int show();
};

SortingArray::SortingArray(int size){
	arr = new int[size];
	this->size = size;
}

SortingArray::~SortingArray(){
	delete []arr;
}

int SortingArray::insertion(){
	int temp, i, j;
		for(int i=0; i<size; i++){
			temp = arr[i];
			j=i-1;
				for(int i=j; i>=0; i--){
					while((temp < arr[j])&&(j>=0)){			
						arr[j+1] = arr[j];
						j=j-1;	
					}
					/*
					if(temp < arr[j] && j>=0){
						arr[j+1] = arr[j];	
						j=j-1;
						arr[j+1] = temp;
					}
					*/
					arr[j+1] = temp;
				}
		}
	cout << "Insertion Sort ! ! !" << endl;
}

int SortingArray::selection(){
	int temp, min, i, j;
		for(int i=0; i<=size-2; i++){
			min = i;
			//j=i+1;
			for(int j=i+1; j<=size-1; j++){
				if(arr[j] < arr[min]){
					min = j;
				}
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;		
		}
	cout << "Selection Sort ! ! !" << endl;
}

int SortingArray::bubble(){
	int temp, i, j;
	for(int i=1; i<=size-1; i++){
		for(int j=size-1; j>=i; j--){
			if(arr[j] < arr[j-1]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	cout << "Bubble Sort ! ! !" << endl;
}

int SortingArray::random(){
	for(int i=0; i<size; i++){
		arr[i] = rand() %10 + 1;
	}
	cout << "Random ! ! !" << endl;
}

int SortingArray::show(){
	cout << "Number : ";
	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int size, num;
	cout << "Input max size >> ";
	cin >> size;
	
	SortingArray arr(size);
	
	do{
		cout << "===================" << endl;
		cout << " 1. Random         " << endl;
		cout << " 2. Insert sort    " << endl;
		cout << " 3. Selection sort " << endl;
		cout << " 4. Bubble sort    " << endl;
		cout << " 5. Show           " << endl;
		cout << " 0. Exit           " << endl;
		cout << "===================" << endl;
		cout << ">> ";
		cin >> num;
	
		if(num == 1){
			arr.random();
		}
		if(num == 2){
			arr.insertion();
		}
		if(num == 3){
			arr.selection();
		}
		if(num == 4){
			arr.bubble();
		}
		if(num == 5){
			arr.show();
		}
	}while(num!=0);
}


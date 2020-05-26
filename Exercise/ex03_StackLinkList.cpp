#include<iostream>
using namespace std;

class StackLink{
			
				private : 
						class Node{
								public : 
									int arr_Stack;
									Node*link;
									Node(int data){
										this->arr_Stack = data;
										link = NULL;
									}
						};
						  Node*top;
						  int count;

				public : 
						StackLink(){
							this->top = NULL;
							this->count = 0;
						}
						~StackLink(){
							for(int i = 1; i < this->count; i++){
									Node * temp = this->top;
									this->top = this->top->link;
									delete temp;
								temp = NULL;
							}// for
								this->top = NULL;
						} // decon		
						
						
						void push(int value){
							Node*newNode = new Node(value);
								if(isEmpty()){
									top = newNode;
								}else{
									newNode->link = top;
									top = newNode;
								}
								count++;	
						}
						
						int pop(){
							if(isEmpty()){
								cout << "    Don't have data ! " <<endl;	
							}else{
								count --;
								cout << "POP!!! " << endl;
									Node*temp = this->top;
									top = top->link;
								return temp->arr_Stack;
								delete temp;
									temp = NULL;
									
							}
						}	
						
						void show(){
							if(isEmpty()){
								cout << "    Don't have data !! " << endl;
							}
							else{
								cout << endl;
								for(Node*temp=top;temp!=NULL;temp=temp->link){
									cout << temp->arr_Stack << " ";
								}
								cout << endl;	
							}
						}
						
						int size(){
							return count;
						}
						
						bool isEmpty(){
								if(count == 0){
									return true;
								}else{
									return false;
								}
						}
						
};
int main(){
				StackLink * obj_stackLink = new StackLink();
				char choice; int data;
			do{
				cout << endl <<" >>>> MENU <<<< " << endl
					 << " 1. show " << endl
					 << " 2. push " << endl
					 << " 3. pop " << endl
					 << " 4. exit " << endl
					 << "Enter choice : " ;
					cin >> choice ;
					
					if(choice == '1'){
							obj_stackLink->show();
					}
					if(choice == '2'){
						cout <<">>> PUSH <<< " << endl << "Enter push data : " ;
							cin >> data;
							obj_stackLink->push(data);
					}
					if(choice == '3'){
							obj_stackLink->pop();
					}
					
				}while(choice != '4');
				cout << endl << "END PROGRAM !!! " << endl;
}	

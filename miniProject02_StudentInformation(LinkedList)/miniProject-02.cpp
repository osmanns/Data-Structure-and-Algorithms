#include <iostream>
#include <fstream>
#include <string>
#include <stdbool.h>
#include <iomanip>

using namespace std;

class Student{
	private : 
		class Node{
			public:
				string id, prefix, fname, lname, nickname, phonenumber;
				float gpa;
				Node *link;

				Node(string id, string prefix, string fname, string lname, string nickname, 
				     string phonenumber, float gpa){
					this->id = id;
					this->prefix = prefix;
					this->fname = fname;
					this->lname = lname;
					this->nickname = nickname;
					this->phonenumber = phonenumber;
					this->gpa = gpa;
					link = NULL;
				}
		};	

		Node *head;
		Node *tail;
		int count;	
		
  	public :
  		Student();
  		~Student();
  		void addInformation(string id, string prefix, string fname, string lname, string nickname, 
				 string phonenumber, float gpa);
		void addInformation(string id, string prefix, string fname, string lname, string nickname, 
				 string phonenumber, float gpa, int index);
  		void removeInformation(string id);
  		void searchInformation(string id);
  		void editInformation(string id);
  		void showInformation();
  		int readFile();
  		int writeFile();
  		bool isEmpty();
		bool checkId(string id);
		int size();	
};

Student::Student(){
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
	this->readFile();
}

Student::~Student(){
	for(int i=1; i<this->count; i++){
		Node *tmp = this->head;
		this->head = this->head->link;
		delete tmp;
		tmp =  NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}

void Student::addInformation(string id, string prefix, string fname, string lname, string nickname, 
				  string phonenumber, float gpa){
	Node *n = new Node(id, prefix, fname, lname, nickname, phonenumber, gpa);
	
		if(isEmpty()){
			head = n;
			tail = n;
		}
		else{
			tail->link = n;
			tail = tail->link;
		} 
		count++;
}

void Student::addInformation(string id, string prefix, string fname, string lname, string nickname, 
				 string phonenumber, float gpa, int index){
	Node *n = new Node(id, prefix, fname, lname, nickname, phonenumber, gpa);
	Node *temp = head;
		if(this->isEmpty()){
			head = n;
			tail = n;
			count++;
		}	
		else{
			//if(index>0 && index<=size()){
				if(index == 1){
					n->link = head;
					head = n;
				count++;
				}
				if(count+1==index){ 
					tail->link = n;
					tail = n;
				count++;
				}
			else{
				for(int i=2;i<count+1;i++){
					if(i==index){
						n->link = temp->link;
						temp->link = n;
					count++;
				 	} 
					temp = temp->link;
			  	} 
			}

		}	 	
}

void Student::removeInformation(string id){
	Node *ptemp, *temp;
	int round = 1;
					
			for(Node *temp = head;temp != NULL;temp = temp->link){
				if(temp->id != id && count == round){
					cout << "The item to be delete is not in the list.\n\n";
				}			
				if(round == 1){
					ptemp = temp;
					if(temp->id == id){
						if(temp == head && temp == tail){
							delete temp;
							head = NULL;
							tail = NULL;
						}else if(temp == head){
							head = head->link;
							delete temp;
						}	
						//cout << "Remove Complete\n\n";
						count--;
						break;
					}
				}
				else{
					if(temp->id == id){							
						if(temp == tail){
							tail = ptemp;
							tail->link = NULL;
							delete temp;
						}
						else{
							ptemp->link = temp->link;
							delete temp;
						}
						//cout << "Remove Complete\n\n";
						count--;
						break;						
					}
					else
					{
						ptemp = temp;
					}	
				}			
				round++;		
			}
}

void Student::searchInformation(string id){
	system("cls");
		cout << "                                    Search Student                                       " << endl;
		cout << "=======================================================================================" << endl;
		cout << "Student Id      Prefix  First & Last Name	Nickname	Tel		GPA                     " << endl;
		cout << "=======================================================================================" << endl;
		for(Node *temp = head;temp != NULL;temp = temp->link){
			if(temp->id == id){			
					cout << setw(8) << left << temp->id << "\t" 
			 			 << setw(4) << left << temp->prefix << "\t"
						 << setw(10) << left << temp->fname << "  " 
						 << setw(10) << left << temp->lname << "\t" 
						 << setw(8) << left << temp->nickname << "\t" 
						 << setw(10) << left << temp->phonenumber << "\t" 
		 				 << setw(4) << left << temp->gpa << "\n\n";				
			}
		}		
}

void Student::editInformation(string id){
		string id2, prefix2, fname2, lname2, nickname2, phonenumber2;
		float gpa2;
		int index = 1;		
			for(Node*temp=head;temp!=NULL;temp=temp->link){	
				if(temp->id == id){
					removeInformation(id);
					cout << "Input Student Id : ";
					cin >> id2;
					cout << "Input Student Prefix : ";
					cin >> prefix2;
					cout << "Input Student Frist Name : ";
					cin >> fname2;
					cout << "Input Student Last Name : ";
					cin >> lname2;
					cout << "Input Student Nickname : ";
					cin >> nickname2;
					cout << "Input Student Phonenumber : ";
					cin >> phonenumber2;
					cout << "Input Student GPA : ";
					cin >> gpa2;					
				addInformation(id2, prefix2, fname2, lname2, nickname2, phonenumber2, gpa2, index);
				writeFile();
				}
			index++;
			}
				
}

void Student::showInformation(){
	system("cls"); 
	int n = 1;
	cout << "                                    Show Student                                             " << endl;
	cout << "=============================================================================================" << endl;
	cout << "No	Student Id      Prefix  First & Last Name	Nickname	Tel		GPA                       " << endl;
	cout << "=============================================================================================" << endl;
		if(this->isEmpty()){
			cout << "No Information !!!" << endl;
		}else{
			Node *temp;
			temp = head;
				for(Node*temp=head;temp!=NULL;temp=temp->link){	
					cout << n << "\t"; 
					cout << setw(8) << left << temp->id << "\t" 
						 << setw(4) << left << temp->prefix << "\t"
						 << setw(8) << left << temp->fname << "   " 
						 << setw(10) << left << temp->lname << "\t" 
						 << setw(8) << left << temp->nickname << "\t" 
						 << setw(10) << left << temp->phonenumber << "\t" 
						 << setw(4) << left << temp->gpa << "\n";
					//temp = temp->link;
					n++;
				}
			}
	cout << "=============================================================================================" << endl;
	cout << endl;
	
}

int Student::readFile(){
	ifstream file;
		
		string id, prefix, fname, lname, nickname, phonenumber;
		float gpa;
		
			file.open("student.txt");	
				while(file >> id >> prefix >> fname >> lname >> nickname >> phonenumber >> gpa){		
					addInformation(id, prefix, fname, lname, nickname, phonenumber, gpa);
				}
			file.close();
}

int Student::writeFile(){
	ofstream file;
		
		file.open("student.txt",ios::out);
		for(Node *temp = head;temp != NULL;temp = temp->link){
			file << temp->id << "\t" 
				 << temp->prefix << "\t" 
				 << temp->fname << "\t"
				 << temp->lname << "\t" 
				 << temp->nickname << "\t" 
				 << temp->phonenumber << "\t" 
				 << temp->gpa << "\n";
		}
		file.close();
}

bool Student::isEmpty(){
	if(count == 0){
		return true;
	}else{
		return false;
	}
}

bool Student::checkId(string id){		
		for(Node *temp = head;temp != NULL;temp = temp->link){
			if(temp->id == id){
				return true;
			}	
		}
		return false;
}

int Student::size(){
	return count;
}

int main(){
	Student x;
	string id, prefix, fname, lname, nickname, phonenumber;
	float gpa;
	string number;	
	
			do{		
				cout << "========================================\n";
				cout << "====== STUDENT INFORMATION SYSTEM ======\n";
				cout << "========================================\n\n";
				cout << "1. List     Student\n";
				cout << "2. Add      Student\n";
				cout << "3. Search   Student\n";
				cout << "4. Edit     Student\n";
				cout << "5. Remove   Student\n";
				cout << "0. Exit   Program\n";
				cout << "-----------------\n";
				cout << "Enter number(0-5) >> ";	
				cin >> number;
			
					if(number == "1"){
						x.showInformation();
					}
					if(number == "2"){
						cout << "                                    Add Student                                           " << endl;
						cout << "=============================================================================================" << endl;
							cout << "Input Student Id : ";
							cin >> id;
							cout << "Input Student Prefix : ";
							cin >> prefix;
							cout << "Input Student Frist Name : ";
							cin >> fname;
							cout << "Input Student Last Name : ";
							cin >> lname;
							cout << "Input Student Nickname : ";
							cin >> nickname;
							cout << "Input Student Phonenumber : ";
							cin >> phonenumber;
							cout << "Input Student GPA : ";
							cin >> gpa;					
							x.addInformation(id, prefix, fname, lname, nickname, phonenumber, gpa);
					}
					if(number == "3"){
						system("cls");
						string id;
						cout << "                                    Search Student                                           " << endl;
						cout << "=============================================================================================" << endl;
						cout << "Enter Student ID >> ";
						cin >> id;
							if(x.checkId(id)){
								x.searchInformation(id);
							}
							else{
								system("cls"); 				
								cout << "\nNo Information !!!\n" << endl;
							} 
					}
					if(number == "4"){
						string id;
						x.showInformation();
						cout << "                                    Edit Student                                             " << endl;
						cout << "=============================================================================================" << endl;
						cout << "Enter Student ID >> ";
						cin >> id;
							if(x.checkId(id)){
								x.editInformation(id);
							}
							else{
								system("cls"); 				
								cout << "\nNo Information !!!\n" << endl;
							}
					}
					if(number == "5"){
						x.showInformation();
						string id;
						cout << "                                    Delete Student                                           " << endl;
						cout << "=============================================================================================" << endl;
						cout << "Enter Student ID >> ";
						cin >> id;
							if(x.checkId(id)){
								x.removeInformation(id);
								cout << "Remove Complete\n\n";
								x.writeFile();
							}
							else{
								system("cls"); 				
								cout << "\nNo Information !!!\n" << endl; 
							}
					}				
			}while(number != "0");
									
};







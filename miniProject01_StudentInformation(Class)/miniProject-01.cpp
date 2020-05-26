#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student{
  private : 
  	int capacity, index; 
	string id[20], prefixname[20], fname[100], lname[100], nickname[20], phonenumber[20];
	double gpa[20];
		
  public :
  	//constructor
  	Student();
  	//accessor
  	void setInformation(string id2, string prefixname2, string fname2, string lname2, string nickname2, string phonenumber2, double gpa2, int index);
  	int readFile();
  	int writeFile();
  	int getCapacity();
	//modifiers
	void setCapacity();
  	void addInformation();
  	void showInformation();
  	int searchInformation();
  	int editInformation();
  	
	
};

Student::Student(){
	capacity = 0;
		for(int i=0; i<capacity; i++){
			id[i] = " ";
			prefixname[i] = " ";
			fname[i] = " ";
			lname[i] = " ";
			nickname[i] = " ";
			phonenumber[i] = " ";
			gpa[i] = 0.00;
		}
}

void Student::setInformation(string id2, string prefixname2, string fname2, string lname2, string nickname2, string phonenumber2, double gpa2, int index){
		id[index] = id2;
		prefixname[index] = prefixname2;
		fname[index] = fname2;
		lname[index] = lname2;
		nickname[index] = nickname2;
		phonenumber[index] = phonenumber2;
		gpa[index] = gpa2;
}

//add max size of list
void Student::setCapacity(){
	int number;
		cout << "\t ========================================\n";
		cout << "\t ====== STUDENT INFORMATION SYSTEM ======\n";
		cout << "\t ========================================\n";
		cout << "\n Number of students >> ";
			cin >> number;
			capacity = number;
}

//add the information to the list
void Student::addInformation(){
	for(int i=0; i<capacity; i++){
		cout << "\nStudent [" << i+1 << "]";
		cout << "\t" << "ID >> ";
			cin >> id[i];
		cout << "\t\t" << "Prefix Name >> ";
			cin >> prefixname[i];
		cout << "\t\t" << "First Name >> ";
			cin >> fname[i];
		cout << "\t\t" << "Last Name >> ";
			cin >> lname[i];
		cout << "\t\t" << "NICKNAME >> ";
			cin >> nickname[i];
		cout << "\t\t" << "TEL >> ";
			cin >> phonenumber[i];
		cout << "\t\t" << "GPA >> ";
			cin >> gpa[i];
		cout << endl;
	}
	system("cls");
}

void Student::showInformation(){
	system("cls");
	
		cout << "\t====== STUDENTS LIST ======\n\n";
			for(int i=0; i<=capacity; i++){
				cout << "\t" << id[i];
				cout << "\t" << prefixname[i];
				cout << " "  << fname[i]; 
				cout << " "  << lname[i];
				cout << "\t" << nickname[i]; 
				cout << "\t" << phonenumber[i];
				cout << "\t" << gpa[i] << "\n\n"; 
			}
}

int Student::searchInformation(){
	system("cls");
		string search;
		
		cout << "\t====== STUDENTS SEARCH ======\n\n";
		cout << "Search ID >> ";
		cin >> search;
		//check 
			for(int i=0; i<=capacity; i++){
				if(search == id[i]){
					cout << "\n";
					cout << "\t" << id[i];
					cout << "\t" << prefixname[i];
					cout << " "  << fname[i]; 
					cout << " "  << lname[i];
					cout << "\t" << nickname[i]; 
					cout << "\t" << phonenumber[i];
					cout << "\t" << gpa[i] << "\n\n\n"; 			
				return 1;
				}					
			}
		//didn't find
		cout << "\n\tDidn't find ID in list.\n\n";	
}

int Student::editInformation(){
	system("cls");
		
		string id2, prefixname2, fname2, lname2, nickname2, phonenumber2;
		double gpa2;
		string search;
		
			cout << "\t====== STUDENTS EDIT ======\n\n";
			cout << "Select ID >> ";
				cin >> search;
					//check 
					for(int i=0; i<=capacity; i++){
						if(search == id[i]){							
							cout << "\n\t" << "ID >> ";
							cin >> id2;
							cout << "\t" << "Prefix Name >> ";
							cin >> prefixname2;
							cout << "\t" << "First Name >> ";
							cin >> fname2;
							cout << "\t" << "Last Name >> ";
							cin >> lname2;
							cout << "\t" << "NICKNAME >> ";
							cin >> nickname2;
							cout << "\t" << "TEL >> ";
							cin >> phonenumber2;
							cout << "\t" << "GPA >> ";
							cin >> gpa2;
							cout << endl;
				//after edit
				setInformation(id2, prefixname2, fname2, lname2, nickname2, phonenumber2, gpa2, i);	
				writeFile();
				}
			}	
			//didn't find
			cout << "\n\tDidn't find ID in list.\n\n";	
}

int Student::readFile(){
	ifstream file;
		
		string id, prefixname, fname, lname, nickname, phonenumber;
		double gpa;
		int index = 0;
		
			file.open("data.txt");	
				while(getline(file, id)){
					file >> id >> prefixname >> fname >> lname >> nickname >> phonenumber >> gpa;
						setInformation(id, prefixname, fname, lname, nickname, phonenumber, gpa, index++);
						//index++;
				}
			capacity = index - 1;
			file.close();
}

int Student::writeFile(){
	ofstream file;
	
		file.open("data.txt");
		for(int i=0; i<=capacity; i++){
			file << "\n" << id[i] << "\t" 
				 << prefixname[i] << " " 
				 << fname[i] << " "
				 << lname[i] << "\t" 
				 << nickname[i] << "\t" 
				 << phonenumber[i] << "\t" 
				 << gpa[i];
		}
		file.close();
}

int Student::getCapacity(){
	return capacity;
}

int main(){
	Student x;
	
	string number;	
	
	x.readFile();
		if(x.getCapacity() == -1){
			x.setCapacity();
			x.addInformation();
			x.writeFile();
		}
		
		//else
			do{		
				cout << "\t ========================================\n";
				cout << "\t ====== STUDENT INFORMATION SYSTEM ======\n";
				cout << "\t ========================================\n\n";
				cout << "\t 1. List   Student\n";
				cout << "\t 2. Search Student\n";
				cout << "\t 3. Edit   Student\n";
				cout << "\t 4. Exit   Program\n";
				cout << "\t -----------------\n";
				cout << "\t Select Choice >> ";
			
				cin >> number;
			
					if(number == "1"){
						x.showInformation();
					}
					if(number == "2"){
						x.searchInformation();
					}
					if(number == "3"){
						x.editInformation();
					}
			}while(number != "4");			
		
};







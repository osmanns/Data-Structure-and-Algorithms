
#include <iostream>
#include <string>
using namespace std;

class Student{
  private : 
	string id, prefixName, fname, lname, nickName;
  public :
	string getId(){
		return id;	
	}
	void setId(string id){
		this->id = id;	
	}
	string getPrefixName(){
		return prefixName;
	}
	void setPrefixName(string prefixName){
		this->prefixName = prefixName;
	}
	string getFname(){
		return fname;
	}
	void setFname(string fname){
		this->fname = fname;
	}
	string getLname(){
		return lname;
	}
	void setLname(string lname){
		this->lname = lname;
	}
	string getNickName(){
		return nickName;
	}
	void setNickName(string nickName){
		this->nickName = nickName;
	}
};
int main(){
	Student s[10];
	string id, prefixName, fname, lname, nickName;
  for(int i=0; i<10; i++){
    cout << "Id : ";
    cin >> id;
    s[i].setId(id);
    cout << "Pre : ";
    cin >> prefixName;
    s[i].setPrefixName(prefixName);
    cout << "Fname : ";
    cin >> fname;
    s[i].setFname(fname);
    cout << "Lname : ";
    cin >> lname;
    s[i].setLname(lname);
    cout << "Nickname : ";
    cin >> nickName;
    s[i].setNickName(nickName);  		
  } 
  for(int i=0; i<10; i++){
    cout << "ID : " << s[i].getId() << endl;
    cout << "Prefixname : " << s[i].getPrefixName() << endl;
    cout << "Fname : " << s[i].getFname() << endl;
    cout << "Lname : " << s[i].getLname() << endl;
    cout << "Nickname : " << s[i].getNickName() << endl;     
  }
}




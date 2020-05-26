#include <iostream>

using namespace std;

class BinaryTree{
	private :
		class Node{
			public :
				int data;
				Node *left;
				Node *right;
			
				Node(int data){
					this->data = data;
					left = NULL;
					right = NULL;
			}
		};
		
	public : 
		~BinaryTree();
		BinaryTree();
		void insert(int value);
		void printPreOrder(Node *leaf);
		void printInOrder(Node *leaf);
		void printPostOrder(Node *leaf);
		bool search(int value);
		void destroy_tree(Node *leaf);
		
		Node *root;
};

BinaryTree::BinaryTree(){
	root = NULL;
}

BinaryTree::~BinaryTree(){
	this->destroy_tree(this->root);
}

void BinaryTree::destroy_tree(Node *leaf){
	if(leaf!=NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;		
	}
}

void BinaryTree::insert(int value){
	Node *n = new Node(value);
	

	if(root == NULL){
		root = n;
	}
	else{
		Node *temp = root;
		bool is_equal = false;
		Node *ptemp = root;
		int rol = 0; // 0 = right, 1 = left
		while(temp!=NULL){
			ptemp = temp;
			
			if(value < temp->data){
				temp = temp->left;
				rol = 1;
			}
			else if(value > temp->data){
				temp = temp->right;
				rol = 0;	
			}
			else{
				is_equal = true;
			}
		}
		if(!is_equal){
			if(rol==1){
				ptemp->left = n;
			}
			else{
				ptemp->right = n;
			}
		}
	}
}

void BinaryTree::printPreOrder(Node *leaf){
	if(leaf==NULL)
		return;
	cout << leaf->data << " ";
	printPreOrder(leaf->left);
	printPreOrder(leaf->right);

}

void BinaryTree::printInOrder(Node *leaf){
	if(leaf==NULL)
		return;
	printInOrder(leaf->left);
	cout << leaf->data << " ";
	printInOrder(leaf->right);
}

void BinaryTree::printPostOrder(Node *leaf){
	if(leaf==NULL)
		return;
	printPreOrder(leaf->left);
	printPreOrder(leaf->right);
	cout << leaf->data << " ";
}

bool BinaryTree::search(int value){
	Node *leaf = this->root;
	while(leaf!=NULL){
		if(value==leaf->data)
			return true;
		if(value<leaf->data){
			leaf = leaf->left;
		}
		else{
			leaf = leaf->right;
		}
	}
	return false;
}

int main(){
	BinaryTree t;
	
	int num ,value;
	do{
		cout << endl;
		cout << "===================" << endl;
		cout << " 1. Insert         " << endl;
		cout << " 2. PreOrder       " << endl;
		cout << " 3. InOrder        " << endl;
		cout << " 4. PostOrder      " << endl;
		cout << " 5. Search         " << endl;
		cout << " 0. Exit  		    " << endl;
		cout << "===================" << endl;
		cout << ">> ";
		cin >> num;
		
		if(num==1){
			cout << "Enter value >> ";
			cin >> value;
			t.insert(value);	
		}
		else if(num==2){
			t.printPreOrder(t.root);
		}
		else if(num==3){
			t.printInOrder(t.root);
		}
		else if(num==4){
			t.printPostOrder(t.root);
		}
		else if(num==5){
			cout << "Enter value >> ";
			cin >> value;
			if(t.search(value)){
				cout << "Found Data ! ! !" << endl;
			}
			else{
				cout << "Not Found Data ! ! !" << endl;
			}
		}
	}while(num!=0);
}


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class BinarySearchTree{
	private:
		struct node{node* left;node* right;int data;};
		node* root;
	
	public:
		BinarySearchTree(){root = NULL;}
	   
		bool isEmpty() const {return root==NULL; }

		void insert(int d){
			node* t = new node;t->data = d;t->left = NULL;t->right = NULL;
			node* parent=NULL;
			if(isEmpty()) {root = t;}
			else{
				node* curr=root;
				while(curr){
					parent = curr;
					if(t->data > curr->data) curr = curr->right;
					else curr = curr->left;
				}
				if(t->data < parent->data) {parent->left = t;}
				else {parent->right = t;}
			}
		}
		
		void printInorder(){inorder(root);}
		
		void inorder(node* p){
			if(p == NULL){return;}
			else{
				if(p->left) inorder(p->left);
				cout<<" "<<p->data<<" ";
				if(p->right) inorder(p->right);
			}
		}
		
		int LCA(int x,int y){
			node* temp=LCAnode(root,x,y);
			return temp->data;
		}
		
		node* LCAnode(node* currentRoot,int x, int y){
			if(currentRoot==NULL){return NULL;}
			if((currentRoot->left !=NULL &&currentRoot->left->data==min(x,y)) || (currentRoot->right !=NULL && currentRoot->right->data==max(x,y))){return currentRoot;}
			node* leftSubtree=LCAnode(currentRoot->left,x,y);
			node* rightSubtree=LCAnode(currentRoot->right,x,y);
			if(leftSubtree && rightSubtree){return currentRoot;}
			else if(leftSubtree){return leftSubtree;}
			else {return rightSubtree;}
		}
		
};

int main (int argc, char * const argv[]) {
	
	BinarySearchTree myTree;
	myTree.insert(30);myTree.insert(8);myTree.insert(52);myTree.insert(3);myTree.insert(20);myTree.insert(10);myTree.insert(29);
	
	ifstream inputFile (argv[1]);
	string line;
	if(inputFile){		
		while(getline(inputFile,line)){
			int first,second;
			istringstream buf(line);
			buf>>first>>second;
			cout << myTree.LCA(first,second)<<endl;
		}
	}
	
	return 0;
}



#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node{
	struct Node *lchild, *rchild;
	int data;
}*root=NULL;

void insert(int key){
    // cout << key;
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	struct Node *currNode = root;
	
	if(root == NULL){
	    root = newNode;
		return;
	}
	else{
		while(1){
		 
			if(key < currNode->data){
				if(currNode->lchild == NULL){
					currNode->lchild = newNode;
					
				// 	return newNode->data;
				 return;
				}
				currNode = currNode->lchild;
			}
			else if(key > currNode->data){
				if(currNode->rchild == NULL){
					currNode->rchild = newNode;
				// 	cout <<newNode->data<<"\n";
					return;
				}
				currNode = currNode->rchild;
			}
			else if(key == currNode->data){
			    cout << "Element already present\n";
			    return;
			}
		}
	}
	return;
}

int Search(int sata){//search data
	struct Node *currNode = root;

	while(currNode != NULL){
		
		if(sata == currNode->data){
			return 1;
		}
		else if(sata < currNode->data){
			currNode = currNode->lchild;
		}
		else if(sata > currNode->data){
			currNode = currNode->rchild;
		}

	}

	return -1;
}

void realTraverse(struct Node *currNode, vector<int> &visited){
	if(currNode != NULL){
		realTraverse(currNode->lchild, visited);
	    visited.push_back(currNode->data);
	    realTraverse(currNode->rchild, visited);
	}
}

vector<int> Inorder(struct Node *currNode){
	vector<int> visited;
	realTraverse(currNode, visited);
	return visited;   
	
}

vector<int> iterativePreorder(struct Node *currNode){
	vector<int> preorder;
	stack<struct Node*> node;
    node.push(currNode);
    while(!node.empty()){

		currNode = node.top();
		node.pop();
		preorder.push_back(currNode->data);
		if(currNode->rchild != NULL){
			node.push(currNode->rchild);
		}
		if(currNode->lchild != NULL){
			node.push(currNode->lchild);
		}

    }
    return preorder;
}

vector<int> iterativeInorder(struct Node *currNode){
	vector<int> inorder;
	stack<struct Node*> node;

    while(true){

	    if(currNode!= NULL){
			node.push(currNode);
			currNode = currNode->lchild;
		}
		else{
			if(node.empty())break;
			currNode = node.top();
			node.pop();
			inorder.push_back(currNode->data);
			currNode = currNode->rchild;
		}
		

    }
    return inorder;
}


vector<int> iterativePostorder(struct Node *currNode){
	 struct Node *temp;
	 vector<int> v;
	 stack<struct Node*> st;
	 while(!st.empty() || currNode!=NULL){
	 	if(currNode!=NULL){
	 		st.push(currNode);
	 		currNode = currNode->lchild;
	 	}
	 	else{
	 		temp = st.top()->rchild;
	 		if(temp == NULL){
	 			temp = st.top();
	 			st.pop();
	 			v.push_back(temp->data);
	 			while(!st.empty() && temp == st.top()->rchild){
	 				temp = st.top();
	 				st.pop();
	 				v.push_back(temp->data);
	 			}
	 			
	 		}
	 		else{
	 			currNode = temp;
	 		}
	 	}
	 }
	 return v;
}

int main(){
	cout <<"Hello"<<"\n";
	insert(10);
	// cout << root->data <<"\n";
	insert(11);
	insert(12);
	insert(5);
	insert(3);
	insert(4);
	vector<int> arr = Inorder(root);
	// for(int i = 0; i < arr.size(); i++){
	// 	cout << arr[i] <<"\n";
	// }
	int flag = Search(4);
	if(flag == 1){
		cout <<"Element is present on the tree";
	}
	else{
		cout <<"Element is not present in tree" <<"\n";
	}
	// vector<int> inorder = iterativeInorder(root);
	// for(int i = 0; i < inorder.size(); i++){
	// 	cout << "\n" << inorder[i] ;
	// }

	// vector<int> preorder = iterativePreorder(root);
	// for(int i = 0; i < preorder.size(); i++){
	// 	cout << "\n" << preorder[i] ;
	// }
    vector<int> post = iterativePostorder(root);
    for(int i = 0; i < post.size(); i++){
		cout << "\n" << post[i] ;
	}
	return 0;
}
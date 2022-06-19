#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
	struct Node *lchild, *rchild;
	int data;
}*root=NULL;

void insert(int key){
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
    				return;
				}
				currNode = currNode->lchild;
			}
			else if(key > currNode->data){
				if(currNode->rchild == NULL){
					currNode->rchild = newNode;
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

struct Node *rInsert(struct Node *currNode, int key){
	if(currNode == NULL){
		currNode = (struct Node*)malloc(sizeof(struct Node *));
		currNode -> data = key;
		currNode -> lchild = currNode -> rchild = NULL;
		return currNode;
	}
	if(key < currNode -> data){
		currNode -> lchild = rInsert(currNode -> lchild, key);
	}
	else if(key > currNode->data){
		currNode -> rchild = rInsert(currNode -> rchild, key);
	}

	return currNode;
}

int Height(struct Node *currNode){
	if(currNode == NULL){
		return 0;
	}
	return 1 + max(Height(currNode -> lchild), Height(currNode -> rchild));
}

struct Node *InPre(struct Node *currNode){
	while(currNode && currNode->rchild != NULL){
		currNode = currNode -> rchild;
	}
	return currNode;
}

struct Node *InSuc(struct Node * currNode){
	while(currNode && currNode -> lchild != NULL){
		currNode = currNode -> lchild;
	}
	return currNode;
}

struct Node *del(struct Node* currNode, int key){

	struct Node * q;
	if(currNode == NULL) return NULL;
	if(currNode -> lchild == NULL && currNode -> rchild == NULL){
		if(currNode == root){
			return NULL;
		}
		free(currNode);
		return NULL;
	}
	if(key > currNode -> data){
		currNode ->rchild = del(currNode -> rchild, key);
	}
	else if(key < currNode->data){
		currNode -> lchild = del(currNode -> lchild, key);
	}
	else{
		if(Height(currNode -> lchild) > Height(currNode -> rchild)){
			q = InPre(currNode -> lchild);
			currNode -> data = q -> data;
			currNode -> lchild = del(currNode -> lchild, q -> data);
		}
		else{
			q = InSuc(currNode -> rchild);
			currNode -> data = q -> data;
			currNode -> rchild = del(currNode -> rchild, q -> data);
		}
	}

	return currNode;
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

vector<int> levelOrder(struct Node *currNode){
	vector<int> v;
	queue<struct Node*> q;
	q.push(currNode);
	while(!q.empty()){
		currNode = q.front();
		q.pop();
		v.push_back(currNode->data);
		if(currNode->lchild != NULL){
			q.push(currNode->lchild);
		}
		if(currNode->rchild != NULL){
			q.push(currNode->rchild);
		}
	}
	return v;
}

int main(){
	cout <<"Hello"<<"\n";
	root = rInsert(root,10);
	insert(11);
	insert(12);
	insert(5);
	insert(3);
	insert(4);
	vector<int> arr = Inorder(root);

	int flag = Search(4);
	if(flag == 1){
		cout <<"Element is present on the tree";
	}
	else{
		cout <<"Element is not present in tree" <<"\n";
	}


	del(root, 10);
    vector<int> post = levelOrder(root);
    for(int i = 0; i < post.size(); i++){
		cout << "\n" << post[i] ;
	}


	return 0;
}
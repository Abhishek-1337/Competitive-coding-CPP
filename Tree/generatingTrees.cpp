#include<bits/stdc++.h>

using namespace std;


struct Node{
	int data;
	struct Node *right, *left;
}*root = NULL;

void generateBST(int arr[], int len){
   root = (struct Node *)malloc(sizeof(struct Node));
   root->left = root->right = NULL;
   root->data = arr[0];
   struct Node *currNode = root;
   stack<struct Node*> stac;
   int i = 1;

   while(i < len){
   	 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node*));
   	 newNode->left = newNode->right = NULL;
   	 newNode->data = arr[i];
   	 if(arr[i] < currNode->data){
   		currNode->left = newNode;
   		stac.push(currNode);
   		currNode = currNode->left;
   		i++;
   	 }
   	 else{
   	 	struct Node* check = stac.top();
   	 	if(stac.empty()){
   	 		check->data = INT_MAX;
   	 	}

        if( arr[i] > currNode->data || arr[i] < check->data){
        	currNode->right = newNode;
        	currNode = currNode->right;
        	i++;
        }
        else{
        	currNode = check;
        	stac.pop();
        }
   	 }
   	 cout << currNode->data;
   }
}
int main(){
	int arr[] = { 30,20,10,15,25, 40, 50, 45};
	int len = sizeof(arr)/sizeof(int);
    generateBST(arr, len);

	return 0;
}
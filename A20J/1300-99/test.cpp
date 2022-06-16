#include<iostream>

using namespace std;

int main(){
	int arr[5] = {1,2,3,4,4};
	printf("%d %p %p %p",arr,&arr[0],arr,&arr);
	return 0;
}
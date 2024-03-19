#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int arr[8] = {31,10,3,20,11,13,5,12};
void swap(int a,int b){
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}
int parent(int i){return (i/2)-1;}
int* heapify(int* arr,int h){
	h--;
	if(parent(h) >= 0){
		if(arr[h]<arr[parent(h)]){swap(h,parent(h));}
		heapify(arr,h);
	}
}
void main(){
	heapify(arr,8);
	heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
        heapify(arr,8);
	heapify(arr,8);
	heapify(arr,8);
	heapify(arr,8);
	int i = 0;
	for(i;i<8;i++){
		printf("%d ",arr[i]);
	}
}

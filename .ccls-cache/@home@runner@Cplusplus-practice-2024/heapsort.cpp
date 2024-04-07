#include <iostream>
#include <cmath>
using namespace std;

void heapify(int arr[], int n, int i){
  int largest = i;
  int left = floor(2*i) ;
  int right = floor(2*i +1);
  if(left < n && arr[left] > arr[largest]){
    largest = left;
    
  }
  if(right < n && arr[right] > arr[largest])
    largest = right;
  if(largest != i){
    swap(arr[i], arr[largest]);
    heapify(arr,n,largest);
    
  }
  
}

void heapsort(int arr[], int n){
  for(int i = n/2 -1; i>=0; --i){
    heapify(arr,n,i);
    
  }
  for(int i = n-1; i>0; --i){
    swap(arr[0], arr[i]);
    heapify(arr,i,0);
    
  }
  
}

void printArray(int arr[], int n){
  for(int i =0; i<n; ++i){
    cout << arr[i] << " ";
    
  }
  cout << endl;
}

void swap(int &a, int &b){
  int temp  = a;
  a = b;
  b = temp;
}

int main(){
  int arr[] = {12,11,13,5,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  heapsort(arr,n);
  cout << "Sorted array is : ";
  printArray(arr,n);
  return 0;
}
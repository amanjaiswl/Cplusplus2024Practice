#include <iostream>
using namespace std;

void radixSort(int arr[], int n){
  int max= arr[0];
  for(int i= 1; i<n;++i){
    if(arr[i] > max)
      max = arr[i];
      
  }
  }
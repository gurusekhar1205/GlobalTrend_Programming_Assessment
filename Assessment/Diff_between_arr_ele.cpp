#include<bits/stdc++.h> 
using namespace std;
 int findmax_diff(int arr[],int n){
 int min_element=arr[0];
 int max_diff=arr[1]-arr[0];
 for(int i=0;i<n;i++){
    if(arr[i]<min_element){
        min_element=arr[i];
    }
    max_diff=max(max_diff,arr[i]-min_element);

 }
return max_diff;
   
 }
int main(){
    int n=5;
    int arr[]={1,4,8,4,9};
   
    int max_diff=findmax_diff(arr,n);
    cout<<" maximum difference between any two elements in the array is " <<max_diff<<endl;
}
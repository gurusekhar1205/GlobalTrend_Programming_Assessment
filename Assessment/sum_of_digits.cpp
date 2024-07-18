#include<iostream>
using namespace std;
int sumOfDigits(int n){
    int sum=0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    return sum;

}
int main(){
    int n=4567;
    
    int digitSum=sumOfDigits(n);
    cout<<" the sum of the digits of the number :"<<digitSum;

    return 0;
}
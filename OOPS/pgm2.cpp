//bubble sort
#include <iostream>
using namespace std;
int main(){
    int arr[1000]={10,8,2,3,1,4};
    int n = 6;
    cout<<"for descending order : "<<endl;
    for(int i=0; i<n-1;i++){
    for(int j=0; j<n-1;j++){
        if(arr[j]<arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<"For ascending order : "<<endl;
    for(int i=0; i<n-1;i++){
    for(int j=0; j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
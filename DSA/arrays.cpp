#include<iostream>
using namespace std;
// selection sort 
void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<=n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[i],arr[min] );
    }
}
int smallest(int arr[],int n){
    sort(arr,n);
    cout<<arr[1]<<endl;
}


void rotate(int arr[],int n,int d){
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<=n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<endl;
    }
    smallest(arr,n);


}




    


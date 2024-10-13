//array sorted or not
#include<iostream>
using namespace std;
bool binary(int arr[],int n){// n = size
    if(n==0||n<2){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool rest=binary(arr+1,n-1);
        return rest;
    }

}
int main(){
    int arr[5]{2,4,6,8,9};
    int n=5;
    bool ans=binary(arr,n);
    if(ans){
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"not"<<endl;
    }   
    return 0;
    
}

// linear search
#include<iostream>
using namespace std;
int linear(int arr[],int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        bool rest=linear(arr+1,size-1,key);
        return rest;
    }
}


int main(){
    int arr[5]={3,7,4,5,3};
    int size=5;
    int key=5;
    bool print=linear(arr,size,key);
    if(print){
        cout<<"present"<<endl;
    }
    else{
        cout<<"not"<<endl;
    }
    return 0;
}


// binar search   bninary search
#include<iostream>
using namespace std;
int binary(int*arr,int s,int e,int key){// s==0 and e==last index or lenght
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    if(key>arr[mid]){
        return binary(arr,mid+1,e,key);// as by changing s and e ,,mid will change whcih is main aim of binary search 
    }
    else{
        return binary(arr,s,mid-1,key);
    }
}
int main(){
    int arr[5]={4,6,22,89,3};
    int key=89;
    bool ans=binary(arr,0,4,key);
    if(ans){
        cout<<"present"<<endl;
    }
    else{
        cout<<"not"<<endl;
    }
    return 0;
    
}
// merge sort
#include<iostream>
using namespace std;

void merge(int*arr,int s,int e,int mid){
    mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    // copying values from left and right arrays to new array first and second to creat a sorted merged array
    int *first=new int[len1];
    int *second=new int[len2];
    int mainarrindex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainarrindex++];
    }
    mainarrindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainarrindex++];
    }
    //now merging
    int index1=0;
    int index2=0;
    mainarrindex=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainarrindex++]=first[index1++];
        }
        if(first[index1]>second[index2]){
            arr[mainarrindex++]=second[index2++];
        }
    }
    while(index1<len1){// for left over elements
        arr[mainarrindex++]=first[index1++];
    }
    while(index1<len2){
        arr[mainarrindex++]=second[index2++];
    }
}
void mergesort(int *arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e,mid);
}
int main(){
    int arr[5]={4,6,3,7,9};
    mergesort(arr,0,4);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<endl;

    }
    return 0;

    
}
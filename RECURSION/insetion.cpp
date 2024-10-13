#include<iostream>
#include<vector>
using namespace std;

// here we swap the 

void insertion(vector<int>&arr,int n){
    for(int i=1;i<=n;i++){// assuming first element is already sorted
        int temp=arr[i];
        int j=i-1;
        for(j;j>=0;j--){// comparing ith element with previous numbers so we run a loop backwards
            if(arr[j]>temp){
                arr[j+1]=arr[j];// the prevous elements are incremented by 1

            }
            else{
                break;// increment i loop
            }
        }
        arr[j+1]=temp;// so old position of prevos numer taken by new number from unsorted part which we compared
    }
}
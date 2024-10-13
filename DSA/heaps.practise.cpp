#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size=0;
        arr[0]=-1;
    }
    void insert(int val){// inserted at end
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
        }
    }
    void deletion(){// inserteda at starting 
        if(size==NULL){
            return;
        }
        arr[size]=arr[1];
        size--;

        int i=1;
        while(i<size){
            int rightChild=2*1+1;
            int leftChild=2*i;
            if(rightChild<size && arr[i]<arr[rightChild]){
                swap(arr[i],arr[rightChild]);
                i=rightChild;
            }
            
            if(leftChild<size && arr[i]<arr[leftChild]){
                swap(arr[i],arr[leftChild]);
                i=leftChild;
            }
            else{
                return;
            }

        }
    }
};

// heapify


void heapify(int arr[],int i,int n){//arr//largest//size
    if(arr==NULL){
        return;
    }
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
void buildheap(int arr[],int N){
    for(int i=(N/2)-1;i>=0;i++){
        heapify(arr,i,N);
    }

}
void print(int arr[],int N){
    for(int i=0;i<=N;i++){
        cout<<arr[i]<<endl;
    }

}
int main(){
    heap h;
    h.insert(5);
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    int arr[]={1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int N=sizeof(arr)/sizeof(arr[0]);
    buildheap(arr,N);
    print(arr,N);


}





#include<iostream>

using namespace std;

// class heap{
//     public:
//     int size;
//     int arr[100];
//     heap(){
//         size=0;
//         arr[0]=-1;
//     }
//     void insert(int val){
//         size=size+1;
//         int index=size;
//         arr[index]=val;

    
//         while(index>1){
//             int parent=index/2;
//             if(arr[parent]<arr[index]){
//                 swap(arr[parent],arr[index]);
//                 parent=index;
//             }
//             else{
//                 return;
//             }

//         }
//     }
//     void deleting(){
//         if(size==0){
//             return;
//         }
//         arr[1]=arr[size];
//         size--;
//         while(size>1){
//             in
//         }

//     }
// }





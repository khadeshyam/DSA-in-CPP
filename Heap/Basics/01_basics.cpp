#include<iostream>
using namespace std;

//1-based indexing is used here in heaps
//Its a MAX-HEAP

    
void heapify(int arr[],int n,int i){
   int largest=i;
   int left = 2*i;
   int right = 2*i+1;
   
   if(left<n && arr[left]>arr[largest]){
      largest = left;
   }
   if(right<n && arr[right]>arr[largest]){
      largest = right;
   }
   //check if largest is updated
   if(largest !=i){
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest);
   }
  
}

class Heap{

   public:
     int arr[100];
     int size;

     Heap(){
        arr[0] = -1;
        size = 0;
     }

     void insert(int val){

        size = size +1;
        int index = size;
        arr[index] = val;

        while(index!=1){
            int parentIndex = index/2;
 
            if(! (arr[parentIndex]>arr[index]) ){
                swap(arr[parentIndex],arr[index]);
                index=parentIndex; 
            }else{
                return;
            }
        }
     }
      
    //deletion => only for root node 
    void deleteRoot(){

         if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
         }

        // STEP-1 : swap or copy first node (root) and last node
         swap(arr[1],arr[size]);   

        // STEP-2 : remove last node
         size--;

        //STEP-3 : propogate root to its correct position in Max-Heap
         heapify(arr,size,1);
    }

    void print(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(70);
    h.print();
    int arr[6] = {-1,54,55,53,50,52};
    int n = 5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}








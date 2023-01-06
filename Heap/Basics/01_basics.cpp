#include<iostream>
using namespace std;

//1-based indexing is used here in heaps

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

     void print(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
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

}








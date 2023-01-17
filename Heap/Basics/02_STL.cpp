
// C++ program to demonstrate the use of priority_queue
#include <iostream>
#include <queue>
using namespace std;
 
// driver code
int main()
{
    int arr[6] = { 10, 2, 4, 8, 6, 9 };
    int n=sizeof(arr)/sizeof(arr[0]);
 
    // defining priority queue
    //max-heap
    priority_queue<int>mx;
    //min-heap
    priority_queue<int,vector<int>,greater<int>>mn;

    // printing array
    cout << "Array: ";

    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;

    // pushing array sequentially one by one
    for(int i=0; i<n; i++){
       mx.push(arr[i]);
       mn.push(arr[i]);
    }
   
    // printing priority queue
    cout << "Max Heap :";
    while(!mx.empty()){
        cout<<mx.top()<<" ";
        mx.pop();
    }
    cout<<endl;

    cout<<"size of min queue is : "<<mn.size()<<endl;

    cout << "Min Heap :";    while(!mn.empty()){
       cout<<mn.top()<<" ";
        mn.pop();
    }
 
    return 0;
}
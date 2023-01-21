#include<bits/stdc++.h>
using namespace std;
template <typename T>

class Graph{
  public:
    unordered_map<T,list<T>>adj;

    void addEdge(T u,T v,bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        } 
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout << j <<", ";
            }
            cout<<"\n";
        }
    }

};
int main(){
  int n;
  cout<<"Enter the no. of nodes"<<endl;
  cin>>n;

  int m;
  cout<<"Enter the no. of edges"<<endl;
  cin>>m;
  
   Graph<int> g;
   cout<<"Enter the no. of edge pairs"<<endl;
  for(int i=0;i<m;i++){
     int u,v;
     cin>>u>>v;
     //creating an undirected graph
     g.addEdge(u,v,0);
  }
  //print graph
   g.printAdjList();

  return 0;
}
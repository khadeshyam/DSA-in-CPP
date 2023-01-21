#include<bits/stdc++.h>
using namespace std;

int main(){
   int m,n;
  //n => no. of nodes m =>no. of edges 

  cout<<"Enter the number of the vertices (nodes) and edges respectively\n";
  cin>>n>>m;

  vector<pair<int,int>> edges;
  vector<int> adj[n+1];

  cout<<"Enter the edges pairs\n";

  for(int i= 1;i<=m;i++){
     int u,v;
     cin>>u>>v;
     edges[i].first=u;
     edges[i].second=v;

  }




  return 0;
}
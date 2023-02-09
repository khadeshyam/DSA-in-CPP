//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    unordered_map <int,bool> visited;
    // Fudfsion to detect cycle in an undirected graph.
    bool dfsCycle(int vertex,int parent, vector<int> adj[]){
            visited[vertex] = true;
            
           for(auto i : adj[vertex]){
                     if(visited[i] == true && i!= parent){
                          return true;
                        }
                     else if(visited[i] == false){
                          
                          return dfsCycle(i,vertex,adj);
                     }
                 }
           
           
        return false;
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        for(int i=0;i<V;i++){
              if(visited[i] == false){
                    if(dfsCycle(i,-1,adj)){
                         return true;
                    }
              }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
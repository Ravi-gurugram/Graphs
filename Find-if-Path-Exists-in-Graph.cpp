class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {  

        if(source==destination)
           return true ;
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int node=edges[i][0] ;
            int dest=edges[i][1] ;
            adj[node].push_back(dest) ;
            adj[dest].push_back(node) ;

        }
      vector<bool>visit(n,0) ;

      
      queue<int>q;
      q.push(source) ;
         visit[source]=1;
         while(!q.empty()){
              int node= q.front();q.pop() ;
              for(int i=0;i<adj[node].size();i++){
                if(adj[node][i]==destination)
                   return true ;

                if(!visit[adj[node][i]])
                   {
                    visit[adj[node][i]]=1;
                    q.push(adj[node][i]) ;
                   }
                else
                  continue ;
            
              }



         }


return false ;








    }
};
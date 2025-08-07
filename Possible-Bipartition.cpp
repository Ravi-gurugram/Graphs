class Solution {
public:

bool check(vector<int>adj[] , int node , vector<int>&color){
    color[node]= 1;
     queue<int>q;
     q.push(node) ;
     while(!q.empty()){
          int node= q.front() ; q.pop() ;
          for(int i=0;i<adj[node].size();i++){
            if(color[adj[node][i]]==-1){
                color[adj[node][i]]= !color[node] ;
                q.push(adj[node][i]) ;

            }
            if(color[adj[node][i]]==color[node])
               return false ;
          }
     }
    return true ;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
           int N= n ;
            vector<int>adj[N+1] ;
            for(auto &v: dislikes  ){
                adj[v[0]].push_back(v[1]) ;
                adj[v[1]].push_back(v[0]) ;

            }
      
      vector<int>color(n+1,-1) ;
      for(int i=1;i<=n;i++){
           if(color[i]==-1&&!check(adj,i,color))
               return false ;
      }
  return true ;

    }
};
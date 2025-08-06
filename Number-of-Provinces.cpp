class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
    vector<int>adj[n] ;
    vector<bool>visit(n,0) ;
       for(int i=0;i<n;i++){
        for(int j=0;j<isConnected[i].size();j++) {
            if(i==j)
              continue ;
            else if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ;
                }
               
       }  }
       queue<int>q ;
      int count=0;
     for(int i=0;i<n;i++){
        if(!visit[i])
           
        {   count++ ;
            q.push(i) ;
            visit[i]=1 ;
            while(!q.empty()){
                int node = q.front() ; q.pop();
                for(int j=0;j<adj[node].size();j++){
                  if(!visit[adj[node][j]])
                      {
                        q.push(adj[node][j]) ;
                            visit[adj[node][j]]=1 ;
                      }
                }

            }
        }
     }

  return count ;







    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int size=n+1;
       vector< vector<pair<int,int>>>adj(size) ;
        for(int i=0;i<times.size();i++){
           adj[ times[i][0]].push_back({times[i][1],times[i][2]}) ;
        }
        vector<int>dist(n+1,INT_MAX) ;
        vector<bool>visited(n+1,0) ;
        visited[0]=1;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        dist[0]=0;
        dist[k]=0;
          p.push({0,k}) ;
        while(!p.empty()){
            int node= p.top().second;
             p.pop() ;
            if(visited[node]==1){
               continue ;
            }

            for(int j=0;j<adj[node].size();j++){
                 int v= adj[node][j].first ;
                 int w= adj[node][j].second ;
                  
                 
                 if(dist[node]+w<dist[v]){
                    dist[v]= dist[node]+w;
                    p.push({dist[v],v}) ;
                 }
            }
        }
       int maxi=INT_MIN ;

     for(int i=1;i<=n;i++){
        
        if(dist[i]==INT_MAX)
           return -1;
        maxi= max(maxi,dist[i]) ; 
     }
return maxi ;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       int n= numCourses ;
           vector<vector<int>>adj(n) ;
           
        vector<int>Indeg(n,0) ;
        for(int i=0;i<prerequisites.size();i++){
            Indeg[prerequisites[i][0]]++ ;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]) ;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!Indeg[i])
               q.push(i) ;
        }
        vector<int>ans ;
        while(!q.empty()){
            int node= q.front(); q.pop();
            ans.push_back(node);
            for(auto &v: adj[node]){
                 Indeg[v]--;
                 if(!Indeg[v])
                    q.push(v ) ;

            }
        }
        if(n==ans.size())
         return ans ;
    return {} ;
    }
};
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V=rooms.size();
      queue<int>q;
      vector<int>visited(V,0);
      q.push(0);
      visited[0]=1;
      while(!q.empty()){

       int node=q.front();
       q.pop() ;
       for(int i=0;i<rooms[node].size();i++){
           
             if(!visited[rooms[node][i]]) {
             q.push({rooms[node][i]}) ;
             visited[rooms[node][i]]=1;
             }

       }

      }
       for(int j=0;j<V;j++){

        if(!visited[j])
        return false ;
       }

    return true ;



    }
};
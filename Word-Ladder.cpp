class Solution {
public:
void wordMatch(string node, unordered_map<string,bool>&visited,queue<string>&q ){
   for(int i=0;i<node.size();i++){
       char ch= node[i] ;
      for(int j=0;j<26;j++){
        node[i]='a' + j ;
        if(visited.count(node)&&!visited[node]){
            q.push(node) ;
            visited[node]= true;
        }  
      }  node[i]=ch;
   }



}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
     
     unordered_map<string,bool>visited ;
     for(string word:wordList)
       visited[word]= false ;
queue<string> q;
     int level=0;
     q.push(beginWord) ;
     while(!q.empty()){
          level++;
          int size= q.size();
          while(size--){

            string node= q.front();q.pop() ;
            if(node==endWord)
              return level ;
          wordMatch(node,visited,q) ;

          }



     }

return 0;
    }
};
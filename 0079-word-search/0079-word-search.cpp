class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i,int j,int index,vector<vector<bool>> &visited){
        int n = board.size();
        int m = board[0].size();
        
        if(index == word.size()){
            return true;
        }
        if(i>=n or j>=m or i<0 or j<0){
            return false;
        }
        if(board[i][j] != word[index])
           return false;

        if(visited[i][j]){
            return false;
        }

        visited[i][j] = true;   // mark this true, 
        bool found = 
                  solve(board,word,i,j+1,index+1,visited) ||

        //move down 
                   solve(board,word,i+1,j,index+1,visited) || 
        
        //move up
                   solve(board,word,i-1,j,index+1,visited) ||

        //left
                   solve(board,word,i,j-1,index+1,visited);
        //backtrack again 

        visited[i][j] = false;
        return found;



        
    }
    bool exist(vector<vector<char>>& board, string word) {
         int n = board.size();
        int m = board[0].size();       
        vector<vector<bool>> visited(n,vector<bool>(m,false));   //this part see this 
            for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(solve(board, word, i, j, 0, visited)) {
                    return true;
                }

            }
        }

        return false;
    }
};
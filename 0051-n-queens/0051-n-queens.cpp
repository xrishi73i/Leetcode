class Solution {
public:   bool canPlace(int r,int c,int n,vector<string> &v){
        int i= r;
        int j = c;
        // there are three direction in which we will check 
        // dir 1 , upward ,vertical 
        while(i>=0){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
        }
        //diagonal 1 left 
         i= r;
        j = c;
        while(i>=0 and j>=0){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
         i= r;
         j = c;
        //diagonal right side 
        while(i>=0 and j<n){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;

    }
    void solve(vector<vector<string>>&ans,int n,int i,vector<string> &v){
        //base case 
        if(i==n){
            ans.push_back(v);
            return;
        }
        //for row 
        for(int j=0;j<n;j++){
            if(canPlace(i,j,n,v)){
                v[i][j] = 'Q';
                solve(ans,n,i+1,v);
                v[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string >v(n,string(n,'.'));
        
        solve(ans,n,0,v);
        return ans;
    }
   
};
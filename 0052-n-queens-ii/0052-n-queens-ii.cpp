class Solution {
public:

    bool canPlace(int r, int c, int n, vector<string>& v) {

        int i = r;
        int j = c;

        // Vertical
        while(i >= 0) {
            if(v[i][j] == 'Q')
                return false;

            i--;
        }

        // Upper-left diagonal
        i = r;
        j = c;

        while(i >= 0 && j >= 0) {
            if(v[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // Upper-right diagonal
        i = r;
        j = c;

        while(i >= 0 && j < n) {
            if(v[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    int solve(int n, int i, vector<string>& v) {

        // One complete valid board
        if(i == n) {
            return 1;
        }

        int paths = 0;

        // Try every column
        for(int j = 0; j < n; j++) {

            if(canPlace(i, j, n, v)) {

                // Choose
                v[i][j] = 'Q';

                // Explore
                paths += solve(n, i + 1, v);

                // Undo
                v[i][j] = '.';
            }
        }

        return paths;
    }

    int totalNQueens(int n) {

        vector<string> v(n, string(n, '.'));

        return solve(n, 0, v);
    }
};
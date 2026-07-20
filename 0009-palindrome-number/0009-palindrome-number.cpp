class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long rev =0;
        int i =0;
        int n =x;
        while(n != 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n = n / 10;
        }

        return rev == x;
        }
    };
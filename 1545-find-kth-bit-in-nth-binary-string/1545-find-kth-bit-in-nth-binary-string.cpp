class Solution {
public:
    char findKthBit(int n, int k) {

        if (n == 1 && k == 1) {
            return '0';
        }

        int mid = pow(2, n - 1);

        if (mid == k) {
            return '1';
        }

        if (k < mid) {
            return findKthBit(n - 1, k);
        }
        else {
            char s = findKthBit(n - 1, pow(2, n) - k);

            if (s == '0') {
                return '1';
            }
            else {
                return '0';
            }
        }
    }
};
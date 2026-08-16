class NumArray {
public:
  vector<int> p;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        p.resize(n);
       
        for (int i = 0; i < p.size(); i++) {
            sum += nums[i];
            p[i] = sum;
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return p[right];
        } else {
            return p[right] - p[left - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
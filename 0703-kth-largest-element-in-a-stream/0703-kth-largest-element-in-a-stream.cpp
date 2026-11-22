class KthLargest {
    template<typename T>
    using minHeap = priority_queue<T, vector<T>, greater<T>>;

public:
    minHeap<int>heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        //constructor 
        for(auto num:nums){
            heap.push(num);

        if(heap.size()>k){
            heap.pop();
        }

        
            
        }
        this->k = k;
    }
    
    int add(int val) {
        heap.push(val);

        if(heap.size()>k){
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
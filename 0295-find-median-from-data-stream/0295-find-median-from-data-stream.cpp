class MedianFinder {
public:
    template<typename T>
    using maxHeap_l = priority_queue<T>;

    template<typename T>
    using minHeap_r = priority_queue<T, vector<T>, greater<T>>;
    MedianFinder() {
        
    }
        maxHeap_l<int>left_max;
        minHeap_r<int>right_min;
    void addNum(int num) {


        if(left_max.empty() or num < left_max.top()){
            left_max.push(num);
        }else{
            right_min.push(num);
        }
        if(abs((int)left_max.size() - (int)right_min.size()) >1 ){
          //means lft incr by + 1. again
          right_min.push(left_max.top());
          left_max.pop(); 

        }else if(right_min.size() > left_max.size()){
            left_max.push(right_min.top());
            right_min.pop();
        }


    }
    
    double findMedian() {
        if(right_min.size() == left_max.size()){
            //even case 
            double ans = (right_min.top() + left_max.top()) /2.0;
            return ans;
        }else{
            return left_max.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
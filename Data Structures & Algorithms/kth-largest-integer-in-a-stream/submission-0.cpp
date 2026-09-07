class KthLargest {
public:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int k_;
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) { 
            pq.push(num);
            if (pq.size() > k) pq.pop(); 
        }
        k_ = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_) pq.pop();
        return pq.top();
    }
};

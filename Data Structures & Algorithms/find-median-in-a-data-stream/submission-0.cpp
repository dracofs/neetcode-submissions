class MedianFinder {
public:
    std::priority_queue<int, vector<int>, std::less<int>> lowerBound;
    std::priority_queue<int, vector<int>, std::greater<int>> upperBound;
    MedianFinder() { }

    void addNum(int num) {
        // at an arbitrary point, the size difference between heaps will be 1
        // we push to the smaller one.
        // if the difference is zero, we compare the element to the top element of the lowerbound heap, if its smaller we push to it, else we push to upper bound
        if (!upperBound.empty() && num > upperBound.top()) { upperBound.push(num); }
        else lowerBound.push(num);

        if (upperBound.size() > lowerBound.size() + 1) {
            int top = upperBound.top(); upperBound.pop();
            lowerBound.push(top);
        } else if (lowerBound.size() > upperBound.size() + 1) {
            int top = lowerBound.top(); lowerBound.pop();
            upperBound.push(top);
        }

    }
    
    double findMedian() {
        if (lowerBound.size() > upperBound.size()) {
            return lowerBound.top();
        } else if (upperBound.size() > lowerBound.size()) {
            return upperBound.top();
        } else {
            return (upperBound.top() + lowerBound.top()) / 2.0;
        }
    }
};

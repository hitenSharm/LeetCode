class MedianFinder {
private:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:
    //basically we need to maintain a maxheap and a minheap of with max size diff of 1
    //lets make a rule that if we have even numbers in the stream at any point both heaps shud have same amount of numbers
    //if we have odd numbers at any point max heap will have more numbers
    //max heap basically represents the left side of the array and  the min heap represents the right side
    //the largest from the max heap and the smallest from the min heap will give me the answer
    //whenever we have a new number we must decide wether it shud be on the left side (maxHeap) or the right side(min heap)

    MedianFinder() {

    }

    void addNum(int num) {
        if (maxHeap.size() == 0) {
            maxHeap.push(num);
            return;
        }
        if (num >= maxHeap.top()) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }

    double findMedian() {
        //cout<<minHeap.top()<<" "<<maxHeap.top()<<"\n";
        //cout<<minHeap.size()<<" "<<maxHeap.size()<<endl;
        if ((maxHeap.size() + minHeap.size()) % 2 != 0) {
            return maxHeap.top();
        }
        else
        {
            double t1=maxHeap.top()/2.0;
            double t2=minHeap.top()/2.0;
            //cout<<t1<<" "<<t2<<endl;
            return (t1+t2);            
        }
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
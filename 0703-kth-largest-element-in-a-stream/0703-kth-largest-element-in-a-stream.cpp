class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;

        // Add each number to the heap
        for (int num : nums) {
            minHeap.push(num);

            // If heap exceeds size k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        // If size exceeds k, remove the smallest (to maintain top k largest)
        if (minHeap.size() > size) {
            minHeap.pop();
        }

        // The top of min-heap is the k-th largest
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:
    int daysRequired(vector<int>& weights, int capacity) {
        int days = 1, load = 0;
        for (int weight : weights) {
            if (load + weight > capacity) {
                days++;
                load = weight;
            }
            else {
                load += weight;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int weight : weights) {
            high += weight;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int requiredDays = daysRequired(weights, mid);
            if (requiredDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
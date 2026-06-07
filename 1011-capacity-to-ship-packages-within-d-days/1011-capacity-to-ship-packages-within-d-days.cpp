class Solution {
public:
int function(vector<int>& weights, int capacity){
    int n = weights.size();
    int day= 1, load = 0;
    for (int i=0; i<n; i++){
        if (load + weights[i] > capacity){
            day= day +1;
            load = weights[i];
        }
        else {
            load += weights[i];
        }
    }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high =0;
        for (int weight : weights) {
            high += weight;
        }
                
        while (low<= high){
            int mid = low + (high-low)/2;
            int noofdays = function(weights, mid);
            if (noofdays<= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
            return low;
        }
};
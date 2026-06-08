class Solution {
public:
int splitarray(vector<int> &arr, int k) {
        int n = arr.size();
        int s = 1;
        long long array = 0;

        for (int i = 0; i < n; i++) {
            if (array + arr[i] <= k) {
                array += arr[i];
            }
            else {
                s++;
                array = arr[i];
            }
        }
        return s;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
         int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
         while (low <= high) {
            int mid = low + (high - low) / 2;

            int subarrays = splitarray(nums, mid);

            if (subarrays > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};

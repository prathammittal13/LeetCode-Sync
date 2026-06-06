class Solution {
public:
    int Flowers(vector<int>& bloomDay, int day, int k) {
        int cnt = 0;
        int noofB = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            }
            else {
                noofB += cnt / k;
                cnt = 0;
            }
        }
        noofB += cnt / k;
        return noofB;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long flowersNeeded = 1LL * m * k;
        if (flowersNeeded > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (Flowers(bloomDay, mid, k) >= m) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
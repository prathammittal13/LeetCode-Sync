class Solution {
public:
    long long canDistribute(vector<int>& candies, int mid) {
        long long children = 0;
        for (int pile : candies) {
            children += pile / mid;
            }
        return children;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = 0;
        for (int pile : candies)
            totalCandies += pile;
        if (totalCandies < k)
            return 0;
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canDistribute(candies, mid) >= k) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
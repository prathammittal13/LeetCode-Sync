class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long int maxFreq =0, l=0, r=0, total=0;
        for (int r=0; r<nums.size(); r++ ){
            total += nums[r];
            if((nums[r] * (r-l+1)) > total+k ){
                total -= nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r-l+1);
        }
    return maxFreq;
    }
};
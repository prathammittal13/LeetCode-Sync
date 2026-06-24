class Solution {
public:
    int storesRequired(vector<int>& quantities, int maxProducts) {
        int stores = 0;
        for (int q : quantities) {
            stores += ceil((double)q / maxProducts);
        }
        return stores;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int stores = storesRequired(quantities, mid);

            if (stores > n) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};
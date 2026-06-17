class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea=0;
        for (int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();
                int nse=i;
                int pse= st.empty() ? -1 : st.top();
                maxArea= max((heights[element]*(nse-pse-1)), maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element= st.top();
            st.pop();
            int nse=heights.size();
            
            int pse= st.empty() ? -1 : st.top();
            maxArea= max(maxArea, ((nse-pse-1)*heights[element]));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea=0;
        vector<int> pSum(m,0);
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] =='1' ) pSum[j]++;
                else pSum[j]=0;
            }
            maxArea= max(maxArea, largestRectangleArea(pSum));
        }
        return maxArea;
    }
};
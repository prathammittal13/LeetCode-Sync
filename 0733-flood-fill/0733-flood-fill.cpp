class Solution {
private: 
void  dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>& image, int newColor, int drow[], int dcol[], int init){
    int n= image.size();
    int m = image[0].size();
    ans[row][col]= newColor;
    for(int i=0; i<4; i++){
        int nrow= row + drow[i];
        int ncol= col+ dcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol]== init && ans[nrow][ncol]!= newColor){
            dfs(nrow, ncol, ans, image, newColor, drow, dcol, init);
        }
    }

}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m = image[0].size();
        int init= image[sr][sc];
        vector<vector<int>>ans = image;
        int drow[]={-1, 0, 1, 0};
        int dcol[]= {0, 1, 0, -1};
        dfs(sr, sc, ans, image, color, drow, dcol, init);
        return ans;
    }
};
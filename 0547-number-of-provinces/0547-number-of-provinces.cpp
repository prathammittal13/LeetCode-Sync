class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjList(V);
        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> visited(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adjList, visited);
            }
        }
        return count;
    }
};
class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& pathVisited) {

        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto neighbor : adj[node]) {

            if (!visited[neighbor]) {

                if (dfs(neighbor, adj, visited, pathVisited))
                    return true;
            }

            // Cycle found
            else if (pathVisited[neighbor]) {
                return true;
            }
        }

        // Remove node from current DFS path
        pathVisited[node] = 0;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Create adjacency list
        vector<int> adj[numCourses];

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        // Check every component
        for (int i = 0; i < numCourses; i++) {

            if (!visited[i]) {

                if (dfs(i, adj, visited, pathVisited))
                    return false;      // Cycle exists
            }
        }

        return true;    // No cycle
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> colour(n, 0);
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (colour[i]) {continue;}
            
            colour[i] = 1;
            for (q.push(i); !q.empty(); q.pop()) {
                int node = q.front();
                for (auto neighbour: graph[node]) {
                    if (!colour[neighbour]) {
                        colour[neighbour] = -colour[node];
                        q.push(neighbour);
                    }              
                    else if (colour[neighbour] == colour[node]) {
                        return false;
                    }
                }
                
            }
        }
        
        return true;
        
    }
};
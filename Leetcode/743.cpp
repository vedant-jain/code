class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>>& g, int src){
        int n = g.size();
        vector<int> ret(n, -1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<void>> q;
        q.push({0,src});

        while(!q.empty()){
            auto x = q.top(); q.pop();
            int c = x.first, v = x.second;
            
            if(ret[v] != -1) continue;
            ret[v] = c;
            for(auto p : g[v]) q.push({p.second + c, p.first});
        }

        return ret;
    }
    
    int networkDelayTime(vector<vector<int>>& a, int n, int k) {
        vector<vector<pair<int,int>>> g(n);
        
        for(int i=0; i<a.size(); i++){
            int u = a[i][0] - 1, v = a[i][1] - 1, c = a[i][2];
            g[u].push_back({v,c});
        }
        
        auto ret = dijkstra(g, k-1);
        int hi = 0;
        for(int i=0; i<n; i++){
            if(ret[i] == -1) return -1;
            hi = max(hi, ret[i]);
        }
        return hi;
    }
};
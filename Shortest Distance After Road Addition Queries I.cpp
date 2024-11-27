class Solution {
public:
    int bfs(int src,int dest,int n, vector<vector<int>>&adj){
        vector<int> dist(n, -1); // Distance array, -1 means not visited
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) { // If not visited
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if (v == dest) return dist[v]; // Early exit if destination is reached
                }
            }
        }
        return dist[dest];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n); //initialize adjacency list
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1); //Edge from i to i+1
        }
        //Each queries and a new node
        vector<int>ans;
        for(auto query:queries){
            int u = query[0], v=query[1];
            adj[u].push_back(v);    //add a new edge
            ans.push_back(bfs(0, n-1, n, adj)); //compute the shortest path
        }
        return ans;
    }
};

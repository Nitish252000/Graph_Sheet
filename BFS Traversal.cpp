void bfs (int node, unordered_map<int,bool>&visited, vector<vector<int>> &adj, vector<int> &ans){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        // Traverse all neighbors of the frontNode
        for(auto i:adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int>ans;      // List to store BFS traversal
    unordered_map<int,bool>visited; // Map to track visited nodes
    //BFS traversal should start only from vertex 0
    if(!visited[0]){
        bfs(0, visited, adj, ans);
    }

    return ans;
}

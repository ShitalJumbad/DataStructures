bool util(int curr,vector<int> graph[], vector<int> &visited){
        if(visited[curr]==2) return false;
        if(visited[curr]==1) return true;
        visited[curr]=2;

        for(int i=0;i<graph[curr].size();i++){
            if(visited[graph[curr][i]]!=1){
                if(!util(graph[curr][i],graph,visited)) return false;
                visited[graph[curr][i]]=1;
            }
        }

        return true;
    }	

    bool canFinish(int vertices, vector<vector<int>>& edges) {
        vector<int> graph[vertices];
        vector<int> visited(vertices,0);

        for(int i=0;i<edges.size();i++)
            graph[edges[i][0]].push_back(edges[i][1]);

        for(int i=0;i<vertices;i++){
            if(visited[i]!=1){
                if(!util(i,graph,visited)) return false;
                visited[i]=1;
            }
        }

        return true;
    }

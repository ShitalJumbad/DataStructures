bool canFinish(int vertices, vector<vector<int>>& edges) {
        
        vector<int> count(vertices,0);
        vector<int> graph[vertices];
        vector<int> seq;

        for(int i=0;i<edges.size();i++){
            count[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
        }

        int cnt=0;
        int i=0;
        
        while(seq.size()!=vertices){
                cnt=0;
                for(int i=0;i<vertices;i++){
                    if(count[i]==0){
                        cnt++;
                        seq.push_back(i);
                        for(auto it=graph[i].begin();it!=graph[i].end();++it){
                            if(*it!=-1)
                            {                                
                                count[*it]--;
                            }
                            *it=-1;
                        }
                        count[i]=-1;
                    }
              }
            if(cnt==0) return false;
        }

        return true;     
        
  }

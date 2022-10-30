class Solution {
public:
    bool isSafe(int n, int m, int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(k+1)));
        
        queue<vector<int>> q;
        q.push({k,0,0});
        visited[0][0][k]=true;
        int res=0;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                int K=curr[0];
                int x=curr[1];
                int y=curr[2];
                if(x==n-1 && y==m-1){
                    return res;
                }
                for(int i=0;i<4;i++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(isSafe(n,m,newX,newY)==false){
                        continue;
                    }
                    if(grid[newX][newY]==1 && K>0 && visited[newX][newY][K-1]==false){ // if obstacle, use K
                        visited[newX][newY][K-1]=true;
                        q.push({K-1,newX,newY});
                    }
                    if(!visited[newX][newY][K] && grid[newX][newY]==0){
                        visited[newX][newY][K]=true;
                        q.push({K,newX,newY});
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
int vis[10000][10000];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool valid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    if(vis[i][j]==1){
        return false;
    }
    return true;
}
void dfs(int s ,int d ,int n,int m,vector<vector<char>>& grid){
    
    vis[s][d]=1;
    for(int i=0;i<4;i++){
        int nx=s+dx[i];
        int ny=d+dy[i];
        if(valid(nx,ny,n,m) && grid[nx][ny]=='1'){
            dfs(nx,ny,n,m,grid);
        }
    }
    
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //so i think we basically count the no. of connected components with 1s
        int n=grid.size();
        if(!n){
            return 0;
        }
        int m=grid[0].size();
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return ans;
    }
};

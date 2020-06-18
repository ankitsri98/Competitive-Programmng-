int vis[60][60];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool valid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m ){
        return false;
    }    
    if(vis[i][j]==1){
        return false;
    }
    return true;
}
int dfs(int i,int j,int n,int m,vector<vector<int>>& grid){

    vis[i][j]=1;
    int ans=1;
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(valid(nx,ny,n,m) && grid[nx][ny]==1){
            //cout<<nx<<" "<<ny<<endl;
            ans+=dfs(nx,ny,n,m,grid);
        }   
    }
    return ans;
}
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(vis,0,sizeof(vis));
        int f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    f=max(f,dfs(i,j,n,m,grid));
                }
            }
        }
        return f;
    }
};

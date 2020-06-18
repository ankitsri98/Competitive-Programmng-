int vis[60][60];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool valid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    if(vis[i][j]==1){
        return false;
    }
    return true;
}
void dfs(int s ,int d ,int n,int m,vector<vector<int >>& grid,int x,int y){
    
    grid[s][d]=x;
    vis[s][d]=1;
    for(int i=0;i<4;i++){
        int nx=s+dx[i];
        int ny=d+dy[i];
        if(valid(nx,ny,n,m) && grid[nx][ny]==y){
            dfs(nx,ny,n,m,grid,x,y);
        }
    }
    
}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(vis,0,sizeof(vis));
        int n=image.size();
        int m=image[0].size();
        int y=image[sr][sc];
        dfs(sr,sc,n,m,image,newColor,y);
        return image;
    }
};

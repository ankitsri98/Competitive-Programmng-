int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
bool valid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=4;
                    int c=0;
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(valid(nx,ny,n,m) && grid[nx][ny]==1){
                            c++;
                        }
                    }
                    ans=ans-c;
                }
            }
        }
        return ans;
    }
};

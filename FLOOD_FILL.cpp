Largest Piece

Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. 
Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

Constraints :
1<=N<=50

Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake

Output Format :
Size of the biggest piece of '1's and no '0's

Sample Input :
2
11
01

Sample Output :
3


#include<bits/stdc++.h>
using namespace std;
int visited[NMAX][NMAX];
int cx[]={0,0,-1,1};//STORES ALL DIRECTIONS 
int cy[]={1,-1,0,0};

int outside(int i,int j,int n,int m)//CHECKS IT INDEX FALL OUTSIDE THE BOARD
{
    if(i>=0&&j>=0&&i<n&&j<n)
        return 1;
    else return 0;
}

int dfs(char cake[NMAX][NMAX],int i,int j,int n)//MAIN INPUT IS I AND J ...BELOW CODE CHECKS IN 4 DIRECTION AND IT IS RECURSION 
    //BELOW CODE ...FOR  ANY PARTICULAR I AND J (0,0) WHOLE FOR LOOP RUNS THAT IT CHECKS IN ALL 4 DIR' ...
    //FOE EX- 1ST DIRECTION IT GET 1 AND DFS GET CALLED THEN FOR THAT INDEX IF ITS NOT VISITED , THEN FOR THAT INDEX TOO ALL 4 DIR' WILL BE CHECKED
    //IT MEANS THAT IT CARRIES ON WHEN IT GET 1 ...MEANS FROM ANY POSITION IT TRIES TO GO IN MAX FEASIBLE DISTANCE...
    //FURTHER WHEN ALL THE CALLS GET CALLED THEN DFS GET RETURNED 
    //FOR X AND Y WHEN GET CALLED IN DFS IN LINE-31 ... FOR THAT X Y ALSO ALL 4 DIR' ARE CHECKED
{
    //cout<<i<<" came "<<j<<endl;
    if(visited[i][j]==1)//NOT TO STAND HERE AND MOVE BACKWARD FROM WHERE U CAME
        return 0;
    visited[i][j]=1; //NEW POSITION WITH CONDITION SATISFIED IS MARKED VISITED
    int count=1;    //FOR EVERY CALL THIS COUNT 1 IS MAINTAINED SO THAT INCREMENT IS DONE WHENEVER NEEDED
    
    for(int k=0;k<4;k++)//TRIES ALL 4 POSITIONS 
    {
        int x=i+cx[k];
        int y=j+cy[k];
       // cout<<x<<"  all "<<y<<endl;
        if(outside(x,y,n,n) && cake[x][y]=='1')//CHECKS OUTSIDE BOUNDARY AND ,=MAIN CONDITION
        {
            //cout<<x<<" in "<<y<<endl;
            count+=dfs(cake,x,y,n);
        }
    }
    return count;
}
int solve(int n,char cake[NMAX][NMAX])
{
	memset(visited,0,sizeof(visited));
    int maximise=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]=='1' && !visited[i][j])//HAR US INDEX PAR JAKAR HUM DEKHENGE KI US INDEX SE MAX LENGTH KAHAAN TAK MIL SAKTI HAI
            {
                maximise=max(maximise,dfs(cake,i,j,n));//COZ HAR INDEX SE MILNE WAALI LENGTH KA MAX VALUE CHAHIYE
            }
        }
    }
    return maximise;
}

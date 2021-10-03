class Solution {
    public int longestIncreasingPath(int[][] a) {
        int n=a.length;
        int m=a[0].length;
        int temp[][]=new int[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                temp_max=0;
                ans=Math.max(ans,dfs(a,i,j,1,temp));
            }
        }
        return ans;
    }
    public int dx[]={-1,0,0,1};
    public int dy[]={0,-1,1,0};
    public int dfs(int a[][],int x,int y,int dis,int temp[][]){
        if(temp[x][y]!=0) return temp[x][y];
        int max=1;
        for(int k=0;k<4;k++)
        {
            int xi=x+dx[k];
            int xj=y+dy[k];
            if(isSafe(xi,xj,a.length,a[0].length)&&a[xi][xj]>a[x][y])
            {
                max=Math.max(max, 1+dfs(a,xi,xj,dis+1,temp));
            }
        }
        temp[x][y]=max;
        return temp[x][y];
    }
    public boolean isSafe(int i,int j,int n,int m){
        return i>-1&&i<n&&j>-1&&j<m;
    }
    public int ans=0;
    public int temp_max=0;
 
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        int tm=0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t= q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+delrow[i];
                int ncol= c+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && grid[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    grid[nrow][ncol]=2;
                    fresh--;
                }
            }
        }

        if(fresh>0)return -1;
        return tm;


        
    }
};
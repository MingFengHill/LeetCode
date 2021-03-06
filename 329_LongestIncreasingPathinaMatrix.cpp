class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        if(matrix.size()==0||matrix[0].size()==0)
            return res;
        int row = matrix.size(), column = matrix[0].size();
        //如何初始化vector的二维数组
        //注意：这道题不用记录已经访问过的路径，因为题目要求是递增序列，已经访问过的路径肯定不能再访问了！！！
        vector<vector<int>> dp(row, vector<int>(column, -1));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                int localMax = dfs(matrix,dp,i,j);
                res = res>localMax?res:localMax;
            }
        }
        return res;
    }

private:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int row,int column)
    {
        int cur = matrix[row][column];
        //访问当前节点
        int down=1,up=1,left=1,right=1;
        //分别向上下左右四个方向遍历
        if((row+1)<matrix.size()&&matrix[row+1][column]>cur)
        {
            if(dp[row+1][column]!=-1)
                down += dp[row+1][column];
            else
                down += dfs(matrix,dp,row+1,column);
        }
        if((row-1)>=0&&matrix[row-1][column]>cur)
        {
            if(dp[row-1][column]!=-1)
                up += dp[row-1][column];
            else
                up += dfs(matrix,dp,row-1,column);
        }
        if((column+1)<matrix[0].size()&&matrix[row][column+1]>cur)
        {
            if(dp[row][column+1]!=-1)
                right += dp[row][column+1];
            else
                right += dfs(matrix,dp,row,column+1);
        }
        if((column-1)>=0&&matrix[row][column-1]>cur)
        {
            if(dp[row][column-1]!=-1)
                left += dp[row][column-1];
            else
                left += dfs(matrix,dp,row,column-1);
        }
        dp[row][column] = max(max(down,up),max(right,left));
        return dp[row][column];
    }
};
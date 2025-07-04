class Solution {
public:
    int check(vector<vector<char>> &board,string word,int idx,int x,int y){
        //move up
        if (idx == word.length()) return idx;

        char temp = board[x][y];
        board[x][y] = '*';
        int maxIdx=idx;
        if(y-1>=0 && board[x][y-1]==word[idx]){
           int res= check(board,word,idx+1,x,y-1);
           maxIdx=max(maxIdx,res);

        }
        //move down
        if(y+1<=board[0].size()-1 && board[x][y+1]==word[idx]){
            int res=check(board,word,idx+1,x,y+1);
            maxIdx=max(maxIdx,res);

        }
        //move left
        if(x-1>=0 && board[x-1][y]==word[idx]){
            int res=check(board,word,idx+1,x-1,y);
            maxIdx=max(maxIdx,res);

        }
        if(x+1<=board.size()-1 && board[x+1][y]==word[idx]){
            int res=check(board,word,idx+1,x+1,y);
            maxIdx=max(maxIdx,res);

        }
        board[x][y] = temp; // restoring the value
        return maxIdx;

    }
    bool exist(vector<vector<char>>& board, string word) {
        // bool result=false;
        vector<int> dp;
        for(int x=0;x<board.size();x++){
            for(int y=0;y<board[0].size();y++){
                if(board[x][y]==word[0]){
                    int result=check(board,word,1,x,y);
                    dp.push_back(result);
                }
                
            }
        }
        for(int i:dp){
            if(i==word.length()){
                return true;
            }
        }
        return false;
        
    }
};
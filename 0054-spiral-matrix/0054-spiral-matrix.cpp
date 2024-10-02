class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(); //size of row
        int n=matrix[0].size(); //size of col
        vector<int>v;

        int minR=0; //minimum row
        int minC=0; //minimum col
        int maxR=m-1; //maximum row
        int maxC=n-1; //max col

        while((minR<=maxR) && (minC<=maxC)){
            //right 
            for(int i=minC;i<=maxC;i++){
                v.push_back(matrix[minR][i]);
            }
            minR++;

            if((minR>maxR) || (minC>maxC))break;
            //down
            for(int i=minR;i<=maxR;i++){
                v.push_back(matrix[i][maxC]);
            }
            maxC--;

           if((minR>maxR) || (minC>maxC))break;
            //left
            for(int i=maxC;i>=minC;i--){
                v.push_back(matrix[maxR][i]);
            }
            maxR--;

           if((minR>maxR) || (minC>maxC))break;
            //top
            for(int i=maxR;i>=minR;i--){
                v.push_back(matrix[i][minC]);
            }
            minC++;

        }

        return v;



        
    }
};
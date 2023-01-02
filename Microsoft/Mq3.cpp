// COMBINATION SUM WITH A TWIST

//Using Backtracking

class Solution {
public:

    void find(vector<vector<int>>& ans,vector<int>&comb,int start,int k ,int n){
        int sum = 0;
        //Base Case
         if( k == comb.size()){
            if(n == 0) ans.push_back(comb);
            return;
        }

        for(int i=start;i<=9;i++){
            comb.push_back(i);
            find(ans,comb,i+1,k,n-i);
            comb.pop_back();
        }
    }
      
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>comb;
        find(ans,comb,1,k,n);
        return ans;
    }
};
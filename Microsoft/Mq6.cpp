//SHORTEST UNSORTED CONTINIUOUS SUBARRAY

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int Max = INT_MIN;
        int Min = INT_MAX;
        int n = nums.size();
        
        //When array has only one element 
        if(n==1){
            return 0;
        }

        for(int i=0;i<n;i++){
            // for 1st element
            if(i==0){
                // Calculating max and min element
                if(nums[i]>nums[i+1]){
                    Max = max(Max,nums[i]);  
                    Min = min(Min,nums[i]);
                }
            }
            // for last element
            else if(i==n-1){
                if(nums[i]<nums[i-1]){
                     Max = max(Max,nums[i]);
                     Min = min(Min,nums[i]);
                }
            }
            else {
              if(nums[i]>nums[i+1] || nums[i]<nums[i-1]){
                Max = max(Max,nums[i]);
                Min = min(Min,nums[i]);
            }
            }
        }
        // When array is already sorted
        if(Max == INT_MIN || Min == INT_MAX){
            return 0;
        }

        //Find position of min (i) and max position (j)
        int i,j;
        for(i=0;i<n && nums[i]<= Min;i++);
        for(j=n-1;j>=0 && nums[j]>=Max;j--);

        //lenght between two indices
        return j-i+1;
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(1)
*/
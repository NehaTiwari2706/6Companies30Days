/* 
DELETION TO MAKE AN ARRAY DIVISIBLE

1) Find the greatest common divisor(gcd) of numsDivide 
2) sort the nums array 
3) Check if nums element is equal to gcd or is divisible by gcd.
4) Return minimum number of deletions


Time Complexity = O(n + m) where n is size of nums and m is size of numsDivide
Space Complexity = O(1)
 */
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        //Finding the greatest common divisor(gcd) of numsDivide 
        int gcd = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            int num = numsDivide[i];
            while(num > 0){
                int temp = gcd % num;
                gcd = num;
                num = temp;
            }
        }
        // sort the nums array 
        sort(nums.begin(),nums.end());
        //Check if nums element is equal to gcd or is divisible by gcd.
        for(int i=0;i<nums.size();i++){
            if(gcd % nums[i] == 0){
                //Return minimum number of deletions
                return i;
            }
        }
        // return -1 if deletion is not possible 
        return -1;
    }
};
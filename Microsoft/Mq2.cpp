/*  Rotate Function 

original array[] = {4,3,2,6}
F1(original array) = 4*0 + 3*1 + 2*2 + 6*3

upon 1 rotation = {6,4,3,2}
F2 = 6*0 + 4*1 + 3*2 + 2*3

What do we observe between F1 AND F2

i) We observe that we multiply each element of original array (except the last one) with one more than the previous time.
Earlier   4*0 + 3*1 + 2*2 + 6*3
Now       6*0 + 4*1 + 3*2 + 2*3

How we get from earlier to now 
     ( 4*0 + 3*1 + 2*2 + 3*6 ) + (4+3+2+6) - 6*4 = now
     now = earlier + sum - (last element * n)
     where n = size of array here n = 4
           sum = sum of original array elements. 
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    
        long sum = 0,original = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            original += i*nums[i];
        }
        
        long maximum = original;
        int n = nums.size();
        
        for(int i= n-1;i>=0;i--)
        {
            original += sum -(nums[i]*n);
            maximum = max(original,maximum);
        }
        return maximum;
    }   
};
     

     /*
     Time Complexity = O(n)
     Space Complexity = O(1)
     */

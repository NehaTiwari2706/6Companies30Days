// NUMBER OF PAIRS SATISFYING INEQUALITY

class Solution {
public:
    long long int count;

    // check Count whether the number of pairs satisfying both conditions.
    void checkCount(vector<int>& nums, int start,int mid,int end,int diff){
        int l = start, r = mid+1;

        while(l<=mid && r<=end){
            // after rearranging the given inequaity 
            // nums[l] <= nums[r]+ diff if this satisfies then count pairs and increment l else increment r
            if(nums[l] <= nums[r]+ diff){
                 count += end - r + 1;
                 l++;
            }
            else{
                r++;
            } 
        }
        // sort all values from start to end
        sort(nums.begin() + start, nums.begin() + end + 1);  // (Sort using two-pointers for better time complexity)
        return;
    }

    // Apply Merge Sort
    void mergesort(vector<int>& nums, int start,int end,int diff){
        if(start == end){
            return ;
        }
        int mid = (start+end)/2;
        mergesort(nums,start,mid,diff);
        mergesort(nums,mid+1,end,diff);

        checkCount(nums,start,mid,end,diff);
        return;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        //count will store the number of pairs that satisfy the conditions.
        count = 0;
        //nums will store the difference of nums1 and nums2
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            nums[i] = nums1[i] - nums2[i];
        }

        mergesort(nums,0,n-1,diff);
        return count;
    }
};

/*
Time Complexity = O(nlogn)
Space Complexity = O(1)
*/
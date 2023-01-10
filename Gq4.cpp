//Split Array into Consecutive Subsequences

class Solution {
public:
    bool isPossible(vector<int>& nums) {
          int n = nums.size();
        unordered_map<int, int> am, vm;
        for(int i=0; i<n; i++){
            am[nums[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(am[nums[i]]){
                // First check if it can fit into existing group
                if(vm[nums[i]]){
                    
                    vm[nums[i]]--;
                    vm[nums[i]+1]++;
                }
                // Then only check for the possibility of creating a new group
                else{
                    // Possible to create a new group
                    if(am[nums[i]+1] && am[nums[i]+2]){
                        am[nums[i]+1]--;
                        am[nums[i]+2]--;

                        vm[nums[i]+3]++;
                    }
                    // Not possible to create a new group
                    else {
                        return false;
                    }
                }
                // In each iteration, nums[i] is consumed, so its frequency is decreased always by 1
                        am[nums[i]]--;
            }

        }
        // Successfully divided the array according to the given constraints
        return true;
    }
};


/*
Time Complexity = O(n)
Space Complexity = O(n)
*/
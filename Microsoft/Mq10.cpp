/*   
LONGEST HAPPY PREFIX

Imgaine that we are given integer array including only 0-9,
A = [1,2,3,4,5,1,2,3],
find the longest matched prefix and suffix.

For one digits, we have 1 and 3.
For two digits. we have 12 and 23
For three digits, we have 123 and 123, matched!

Calculate the value of prefix and suffix at the same time.
Time Complexity = O(n)
Space Complexity = O(1)
*/
class Solution {
public:
    string longestPrefix(string s) {
        
        long l = 0, r = 0, mul = 1,len = 0 , mod = 1e9 + 7;

        for(int i = 0, j = s.size()-1; j>0 ; i++, --j){
            int first = s[i] - 'a';
            int last = s[j] - 'a';

            l = (l*26 + first)% mod;
            r = (r + mul*last)% mod;

            mul = mul*26 % mod;

            if(l == r){
                len = i + 1;
            }
        }
        return s.substr(0,len);
    }
};
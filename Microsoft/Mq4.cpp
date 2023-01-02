// Substrings containing all three Characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        // count will store the count of no. of substrings
        int count = 0;
        // initializing index of a,b and c by -1
        int indexA = -1, indexB = -1 , indexC = -1;
        
        //Traversing string s
        for(int i=0;i<s.size();i++){
            //if the character is a, b or c strore its recent index
            if(s[i]== 'a'){
                indexA = i;
            }
            else if(s[i] == 'b'){
                indexB = i;
            }
            else{
                indexC = i;
            }
            // if i is greater than 1 then update count
            if(i>1){
                int mini = min(indexA,indexB);
                count += min(mini,indexC)+1;
            }
        }
        return count;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(1)
*/
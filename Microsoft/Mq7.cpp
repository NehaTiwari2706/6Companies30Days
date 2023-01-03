//BULLS AND COWS

class Solution {
public:
    string getHint(string secret, string guess) {
       
       int bulls = 0, cows = 0;
       //frequency of character in secret
       vector<int> s(10,0);
       //frequency of character in guess
       vector<int> g(10,0);

       for(int i=0;i<secret.size();i++){
           // if element of secret and guess is equal then increment bulls
           if(secret[i]==guess[i]){
               bulls++;
           }
           // else increment frequency of element in secret and guess arrays
           else{
               s[secret[i]-'0']++;
               g[guess[i]-'0']++;
           }
       }

       // Calculating cows
       for(int i=0;i<10;i++){
           cows += min(s[i],g[i]);
       }
        //convert bulls and cows to string and return 
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};
/* 
Time Complexity = O(N)
Space Complexity = O(1)
*/
// Minimum Consecutive Cards to Pick Up

/*
We will store the previous occurence of an element in an array 'lastidx' and we continue to traverese the array 'cards' . If element is already present we take its index and find the current length. We update the "ans" if current length is less than "ans" .

If all the elements are unique then "ans" won't get updated we can return "-1"
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
      vector<int> lastidx(1000001,-1);
      int ans = INT_MAX;

      for(int i=0;i<cards.size();i++){
          if(lastidx[cards[i]] != -1){
              ans = min(ans, (i- lastidx[cards[i]] + 1));
          }
          lastidx[cards[i]] = i;
      }

      return (ans == INT_MAX) ? -1 : ans;
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(1)
*/
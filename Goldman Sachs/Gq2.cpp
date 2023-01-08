/*
Calculate the distance between points p1 p2, p1 p3, p1 p4, p2 p3, p2 p4 and p3 p4.
then using unordered map count the no. of values of equal sides and diagonals and if the count of any side's vaue is 4 and diagonal's value is 2 then Its a valid Square return true else false.

Time Complexity = O(1)
Space Complexity = O(1)
*/


class Solution {
public:
    //  Calculating distance
    int getlen(vector<int>& a, vector<int>& b){
        return( (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]) );
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // if any of the sides are equal then return false
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4){
            return false;
        }
    // array of distance btw 2 points
    vector<int> sides = {
       getlen(p1,p2),
       getlen(p1,p3),
       getlen(p1,p4),
       getlen(p2,p3),
       getlen(p2,p4),
       getlen(p3,p4),
    };
    
    unordered_map<int,int>m;
    for(auto& s : sides){
        // if the count of side is 0 then insert the pair of (side and its count 1)
        if(!m.count(s)){
            m.insert({s,1});
        }
        // else just increment the count of s
        else{
            m[s]++;
        }
    }
    // if map has more than 2 values then return false
    if(m.size() != 2){
        return false;
    }  
    // traverse map and check if the count is 2 or 4 then return true
    for(auto& it:m){
        return (it.second == 2 || it.second == 4);
    } 
     
    return false;
    }
};
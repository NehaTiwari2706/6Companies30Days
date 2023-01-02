/*
Seat Arrangement in a SpiceJet Problem 

The probability that the nth person gets his own seat is 1/2 because nth person will randomly sit on any seat(say 3) and the seat 3 person will only find nth seat empty bacause others will sit on their respective places.So there are 2 choices for nth person
1) Sit on nth seat in which case 3rd person will surely sit on his seat.
2) Sit on 3rd seat in which case 3rd person will surely not sit on his seat.

Time Complexity = O(1)
Space Complexity = O(1)
*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1){
            return 1.0;
        }
        else
             return 0.5;
    }
};

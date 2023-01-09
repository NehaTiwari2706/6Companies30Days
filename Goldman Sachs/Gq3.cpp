/*
 Number of Boomerangs

Foreach point, call this a center point, group the other points into buckets where each bucket contains points that are the same distance from the center point. Each bucket with more than 1 point can make boomerangs.

How many boomerangs can a bucket make?

Each point in a bucket can make a boomerang with all other points in the bucket. A bucket with N points, can make N * (N - 1) boomerangs.

Time Complexity = O(n^2)
Space Complexity = O(n)
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int total=0;
        for(int i=0;i<n;i++){
            map<int,int>mp;
            for(int j=0;j<n;j++){
                int dist = ((points[i][0]-points[j][0])*(points[i][0]-points[j][0])) + ((points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                mp[dist]++;
            }
            for(auto i : mp){
                if(i.second) total+=(i.second*(i.second-1));
            }
        }
        return total;
    }
};
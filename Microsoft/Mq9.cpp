// DFS by checking if a Directed graph has a cycle then return false else true

class Solution {
public:
    //Detect if a graph has a cycle
    bool isCyclic(vector<vector<int>>& ad,vector<int>& visited,int curr)
    {
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2;
        for(int i=0;i<ad[curr].size();++i)
            if(visited[ad[curr][i]]!=1)
                if(isCyclic(ad,visited,ad[curr][i]))
                    return true;
        
        visited[curr] = 1;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adjencency list will store the bi before ai (Directed Graph)
        vector<vector<int>> ad(numCourses);

        for(int i=0;i<prerequisites.size();++i)
            ad[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        //visited will store if a node is visited(1) or unvisited(0) or processing(2)
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;++i)
            if(visited[i]==0)
                if(isCyclic(ad,visited,i))
                    return false;
        
        return true;
    }
};
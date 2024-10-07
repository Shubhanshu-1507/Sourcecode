/*
Given n cuboids where the dimensions of the ith cuboid is
cuboids[i] = [widthi, lengthi, heighti] (0-indexed).
Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj 
and lengthi <= lengthj and heighti <= heightj. 
You can rearrange any cuboid's dimensions by 
rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

 
*/

class Solution {
private:
    bool check(vector<int>curr,vector<int>prev){
        //prev is small cube and curr is large cube

        if(prev[0]<=curr[0]&&prev[1]<=curr[1]&&prev[2]<=curr[2]){
            return true;
        }
        else{
            return false;
        }
    }

    int SolveUsingTab(vector<vector<int>>& cuboids){
        int n=cuboids.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        int ans=0;

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int include=0;
                if(j==-1||check(cuboids[i],cuboids[j])){
                    include = cuboids[i][2]+next[i+1];
                }
                int exclude = 0+ next[j+1];
                curr[j+1]=max(include,exclude);
            }
            next=curr;
        }
        return next[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return SolveUsingTab(cuboids);
    }
};
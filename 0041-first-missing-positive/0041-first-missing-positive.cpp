#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 1;
        }
        // find minmax
        map<int,int> m;
        int maxnum=INT_MIN;
        int minnum=INT_MAX;
        for(int i=0;i<n;i++){
            m[nums[i]]=1;
            if(nums[i]>maxnum){
                maxnum=nums[i];
            }
            if(nums[i]<minnum){
                minnum=nums[i];
            }
        }
        // find min positive
        if(maxnum<=0){
            return 1;
        }
        if(minnum<=0){
            minnum=1;
        }
        if(minnum>1){
            return 1;
        }
        for(int i=minnum;i<=maxnum;i++){
            if(m[i]==0){
                return i;
            }
        }
        return maxnum+1;
    }
};
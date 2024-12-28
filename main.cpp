#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //distance between i and j is -> j-i
        //score i<j is -> values[i]+values[j]+i-j
        //search the maximum
        int n=values.size();
        if(n<2) return values[0]+values[1]+0-1;
        vector<int> suffixMax(n);
        suffixMax[n-1]=values[n-1] - (n-1);
        
        for(int i=n-2; i>=0; i--){
            suffixMax[i]=max(suffixMax[i+1], values[i]-i);
        }
        int maxScore=INT_MIN;
        for(int i=0; i<n-1; i++){
            maxScore=max(maxScore, values[i]+i+suffixMax[i+1]);
        }
        return maxScore;
    }
};

int main(){
    return 0;
}
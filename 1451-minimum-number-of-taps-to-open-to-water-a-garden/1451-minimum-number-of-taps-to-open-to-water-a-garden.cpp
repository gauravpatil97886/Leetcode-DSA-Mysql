class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        
        // Calculate the maximum right boundary reachable from each left boundary
        for (int leftBoundary = 0; leftBoundary < ranges.size(); leftBoundary++) {
            int coverageStart = max(0, leftBoundary - ranges[leftBoundary]);
            int coverageEnd = min(n, leftBoundary + ranges[leftBoundary]);
            maxReach[coverageStart] = max(maxReach[coverageStart], coverageEnd);
        }
        
        int currentPosition = 0;      // The current rightmost boundary covered
        int farthestReachable = 0;    // The farthest right boundary reachable from any point
        int tapsUsed = 0;             // Count of taps used
        int currentIndex = 0;         // Index for iterating through maxReach
        
        // While the entire garden is not covered
        while (currentPosition < n) {
            // Iterate through maxReach[currentIndex] and update the farthest reachable point
            while (currentIndex <= currentPosition) {
                farthestReachable = max(farthestReachable, maxReach[currentIndex]);
                currentIndex++;
            }
            
            // If the farthest reachable point is not beyond the current end point
            if (farthestReachable <= currentPosition) {
                return -1;  // Unable to cover the entire garden
            }
            
            currentPosition = farthestReachable; // Move the end point to the farthest reachable point
            tapsUsed++;                         // Increment the count of taps used
        }
        
        return tapsUsed;        
    }
};

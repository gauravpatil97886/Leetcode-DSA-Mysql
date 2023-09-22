class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        
        int maxPointsOnLine = 2;  // At least 2 points are needed for a line.
        
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> slopeFrequency;
            int vertical = 0;  // Count of vertical points (same x-coordinate).
            int duplicate = 1; // Count of duplicate points.
            int localMax = 1;  // Local maximum for the current point.
            
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;  // Skip the same point.
                }
                
                if (points[i][0] == points[j][0]) {
                    if (points[i][1] == points[j][1]) {
                        duplicate++;
                    } else {
                        vertical++;
                    }
                } else {
                    double slope = static_cast<double>(points[i][1] - points[j][1]) / 
                                   static_cast<double>(points[i][0] - points[j][0]);
                    slopeFrequency[slope]++;
                    localMax = max(localMax, slopeFrequency[slope]);
                }
            }
            
            // Update the global maximum with the current local maximum.
            maxPointsOnLine = max(maxPointsOnLine, max(localMax + duplicate, vertical + duplicate));
        }
        
        return maxPointsOnLine;
    }
};

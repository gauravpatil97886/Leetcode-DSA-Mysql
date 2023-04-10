//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int maxIntersections(vector<vector<int>>& lines, int N) {
        vector<pair<int, int>> events;
        for (int i = 0; i < N; i++) {
            events.push_back({lines[i][0], 0});
            events.push_back({lines[i][1], 1});
        }
        sort(events.begin(), events.end());
        int counter = 0;
        int max_intersections = 0;
        for (auto event : events) {
            if (event.second == 0) { // start of a line segment
                counter++;
                max_intersections = max(max_intersections, counter);
            } else { // end of a line segment
                counter--;
            }
        }
        return max_intersections;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends
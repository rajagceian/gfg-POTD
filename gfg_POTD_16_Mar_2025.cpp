class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0; // Already at the end
        
        int steps = 0;
        int maxReach = 0;
        int currentEnd = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i > maxReach) return -1; // Cannot proceed further
            
            maxReach = max(maxReach, i + arr[i]);
            
            if (i == currentEnd) {
                ++steps;
                currentEnd = maxReach;
                
                if (currentEnd >= n - 1) {
                    return steps;
                }
            }
        }
        
        return -1; // Should not reach here under normal circumstances
    }
};

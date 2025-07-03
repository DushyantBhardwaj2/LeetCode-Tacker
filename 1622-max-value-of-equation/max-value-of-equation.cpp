class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int maxi = INT_MIN;

        // Step 1: Precompute y - x for each point
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = points[i][1] - points[i][0];
        }

        int bestIndex = 0; // index with max (y - x)
        int i = 0;

        for (int j = 1; j < n; ++j) {
            // Move i to maintain xj - xi <= k
            while (i < j && points[j][0] - points[i][0] > k) {
                if (i == bestIndex) {
                    // best goes out of window, recompute bestIndex
                    bestIndex = i + 1;
                    for (int t = i + 1; t < j; ++t) {
                        if (diff[t] > diff[bestIndex]) {
                            bestIndex = t;
                        }
                    }
                }
                i++;
            }

            // If i < j and window is valid, compute value
            if (i < j && points[j][0] - points[i][0] <= k) {
                int value = points[j][1] + points[j][0] + diff[bestIndex];
                maxi = max(maxi, value);
            }

            // Update bestIndex if current (y - x) is better
            if (diff[j] > diff[bestIndex]) {
                bestIndex = j;
            }
        }

        return maxi;
    }
};

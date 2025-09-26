#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    if (n < 3) return 0;

    int i = 0;
    int water = 0;
    while (i < n - 1) {
        int leftGuard = height[i];
        int j = i + 1;
        int rightGuard = 0;
        int rightPos = -1;
        for (int k = j; k < n; k++) {
            if (height[k] >= leftGuard) {
                rightGuard = height[k];
                rightPos = k;
                break;
            }
            if (height[k] > rightGuard) {
                    rightGuard = height[k];
                    rightPos = k;
            }
        }   
        if (rightPos == -1) break;
        int minH = min(leftGuard, rightGuard);

        for (int x = i + 1; x < rightPos; x++) {
            if (height[x] < minH)
                water += minH - height[x];
        }
        i = rightPos;
    }
    return water;
}

int main() {
    vector<int> heights = {4,2,0,3,2,5};
    trap(heights);
    return 0;
}
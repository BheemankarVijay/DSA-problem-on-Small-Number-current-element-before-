#include <iostream>
#include <vector>
using namespace std;

// Include the solution class with the method
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int num : nums) {
            freq[num]++;
        }
        for (int i = 1; i < 101; i++) {
            freq[i] += freq[i - 1];
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numsBefore = (nums[i] == 0) ? 0 : freq[nums[i] - 1];
            result.push_back(numsBefore);
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the vector: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.smallerNumbersThanCurrent(nums);

    cout << "The resulting vector is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
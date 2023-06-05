#include <bits/stdc++.h>
using namespace std;

int lis(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    int result = lis(nums);
    std::cout << "Length of the Longest Increasing Subsequence: " << result << std::endl;

    return 0;
}


/*

std::vector<int> lis(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);
    std::vector<int> lisValues;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLength = *std::max_element(dp.begin(), dp.end());
    int index = std::max_element(dp.begin(), dp.end()) - dp.begin();

    while (true) {
        lisValues.push_back(nums[index]);
        maxLength--;

        if (maxLength == 0) {
            break;
        }

        for (int i = index - 1; i >= 0; --i) {
            if (dp[i] == maxLength && nums[i] < nums[index]) {
                index = i;
                break;
            }
        }
    }

    std::reverse(lisValues.begin(), lisValues.end());
    return lisValues;
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    std::vector<int> lisValues = lis(nums);
    int lisLength = lisValues.size();

    std::cout << "Length of the Longest Increasing Subsequence: " << lisLength << std::endl;
    std::cout << "Longest Increasing Subsequence: ";
    for (int i = 0; i < lisLength; ++i) {
        std::cout << lisValues[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/
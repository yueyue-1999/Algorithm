/*
34. 在排序数组中查找元素的第一个和最后一个位置

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

示例 1：

    输入：nums = [5,7,7,8,8,10], target = 8
    输出：[3,4]

示例 2：

    输入：nums = [5,7,7,8,8,10], target = 6
    输出：[-1,-1]

示例 3：

    输入：nums = [], target = 0
    输出：[-1,-1]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    // 查找左边界
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    // nums[right] < target, nums[left] >= target;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    int ls = right;
    // 查找右边界
    left = 0, right = nums.size() - 1;
    // nums[right] < target, nums[left] >= target;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int rs = left;
    return ls < rs - 1 ? vector<int>{ls + 1, rs - 1} : vector<int> {-1, -1};
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << '[' << result[0] << ',' << result[1] << ']' << endl;
    return 0;
}

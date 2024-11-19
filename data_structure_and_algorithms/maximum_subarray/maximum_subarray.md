# 最大子序列

## 问题描述

给定数组`nums`, 请找出具有最大连续和的连续子数组, 返回最大值

## 分析

### 法1: 穷举法

列出每个子序列, 并求和.

```cpp
#include <bits/stdc++.h>

int main()
{
    std::vector<int> nums;
    int size = 0;
    std::cin >> size;
    while (size--) {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    size = nums.size();
    int max = INT_MIN;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += nums[k];
            }
            if (sum > max) {
                max = sum;
            }
        }
    }
    std::cout << max << std::endl;
    return 0;
}
```

点评: 该方法容易想到, 但是时间复杂度是$O(n^3)$

## 法2.运算时比较

优化法1, 减少一层循环, 一边运算一边比较

```cpp
#include <bits/stdc++.h>

int main()
{
    std::vector<int> nums;
    int size = 0;
    std::cin >> size;
    while (size--) {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    size = nums.size();
    int max = INT_MIN;
    for (int i = 0; i < size; ++i) {
        int sum = 0;
        for (int j = i; j < size; ++j) {
            sum += nums[j];
            if (sum > max) {
                max = sum;
            }
        }
    }
    std::cout << max << std::endl;
    return 0;
}
```

点评: 时间复杂度变为$O(n^2)$, 但是能看出有的序列根本不可能, 但也被计入.

## 法3.分治法

例如`4, -3, 5, -2, -1, 2, 6, -2`这样的序列, 可以分成两个部分`4, -3, 5, -2  | -1, 2, 6, -2`, 最大的子序列可能在`|`左边,
右边, 或者横跨在两侧. 左边部分最大的子序列`4, -3, 5`最大和为6, 右边最大是`2, 6`, 和为8.

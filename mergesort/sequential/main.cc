#include <algorithm>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<int> readFromFile(const std::string &filename = "10000_nums.data")
{
    std::ifstream ifs(filename);
    std::vector<int> nums;
    int num;
    while (ifs >> num)
        nums.push_back(num);
    return nums;
}

void merge(std::vector<int> &nums, int l1, int r1, int l2, int r2)
{
    std::vector<int> tmp;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2)
    {
        if (nums[i] < nums[j])
            tmp.push_back(nums[i++]);
        else
            tmp.push_back(nums[j++]);
    }
    while (i <= r1)
        tmp.push_back(nums[i++]);
    while (j <= r2)
        tmp.push_back(nums[j++]);
    for (int i = 0; i < tmp.size(); i++)
        nums[l1 + i] = tmp[i];
}

void mergeSort(std::vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int len = r - l + 1;
    mergeSort(nums, l, l + len / 2 - 1);
    mergeSort(nums, l + len / 2, r);
    merge(nums, l, l + len / 2 - 1, l + len / 2, r);
}

int main()
{
    std::vector<int> nums = readFromFile();
    mergeSort(nums, 0, nums.size() - 1);
    for (int i = 1; i < 10000; i++)
    {
        assert(nums[i - 1] <= nums[i]);
    }
    printf("Passed\n");
    return 0;
}
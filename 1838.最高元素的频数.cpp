#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 元素的 频数 是该元素在一个数组中出现的次数。
// 给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。
// 执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。

// 输入：nums = [1,2,4], k = 5
// 输出：3
// 解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
// 4 是数组中最高频元素，频数是 3 。

// 排序 + 滑动窗口

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        if(nums.empty() || k<0) return 0;   //边界处理
        sort(nums.begin(), nums.end()); //排序

        long long total = 0;
        int l = 0, res = 1;
        for(int r=1; r<nums.size(); ++r){
            // 每一次遍历，将前面数字变成与当前数字一样所需的操作步数， 同时需要注意大数
            total += (long long) (nums[r] - nums[r-1]) * (r - l);

            //当需要值大于给定值， 就需要缩短窗口左值
            while(total > k){
                total -= nums[r] - nums[l];
                ++l;
            }
            //统计左右滑窗之间间距大小，即为结果
            res = max(res, r - l + 1);
        }

        return res;
    }
};


int main(){
    cout << "Please enter array size and operator num: " << "\n";
    int len, k;
    cin >> len >> k;
    vector<int> array(len);

    cout << "Please enter array data: " << "\n";
    for(int i=0; i<len; ++i){
        cin >> array[i];
    }
    
    Solution s;
    cout << "res: " << s.maxFrequency(array, k) << endl;

    return 0;
}
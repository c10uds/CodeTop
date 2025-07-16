#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            return quickSelect(nums, 0, nums.size() - 1, k - 1);
        }
        int quickSelect(vector<int>& nums, int left, int right, int k) {
            int index = partition(nums, left, right, k);
            if (index == k) return nums[index];
            else if (index < k) return partition(nums, index + 1, right, k);
            else  return partition(nums, left, index - 1, k);
        }
        int partition(vector<int>& nums, int left, int right, int k) {
            int pivot = nums[right];
            int i = left;
            for (int j = left; j < right; j++) {
                if(nums[j] > pivot) {
                    swap(nums[i], nums[j]);
                    ++i;
                }
            }
            swap(nums[i], nums[right]);
            return i;
        }
    };
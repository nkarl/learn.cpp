#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

//void print(vector<int>& nums, int key) {
    //for (auto i : nums)
        //cout << i << ' ';

    //cout << endl;
    //cout << "key: " << key << endl;
//}

int search(vector<int>&, int);

int main(int argc, char* argv[]) {

    vector<int> nums = { -1, 0, 2, 5, 9, 11 };
    //vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int key = 5;

    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << endl;

    int res = search(nums, key);
    cout << "key index:" << res << endl;
    //cout << endl;
    //cout << typeid(nums).name() << endl;

    return 0;
}

int search(vector<int>& nums, int target) {
    int head = 0, tail = nums.size() - 1;

    while (head <= tail) {
        int mid = head + (tail - head) / 2;
        int cmp = (target < nums[mid]) ? -1
                : (target > nums[mid]) ? 1
                : 0;
        if (cmp < 0) tail = mid - 1;
        else if (cmp > 0) head = mid + 1;
        else return mid;
    }
    return -1;
}

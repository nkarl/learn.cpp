#include <iostream>
#include <vector>
#include <typeinfo>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int print(vector<int>& nums, int key) {
    for (auto i : nums)
        cout << i << ' ';

    cout << endl;
    cout << "key: " << key << endl;
}

int binary_search(vector<int>&, int);
int search(vector<int>&, int);

auto main(int argc, char *argv[]) -> int {

    //vector<int> nums = { -1, 0, 2, 5, 9, 11 };
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int key = 5;

    auto res = binary_search(nums, key);
    cout << "key index:" << res << endl;
    return 0;
}

int binary_search(vector<int>& nums, int key) {
    return search(nums, key);
}

int search(vector<int>& nums, int key) {
    int lo = 0, hi = nums.size() - 1;
    print(nums, key);
    //cout << "key = " << key << endl;
    int result = -1;
    int c = 0;
    while (lo <= hi) {
        ++c;
        cout << "-----------------" << endl;
        cout << "loop count: " << c << endl;
        cout << "lo : " << lo << endl;
        cout << "hi : " << hi << endl;

        int mid = lo + (hi - lo) / 2;
        cout << "mid: " << mid << endl;
        //cout << mid << endl;
        int cmp = (nums[mid] < key) ? -1
                : (nums[mid] > key) ? 1
                : 0;
        if      (cmp < 0 ) hi = mid - 1;
        else if (cmp > 0 ) lo = mid + 1;
        else {
            cout << "break out mid: " << mid;
            result = mid;
            break;
        }
    }

    cout << "result: " << result << endl;
    return result;
}

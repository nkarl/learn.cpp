#include <iostream>
#include <vector>
#include <typeinfo>

using std::string;
using std::vector;
using std::cout;
using std::endl;

void print(vector<int>& nums, int key) {
    for (auto i : nums)
        cout << i << ' ';

    cout << endl;
    cout << "key: " << key << endl;
}

int binary_search(vector<int>&, int);
int search(vector<int>&, int);

int main(int argc, char *argv[]) {

    //vector<int> nums = { -1, 0, 2, 5, 9, 11 };
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int key = 5;

    auto res = binary_search(nums, key);
    cout << "key index: " << res << endl;
    return 0;
}

int binary_search(vector<int>& nums, int key) {
    return search(nums, key);
}

int search(vector<int>& nums, int key) {
    int head = 0, tail = nums.size() - 1;

    int result = -1;
    int c = 0;
    while (head <= tail) {
        ++c;
        cout << "-----------------" << endl;
        cout << "headop count: " << c << endl;
        cout << "head : " << head << endl;
        cout << "hi : " << tail << endl;

        int mid = head + (tail - head) / 2;
        cout << "mid: " << mid << endl;
        //cout << mid << endl;
        int cmp = (key < nums[mid]) ? -1
                : (key > nums[mid]) ? 1
                : 0;
        //int cmp = (nums[mid] < key) ? -1
                //: (nums[mid] > key) ? 1
                //: 0;
        if      (cmp < 0 ) tail = mid - 1;
        else if (cmp > 0 ) head = mid + 1;
        else {
            cout << "break out mid: " << mid;
            result = mid;
            break;
        }
    }

    cout << "result: " << result << endl;
    return result;
}

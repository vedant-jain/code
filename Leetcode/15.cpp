#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    // incomplete
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        if(target < 0)
        {
            break;
        }

        while (front < back) {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }

    return res;
}

int main() {
    vector<int> nums;
    int input[6] = {-1, 0, 1, 2, -1, -4};
    for (int i = 0; i < 6; i++) {
        nums.push_back(input[i]);
    }
    vector<vector<int> > answer = threeSum(nums);
    for (int i = 0; i < answer.size(); i++) {
        cout << "[";
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << ", ";
        }
        cout << "]," << endl;
    }
}
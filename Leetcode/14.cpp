#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        
    if (strs.size() == 0) {
        return "";
    }

    if (strs[0].length() == 0) {
        return "";
    }

    if (strs.size() == 1) {
        return strs[0];
    }

    string prefix = strs[0];

    // prefix populated
    for (int i = 1; i < strs.size(); i++) {
        if (strs[i].length() == 0) {
            return "";
        }
        for (int j = 0; j < prefix.length(); j++) {
            if (j > strs[i].length()-1) {
                prefix.erase(j);
                break;
            }
            if (strs[i].at(j) != prefix.at(j)) {
                prefix.erase(j);
            }
        }
    }

    return prefix;
}

int main() {
    vector<string> strs;
    strs.push_back("aca");
    strs.push_back("cba");
    cout << longestCommonPrefix(strs);
}
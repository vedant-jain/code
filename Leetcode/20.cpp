#include "bits/stdc++"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool isValid(string s) {
    stack <char> stack;
    for (int i = 0; i < s.length(); i++) {

        if (strcmp(s.at(i), '[') || strcmp(s.at(i), '(') || strcmp(s.at(i), '{'))


        if (s.at(i).compare("[") || s.at(i).compare("(") || s.at(i).compare("{")) {
            stack.push(s.at(i));
        }
        else if ((s.at(i).compare("]") && s.top.compare("[")) || (s.at(i).compare(")") && s.top.compare("(")) || (s.at(i).compare("}") && s.top.compare("{"))) {
            stack.pop();
        }
    }
    
    if (stack.empty()) {
        return true;
    }
    
    return false;
}

int main() {
    
}
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

void SortAnagramList(vector<string>* list) {
    if(list == nullptr) {
        return;
    }
    unordered_map<string, vector<string>> table;
    for(auto s : (*list)) {
        string tmp(s);
        sort(tmp.begin(), tmp.end());
        table[tmp].push_back(s);
    }
    int index = 0;
    for(auto anagrams : table) {
        for(auto astr : anagrams.second) {
            (*list)[index++] = astr;
        }
    }
}


int main(int argc, char *argv[])
{
    vector<string> list;
    list.push_back("dog");
    list.push_back("something");
    list.push_back("god");
    list.push_back("licker");
    list.push_back("dice");
    list.push_back("kicler");
    list.push_back("cide");
    SortAnagramList(&list);
    for(auto str : list) {
        cout << str << endl;
    }
    return 0;
}

#include <set>
#include <vector>
#include <iostream>

using namespace std;

/*
void GetSubsets(const set<int>& s, vector<set<int>>* out) {
    if(s.size() == 0 || out == nullptr) {
        return;
    }
    out->push_back(s);
    for(auto v : s) {
        set<int> tmp(s);
        tmp.erase(v);
        GetSubsets(tmp, out);
    }
}
*/

void GetSubsets(const set<int>& s, vector<set<int>>* out) {
    if(s.size() == 0 || out == nullptr) {
        return;
    }
    for(auto v : s) {
        for(auto pset : vector<set<int>>{*out}) {
            set<int> tmp(pset);
            tmp.insert(v);
            out->push_back(tmp);
        }
        out->push_back(set<int>{v});
    }
}

int main()
{
    set<int> s{1,2,3,4};
    vector<set<int>> output;

    GetSubsets(s, &output);

    for(auto o : output) {
        for(auto v : o) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

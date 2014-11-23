// Programming Interviews Exposed
// Print All String Permutations

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Option 1
void perm(string str, size_t rotate) {
    if(str.size() <= rotate) {
        cout << str << endl;
    }
    else {
        for(size_t idx = rotate; idx < str.size(); idx++) {
            string rstr = str;
            char tmp = rstr[rotate];
            rstr[rotate] = rstr[idx];
            rstr[idx] = tmp;
            perm(rstr, rotate+1);
        }
    }
}

// Option 2
vector<string> GenerateStrings(string source, string target) {
    vector<string> results;
    if(source.size() == 0) {
        results.push_back(target);
    }
    for(size_t i = 0; i < source.size(); ++i) {
        string new_source(source);
        string new_target(target);
        new_source.erase(i, 1);
        new_target.push_back(source.at(i));
        vector<string> tmp_results = GenerateStrings(new_source, new_target);
        results.insert(results.end(), tmp_results.begin(), tmp_results.end());
    }
    return results;
}

int main()
{
    perm("hat", 0);
    perm("tire", 0);
    perm("sweat", 0);

    vector<string> results = GenerateStrings("abcd", "");
    for(auto s : results) {
        cout << s << endl;
    }

    return 0;
}

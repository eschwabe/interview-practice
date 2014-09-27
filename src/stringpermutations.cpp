// Programming Interviews Exposed
// Print All String Permutations

#include <string>
#include <iostream>

using namespace std;

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

int main()
{
    perm("hat", 0);
    perm("tire", 0);
    perm("sweat", 0);
    return 0;
}

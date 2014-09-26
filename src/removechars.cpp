// Programming Interviews Exposed PG.94
// Remove Specified Characters

#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

string remove_chars(string str, string remove) {
    string output;
    unordered_set<char> remove_set;
    for(char c : remove) {
        remove_set.insert(c);
    }
    for(char c : str) {
        if( remove_set.find(c) == remove_set.end() ) {
            output.append(1, c);
        }
    }

    return output;
}

int main(int argc, char *argv[])
{
    string output = remove_chars(string("My Little Pony"), string("aeiou"));
    cout << output << endl;
    return 0;
}

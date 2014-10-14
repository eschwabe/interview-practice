// Interviews Exposed - PG 97
// Reverse Words

#include <algorithm>
#include <iostream>

using namespace std;

string ReverseWords(const string& str) {
    string rstr = str;
    reverse(rstr.begin(), rstr.end());

    auto word_start = rstr.begin();
    auto word_end = word_start;

    while(word_start != rstr.end() && word_end != rstr.end()) {

        while(word_start != rstr.end() && (*word_start) == ' ') {
            word_start++;
        }

        word_end = word_start;
        while(word_end != rstr.end() && (*word_end) != ' ') {
            word_end++;
        }

        reverse(word_start, word_end);

        word_start = word_end;
    }

    return rstr;
}

int main()
{
    cout << ReverseWords("testing a sentence of some sort, do stuff!") << endl;
    cout << ReverseWords("wtf. why is there a mammoth in my place... word   ") << endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void PrintLastLines(const string& filename, const int K) {
    if(K <= 0) {
        return;
    }
    ifstream filestream(filename);
    string tmp;
    vector<off_t> offsets;
    offsets.push_back(0);
    while(getline(filestream, tmp)) {
        offsets.push_back(filestream.tellg());
    }
    size_t start_line = (static_cast<size_t>(K) < offsets.size()) ? (offsets.size() - static_cast<size_t>(K)) : 0;
    filestream.clear();
    filestream.seekg(offsets[start_line]);
    while(getline(filestream,tmp)) {
        cout << tmp << endl;
    }

}

int main(int argc, char *argv[])
{
    if(argc < 3) {
        cout << argv[0] << " FILE LINES" << endl;
        return 1;
    }
    PrintLastLines(argv[1],atoi(argv[2]));
    return 0;
}

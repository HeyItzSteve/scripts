#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

/*

    Removes quotation marks in files.

*/

int main(int argc, char* argv[]) {

    cout << argv[0] << endl;

    if(argc != 2) {
        cerr << "Usage: ./remove_q [input file]" << endl;
        exit(1);
    }

    ifstream readFile(argv[1]);

    if(!readFile) {
        cerr << "Error: File does not exist!" << endl;
        exit(1);
    }

    string currLine;
    char charRemove = '\"';

    while (getline(readFile,currLine)) {
        if(currLine.find(charRemove)!=string::npos) {
            currLine.erase(remove(currLine.begin(), currLine.end(), charRemove), currLine.end());
        }
        cout << currLine << endl;
    }
    
}
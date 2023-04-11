#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*

    Converts a bullet-point list into a numbered list.

*/

int main(int argc, char* argv[]) {

    if(argc != 2) {
        cerr << "Usage: ./p2num [input file]" << endl;
        exit(1);
    }

    ifstream readFile(argv[1]);

    if(!readFile) {
        cerr << "Error: File does not exist!" << endl;
        exit(1);
    }

    int counter = 1;
    string currLine;

    while (getline(readFile,currLine)) {
        if(currLine.size() > 0 && currLine.at(0) == '*') {
            currLine = currLine.substr(1);
            currLine = to_string(counter) + ". " + currLine + "<br/>";
            counter++;
        }
        cout << currLine << endl;
    }
    
}
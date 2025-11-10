/**
  Reading from a file and performing operations:
    printing first 'n' numbers if the n>0, else last 'n' numbers
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

vector<int> processStream(istream& input, int n) {
    vector<int> result;

    if (n > 0) {
        int value;
        while (n-- > 0 && input >> value) {
            result.push_back(value);
        }
    } else if (n < 0) {
        deque<int> buffer;
        int value;
        int count = -n;
        while (input >> value) {
            if (buffer.size() == count) {
                buffer.pop_front();
            }
            buffer.push_back(value);
        }
        result.assign(buffer.begin(), buffer.end());
    }

    return result;
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    int n;
    cout << "Enter n (positive or negative): ";
    cin >> n;

    vector<int> output = processStream(file, n);

    cout << "Output:\n";
    for (int num : output) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/* ==================================================================== */

/**
Reading and writing to files
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

vector<int> processStream(istream& input, int n) {
    vector<int> result;

    if (n > 0) {
        int value;
        while (n-- > 0 && input >> value) {
            result.push_back(value);
        }
    } else if (n < 0) {
        deque<int> buffer;
        int value;
        int count = -n;
        while (input >> value) {
            if (buffer.size() == count) {
                buffer.pop_front();
            }
            buffer.push_back(value);
        }
        result.assign(buffer.begin(), buffer.end());
    }

    return result;
}

int main() {
    string inputFile, outputFile;
    cout << "Enter input filename: ";
    cin >> inputFile;

    ifstream file(inputFile);
    if (!file) {
        cerr << "Error: Could not open input file " << inputFile << endl;
        return 1;
    }

    cout << "Enter output filename: ";
    cin >> outputFile;

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error: Could not open output file " << outputFile << endl;
        return 1;
    }

    int n;
    cout << "Enter n (positive or negative): ";
    cin >> n;

    vector<int> output = processStream(file, n);

    outFile << "Output:\n";
    for (int num : output) {
        outFile << num << " ";
    }
    outFile << endl;

    cout << "Results written to " << outputFile << endl;

    return 0;
}

/** ================================================================================  */

/**

 Types of File Streams
| Type     |  Purpose             | Example Usage | 
========================================================
| ifstream | Input (read from file) | ifstream in("data.txt"); | 
| ofstream | Output (write to file) | ofstream out("log.txt"); | 
| fstream | Input + Output (read/write) | fstream file("data.txt", ios::in | ios::out); | 

*/

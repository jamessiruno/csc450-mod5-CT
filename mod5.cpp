#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void appendToFile(const string& filename, const string& input) {
    ofstream file;
    file.open(filename, ios::app); // Open file in append mode
    if (file.is_open()) {
        file << input << endl;
        file.close();
        cout << "Data appended to " << filename << " successfully." << endl;
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void reverseFile(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (inputFile.is_open() && outputFile.is_open()) {
        string content((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
        reverse(content.begin(), content.end());
        outputFile << content;
        cout << "File reversed successfully and stored in " << outputFilename << endl;
    } else {
        cout << "Unable to open input or output file." << endl;
    }
}

int main() {
    string userInput;
    cout << "Enter data to append to CSC450_CT5_mod5.txt (Enter 'q' to stop):\n";

    // Get user input
    getline(cin, userInput);
    while (userInput != "q") {
        appendToFile("CSC450_CT5_mod5.txt", userInput);
        getline(cin, userInput);
    }

    // Reverse the file contents
    reverseFile("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");

    return 0;
}

#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;

int appendFunctionFileString(string file, string data = "") { // And create new file if does not exist. // Slow!
    ofstream outfile(file.c_str(), ios_base::app);
    if (!outfile) {
        cerr << "Error: Impossible to write in the file " << file << "!" << endl;
        return -1;
    } else {
        outfile << data;
        outfile.close();
    }
    return 0; // Ok.
}

void foo() {

}

int main() {
    srand (time(NULL));
    int numberOfMessage = 4;
    string stringOut = "";
    string fileIn1 = "fileIn1.txt";
    string fileIn2 = "fileIn2.txt";
    string fileIn3 = "fileIn3.txt";
    string fileIn4 = "fileIn4.txt";
    string fileOut = "persMess.txt";
    vector<vector<string>> Matrix;
    Matrix = {{"Le chat ", "La vache ", "Le chien ", "Un homme "},{"joue avec ", "mange ", "court autour d'"},{"une bicyclette.", "une pomme.", "une poire.", "une cerise."}};
    for (int message=1; message<numberOfMessage+1; ++message) { // iMax not included
        for (int i=0; i<Matrix.size(); ++i) {
            stringOut = stringOut + Matrix[i][rand() % Matrix[i].size()];
        }
        appendFunctionFileString(fileOut, stringOut + "\n");
        cout << stringOut << endl;
        stringOut = "";
    }
    cout << "Ok." << endl;
    return 0;
}

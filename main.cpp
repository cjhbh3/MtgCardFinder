#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool searchList(vector<string> cardList) {
    return false;
}

void printList(vector<string> cardList) {
    if (!cardList.empty()) {
        for (const auto &cardName : cardList) {
            cout << cardName << endl;
        }
    }
    else {
        cout << "List is empty" << endl;
    }
}

vector<string> loadCards() {
    vector<string> list;
    string cardName;
    string fileName;

    cin >> fileName;

    fileName = "Test Files/" + fileName;

    ifstream in;
    
    in.open(fileName.c_str());

    if (!in.is_open()) {
        cout << "File failed to open" << endl;
    }
    else {
        cout << "Pog" << endl;
    }

    while (getline(in, cardName)) {
        list.push_back(cardName);
    }

    in.close();

    return list;
}

int main() {
    // argv[0] = executable
    string inputFileName;
    vector<string> cards;

    cout << "Hello World" << endl;

    // Prompt for input file
    cout << "What is the file name?" << endl;
    
    cards = loadCards();

    cout << cards.size() << endl;

    // print list of cards
    printList(cards);

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool searchList(vector<string> cardList, string cardName) {
    if (!cardList.empty()) {
        for (const auto &card: cardList){
            if (card == cardName) {
                return true;
            }
        }
    }
    else {
        cout << "List is empty" << endl;
    }
    
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
        cout << "File opened successfully" << endl;
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
    string menuOption = "";
    vector<string> cards;

    cout << "Hello World" << endl;

    // Prompt for input file
    cout << "What is the file name?" << endl;
    cards = loadCards();

    while (menuOption != "3") {
        cout << "What do you want to do" << endl;
        cout << "1. Print Deck List" << endl;
        cout << "2. Find Card in Deck List" << endl;
        cout << "3. Quit" << endl;

        cin >> menuOption;

        if (menuOption == "1") {
            printList(cards);
        }
        else if (menuOption == "2") {
            string cardName = "";
            cout << "What card are you looking for?" << endl;
            cin >> cardName;
            if (searchList(cards, cardName)) {
                cout << "Card is in the list" << endl;
            }
            else {
                cout << "Card is not in the list" << endl;
            }
        }
        else if (menuOption != "3") {
            cout << "Please try again" << endl;
        }
    }



    return 0;
}
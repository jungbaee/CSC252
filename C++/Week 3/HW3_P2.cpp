#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {

    //Member ID, last name, first anme and current balance of points (0 to 99999)
    vector<string> memId;
    vector<string> firstName;
    vector<string> lastName;
    vector<int> currentBalance;
    string id, lName, fName;
    int cBalance, i = 0;

    //Phase A: (1) read app input records
    ifstream input("csc252hw3in.txt");

    if (input.fail()) {
        cout<< "Files does not exist" <<endl;
        return 0;
    }

    while (input >> id) {
        input >> fName;
        input >> lName;
        input >> cBalance;

        memId.push_back(id);
        firstName.push_back(fName);
        lastName.push_back(lName);
        currentBalance.push_back(cBalance);
    }

    cout << "Displaying all records from the input data file: \n";
    //Phase A (2)
    while (i < memId.size()) {
        cout<< memId.at(i) << " " << firstName.at(i) << " " << lastName.at(i) << " " << currentBalance.at(i) << " \n";
        i++;
    } cout<< endl;

    //Selection sort
    for (i = 0; i < memId.size() - 1 ; i++) {

        int temp = i;

        for (int j = i+1; j < memId.size(); j++) {

            if (memId.at(j) < memId.at(temp)) {
                temp = j;
            }
        }

        id = memId.at(i);
        memId.at(i) = memId.at(temp);
        memId.at(temp) = id;
                
        lName = lastName.at(i);
        lastName.at(i) = lastName.at(temp);
        lastName.at(temp) = lName;
                
        fName = firstName.at(i);
        firstName.at(i) = firstName.at(temp);
        firstName.at(temp) = fName;

        cBalance = currentBalance.at(i);
        currentBalance.at(i) = currentBalance.at(temp);
        currentBalance.at(temp) = cBalance;  
    }

    cout << "Displaying all records after selection sort: \n";
    //Phase A (3)
    i = 0;
    while (i < memId.size()) {
        cout<< memId.at(i) << " " << firstName.at(i) << " " << lastName.at(i) << " " << currentBalance.at(i) << " \n";
        i++;
    } cout<< endl;


    //Phase B. (1)
    char quit = 'a';
    while (quit != 'q') {
        //Phase B (1) - (1a)
        string userInput;
        bool isFound = false;
        int index;
        cout << "Type a Member ID: ";
        cin >> userInput;

        for (i = 0; i < memId.size(); i++) {
            if(memId.at(i) == userInput) {
                index = i;
                isFound = true;
                break;
            }
        }

        //Phase B (1) - (1b)
        if (isFound) {
            char ans;
            int amount;
            cout<< "Member found below" <<endl;
            cout<< memId.at(index) << " " << firstName.at(index) << " " << lastName.at(index) << " " << currentBalance.at(index) << " \n\n";
            cout<< "Update the number of points (current balance) 'a' to add, 's' to substract \n" ;
            cin>> ans;
            if (ans == 'a') {
                cout<< "Enter the amount to add: ";
                cin>>amount;
                currentBalance.at(index) += amount;
            } else if (ans == 's') {
                cout<< "Enter the amount to subtract: ";
                cin>>amount;
                currentBalance.at(index) -= amount;
            } else {
                cout<< "Invalid input. Exiting \n";
            }
        ////Phase B (1) - (1c)
        } else {
            cout<< "Member not found\n"; 
        }

        cout<< "Quit? \nPress ('q') to quit if not type anything character: ";
        cin >> quit;        
    }

    cout << "Displaying all records with current values: \n";
    //Phase B (2)
    i = 0;
    while (i < memId.size()) {
        cout<< memId.at(i) << " " << firstName.at(i) << " " << lastName.at(i) << " " << currentBalance.at(i) << " \n";
        i++;
    } cout<< endl;

    //Outputstream
    ofstream output("csc252hw3out.txt");
    i = 0;
    while (i < memId.size()) {
        output << memId.at(i) << " " << firstName.at(i) << " " << lastName.at(i) << " " << currentBalance.at(i) << " \n";
        i++;
    } cout<< endl;
    output.close();

    cout<< "Updating of records done and the new file is: csc252hw3out.txt\n";


}












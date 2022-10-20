#include <iostream>
#include <string>

using namespace std;

template <typename T>
int binarySearch(const T list[], T key, int listSize) {
    int low = 0;
    int high = listSize - 1;
    
    while (high >= low) {
        int mid = (low+high)/2;
        if (key < list[mid]) {
            high = mid -1;
        } else if (key == list[mid]) {
            return mid;
        } else {
            low = mid+1;
        }
    }
    return -low-1;
}

int main () {
    //Testing ints, doubles and strings
    int listOfInts [] = {1,2,3,4,5,6,7,8,9,10};
    double listOfDoubles [] = {1.0, 3.5, 5.7, 7.8, 9.9, 10.0, 16.8, 27.9, 103.57};
    string listOfStrings [] = {"a", "bear", "chi", "kilo", "no", "papel", "zoo"};
    int keyInt = 7;
    double keyDouble = 9.9;
    string keyString = "papel";
    
    cout<< "Negative means it is not in the array" <<endl<<endl;
    
    cout << "Testing on the list of Ints: " << endl;
    for (int i: listOfInts) {
        cout<< i << " ";
    }
    cout<< endl;
    cout << "The element " << keyInt << " is at index: " <<
    binarySearch(listOfInts, keyInt, sizeof(listOfInts)/sizeof(listOfInts[0]))
    <<"\n\n";
    
    cout << "Testing on the list of Doubles: " << endl;
    for (double i: listOfDoubles) {
        cout<< i << " ";
    }
    cout<< endl;
    cout << "The element " << keyDouble << " is at index: " <<
    binarySearch(listOfDoubles, keyDouble, sizeof(listOfDoubles)/sizeof(listOfDoubles[0]))
    <<"\n\n";
    
    cout << "Testing on the list of Strings: " << endl;
    for (string i : listOfStrings) {
        cout<< i << " ";
    }
    cout<< endl;
    cout << "The element " << keyString << " is at index: " <<
    binarySearch(listOfStrings, keyString, sizeof(listOfStrings)/sizeof(listOfStrings[0]))
    <<"\n\n";
    
    
}

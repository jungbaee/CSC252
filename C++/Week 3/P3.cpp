#include <iostream>
#include <vector>
using namespace std;
 
vector<double> rowSum(vector<vector<double>> v) {
    
    vector<double> sum;
    double sumOfRow = 0;
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            sumOfRow += v[i][j];
        }
        sum.push_back(sumOfRow);
        sumOfRow = 0;
    }
    
    return sum;
}
 
int main () {
    vector<vector<double>> vect {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {1,2,3,4,5}
    };
    
    cout<< "The original 2D vector is: " << endl;
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<< "The sum of each row in the above 2D vector is: " << endl;
    vector <double> vect2 = rowSum(vect);
 
    for (double i:vect2) {
        cout << i << " ";
    }
    cout<< endl;
        
}


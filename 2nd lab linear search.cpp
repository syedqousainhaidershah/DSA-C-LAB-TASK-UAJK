#include <iostream>
#include <iomanip>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    int* rollNumbers = new int[numStudents];
    int* pf = new int[numStudents];
    int* oop = new int[numStudents];
    int* dsa = new int[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Roll Number: ";
        cin >> rollNumbers[i];
        cout << "PF marks: ";
        cin >> pf[i];
        cout << "OOP marks: ";
        cin >> oop[i];
        cout << "DSA marks: ";
        cin >> dsa[i];
    }

    int searchRoll;
    cout << "\nEnter roll number to search: ";
    cin >> searchRoll;

    int index = linearSearch(rollNumbers, numStudents, searchRoll);

    if (index != -1) {
        int total = pf[index] + oop[index] + dsa[index];
        double percentage = (total / 300.0) * 100;
        cout << fixed << setprecision(2);
        cout << "\n--- Student Record Found ---" << endl;
        cout << "Roll Number: " << rollNumbers[index] << endl;
        cout << "PF: " << pf[index] << ", OOP: " << oop[index] << ", DSA: " << dsa[index] << endl;
        cout << "Total Marks: " << total << "/300" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    } else {
        cout << "Record Not Found" << endl;
    }

    delete[] rollNumbers;
    delete[] pf;
    delete[] oop;
    delete[] dsa;

    return 0;
}

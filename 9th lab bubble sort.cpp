#include <iostream>
#include <vector>
using namespace std;

/*
 * Function: addSalary
 * Purpose : Adds a new salary to the list of salaries
 * Input : vector<int>& salaries - reference to salary list
 * int salary - salary value to add
 */
void addSalary(vector<int>& salaries, int salary) {
    salaries.push_back(salary);
}

/*
 * Function: displaySalaries
 * Purpose : Displays all salaries in the current list
 * Input : vector<int>& salaries - reference to salary list
 */
void displaySalaries(const vector<int>& salaries) {
    if(salaries.empty()) {
        cout << "No salaries available." << endl;
        return;
    }

    for (size_t i = 0; i < salaries.size(); i++) {
        cout << salaries[i] << " ";
    }
    cout << endl;
}

/*
 * Function: bubbleSort
 * Purpose : Sorts the salary list in ascending order using Bubble Sort
 * Input : vector<int>& salaries - reference to salary list
 */
void bubbleSort(vector<int>& salaries) {
    int n = salaries.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization: check if swap happened
        for (int j = 0; j < n - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                int temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break; // Already sorted
    }
}

int main() {
    vector<int> salaries;
    int choice, salary;

    do {
        cout << "---- Employee Salary Management Menu ----" << endl;
        cout << "1. Add Salary" << endl;
        cout << "2. Display Salaries" << endl;
        cout << "3. Sort Salaries" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter salary to add: ";
                cin >> salary;
                addSalary(salaries, salary);
                break;
            case 2:
                cout << "Current Salaries: ";
                displaySalaries(salaries);
                break;
            case 3:
                if(salaries.empty()) {
                    cout << "No salaries to sort." << endl;
                } else {
                    bubbleSort(salaries);
                    cout << "Salaries sorted in ascending order:" << endl;
                    displaySalaries(salaries);
                }
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}

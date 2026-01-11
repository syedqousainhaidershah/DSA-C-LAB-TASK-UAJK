#include <iostream>
#include <string>
using namespace std;

#define MAX 100
class BookStack {
private:
    string books[MAX]; 
    int top; 
public:
   
    BookStack() {
        top = -1; 
    }


    bool isEmpty() {
        return (top == -1);
    }

    
    bool isFull() {
        return (top == MAX - 1);
    }

    
    void push(string bookName) {
        if (isFull()) {
            cout << "? Stack Overflow! Cannot add more books.\n";
            return;
        }
        top++;
        books[top] = bookName;
        cout << "? Book added: " << bookName << endl;
    }

    
    void pop() {
        if (isEmpty()) {
            cout << "? Stack Underflow! No books to remove.\n";
            return;
        }
        cout << "??? Book removed: " << books[top] << endl;
        top--;
    }

  
    void peek() {
        if (isEmpty()) {
            cout << "?? Stack is empty. No top book.\n";
            return;
        }
        cout << "?? Top Book: " << books[top] << endl;
    }

  
    void display() {
        if (isEmpty()) {
            cout << "?? No books in stack.\n";
            return;
        }

        cout << "\n?? Books in Stack (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "- " << books[i] << endl;
        }
    }
};


int main() {
    BookStack stack;
    int choice;
    string bookName;

    do {
        cout << "\n====== Library Stack Menu ======\n";
        cout << "1. Add Book (Push)\n";
        cout << "2. Remove Book (Pop)\n";
        cout << "3. View Top Book (Peek)\n";
        cout << "4. Display All Books\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter book name: ";
                getline(cin, bookName);
                stack.push(bookName);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.peek();
                break;

            case 4:
                stack.display();
                break;

            case 5:
                if (stack.isEmpty())
                    cout << "?? Stack is empty.\n";
                else
                    cout << "?? Stack is not empty.\n";
                break;

            case 0:
                cout << "?? Exiting program...\n";
                break;

            default:
                cout << "? Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

#define MAX 5 // Maximum size of queue

class TicketQueue {
private:
    string tickets[MAX];
    int front, rear;

public:
    // Constructor
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Add a customer ticket (Enqueue)
    void enqueue(string ticket) {
        if (isFull()) {
            cout << "Queue is full. Cannot add ticket.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        tickets[rear] = ticket;
        cout << "Ticket added successfully.\n";
    }

    // Process next ticket (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No ticket to process.\n";
            return;
        }
        cout << "Processing ticket: " << tickets[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Display all pending tickets
    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }
        cout << "Pending Tickets:\n";
        for (int i = front; i <= rear; i++) {
            cout << "- " << tickets[i] << endl;
        }
    }

    // Cancel a specific ticket
    void cancelTicket(string ticket) {
        if (isEmpty()) {
            cout << "Queue is empty. No ticket to cancel.\n";
            return;
        }

        int pos = -1;
        for (int i = front; i <= rear; i++) {
            if (tickets[i] == ticket) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Ticket not found.\n";
            return;
        }

        for (int i = pos; i < rear; i++) {
            tickets[i] = tickets[i + 1];
        }
        rear--;

        if (rear < front) {
            front = rear = -1;
        }

        cout << "Ticket cancelled successfully.\n";
    }
};

int main() {
    TicketQueue tq;
    int choice;
    string ticket;

    do {
        cout << "\n--- Customer Service Ticketing System ---\n";
        cout << "1. Add Ticket\n";
        cout << "2. Process Ticket\n";
        cout << "3. Display Tickets\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Check if Queue is Empty\n";
        cout << "6. Check if Queue is Full\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter ticket description: ";
            getline(cin, ticket);
            tq.enqueue(ticket);
            break;

        case 2:
            tq.dequeue();
            break;

        case 3:
            tq.display();
            break;

        case 4:
            cout << "Enter ticket to cancel: ";
            getline(cin, ticket);
            tq.cancelTicket(ticket);
            break;

        case 5:
            cout << (tq.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;

        case 6:
            cout << (tq.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int id, sem;
    float gpa;
    char name[30];
    Node *next, *prev;
} *head = NULL;

Node* makeNode() {
    Node* n = new Node;
    cout << "\nEnter ID, Name, Semester, GPA:\n";
    cin >> n->id >> n->name >> n->sem >> n->gpa;
    n->next = n->prev = NULL;
    return n;
}

void insertBeg() {
    Node* n = makeNode();
    n->next = head;
    if (head) head->prev = n;
    head = n;
}
void insertEnd() {
    Node* n = makeNode();
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}
void insertPos(int pos) {
    if (pos == 1) { insertBeg(); return; }
    Node* t = head;
    int i = 1;
    while (t && i < pos - 1) { t = t->next; i++; }
    if (!t) {
        cout << "\nInvalid Position!\n";
        return;
    }
    Node* n = makeNode();
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}
void deleteBeg() {
    if (!head) { cout << "\nList Empty!\n"; return; }
    Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete t;
}
void deleteEnd() {
    if (!head) { cout << "\nList Empty!\n"; return; }
    Node* t = head;
    if (!t->next) { head = NULL; delete t; return; }
    while (t->next) t = t->next;
    t->prev->next = NULL;
    delete t;
}
void deletePos(int pos) {
    if (pos == 1) { deleteBeg(); return; }
    Node* t = head;
    int i = 1;
    while (t && i < pos) { t = t->next; i++; }
    if (!t) {
        cout << "\nInvalid Position!\n";
        return;
    }
    t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}
void displayForward() {
    if (!head) { cout << "\nList Empty!\n"; return; }
    Node* t = head;
    cout << "\n--- Forward Display ---\n";
    while (t) {
        cout << t->id << " " << t->name << " " << t->sem << " " << t->gpa << "\n";
        t = t->next;
    }
}
void displayBackward() {
    if (!head) { cout << "\nList Empty!\n"; return; }
    Node* t = head;
    while (t->next) t = t->next;
    cout << "\n--- Backward Display ---\n";
    while (t) {
        cout << t->id << " " << t->name << " " << t->sem << " " << t->gpa << "\n";
        t = t->prev;
    }}
int main() {
    int choice, pos;
    while (true) {      
        cout << "\n MENU";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Delete at Beginning";
        cout << "\n5. Delete at End";
        cout << "\n6. Delete at Position";
        cout << "\n7. Display Forward";
        cout << "\n8. Display Backward";
        cout << "\n9. Exit";
        cout << "\nEnter Choice: ";

        cin >> choice;

        switch (choice) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                insertPos(pos);
                break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6:
                cout << "Enter Position: ";
                cin >> pos;
                deletePos(pos);
                break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: cout << "\nExiting...\n"; return 0;
            default: cout << "\nInvalid Choice!\n";
        }
    }
}

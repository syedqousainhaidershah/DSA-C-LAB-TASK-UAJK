#include <iostream>
#include <string>
using namespace std;

/* ================= CSLL : SIMPLE PLAYLIST ================= */

struct CSNode {
    int id;
    string name;
    string artist;
    float duration;
    CSNode* next;
};

class CSLL {
private:
    CSNode* head;

public:
    CSLL() {
        head = NULL;
    }

    void insertBeginning(int id, string name, string artist, float duration) {
        CSNode* node = new CSNode;
        node->id = id;
        node->name = name;
        node->artist = artist;
        node->duration = duration;

        if (!head) {
            head = node;
            node->next = head;
        } else {
            CSNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            node->next = head;
            temp->next = node;
            head = node;
        }
    }

    void insertEnd(int id, string name, string artist, float duration) {
        if (!head) {
            insertBeginning(id, name, artist, duration);
            return;
        }

        CSNode* node = new CSNode;
        node->id = id;
        node->name = name;
        node->artist = artist;
        node->duration = duration;
        node->next = head;

        CSNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = node;
    }

    void deleteFirst() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        CSNode* temp = head;
        CSNode* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteLast() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        CSNode* temp = head;
        while (temp->next->next != head)
            temp = temp->next;

        delete temp->next;
        temp->next = head;
    }

    void deleteByID(int id) {
        if (!head) return;

        if (head->id == id) {
            deleteFirst();
            return;
        }

        CSNode* temp = head;
        while (temp->next != head && temp->next->id != id)
            temp = temp->next;

        if (temp->next != head) {
            CSNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void display() {
        if (!head) {
            cout << "Playlist Empty\n";
            return;
        }

        CSNode* temp = head;
        do {
            cout << "ID: " << temp->id
                 << " | " << temp->name
                 << " | " << temp->artist
                 << " | " << temp->duration << " min\n";
            temp = temp->next;
        } while (temp != head);
    }
};

/* ================= CDLL : PREMIUM PLAYLIST ================= */

struct CDNode {
    int id;
    string title;
    string artist;
    string album;
    float duration;
    CDNode* next;
    CDNode* prev;
};

class CDLL {
private:
    CDNode* head;
    CDNode* current;

public:
    CDLL() {
        head = NULL;
        current = NULL;
    }

    void insertEnd(int id, string title, string artist, string album, float duration) {
        CDNode* node = new CDNode;
        node->id = id;
        node->title = title;
        node->artist = artist;
        node->album = album;
        node->duration = duration;

        if (!head) {
            head = node;
            node->next = node;
            node->prev = node;
            current = node;
            return;
        }

        CDNode* last = head->prev;
        node->next = head;
        node->prev = last;
        last->next = node;
        head->prev = node;
    }

    void deleteFirst() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = current = NULL;
            return;
        }

        CDNode* last = head->prev;
        CDNode* temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;

        if (current == temp)
            current = head;

        delete temp;
    }

    void displayForward() {
        if (!head) {
            cout << "Playlist Empty\n";
            return;
        }

        CDNode* temp = head;
        do {
            cout << "ID: " << temp->id
                 << " | " << temp->title
                 << " | " << temp->artist
                 << " | " << temp->album
                 << " | " << temp->duration << " min\n";
            temp = temp->next;
        } while (temp != head);
    }

    void displayReverse() {
        if (!head) {
            cout << "Playlist Empty\n";
            return;
        }

        CDNode* temp = head->prev;
        CDNode* stop = temp;
        do {
            cout << "ID: " << temp->id
                 << " | " << temp->title << endl;
            temp = temp->prev;
        } while (temp != stop);
    }

    void playNext() {
        if (!current) return;
        current = current->next;
        cout << "Now Playing: " << current->title << endl;
    }

    void playPrevious() {
        if (!current) return;
        current = current->prev;
        cout << "Now Playing: " << current->title << endl;
    }
};

/* ================= MAIN MENU ================= */

int main() {
    CSLL simple;
    CDLL premium;
    int choice;

    do {
        cout << "\n--- Music Playlist Manager ---\n";
        cout << "1. Display CSLL\n";
        cout << "2. Insert CSLL Track\n";
        cout << "3. Delete CSLL by ID\n";
        cout << "4. Display CDLL Forward\n";
        cout << "5. Display CDLL Reverse\n";
        cout << "6. Insert CDLL Track\n";
        cout << "7. Play Next\n";
        cout << "8. Play Previous\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 2) {
            int id;
            float d;
            string n, a;

            cout << "Track ID: ";
            cin >> id;
            cin.ignore();
            cout << "Track Name: ";
            getline(cin, n);
            cout << "Artist: ";
            getline(cin, a);
            cout << "Duration: ";
            cin >> d;

            simple.insertEnd(id, n, a, d);
        }

        else if (choice == 1)
            simple.display();

        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            simple.deleteByID(id);
        }

        else if (choice == 6) {
            int id;
            float d;
            string t, a, al;

            cout << "Track ID: ";
            cin >> id;
            cin.ignore();
            cout << "Title: ";
            getline(cin, t);
            cout << "Artist: ";
            getline(cin, a);
            cout << "Album: ";
            getline(cin, al);
            cout << "Duration: ";
            cin >> d;

            premium.insertEnd(id, t, a, al, d);
        }

        else if (choice == 4)
            premium.displayForward();

        else if (choice == 5)
            premium.displayReverse();

        else if (choice == 7)
            premium.playNext();

        else if (choice == 8)
            premium.playPrevious();

    } while (choice != 0);

    return 0;
}


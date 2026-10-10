//Lab 21 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class Goat {
    private:
        int age;
        string name;
        string color;
        string names[15] = {"Billy", "Nibbles", "Clover", "Gruff", "Biscuit", "Pepper", "Hazel", "Mochi", "Thistle", "Ziggy", "Daisy", "Brutus", "Maple", "Waffles", "Juniper"};
        string colors[15] = {"White", "Black", "Brown", "Tan", "Gray", "Cream", "Chestnut", "Red", "Gold", "Buckskin", "Charcoal", "Fawn", "Silver", "Copper", "Ivory"};
    public:
    
        Goat() {
            age = rand() % (20-1 +1) + 1;
            name = names[rand() % 15];
            color = colors[rand() % 15];
        }
        Goat(int a, string n, string c) {
            age = a;
            name = n;
            color = c;
        }
    };

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat g, Node* p = nullptr, Node* n = nullptr) {
            data = g; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat g) {
        Node* newNode = new Node(g);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat g) {
        Node* newNode = new Node(g);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(Goat());

    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}

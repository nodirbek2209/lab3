#include <iostream>
#include <limits>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int maximum() {
        if (!head) return 0;
        int max_val = numeric_limits<int>::min();
        Node* temp = head;
        while (temp) {
            max_val = max(max_val, temp->data);
            temp = temp->next;
        }
        return max_val;
    }

    int minimum() {
        if (!head) return 0;
        int min_val = numeric_limits<int>::max();
        Node* temp = head;
        while (temp) {
            min_val = min(min_val, temp->data);
            temp = temp->next;
        }
        return min_val;
    }

    int first() {
        if (!head) return 0;
        return head->data;
    }
};

int main() {
    LinkedList list;

    
    int num;
    while (cin >> num) {
        list.insert(num);
    }

    cout << list.maximum() << endl;
    cout << list.first() << endl;
    cout <<  list.size() << endl;
    cout <<  list.minimum() << endl;

    return 0;
}

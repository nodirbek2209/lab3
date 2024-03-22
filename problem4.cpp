#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data_n;
    Node* next_n;
    Node* prev_n;
    
    Node(int data) : data_n(data), next_n(nullptr), prev_n(nullptr) {}
};

class BidirectionalLinkedList {
public:
    Node* head_n;
    Node* tail_n;

    BidirectionalLinkedList() : head_n(nullptr), tail_n(nullptr) {}

    void insert_back(int data) {
        Node* new_node = new Node(data);
        if (head_n == nullptr) {
            head_n = new_node;
        } else {
            tail_n->next_n = new_node;
            new_node->prev_n = tail_n;
        }
        tail_n = new_node;
    }

    void reverse() {
        Node* current = head_n;
        while (current != nullptr) {
            swap(current->next_n, current->prev_n);
            current = current->prev_n;
        }
        swap(head_n, tail_n);
    }

    void display() {
        Node* current = head_n;
        while (current != nullptr) {
            cout << current->data_n << " ";
            current = current->next_n;
        }
        cout << endl;
    }
};

int main() {
    int n_n;
    
    cin >> n_n;

    vector<int> elements_n(n_n);
    
    for (int i = 0; i < n_n; ++i) {
        cin >> elements_n[i];
    }

    BidirectionalLinkedList linked_list;
    for (int i = 0; i < n_n; ++i) {
        linked_list.insert_back(elements_n[i]);
    }

    

    linked_list.reverse();

    
    linked_list.display();

    return 0;
}

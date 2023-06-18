#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Inserting elements in linked list
void InsertElements(Node* &tail, int a) {
    Node* temp = new Node(a);
    tail->next= temp;
    tail = temp;
}

// Detect and remove cycle
void detectRemoveCycle(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* print = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            Node* intersection = fast;
            slow = head;
            while (slow != intersection) {
                prev = intersection;
                slow = slow->next;
                intersection = intersection->next;
            }
            cout << "Cycle is present at " << slow->data << endl;
            prev->next = NULL;
            return;
        }
    }

    while (print != NULL) {
        cout << print->data << " ";
        print = print->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;
    Node* cycle = head;

    InsertElements(tail, 12);
    InsertElements(tail, 15);
    InsertElements(tail, 18);
    InsertElements(tail, 20);
    InsertElements(tail, 22);
    InsertElements(tail, 25);
    InsertElements(tail, 30);
    cycle = cycle->next->next;
    head->next = cycle;
  
    detectRemoveCycle(head);

    return 0;
}

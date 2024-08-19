#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    long long val;
    struct node* next;
} Node;

void remove_cycle(Node* head) {

    Node *slow = head, *fast = head;

    bool cycle_found = false;

    while(fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cycle_found = true;
            break;
        }
    }

    fast = head;

    Node* prev = slow;
    while(fast != slow) fast = fast->next, prev = slow, slow = slow->next;

    prev->next = nullptr;
}

void solve(long long testcase) {
    long long n;
    cin >> n;

    Node* head = new Node();
    Node* curr = head;

    vector<Node*> nodes(n);

    for (long long i = 0, temp; i < n; ++i) {
        cin >> temp;
        Node* t = new Node();
        t->val = temp;
        curr->next = t;

        curr = curr->next;
        nodes[i] = curr; 
    }

    head = head->next;

    long long last_node_connection;
    cin >> last_node_connection;

    curr->next = nodes[last_node_connection];

    remove_cycle(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << "\n";
}

int main() {
    ifstream in("input/input_file");
    cin.rdbuf(in.rdbuf());

    long long testcases;
    cin >> testcases;
    
    for (long long tc = 1; tc <= testcases; ++tc) {
        solve(tc);
    }

    return 0;
}
#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    long long val;
    struct node* next;
} Node;

Node* reverse_linked_list(Node* head) {
    Node* prev = nullptr, *curr = head, *temp;

    while (curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;

        curr = temp;
    }

    return prev;
}

void solve(long long testcase) {
    long long n;
    cin >> n;

    Node* head = new Node();
    Node* curr = head;


    for (long long i = 0, temp; i < n; ++i) {
        cin >> temp;
        Node* t = new Node();
        t->val = temp;
        curr->next = t;

        curr = curr->next;
    }

    // new head 
    head = head->next;

    head = reverse_linked_list(head);

    while(head) cout << head->val << " ", head = head->next;
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
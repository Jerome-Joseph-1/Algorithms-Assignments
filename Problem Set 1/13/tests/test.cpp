#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct node {
    long long val;
    struct node* next;
} Node;

string GREEN = "\033[32m";
string RED = "\033[31m";
string WHITE = "\033[37m";

long long UPPER_LIMIT = 1e5;

bool is_cycle_present(Node* head) {

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

    return cycle_found;
}

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
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

        if(last_node_connection != -1) {
            curr->next = nodes[last_node_connection];
        }

        bool actual_output = is_cycle_present(head);
        bool expected_output = last_node_connection != -1;

        cout << "Test Case: " << tc << " ";
        if(actual_output == expected_output) {
            passed_tc++;
            cout << GREEN << "Passed. " << WHITE;
        } else {
            cout << RED << "Failed. " << WHITE;
        }
        cout << "\n";
    }

    cout << (passed_tc == t ? GREEN : RED)
              << ("Passed")
              << " (" 
              << (passed_tc == t ? GREEN : RED)
              << passed_tc << " / " << t 
              << WHITE << ")" << endl;  
    return 0;
}   
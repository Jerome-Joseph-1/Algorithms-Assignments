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

int main() {
    ifstream in("../input/input_file");
    cin.rdbuf(in.rdbuf());

    long long t;
    cin >> t;

    long long passed_tc = 0;

    for (long long tc = 1; tc <= t; ++tc) {
        long long n;
        cin >> n;

        vector<long long> nums(n);
        Node* head = new Node();
        Node* curr = head;


        for (long long i = 0, temp; i < n; ++i) {
            cin >> temp;

            nums[n - i - 1] = temp;
            Node* t = new Node();
            t->val = temp;
            curr->next = t;

            curr = curr->next;
        }

        // new head 
        head = head->next;

        head = reverse_linked_list(head);
        bool passed = true;
        for (long long i = 0; i < n; ++i, head = head->next) {
            if(head->val != nums[i]) {
                passed = false;
                break;
            }
        }

        cout << "Test Case: " << tc << " ";
        if(passed) {
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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> a;
        ListNode* temp = list1;

        if (list1 == NULL && list2 == NULL) return list1;

        while (temp != NULL) {
            a.push_back(temp->val);
            temp = temp->next;
        }

        temp = list2;
        while (temp != NULL) {
            a.push_back(temp->val);
            temp = temp->next;
        }

        sort(a.begin(), a.end());

        if (a.empty()) return nullptr; // Handle empty input lists

        ListNode* head = new ListNode(a[0]);
        temp = head;
        for (int i = 1; i < a.size(); i++) {
            temp->next = new ListNode(a[i]);
            temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;

    // Test case 1
    vector<int> list1_values = {1, 2, 4};
    vector<int> list2_values = {1, 3, 4};
    ListNode* list1 = createLinkedList(list1_values);
    ListNode* list2 = createLinkedList(list2_values);
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    
    cout << "Merged List 1 and List 2: ";
    printLinkedList(mergedList);

    // Clean up memory (optional)
    // You can add a function to delete the linked list nodes if needed

    return 0;
}

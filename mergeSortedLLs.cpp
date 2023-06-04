#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* head1, Node<int>* head2)
{
    // Write your code here.
    if (head1 == NULL) {
            return head2;
        }
        if (head2 == NULL) {
            return head1;
        }
        Node <int> *fh = NULL;
        Node <int> *ft = NULL;
        Node <int> *h1 = head1;
        Node <int> *h2 = head2;
        
        if (h1 -> data < h2 -> data) {
            fh = head1;
            ft = head1;
            h1 = h1 -> next;
        }
        else {
            fh = head2;
            ft = head2;
            h2 = h2 -> next;
        }
        while (h1 && h2) {
            if (h1 -> data < h2 -> data) {
                ft -> next = h1;
                ft = h1;
                h1 = h1 -> next;
            }
            else {
                ft -> next = h2;
                ft = h2;
                h2 = h2 -> next;
            }
        }
        if (h1 != NULL) {
            ft -> next = h1;
        }
        if (h2 != NULL) {
            ft -> next = h2;
        }
        return fh;
        
    }

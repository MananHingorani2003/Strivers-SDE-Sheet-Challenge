int length (Node *head) {
    Node *temp = head;
    int counter = 0;
    while (temp != NULL) {
        counter++;
        temp = temp -> next;
    }

    return counter;
}

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    if (head == nullptr) return head;
    int n = length (head);
    if (K==n) return head -> next;
    int num = n-K;
    Node *temp = head;

    while (--num) {
        temp = temp -> next;
    }

    Node *awesome = temp -> next -> next;
    temp -> next = awesome;

    return head;


}

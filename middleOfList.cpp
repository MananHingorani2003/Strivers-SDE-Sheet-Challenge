int length(Node *head) {
    //Write your code here
        Node *temp = head;
        int counter = 0;
        
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
}

Node *findMiddle(Node *head) {
    // Write your code here
    if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        Node *slow = head;
        Node *fast = head;

        while (fast->next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        int a = length (head);
        if (a%2!=0) return slow;
        else return slow->next;
}

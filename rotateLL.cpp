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

Node *rotate(Node *head, int k) {
     // Write your code here.
     if (head == nullptr || head -> next==nullptr) return head;
        int a = length (head);
        k = k%a;
        if (k==0) return head;
        int fromEnd = a-k;
        Node *temp = head;

        while (--fromEnd) {
            temp = temp -> next;
        }
        Node *head2 = temp->next;
        Node *temp2 = head2;
        temp->next = NULL;

        while (temp2 -> next != NULL) {
            temp2 = temp2 -> next;
        }

        temp2 -> next = head;

        return head2;
}

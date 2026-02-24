struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node pointing to head
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val == val) {
            // remove curr
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    
    return dummy.next;
}
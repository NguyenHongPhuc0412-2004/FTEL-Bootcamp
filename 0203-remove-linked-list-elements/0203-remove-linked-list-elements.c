/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    while(head != NULL && head->val == val)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    if (head == NULL) return NULL;


    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    while(curr != NULL)
    {
        if(curr->val == val)
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else{
        //không xóa node
        prev = curr;
        curr = curr->next;
        }
    }
    return head;
}
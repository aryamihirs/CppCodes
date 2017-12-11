//O(n) O(n)
ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode *temp = head, *isNull = NULL;
        if(head == NULL){
            return isNull;
        }
        else
        {
            while(temp!=NULL){
                st.push(temp->val);
                temp = temp->next;
            }

            temp = head;

            while(temp!=NULL){
                temp->val = st.top();
                st.pop();
                temp = temp->next;
            }

            return head;
        }
    }
// Using pointer O(n) O(1)
    ListNode* reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *temp = head, *Mth_node;
       stack<int> st;
       int M = m - 1, N = n - m + 1;
       if(head == NULL){
           return head;
       }
       while(M--){
           temp = temp->next;
       }
       Mth_node = temp;
       while(N--){
           st.push(temp->val);
           cout << " st.top(): " << st.top();
           temp = temp->next;
       }
       temp = Mth_node;
       N = n - m + 1;
       while(N--){
           temp->val = st.top();
           st.pop();
           temp=temp->next;
       }
       return head;
   }

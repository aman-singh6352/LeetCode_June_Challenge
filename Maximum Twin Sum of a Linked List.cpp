int pairSum(ListNode* head) {
    vector<int> arr;
    ListNode* temp = head;
    while(temp != NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    int ans = INT_MIN, n = arr.size();
    for(int i = 0;i < n/2;i++){
        ans = max(ans, arr[i] + arr[n-i-1]);
    }
    return ans;
}


// Optimal Solution

int pairSum(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = NULL, *curr = slow, *nxt;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    int ans = INT_MIN;
    ListNode* temp1 = head, *temp2 = prev;
    while(temp2 != NULL){
        ans = max(ans, temp1->val + temp2->val);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return ans;
}
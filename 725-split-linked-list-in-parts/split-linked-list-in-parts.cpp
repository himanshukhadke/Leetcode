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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp= head;
        vector<ListNode*> ans;
        int size=0;
        while(temp){
            ++size;
            temp=temp->next;
        }
        int rem= size % k;
        int equal_size = size / k;
        if(k>=size){
            ListNode* temp= head;
            for(int i=0;i<k;++i){
                if(temp){
                    ans.push_back(temp);
                    temp = temp->next;
                    ans.back()->next= NULL;
                }else{
                    ans.push_back(NULL);
                }
            }
        }else{
            ListNode *dymm = NULL;
            ListNode* temp= head;
            while(rem--){
                ans.push_back(temp);
                for(int i=0;i<equal_size;++i){
                    temp = temp->next;
                }
                dymm = temp->next;
                temp->next=NULL;
                temp = dymm;
            }
            while(temp){
                ans.push_back(temp);                
                for(int i=0;i<equal_size-1;++i){
                  temp = temp->next;
                }
                dymm = temp->next;
                temp->next=NULL;
                temp = dymm;
            }
        }
        return ans;
    }
};
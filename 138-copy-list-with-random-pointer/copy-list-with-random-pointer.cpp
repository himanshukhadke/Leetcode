/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void addExtraNode(Node* head){
        Node *temp= head;
        Node *nxt;
        while(temp){
            nxt = temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=nxt;
            temp=nxt;
        }
    }

    void copyRandomPointer(Node *head){
        Node *temp= head;
        while(temp){
            temp->next->random = temp->random!=NULL?temp->random->next:NULL;
            temp=temp->next->next;
        }
    }
    
    Node* returnCopy(Node* head){
        Node *copyHead = NULL,*copy= NULL;
        Node *temp = head;
        while(temp){
            if(copy){
                copy->next=temp->next;
                copy = copy->next;
            }else {
                copyHead=temp->next;
                copy = temp->next;
            }
                 
            temp->next=temp->next->next;    
            temp=temp->next;
        }
        return copyHead;
    }

    Node* copyRandomList(Node* head) {
        // adding extra new node at the end of list
        addExtraNode(head);
        // copying random pointer
        copyRandomPointer(head);
        // return copy
        return returnCopy(head);
    }
};
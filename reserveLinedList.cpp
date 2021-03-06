#include "myhead.h"
/**
Definition for singly-linked list. */ 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *reverseBetween(ListNode *node, int m, int n) {
        int cnt=1;
        ListNode *head;
        ListNode *tail;
        ListNode *root=node;
        ListNode *pre=NULL;
        if(m==n)
        	return node;
        if(node==NULL)
        	return node;
        while(root){
            if(cnt==m){
                head=pre;
                pre=root;
            	root=root->next;

            }else if(cnt>m && cnt <n)
            {

                tail=root->next;
                root->next=pre;
                
                pre=root;
                root=tail;
                cout<<root<<endl;
            }else if(cnt==n){

                tail=root->next;
                root->next=pre;
                if(head){
                    head->next->next=tail;
                    head->next=root;
                }else{

                    node->next=tail;
                    node=root;
                }
                break;
            }else{
                pre=root;
                root=root->next;
            }
            cnt++;
        }
        
        return node;
    }
};
int main(){
	ListNode *head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	Solution s;
	head=s.reverseBetween(head,2,4);
	while(head && true){
		cout<<head->val<<endl;
		head=head->next;
	}
}


#include"myhead.h"

struct Node{
	int val;
	Node * left;
	Node * right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
int maxPath(Node *node,int &maxx){
	if(node == NULL)
		return 0;
	int p1=maxPath(node->left,maxx);
	int p2=maxPath(node->right,maxx);
	if(p1+p2 > maxx){
		maxx=p1+p2;
		cout<<p1<<","<<p2<<endl;
		}
	return max(p1,p2)+1;
}
int main(){
	Node *ph=new Node(1);
	Node *head=new Node(1);
	Node *tmp=head->left=new Node(1);
	tmp->left=new Node(1);
	tmp->right=new Node(1);
	tmp->left->left=new Node(1);
	tmp=head->right=new Node(1);
	tmp->left=new Node(1);
	tmp->left->right=new Node(1);
	tmp->right=new Node(1);
	int maxx=0;
	ph->right=head;
	cout<<maxPath(ph,maxx)<<endl;
	cout<<maxx<<endl;
	
}



#include "myhead.h"


void outcome(int head,int tail){
	for(int i=head;i<=tail;i++)
		cout<<i<<" ";
	cout<<endl;
}
void deal(int n){
	int head=1,tail=2;
	int sum;
	while( head < (n+1)/2 ){
		sum= ( (head+tail)*(tail-head+1) )/2;
		if( sum> n)
			head++;
		else if(sum < n)
			tail++;
		else{
			outcome(head,tail);
			tail++;
		}
	}
}

int main(){
	int n;
	while(cin>>n){
		deal(n);
	}

}

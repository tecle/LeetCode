#include <iostream>
#include<stack>
using namespace std;
class myqueue{
public:
	stack<int> value;
	void enQueue(int v){
		value.push(v);
	}
	int deQueue(){
		if(value.empty())
			return -1;
			
		int v=value.top();
		value.pop();
		if(value.empty())
			return v;
		int ans=deQueue();
		value.push(v);
		return ans;
	}
	bool empty(){
		return value.empty();
	}
};

int main(){
	myqueue q;
	stack<int> s;
	for(int i=0;i<10;i++){
		q.enQueue(i);
		s.push(i);
		}
	while(!q.empty())
		cout<<q.deQueue()<<endl;
		
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
		}
	
}

#include<iostream>
#include<vector>
using namespace std;
class A{
	public:
		short a;
		long long b;
		A(int a,int b){
			this->a=a;
			this->b=b;
		}
};
struct B{
	short a;
	long b;
};
int main(){
	int p=2;
	int *p1=&p;
	short ii;
	vector<char> v1;
	vector<int> v2;
	vector<int> v3(2,3);
	A cc(1,2);
	int a[100];
	char a1[]="aaa";
	cout<<sizeof(p)<<endl;
	cout<<sizeof(p1)<<endl;
	cout<<sizeof(v1)<<endl;
	cout<<sizeof(&v2)<<endl;
	cout<<sizeof(v3)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(a1)<<endl;
	cout<<sizeof(cc)<<endl;
	cout<<sizeof(B)<<endl;
	cout<<sizeof(ii)<<endl;
	return 0;
}

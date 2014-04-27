#include<iostream>
#include<stdexcept>

using namespace std;

int showExcept(int i){
	if(i==0){
		throw runtime_error("zero!");
		return 0;	
	}
	return 2/i;

}
int main(){
	cout<<showExcept(1)<<endl;
	cout<<showExcept(0)<<endl;
}

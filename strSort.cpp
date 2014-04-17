#include<iostream>
#include<vector>
using namespace std;
void prtSort(char * str,char * now){
	if(*now == '\0'){
		cout<<str<<endl;
		return;
	}
	char *head=now;
	char tmp;
	while( (*head)!='\0' ){
		//if( (*now)!=(*head) ){
			tmp=*now;
			*now=*head;
			*head=tmp;
			prtSort(str,now+1);
			tmp=*now;
			*now=*head;
			*head=tmp;
		//}
		
		head++;
	}
}

void permutation(char *pStr,char *pBegin){
	if(*pBegin == '\0'){
		cout<<pStr<<endl;
	}else{
		for(char* pCh=pBegin;*pCh!='\0';++pCh){
			char tmp=*pCh;
			*pCh = *pBegin;
			*pBegin=tmp;
			
			permutation(pStr,pBegin+1);
			
			tmp=*pCh;
			*pCh=*pBegin;
			*pBegin=tmp;
		}
	}
}
void permutation(char *pStr){
	if(pStr==NULL)
		return;
	permutation(pStr,pStr);
}
int main(){
	char * str;
	while(cin>>str){
		prtSort(str,str);
	}
	return 0;
}

#include "myhead.h"

class Solutions {
public:
    vector<vector<int> > flag;
    //vector<vector<int> > rcd;
    int minCut(string s) {
        
        int slen=s.size();
        
        vector<int> t(slen);
        for(int i=0;i<slen;i++){
            flag.push_back(t);
            //rcd.push_back(t);
            }
        
        return getMin(s,0,slen-1);
    }
    bool isPalindrome(const string &s ,int i,int j){
    	if(i==j)
    		return true;

        while(i<j){
            if(s[i]!=s[j]){
                return false;
               	//rcd[i][j]=-1;
               }
            i++;
            j--;
        }
        //rcd[i][j]=1;
        return true;
    }
    int getMin(const string &s,int head,int tail){
        //cout<<head<<","<<tail<<endl;
    	if(head==tail)
    		return 0;
    	if(flag[head][tail]>0)
    		return flag[head][tail]-1;
    	int i,j;
    	int tmp,minC=s.size();
    	//this string is a parlindrom,return
    	if(isPalindrome(s,head,tail))
    		return 0;
    	
    	for(i=head+1;i<=tail;i++){
    		tmp=1+getMin(s,head,i-1)+getMin(s,i,tail);
    		if(tmp<minC)
    			minC=tmp;
    		if(minC==1)
    			break;
    	}
    	flag[head][tail]=minC+1;
    	return minC;
    }
};
int main(){
	Solutions s;
	time_t start,end,time;
	start=clock();
	//s.f("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi");
	cout<<s.minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp")<<endl;
	end=clock();
	cout<<-start+end<<endl;

}

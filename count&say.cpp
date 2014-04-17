#include "myhead.h"
class Solution {
public:
    string countAndSay(int n) {
        vector<int> seq1;
        vector<int> seq2;
        string s="";
        if(n==0)
            return s;
        seq1.push_back(1);
        int cnt=0,pre=-1;
        int i,j;
        vector<int> *now=&seq1;
        vector<int> *partner=&seq2;
        for(i=2;i<=n;i++){
            //遍历当前向量中的元素，统计出现的次数
            cnt=1;
            //-1是不会与其它数相等的
            pre=-1;
            (*partner).clear();
            //对当前向量中的每个元素进行统计
            for(j=0;j<(*now).size();j++){

                if((*now)[j]==pre){
                    cnt++;
                }else{
					
                    //不相等时，记录当前的元素，计数器不变，并且对前一个数进行格式化。
					if(pre!=-1){
						(*partner).push_back(cnt);
						(*partner).push_back(pre);
					}
                    pre=(*now)[j];
                    cnt=1;
                }
            }
			//最后的元素并没有计入统计中
			(*partner).push_back(cnt);
			(*partner).push_back(pre);
            //交换伙伴向量和结果向量的位置
            if(now==&seq1){
                now=&seq2;
                partner=&seq1;
            }else{
                now=&seq1;
                partner=&seq2;
            }
        }
        //处理完成，结果再now中
		for(i=0;i<(*now).size();i++)
			s.append(1,(*now)[i]+'0');
		return s;
    }

};

int main(){
	Solution s;
	int n;
	while(cin>>n){
		cout<<s.countAndSay(n)<<endl;
	}
}

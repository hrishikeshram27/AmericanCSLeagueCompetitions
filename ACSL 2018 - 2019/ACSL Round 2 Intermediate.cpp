#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

string diff(string input1,string input2){
	string result="";
	for(int i=0;i<input1.length();i++){
	    int charPos = input2.find(input1[i]);
        if(charPos>=0 && charPos<input2.length()){
            result += input1[i];
            input2 = input2.substr(charPos+1);
        }
	}
	return result;
}

string commonChar(string result1,string result2,string result3,string result4){
	string common = "";
	for(int i=0;i<result1.length();i++){
		for(int j=0;j<result2.length();j++){
			for(int k=0;k<result3.length();k++){
				for(int h=0;h<result4.length();h++){
					if(result1[i]==result2[j] && result2[j]==result3[k] && result3[k]==result4[h]){ //if all are equal
						//to make sure no duplicates are added to common
						int already = common.find(result1[i]);
						if(already<0 || already>=common.length()){
							common += result1[i];
						}
					}
				}
			}
		}
	}
	return common;
}

int main(){
	ifstream myFile("S://Public/CS/int2.txt");
	string in1;
	for(int i=0;i<5;i++){
		getline(myFile, in1);
		string input1 = in1.substr(0,in1.find(" "));
		string input2 = in1.substr(in1.find(" "));
		string rev1(input1.rbegin(),input1.rend());
		string rev2(input2.rbegin(),input2.rend());
		string result1 = diff(input1,input2);
		string result2 = diff(input2,input1);
		string result3 = diff(rev1,rev2);
		string result4 = diff(rev2,rev1);
		string finalStr = commonChar(result1,result2,result3,result4);
		sort(finalStr.begin(),finalStr.end());
		if(finalStr.length()==0){
            cout<<"NONE"<<endl;
        }else{
            cout<<finalStr<<endl;
        }
	}
	return 0;
}

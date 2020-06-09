#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

string delSpaces(string input){
    for(int i=0;i<input.length();i++){
        if(input[i]==' '){
            input.erase(i,1);
        }
    }
    return input;
}

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

string delWords(string input1,string input2){
    string result = "";
    vector <int> spaces1;
    spaces1.push_back(-1);
    for(int i=0;i<input1.length();i++){
        if(input1[i]==' '){
            spaces1.push_back(i);
        }
    }
    string words1[spaces1.size()];
    for(int i=0;i<spaces1.size()-1;i++){
        words1[i] = input1.substr(spaces1[i]+1,spaces1[i+1]-spaces1[i]-1);
    }
    words1[spaces1.size()-1] = input1.substr(spaces1[spaces1.size()-1]+1);
    for(int i=0;i<spaces1.size();i++){
        int posWord = input2.find(words1[i]);
        int wordLen = words1[i].length();
        if(posWord>=0 && posWord<input2.length()){
            result += (words1[i] + " ");
            input2.erase(posWord,wordLen);
        }
    }
    if(result[result.length()-1]==' '){result.erase(result.length()-1,1);}
    return result;
}

int main(){
    ifstream myFile("S://Public/CS/sr2.txt");
    for(int i=0;i<5;i++){
        string input1,input2;
        getline(myFile,input1);
        while(input1.length()==0){
            getline(myFile,input1);
        }
        getline(myFile,input2);
        while(input2.length()==0){
            getline(myFile,input2);
        }
        string finalStr = diff(delSpaces(delWords(input1,input2)),delSpaces(delWords(input2,input1)));
        if(finalStr.length()==0){cout<<"NONE"<<endl;}
        else{cout<<finalStr<<endl;}
    }
    return 0;
}

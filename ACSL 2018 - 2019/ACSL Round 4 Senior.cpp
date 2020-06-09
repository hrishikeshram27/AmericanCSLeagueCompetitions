#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int switcher(int a, int b, int c){
    if(a>0){
        return b;
    }else{
        return c;
    }
}

int maxer(int a, int b, int c){
    int maxNum;
    if(a>=b){
        maxNum = a;
    }else{
        maxNum = b;
    }
    if(c>=maxNum){
        maxNum = c;
    }
    return maxNum;
}

bool checkInt(string input){
	if(input=="0"){
		return true;
	}else{
		if(atoi(input.c_str())==0){
			return false;
		}else{
			return true;
		}
	}
}

int maxleft(vector <string> split){
	int counter = 0;
	for(int i=0;i<split.size();i++){
		if(split[i]=="@" || split[i]==">"){
			counter+=3;
		}else if(split[i]=="+" || split[i]=="-" || split[i]=="*"){
			counter+=2;
		}else if(split[i]=="|"){
            counter+=1;
		}
	}
	return counter;
}

string intToStr(int x){
    ostringstream y;
    y << x;
    return y.str();
}

void splitStr(string input, vector <string> &split){
    vector <int> spaces;
    spaces.push_back(-1);
    for(int i=0;i<input.length();i++){
        if(input[i]==' '){
            spaces.push_back(i);
        }
    }
    for(int i=0;i<spaces.size()-1;i++){
        split.push_back(input.substr(spaces[i]+1,spaces[i+1]-spaces[i]-1));
    }
    split.push_back(input.substr(spaces[spaces.size()-1]+1));
}

void evaluate(vector <string> &split){
	int counter=0;
	int limit = maxleft(split);
	while(split.size()>limit){
		if(!checkInt(split[counter])){
			if(split[counter]=="@" && (counter+3)<split.size() && checkInt(split[counter+1]) && checkInt(split[counter+2]) && checkInt(split[counter+3])){
				int temp = switcher(atoi(split[counter+1].c_str()), atoi(split[counter+2].c_str()), atoi(split[counter+3].c_str()));
				split.erase(split.begin()+counter,split.begin()+counter+4);
                split.insert(split.begin()+counter, intToStr(temp));
			}else if(split[counter]==">" && (counter+3)<split.size() && checkInt(split[counter+1]) && checkInt(split[counter+2]) && checkInt(split[counter+3])){
				int temp = maxer(atoi(split[counter+1].c_str()), atoi(split[counter+2].c_str()), atoi(split[counter+3].c_str()));
				split.erase(split.begin()+counter,split.begin()+counter+4);
                split.insert(split.begin()+counter, intToStr(temp));
			}else if(split[counter]=="+" && (counter+2)<split.size() && checkInt(split[counter+1]) && checkInt(split[counter+2])){
				int temp = atoi(split[counter+1].c_str()) + atoi(split[counter+2].c_str());
				split.erase(split.begin()+counter,split.begin()+counter+3);
                split.insert(split.begin()+counter, intToStr(temp));
			}else if(split[counter]=="-" && (counter+2)<split.size() && checkInt(split[counter+1]) && checkInt(split[counter+2])){
				int temp = atoi(split[counter+1].c_str()) - atoi(split[counter+2].c_str());
				split.erase(split.begin()+counter,split.begin()+counter+3);
                split.insert(split.begin()+counter, intToStr(temp));
			}else if(split[counter]=="*" && (counter+2)<split.size() && checkInt(split[counter+1]) && checkInt(split[counter+2])){
				int temp = atoi(split[counter+1].c_str()) * atoi(split[counter+2].c_str());
				split.erase(split.begin()+counter,split.begin()+counter+3);
                split.insert(split.begin()+counter, intToStr(temp));
			}else if(split[counter]=="|" && (counter+1)<split.size() && checkInt(split[counter+1])){
                int temp = fabs(atoi(split[counter+1].c_str()));
                split.erase(split.begin()+counter,split.begin()+counter+2);
                split.insert(split.begin()+counter, intToStr(temp));
			}
		}
		counter++;
	}
}

int main(){
	ifstream myFile("F://sr4.txt");
	string input;
	while(getline(myFile,input)){
		vector <string> manip;
		splitStr(input, manip);
		while(manip.size()>1){evaluate(manip);}
		cout<<manip[0]<<endl;
	}
	return 0;
}

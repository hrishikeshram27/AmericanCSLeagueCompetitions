#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<math.h>
using namespace std;

int strToInt1(string input){
    int output = 0;
    int counter = input.length()-1;
    for(int i=0;i<input.length();i++){
        output += (input[i] - '0')*pow(10,counter);
        counter--;
    }
    return output;
}

string addStr(string input1,string input2){
    string output;
    if(input2.length()<input1.length()){
        while(input2.length()<input1.length()){
            input2.insert(0,"0");
        }
    }else if(input1.length()<input2.length()){
        while(input1.length()<input2.length()){
            input1.insert(0,"0");
        }
    }
    int digit1,digit2,num1,carry=0;
    vector <char> sum;
    for(int i=input1.length()-1;i>=0;i--){
        digit1 = input1[i] - '0';
        digit2 = input2[i] - '0';
        num1 = digit1 + digit2 + carry;
        carry=0;
        if(num1>9){
            carry=1;
            num1 = (num1-10);
            sum.insert(sum.begin(),(num1 + '0'));
        }else{
            sum.insert(sum.begin(),(num1 + '0'));
        }
    }
    if(carry!=0){
        sum.insert(sum.begin(),(carry + '0'));
    }
    for(int i=0;i<sum.size();i++){
        output+=sum[i];
    }
    return output;
}

int main(){
    ifstream myFile("D://ACSL1Senior.txt");
    for(int x=0;x<5;x++){
        string input1;
        getline(myFile,input1);
        int split1 = input1.find(" ");
        string numStr1 = input1.substr(0,split1);
        string iterStr1 = (input1.substr(split1+1));
        int iterNum1 = strToInt1(iterStr1);
        string sum = "0";
        while(numStr1.length()>=iterNum1){
            string looper = numStr1.substr(0,iterNum1);
            sum = addStr(sum,looper);
            numStr1 = numStr1.substr(iterNum1);
        }
        numStr1.insert(numStr1.end(),(iterNum1-numStr1.length()),'0');
        sum = addStr(sum,numStr1);
        cout<<"Input: "<<input1<<endl<<"Output: "<<sum<<endl<<endl;
    }
    return 0;
}

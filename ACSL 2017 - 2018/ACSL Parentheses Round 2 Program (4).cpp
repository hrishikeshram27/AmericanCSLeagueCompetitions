//Hrishikesh Ram Period 4A

#include<iostream>
#include<string>
using namespace std;

void calcPos(string &a){
    int parenPos;
    char parenType;
    int strLen = a.length();
    if(a.find(")")!=-1){
        parenPos = a.find(")");
        parenType = 'a';
    }else if(a.find("(")!=-1){
        parenPos = a.find("(");
        parenType = 'b';
    }

    int possible;
    if(parenType == 'b'){
        if(parenPos >= 0 && parenPos <= strLen){
            possible = parenPos+4;
            while(possible<=strLen){
                cout<<possible+1<<", ";
                possible+=2;
            }
        }
    }else if(parenType == 'a'){
        if(parenPos >= 0 && parenPos <= strLen){
            possible = 0;
            while(possible<=(parenPos-2)){
                cout<<possible+1<<", ";
                possible+=2;
            }
        }
    }
}

int main(){
    string a,b,c,d,e;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    cout<<endl;
    calcPos(a);
    cout<<endl;
    calcPos(b);
    cout<<endl;
    calcPos(c);
    cout<<endl;
    calcPos(d);
    cout<<endl;
    calcPos(e);
    cout<<endl;

    return 0;
}

//Hrishikesh Ram 4A

#include<iostream>
#include<vector>
#include<string>
#include<locale>
#include<algorithm>
using namespace std;

string delSpaces(string &str)
{
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

int main(){
    //gather inputs
    locale loc;
    string dummy;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string a;
    int aNum;
    cin>>aNum;
    getline(cin,dummy);
    getline(cin,a);
    //changing original a to uppercase and remove spaces
    for(int i=0;i<a.size();i++){
        a[i] = toupper(a[i],loc);
    }
    delSpaces(a);
    //making a2 equal to a, and then sorting it
    string a2 = a.substr(0,aNum-1);
    sort(a2.begin(),a2.end());
    int counter = 1;
    char occupant = a2[aNum];
    for(int j=aNum;j<a.size();j++){
        if(alphabet.find(a[j])<alphabet.find(occupant)){
            occupant = a[j];
            counter++;
        }
    }
    cout<<counter;        //figure out how to insert values in correct spot and track number of passages through placement
    return 0;
}

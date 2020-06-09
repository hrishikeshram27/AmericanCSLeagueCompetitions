//Hrishikesh Ram 4A

#include<iostream>
#include <sstream>
#include<vector>
#include<string>
#include<locale>
#include<algorithm>
using namespace std;

//function to delete spaces
string delSpaces(string &str){
   str.erase(remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

void output(){
    //setup inputs
    string dummy;
    string a;
    int aNum;

    //take inputs
    cin>>aNum;
    getline(cin,dummy);
    getline(cin,a);

    //changing original string to uppercase
    locale loc;
    for(int i=0;i<a.size();i++){
        a[i] = toupper(a[i],loc);
    }

    //delete spaces from string
    delSpaces(a);

    //get sorted version of string until the correct position
    string aSorted = a.substr(0,aNum);
    sort(aSorted.begin(),aSorted.end());

    //setup counter and alphabet
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int counter = 1;

    //setup occupant and temp storage for occupant
    char occupant = aSorted[aNum-1];
    char temp = occupant;

    //increment counter whenever a letter should shift the string, repeats excluded
    for(int i=aNum;i<a.size();i++){
        if(alphabet.find(a[i]) < alphabet.find(occupant)){
            aSorted.push_back(a[i]);
            sort(aSorted.begin(),aSorted.end());
            occupant = aSorted[aNum-1];
            if(occupant != temp){
                counter++;
                temp = occupant;
            }else{continue;}
        }
    }

    //output counter
    cout<<counter;
}


int main(){
    //take 5 lines of inputs
    output();
    output();
    output();
    output();
    output();

    //end program by returning 0
    return 0;
}

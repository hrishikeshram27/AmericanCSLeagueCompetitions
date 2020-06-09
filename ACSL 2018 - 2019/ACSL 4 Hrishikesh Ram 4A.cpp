//Hrishikesh Ram 4A

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string delSpaces(string &str){
   str.erase(remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

int trackPos(string &unsorted, int &pos){
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int counter = 0;
    int counter2 = 0;
    char posTracker;
    char posTracker2;
    vector <char> tracker;
    tracker.push_back(unsorted[0]);
    for(int i=1;i<unsorted.size();i++){
        if(alphabet.find(unsorted[i])>alphabet.find(unsorted[i-1])){
            tracker.insert(tracker.end(),unsorted[i]);
        }
        else if(alphabet.find(unsorted[i])<=alphabet.find(unsorted[i-1])){
            tracker.insert(tracker.begin()+(i-1),unsorted[i]);
        }
        if(tracker[pos]){
            counter++;
            posTracker = tracker[pos];
            if(counter2<1){
                posTracker2 = posTracker;
                counter2++;
            }
        }
        if(posTracker!=posTracker2){
            counter++;
        }
        continue;
    }
    for(int i=0;i<tracker.size();i++){
        cout<<tracker[i];
    }
    cout<<endl;
    return counter;
}

int main(){
    string dummy;
    int a;
    string a1;
    cin>>a;
    getline(cin,dummy);
    getline(cin,a1);
    int b;
    string b1;
    cin>>b;
    getline(cin,dummy);
    getline(cin,b1);
    int c;
    string c1;
    cin>>c;
    getline(cin,dummy);
    getline(cin,c1);
    int d;
    string d1;
    cin>>d;
    getline(cin,dummy);
    getline(cin,d1);
    int e;
    string e1;
    cin>>e;
    getline(cin,dummy);
    getline(cin,e1);
    a1 = delSpaces(a1);
    b1 = delSpaces(b1);
    c1 = delSpaces(c1);
    d1 = delSpaces(d1);
    e1 = delSpaces(e1);
    transform(a1.begin(), a1.end(), a1.begin(), ::toupper);
    transform(b1.begin(), b1.end(), b1.begin(), ::toupper);
    transform(c1.begin(), c1.end(), c1.begin(), ::toupper);
    transform(d1.begin(), d1.end(), d1.begin(), ::toupper);
    transform(e1.begin(), e1.end(), e1.begin(), ::toupper);
    string a2,b2,c2,d2,e2;
    a2 = a1;
    b2 = b1;
    c2 = c1;
    d2 = d1;
    e2 = e1;
    sort(a2.begin(),a2.end());
    sort(b2.begin(),b2.end());
    sort(c2.begin(),c2.end());
    sort(d2.begin(),d2.end());
    sort(e2.begin(),e2.end());
    cout<<trackPos(a1,a)<<endl<<trackPos(b1,b)<<endl<<trackPos(c1,c)<<endl<<trackPos(d1,d)<<trackPos(e1,e);
    return 0;
}

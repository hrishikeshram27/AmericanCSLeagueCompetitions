//Hrishikesh Ram 4A

//REFERNCE FOR INT TO STRING AND STRING TO INT, ERASING STRINGS, ETC.
//INPUTS NEED FORMATTING, AND IF FILE INPUT IS REQUIRED, THAT CAN BE ADDED, BUT OTHERWISE, PROGRAM WORKS WELL!!!!!!!!!!!!!!!!!!!!

#include<iostream> //standard
#include<string> //includes to_string for int to string
#include<sstream> //includes stringstream for string to int
using namespace std;

//function to reverse digits in the integer
int reverseDigits(int &original){
    //convert original int to string with following:
    //step 1: use "output string stream" like so:
    ostringstream intStr;
    //step 2: send number into output string stream like so:
    intStr << original;
    //declare string variable to hold converted int, and set it equal to a converted string like so:
    string original1 = intStr.str();

    //string to hold reversed number in form of string
    string reversed1;

    //for loop iterates through string backwards
    for(int i=0;i<original1.size();i++){
        //temporary string to hold char by pushing back, since can't insert char into string
        string temp;
        temp.push_back(original1[i]);
        //insert the temp string into reversed1
        reversed1.insert(0,temp);
        //erase the temp string to do it again in the next loop-around
        temp.erase(temp.begin());
    }
    //int to hold reversed number in correct int form
    int reversed;

    //use stringstream to stream an int form of reversed string to the int variable
    stringstream(reversed1) >> reversed;

    return reversed;
}

void findPalindrome(int a){
    //do the first sum
    int xtemp = a + reverseDigits(a);

    //set boolean variable to make sure that if one sum isn't palindrome, then print NONE and the last sum
    bool palindrome = false;

    //do the next 9 sums and break the loop if one of them is a palindrome, and if one isn't, set boolean variable to false in order to then print NONE and the last sum
    for(int i=0;i<9;i++){
        if(xtemp == reverseDigits(xtemp)){
            palindrome = true;
            cout<<xtemp<<endl;
            break;
        }
        xtemp = xtemp + reverseDigits(xtemp);
        continue;
    }

    //if boolean variable is false, then print NONE and last sum
    if(!palindrome){
        cout<<"NONE, "<<xtemp<<endl;
    }
}

int main(){
    //declare and gather 5 inputs
    int a,b,c,d,e;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;

    //call function to find palindrome on 5 inputs
    findPalindrome(a);
    findPalindrome(b);
    findPalindrome(c);
    findPalindrome(d);
    findPalindrome(e);

    //return 0 to end program
    return 0;
}

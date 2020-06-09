//Hrishikesh Ram Period 4A

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<string>
#include<locale>
#include<algorithm>
using namespace std;

//function to delete all spaces
string delSpaces(string &str){
    //erase all spaces
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    //return string with no spaces
    return str;
}

//function to take inputs and format them
void input(int &numberFromStr1, string &word1,int &numberFromStr2, string &word2,int &numberFromStr3, string &word3,int &numberFromStr4, string &word4,int &numberFromStr5, string &word5, string &readIn1, string &readIn2, string &readIn3, string &readIn4, string &readIn5){
    //open file to read in from
    ifstream myFile;
    myFile.open("S://Public/CS/check/jr.txt");

    //get the lines from the file,use dummy to bypass blank inputs
    getline(myFile,readIn1);
    getline(myFile,readIn2);
    getline(myFile,readIn3);
    getline(myFile,readIn4);
    getline(myFile,readIn5);

    //find the space
    int spacePos1 = readIn1.find(' ');
    int spacePos2 = readIn2.find(' ');
    int spacePos3 = readIn3.find(' ');
    int spacePos4 = readIn4.find(' ');
    int spacePos5 = readIn5.find(' ');

    //everything after space is word
    word1 = readIn1.substr(spacePos1+1,readIn1.size()-1);
    word2 = readIn2.substr(spacePos2+1,readIn2.size()-1);
    word3 = readIn3.substr(spacePos3+1,readIn3.size()-1);
    word4 = readIn4.substr(spacePos4+1,readIn4.size()-1);
    word5 = readIn5.substr(spacePos5+1,readIn5.size()-1);

    //delete accidental spaces from word
    delSpaces(word1);
    delSpaces(word2);
    delSpaces(word3);
    delSpaces(word4);
    delSpaces(word5);

    //everything uppercase
    locale loc;
    for(int i=0;i<word1.size();i++){
        word1[i] = toupper(word1[i],loc);
    }
    for(int i=0;i<word2.size();i++){
        word2[i] = toupper(word2[i],loc);
    }
    for(int i=0;i<word3.size();i++){
        word3[i] = toupper(word3[i],loc);
    }
    for(int i=0;i<word4.size();i++){
        word4[i] = toupper(word4[i],loc);
    }
    for(int i=0;i<word5.size();i++){
        word5[i] = toupper(word5[i],loc);
    }

    //everything before space is number, delete accidental spaces, convert string to int
    string number1 = readIn1.substr(0,spacePos1);
    delSpaces(number1);
    numberFromStr1 = atoi(number1.c_str());
    string number2 = readIn2.substr(0,spacePos2);
    delSpaces(number2);
    numberFromStr2 = atoi(number2.c_str());
    string number3 = readIn3.substr(0,spacePos3);
    delSpaces(number3);
    numberFromStr3 = atoi(number3.c_str());
    string number4 = readIn4.substr(0,spacePos4);
    delSpaces(number4);
    numberFromStr4 = atoi(number4.c_str());
    string number5 = readIn5.substr(0,spacePos5);
    delSpaces(number5);
    numberFromStr5 = atoi(number5.c_str());

    //close file
    myFile.close();

    //function stores values in numberFromStr variables for the int, and word variables for the string, and the entire line in the readIn variables
}

//output function that returns final value
int output(string &original, int &aNum){
    //get sorted version of string until the correct position
    string aSorted = original.substr(0,aNum);
    sort(aSorted.begin(),aSorted.end());

    //setup counter and alphabet
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int counter = 1;

    //setup current occupant and temp storage for occupant
    char occupant = aSorted[aNum-1];
    char temp = occupant;

    //increment counter whenever a letter should shift the string, repeats excluded
    for(int i=aNum;i<original.size();i++){
        //if the current letter would go before occupant and shift the string, and there are no repeats, then increment counter value and update current occupant and temp values
        if(alphabet.find(original[i]) < alphabet.find(occupant)){
            //if alphabetically earlier, then put current letter in, sort, and pick up new occupant
            aSorted.push_back(original[i]);
            sort(aSorted.begin(),aSorted.end());
            occupant = aSorted[aNum-1];

            //make sure of no repeats, update temp and increment counter
            if(occupant != temp){
                counter++;
                temp = occupant;
            }else{continue;}
        }
    }

    //return counter
    return counter;
}

//main function
int main(){
    //create readIn strings to take entire input
    string readIn1,readIn2,readIn3,readIn4,readIn5;

    //create strings to take parsed string from readIn input strings
    string word1,word2,word3,word4,word5;

    //create integers to take parsed integer from readIn input strings
    int number1,number2,number3,number4,number5;

    //call input function to take inputs and format everything
    input(number1,word1,number2,word2,number3,word3,number4,word4,number5,word5,readIn1,readIn2,readIn3,readIn4,readIn5);

    //output everything, nicely formatted
    cout<<"Input line #1: "<<readIn1<<endl<<"Output #1: "<<output(word1,number1)<<endl;
    cout<<"Input line #2: "<<readIn2<<endl<<"Output #2: "<<output(word2,number2)<<endl;
    cout<<"Input line #3: "<<readIn3<<endl<<"Output #3: "<<output(word3,number3)<<endl;
    cout<<"Input line #4: "<<readIn4<<endl<<"Output #4: "<<output(word4,number4)<<endl;
    cout<<"Input line #5: "<<readIn5<<endl<<"Output #5: "<<output(word5,number5)<<endl;

    //return 0 to end program
    return 0;
}

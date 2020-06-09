//Hrishikesh Ram 4A

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void increment(string array3[4],int &column, int &row){
    if((array3[row])[column]=='0'){
        (array3[row])[column]='1';
    }else if((array3[row])[column]=='1'){
        (array3[row])[column]='2';
    }else if((array3[row])[column]=='2'){
        (array3[row])[column]='3';
    }else if((array3[row])[column]=='3'){
        (array3[row])[column]='0';
    }
}

void moveLeft(string array3[4],int &column,int &row, int &prevValue){
    if((array3[row])[column]=='1' && column!=0){
        column-=1;
        prevValue = (column)+1;
    }else if((array3[row])[column]=='1' && column==0){
        column=3;
        prevValue = 0;
    }
}

void moveRight(string array3[4],int &column,int &row, int &prevValue){
    if((array3[row])[column]=='0' && column!=3){
        column+=1;
        prevValue = (column)-1;
    }else if((array3[row])[column]=='0' && column==3){
        column=0;
        prevValue = 3;
    }
}

void moveUp(string array3[4],int &column,int &row, int &prevValue){
    if((array3[row])[column]=='2' && row!=0){
        row+=1;
        prevValue = (row)-1;
    }else if((array3[row])[column]=='2' && column==0){
        row=3;
        prevValue = 0;
    }
}

void moveDown(string array3[4],int &column,int &row, int &prevValue){
    if((array3[row])[column]=='3' && row!=3){
        row-=1;
        prevValue = (row)+1;
    }else if((array3[row])[column]=='3' && row==3){
        row=0;
        prevValue = 3;
    }
}


int main(){
    int column=3,row=2;
    int prevValue;
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    while(a.length()<4){
        if(a.length()<4){
            a.insert(0,"0");
        }
    }
    while(b.length()<4){
        if(b.length()<4){
            b.insert(0,"0");
        }
    }
    while(c.length()<4){
        if(c.length()<4){
            c.insert(0,"0");
        }
    }
    while(d.length()<4){
        if(d.length()<4){
            d.insert(0,"0");
        }
    }
    string array1[4] = {a,b,c,d};
    string array2[4] = {a,b,c,d};

    int counter = 0;
    while(counter<6){
        if((array1[row])[column]=='0'){
            moveRight(array1,column,row,prevValue);
            increment(array1,prevValue,row);
        }else if((array1[row])[column]=='1'){
            moveLeft(array1,column,row,prevValue);
            increment(array1,prevValue,row);
        }else if((array1[row])[column]=='2'){
            moveUp(array1,column,row,prevValue);
            increment(array1,column,prevValue);
        }else if((array1[row])[column]=='3'){
            moveDown(array1,column,row,prevValue);
            increment(array1,column,prevValue);
        }
        counter++;
    }




    cout<<endl<<row<<","<<column<<endl;

    return 0;
}

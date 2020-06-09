//Hrishikesh Ram 4A

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void increment(string array3[4],int &walkerX, int &walkerY){
    if((array3[walkerY])[walkerX]=='0'){
        (array3[walkerY])[walkerX]='1';
    }else if((array3[walkerY])[walkerX]=='1'){
        (array3[walkerY])[walkerX]='2';
    }else if((array3[walkerY])[walkerX]=='2'){
        (array3[walkerY])[walkerX]='3';
    }else if((array3[walkerY])[walkerX]=='3'){
        (array3[walkerY])[walkerX]='0';
    }
}

void moveLeft(string array3[4],int &walkerX,int &walkerY, int &prevValue){
    if((array3[walkerY])[walkerX]=='1' && walkerX!=0){
        walkerX-=1;
        prevValue = (walkerX)+1;
    }else if((array3[walkerY])[walkerX]=='1' && walkerX==0){
        walkerX=3;
        prevValue = 0;
    }
}

void moveRight(string array3[4],int &walkerX,int &walkerY, int &prevValue){
    if((array3[walkerY])[walkerX]=='0' && walkerX!=3){
        walkerX+=1;
        prevValue = (walkerX)-1;
    }else if((array3[walkerY])[walkerX]=='0' && walkerX==3){
        walkerX=0;
        prevValue = 3;
    }
}

void moveUp(string array3[4],int &walkerX,int &walkerY, int &prevValue){
    if((array3[walkerY])[walkerX]=='2' && walkerY!=0){
        walkerY+=1;
        prevValue = (walkerY)-1;
    }else if((array3[walkerY])[walkerX]=='2' && walkerX==0){
        walkerY=3;
        prevValue = 0;
    }
}

void moveDown(string array3[4],int &walkerX,int &walkerY, int &prevValue){
    if((array3[walkerY])[walkerX]=='3' && walkerY!=3){
        walkerY-=1;
        prevValue = (walkerY)+1;
    }else if((array3[walkerY])[walkerX]=='3' && walkerY==3){
        walkerY=0;
        prevValue = 3;
    }
}


int main(){
    int walkerX=3,walkerY=2;
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
        if((array1[walkerY])[walkerX]=='0'){
            moveRight(array1,walkerX,walkerY,prevValue);
            increment(array1,prevValue,walkerY);
        }else if((array1[walkerY])[walkerX]=='1'){
            moveLeft(array1,walkerX,walkerY,prevValue);
            increment(array1,prevValue,walkerY);
        }else if((array1[walkerY])[walkerX]=='2'){
            moveUp(array1,walkerX,walkerY,prevValue);
            increment(array1,walkerX,prevValue);
        }else if((array1[walkerY])[walkerX]=='3'){
            moveDown(array1,walkerX,walkerY,prevValue);
            increment(array1,walkerX,prevValue);
        }
        counter++;
    }




    cout<<endl<<walkerY<<","<<walkerX<<endl;

    return 0;
}

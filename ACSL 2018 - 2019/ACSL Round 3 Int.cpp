//Hrishikesh Ram
//3-7-18
//Enloe HS
//Int 5
//Contest #3
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    string finalStr = "";
    //first 4 inputs
    int r,c,s,n;
    ifstream myFile("S://Public/CS/int3.txt");
    int temp;
    vector <int> hold;
    while(myFile>>temp){
        hold.push_back(temp);
    }
    for(int l=0;l<5;l++){
        r=hold[0]; c=hold[1]; s=hold[2]; n=hold[3];
        int grid[r][c]; //declare 2-d array
        if(n>0){
            int blocked[n]; //blocked cells
            for(int i=0;i<n;i++){
                blocked[i] = hold[i+4];
            }

            //set up 2-d array
            for(int i=0;i<r;i++){
                for(int j=1;j<=c;j++){
                    grid[i][j-1] = (c*i)+j;
                    for(int k=0;k<n;k++){
                        if(((c*i)+j)==blocked[k]){
                            grid[i][j-1] = (r*c)+blocked[k]; //subtract (r*c) to get real value of cell
                        }
                    }
                }
            }
        }else{
            //set up 2-d array
            for(int i=0;i<r;i++){
                for(int j=1;j<=c;j++){
                    grid[i][j-1] = (c*i)+j;
                }
            }
        }
        //outputs 2-d array
/*
        cout<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]>(r*c)){
                    cout<<"XX"<<"\t";
                }else{
                    cout<<grid[i][j]<<"\t";
                }
            }
            cout<<endl;
        }
*/

        //location of s in grid: grid[currentR][currentC]
        int currentR = ((s-1)/c);
        int currentC = ((s-1)%c);
        char curLet;

        if(currentC==0){ //left to right
            while(currentC<c){
                if(currentC==0){ //start left side
                    //has to be pieces A or C
                    //A and C both share 2 tiles at top
                    if(grid[currentR][currentC+2]<=(r*c)){ //has to be A
                        finalStr += "A";
                        curLet = 'A';
                        currentC += 3;
                    }else{
                        finalStr += "C";
                        curLet = 'C';
                        currentR += 2;
                        currentC += 2;
                    }
                }else{
                    if(curLet == 'A'){
                        if((currentC+1)<c && (currentR+1)<r && grid[currentR][currentC]<=(r*c) && grid[currentR+1][currentC]<=(r*c) && grid[currentR+1][currentC+1]<=(r*c)){
                            finalStr += "B";
                            currentR++;
                            currentC += 2;
                        }
                        curLet = 'B';
                    }else if(curLet == 'B'){
                        if((currentC+1)<(c-1) && (currentR+2)<r && grid[currentR][currentC]<=(r*c) && grid[currentR][currentC+1]<=(r*c) && grid[currentR+1][currentC+1]<=(r*c) && grid[currentR+2][currentC+1]<=(r*c)){
                            finalStr += "C";
                            curLet = 'C';
                            currentR += 2;
                            currentC += 2;
                        }
                        curLet = 'C';
                    }else if(curLet == 'C'){
                        if((currentC+2)<c && grid[currentR][currentC]<=(r*c) && grid[currentR][currentC+1]<=(r*c) && grid[currentR][currentC+2]<=(r*c)){
                            finalStr += "A";
                            currentC += 3;
                        }
                        curLet = 'A';
                    }
                }
            }
        }else if(currentC==(c-1)){ //right to left: reverse string at end
            while(currentC>=0){
                if(currentC==(c-1)){ //start right side
                    //has to be pieces A or B
                    //A and B both share 2 tiles
                    if(grid[currentR][currentC-2]<=(r*c)){ //has to be A
                        finalStr += "A";
                        curLet = 'A';
                        currentC -= 3;
                    }else{
                        finalStr += "B";
                        curLet = 'B';
                        currentR--;
                        currentC -= 2;
                    }
                }else{
                    if(curLet == 'A'){
                        if((currentC-1)>0 && (currentR-1)>=0 && grid[currentR][currentC]<=(r*c) && grid[currentR-1][currentC-1]<=(r*c) && grid[currentR][currentC-1]<=(r*c)){
                            finalStr += "B";
                            currentR--;
                            currentC -= 2;
                        }
                        curLet = 'B';
                    }else if(curLet == 'B'){
                        if((currentC-1)>=0 && (currentR-2)>=0 && grid[currentR][currentC]<=(r*c) && grid[currentR-1][currentC]<=(r*c) && grid[currentR-2][currentC]<=(r*c) && grid[currentR-2][currentC-1]<=(r*c)){
                            finalStr += "C";
                            currentR -= 2;
                            currentC -= 2;
                        }
                        curLet = 'C';
                    }else if(curLet == 'C'){
                        if((currentC-2)>=0 && grid[currentR][currentC]<=(r*c) && grid[currentR][currentC-1]<=(r*c) && grid[currentR][currentC-2]<=(r*c)){
                            finalStr += "A";
                            currentC -= 3;
                        }
                        curLet = 'A';
                    }
                }
            }
            reverse(finalStr.begin(),finalStr.end());
        }
        cout<<l+1<<". "<<finalStr<<endl;
        hold.erase(hold.begin(),hold.begin()+n+4);
        finalStr = "";
    }
	return 0;
}

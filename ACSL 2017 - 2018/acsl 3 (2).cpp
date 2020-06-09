# include <iostream>
# include <string>
using namespace std;

int nextCoordX(int originalX){
    int updatedI;
    if(originalX == 1){
        updatedI = 1;
    }else if(originalX == 2){
        updatedI = 2;
    }else if(originalX == 3){
        updatedI = 3;
    }else if(originalX == 4){
        updatedI = 4;
    }
    return updatedI;
}

int nextCoordY(int originalY){
    int updatedJ;
    if(originalY == 1){
        updatedJ = 1;
    }else if(originalY == 2){
        updatedJ = 2;
    }else if(originalY == 3){
        updatedJ = 3;
    }else if(originalY == 4){
        updatedJ = 4;
    }
    return updatedJ;
}

int increment1(int originalLow){
    int high = (originalLow%4)+1;
    return high;
}

int decrement1(int originalHigh){
    int low = ((((((originalHigh%4)+1)%4)+1)%4)+1);
    return low;
}

int main(){
    cout<<"Input"<<endl;

    string a;
    string b;
    string c;
    string d;

    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;

    cout<<endl;

    int rowsize = a.length();
    int rowsize2 = b.length();
    int rowsize3 = c.length();
    int rowsize4 = d.length();


    if(rowsize == 2){
        a = "000"+a.substr(0,1);
    }else if(rowsize == 3){
        a = "00"+a.substr(0,2);
    }else if(rowsize == 4){
        a = "0"+a.substr(0,3);
    }else if(rowsize == 5){
        a = a.substr(0,4);
    }

    if(rowsize2 == 2){
        b = "000"+b.substr(0,1);
    }else if(rowsize2 == 3){
        b = "00"+b.substr(0,2);
    }else if(rowsize2 == 4){
        b = "0"+b.substr(0,3);
    }else if(rowsize2 == 5){
        b = b.substr(0,4);
    }

    if(rowsize3 == 2){
        c = "000"+c.substr(0,1);
    }else if(rowsize3 == 3){
        c = "00"+c.substr(0,2);
    }else if(rowsize3 == 4){
        c = "0"+c.substr(0,3);
    }else if(rowsize3 == 5){
        c = c.substr(0,4);
    }

    if(rowsize4 == 1){
        d = "000"+d;
    }else if(rowsize4 == 2){
        d = "00"+d;
    }else if(rowsize4 == 3){
        d = "0"+d;
    }else if(rowsize4 == 4){
        d = d;
    }

    for(int i=0; i<5; i++){
        string array1 [5][5];

        for(int i=0; i<4; i++){
            array1[1][i+1] = a.substr(i,1);
            array1[2][i+1] = b.substr(i,1);
            array1[3][i+1] = c.substr(i,1);
            array1[4][i+1] = d.substr(i,1);
        }

        int inputI;
        int inputJ;

        cout<<"Input:"<<endl;

        cin>>inputI;
        cin>>inputJ;

        int currenti, currentj;
        int originalI, originalJ;


        originalI = inputI;
        originalJ = inputJ;
        currenti = nextCoordX(originalI);
        currentj = nextCoordY(originalJ);

        for(int j=0; j<6; j++){
            if(array1[originalI][originalJ] == "0"){
                currenti = originalI;
                currentj = increment1(originalJ);
            }else if(array1[originalI][originalJ] == "1"){
                currenti = originalI;
                currentj = decrement1(originalJ);
            }else if(array1[originalI][originalJ] == "2"){
                currenti = decrement1(originalI);
                currentj = originalJ;
            }else if(array1[originalI][originalJ] == "3"){
                currenti = increment1(originalI);
                currentj = originalJ;
            }

            if(array1[originalI][originalJ] == "0"){
                array1[originalI][originalJ] = "1";
            }else if (array1[originalI][originalJ] == "1"){
                array1[originalI][originalJ] = "2";
            }else if (array1[originalI][originalJ] == "2"){
                array1[originalI][originalJ] = "3";
            }else if (array1[originalI][originalJ] == "3"){
                array1[originalI][originalJ] = "0";
            }

            originalI = currenti;
            originalJ = currentj;
        }
        cout<<currenti<<", "<<currentj<<endl;
    }
    return 0;
}

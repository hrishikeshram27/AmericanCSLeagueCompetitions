//Hrishikesh Ram, ACSL Program
//Period 4A

#include<iostream>
using namespace std;


void input(int array1[], int array2[], int array3[], int array4[], int array5[]){
    cout<<"1. ";
    cin>>array1[0]>>array1[1]>>array1[2]>>array1[3]>>array1[4]>>array1[5]>>array1[6]>>array1[7]>>array1[8]>>array1[9]>>array1[10];
    cout<<endl<<"2. ";
    cin>>array2[0]>>array2[1]>>array2[2]>>array2[3]>>array2[4]>>array2[5]>>array2[6]>>array2[7]>>array2[8]>>array2[9]>>array2[10];
    cout<<endl<<"3. ";
    cin>>array3[0]>>array3[1]>>array3[2]>>array3[3]>>array3[4]>>array3[5]>>array3[6]>>array3[7]>>array3[8]>>array3[9]>>array3[10];
    cout<<endl<<"4. ";
    cin>>array4[0]>>array4[1]>>array4[2]>>array4[3]>>array4[4]>>array4[5]>>array4[6]>>array4[7]>>array4[8]>>array4[9]>>array4[10];
    cout<<endl<<"5. ";
    cin>>array5[0]>>array5[1]>>array5[2]>>array5[3]>>array5[4]>>array5[5]>>array5[6]>>array5[7]>>array5[8]>>array5[9]>>array5[10];
}

void output(int array1[]){
    int total = array1[0];
    string word;
    int playerScore = total;
    int deck[] = {array1[1],array1[2],array1[3]};
    while(total<=99){
    if(deck[0]!=9 && deck[0]!=4 && deck[0]!=0){
        total += deck[0];
    } else{
        if(deck[0]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(deck[0]==4){total-=10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Dealer";
        break;
    }
    deck[0]=array1[4];
    if(array1[5]!=9 && array1[5]!=4 && array1[5]!=0){
        total += array1[5];
    } else{
        if(array1[5]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(array1[5]==4){total -= 10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Player";
        break;
    }
    if(deck[1]!=9 && deck[1]!=4 && deck[1]!=0){
        total += deck[1];
    } else{
        if(deck[1]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(deck[1]==4){total-=10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Dealer";
        break;
    }
    deck[1]=array1[6];
    if(array1[7]!=9 && array1[7]!=4 && array1[7]!=0){
        total += array1[7];
    } else{
        if(array1[7]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(array1[7]==4){total -= 10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Player";
        break;
    }
    if(deck[2]!=9 && deck[2]!=4 && deck[2]!=0){
        total += deck[2];
    } else{
        if(deck[2]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(deck[2]==4){total-=10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Dealer";
        break;
    }
    deck[2] = array1[8];
    if(array1[9]!=9 && array1[9]!=4 && array1[9]!=0){
        total += array1[9];
    } else{
        if(array1[9]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(array1[9]==4){total -= 10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Player";
        break;
    }
    if(deck[0]!=9 && deck[0]!=4 && deck[0]!=0){
        total += deck[0];
    } else{
        if(deck[0]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(deck[0]==4){total-=10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Dealer";
        break;
    }
    deck[0] = array1[10];
    if(deck[0]!=9 && deck[0]!=4 && deck[0]!=0){
        total += deck[0];
    } else{
        if(deck[0]==0){
            if(total+11<=99){total += 11;}
            else{total+=1;}
        }else if(deck[0]==4){total-=10;}
        else{total+=0;}
    }
    if(total>99){
        word = "Dealer";
        break;
    }
    }
    cout<<total<<", "<<word;
}

int main(){
    int array1[11];
    int array2[11];
    int array3[11];
    int array4[11];
    int array5[11];

    input(array1,array2,array3,array4,array5);

    cout<<endl;

    output(array1);
    cout<<endl;

    output(array2);
    cout<<endl;

    output(array3);
    cout<<endl;

    output(array4);
    cout<<endl;

    output(array5);
    cout<<endl;

    return 0;
}

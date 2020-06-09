//Hrishikesh Ram, ACSL Program
//Period 4A

#include<iostream>
using namespace std;


void input(int array1[], int array2[], int array3[], int array4[], int array5[]){
    cout<<"1. ";
    for(int i=0;i<11;i++){
        cin>>array1[i];
    }
    cout<<endl<<"2. ";
    for(int i=0;i<11;i++){
        cin>>array2[i];
    }
    cout<<endl<<"3. ";
    for(int i=0;i<11;i++){
        cin>>array3[i];
    }
    cout<<endl<<"4. ";
    for(int i=0;i<11;i++){
        cin>>array4[i];
    }
    cout<<endl<<"5. ";
    for(int i=0;i<11;i++){
        cin>>array5[i];
    }
}

void output(int array1[]){
    int total1 = array1[0];
    int array1player[3] = {array1[1],array1[2],array1[3]};
    while(total1<=99){
    if(array1[1]!=0 && array1[1]!=4 && array1[1]!=9){
        total1 += array1[1];
    } else if(array1[1]==0 || array1[1]==4 || array1[1]==9){
        if(array1[1]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[1]==4){
            total1 -= 10;
        } else if(array1[1]==9){
            total1 += 0;
        }
    }
    array1player[1] = array1[4];
    if(array1[5]!=0 && array1[5]!=4 && array1[5]!=9){
        total1 += array1[5];
    } else if(array1[5]==0 || array1[5]==4 || array1[5]==9){
        if(array1[5]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[5]==4){
            total1 -= 10;
        } else if(array1[5]==9){
            total1 += 0;
        }
    }
    if(array1[2]!=0 && array1[2]!=4 && array1[2]!=9){
        total1 += array1[2];
    } else if(array1[2]==0 || array1[2]==4 || array1[2]==9){
        if(array1[2]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[2]==4){
            total1 -= 10;
        } else if(array1[2]==9){
            total1 += 0;
        }
    }
    array1player[2] = array1[6];
    if(array1[7]!=0 && array1[7]!=4 && array1[7]!=9){
        total1 += array1[7];
    } else if(array1[7]==0 || array1[7]==4 || array1[7]==9){
        if(array1[7]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[7]==4){
            total1 -= 10;
        } else if(array1[7]==9){
            total1 += 0;
        }
    }
    if(array1[3]!=0 && array1[3]!=4 && array1[3]!=9){
        total1 += array1[3];
    } else if(array1[3]==0 || array1[3]==4 || array1[3]==9){
        if(array1[3]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[3]==4){
            total1 -= 10;
        } else if(array1[3]==9){
            total1 += 0;
        }
    }
    array1player[3]=array1[8];
    if(array1[9]!=0 && array1[9]!=4 && array1[9]!=9){
        total1 += array1[9];
    } else if(array1[9]==0 || array1[9]==4 || array1[9]==9){
        if(array1[9]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[9]==4){
            total1 -= 10;
        } else if(array1[9]==9){
            total1 += 0;
        }
    }
    if(array1[1]!=0 && array1[1]!=4 && array1[1]!=9){
        total1 += array1[1];
    } else if(array1[1]==0 || array1[1]==4 || array1[1]==9){
        if(array1[1]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[1]==4){
            total1 -= 10;
        } else if(array1[1]==9){
            total1 += 0;
        }
    }
    array1player[1] = array1[10];
    }if(array1[1]!=0 && array1[1]!=4 && array1[1]!=9){
        total1 += array1[1];
    } else if(array1[1]==0 || array1[1]==4 || array1[1]==9){
        if(array1[1]==0){
            if(total1+11<=99){
                total1 += 11;
            }else if(total1+11>99){
                total1 += 1;
            }
        } else if(array1[1]==4){
            total1 -= 10;
        } else if(array1[1]==9){
            total1 += 0;
        }
    }
}

int main(){
    int array1[11] = {87,5,8,9,7,4,6,3,9,0,2};
    int array2[11];
    int array3[11];
    int array4[11];
    int array5[11];

    output(array1);
}

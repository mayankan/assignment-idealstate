//
//  main.cpp
//  CentralPool
//
//  Created by Mayank Anand on 18/08/18.
//  Copyright © 2018 Mayank Anand. All rights reserved.
//  Run on Xcode IDE(Mac OS)

#include <iostream>

int main(int argc, const char * argv[]) {
    // number of transactions taken for input(i.e. no of rows)
    // i & j defined here for taking input of rows and colums.
    int noOfTransactions,i,j;
    //idle stores ideal average value of each member(they should have paid) for total number of rows.
    //memberDifference stores difference between each member's values and the ideal value, i.e. -ve for outstanding and +ve for paying extra).
    //memberValues stores output for each member with their values to be pending from other members.
    double idle = 0.0,memberDifference[4],memberValues[4][4];
    //Takes input for number of transaction rows that have taken place(Food,Drinks,Movie,etc.)
    std::cout << "Enter number of transactions : ";
    std::cin >> noOfTransactions;
    //transactions store the input given by the user for each transaction x no. of members(4 in this case).
    int transactions[noOfTransactions][4];
    //Looping for each transaction row
    for(i=0;i<noOfTransactions;i++)
    {
        //Looping for each member
        for(j=0;j<4;j++)
        {
            //Takes input for each member and each transaction sequentially.
            std::cout << "Enter amount paid by member " << (j+1) << " for transaction " << (i+1) << " ";
            std::cin >> transactions[i][j];
            //stores sum of each transaction value till the input is taken, i.e. sum of all values in each row.
            idle += transactions[i][j];
        }
    }
    //Shows values input by the user in a matrix(2D Array) form.
    std::cout << "ORGANISED TABLE\n";
    //Looping for each transaction row
    for(j=0;j<noOfTransactions;j++)
    {
        std::cout<< "ITEM"<<j+1<<" : "<<transactions[j][0]<< " " << transactions[j][1]<< " " << transactions[j][2]<< " " << transactions[j][3]<< "\n";
        //Looping for each member
        for(int i=0;i<4;i++)
        {
            //memberDifference for each member(i) stores total amount paid by each member.
            memberDifference[i] +=transactions[j][i];
        }
    }
    //idle which earlier stored sum of all transactions is divided by to get the ideal average value that each member should pay.
    idle = idle/4;
    //Looping for each member
    for(i=0;i<4;i++)
    {
        //memberDifference which earlier stored total amount paid by each user for all transactions is replaced and subtracted to idle which stored value each member should pay to get the outstanding amount for each member.
        memberDifference[i] -= idle;
    }
    //Looping for each member
    for(i=0;i<4;i++)
    {
        //Looping for each member outstanding
        for(j=0;j<4;j++)
        {
            //Checks same value in a 2D Array for i and j.eg - 11,22,33
            //as Member1 will not pay to Member1 itself.
            if(i==j)
            {
                //Returns 0 for this case in the output array.
                memberValues[i][j]=0;
            }
            //Checks memberDifference(i) as negative
            else if(memberDifference[i]<0)
            {
                //Checks memberDifference(j) as positive to balance the amounts
                if(memberDifference[j]>0)
                {
                    //Adds both values of payee and payer
                    memberDifference[i]+=memberDifference[j];
                    //Checks if addition is +ve which means payer was having higer amount outstanding
                    if(memberDifference[i]>0)
                    {
                        //Output value in memberValues for payee and payer stores amount paid by payee to payer irrespective of additional amount which it is holding.
                        memberValues[i][j]=memberDifference[j]-memberDifference[i];
                        //memberDifference of payer holds extra amount which it was holding.
                        memberDifference[j]=memberDifference[i];
                        //memberDifference of payee is made empty as it is paid by payer in this case.
                        memberDifference[i]=0;
                    }
                    //This case holds addition as -ve or 0 which means payee was having higer amount
                    else
                    {
                        //Output value stores the value of payer as it is having higer amount than payee
                        memberValues[i][j]=memberDifference[j];
                        //memberDifference of payee is made empty as it is paid by payer in this case.
                        memberDifference[j]=0;
                    }
                }
                else
                {
                    //Returns 0 for this case in the output array.
                    memberValues[i][j]=0;
                }
            }
            else
            {
                //Returns 0 for this case in the output array.
                memberValues[i][j]=0;
            }
        }
    }
    //Output Starts
    //Output value in an array stores values in a matrix form(2D Array) which also stores values for member1->member1,member2->member2,etc.
    //That's why, values of output is taken separately for each member and printed.
    std::cout << "BILL SPLIT\n";
    std::cout << "M1 " << "M2: " << memberValues[0][1] << " M3: " << memberValues[0][2] << " M4: " << memberValues[0][3] << "\n";
    std::cout << "M2 " << "M1: " << memberValues[1][0] << " M3: " << memberValues[1][2] << " M4: " << memberValues[1][3] << "\n";
    std::cout << "M3 " << "M1: " << memberValues[2][0] << " M2: " << memberValues[2][1] << " M4: " << memberValues[2][3] << "\n";
    std::cout << "M4 " << "M1: " << memberValues[3][0] << " M2: " << memberValues[3][1] << " M3: " << memberValues[3][2] << "\n";
}

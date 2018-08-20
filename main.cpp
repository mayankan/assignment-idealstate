//
//  main.cpp
//  CentralPool
//
//  Created by Mayank Anand on 18/08/18.
//  Copyright © 2018 Mayank Anand. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int noOfTransactions,i,j;
    double idle = 0.0,memberDifference[4],memberValues[4][4];
    std::cout << "Enter number of transactions : ";
    std::cin >> noOfTransactions;
    int transactions[noOfTransactions][4];
    for(i=0;i<noOfTransactions;i++)
    {
        for(j=0;j<4;j++)
        {
            std::cout << "Enter amount paid by member " << (j+1) << " for transaction " << (i+1) << " ";
            std::cin >> transactions[i][j];
            idle += transactions[i][j];
        }
    }
    std::cout << "ORGANISED TABLE\n";
    for(j=0;j<noOfTransactions;j++)
    {
        std::cout<< "ITEM"<<j+1<<" : "<<transactions[j][0]<< " " << transactions[j][1]<< " " << transactions[j][2]<< " " << transactions[j][3]<< "\n";
        for(int i=0;i<4;i++)
        {
            memberDifference[i] +=transactions[j][i];
        }
    }
    idle = idle/4;
    for(i=0;i<4;i++)
    {
        memberDifference[i] -= idle;
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==j)
            {
                memberValues[i][j]=0;
            }
            else if(memberDifference[i]<0)
            {
                if(memberDifference[j]>0)
                {
                    memberDifference[i]+=memberDifference[j];
                    if(memberDifference[i]>0)
                    {
                        memberValues[i][j]=memberDifference[j]-memberDifference[i];
                        memberDifference[j]=memberDifference[i];
                        memberDifference[i]=0;
                    }
                    else
                    {
                        memberValues[i][j]=memberDifference[j];
                        memberDifference[j]=0;
                    }
                }
                else
                {
                    memberValues[i][j]=0;
                }
            }
            else
            {
                memberValues[i][j]=0;
            }
        }
    }
    std::cout << "BILL SPLIT\n";
    std::cout << "M1 " << "M2: " << memberValues[0][1] << " M3: " << memberValues[0][2] << " M4: " << memberValues[0][3] << "\n";
    std::cout << "M2 " << "M1: " << memberValues[1][0] << " M3: " << memberValues[1][2] << " M4: " << memberValues[1][3] << "\n";
    std::cout << "M3 " << "M1: " << memberValues[2][0] << " M2: " << memberValues[2][1] << " M4: " << memberValues[2][3] << "\n";
    std::cout << "M4 " << "M1: " << memberValues[3][0] << " M2: " << memberValues[3][1] << " M3: " << memberValues[3][2] << "\n";
}

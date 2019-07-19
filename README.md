# Optimised Splitting Amount Problem

Description : Problem Set to achieve optimised splitting of money between members paying different amounts for different items.
Exchanging money from each member to other members to reach ideal state(i.e. money spent by each member is equal).

We often perform monetary transactions for various purposes like digital printing, IT service and infrastructure cost, and expenses on informal materials and services.

Refer to the following table:

S.no  Item/Service      M1      M2      M3      M4      Total
1.    Food              100     150     0       500     750

Let’s call each row a ‘transaction’
In an ideal case, each member ( M1, M2, M3, M4 ) should contribute equally in all transactions. However, it is not always the case (except for 3rd transaction).
Your goal is to derive an algorithm that accepts a transaction table and evaluates “who pays how much to whom” to reach the “ideal state”.

You are free to choose any suitable data structure to represent the transaction table.
Sample Output :

‘M1’ : {‘M2: 0, ‘M3’ : 250’, ‘M4’:’100’} 

‘M2’ : {‘M1: 100, ‘M3’ : 700’, ‘M4’:’100’} 

‘M3’ : {‘M2: 10, ‘M1’ : 25’, ‘M4’:’10’}

‘M4’ : {‘M2: 10, ‘M3’ : 80’, ‘M1’:’25’} 

You must return the output for each individual transaction.

Please note sample output is not the result of sample input in the shown example.

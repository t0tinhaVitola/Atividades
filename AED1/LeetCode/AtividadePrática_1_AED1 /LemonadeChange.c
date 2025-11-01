/*
A solution to the LeetCode Problem "Lemonade Change".
Description:

"At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise."

Time Complexity: O(n)
Space Complexity: O(1)

*/

bool lemonadeChange(int* bills, int billsSize) {
    if    ( bills[0] != 5 )    {
            return false;
    }

    int acumulador5 = 0, acumulador10 = 0, acumulador20 = 0;

    for    ( int i = 0; i < billsSize ; i++)    {
        if    ( bills[ i ] == 5 ) {
            acumulador5 ++;
        }    else if    ( bills[ i ] == 10 && acumulador5 > 0 )    {
            acumulador10 ++;
            acumulador5--;;
        }    else if    ( bills[ i ] == 20 )    {
            if    ( acumulador5 >= 3 && acumulador10 == 0 )    {
                acumulador20++;
                acumulador5 -= 3;
            }   else if    ( acumulador5 >= 1 && acumulador10 >= 1 )    {
                acumulador20++;
                acumulador5--;
                acumulador10--;
            }    else    {
                return false;
            }
        }    else    {
            return false;
        }
    }

    return true;
}

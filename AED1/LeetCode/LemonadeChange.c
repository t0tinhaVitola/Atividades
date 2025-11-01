/*
A solution to the LeetCode Problem "Lemonade Change".
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

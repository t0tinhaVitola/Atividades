/*
A solution to the LeetCode Problem "Roman to Integer", which, given a string representing a roman numeral, returns its integer value.

*/

int romanToInt(char* s) {
    int numFinal = 0, tamString = strlen( s );

    for(int i = 0; i < tamString; i++){
        if  ( s[ i ] == 'I' )   {
            if  ( i + 1 < tamString && ( s[ i + 1 ] == 'V' || s[ i + 1 ] == 'X' ) ) {
                    numFinal -= 1;
            }   else    {
                    numFinal += 1;
            }    
        }   else if  ( s[i] == 'V' )    {
                    numFinal += 5;
        }   else if  ( s[ i ] == 'X' )   {
                if  ( i + 1 < tamString && ( s[ i + 1 ] == 'L' || s[ i + 1 ] == 'C' ) ) {
                    numFinal -= 10;
                }   else    {
                    numFinal += 10;
                } 
        }   else if ( s[ i ] == 'L' )   {
                    numFinal += 50;
        }   else if ( s[ i ] == 'C' )   {
                if  ( i + 1 < tamString && ( s[ i + 1 ] == 'D' || s [ i + 1 ]  == 'M' )  )   {
                    numFinal -= 100;
                }   else    {
                    numFinal += 100;
                } 
        }   else if ( s[ i ] == 'D' )   {
                    numFinal += 500;
        }   else if ( s[ i ] == 'M' )   {
                    numFinal += 1000;
        }   else {  
                    return -1;
        }
    }
    return numFinal;
}

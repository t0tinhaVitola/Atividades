/*
A solution to the LeetCode problem "Palindrome Number", which, given an integer number, returns whether the number is a palindrome.

*/

bool isPalindrome(int x) {
   long int target = x, resultado = 0;

    if  ( x < 0 ) return false;

    while  ( x > 0 ){
        resultado = ( resultado * 10 ) + ( x % 10 );
        x /= 10;
    }

    if  ( resultado == target )  {
        return true;
    }  else  {
        return false;
    }
}

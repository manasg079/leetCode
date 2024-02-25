/*Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.*/


#include<stdio.h>
#include<stdbool.h>

bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedNumber = 0;
    while (x > reversedNumber) {
        reversedNumber = reversedNumber * 10 + x % 10;
        x /= 10;
    }

    // When the length of the original number is odd, we can ignore the middle digit.
    // For example, in 12321, after the loop, reversedNumber will be 123, x will be 12.
    // So, to compare if it's a palindrome, we can ignore the last digit of reversedNumber.
    // When the length of the original number is even, reversedNumber will be equal to x.
    return x == reversedNumber || x == reversedNumber / 10;
}

int main() {
    int x1 = 121;
    printf("Input : %d\n Output : %s\n",x1, isPalindrome(x1) ? "true" : "false");

    int x2 = -121;
    printf("Input : %d\n Output : %s\n",x2, isPalindrome(x2) ? "true" : "false");

    int x3 = 10;
    printf("Input : %d\n Output : %s\n",x3, isPalindrome(x3) ? "true" : "false");
    
}


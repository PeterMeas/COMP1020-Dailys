#include <stdio.h>
#include <stdlib.h>

char* reverse(char array[])
{
    int length = 0; //used to iterate,  set to 0
    while(array[length] != '\0') //while loop, while array[length] isnt the null terminator, continue
    {
        length++; //while it isnt null temrinator, icrement ++ for length
    }
    int start = 0; //represents index of first character
    int end = length - 1; //represents index of last character, subtracting 1
    while(start < end) // while loop for start being less than end character, to reverse characters
    {
        char temp = array[start]; //create temp variable and now holds value stored in array[start]
        array[start] = array[end]; //array[start] now holds value stored in array[end]
        array[end]= temp; //array[end] now holds value stored in temp

        start++; //after each swap, will increment and decrement accordingly
        end--;
    }
    return array;
}

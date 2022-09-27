/*
 *  my_lab2exe_B.cpp
 *  ENSF 614 Lab 2 Exercise B
 */

int my_strlen(const char *s);
/*  Duplicates strlen from <cstring>, except return type is int.
 *  REQUIRES
 *     s points to the beginning of a string.
 *  PROMISES
 *     Returns the number of chars in the string, not including the
 *     terminating null.
 */

void my_strncat(char *dest, const char *source, int);
/*  Duplicates strncat from <cstring>, except return type is void.
 */

int my_strcmp(const char* str1, const char* str2);
/* strcmp compares str1 and str2, and returns 0 if the two strings are identical. 
Otherwise, returns a positive number if str1 is greater than str2, 
and a negative number if str2 is greater than str1.
*/

#include <iostream>
#include <cstring>
using namespace std;

int my_strlen(const char *s){
    int count = 0;
    const char terminator = '\0';
    while(s[count] != terminator){
        count++;
    }

    return count;
}

void my_strncat(char *dest, const char *source, int num){
    int i;
    int j;

    for(i = 0; dest[i] != '\0'; i++);

    for(j = 0; source[j] != '\0' && j < num; j++){
        dest[i + j] = source[j];
    }

    dest[i + j] = '\0';

}

int my_strcmp(const char* str1, const char* str2){
    while(*str1){
        // if characters differ, or end of the second string is reached
        if(*str1 != *str2){
            break;
        }
        
        str1++;
        str2++;
    }

    // return the ASCII difference after converting `char*` to `unsigned char*`
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int main(void)
{
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char* str3 = "-toe";
    
    /* point 1 */
    char str5[] = "ticket";
    char my_string[100]="";
    int bytes;
    int length;
    
    /* using strlen libarary function */
    length = (int) my_strlen(my_string);
    cout << "\nLine 1: my_string length is " << length;
  
    /* using sizeof operator */
    bytes = sizeof (my_string);
    cout << "\nLine 2: my_string size is " << bytes << " bytes.";
   
    /* using strcpy libarary function */
    strcpy(my_string, str1);
    cout << "\nLine 3: my_string contains: " << my_string;
   
    length = (int) my_strlen(my_string);
    cout << "\nLine 4: my_string length is " << length << ".";
   
    my_string[0] = '\0';
    cout << "\nLine 5: my_string contains:\"" << my_string << "\"";
  
    length = (int) my_strlen(my_string);
    cout << "\nLine 6: my_string length is " <<  length << ".";
   
    bytes = sizeof (my_string);
    cout << "\nLine 7: my_string size is still " << bytes << " bytes.";
 
    /* strncat append the first 3 characters of str5 to the end of my_string */
    my_strncat(my_string, str5, 3);
    cout << "\nLine 8: my_string contains:\"" << my_string << "\"";
  
    length = (int) my_strlen(my_string);
    cout << "\nLine 9: my_string length is " << length << ".";
   
    my_strncat(my_string, str2,  4);
    cout << "\nLine 10: my_string contains:\"" << my_string << "\"";
    
    /* my_strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
    my_strncat(my_string, str3, 6);
    cout << "\nLine 11: my_string contains:\"" << my_string << "\"";
   
    length = (int) my_strlen(my_string);
    cout << "\nLine 12; my_string has " << length << " characters.";

    cout << "\n\nUsing my_strcmp - user defined function: ";
    
    cout << "\n\"ABCD\" is less than \"ABCDE\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCDE");

    cout << "\n\"ABCD\" is less than \"ABND\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABND");
    
    cout << "\n\"ABCD\" is equal than \"ABCD\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCD");
 
    cout << "\n\"ABCD\" is less than \"ABCd\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCd");

    cout << "\n\"Orange\" is greater than \"Apple\" ... my_strcmp returns: " <<
    my_strcmp("Orange", "Apple") << endl;
    return 0;
}

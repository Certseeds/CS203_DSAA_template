<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-08 09:10:05
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-22 13:09:09
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab06

1. Write a program to input an alphabet and check whether it is vowel or consonant using switch case. The program to
   check vowel or consonant using switch case.A sample run might look like this:.

``` log
Enter ang alphabet : a
Vowel
```

``` log
Enter ang alphabet : b
Consonant
```

``` log
Enter ang alphabet : A
Vowel
```

``` log
Enter ang alphabet : B
Consonant
```

NOTE:English alphabets 'a' , 'e' , 'i' , 'o' , 'u' both lowercase and uppercase are known as vowels. Alphabets other
than vowels are known as consonants.

2. Write a program that reads input a word at a time until a lone q is entered.The program should then report the number
   of words that began with vowels,the num- ber that began with consonants,and the number that fit neither of those
   categories. One approach is to use **isalpha()** to discriminate between words beginning with letters and those that
   don't and then use an **if or switch** statement to further identify those passing the **isalpha()** test that begin
   with vowels.A sample run might look like this:.

``` log
Input:
    in all sections, yuwen is the basic class
    it can import the basic language apower and other works.
    not at all! done
    1
    q
Output:
    10 words begining with vowels
    12 words begining with consonants
    1 others
```

PS: basic frame is provided!

``` cpp
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
const int vn=5;
const char vowel [vn] = {'a', 'e', 'i', 'o', 'u'};
int main() {
cout << "Enter words (q to quit):"<< endl;
int nVowel=0;
int nConsonant =0;
int nOther =0;
char word[30];
while(cin >> word) {
    if (isalpha(word[0])) {
        if (strlen(word) == 1 && word[0] == 'q') {
            break;
        }
    char x = tolower(word[0]);
//complete code here
    }
cout << nVowel << " words begining with vowels" << endl
<< nConsonant << " words begining with consonants" << endl
<< nOther << " others" << endl;
return 0;
}
}
```

3. Write a program that determines a student’s grade. The program will read three types of scores (quiz, mid-term, and
   final scores) and determine the grade based on the following rules:

+ if the average score =90% =>grade=A
+ if the average score >= 70% and <90% => grade=B
+ if the average score>=50% and <70% =>grade=C
+ if the average score<50% =>grade=F.
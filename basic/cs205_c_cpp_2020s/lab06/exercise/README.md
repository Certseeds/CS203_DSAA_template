<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-26 23:23:19
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-22 13:42:17
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 --> 
**Environment**: WSL_1,gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

# Lab06 Exercise: 2020_0326

## E1 Code & Result

### Code

``` cpp
#include <iostream>
#include <cstring>
const int32_t lab06_01_max_length = 1024;
int main() {
    char beta;
    char output[lab06_01_max_length];
    memset(output, '\0', lab06_01_max_length*sizeof(char));
    std::cout << "Enter any alphabet: ";
    std::cin >> beta;
    if(isalpha(beta)){
        switch (tolower(beta)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': {
                sprintf(output, "Vowel");
                break;
            }
            default:{
                sprintf(output, "Consonant");
                break;
            }
        }
    }else{
        sprintf(output, "Error! please input vowel or consonant characters");
    }
    std::cout << output << std::endl;
    return 0;
}
```

### Result

#### Test Case #1:

``` log
Input: 
    a
Output:
    Vowel
```

![picture_01](./lab06_01.png)

#### Test Case #2:

``` log
Input: 
    b
Output:
    Consonant
```

![picture_02](./lab06_02.png)

#### Test Case #3:

``` log
Input: 
    E
Output:
    Vowel
```

![picture_03](./lab06_03.png)

#### Test Case #4:

``` log
Input: 
    C
Output:
    Consonant
```

![picture_04](./lab06_04.png)

#### Test Case #5:

``` log
Input: 
    i
Output:
    Vowel
```

![picture_05](./lab06_05.png)

#### Test Case #6:

``` log
Input: 
    O
Output:
    Vowel
```

![picture_06](./lab06_06.png)

#### Test Case #7:

``` log
Input: 
    t
Output:
    Consonant
```

![picture_07](./lab06_07.png)

#### Test Case #8:

``` log
Input: 
    U
Output:
    Vowel
```

![picture_08](./lab06_08.png)

#### Test Case #9:

``` log
Input: 
    ?
Output:
    Error! please input vowel or consonant characters
```

![picture_09](./lab06_09.png)

## E2 Code & Result

### Code

``` cpp
#include <iostream>
#include <cstring>
const int32_t lab06_02_max_length = 1024;
int main() {
    std::cout << "Enter words (q to quit): ";
    std::cout.flush();
    int32_t nVowel = 0;
    int32_t nConsonant = 0;
    int32_t nOther = 0;
    char word[lab06_02_max_length + 1];
    while (std::cin >> word) {
        if (isalpha(word[0])) {
            if (strlen(word) == 1 && word[0] == 'q') {
                break;
            }
            char x = tolower(word[0]);
            switch (x) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u': {
                    nVowel++;
                    break;
                }
                default: {
                    nConsonant++;
                    break;
                }
            }
        } else {
            nOther++;
        };
    }
    std::cout << nVowel << " words begining with vowels" << std::endl
              << nConsonant << " words begining with consonants" << std::endl
              << nOther << " others" << std::endl;
    return 0;
}
```

### Result

#### Test Case #1:

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

![picture_10](./lab06_10.png)

## E3 Code & Result

### Code

``` cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    double quiz = 0;
    double mid_term = 0;
    double scores = 0;
    double average = 0;
    cout << "Input scores between 0 to 100" << endl;
    cout << "Input quiz Score";
    cin >> quiz;
    while ((getchar()) != '\n');
    cout << "Input mid_term Score";
    cin >> mid_term;
    while ((getchar()) != '\n');
    cout << "Input mid_term Score";
    cin >> scores;
    while ((getchar()) != '\n');
    average = (quiz + mid_term + scores) / 3;
    char grade = '\0';
    if (average >= 90) {
        grade = 'A';
    } else if (average >= 70) {
        grade = 'B';
    } else if (average >= 50) {
        grade = 'C';
    } else {
        grade = 'F';
    }
    cout << "Grade is : " << grade << endl;
    return 0;
}
```

### Result

#### Test Case #1:

``` log
Input:
    89
    99
    97
Output:
    Average is : 93.6667
    Grade is : A
```

![picture_11](./lab06_11.png)

#### Test Case #2:

``` log
Input:
    85
    90
    95
Output:
    Average is : 90
    Grade is : A
```

![picture_12](./lab06_12.png)

#### Test Case #3:

``` log
Input:
    79
    83
    89
Output:
    Average is : 83.6667
    Grade is : B
```

![picture_13](./lab06_13.png)

#### Test Case #4:

``` log
Input:
    65
    75
    70
Output:
    Average is : 70
    Grade is : B
```

![picture_14](./lab06_14.png)

#### Test Case #5:

``` log
Input:
    60
    53
    59
Output:
    Average is : 57.3333
    Grade is : C
```

![picture_15](./lab06_15.png)

#### Test Case #6:

``` log
Input:
    45
    51
    54
Output:
    Average is : 50
    Grade is : C
```

![picture_16](./lab06_16.png)

#### Test Case #7:

``` log
Input:
    1
    2
    3
Output:
    Average is : 2
    Grade is : F
```

![picture_17](./lab06_17.png)

#### Test Case #8:

``` log
Input:
    60.0
    25.0
    99.98
Output:
    Average is : 61.66
    Grade is : C
```

![picture_18](./lab06_18.png)
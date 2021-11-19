/*
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2020-03-19 16:32:52
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-19 18:23:18
 */
#include <iostream>
#include<cstring>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int32_t sub_main_05_02();

#ifndef _UNIT_TESTING_LAB_05_
#define _UNIT_TESTING_LAB_05_

int main() {
    const int32_t will_return = sub_main_05_02();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !_UNIT_TESTING_LAB_05_
const int lab05_02_length = 1024;
const char done[] = "done";

int32_t sub_main_05_02() {
    char buffer[lab05_02_length + 1];
    memset(buffer, '\0', (lab05_02_length + 1) * sizeof(char));
    cout << "Entry words (to stop, type the word done):" << endl;
    uint32_t count = 0;
    while (true) {
        bool get_out = false;
        cin.get(buffer, lab05_02_length);
        while ((getchar()) != '\n');
        vector<char *> strings = {buffer};
        for (uint32_t x = 1; x < lab05_02_length; x++) {
            if (' ' == buffer[x]) {
                buffer[x] = '\0';
            }
            if ('\0' != buffer[x] && '\0' == buffer[x - 1]) {
                strings.push_back(buffer + x);
            }
        }
        for (auto i: strings) {
            if (0 == strcmp(done, i)) {
                get_out = true;
                break;
            }
            count++;
        }
        if (get_out) {
            break;
        }
        memset(buffer, '\0', lab05_02_length * sizeof(char));
    }
    cout << "You entered a total of " << count << " words.";
    return 0;
}
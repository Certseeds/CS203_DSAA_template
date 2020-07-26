#!/usr/bin/env python3
# coding=utf-8
'''
@Github: https://github.com/Certseeds/CS203_DSAA_template
@Organization: SUSTech
@Author: nanoseeds
@Date: 2020-07-15 21:47:09
@LastEditors: nanoseeds
@LastEditTime: 2020-07-22 00:13:31
@LICENSE: MIT
'''
"""
MIT License

CS203_DSAA_template 

Copyright (c) 2020  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""

import os
import time
from typing import List

main_code_template: str
test_code_template: str
file_header_template: str
GITHUB_USER: str = "YOUR_GITHUB_NAME"  # example: Certseeds
USER: str = "YOUR_USER_NAME"  # example: nanoseeds
year: str = time.strftime("%Y", time.localtime())
create_time: str = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
source_path: str = "./../source/lab_{}/lab_{}_{}.cpp"
test_path: str = "./../test/lab_{}/lab_{}_{}_test.cpp"


def read_file(file_name: str) -> str:
    will_return: str
    with open(file_name, mode='r', encoding="UTF-8") as template:
        will_return = template.read()
    return will_return


def fill_file(lab_number: str, problem_order: str) -> None:
    with open(source_path.format(lab_number, lab_number, problem_order), mode='a+', encoding="UTF-8") as file:
        file.write(file_header_template.format(GITHUB_USER, USER, create_time, year))
        file.write(main_code_template)
    print("main finish")
    with open(test_path.format(lab_number, lab_number, problem_order), mode='a+', encoding="UTF-8") as file:
        file.write(file_header_template.format(GITHUB_USER, USER, create_time, year))
        file.write(test_code_template.format(lab_number, problem_order))
    print('test finish')


def try_mkdir(lab_number: str) -> None:
    if not os.path.exists("./../source/lab_{0}".format(lab_number)):
        os.mkdir("./../source/lab_{0}".format(lab_number))
    if not os.path.exists("./../test/lab_{0}".format(lab_number)):
        os.mkdir("./../test/lab_{0}".format(lab_number))


# range in [begin,end)
if __name__ == '__main__':
    file_header_template = read_file("file_header.txt")
    main_code_template = read_file("cpp_template.txt")
    test_code_template = read_file("cpp_test_template.txt")
    labs: List[str] = ['01', '02', '03', '04', '05', '06', '07',
                       '08', '09', '10', '11', '12', '13', '14', '15']
    problem_order: List[chr] = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
    for i in labs:
        try_mkdir(i)  # 准备文件夹
        for j in problem_order:
            fill_file(i, j)  # 为 lab_${i}/lab_${i}_${j} 创建文件
    print('produce files finish')
    print(str(len(labs) * len(problem_order) * 2) + ' files is produced')

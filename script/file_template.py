#!/usr/bin/env python3
# coding=utf-8
'''

SPDX-License-Identifier: AGPL-3.0-or-later

CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds
'''

import os
import time
from typing import List

main_code_template: str
test_code_template: str
file_header_template: str
source_cmake_template: str
test_cmake_template: str
GITHUB_USER: str = 'YOUR_GITHUB_NAME'  # replace it with your github name
GITHUB_USER: str = 'Certseeds'  # example: Certseeds
USER: str = 'YOUR_USER_NAME'  # replace it with your user name
USER: str = 'nanoseeds'  # example: nanoseeds
REPO_NAME: str = 'YOUR_REPO_NAME'  # replace it with your github repo name
REPO_NAME: str = 'CS203_DSAA_template'  # example: CS203_DSAA_template
year: str = time.strftime('%Y', time.localtime())
create_time: str = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
source_path: str = './../lab_{0}/lab_{0}_{1}.cpp'
test_path: str = './../lab_{0}/lab_{0}_{1}_test.cpp'
source_cmake_path: str = './../lab_{0}/CMakeLists.txt'
attributes_path: str = './../lab_{0}/.gitattributes'
main_cmake_path: str = './../CMakeLists.txt'


def read_file(file_name: str) -> str:
    will_return: str
    with open(file_name, mode='r', encoding='UTF-8') as template:
        will_return = template.read()
    return will_return


def fill_file(lab_number: str, problem_order: str) -> None:
    with open(source_path.format(lab_number, problem_order), mode='a+', encoding='UTF-8') as file:
        file.write(file_header_template.format(
            GITHUB_USER, REPO_NAME, USER, create_time, year))
        file.write(main_code_template.format(lab_number, problem_order))
    print('main finish')
    with open(test_path.format(lab_number, problem_order), mode='a+', encoding='UTF-8') as file:
        file.write(file_header_template.format(
            GITHUB_USER, REPO_NAME, USER, create_time, year))
        file.write(test_code_template.format(lab_number, problem_order))
    print('test finish')


def try_mkdir(lab_number: str) -> None:
    if not os.path.exists('./../lab_{0}'.format(lab_number)):
        os.mkdir('./../lab_{0}'.format(lab_number))


def copy_cmakeLists(lab_number: str, problem_list: str) -> None:
    with open(source_cmake_path.format(lab_number), mode='a+', encoding='UTF-8') as file:
        file.write(source_cmake_template.format(lab_number, problem_list))
    return


def main() -> None:
    labs: List[str] = ['welcome', '02', '03', '04', '05', '06',
                       '07', '08', '09', '10', 'bonus']
    problem_order: List[str] = ['A', 'B', 'C', 'D', 'E', 'F']
    # labs: List[str] = ['01']
    # problem_order: List[str] = ['A', 'B', 'C',
    #                                 'D', 'E', 'F', 'G', 'H', 'I', 'J']
    problem_order_list_str: str = " ".join(problem_order)
    for i in labs:
        try_mkdir(i)  # 准备文件夹
        copy_cmakeLists(i, problem_order_list_str)  # prepare CMakeLists
        for j in problem_order:
            fill_file(i, j)  # 为 lab_${i}/lab_${i}_${j} 创建文件
        with open(attributes_path.format(i), mode='a+', encoding='UTF-8') as attr:
            attr.write("* linguist-vendored")
    print('produce files finish')
    print(f"{len(labs) * (len(problem_order) + 1) * 2} files is produced")


# range in [begin,end)
if __name__ == '__main__':
    file_header_template = read_file('file_header.txt')
    main_code_template = read_file('cpp_template.txt')
    test_code_template = read_file('cpp_test_template.txt')
    source_cmake_template = read_file('CMakeLists_template.txt')
    main()

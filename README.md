<!--
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-15 23:52:04
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-01-28 17:02:29
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# CS203_DSAA_template  

# CS203_数据结构与算法分析_代码模板

1. 除去`./third_party/*`的所有代码(*.cpp,*.hpp,etc)基于MIT协议:限制最少的主流开源协议,
    + 在署名的前提下,
    + 允许他人以任何方式使用,  
    + 同时原作者不承担任何风险.
    + 具体内容请看[`LICENSE_MIT.md`](./LICENSE_MIT.md)

2. 所有其他文件(主要是*.md)基于CC-BY-NC-SA-4.0(或以后版本)协议.
    + 相同方式共享-署名-非商业性使用的知识共享协议4.0或任何以后版本.
    + 署名(BY)-使用到相应内容的其他地方,应该加以注释,保留来源.
    + 非商业性使用(NC)-默认情况下,只要署名,可以在不盈利的情况下使用.(并不是指商业情况不能用,而是需要和原作者沟通)
    + 相同方式共享(SA)-使得协议具有传染性,只要其他内容采用了本repo的内容,就需要在署名的同时,保证其协议也是CC-BY-NC-SA-4.0 or later version.
    + 具体内容请看[`LICENSE_CC_BY_NC_SA_V4_0.md`](./LICENSE_CC_BY_NC_SA_V4_0.md)

3. 本repo的目的:提供一个
    + 较为简单,
    + 开箱即用,
    + 带有测试,
    + 针对CS203_dsaa的lab设计的c++11代码模板仓库,方便同学们进行课程的学习.
    + 同时会提供一些基本的算法框架.

## 如何使用本repo

+ 首先请到[release_latest](https://github.com/Certseeds/CS203_DSAA_template/releases/latest)下载script_no_need.zip.
+ 将其解压,放到某处.
+ 将脚本创建的版权声明中的所有者替换成自己: 
    1. `.idea`中的`#set( ${GITHUB_USER} = "Certseeds")` -> `#set( ${GITHUB_USER} = "YOUR_GITHUB_NAME")`
    2. `.vscode/settings.json`中的`"Github": "https://github.com/Certseeds/CS203_DSAA_template"` -> `"Github": "https://github.com/YOUR_GITHUB_NAME/YOUR_REPO_NAME"`
    3. `./script/file_template.py`中

        ``` python
        GITHUB_USER: str = "Certseeds"
        USER: str = "nanoseeds"
        ```

        ->

        ``` python
        GITHUB_USER: str = "YOUR_GITHUB_NAME"
        USER: str = "YOUR_USER_NAME"
        #下面这个和上面这个相同也行,不同也行,不重要.
        ```

- 可选项: 使用脚本产生自定义的文件(适合source.zip或者有bonuslab):
  + 使用命令行,进入`./script`下,`python3 ./file_template.py`,出现`produce files finish`提示,即为创建成功.
    默认产生lab01-lab15十五个lab,  
    每个lab下A-J10个问题,  
    每个问题一个source文件,一个test文件.  
  + 一共15 \* 10 \* 2 = 300个文件.(全都默认为`https://acm.sustech.edu.cn/onlinejudge/problem.php?id=1000`的对应代码与测试).
    + 如果有bonus等情况,直接到`script\file_template.py`中修改`labs`,`problem_order`,便可修改产生的lab数,lab名与每道题对应的名字.
    + PS:  就像下面的修改,增加了两个Bonus_Lab,同时给每个Lab中的C拆分成了C1 && C2

        ```  python
        labs: List[str] = ['01', '02', '03', '03Bouns', '04', '05', '06', '07','07Bouns','08', '09']
        problem_order: List[str] = ['A', 'B', 'C1', 'C2','D', 'E', 'F', 'G']
        ``` 

+ 执行代码和测试:
  + 使用clion打开文件夹,配置好C++环境的基础上,会自动识别`CmakeList.txt`.产生`CS203_lab${order}_${ques_Order}`,`CS203_lab${order}_${ques_Order}_test` 复数个可以运行的可选项.
    `lab${order}_${ques_Order}`为对应题号,比如`lab07_01`对应lab_07的C1题.
    + `CS203_lab07_01`将调用`source\lab_07\lab_07_C1.cpp`,为将要提交的源文件.  
    + `CS203_lab07_01_test`将调用`test\lab_07\lab_07_C1_test.cpp`,对其进行测试.  
    + `test\lab_*\lab_*_*_test.cpp`目的为方便测试,同时便于分享测试用例.

## 实际场景

1. A+B: lab_00_A ,测试样例
    + 这个问题较为简单,见[A+B](./source/lab_00/lab_00_A.cpp).解决起来不复杂.
    + 虽然手工一个一个输入,然后肉眼观察输出.但是如果我们希望严谨的测试,要100组测试数据,难道每次出新版本都要手动输入100次吗?
      显然,有更好的解决方式:使用测试框架.
    + 在本repo,使用`Catch2`测试框架.
      比如,我们有四组数据,第一组,第二组测试边界值,第三组使用随机数测试对偶性与正确性,第四组测试几个手动的随机值.
      参见[test_for_lab00_A](./test/lab_00/lab_00_A_test.cpp).
    + 这样一来,我们只需要每次修改完主文件之后,run `CS203_DSAA_template_test`, 对其进行调用,就能验证其在所有的测试用例上的正确性.
      测试的结果也会出现在输出中.
2. 多个输出值的检查:`Catch::Matchers`
    + 上面的例子里,输出值只是一个值,所以手动检查的难度不大,但是如果目标输出是一个数组,那么手动检查的难度就非常大了.
    + 举例:[Crzay Plan](https://acm.sustech.edu.cn/onlinejudge/problem.php?id=1250),输入可能有1.1*10^6个.  
      这种情况下对这么多值进行直接的观察就很难,所以我们预先将期望的值直接写在测试文件里,用Catch2内置的Matcher比较.
      见[test_for_lab00_B](./test/lab_00/lab_00_B_test.cpp)的`CHECK_THAT()`部分.
    + 当然,这种情况也只适用于规模比较小的情况,规模再大的话,直接由人手动写在测试文件里也太占空间了.
3. 输入输出重定向-1:
    + 常见于tree,graph类的问题,debug需要的数据集都比较大,不方便直接写在代码中.
    + 比如[判断二分图](./source/lab_00/lab_00_C.cpp),一张图可以有几十上百个node,写在内部占用空间太大.
    + 而在这里,使用`CS203_redirect`对象,便可以省去手动输入的方式.

    ``` cpp
        TEST_CASE("test case 1", "[test 00 C]") {
            CS203_redirect cr{"01.data.in", ""};
            // 重定向开始,开始run
            // or CS203_redirect cr{"01.data.in"};
            auto output_data = isBipartite(read());
            // 重定向结束
            CHECK_FALSE(output_data);
        }
    ```

    只需要准备好输入的数据与结果,就可以从文件中读取,执行后判断结果是否符合预期.   
    + test case 1-5为最简单的逐个判断,最简单,代码量最大.
    + test case loop 则优化了一些,但是还是比较麻烦,for循环还需要了解测试样例的个数.
    + test case with tuple 则最优雅,修改起来的难度最小.
    + test case with sequence 比tuple更优雅,输入,输出全为自动产生.
    + PS: 此处注意,引用文件的相对路径,不是直接的`test/lab_00/lab_00_C_data/01.data.in`,
    而是编译出的文件相对于测试数据的相对路径.
    在样例中,编译出的文件在`CS203_DSAA_template/cmake-build-debug`下,所以需要加`./../`

4. 输入输出重定向-2:
    + 一般来说,题目的输出不会太复杂,但是反例也不是没有.:比如专门考输出的[立体图](./source/lab_00/lab_00_D.cpp)
    + 这种情况下,使用c++的重定向输出就可以较为方便的对输入进行处理,同时保存输出方便调试.

    ``` cpp
        TEST_CASE("test case 2", "[test 00 D]") {
            SECTION("do") {
                CS203_redirect cr{"01.data.in", "01.test.out"};
                auto input_data = read();
                cal(input_data);
            }SECTION("compare files") {
                CHECK(compareFiles("01.test.out", "01.data.out"));
            }
        }
    ```

    这样就将标准输出重定向到了01.test.out中,并与01.data.out比对.
    + 至于比较文件之间的差异,可以使用内置的`compareFiles(string path1,string path2)`函数进行比较.
    参考[文本比对_test_case_2](./test/lab_00/lab_00_D_test.cpp)

5. 为什么要将 `读取` `数据处理` `输出` 分开?
    + 便于理清思路,读完题目之后,不管别的,先把数据读入,输出的函数写好,方便后续写作.
    + 交流代码逻辑的时候不会受到无关逻辑的影响
    + 可以互相分享少量代码而不触及核心逻辑,方便协作.  
    + 便于使用测试.

## 为什么要选择C++做题?

1. C++是dalao们的选择
直接去
[dalao1](https://acm.sustech.edu.cn/onlinejudge/status.php?user_id=11710724&jresult=4)
[dalao2](https://acm.sustech.edu.cn/onlinejudge/status.php?user_id=11612908&jresult=4)
[dalao3](https://acm.sustech.edu.cn/onlinejudge/status.php?user_id=11712510&jresult=4)
等等dalao的解题页面看看,会发现在排行榜榜首的人,绝大多数题目使用的都是C++.

2. 速度.

+ oj内一般java的最大运行时间都会是c++的2倍,显然是暗示速度之间的差别.
+ 其次,C++可以通过一些魔法操作,比如下文的优化等操作再获取一些时间上的优势.

3. 对数据结构的友好性  

DSAA既然内含Data structure,就势必涉及到类似Node,Tree,Graph等等数据结构,这类数据结构使用C++写,比较方便理解.

4. 对算法友好的性能:  

我写树和图相关的题目时,最头疼的就是Java的爆栈,有一段时间只要用递归就爆栈,相同算法修改为C++之后问题就消失了.

5. 相关资源的丰富程度  

不管怎么说,c++是dalao的选择,所以在网络上搜索题目,得到的大多数答案都是C/C++,java的数量很少.

## 如何手动开优化

1. 将[magic_optimize](./includes/magic_macro.hpp)内的内容粘贴到代码最上方.
2. 关闭同步,

```cpp
static const auto faster_streams = [] {
    srand(time(nullptr)); 
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
```

已放置在源文件最下方,注意不要混用c风格输入输出与c++风格输入输出

3. 通常情况下,可以将运行时间缩短到1/2甚至更少.

## Why choose Catch?

1. 先来看可选项有哪些

|        FrameWork         | Catch2 | Google Test | CPPUnit | Boost.Test | CTest |    Microsoft 单元测试框架    |
| :----------------------: | :----: | :---------: | :-----: | :--------: | :---: | :--------------------------: |
|          跨平台          |   √    |      √      |    √    |     √      |   √   |              X               |
| 是否需要提前在系统内安装 |   X    |      √      |    √    |     √      |   X   | √(and visual studio make it) |
|           语法           |  简单  |    简单     |  复杂   |    简单    | 愚蠢  |           Unknown            |

先筛选跨平台,去掉了Microsoft,  
再筛选不需要安装,只剩Catch2和CTest,  
再把语法傻逼的CTest去掉.齐活.

TODO: 介绍使用Cyaron 生成数据.

[![MIT](https://img.shields.io/badge/License-MIT-orange)][MIT_Link]

[![CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-orange)][cc_by_nc_sa_4_0]

[![CC BY-SA 4.0][cc_by_nc_sa_4_0_image]][cc_by_nc_sa_4_0]

## test Based on  

![Catch 2](https://github.com/catchorg/Catch2/blob/master/artwork/catch2-logo-small.png?raw=true)

[MIT_Link]: http://opensource.org/licenses/MIT

[cc_by_nc_sa_4_0]: https://creativecommons.org/licenses/by-nc-sa/4.0/

[cc_by_nc_sa_4_0_image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png

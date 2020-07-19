<!--
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-15 23:52:04
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-19 21:59:31
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

### 如何使用本repo:
+ 首先请到[release_latest](https://github.com/Certseeds/CS203_DSAA_template/releases/latest)下载source.zip.
+ 将其解压,放到某处,把文件夹名内的版本号去掉.
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
+ 使用脚本产生文件:
    + 使用命令行,进入`./script`下,`python3 ./file_template.py`,出现`produce files finish`提示,即为创建成功.
      默认产生lab01-lab15十五个lab,每个lab下A-J10个问题,每个问题一个source文件,一个test文件.
    + 一共15*10*2 = 300个文件.(全都默认为`https://acm.sustech.edu.cn/onlinejudge/problem.php?id=1000`的对应代码与测试).
    + 如果有bonus等情况,直接到`script\file_template.py`中修改`labs`,`problem_order`,便可修改产生的lab数,lab名与每道题对应的名字.
     + PS:  就像下面的修改,增加了两个Bonus_Lab,同时给每个Lab中的C拆分成了C1 && C2
        ```  python
        labs: List[str] = ['01', '02', '03', '03Bouns', '04', '05', '06', '07','07Bouns','08', '09']
        problem_order: List[chr] = ['A', 'B', 'C1', 'C2','D', 'E', 'F', 'G']
        ```  
+ 执行代码和测试:
    + 使用clion打开文件夹,配置好C++环境的基础上,会自动识别`CmakeList.txt`.产生`CS203_DSAA_template`,`CS203_DSAA_template_test`两个可以运行的可选项.
    + 首先,设定lab号和题号,修改`CmakeList.txt`中的
    ``` cmake
    set(lab_number 07) 
    set(problem_order C1)
    ``` 
    为对应题号,比如上面的配置对应lab_07的C1题.
    + `CS203_DSAA_template`将调用`source\lab_07\lab_07_C1.cpp`.  
    + `CS203_DSAA_template_test`将调用`test\lab_07\lab_07_C1_test.cpp`,对`source\lab_07\lab_07_C1.cpp`进行测试.    
    + 需要提交的是`source\lab_07\lab_07_C1.cpp`,`test\lab_07\lab_07_C1_test.cpp`可以方便测试,分享测试用例.

### 实际场景:
1. A+B: lab_00_A ,测试样例
    + 这个问题较为简单,见[A+B](./source/lab_00/lab_00_A.cpp).解决起来不复杂.
    + 虽然手工一个一个输入,然后肉眼观察输出.但是如果我们希望严谨的测试,要100组测试数据,难道每次出新版本都要手动输入100次吗?
      显然,有更好的解决方式:使用测试框架.
    + 在本repo,使用`Catch2`测试框架.
      比如,我们有四组数据,第一组,第二组测试边界值,第三组使用随机数测试对偶性与正确性,第四组测试几个手动的随机值.
      参见[test_for_lab00_A](./test/lab_00/lab_00_A_test.cpp).
    + 这样一来,我们只需要每次修改完主文件之后,run `CS203_DSAA_template_test`, 对其进行调用,就能验证其在所有的测试用例上的正确性.
      测试的结果也会出现在run完的输出中.
2. 多个输出值的检查:`Catch::Matchers`
    + 上面的例子里,输出值只是一个值,所以手动检查的难度不大,但是如果目标输出是一个数组,那么手动检查的难度就非常大了.
    + 举例:[Crzay Plan](https://acm.sustech.edu.cn/onlinejudge/problem.php?id=1250),输入可能有1.1*10^6个.  
      这种情况下对这么多值进行直接的观察就很难,所以我们预先将期望的值直接写在测试文件里,用Catch2内置的Matcher比较.
      见[test_for_lab00_B](./test/lab_00/lab_00_B_test.cpp)的`CHECK_THAT()`部分.
    + 当然,这种情况也只适用于规模比较小的情况,规模再大的话,直接由人手动写在测试文件里也太占空间了.
3. 将文件重定向到标准输出中:
    + 常见于tree,graph类的问题,debug需要的数据集都比较大,不方便直接写在代码中.
    + 比如[判断二分图](./source/lab_00/lab_00_C.cpp),一张图可以有几十上百个node,写在内部占用空间太大.
    + 而在这里,使用文件的重定向输入,便可以省去手动输入的方式.
    ```c++
        // begin prepare
        std::streambuf *backup;
        std::ifstream fin;
        fin.open(path); // 打开path(一个代表路径的string)作为读入的数据源.
        backup = cin.rdbuf();
        cin.rdbuf(fin.rdbuf());
        // 开始重定向,此时可以read
        auto result_data = isBipartite(read());
        // read结束,将输入恢复.
        cin.rdbuf(backup);
    ```
    只需要准备好输入的数据与结果,就可以从文件中读取,执行后判断结果是否符合预期.   
    + test case 1-5为最简单的逐个判断,最简单,代码量最大.
    + test case loop 则优化了一些,但是还是比较麻烦,for循环还需要了解测试样例的个数.
    + test case with tuple 则最优雅,修改起来的难度最小.
    + PS: 此处注意,引用文件的相对路径,不是直接的`test/lab_00/lab_00_C_data/01.data.in`,
    而是编译出的文件相对于测试数据的相对路径.
    在样例中,编译出的文件在`CS203_DSAA_template/cmake-build-debug`下,所以需要加`./../`
    + PS2: 文件重定向输出不说了,因为输出就两个,保证数据正确和格式正确,数据正确完全可以通过读取*.data.out之后来判断,
    格式正确主要是看output函数.

4. TODO: 介绍为什么要将 `读取` `数据处理` `输出` 分开,以及这样做有什么好处　
  
TODO: 为什么要选择C++做题.   
TODO: 介绍一些神秘操作.比如手动开优化等.   
TODO: 为什么要选择Catch2,而不是google test等.

[![MIT](https://img.shields.io/badge/License-MIT-orange)][MIT_Link]

[![CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-orange)][cc_by_nc_sa_4_0]

[![CC BY-SA 4.0][cc_by_nc_sa_4_0_image]][cc_by_nc_sa_4_0]

### test Based on  
![Catch 2](https://github.com/catchorg/Catch2/blob/master/artwork/catch2-logo-small.png?raw=true)

[MIT_Link]: http://opensource.org/licenses/MIT

[cc_by_nc_sa_4_0]: https://creativecommons.org/licenses/by-nc-sa/4.0/

[cc_by_nc_sa_4_0_image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png

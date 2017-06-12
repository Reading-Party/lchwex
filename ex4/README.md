# 工具介绍Valgrind

## 安装

可以从源码编译安装：

1. 下载源码，然后用md5sum验证来源:  
```
   wget http://valgrind.org/downloads/valgrind-3.12.0.tar.bz2
   md5sum valgrind-3.12.0.tar.bz2
```
2. 解压：

```
  tar -xjvf valgrind-3.12.0.tar.bz2
  cd valgrind-3.12.0
  ./configure
```
3. 运行make
4. 运行sudo make install 安装

Linux下还需要libc的debug工具：sudo apt-get install libc6-dbg
其他平台，注意看valgrind命令执行后的提示信息。

### valgrind工具介绍

Valgrind是一套Linux下，开放源代码（GPL V2）的仿真调试工具的集合。Valgrind由内核（core）以及基于内核的其他调试工具组成。内核类似于一个框架（framework），它模拟了一个CPU环境，并提供服务给其他工具；而其他工具则类似于插件 (plug-in)，利用内核提供的服务完成各种特定的内存调试任务。

Valgrind包括如下一些工具：

1. Memcheck。这是valgrind应用最广泛的工具，一个重量级的内存检查器，能够发现开发中绝大多数内存错误使用情况，比如：使用未初始化的内存，使用已经释放了的内存，内存访问越界等。这也是本文将重点介绍的部分。
2. Callgrind。它主要用来检查程序中函数调用过程中出现的问题。
3. Cachegrind。它主要用来检查程序中缓存使用出现的问题。
4. Helgrind。它主要用来检查多线程程序中出现的竞争问题。
5. Massif。它主要用来检查程序中堆栈使用中出现的问题。
6. Extension。可以利用core提供的功能，自己编写特定的内存调试工具


### Rust

Valgrind不限于检测C程序，也可以检测Rust程序

```
valgrind --leak-check=full --show-reachable=yes ./learn
```
也有cargo的一个插件是基于valgrind做的，目的是方便使用valgrind：

https://github.com/pegasos1/cargo-profiler

同类型工具还有：

https://github.com/japaric/rust-san

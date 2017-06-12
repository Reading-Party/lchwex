# APR （Apache可移植运行时）

本节练习中做的小工具用到了APR，它的主要功能是为应用提供一个可移植的、平台无关的层。它使用底层的、交叉平台的库来提供文件系统访问、网络编程、进程和线程管理以及共享内存等功能。那些使用Apache专有APR、而不是使用本地系统功能的模块在平台之间只可以移植的，并且能够在所有被Apache所支持的平台上被干净地（最坏的情况也是需要很小程度修改）编译。

APR实用库（APR-UTIL，或者APU）是APR项目的第二个库。它在APR基础上，使用统一标准的编程接口，提供了一部分功能函数集。APU并不是每在一个平台上都有一个单独的模块，但是它为某些其他常用的资源例如数据库提供了一个类似的方法。

APR和APR-UTIL采用了一些约定，使得它们的API具有同质性，并且易于使用。

APR和APU提供了很多模块，供外部使用。比如shell.h里用到的apr_thread_proc.h，就是提供了线程和进程函数以供使用。

### 安装

```
$ wget http://archive.apache.org/dist/apr/apr-1.5.2.tar.gz
$ tar -xzvf apr-1.5.2.tar.gz
$ cd apr-1.5.2/
$ ./configure  &  make & sudo make install

$ wget http://archive.apache.org/dist/apr/apr-util-1.5.2.tar.gz
$ tar -xzvf apr-util-1.5.2.tar.gz
$ cd apr-1.5.2/
$ ./configure  &  make & sudo make install


```

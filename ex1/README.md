# make命令说明

当你执行命令`make ex1`的时候，就是告诉make，我想创建名为ex1的文件，make会做下面几件事：

- 文件ex1是否存在
- 没有。好的，有没有其他ex1开头的文件
- 有，是ex1.c
- 使用命令cc ex1.c -o ex1来构建文件ex1

`CFLAGS="-Wall" make ex1` 命令前面多了一个`CFLAGS="-Wall"`，这会给cc命令前面加一个`-Wall`选项，该选项会让编译器报告所有警告。

我们还可以使用Makefile文件，具体查看ex2/Makefile。

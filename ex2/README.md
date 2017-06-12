Makefile文件：

```
CFLAGS=-Wall -g

clean:
	rm -f ex2
```

注意rm命令前面是一个TAB，此处不能用空格或空格tab混合。

-g标识用来获取调试信息。

clean部分告诉make如何清理小项目。

```
$ make clean
$ make ex2
```

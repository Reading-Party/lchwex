# 内存里的字符串

`char *s = "NIHAO";`

```
|     s:400     |
|---|---|---|---|

|'N'|'I'|'H'|'A'|'O'| 0 |
|---|---|---|---|---|---|
|400|401|402|403|404|405|

```

如上图，假设字母A处于内存的第400号格子，那么后面几个字母也是紧跟着的。 变量s本身并没有储存字符串，而存的是字符串的首地址400。也即，s指向这个字符串。

为什么没有专门一个字符串的类型而是要靠一个指针指向它呢？因为字符串的长度是不固定的，所以一个字符串还包含着长度信息，基本类型是无法处理数据结构的。

我们都知道字符串是以0结尾的，而且这个更像是一种约定，C编译器本身并没有对此做任何保证。

### 比较字符串

```
const char *s = "abcd";
const char *t = "abcd";
if (s == t) {
    ...
}
/* right */
if (!strcmp(s, t)) {
    ...
}
```

因为s和t都没有存字符串的内容，它们存的是字符串的地址，如果用==比较，比较的是两个字符串的地址是否相同。我们希望比较的是内容是否相同。

请使用C语言库函数中的strcmp比较字符串是否相等

### 复制字符串

```
tries to copy a string
char s[5] = "abcd";
char *t = s;
t[3] = 'z';
puts(s);

```
上面这种做法让t和s指向同一字符串，修改t指向的内容，会发现s指向的内容也被修改了。这种做法没有错，经常会用到，但不一定是你想要的。

```
/* wrong */
char *s = "abcd";
char *t; /* not initialized */
strcpy(t, s);
/* right */
char *s = "abcd";
char t[10] = {0}; /* or char *t = (char *) malloc(5*sizeof(char)); */
strcpy(t, s);

```

使用strcpy复制字符串的内容而不是指针，但也要注意初始化t这个指针
也可以使用strdup来复制字符串

### 怎样让函数得到一个字符串结果

int，float之类的很简单直接return就好 但现在我想写一个函数，它能够得到一个字符串

#### 三种错误的或者不太好的做法 :

```
/*
no problem, but meaningless
返回一个字符串常量并没有问题因为它不可修改，但是不可修改也就没什么意义了。
*/
const char *f()
{
    const char *s = "abcd";
    return s;
}

/*
返回一个局部的数组是完全错误的
这个数组的内存会在函数调用完后被收回，因此返回的指针指向的时候没有意义的地方。
现代编译器一般都会对这个有warning。
*/
char *f()
{
    char s[100];
    /* do something with s */
    return s;
}

/*
result correct but not good
返回malloc的指针，虽然可以得到正确答案，但是调用该函数的人很有可能不知道此函数里面分配过内存
多次调用这个函数的结果就是内存溢出，不推荐
*/
char *f()
{
    int n = 10;
    char *s = (char *) malloc(n*sizeof(char));
    /* do something with s */
    return s;
}

```

#### 正确的做法:

正确的做法是把分配内存这种事情放在函数外面做，正如strcpy一样

```
char *strcpy(char *dest, const char *src)
{
    int i;
    for (i = 0; i < strlen(src); i++) {
        dest[i] = src[i];
    }
    return dest;
}
```

dest是我们想要返回的字符串，它是从外面传进来的原因是我们不想在函数内部为它分配内存，而是在外面分配好了，里面只对这个字符串进行修改。

注意这里返回了`char *`但其实返回的正是原本传进来的dest，这里只是为了方便而已。

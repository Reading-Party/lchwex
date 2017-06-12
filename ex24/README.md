# ANSI C语言标准文件IO函数

- fscanf
- fgets
- fopen
- freopen
- fdopen
- fclose
- fcloseall
- fgetpos
- fseek
- ftell
- rewind
- fprintf
- fwrite
- fread

可以使用man命令对这些函数的用法进行查看

# c语言中常用的I/O函数

最常用的字符串的标准I/O函数有

```
getchar()、putchar()、gets()、puts()、scanf()、printf()、fputs()、fgets()、getc()、putc()、fscanf()、fprintf()、fseek()、ftell()、fread()、fwrite()等。
```

getchar()和putchar()

他们是专门为字符I/O设计的一对C函数，getchar()函数没有参数，它返回来自输入设备的下一个字符。以下输入输出代码是等效的。这两个函数能读取输入的任意一个字符串，包括空格和换行符。
```
ch=getchar();
scanf("%c", &ch);putchar(ch);printf("%c", ch);
```

gets()、puts()

gets()能从系统的标准输入设备获得一个字符串，在输入的时候遇到一个换行符(\n)终止，并不读取此换行符，并且在后面自动加上字符串结束标志\0。如以下例子所示

```
 #include<stdio.h>
 #define MAX 61
 int main()
 {
     char name[MAX];
     char * ptr;

     printf("Hi, what's your name?\n");
     ptr=gets(name);
     puts(ptr);//puts(name);
     puts(" Ah! that's a good name, i like it!");
     ;
 }

```
scanf()和printf()

这两个函数大家都比较熟悉，我就只讲一下这两个函数的返回值。其中scanf()函数的返回成功读取的个数，常用来检测读取是否正确。printf()返回的则是输出的字节数(包含结尾的换行符)。还有一点需要注意的就是printf用在对于字符串%s的输出时，接收的是字符数组的名字也就是字符串的首地址。

fgets()和fput()

`char * fgets(char * , int , FILE *);`总共要输入三个参数，第一个参数是指向输入的字符串的地址，第二个参数是字符串的最大的长度（这个参数可以控制原来的数组空间是否溢出），第三个就是一个文件指针，可以由文件输入，也可以由标准输入设备输入（stdin）。它能读取标准输入中，由于确认输入而输入额外的换行符，同时在字符串的后面添加一个\0。函数能返回输入字符串的首字母的地址。

`void fputs(char * ,FILE *);`

getc(),putc()

这两个函数的工作方式与函数getchar()和putchar()非常相似，不同之处在于你需要告诉getc()和putc()函数他们要使用的文件。如下所示

```
FILE *fp, *fpout;
fp=fopen("input.txt","r");
fpout=fopen("output.txt","w");
ch=getc(fp);      //一次只能读取一个字符putc(ch,fpout);   //一次只能输出一个字符
```

fscanf()和fprintf()

fscanf()和fprintf()的工作方式与scanf和printf()函数相似，区别在于前者需要第一个参数来指定合适的文件。如下所示

```
 #include<stdio.h>
 #include<stdlib.h>
 #define MAX 40
 int main()
 {
     FILE * fp;
     char words[MAX];

     if((fp=fopen("words","a+"))==NULL)
     {
          frptinf(stdout, "can't open \"words\" file.\n");
          exit();
     }
     puts("Enter words to add to the file: press to the Enter");
     puts("key at the begining of a line to terminate.");
     ] != '\0')
         fprintf(fp,"%s ",words);
     puts("File contents: ");
     rewind(fp);
     )  //它的返回值也是成功读取值的个数
         puts(words);
     )
         fprintf(stderr, "error closing file.\n");
     ;
 }
```

fseek()和ftell()

这两个函数被称为文件的随机存储函数，其实也不能算作是I/O函数，它能够把文件中的字符串当成数组来处理，直接访问其中的某一位。下面是一些例子，其中fp是一个文件指针

```
fseek(fp, 0L, SEEK_SET); //找到文件的开始处
fseek(fp, 10L, SEEK_SET);  //找到文件的第十个字节
fseek(fp, 2L, SEEK_CUR);  //从文件当前位置向前移动2个字节
fseek(fp, 0L, SEEK_END);   //到达文件的结尾处
fseek(fp, -10L, SEEK_END);  //从文件的结尾处退回10个字节

```
fseek如果操作成功的话，返回0；如果试图移动超过文件范围，则返回-1。

ftell()函数为long类型，它返回文件的当前位置。文件的第一个字节到文件开始处的距离是字节0，依次类推。用法如下

```
long site;
...
site=ftell(fp);  //返回文件指针所指的当前位置
```

fread()和fwrite()

这两个函数被称为二进制I/O函数。一般用fprintf()函数向文件中存储浮点数的时候，由于%f的输出，一般情况下不能得到精确值。而使用fread()和fwrite()这两个函数就可以避免这个问题。

先来看一下fwrite()

fwrite()函数的原型是：

```
xize_t fwirte(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp);
```

例如，要保存一个浮点数组的数据对象，可以这样做

```
];
FILE * fp;
...
fwrite=(data, , fp);
```

fwirte的返回值是成功写入size大小的数据块的数目，该数目应该与nmemb相等，如果小于的时候就表明由写入的错误。

fread()函数的原型是：

```
size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp);
```

例如，要从文件中读取10个double值的数组，并保存一个数组中，如下可以实现

```
];
FILE * fp;
...
fread(data, , fp);
```

函数的返回成功读入的项目数，正常情况下与nmemb相等。

下面的一个例子组合使用了上述提到的几种I/O函数

```
 /*随机存储，二进制I/O*/
 #include<stdio.h>
 #include<stdlib.h>
 #define ARSIZE 1000

 int main()
 {
     double numbers[ARSIZE];
     double value;
     const char * file = "numbers.dat";
     int i;
     long pos;
     FILE * iofile;
     //创建一组double类型的值
     ; i < ARSIZE; i++)
         numbers[i] = );
     //尝试打开文件
     if((iofile = fopen(file, "wb")) == NULL)
     {
         fprintf(stderr, "Could not open %s for output.\n", file);
         exit();
     }
     fwrite(numbers, sizeof(double), ARSIZE, iofile);
     fclose(iofile);
     if((iofile = fopen(file, "rb")) == NULL)
     {
         fprintf(stderr, "Could not open %s for random access.\n", file);
         exit();
     }
     //从文件中读取所选的项目
     printf("Enter an index in the range 0-%d.\n", file);
     scanf("%d",&i);
      && i < ARSIZE)
     {
         pos = (long) i * sizeof(double); //计算偏移量
         fseek(iofile, pos, SEEK_SET);   //在文件中定位到目标位置
         fread(&value, , iofile);
         printf("The value there is %f.\n", value);
         puts("Next index (out of range to quit):\n");
         scanf("%d",&i);
     }
     fclose(iofile);
     puts("Bye!");
     ;
 }
 ```

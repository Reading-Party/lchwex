# 该Makefile文件被设计用于构建一个库

# 几乎每个项目都会设置CFLAGS
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
# 用于链接库的选项
LIBS=-ldl $(OPTLIBS)
# 设置一个叫做PREFIX的可选变量
PREFIX?=/usr/local
# 通过执行wildcard在src中搜索所有*.c文件来创建SOURCES变量
SOURCES=$(wildcard src/**/*.c src/*.c)
# 一旦创建了源文件列表，就可以使用patsubst命令获取*.c文件的SOURCES来创建目标文件的新列表。
# 你可以告诉patsubst，把所有的%.c扩展为%.o，并将其赋值给OBJECTS
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
# 寻找测试源文件
TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%.o,$(TEST_SRC))

# 设置目标为build/libYOUR_LIBRARY.a
TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# ####################### 以上是Makefile文件头部
# 当没有提供Target的时候make会默认运行第一个目标。这里叫做all:，并且它提供$(TARGET) tests作为构建目标。

# The Target build
all: $(TARGET) $(SO_TARGET) tests
# 另一种用于执行“开发者构建”的target
dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
# 创建build目录之后编译所有的OBJECTS
$(TARGET): build $(OBJECTS)
				ar rcs $@ $(OBJECTS)
				ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
				$(CC) -shared -o $@ $(OBJECTS)

build:
				@mkdir -p build
				@mkdir -p bin

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
				sh ./tests/runtests.sh

valgrind:
				VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean:
				rm -rf build $(OBJECTS) $(TESTS)
				rm -rf tests/tests.log
				find . -name "*.gc*" -exec rm {} \;
				rm -rf `find . -name "*.dSYM" -print`

# The Install
# makefile会将构建出来的库放入PREFIX的lib目录下
install: all
				install -d $(DESTDIR)/$(PREFIX)/lib/
				install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
				@echo Files with potentially dangerous functions.
				@egrep $(BADFUNCS) $(SOURCES) || true

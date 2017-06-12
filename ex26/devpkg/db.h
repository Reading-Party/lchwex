/*
程序中必须有个方法来记录已经安装过的url、列出这些url，并且检查一些程序是否已经安装以便跳过。
我们来创建一个简单、扁平的文件数据库
*/

#ifndef _db_h
#define _db_h

#define DB_FILE "/usr/local/.devpkg/db"
#define DB_DIR "/usr/local/.devpkg"

int DB_init();
int DB_list();
int DB_update(const char *url);
int DB_find(const char *url);

#endif

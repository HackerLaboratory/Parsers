#直接执行make命令进行构建
#http://www.xumenger.com/make-makefile/

#目标 : 依赖
#<tab键>命令
#最后执行的编译命令要放在最前面！

#链接.o生成可执行文件
testDBF : cDBF.o testDBF.o
	gcc testDBF.o cDBF.o -o testDBF
#编译(不链接).c生成.o文件，通过-DDEBUG开启DEBUG编译选项
cDBF.o : ../src/cDBF.c ../src/cDBF.h ../src/cDBFStruct.h
	gcc -DDEBUG -c ../src/cDBF.c -o cDBF.o
testDBF.o : testDBF.c
	gcc -c testDBF.c -o testDBF.o

文件说明：
mylib.h:函数sum()、max()、init()、show()的声明
aoprand.c:函数sum()、max()的定义
base.c:函数init()、show()的定义
libdylib.so:使用aoprand.o，base.o创建的动态库
localDyTest.c:测试libdylib.so的用例（编译时链接方式）
localDyTest:测试用例的可执行文件

# 源码目录 -- [返回首页](https://github.com/wzx19840423/php-extension/)
* [输出Hello World](/src/hello)
* [初始化和关闭函数](/src/init)
* [基础数据变量](/src/variable)
* [函数传引用参数](/src/reference)

linux环境生成扩展的步骤：

1. 进入扩展源码目录，按顺序执行以下命令
2. phpize
3. ./configure
4. make
5. make test

如果执行都正确，会在modules目录生成.so文件

测试扩展：

1. 修改php.ini的配置改为enable_dl = On
2. 将编译生成的so文件拷贝到php的扩展目录
3. 在扩展源码目录执行php test.php查看结果
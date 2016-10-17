# 输出Hello World -- [返回首页](https://github.com/wzx19840423/php-extension/)

linux环境生成hello.so的步骤：

1. phpize
2. ./configure
3. make
4. make test

如果执行都正确，会在modules目录生成hello.so

执行方法：

1. 修改php.ini的配置改为enable_dl = On
2. 将编译生成的so文件拷贝到php的扩展目录
3. 执行php test.php，输出"Hello World"表示扩展正确。

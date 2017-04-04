#ifndef TESTLINUX_H_INCLUDED
#define TESTLINUX_H_INCLUDED
#include<iostream>
//!可以在Windows下使用linux的头文件
#include<sys/types.h>
//包含流的操作
//!必须最早出现
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
//
#include<fcntl.h>

#include<sys/stat.h>
namespace Linux {
    void testLinuxHeader() {
        char *str="Hello World\n";
        //输出
        write(1,str,strlen(str));
        char* str2=new char[100];
        //输入
        int size=read(0,str2,100);
        write(1,str2,size);

    }
    /**
    open建立了一条到文件或设备的访问路径
    **/
    void testFileOpr() {
        //建立并打开一个文件
        int d=open("myfile",O_CREAT,S_IRUSR);
        std::cout<<d<<endl;
        int r=close(d);
        std::cout<<r<<endl;


    }
    void testProcess(){
        //获得当前进程的id
        //i386上pid_t和int兼容
        pid_t pid=getpid();
        std::cout<<pid<<endl;
        //
        //fork被调用一次，但能够返回两次
    }
    void testFork(){
//        fork();

//        pid_t child_pid;
//        //声明一个变量作为锁,保证原进程和子进程均能完整执行
//        int status;
//        //fork调用成功，对子进程返回0，对父进程返回子进程的pid
//        if((child_pid=fork())==0){
//            //相当于子进程中执行的代码
//            //对于子进程，必须在其中执行getpid才能获得相对于整体的pid
//            //如果直接打印child_pid则显示为0
//            std::cout<<"This is child process "<<getpid()<<endl;
//            std::cout<<getpid()<<" 's parent process id is "<<getpid()<<endl;
//        }else{
//            std::cout<<"This is parent process "<<getpid()<<endl;
//            std::cout<<getpid()<<" 's child process id is "<<child_pid<<endl;
//        }

    }
    void testDir(){


        char* dir="c:\\";
        chdir(dir);

        int bufSize=100;
        char* cwd=new char[bufSize];
        //获得当前目录
        getcwd(cwd,bufSize);
        std::cout<<cwd<<endl;
    }
    void test(){
        testFork();
//        testProcess();
//        testDir();
    }
};
#endif // TESTLINUX_H_INCLUDED

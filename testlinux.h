#ifndef TESTLINUX_H_INCLUDED
#define TESTLINUX_H_INCLUDED
#include<iostream>
//!������Windows��ʹ��linux��ͷ�ļ�
#include<sys/types.h>
//�������Ĳ���
//!�����������
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
//
#include<fcntl.h>

#include<sys/stat.h>
namespace Linux {
    void testLinuxHeader() {
        char *str="Hello World\n";
        //���
        write(1,str,strlen(str));
        char* str2=new char[100];
        //����
        int size=read(0,str2,100);
        write(1,str2,size);

    }
    /**
    open������һ�����ļ����豸�ķ���·��
    **/
    void testFileOpr() {
        //��������һ���ļ�
        int d=open("myfile",O_CREAT,S_IRUSR);
        std::cout<<d<<endl;
        int r=close(d);
        std::cout<<r<<endl;


    }
    void testProcess(){
        //��õ�ǰ���̵�id
        //i386��pid_t��int����
        pid_t pid=getpid();
        std::cout<<pid<<endl;
        //
        //fork������һ�Σ����ܹ���������
    }
    void testFork(){
//        fork();

//        pid_t child_pid;
//        //����һ��������Ϊ��,��֤ԭ���̺��ӽ��̾�������ִ��
//        int status;
//        //fork���óɹ������ӽ��̷���0���Ը����̷����ӽ��̵�pid
//        if((child_pid=fork())==0){
//            //�൱���ӽ�����ִ�еĴ���
//            //�����ӽ��̣�����������ִ��getpid���ܻ������������pid
//            //���ֱ�Ӵ�ӡchild_pid����ʾΪ0
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
        //��õ�ǰĿ¼
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

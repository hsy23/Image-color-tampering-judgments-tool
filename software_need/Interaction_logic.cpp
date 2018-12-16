#include<iostream>
#include<cstdlib>
#include<string>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

string order = "./build/examples/cpp_classification/classification.bin software_need/deploy.prototxt software_need/solver_iter_2000.caffemodel software_need/mydata_mean.binaryproto software_need/labels.txt ";

int jud_cd(string cd)
{
  int status = system(cd.c_str());
  return status;
}

int main()
{
	FILE  *stream0;
	stream0 = popen("pwd", "r" );
	char now_add[100];
	memset( now_add, '\0', sizeof(now_add) );
	fread(now_add, sizeof(char), sizeof(now_add), stream0);
	char now_addr[100];
	memset( now_addr, '\0', sizeof(now_addr) );
	for(int i = 0; 1; i++)
	{
		if(now_add[i] == '\n')
			break;
		else
		   now_addr[i] = now_add[i];
	}
	
	string add;
	cout<<"请输入图片或包含图片文件夹的路径"<<endl;
	getline(cin,add);
	if(add.find('.') != string::npos )
	{
		cout<<"你选择了一张图片"<<endl;
                string shellorder = order+add;
		system(shellorder.c_str());
	}
	else
	{
		cout<<"你选择了一个包含图片的文件夹"<<endl;
		cout<<"请再次确认文件路径：（再次输入，从用户根目录开始）";
		for(;;)
		{
		    getline(cin,add);
		    string cd_order = "cd ";
		    string cd_image = cd_order + add;
		        if(!jud_cd(cd_image))
		            break;
		        else
		            cout<<"文件路径有误，请重新输入"<<endl;
		}

        chdir(add.c_str());
        FILE   *stream;
        FILE   *stream2;
        char   buf[50000];
        char   size_f[5];
        memset( buf, '\0', sizeof(buf) );//初始化buf,以免后面写如乱码到文件中	
	memset( size_f, '\0', sizeof(size_f) );
        stream = popen("ls", "r" ); //将“ls -l”命令的输出 通过管道读取(“r”参数)到FILE* stream
        fread(buf, sizeof(char), sizeof(buf), stream); //将刚刚FILE* stream的数据流读取到buf中
        pclose(stream);

        stream2 = popen( "ls | wc -l", "r" );
        fread( size_f,sizeof(char),sizeof(size_f),stream2);
        pclose(stream2);
        int num_f;
	sscanf(size_f,"%d",&num_f);

        cout<<"共选中"<<num_f<<"张图片"<<endl;

        char name_f[num_f][50];
        memset(name_f,'\0', sizeof(name_f));
        int j = 0;
        for(int i = 0; i<num_f; i++)
        {
            for(int k = 0; 1;k++,j++)
            {
                if(buf[j] == '\n')
                {
                    j++;
                    break;
                }
                else
                {
                   name_f[i][k] = buf[j];
                }
            }
        }
        
	
	chdir(now_addr);
        cout<<"你希望将判断结果输出到终端还是文件内？（终端输入0，文件输入1）";
        int j_input;
        cin>>j_input;
        if(!j_input)
        {
            for(int i = 0; i<num_f;i++)
            {
                string shellorder = order + add + '/' + name_f[i];

                system(shellorder.c_str());
            }
        }
        else
        {
            for(int i = 0; i<num_f;i++)
            {
                string shellorder = order + add + '/' + name_f[i] + " >> " + add+ "/result.txt";
                system(shellorder.c_str());
            }
		cout<<"文件已成功写入图片文件夹下"<<endl;
        }
    }
    return 0;
}


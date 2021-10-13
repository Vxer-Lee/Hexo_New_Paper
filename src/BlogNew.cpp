/***********************************************************
* 生产力工具，主要是用来生成写博客的Markdown文件。
* 
* 参数：【文章名】【分类】【标签】
* 
* By:VxerLee
* Time:2021年10月13日 10:42:52
* **********************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctime>
using namespace std;

void usage()
{
	printf("\n \
                              ########                  #\n \
                          #################            #\n \
                       ######################         #\n \
                      #########################      #\n \
                    ############################\n \
                   ##############################\n \
                   ###############################\n \
                  ###############################\n \
                  ##############################\n \
                                  #    ########   #\n \
                     ##        ###        ####   ##\n \
                                          ###   ###\n \
                                        ####   ###\n \
                   ####          ##########   ####\n \
                   #######################   ####\n \
                     ####################   ####\n \
                      ##################  ####\n \
                        ############      ##\n \
                           ########        ###\n \
                          #########        #####\n \
                        ############      ######\n \
                       ########      #########\n \
                         #####       ########\n \
                           ###       #########\n \
                          ######    ############\n \
                         #######################\n \
                         #   #   ###  #   #   ##\n \
                         ########################\n \
                          ##     ##   ##     ##\n \
                        [Lee.Reverse & Pwn & Web]\n \
		");
    printf("\n");
    printf("Usage:\n");
    printf("      BlogNew [文章名] [标题] [分类] [标签] [\"时间\"]\n");
}

int main(int argc,char *argv[])
{
    system("pwd");
    return 0;
	if (argc<=1)
	{
		usage();
		return 0;
	}

    //两种方式,一种可以没时间系统自动生成，另外一直有时间
    try
    {

        char* _Postname = argv[1];
        char* _title = argv[2];
        char* _Categories = argv[3];
        char* _tags = argv[4];
        char* _date = argv[5];

        /*
        ---
        title: 湖湘杯Re writeup
        date: 2020-1-09 14:22:52
        tags: ['ctf系列']
        categories: PC逆向
        cover: ../cover/PCRe/huxiangbei.png
        ---
        <meta name="referrer" content="no-referrer"/>
        */
        string __ = "---\n";
        string title = "title: "; title.append(_title); title.append(" \n");
        string date = "date: ";  
        string tags = "tags: ";  tags.append("['']"); tags.append("\n");
        string categories = "categories: "; categories.append(_Categories); categories.append("\n");
        string cover = "cover: ../cover/xxx/xxx.png"; cover.append("\n");
        string referrer = "<meta name=\"referrer\" content=\"no - referrer\"/>\n";

        if (argc <= 5)
        {
            //获取当前时间
            time_t rawtime;
            struct tm* ptminfo;

            time(&rawtime);
            ptminfo = localtime(&rawtime);
            char _date_now[256] = { 0 };

            sprintf(_date_now, "%02d-%02d-%02d %02d:%02d:%02d",
                ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
                ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec);

            date.append(_date_now); date.append("\n");
        }
        else
        {
            date.append(_date); date.append("\n");
        }

        //写出 文章名.md
        string name = _Postname;
        name.append(".md");
        FILE* fp = fopen(name.c_str(), "w+");
        if (fp != NULL)
        {
            string Alltext = "";
            Alltext.append(__);
            Alltext.append(title);
            Alltext.append(date);
            Alltext.append(tags);
            Alltext.append(categories);
            Alltext.append(cover);
            Alltext.append(__);
            Alltext.append(referrer);
            fwrite(Alltext.c_str(), 1, Alltext.length(), fp);
        }
        else
        {
            return -1;
        }
    }
    catch (const std::exception& e)
    {
        printf(e.what());
    }

	return 0;
}


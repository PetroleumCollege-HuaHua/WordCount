#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int ch, count = 1;
  FILE *pt; //文件指针
  // 判断是否输入文件
  if (argc != 3)
  {
    printf("请使用格式: %s -c/-w 文件名", argv[0]);
    exit(1); //非正常退出
  }
  // 判断能否成功打开txt文件
  if ((pt = fopen(argv[2], "r")) == NULL)
  { //将argv[1]赋值给指针pt
    printf("打开文件 %s 失败，请确认文件名是否正确", argv[2]);
    exit(1);
  }
  
  if (strcmp(argv[1], "-c") == 0)//当第二个指令为 -c 时，做字符检测 
  {
    count = 0;
    while ((ch = getc(pt)) != EOF)
    {
      count++;
    }
    printf("字符数%d个\n", count);
  }
  
  else if (strcmp(argv[1], "-w") == 0)//当第二个指令为 -w 时，做单词检测 
  {
    while ((ch = getc(pt)) != EOF)
    {
      if ((ch == ' ') || (ch == ','))//被空格和逗号隔开的视为单词 
        count++;
    }
    printf("单词数%d个\n", count);
  }
  else//输入指令非-c或-w，提示并退出 
  {
  	printf("请使用格式: %s -c/-w 文件名", argv[0]);
  	exit(1);
  }
  fclose(pt);
  return 0;
}


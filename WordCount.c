#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int ch, count = 1;
  FILE *pt; //�ļ�ָ��
  // �ж��Ƿ������ļ�
  if (argc != 3)
  {
    printf("��ʹ�ø�ʽ: %s -c/-w �ļ���", argv[0]);
    exit(1); //�������˳�
  }
  // �ж��ܷ�ɹ���txt�ļ�
  if ((pt = fopen(argv[2], "r")) == NULL)
  { //��argv[1]��ֵ��ָ��pt
    printf("���ļ� %s ʧ�ܣ���ȷ���ļ����Ƿ���ȷ", argv[2]);
    exit(1);
  }
  
  if (strcmp(argv[1], "-c") == 0)//���ڶ���ָ��Ϊ -c ʱ�����ַ���� 
  {
    count = 0;
    while ((ch = getc(pt)) != EOF)
    {
      count++;
    }
    printf("�ַ���%d��\n", count);
  }
  
  else if (strcmp(argv[1], "-w") == 0)//���ڶ���ָ��Ϊ -w ʱ�������ʼ�� 
  {
    while ((ch = getc(pt)) != EOF)
    {
      if ((ch == ' ') || (ch == ','))//���ո�Ͷ��Ÿ�������Ϊ���� 
        count++;
    }
    printf("������%d��\n", count);
  }
  else//����ָ���-c��-w����ʾ���˳� 
  {
  	printf("��ʹ�ø�ʽ: %s -c/-w �ļ���", argv[0]);
  	exit(1);
  }
  fclose(pt);
  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>

#define BLOCK_SIZE 4096
#define size 512

int main(int agrc, char** agrv)
{
  char inputFile[50], outputFile[50];
  int inputTest = -1;
  int outputTest = -1;
  int fd;
  ssize_t bytes_read = -1, bytes_write;
  char buffer[512];

  printf("Please input the name of the source file : \n");          // 輸入檔案檔名及位置
  scanf("%s",inputFile);

  if ( (inputTest = open(inputFile , O_RDONLY)) == -1)              // 若開啟檔案失敗，則退出程式。
  {
    perror("Open file failed\n");
    exit(1);
  }    

  printf("Please input the name of the destination file : \n");     // 輸出檔案檔名及位置
  scanf("%s",outputFile);

  outputTest = open(outputFile, O_CREAT | O_WRONLY, 0644);          // 若開啟檔案失敗，則退出程式。
  if (outputTest == -1)
  {
    perror("Open file failed\n");
    return 1;
  }

  while ((fd = read(inputTest,buffer,size)) > 0)                    // 以512個位元組為單位，從第一個檔案讀取資料，並立刻把資料轉寫到第二個檔案，直到讀不到東西為止(讀到檔案結束) 
  {
    write(outputTest,buffer,fd);
  }

  close(inputTest);
  close(outputTest);
  
  return 0;
}

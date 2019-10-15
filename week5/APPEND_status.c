    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>

int main(int argc, char* argv[]){
    int fd;
    if(argc !=2){
        printf("input error\n");
        return -1;
    }
    if((fd=open(argv[1], O_CREAT|O_RDWR | O_APPEND, 0766))<0){
        printf("open error\n");
        return -1;
    }
    if(lseek(fd, 10, SEEK_SET)<0){
        printf("lseek error\n");
        return -1;
    }
    char buf[100];
    if(read(fd,buf, 20)<0){
        printf("read error\n");
        return -1;
    }
    printf("%s\n", buf); 
    if(write(fd, buf, 20)!=20){
    printf("write error\n");
    return -1;
    }
    int new_offset = lseek(fd, 0, SEEK_CUR);
    printf("new offset : %d\n", new_offset);
    return 0;
}


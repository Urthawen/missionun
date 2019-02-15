#include "LibFS.h"
#include "Disque.h"

// variable errno pour gerer les erreurs
int osErrno;

#define MAGICNUMBER 1111

typedef struct _superbloc{
  char unused[508];
  int magicnumber;
} superbloc;


int FS_Format(){
  return 0;
}

int
FS_Boot(char *path)
{
    printf("FS_Boot %s\n", path);

    if (Disk_Init() == -1) {
    	printf("Disk_Init() failed\n");
    	osErrno = E_GENERAL;
    	return -1;
    }

    if (Disk_Load(path) == -1) {
      if(FS_Format() == -1){
        printf("Disk_Load() failed\n");
        osErrno = E_GENERAL;
        return -1;
      }
    }

    superbloc buffer;

    if(Disk_Read(0, buffer.unused) == -1){
      printf("Disk_Read() failed\n");
      osErrno = E_GENERAL;
      return -1;
    }

    if((int)(buffer.magicnumber) != MAGICNUMBER){
      printf("WTF NUMBER WRONG MAN\n");
      osErrno = E_GENERAL;
      return -1;
    }else{
      printf("OK\n");
    }

    return 0;
}


int
FS_Sync()
{
    printf("FS_Sync\n");

    return 0;
}


int
File_Create(char *file)
{
    printf("FS_Create\n");
    // TODO...
    return 0;
}

int
File_Open(char *file)
{
    printf("FS_Open\n");
    // TODO...
    return 0;
}

int
File_Read(int fd, void *buffer, int size)
{
    printf("FS_Read\n");
    // TODO...
    return 0;
}

int
File_Write(int fd, void *buffer, int size)
{
    printf("FS_Write\n");
    // TODO...
    return 0;
}

int
File_Seek(int fd, int offset)
{
    printf("FS_Seek\n");
    // TODO...
    return 0;
}

int
File_Close(int fd)
{
    printf("FS_Close\n");
    // TODO...
    return 0;
}

int
File_Unlink(char *file)
{
    printf("FS_Unlink\n");
    // TODO...
    return 0;
}


// directory ops
int
Dir_Create(char *path)
{
    printf("Dir_Create %s\n", path);
    return 0;
}

int
Dir_Size(char *path)
{
    printf("Dir_Size\n");
    return 0;
}

int
Dir_Read(char *path, void *buffer, int size)
{
    printf("Dir_Read\n");
    return 0;
}

int
Dir_Unlink(char *path)
{
    printf("Dir_Unlink\n");
    return 0;
}

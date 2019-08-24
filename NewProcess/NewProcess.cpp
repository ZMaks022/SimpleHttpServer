//
// Created by user on 2019-08-23.
//

#include "NewProcess.h"

void NewProcess(char request[], int bufSize, int fd_client) {
   int readPipe[2];
   int writePipe[2];
   pipe(readPipe);
   pipe(writePipe);

   pid_t pid = fork();
   switch(pid) {
      case -1:
         perror("fork");
         exit(EXIT_FAILURE);
      case 0:
         close(readPipe[0]);
         close(writePipe[1]);
         dup2(readPipe[1], 1);
         dup2(writePipe[0], 0);
         execlp("/home/max/BackEnd/RetCore/RetCore", "",  NULL);
         close(readPipe[1]);
         close(writePipe[0]);
         _exit(EXIT_SUCCESS);
   }

   close(writePipe[0]);
   write(writePipe[1], request, bufSize);
   close(writePipe[1]);

   close(readPipe[1]);
   writeResponse(readPipe[0], fd_client);
   close(readPipe[0]);
   waitpid(pid, NULL, 0);
}
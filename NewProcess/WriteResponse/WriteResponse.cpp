//
// Created by user on 2019-08-23.
//
#include "WriteResponse.h"

void writeResponse (int readPipe, int fd_client) {
   const int buffSize = 1024;
   char response[buffSize] = "";

   start:
   memset(response, '\f', buffSize);
   read(readPipe, response, buffSize);

   if (response[buffSize-1] == '\f') {
      for (int i = buffSize-1; i >= 0; i++) {
         if (response[i] != '\f') {
            write(fd_client, response, i);
            return;
         }
      }
   }

   // if not found \f
   write(fd_client, response, buffSize);
   goto start;
}

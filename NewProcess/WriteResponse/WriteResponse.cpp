//
// Created by user on 2019-08-23.
//

#include "WriteResponse.h"

void writeResponse (int readPipe, int fd_client) {
   const int buffSize = 1024;
   char response[buffSize] = "";
   int l, r, i;

   start:
   memset(response, '\f', buffSize);
   read(readPipe, response, buffSize);

   if (response[buffSize-1] == '\f') {
      while (r - l > 1) {
         l = 0;
         r = buffSize - 1;
         if (response[(l + r) / 2] == '\f') {
            r = (l + r) / 2;
         } else {
            l = (l + r) /2;
         }
      }

      if (response[l] == '\f') {
         write(fd_client, response, l-1);
      } else {
         write(fd_client, response, r-1);
      }
      return;
   }

   // if not found \f
   write(fd_client, response, buffSize);
   goto start;
}
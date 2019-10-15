//
// Created by user on 2019-08-23.
//
#include "UploadFile.h"
#include <iostream>
using namespace std;

void UploadFile (const char* path, int fd_client) noexcept {
   const char* home = "/home/zakhar/frontend"; // frontend directory
   struct stat* buf;
   char fullpath[strlen(home)+strlen(path)+1];
   strcpy(fullpath, home);
   strcat(fullpath, path);
   int fdimg = open(fullpath, O_RDONLY);
   stat(fullpath, buf);

   sendfile(fd_client, fdimg, 0, buf->st_size);

   close(fdimg);
}

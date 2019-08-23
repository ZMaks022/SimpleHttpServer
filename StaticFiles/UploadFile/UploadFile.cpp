//
// Created by user on 2019-08-23.
//

#include "UploadFile.h"

void UploadFile (const char* path, int fd_client) noexcept {
   const char* home = "/home/zakhar/frontend";
   struct stat* buf;
   char fullpath[strlen(home)+strlen(path)+1];

   strcpy(fullpath, home);
   strcpy(fullpath, path);
   int fdimg = open(fullpath, O_RDONLY);
   stat(fullpath, buf);

   #ifdef LINUX
      sendfile(fd_client, fdimg, 0, buf->st_size);
   #endif

   #ifdef MACOS
      sendfile(fd_client, fdimg, 0, reinterpret_cast<off_t *>(buf->st_size), NULL, 0);
   #endif

   close(fdimg);
}
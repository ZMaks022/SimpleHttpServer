//
// Function UploadFile send static file using socket and path file
//
#include "UploadFile.h"

void UploadFile (const char* path, int fd_client) noexcept {
   Options& opt = Options::Instance();
   const char* home = opt.getFrontend().c_str();
   struct stat buf;

   char fullpath[strlen(home)+strlen(path)+1];
   strcpy(fullpath, home);
   strcat(fullpath, path);

   int fdimg = open(fullpath, O_RDONLY);
   stat(fullpath, &buf);

   sendfile(fd_client, fdimg, 0, buf.st_size);

   close(fdimg);
}

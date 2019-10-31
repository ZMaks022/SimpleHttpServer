//
// Function UploadFile send static file using socket and path file
//

#ifndef WEBSERVER_UPLOADFILE_H
#define WEBSERVER_UPLOADFILE_H

#include "../../Options/Option.h"
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <string.h>
#include <sys/sendfile.h>

void UploadFile (const char* path, int fd_client) noexcept ;

#endif //WEBSERVER_UPLOADFILE_H

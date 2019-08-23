//
// Created by user on 2019-08-23.
//

#ifndef WEBSERVER_UPLOADFILE_H
#define WEBSERVER_UPLOADFILE_H

#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define LINUX
//#define MACOS

void UploadFile (const char* path, int fd_client) noexcept ;

#endif //WEBSERVER_UPLOADFILE_H

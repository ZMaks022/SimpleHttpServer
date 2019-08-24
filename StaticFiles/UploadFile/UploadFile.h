//
// Created by user on 2019-08-23.
//

#ifndef WEBSERVER_UPLOADFILE_H
#define WEBSERVER_UPLOADFILE_H

// TODO move define to main.cpp
#define LINUX
//#define MACOS

#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#ifdef LINUX
   #include <sys/sendfile.h>
#endif



void UploadFile (const char* path, int fd_client) noexcept ;

#endif //WEBSERVER_UPLOADFILE_H

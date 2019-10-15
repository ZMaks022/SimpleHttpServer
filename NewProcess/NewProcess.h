//
// Created by user on 2019-08-23.
//

#ifndef WEBSERVER_NEWPROCESS_H
#define WEBSERVER_NEWPROCESS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../Options/Option.cpp"
#include <string>
#include "WriteResponse/WriteResponse.h"

void NewProcess(char request[], int bufSize, int fd_client);

#endif //WEBSERVER_NEWPROCESS_H

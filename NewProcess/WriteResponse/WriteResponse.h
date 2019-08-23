//
// Created by user on 2019-08-23.
//

#ifndef WEBSERVER_WRITERESPONSE_H
#define WEBSERVER_WRITERESPONSE_H

#include <string.h>
#include <unistd.h>

void writeResponse (int readPipe, int fd_client);

#endif //WEBSERVER_WRITERESPONSE_H

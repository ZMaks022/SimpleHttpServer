//
// NewProcess create a new child process and run some programm
//

#ifndef WEBSERVER_NEWPROCESS_H
#define WEBSERVER_NEWPROCESS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../Options/Option.h"
#include <string>
#include "WriteResponse/WriteResponse.h"

void NewProcess(char request[], int bufSize, int fd_client);

#endif //WEBSERVER_NEWPROCESS_H

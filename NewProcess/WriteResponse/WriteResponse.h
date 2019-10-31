//
// writeResponse - send all output from programm to client
//

#ifndef WEBSERVER_WRITERESPONSE_H
#define WEBSERVER_WRITERESPONSE_H

#include <string.h>
#include <unistd.h>

void writeResponse (int readPipe, int fd_client);

#endif //WEBSERVER_WRITERESPONSE_H

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Library/ParseUrl/Parse.h"
#include "NewProcess/NewProcess.h"
#include "StaticFiles/Check/Check.h"
#include "StaticFiles/UploadFile/UploadFile.h"

int main(int argc, char* argv[]) {
   // TODO CONFIG FILE AND STRUCT

   struct sockaddr_in server_addr, client_addr;
   socklen_t sin_len = sizeof(client_addr);
   int fd_server, fd_client;
   const int bufSize = 8096; char buf[bufSize];
   int fdimg, on = 1;

   // CREATE A SOCKET
   fd_server = socket(AF_INET, SOCK_STREAM, 0);
   if (fd_server < 0) {
      std::cout << "Error socket" << std::endl;
      return 1;
   }
   setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
   // END

   // SETTING
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(80);
   // END

   // BIND AND LISTEN
   if(bind(fd_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
      std::cout << "Error bind" << std::endl;
      close(fd_server);
      return 1;
   } if (listen(fd_server, 10) == -1) {
      std::cout << "Error listen" << std::endl;
      close(fd_server);
      return 1;
   }
   // END

   // MAIN LOOP AND CONNECT TO CLIENT
   while(1) {
      fd_client = accept(fd_server, (struct sockaddr *)&client_addr, &sin_len);
      if (fd_client == -1) {
         std::cout << "Error: can't connect to client" << std::endl;
         continue;
      }

      if(!fork()) {
         /* child process */
         close(fd_server);
         memset(buf, 0, bufSize);
         read(fd_client, buf, bufSize-1);

         // Check url for availability static files
         char* url = ParseUrl(buf, bufSize);
         if (CheckStaticFile(url)) {
            if (!CheckAvailabilitySymbols(url)) {
               close(fd_client);
               exit(0); // rewrite on sending header of error
            }
            if (!AvailableExt(url)) {
               close(fd_client);
               exit(0); // rewrite on sending header of error
            }
            std::cout << 1 << std::endl;
            UploadFile(url, fd_client);
         } else { // TODO give url in arguments to BackEnd
            NewProcess(buf, bufSize, fd_client);
         }

         delete[] url;
         exit(0);
      }
      close(fd_client);

   }
   // END

   return 0;
}















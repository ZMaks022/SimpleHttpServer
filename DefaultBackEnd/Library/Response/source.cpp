#include "header.h"

namespace Server {

  Response& Response::Instance() {
    static Response s;
    return s;
  }

  void Response::write(const char* str) {
    int counter = 0;
    while(str[counter] != '\0') {
      putchar_unlocked(str[counter]);
      counter++;
    }
  }

  void Response::header() {
    this->write("HTTP/1.1 200 OK\r\n");
    this->write("Server: EtmoServer\n");
    this->write("Date: Sun, 21 Apr 2019 11:04:32 GMT\n");
    this->write("Content-Type: text/html; charset=UTF-8\n");
    //this->write("Transfer-Encoding: chunked\n");
    this->write("Connection: keep-alive\r\n\r\n");
    //this->write("Expires: Thu, 19 Nov 1981 08:52:00 GMT\n");
    //this->write("Cache-Control: no-store, no-cache, must-revalidate, post-check=0, pre-check=0\n");
    //this->write("Pragma: no-cache\n");

  }


};

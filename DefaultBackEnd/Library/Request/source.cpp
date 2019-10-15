#include "header.h"

namespace Server {

  Request& Request::Instance() {
    static Request s;
    return s;
  }

  void Request::read() {
    char buffer[256];
    char temp;
    int counter = 0;

    // parse Method
    temp = getchar_unlocked();
    for(; temp != ' '; temp = getchar_unlocked(), counter++){
      buffer[counter] = temp;
    }
    buffer[counter] = '\0';
    this->method = new char[counter+1];
    for(int i = 0; i <= counter; i++)
      this->method[i] = buffer[i];
    counter = 0;

    // parse Url
    temp = getchar_unlocked();
    for(; temp != ' '; temp = getchar_unlocked(), counter++){
      buffer[counter] = temp;
    }
    buffer[counter] = '\0';
    this->url = new char[counter+1];
    for(int i = 0; i <= counter; i++)
      this->url[i] = buffer[i];
    counter = 0;
  }

  char* Request::getMethod() {
    return this->method;
  }

  char* Request::getUrl() {
    return this->url;
  }
};

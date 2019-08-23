//
// Created by user on 2019-08-23.
//

#include "Parse.h"

char* ParseUrl (const char* request, int bufSize) noexcept {
   int counter = 0;
   char* url;

   // Skip method
   int it = 1;
   for (; request[it] != ' '; it++) ;
   it++;

   // Start parse a url
   for (int i = it; request[i] != ' '; i++, counter++) ; // find size of url string
   url = new char[counter+1];
   for (int i = 0; request[it] != ' '; it++, i++)
      url[i] = request[it];
   url[counter] = '\0';

   return url;
}
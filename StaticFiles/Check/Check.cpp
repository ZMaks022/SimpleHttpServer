//
// Created by user on 2019-08-23.
//

#include "Check.h"

bool CheckStaticFile (const char* string) noexcept {
   // Just check the point in string :)
   for (int i = 0; string[i] != '\0'; i++) {
      if (string[i] == '.')
         return true;
   }
   return  false;
}

bool CheckAvailabilitySymbols ( char* string) noexcept {
   char* res = strstr(string, "../");
   if (res != NULL)
      return false;

   return true;
}

bool AvailableExt (char* string) noexcept {
   // check extension
   const int N = 9;
   const char* ext[N] = {
           ".html", ".js", ".css", ".jpg", ".jpeg", ".png", ".gif", ".mp3", ".mp4"
   };

   char* res = strstr(string, ".");
   for (auto it : ext) {
      if (strcmp(it, res) == 0) {
         return  true;
      }
   }
   return  false;
}
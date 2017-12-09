#include "downloader.h"

#include <curl/curl.h>
#include <stdexcept>

namespace
{
   // RAII wrapper for cURL.
   struct Curl
   {
      Curl()
         : curl(curl_easy_init())
      {}

      ~Curl()
      {
         curl_easy_cleanup(curl);
      }

      static size_t write(void* ptr, size_t size, size_t nmemb, FILE* fp)
      {
         return fwrite(ptr, size, nmemb, fp);
      }

      void http_download(const std::string& url, const std::string& destination)
      {
         FILE* fp = fopen(destination.c_str(), "wb");
         if(!fp)
            throw std::runtime_error(std::string("Error opening ") + destination);

         curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Curl::write);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
         res = curl_easy_perform(curl);
      }

      CURL *curl;
      CURLcode res;
   };
}

void scraper::http_download(const std::string& url, const std::string& destination)
{
   Curl curl;
   curl.http_download(url, destination);
}

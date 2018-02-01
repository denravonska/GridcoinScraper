#pragma once

#include <curl/curl.h>
#include <stdexcept>
#include <string>
#include <iostream>

class CppCurl
{
private:
   CURL *m_handle;
   CURLcode res;
   std::string m_data = std::string();

   static size_t write(void* ptr, size_t size, size_t nmemb, FILE* fp)
   {
      return fwrite(ptr, size, nmemb, fp);
   }

   void SendHeaderRequest(const char* url)
   {
      m_data = "";
      curl_easy_setopt(m_handle, CURLOPT_URL, url);
      curl_easy_setopt(m_handle, CURLOPT_NOPROGRESS, 1L);
      curl_easy_setopt(m_handle, CURLOPT_HEADER, 1L);
      curl_easy_setopt(m_handle, CURLOPT_NOBODY,1L);
      curl_easy_setopt(m_handle, CURLOPT_WRITEFUNCTION, CppCurl::WriteDataCallback);
      curl_easy_setopt(m_handle, CURLOPT_WRITEDATA, this);
      res = curl_easy_perform(m_handle);
      // exception handling needs to be improved once it is clear how the database is structured
      if(res != 0)
      {
         throw std::runtime_error(std::string("Error Getting file ") + url);
      }
      clean_curl();
   }


   void SendFileRequest(const char* url, const char* destination)
   {
      FILE* fp = fopen(destination, "wb");
      if(!fp)
      throw std::runtime_error(std::string("Error opening ") + destination);
      curl_easy_setopt(m_handle, CURLOPT_URL, url);
      curl_easy_setopt(m_handle, CURLOPT_NOPROGRESS, 1L);
      curl_easy_setopt(m_handle, CURLOPT_WRITEFUNCTION, CppCurl::write);
      curl_easy_setopt(m_handle, CURLOPT_WRITEDATA, fp);
      // exception handling needs to be improved once it is clear how the database is structured
      res = curl_easy_perform(m_handle);
      if(res != 0)
      {
         throw std::runtime_error(std::string("Error Getting file ") + url);
      }
      fclose(fp);
      clean_curl();
   }

   static size_t WriteDataCallback(void* ptr, size_t size, size_t nmemb, void* pInstance)
   {
      return (static_cast<CppCurl*>(pInstance))->write_data(ptr, size, nmemb);
   }

   size_t write_data(void* ptr, size_t size, size_t nmemb)
   {
      size_t numOfBytes = size * nmemb;
      char *iter = (char*)ptr;
      char *iterEnd = iter + numOfBytes;
      m_data += std::string(iter, iterEnd);
      return numOfBytes;
   }

   void clean_curl()
   {
      curl_easy_cleanup(m_handle);
      m_handle = curl_easy_init();
   }

   time_t get_date(char * datestring)
   {
      return curl_getdate(datestring, NULL);
   }

public:
   CppCurl();
   void settings(const char *url);
   std::string fetch_header(const std::string& url);
   void fetch_content(const std::string& url, const std::string& destination);
   time_t get_date_from_header(std::string date);
   ~CppCurl();
};

namespace scraper
{
   //!
   //! \brief Download file from HTTP.
   //!
   //! \param url File URL.
   //! \param destination Destination path and filename.
   //!
   void http_download(const std::string& url, const std::string& destination);
}

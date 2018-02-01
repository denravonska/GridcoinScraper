#include "downloader.h"

#include <curl/curl.h>
#include <stdexcept>
#include <iostream>
#include <ctime>

#include "boost/filesystem.hpp"

CppCurl::CppCurl()
{
    curl_global_init(CURL_GLOBAL_ALL);
    m_handle = curl_easy_init();
}

std::string CppCurl::fetch_header(const std::string& url)
{
    SendHeaderRequest(url.c_str());
    return m_data;
}

void CppCurl::fetch_content(const std::string& url, const std::string& destination)
{
    SendFileRequest(url.c_str(),destination.c_str());
}

time_t CppCurl::get_date_from_header(std::string header)
{
    std::size_t pos = header.find("Last-Modified: ");
    std::string date = header.substr(pos+14,pos+26);
    return get_date(const_cast<char*>(date.c_str()));
}


CppCurl::~CppCurl()
{
    curl_easy_cleanup(m_handle);
}

void scraper::http_download(const std::string& url, const std::string& destination)
{
   CppCurl curl;
   std::string header = curl.fetch_header(url);
   std::time_t remote_last_modified = curl.get_date_from_header(header);
   if (boost::filesystem::exists(destination))
   {
      std::time_t local_last_modified = boost::filesystem::last_write_time(destination);
      if(remote_last_modified > local_last_modified)
      {
         std::cout << " Download " << url << std::endl;
         curl.fetch_content(url, destination);
      }
      else
      {
         std::cout << "Skipping Download of " << url << " , local file is fresher " << std::endl;
      }
   }
   else
   {
	  curl.fetch_content(url, destination);
   }
}

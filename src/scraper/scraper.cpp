#include "scraper/scraper.h"
#include "scraper/downloader.h"

#include <iostream>

void scraper::synchronize(
      const std::vector<std::string> &cpid_list,
      const std::vector<std::string> &project_list)
{
   if(cpid_list.empty())
      throw std::runtime_error("Empty CPID list");

   if(project_list.empty())
      throw std::runtime_error("Empty project list");

   for(auto& project_url : project_list)
   {
      std::string url = project_url + "/user.gz";
      std::cout << "Download " << url << std::endl;

      scraper::http_download(url, "user.gz");
   }
}

#include "scraper/scraper.h"
#include "downloader.h"
#include "processor.h"

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <iostream>

void scraper::synchronize(
      const std::set<std::string>& cpid_list,
      const std::set<std::string>& project_list)
{
   if(cpid_list.empty())
      throw std::runtime_error("Empty CPID list");

   if(project_list.empty())
      throw std::runtime_error("Empty project list");

   for(auto& project_url : project_list)
   {
      std::string url = project_url + "/user.gz";
      std::cout << "Get Project " << url << std::endl;
      scraper::http_download(url, "user.gz");
      scraper::extract_credits("user.gz", cpid_list);
   }
}

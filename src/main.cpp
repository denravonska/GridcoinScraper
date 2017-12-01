#include "scraper/scraper.h"

int main(int argc, char* argv[])
{
   std::vector<std::string> cpid_list =
   {
     "5a094d7d93f6d6370e78a2ac8c008407"
   };

   std::vector<std::string> project_list =
   {
     "http://srbase.my-firewall.org/sr5/stats",
   };

   scraper::synchronize(cpid_list, project_list);
   return 0;
}

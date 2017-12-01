#include "scraper/scraper.h"

int main(int argc, char* argv[])
{
   std::set<std::string> cpid_list =
   {
     "5a094d7d93f6d6370e78a2ac8c008407",
      "b67846ea8547cedd2d61ce492fe14102",
      "9a8ff0f77debd73b1181f1a864b658af",
      "bbd5cd0501600612d5783051f90c1262"
   };

   std::set<std::string> project_list =
   {
     "http://srbase.my-firewall.org/sr5/stats",
   };

   scraper::synchronize(cpid_list, project_list);
   return 0;
}

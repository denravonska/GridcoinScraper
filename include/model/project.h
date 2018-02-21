#pragma once

#include <string>
#include <ctime>

namespace model
{
   class ProjectResearcher
   {
      int Id;
      int ProjectId;
      int ResearcherId;
      bool InTeam;
      double Credit;
      double RAC;
      double ProjectMag;
      double ProjectMagNTR;
      int WebUserId;
   };

   class Project
   {
   private:

   public:
      int Id;
      int TeamId;
      double TeamTotalRAC;
      double TeamAvgRAC;
      std::string Name;
      std::string Url;
      std::size_t LastSyncUtc;
   };
}

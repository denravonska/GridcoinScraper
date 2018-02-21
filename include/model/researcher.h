#pragma once

#include <string>
#include "sqlite_db.h"

namespace model
{
   class Researcher
   {
   private:
      SqliteDb* database;
      int Id;
      std::string CPID;
      std::string CPIDv2;
      std::string BlockHash;
      std::string Address;
      bool IsValid;
      double TotalMag;
      double TotalMagNTR;
   public:
      Researcher();
      void AddResearcher();
      void GetResearcher();
   };
}

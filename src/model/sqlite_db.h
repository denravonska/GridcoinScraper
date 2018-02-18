#pragma once

#include "model/db.h"
#include <sqlite3.h>
#include <string>
#include <stdexcept>

class sqlite3;

namespace model
{
   class SqliteDb : public IDb
   {
   private:

      int rc;
      char *zErrMsg = 0;
      sqlite3* db;

      static int Callback(void *NotUsed, int argc, char **argv, char **azColName)
      {
         int i;
         for(i = 0; i<argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
         }
         printf("\n");
         return 0;
      }

   public:
      //!
      //! \brief Constructor.
      //!
      //! \param filename Path to database file. If missing this database will
      //! be created.
      //! \throws std::runtime_error on database open or creation failure.
      //!
      SqliteDb(const std::string& filename);
      void ExecuteQuery(std::string sqlquery,std::string dbname);

      //!
      //! \brief Destructor.
      //!
      //! Closes and flushes the currently open database.
      //!
      ~SqliteDb();
   };
}

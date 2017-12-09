#pragma once

#include "model/db.h"
#include <string>

class sqlite3;

namespace model
{
   class SqliteDb : public IDb
   {
   public:
      //!
      //! \brief Constructor.
      //!
      //! \param filename Path to database file. If missing this database will
      //! be created.
      //! \throws std::runtime_error on database open or creation failure.
      //!
      SqliteDb(const std::string& filename);

      //!
      //! \brief Destructor.
      //!
      //! Closes and flushes the currently open database.
      //!
      ~SqliteDb();

   private:
      void CreateTables();

      sqlite3* db;
   };
}

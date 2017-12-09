#include "sqlite_db.h"

#include <sqlite3.h>
#include <stdexcept>

using namespace model;

SqliteDb::SqliteDb(const std::string& filename)
{
   int ret = sqlite3_open(filename.c_str(), &db);
   if(!db)
      throw std::runtime_error("Error opening " + filename);

   if(ret | SQLITE_OPEN_CREATE)
      CreateTables();
}

SqliteDb::~SqliteDb()
{
   sqlite3_close(db);
}

void SqliteDb::CreateTables()
{}

#include "sqlite_db.h"

#include <stdexcept>

using namespace model;

SqliteDb::SqliteDb(const std::string& filename)
{
   rc = sqlite3_open(filename.c_str(), &db);
   if(rc)
      throw std::runtime_error("Error opening " + filename);

   if(rc | SQLITE_OPEN_CREATE)
      ExecuteQuery("CREATE TABLE RESEARCHER",filename);
}

void SqliteDb::ExecuteQuery(std::string sqlquery, std::string dbname)
{
   rc = sqlite3_open(dbname.c_str(), &db);

   if( rc ) {
      throw std::runtime_error(sqlite3_errmsg(db));
   }

   rc = sqlite3_exec(db, sqlquery.c_str(), Callback, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
      throw std::runtime_error(zErrMsg);
      sqlite3_free(zErrMsg);
   }
   sqlite3_close(db);
}



SqliteDb::~SqliteDb()
{
   sqlite3_close(db);
}



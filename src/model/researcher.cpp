#include "model/researcher.h"
#include <string>

using namespace model;

Researcher::Researcher()
{
   database = new SqliteDb("researchdb","RESEARCHER(ID INT PRIMARY KEY NOT NULL, cpid INT, address STRING)");
}

void Researcher::AddResearcher()
{
  database->ExecuteQuery("INSERT INTO RESEARCHER(ID, cpid, address) VALUES (1, 12, 'abc');","researchdb");
}



#pragma once

#include <set>
#include <string>

namespace scraper
{
   //!
   //! \brief Extract total credits from stat file.
   //!
   //! Reads the gzip stat file \p file and extracts the total  credits for
   //! each user in \p cpid_list.
   //!
   //! \param file gzip file to read.
   //! \param cpid_list List of CPIDs to extract credits for.
   //!
   void extract_credits(
         const std::string& file,
         const std::set<std::string>& cpid_list);

}

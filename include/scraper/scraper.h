#pragma once

#include <vector>
#include <string>

namespace scraper
{
   //!
   //! \brief Begin data synchronization.
   //!
   //! Downloads data from project servers and extract the credits for the
   //! given CPIDs.
   //!
   //! This operation is synchronous. If there is a need for asynchronous
   //! data synchronization then this should be wrapped in
   //! std::async_task or something similar.
   //!
   //! \param cpid_list List of CPIDs to extract.
   //! \param project_list List of projects to contact.
   //!
   void synchronize(
         const std::vector<std::string>& cpid_list,
         const std::vector<std::string>& project_list);
}

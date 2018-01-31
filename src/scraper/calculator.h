#pragma once

#include <set>
#include <string>

namespace scraper
{
   //!
   //! \brief Calculate the Recent Average Credits of a user.
   //!
   //! \param avg_credits of user from xml
   //! \param avg_time of user from xml
   //!
   double calc_RAC(
         double avg_credits,
         double avg_time);

}

#pragma once

#include <string>

namespace scraper
{
   //!
   //! \brief Download file from HTTP.
   //!
   //! \param url File URL.
   //! \param destination Destination path and filename.
   //!
   void http_download(const std::string& url, const std::string& destination);
}

#pragma once

#include <memory>

namespace model
{
   // Forward declarations.
   class IDb;

   //!
   //! \brief Database shared pointer.
   //!
   typedef std::shared_ptr<IDb> IDbPtr;
}

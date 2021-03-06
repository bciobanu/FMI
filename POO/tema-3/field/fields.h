#ifndef _FIELD_FIELDS_H_
#define _FIELD_FIELDS_H_

#include "generic.h"

#include "../sets/integer_number.h"
#include "../sets/complex_number.h"
#include "../sets/mod_number.h"
#include "../sets/real_number.h"
#include "../sets/rational_number.h"
#include "../sets/finite.h"

#define DECLARE(NAME, TEMPLATE) \
class NAME##FieldElement : public GenericFieldElement<NAME##Number TEMPLATE> { \
  public: \
    using GenericFieldElement<NAME##Number TEMPLATE>::GenericFieldElement; \
}

namespace crypto {

template <typename T> DECLARE(Integer, <T>);
template <typename T> DECLARE(Complex, <T>);
template <typename T> DECLARE(Real, <T>);
template <typename T> DECLARE(Rational, <T>);
DECLARE(Mod,);
DECLARE(Finite,);

}  // namespace crypto

#undef DECLARE

#endif  // _FIELD_FIELDS_H_
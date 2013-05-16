#ifndef MYINIT_H_
#define MYINIT_H_

#include "../const-c.inc"

using namespace mysql; // hack
using namespace system; // hack
using namespace mysql::system; // hack

#define NEW_MORTAL_AV() ((AV *)sv_2mortal((SV *)newAV()))

#define STD_EXCEPTION_CATCHERS                          \
    catch (std::exception& e) {                         \
      croak("Caught C++ exception of type or derived "  \
            "from 'std::exception': %s", e.what());     \
    }                                                   \
    catch (...) {                                       \
      croak("Caught C++ exception of unknown type");    \
    }

#define SSTREAM_TO_SV(sstream) (newSVpvn(sstream.str().c_str(), sstream.str().length()))

// defined in author_tools/gen_constants.pl => const-c.inc
const char *mbl_event_id_to_perl_class(IV event_id);

#endif

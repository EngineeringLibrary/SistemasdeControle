#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

namespace Identifiers{



    struct to{
        to(unsigned interval) : interval(interval) {}

        unsigned interval;
    };
    struct from{
        from(unsigned interval) : interval(interval) {}

        unsigned interval;

        unsigned* operator > (to b){
            unsigned* ret = new unsigned[2];
            ret[0] = this->interval;
            ret[1] = b.interval;
            return ret;
        }

        from operator --(int){
            return *this;
        }
    };
}
#endif // IDENTIFIERS_H

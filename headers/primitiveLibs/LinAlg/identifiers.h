#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

namespace Identifiers{
    struct to{
        to(int interval) : interval(interval) {}

        int interval;
    };
    struct from{
        from(int interval) : interval(interval) {}

        int interval;

        int* operator > (to b){
            int* ret = new int[2];
            ret[0] = this->interval;
            ret[1] = b.interval;
            return ret;
        }

        int* operator > (int b){
            int* ret = new int[2];
            ret[0] = this->interval;
            ret[1] = b;
            return ret;
        }

        int operator- (int b){
            return this->interval - b;
        }

        int operator+ (int b){
            return this->interval + b;
        }

        void operator = (int b){
            this->interval = b;
        }

        from operator --(int){
            return *this;
        }
    };
}
#endif // IDENTIFIERS_H

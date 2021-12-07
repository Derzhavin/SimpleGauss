//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLECPUAPI_H
#define SIMPLEGAUSS_SIMPLECPUAPI_H


#include "IComputationAPI.h"

class SimpleCPUAPI: public IComputationAPI<SimpleCPUAPI> {
    friend class IComputationAPI<SimpleCPUAPI>;

    inline bool setupImpl()
    {
        return true;
    }
    inline bool finalizeImpl()
    {
        return true;
    }
    static inline std::string APINameImpl()
    {
        return "Simple CPU API";
    }
};


#endif //SIMPLEGAUSS_SIMPLECPUAPI_H

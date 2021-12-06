//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLECPUAPI_H
#define SIMPLEGAUSS_SIMPLECPUAPI_H


#include "IComputationAPI.h"

class SimpleCPUAPI: public IComputationAPI<SimpleCPUAPI> {
    friend class IComputationAPI<SimpleCPUAPI>;

public:
    bool _setuped;

    inline bool setup(Device& device)
    {
        _setuped = device == Device::CPU;
        return _setuped;
    }
    inline bool finalize()
    {
        return true;
    }
};


#endif //SIMPLEGAUSS_SIMPLECPUAPI_H

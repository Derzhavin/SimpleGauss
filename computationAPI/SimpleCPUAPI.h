//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_SIMPLECPUAPI_H
#define SIMPLEGAUSS_SIMPLECPUAPI_H


#include "IComputationAPI.h"

class SimpleCPUAPI: public IComputationAPI<SimpleCPUAPI> {
    friend class IComputationAPI<SimpleCPUAPI>;

    inline bool setupImpl(Device &device, unsigned short deviceId)
    {
        _deviceId = deviceId;
        _device = device;

        return deviceId == 0 && device == Device::CPU;
    }
    inline bool finalizeImpl()
    {
        return true;
    }
    static inline std::string APINameImpl()
    {
        return "SimpleCPUAPI";
    }
};


#endif //SIMPLEGAUSS_SIMPLECPUAPI_H

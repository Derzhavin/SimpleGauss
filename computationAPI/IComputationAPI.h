//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_ICOMPUTATIONAPI_H
#define SIMPLEGAUSS_ICOMPUTATIONAPI_H

#include <string>

enum class Device
{
    CPU,
    GPU
};

template<class ComputationAPIImpl>
class IComputationAPI {
protected:
    unsigned short _deviceId;
    Device _device;

public:
    inline bool setup(Device &device, unsigned short deviceId)
    {
        return impl()->setupImpl(device, 0);
    }
    inline bool finalize()
    {
        return impl()->finalizeImpl();
    }
    static inline std::string APIName()
    {
        return std::move(ComputationAPIImpl::APINameImpl());
    }
private:
    inline ComputationAPIImpl* impl()
    {
        return static_cast<ComputationAPIImpl*>(this);
    }
};



#endif //SIMPLEGAUSS_ICOMPUTATIONAPI_H

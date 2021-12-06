//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_ICOMPUTATIONAPI_H
#define SIMPLEGAUSS_ICOMPUTATIONAPI_H

enum class Device
{
    CPU,
    GPU
};

template<class ComputationAPIImpl>
class IComputationAPI {
public:
    inline bool setup(Device& device)
    {
        return static_cast<ComputationAPIImpl*>(this)->setup(device);
    }
    inline bool finalize()
    {
        return static_cast<ComputationAPIImpl*>(this)->finalize();
    }
};



#endif //SIMPLEGAUSS_ICOMPUTATIONAPI_H

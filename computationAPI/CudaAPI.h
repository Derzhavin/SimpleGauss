//
// Created by denis on 07.12.2021.
//

#ifndef SIMPLEGAUSS_CUDAAPI_H
#define SIMPLEGAUSS_CUDAAPI_H

#include "IComputationAPI.h"

#include <cuda_runtime.h>

class CudaAPI: public IComputationAPI<CudaAPI> {
    friend class IComputationAPI<CudaAPI>;

    inline bool setupImpl()
    {
        int deviceCount = 0;
        return cudaGetDeviceCount(&deviceCount) == cudaSuccess && deviceCount > 0;
    }
    inline bool finalizeImpl()
    {
        return true;
    }
    static inline std::string APINameImpl()
    {
        return "CUDA API";
    }
};


#endif //SIMPLEGAUSS_CUDAAPI_H

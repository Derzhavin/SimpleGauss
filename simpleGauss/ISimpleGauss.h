//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_ISIMPLEGAUSS_H
#define SIMPLEGAUSS_ISIMPLEGAUSS_H

#include "computationAPI/IComputationAPI.h"
#include "matrix/BasicMat.h"


template<class SimpleGaussImpl, class IMat, class ComputationAPIImpl>
class ISimpleGauss {
    ComputationAPIImpl computationApi;
public:
    explicit ISimpleGauss(Device device=Device::CPU)
    {
        computationApi.setup(device);
    }
    inline IMat& solve(IMat& mat, IMat& matSolution)
    {
        return static_cast<SimpleGaussImpl*>(this)->solve(mat, matSolution);
    }
    ~ISimpleGauss()
    {
        computationApi.finalize();
    }
};


#endif //SIMPLEGAUSS_ISIMPLEGAUSS_H

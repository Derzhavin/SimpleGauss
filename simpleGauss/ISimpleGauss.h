//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_ISIMPLEGAUSS_H
#define SIMPLEGAUSS_ISIMPLEGAUSS_H

#include "computationAPI//IComputationAPI.h"
#include "matrix/IMat.h"


template<class SimpleGaussImpl, class IMat, class ComputationAPIImpl>
class ISimpleGauss {
    ComputationAPIImpl computationApi;
public:
    ISimpleGauss(Device device=Device::CPU)
    {
        computationApi.setup(device);
    }
    inline IMat& solve(IMat& mat, IMat& matSolution)
    {
        return static_cast<SimpleGaussImpl*>(this)->solve(mat, matSolution);
    }
    virtual ~ISimpleGauss()
    {
        computationApi.finalize();
    }
};


#endif //SIMPLEGAUSS_ISIMPLEGAUSS_H

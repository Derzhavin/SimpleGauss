//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_ISIMPLEGAUSS_H
#define SIMPLEGAUSS_ISIMPLEGAUSS_H

#include "computationAPI/IComputationAPI.h"
#include "matrix/IMat.h"


template<class SimpleGaussImpl, class IMat, class ComputationAPIImpl>
class ISimpleGauss {
    using ApiBase = IComputationAPI<ComputationAPIImpl>;
    ComputationAPIImpl computationApi;
public:
    explicit ISimpleGauss(Device device=Device::CPU)
    {
        computationApi.ApiBase::setup(device);
    }
    inline IMat& solve(IMat& mat, IMat& matSolution)
    {
        return static_cast<SimpleGaussImpl*>(this)->solve(mat, matSolution);
    }
    ~ISimpleGauss()
    {
        computationApi.ApiBase::finalize();
    }
};


#endif //SIMPLEGAUSS_ISIMPLEGAUSS_H

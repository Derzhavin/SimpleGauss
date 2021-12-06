//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_ISIMPLEGAUSS_H
#define SIMPLEGAUSS_ISIMPLEGAUSS_H

#include "computationAPI/IComputationAPI.h"
#include "matrix/BaseMat.h"


template<class SimpleGaussImpl, class MatImpl, typename MatT, class ComputationAPIImpl>
class ISimpleGauss {
    ComputationAPIImpl computationApi;
public:
    explicit ISimpleGauss(Device device=Device::CPU)
    {
        computationApi.setup(device);
    }
    inline MatImpl& solve(BaseMat<MatImpl, MatT>& mat)
    {
        return static_cast<SimpleGaussImpl*>(this)->solve(mat);
    }
    ~ISimpleGauss()
    {
        computationApi.finalize();
    }
};


#endif //SIMPLEGAUSS_ISIMPLEGAUSS_H

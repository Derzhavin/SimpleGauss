//
// Created by denis on 06.12.2021.
//

#ifndef SIMPLEGAUSS_ISIMPLEGAUSS_H
#define SIMPLEGAUSS_ISIMPLEGAUSS_H

#include "computationAPI/IComputationAPI.h"
#include "matrix/BaseMat.h"


template<class SimpleGaussImpl, class MatImpl, typename MatT, class IComputationAPI>
class ISimpleGauss {
    bool _warnings;
    IComputationAPI iComputationApi;

public:
    explicit ISimpleGauss(bool warnings= false)
    {
        iComputationApi.setup();
        _warnings = warnings;
    }
    ~ISimpleGauss()
    {
        finalizeComputationAPI();
    }
    inline MatImpl solve(BaseMat<MatImpl, MatT>& mat)
    {
        if (iComputationApi.setuped())
            return impl()->solveImpl(mat);
        else if (_warnings)
        {
            std::cout   << "WARNING: " << IComputationAPI::APIName() << " did not run solve SimpleGauss because "
                        << IComputationAPI::APIName() << " was not setuped" << std::endl;
        }
        return std::move(MatImpl());
    }

    inline bool finalizeComputationAPI()
    {
        if (iComputationApi.setuped()) {
            if (!iComputationApi.finalize())
            {
                if (_warnings)
                    std::cout << "WARNING: " << IComputationAPI::APIName() << " was not finalized successfully" << std::endl;
                return false;
            }
            return true;
        }
        else if (_warnings)
            std::cout << "WARNING: " << IComputationAPI::APIName() << " was not finalized because it was not setuped" << std::endl;
        return false;
    }
private:
    SimpleGaussImpl* impl()
    {
        return static_cast<SimpleGaussImpl*>(this);
    }
};


#endif //SIMPLEGAUSS_ISIMPLEGAUSS_H

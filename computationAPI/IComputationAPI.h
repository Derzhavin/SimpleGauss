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
    bool _setuped;
    bool _finalized;
public:
    IComputationAPI(): _setuped(false), _finalized(false)
    {
        setup();
    }
    inline bool setup()
    {
        _setuped = impl()->setupImpl();
        _finalized = false;
        return _setuped;
    }
    inline bool finalize()
    {
        _finalized = impl()->finalizeImpl();
        _setuped = false;
        return _finalized;
    }
    static inline std::string APIName()
    {
        return std::move(ComputationAPIImpl::APINameImpl());
    }
    ~IComputationAPI()
    {
        finalize();
    }
    bool setuped() const
    {
        return _setuped;
    }
    bool finalized() const
    {
        return _finalized;
    }
private:
    inline ComputationAPIImpl* impl()
    {
        return static_cast<ComputationAPIImpl*>(this);
    }
};



#endif //SIMPLEGAUSS_ICOMPUTATIONAPI_H

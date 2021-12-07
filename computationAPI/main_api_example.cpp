//
// Created by denis on 07.12.2021.
//

#include "CudaAPI.h"
#include "SimpleCPUAPI.h"

int main()
{
    SimpleCPUAPI cpuApi;
    cpuApi.setup();

    CudaAPI cudaApi;
    cudaApi.setup();
}
#include <iostream>
#include <cuda_runtime.h>

__global__ void myKernel(int* data) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    data[idx] *= 2; // Example kernel operation
}

int main() {
    const int dataSize = 1024;
    int h_data[dataSize]; // Host data array
    int *d_data; // Device data array

    // Allocate GPU memory
    cudaMalloc((void**)&d_data, dataSize * sizeof(int));

    // Initialize host data
    for (int i = 0; i < dataSize; ++i) {
        h_data[i] = i;
    }

    // Copy data to GPU
    cudaMemcpy(d_data, h_data, dataSize * sizeof(int), cudaMemcpyHostToDevice);

    // Launch kernel
    myKernel<<<1, dataSize>>>(d_data);

    // Copy results back to host
    cudaMemcpy(h_data, d_data, dataSize * sizeof(int), cudaMemcpyDeviceToHost);

    // Print results
    for (int i = 0; i < 10; ++i) {
        std::cout << h_data[i] << " ";
    }

    // Free GPU memory
    cudaFree(d_data);

    return 0;
}

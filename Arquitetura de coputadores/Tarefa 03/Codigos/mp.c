#include <iostream>
#include <cuda_runtime.h>

const int matrixSizes[] = { 100, 200, 300, 400, 500 };  // Tamanhos das matrizes

__global__ void matrixMultiplicationKernel(const int* A, const int* B, int* result, int matrixSize) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < matrixSize && col < matrixSize) {
        int value = 0;
        for (int k = 0; k < matrixSize; ++k) {
            value += A[row * matrixSize + k] * B[k * matrixSize + col];
        }
        result[row * matrixSize + col] = value;
    }
}

void matrixMultiplicationParallel(const int matrixSize, const int numThreads) {
    // Matrizes na CPU
    int* hostMatrixA = new int[matrixSize * matrixSize];
    int* hostMatrixB = new int[matrixSize * matrixSize];
    int* hostResultMatrix = new int[matrixSize * matrixSize];

    // Preencheendo as matrizes
    for (int i = 0; i < matrixSize * matrixSize; ++i) {
        hostMatrixA[i] = i;
        hostMatrixB[i] = i;
    }

    // Matrizes na GPU
    int* deviceMatrixA, * deviceMatrixB, * deviceResultMatrix;
    cudaMalloc((void**)&deviceMatrixA, matrixSize * matrixSize * sizeof(int));
    cudaMalloc((void**)&deviceMatrixB, matrixSize * matrixSize * sizeof(int));
    cudaMalloc((void**)&deviceResultMatrix, matrixSize * matrixSize * sizeof(int));

    // Transferir dados para a GPU
    cudaMemcpy(deviceMatrixA, hostMatrixA, matrixSize * matrixSize * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(deviceMatrixB, hostMatrixB, matrixSize * matrixSize * sizeof(int), cudaMemcpyHostToDevice);

    // Configurar grade e blocos
    dim3 blockDim(numThreads, numThreads);
    dim3 gridDim((matrixSize + blockDim.x - 1) / blockDim.x, (matrixSize + blockDim.y - 1) / blockDim.y);

    // Criar eventos CUDA para medir o tempo de execução
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // Registrar o início do tempo de execução
    cudaEventRecord(start);

    // Executar o kernel na GPU para multiplicar as matrizes
    matrixMultiplicationKernel << <gridDim, blockDim >> > (deviceMatrixA, deviceMatrixB, deviceResultMatrix, matrixSize);

    // Aguardar a conclusão do kernel
    cudaDeviceSynchronize();

    // Registrar o fim do tempo de execução
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);

    // Calcular o tempo de execução em milissegundos
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);

    std::cout << "Threads: " << numThreads << " , tempo de execucao: " << milliseconds << " ms" << std::endl;

    delete[] hostMatrixA;
    delete[] hostMatrixB;
    delete[] hostResultMatrix;
    cudaFree(deviceMatrixA);
    cudaFree(deviceMatrixB);
    cudaFree(deviceResultMatrix);
}

int main() {
    // Diferentes números de threads por bloco
    const int numThreads[] = { 1, 2, 4, 8, 16, 32 };
    for (int i = 0; i < sizeof(matrixSizes) / sizeof(matrixSizes[0]); ++i) {
        std::cout << "Tamanho da Matriz " << matrixSizes[i] << " x " << matrixSizes[i] << ":" << std::endl;
        for (int j = 0; j < sizeof(numThreads) / sizeof(numThreads[0]); ++j) {
            matrixMultiplicationParallel(matrixSizes[i], numThreads[j]);
        }
        std::cout << "--------------------------------------------------------" << std::endl;
    }

    return 0;
}

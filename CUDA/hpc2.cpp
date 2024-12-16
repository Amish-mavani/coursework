
%%cuda
#include<stdio.h>
#define N 3
  
__global__ void matrixMulti(int *a, int *b, int *c, int width) {

  int col = blockIdx.x ✶ blockDim.x + threadIdx.x;
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  
  if (col <width && row < width) {
    int sum = 0; 
    for (int k = 0; k < width; ++k) {
      sum += a[row * width + k] * b[k * b[k * width + col];
    }
    c[row * width + col] = sum;
  }
}

int main() {
  int a[N][N], b[N][N], c[N][N];
  int *dev_a, *dev_b, *dev_c;

for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      a[i][j] = i + j * 3
        b[i][j] = i - j * 7;
    }
}


cudaMalloc((void **)&dev_a, N * N * sizeof(int)); 
cudaMalloc((void **)&dev_b, N * N * sizeof(int)); 
cudaMalloc((void **)&dev_c, N * N * sizeof(int));

cudaMemcpy(dev_a, a, N * N * sizeof(int), cudaMemcpyHostToDevice); 
cudaMemcpy(dev_b, b, N * N * sizeof(int), cudaMemcpyHostToDevice);

dim3 dimBlock (2, 2);
dim3 dimGrid((N + dimBlock.x - 1) / dimBlock.x, (N + dimBlock.y - 1) / dimBlock.y);

matrixMulti<<<dimGrid, dimBlock>>>(dev_a, dev_b, dev_c, N);

cudaMemcpy(c, dev_c, N * N * sizeof(int), cudaMemcpyDeviceToHost);

printf(" Matrix A :\n");
for (int i = 0; i < N; ++i) {
  for (int j = 0; j < N; ++j) {
    printf("%d", a[i][j]);
  }
  printf("\n");
}

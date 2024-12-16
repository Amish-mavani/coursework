#include &lt;iostream&gt;
#include &lt;cmath&gt;
#include &lt;cstdlib&gt;
#include &lt;omp.h&gt;

int main() {
int np = 1000000;
int count = 0;
srand(time(NULL));
#pragma omp parallel for reduction(+: count)
for (int i = 0; i &lt; np; ++i) {
double x = (double)rand() / RAND_MAX;
double y = (double)rand() / RAND_MAX;
if (std::sqrt(x * x + y * y) &lt;= 1) {
count++;
}
}

double q = (double)count / np;
double pi = 4 * q;
std::cout &lt;&lt; &quot;Estimated value of π: &quot; &lt;&lt; pi &lt;&lt; std::endl;
return 0;
}

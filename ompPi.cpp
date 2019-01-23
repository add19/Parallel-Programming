#include<bits/stdc++.h>
#include<omp.h>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    int i, count;           //count is number of points to be inside the quarter cricle
    unsigned short xi[3];   //seed for random number
    int samples;            //samples number of points to generate
    
    double x, y;            //point coordinates generated randomly
    double pi;

    samples = atoi(argv[1]);//enter the number of samples to be generated via command line arguements

    #pragma omp parallel
    {
        xi[0] = 1;          
        xi[1] = 1;
        xi[2] = omp_get_thread_num();
        count = 0;
        //firstprivate directive is used to initialize a private local variable for 
        //each thread with a value assigned in master thread

        //reduction is used to combine local copies of a variable in different threads
        //into a single copy at the master thread when threads exits
        #pragma omp parallel for firstprivate(xi) private (x, y) reduction(+:count)
        for(i=0; i<samples; i++){
            x = erand48(xi);
            y = erand48(xi);

            if(x*x + y*y <= 1.0)
                count++;
        }
    }

    pi = 4.0 * count / samples;
    
    cout.precision(5);
    cout << "Count = " << count << ", Samples = " << samples << ", Estimate of pi: " << pi << endl;
    return 0;
}

#include "stat.h"
#include "calculation.h"
#include <limits.h>
#include <math.h>


int * variance_1_svc(data * dp, struct svc_req * rqstp){
    int *p;
    u_int len;
    static int variance;

    p = dp->data.data_val;
    len = dp->data.data_len;

    variance = (int)findVariance(p,len);
    return (&variance);

}

int * average_1_svc(data *dp, struct svc_req *rqstp) {
    int *p;
    u_int len;
    static int average;

    p = dp->data.data_val;
    len = dp->data.data_len;
    double mean = findMean(p, len);
    average = (int) mean;
    return (&average);
}

int * stddev_1_svc(data *dp, struct svc_req *rqstp){
    int *p;
    u_int len;
    static int stddev;

    p = dp->data.data_val;
    len = dp->data.data_len;
    int variance = (int)findVariance(p, len);
    stddev = (int)sqrt(variance);
    return (&stddev);
}

int * maximum_1_svc(data *dp, struct svc_req *rqstp) {
    static int max = INT_MIN;
    int i;
    int *p;
    u_int len;

    p = dp->data.data_val;
    len = dp->data.data_len;

    for (i = 0; i < len; i++) {
        if (p[i] > max)
            max = p[i];
    }
    return (&max);

}

int * minimum_1_svc(data *dp, struct svc_req *rqstp) {
    static int min = INT_MAX;
    int i;
    int *p;
    u_int len;

    p = dp->data.data_val;
    len = dp->data.data_len;

    for (i = 0; i < len; i++) {
        if (p[i] < min)
            min = p[i];
    }
    return (&min);

}

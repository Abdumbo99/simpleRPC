
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>

int r;


int main (int argc, char *argv[])
{
    char *host;
    CLIENT *clnt;
    int  *resp;
    data d;
    int datalen;
    int *ip;
    int x;
    int i;

    if (argc < 3) {
        printf("usage: %s host value ...\n", argv[0]);
        exit(1);
    }

    if (argc > MAXDATALEN + 2) {
        printf("Too many input values\n");
        exit(1);
    }

    host = argv[1];

    d.data.data_val = (int *)malloc(MAXDATALEN*sizeof(int));
    ip = d.data.data_val;
    datalen = (argc - 2);
    d.data.data_len = datalen;
    printf ("datalength=%d\n", datalen);

    for (i = 0; i < datalen; ++i) {
        x = atoi(argv[i+2]);
        *ip = x;
        printf ("data=%d\n", *ip);
        ip++;
    }

    clnt = clnt_create(host, STATPROG,
                       STATVERS, "tcp");

    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }
    printf("connected to the server\n");

    resp = variance_1(&d, clnt);;  // calling the remote procedure
    if (resp == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }
    r = *resp;
    printf("variance Result = %d\n", r);


    resp = average_1(&d, clnt);;  // calling the remote procedure
    if (resp == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }
    r = *resp;
    printf("average Result = %d\n", r);


    resp = stddev_1(&d, clnt);;  // calling the remote procedure
    if (resp == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }
    r = *resp;
    printf("stddev Result = %d\n", r);

    resp = maximum_1(&d, clnt);;  // calling the remote procedure
    if (resp == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }
    r = *resp;
    printf("maximum Result = %d\n", r);

    resp = minimum_1(&d, clnt);;  // calling the remote procedure
    if (resp == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }
    r = *resp;

    printf("minimum Result = %d\n", r);

    clnt_destroy (clnt);

    return (1);
}

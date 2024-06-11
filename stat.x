
const MAXDATALEN  = 200;

struct data {
  int data<MAXDATALEN>;
};

typedef struct data data;

program STATPROG {
	version STATVERS {
		int VARIANCE(data) = 1;
        int AVERAGE(data) = 2;
        int STDDEV(data) = 3;
        int MAXIMUM(data) = 4;
        int MINIMUM(data) = 5;
	} = 1;
} = 21678;
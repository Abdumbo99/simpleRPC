all: server client

server: server.c stat_svc.c stat.h calculation.h
	gcc -Wall -c server.c
	gcc -Wall -c stat_svc.c
	gcc -Wall -c stat_xdr.c
	gcc -o server server.o -lm stat_svc.o stat_xdr.o


client: client.c stat_clnt.c stat.h
	gcc -Wall -c client.c
	gcc -Wall -c stat_clnt.c
	gcc -Wall -c stat_xdr.c
	gcc -o client client.o stat_clnt.o stat_xdr.o

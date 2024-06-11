/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
statprog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		data variance_1_arg;
		data average_1_arg;
		data stddev_1_arg;
		data maximum_1_arg;
		data minimum_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case VARIANCE:
		_xdr_argument = (xdrproc_t) xdr_data;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) variance_1_svc;
		break;

	case AVERAGE:
		_xdr_argument = (xdrproc_t) xdr_data;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) average_1_svc;
		break;

	case STDDEV:
		_xdr_argument = (xdrproc_t) xdr_data;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) stddev_1_svc;
		break;

	case MAXIMUM:
		_xdr_argument = (xdrproc_t) xdr_data;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) maximum_1_svc;
		break;

	case MINIMUM:
		_xdr_argument = (xdrproc_t) xdr_data;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) minimum_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (STATPROG, STATVERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, STATPROG, STATVERS, statprog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (STATPROG, STATVERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, STATPROG, STATVERS, statprog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (STATPROG, STATVERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}

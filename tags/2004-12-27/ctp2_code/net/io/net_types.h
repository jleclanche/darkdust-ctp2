


#pragma once
#ifndef _NET_TYPES_H_
#define _NET_TYPES_H_

enum NET_ERR {
	NET_ERR_OK,
	NET_ERR_INVALIDADDR,
	NET_ERR_INVALIDPORT,
	NET_ERR_CONNCLOSED,
	NET_ERR_NODATA,
	NET_ERR_WRITEERR,
	NET_ERR_NOTIMPLEMENTED,
	NET_ERR_TRANSPORTERROR,
	NET_ERR_ALREADYOPEN,
	NET_ERR_NOMORESESSIONS,
	NET_ERR_NOTSTARTED,
	NET_ERR_BADTRANSPORT,
	NET_ERR_WOULDBLOCK,
	NET_ERR_INVALIDSESSION,
	NET_ERR_NO_TRANSPORTS,
	NET_ERR_TOO_LARGE,
	NET_ERR_UNKNOWN,
};

#endif
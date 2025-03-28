/*
 * \brief  Server-side Uplink session interface
 * \author Martin Stein
 * \date   2020-11-30
 */

/*
 * Copyright (C) 2020 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#ifndef _UPLINK_SESSION__RPC_OBJECT_H_
#define _UPLINK_SESSION__RPC_OBJECT_H_

/* Genode includes */
#include <uplink_session/uplink_session.h>
#include <packet_stream_tx/rpc_object.h>
#include <packet_stream_rx/rpc_object.h>

namespace Uplink { class Session_rpc_object; }


class Uplink::Session_rpc_object : public Genode::Rpc_object<Session, Session_rpc_object>
{
	protected:

		Packet_stream_tx::Rpc_object<Tx> _tx;
		Packet_stream_rx::Rpc_object<Rx> _rx;

	public:

		/**
		 * Constructor
		 *
		 * \param tx_ds            dataspace used as communication buffer
		 *                         for the tx packet stream
		 * \param rx_ds            dataspace used as communication buffer
		 *                         for the rx packet stream
		 * \param rx_buffer_alloc  allocator used for managing the communication
		 *                         buffer of the rx packet stream
		 * \param ep               entry point used for packet-stream channels
		 */
		Session_rpc_object(Genode::Region_map           &rm,
		                   Genode::Dataspace_capability  tx_ds,
		                   Genode::Dataspace_capability  rx_ds,
		                   Genode::Range_allocator      *rx_buffer_alloc,
		                   Genode::Rpc_entrypoint       &ep)
		:
			_tx(tx_ds, rm, ep),
			_rx(rx_ds, rm, *rx_buffer_alloc, ep)
		{ }

		Genode::Capability<Tx> _tx_cap() { return _tx.cap(); }
		Genode::Capability<Rx> _rx_cap() { return _rx.cap(); }
};

#endif /* _UPLINK_SESSION__RPC_OBJECT_H_ */

/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
/*
 * Copyright (c) 2012-2021, The Linux Foundation. All rights reserved.
 *
 * Copyright (c) 2022-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _MSM_IPA_H_
#define _MSM_IPA_H_

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/stat.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/if_ether.h>

/**
 * unique magic number of the IPA device
 */
#define IPA_IOC_MAGIC 0xCF

/**
 * IPA device full path
 */
#define IPA_DEV_NAME "/dev/ipa"

/**
 * IPA NAT table character device name
 */
#define IPA_NAT_DEV_NAME "ipaNatTable"

/**
 * IPA IPv6CT table character device name
 */
#define IPA_IPV6CT_DEV_NAME "ipaIpv6CTTable"

/**
 * name of the default routing tables for v4 and v6
 */
#define IPA_DFLT_RT_TBL_NAME "ipa_dflt_rt"

/**
 * name for default value of invalid protocol of NAT
 */
#define IPAHAL_NAT_INVALID_PROTOCOL   0xFF

#define IPA_ETH_API_VER 2

/**
 * commands supported by IPA driver
 */
#define IPA_IOCTL_ADD_HDR                       0
#define IPA_IOCTL_DEL_HDR                       1
#define IPA_IOCTL_ADD_RT_RULE                   2
#define IPA_IOCTL_DEL_RT_RULE                   3
#define IPA_IOCTL_ADD_FLT_RULE                  4
#define IPA_IOCTL_DEL_FLT_RULE                  5
#define IPA_IOCTL_COMMIT_HDR                    6
#define IPA_IOCTL_RESET_HDR                     7
#define IPA_IOCTL_COMMIT_RT                     8
#define IPA_IOCTL_RESET_RT                      9
#define IPA_IOCTL_COMMIT_FLT                    10
#define IPA_IOCTL_RESET_FLT                     11
#define IPA_IOCTL_DUMP                          12
#define IPA_IOCTL_GET_RT_TBL                    13
#define IPA_IOCTL_PUT_RT_TBL                    14
#define IPA_IOCTL_COPY_HDR                      15
#define IPA_IOCTL_QUERY_INTF                    16
#define IPA_IOCTL_QUERY_INTF_TX_PROPS           17
#define IPA_IOCTL_QUERY_INTF_RX_PROPS           18
#define IPA_IOCTL_GET_HDR                       19
#define IPA_IOCTL_PUT_HDR                       20
#define IPA_IOCTL_SET_FLT                       21
#define IPA_IOCTL_ALLOC_NAT_MEM                 22
#define IPA_IOCTL_V4_INIT_NAT                   23
#define IPA_IOCTL_TABLE_DMA_CMD                 24
#define IPA_IOCTL_NAT_DMA                       IPA_IOCTL_TABLE_DMA_CMD
#define IPA_IOCTL_INIT_IPV6CT_TABLE             25
#define IPA_IOCTL_V4_DEL_NAT                    26
#define IPA_IOCTL_PULL_MSG                      27
#define IPA_IOCTL_GET_NAT_OFFSET                28
#define IPA_IOCTL_RM_ADD_DEPENDENCY             29
#define IPA_IOCTL_RM_DEL_DEPENDENCY             30
#define IPA_IOCTL_GENERATE_FLT_EQ               31
#define IPA_IOCTL_QUERY_INTF_EXT_PROPS          32
#define IPA_IOCTL_QUERY_EP_MAPPING              33
#define IPA_IOCTL_QUERY_RT_TBL_INDEX            34
#define IPA_IOCTL_WRITE_QMAPID                  35
#define IPA_IOCTL_MDFY_FLT_RULE                 36
#define IPA_IOCTL_NOTIFY_WAN_UPSTREAM_ROUTE_ADD 37
#define IPA_IOCTL_NOTIFY_WAN_UPSTREAM_ROUTE_DEL 38
#define IPA_IOCTL_NOTIFY_WAN_EMBMS_CONNECTED    39
#define IPA_IOCTL_ADD_HDR_PROC_CTX              40
#define IPA_IOCTL_DEL_HDR_PROC_CTX              41
#define IPA_IOCTL_MDFY_RT_RULE                  42
#define IPA_IOCTL_ADD_RT_RULE_AFTER             43
#define IPA_IOCTL_ADD_FLT_RULE_AFTER            44
#define IPA_IOCTL_GET_HW_VERSION                45
#define IPA_IOCTL_ADD_RT_RULE_EXT               46
#define IPA_IOCTL_ADD_VLAN_IFACE                47
#define IPA_IOCTL_DEL_VLAN_IFACE                48
#define IPA_IOCTL_ADD_L2TP_VLAN_MAPPING         49
#define IPA_IOCTL_DEL_L2TP_VLAN_MAPPING         50
#define IPA_IOCTL_NAT_MODIFY_PDN                51
#define IPA_IOCTL_ALLOC_NAT_TABLE               52
#define IPA_IOCTL_ALLOC_IPV6CT_TABLE            53
#define IPA_IOCTL_DEL_NAT_TABLE                 54
#define IPA_IOCTL_DEL_IPV6CT_TABLE              55
#define IPA_IOCTL_CLEANUP                       56
#define IPA_IOCTL_QUERY_WLAN_CLIENT             57
#define IPA_IOCTL_GET_VLAN_MODE                 58
#define IPA_IOCTL_ADD_BRIDGE_VLAN_MAPPING       59
#define IPA_IOCTL_DEL_BRIDGE_VLAN_MAPPING       60
#define IPA_IOCTL_ODL_QUERY_ADAPL_EP_INFO       61
#define IPA_IOCTL_ODL_GET_AGG_BYTE_LIMIT        62
#define IPA_IOCTL_ODL_QUERY_MODEM_CONFIG        63
#define IPA_IOCTL_GSB_CONNECT                   64
#define IPA_IOCTL_GSB_DISCONNECT                65
#define IPA_IOCTL_WIGIG_FST_SWITCH              66
#define IPA_IOCTL_ADD_RT_RULE_V2                67
#define IPA_IOCTL_ADD_RT_RULE_EXT_V2            68
#define IPA_IOCTL_ADD_RT_RULE_AFTER_V2          69
#define IPA_IOCTL_MDFY_RT_RULE_V2               70
#define IPA_IOCTL_ADD_FLT_RULE_V2               71
#define IPA_IOCTL_ADD_FLT_RULE_AFTER_V2         72
#define IPA_IOCTL_MDFY_FLT_RULE_V2              73
#define IPA_IOCTL_FNR_COUNTER_ALLOC             74
#define IPA_IOCTL_FNR_COUNTER_DEALLOC           75
#define IPA_IOCTL_FNR_COUNTER_QUERY             76
#define IPA_IOCTL_SET_FNR_COUNTER_INFO          77
#define IPA_IOCTL_GET_NAT_IN_SRAM_INFO          78
#define IPA_IOCTL_APP_CLOCK_VOTE                79
#define IPA_IOCTL_PDN_CONFIG                    80
#define IPA_IOCTL_SET_MAC_FLT                   81
#define IPA_IOCTL_GET_PHERIPHERAL_EP_INFO       82
#define IPA_IOCTL_ADD_UC_ACT_ENTRY              83
#define IPA_IOCTL_DEL_UC_ACT_ENTRY              84
#define IPA_IOCTL_SET_SW_FLT                    85
#define IPA_IOCTL_GET_HW_FEATURE_SUPPORT        86
#define IPA_IOCTL_SET_PKT_THRESHOLD             87
#define IPA_IOCTL_ADD_EoGRE_MAPPING             88
#define IPA_IOCTL_DEL_EoGRE_MAPPING             89
#define IPA_IOCTL_SET_IPPT_SW_FLT               90
#define IPA_IOCTL_FLT_MEM_PERIPHERAL_SET_PRIO_HIGH 91
#define IPA_IOCTL_ADD_MACSEC_MAPPING            92
#define IPA_IOCTL_DEL_MACSEC_MAPPING            93
#define IPA_IOCTL_QUERY_CACHED_DRIVER_MSG       94
#define IPA_IOCTL_SET_EXT_ROUTER_MODE           95
#define IPA_IOCTL_ADD_DEL_DSCP_PCP_MAPPING      96
#define IPA_IOCTL_SEND_VLAN_MUXID_MAPPING       97
#define IPA_IOCTL_SEND_TUNNEL_TEMPLATE_INFO       98
#define IPA_IOCTL_QUERY_TUNNEL_FEATURE       99
/**
 * max size of the header to be inserted
 */
#define IPA_HDR_MAX_SIZE 64

/**
 * max size of the name of the resource (routing table, header)
 */
#define IPA_RESOURCE_NAME_MAX 32

/**
 * max number of interface properties
 */
#define IPA_NUM_PROPS_MAX 35

/**
 * size of the mac address
 */
#define IPA_MAC_ADDR_SIZE  6

/**
 * max number of mbim streams
 */
#define IPA_MBIM_MAX_STREAM_NUM 8

/**
 *  size of the ipv6 address
 */
#define IPA_WAN_MSG_IPv6_ADDR_GW_LEN 4

/**
 * max number of lan clients supported per device type
 * for LAN stats via HW.
 */
#define IPA_MAX_NUM_HW_PATH_CLIENTS 16

/**
 * max number of destination pipes possible for a client.
 */
#define QMI_IPA_MAX_CLIENT_DST_PIPES 4

/**
 * Max number of clients supported for mac based exception
 */

#define IPA_MAX_NUM_MAC_FLT 32
#define IPA_MAX_NUM_IPv4_SEGS_FLT 16
#define IPA_MAX_NUM_IFACE_FLT 4


/**
 * MAX number of the FLT_RT stats counter supported.
 */
#define IPA_MAX_FLT_RT_CNT_INDEX (128)
#define IPA_FLT_RT_HW_COUNTER (120)
#define IPA_FLT_RT_SW_COUNTER \
	(IPA_MAX_FLT_RT_CNT_INDEX - IPA_FLT_RT_HW_COUNTER)
#define IPA_MAX_FLT_RT_CLIENTS 60

/**
 * Max number of ports/IPs IPPT exception
 */

#define IPA_MAX_IPPT_NUM_PORT_FLT 5

/**
 * Max number of DSCP entries in uc
 */
#define IPA_UC_MAX_DSCP_VAL 64

/**
 * New feature flag for CV2X config.
 */

#define IPA_CV2X_SUPPORT

/**
 *  Max number of delegated IDUs for prefix delegation FR
 */
#define IPA_PREFIX_MAPPING_MAX 16

/**
 * the attributes of the rule (routing or filtering)
 */
#define IPA_FLT_TOS			(1ul << 0)
#define IPA_FLT_PROTOCOL		(1ul << 1)
#define IPA_FLT_SRC_ADDR		(1ul << 2)
#define IPA_FLT_DST_ADDR		(1ul << 3)
#define IPA_FLT_SRC_PORT_RANGE		(1ul << 4)
#define IPA_FLT_DST_PORT_RANGE		(1ul << 5)
#define IPA_FLT_TYPE			(1ul << 6)
#define IPA_FLT_CODE			(1ul << 7)
#define IPA_FLT_SPI			(1ul << 8)
#define IPA_FLT_SRC_PORT		(1ul << 9)
#define IPA_FLT_DST_PORT		(1ul << 10)
#define IPA_FLT_TC			(1ul << 11)
#define IPA_FLT_FLOW_LABEL		(1ul << 12)
#define IPA_FLT_NEXT_HDR		(1ul << 13)
#define IPA_FLT_META_DATA		(1ul << 14)
#define IPA_FLT_FRAGMENT		(1ul << 15)
#define IPA_FLT_TOS_MASKED		(1ul << 16)
#define IPA_FLT_MAC_SRC_ADDR_ETHER_II	(1ul << 17)
#define IPA_FLT_MAC_DST_ADDR_ETHER_II	(1ul << 18)
#define IPA_FLT_MAC_SRC_ADDR_802_3	(1ul << 19)
#define IPA_FLT_MAC_DST_ADDR_802_3	(1ul << 20)
#define IPA_FLT_MAC_ETHER_TYPE		(1ul << 21)
#define IPA_FLT_MAC_DST_ADDR_L2TP	(1ul << 22)
#define IPA_FLT_TCP_SYN			(1ul << 23)
#define IPA_FLT_TCP_SYN_L2TP		(1ul << 24)
#define IPA_FLT_L2TP_INNER_IP_TYPE	(1ul << 25)
#define IPA_FLT_L2TP_INNER_IPV4_DST_ADDR (1ul << 26)
#define IPA_FLT_IS_PURE_ACK		(1ul << 27)
#define IPA_FLT_VLAN_ID			(1ul << 28)
#define IPA_FLT_MAC_SRC_ADDR_802_1Q	(1ul << 29)
#define IPA_FLT_MAC_DST_ADDR_802_1Q	(1ul << 30)
#define IPA_FLT_L2TP_UDP_INNER_MAC_DST_ADDR (1ul << 31)

/* Extended attributes for the rule (routing or filtering) */
#define IPA_FLT_EXT_L2TP_UDP_TCP_SYN          (1ul << 0)
#define IPA_FLT_EXT_L2TP_UDP_INNER_ETHER_TYPE (1ul << 1)
#define IPA_FLT_EXT_MTU                       (1ul << 2)
#define IPA_FLT_EXT_L2TP_UDP_INNER_NEXT_HDR   (1ul << 3)
#define IPA_FLT_EXT_NEXT_HDR                  (1ul << 4)
/* ip protocol/udp ports/eth-type */
#define IPA_FLT_EXT_MPLS_GRE_GENERAL          (1ul << 5)

/**
 * maximal number of NAT PDNs in the PDN config table
 */
#define IPA_MAX_PDN_NUM 16
#define IPA_MAX_PDN_NUM_v4 5

/**
 * Macros duplicated from ipa_lnx_spearhead_stats.h and
 * ipa_lnx_stats.h. All three macros should match.
 * This needs to be updated whenever the header file structure
 * and structure length macros are updated to match exactly
 * the same. This is done to overcome backward and forward
 * compatibility between userspace and driver spearhead structures.
 */
/* IPA Linux basic stats structure macros */
#define IPA_LNX_PG_RECYCLE_STATS_STRUCT_LEN 32
#define IPA_LNX_EXCEPTION_STATS_STRUCT_LEN 40
#define IPA_LNX_ODL_EP_STATS_STRUCT_LEN 16
#define IPA_LNX_HOLB_DISCARD_STATS_STRUCT_LEN 16
#define IPA_LNX_HOLB_MONITOR_STATS_STRUCT_LEN 16
#define IPA_LNX_HOLB_DROP_AND_MON_STATS_STRUCT_LEN (8 + 16 + 16)
#define IPA_LNX_GENERIC_STATS_STRUCT_LEN (40 + 32 + 40 + 16 + 40)
/* IPA Linux clock stats structures */
#define IPA_LNX_PM_CLIENT_STATS_STRUCT_LEN 24
#define IPA_LNX_CLOCK_STATS_STRUCT_LEN (24 + 24)
/* Generic instance structures */
#define IPA_LNX_GSI_RX_DEBUG_STATS_STRUCT_LEN 48
#define IPA_LNX_GSI_TX_DEBUG_STATS_STRUCT_LEN 56
#define IPA_LNX_GSI_DEBUG_STATS_STRUCT_LEN (8 + 48 + 56)
#define IPA_LNX_PIPE_INFO_STATS_STRUCT_LEN 120
/* IPA Linux wlan instance stats structures */
#define IPA_LNX_WLAN_INSTANCE_INFO_STRUCT_LEN (32 + 112 + 120)
#define IPA_LNX_WLAN_INST_STATS_STRUCT_LEN (8 + 264)
/* IPA Linux eth instance stats structures */
#define IPA_LNX_ETH_INSTANCE_INFO_STRUCT_LEN (16 + 112 + 120)
#define IPA_LNX_ETH_INST_STATS_STRUCT_LEN (8 + 248)
/* IPA Linux usb instance stats structures */
#define IPA_LNX_USB_INSTANCE_INFO_STRUCT_LEN (16 + 112 + 120)
#define IPA_LNX_USB_INST_STATS_STRUCT_LEN (8 + 248)
/* IPA Linux mhip instance stats structures */
#define IPA_LNX_MHIP_INSTANCE_INFO_STRUCT_LEN (16 + 112 + 120)
#define IPA_LNX_MHIP_INST_STATS_STRUCT_LEN (8 + 248)
/* IPA Linux consolidated stats structure */
#define IPA_LNX_CONSOLIDATED_STATS_STRUCT_LEN (8 + 48)
/* IPA Linux Instance allocation info structures */
#define IPA_LNX_EACH_INST_ALLOC_INFO_STRUCT_LEN (24 + 12 + 12 + 16)
#define IPA_LNX_STATS_ALL_INFO_STRUCT_LEN (32 + 128 + 128 + 128)
#define IPA_LNX_STATS_SPEARHEAD_CTX_STRUCT_LEN (8 + 4 + 416)

/**
 * enum ipa_client_type - names for the various IPA "clients"
 * these are from the perspective of the clients, for e.g.
 * HSIC1_PROD means HSIC client is the producer and IPA is the
 * consumer.
 * PROD clients are always even, and CONS clients are always odd.
 * Add new clients in the end of the list or replace reserved one,
 * update IPA_CLIENT_MAX and update the strings array ipa_clients_strings[]
 * while keeping the ordering of the clients the same
 */
enum ipa_client_type {
	IPA_CLIENT_HSIC1_PROD			= 0,
	IPA_CLIENT_HSIC1_CONS			= 1,

	IPA_CLIENT_HSIC2_PROD			= 2,
	IPA_CLIENT_HSIC2_CONS			= 3,

	IPA_CLIENT_HSIC3_PROD			= 4,
	IPA_CLIENT_HSIC3_CONS			= 5,

	IPA_CLIENT_HSIC4_PROD			= 6,
	IPA_CLIENT_HSIC4_CONS			= 7,

	IPA_CLIENT_HSIC5_PROD			= 8,
	IPA_CLIENT_HSIC5_CONS			= 9,

	IPA_CLIENT_WLAN1_PROD			= 10,
	IPA_CLIENT_WLAN1_CONS			= 11,

	IPA_CLIENT_A5_WLAN_AMPDU_PROD		= 12,
	IPA_CLIENT_WLAN2_CONS			= 13,

	IPA_CLIENT_WLAN3_PROD			= 14,
	IPA_CLIENT_WLAN3_CONS			= 15,

	IPA_CLIENT_WLAN2_PROD1			= 16,
	IPA_CLIENT_WLAN4_CONS			= 17,

	IPA_CLIENT_USB_PROD			= 18,
	IPA_CLIENT_USB_CONS			= 19,

	IPA_CLIENT_USB2_PROD			= 20,
	IPA_CLIENT_USB2_CONS			= 21,

	IPA_CLIENT_USB3_PROD			= 22,
	IPA_CLIENT_USB3_CONS			= 23,

	IPA_CLIENT_USB4_PROD			= 24,
	IPA_CLIENT_USB4_CONS			= 25,

	IPA_CLIENT_UC_USB_PROD			= 26,
	IPA_CLIENT_USB_DPL_CONS			= 27,

	IPA_CLIENT_A2_EMBEDDED_PROD		= 28,
	IPA_CLIENT_A2_EMBEDDED_CONS		= 29,

	IPA_CLIENT_A2_TETHERED_PROD		= 30,
	IPA_CLIENT_A2_TETHERED_CONS		= 31,

	IPA_CLIENT_APPS_LAN_PROD		= 32,
	IPA_CLIENT_APPS_LAN_CONS		= 33,

	IPA_CLIENT_APPS_WAN_PROD		= 34,
	IPA_CLIENT_APPS_LAN_WAN_PROD = IPA_CLIENT_APPS_WAN_PROD,
	IPA_CLIENT_APPS_WAN_CONS		= 35,

	IPA_CLIENT_APPS_CMD_PROD		= 36,
	IPA_CLIENT_A5_LAN_WAN_CONS		= 37,

	IPA_CLIENT_ODU_PROD			= 38,
	IPA_CLIENT_ODU_EMB_CONS			= 39,

	IPA_CLIENT_WLAN3_PROD1			= 40,
	IPA_CLIENT_ODU_TETH_CONS		= 41,

	IPA_CLIENT_MHI_PROD			= 42,
	IPA_CLIENT_MHI_CONS			= 43,

	IPA_CLIENT_MEMCPY_DMA_SYNC_PROD		= 44,
	IPA_CLIENT_MEMCPY_DMA_SYNC_CONS		= 45,

	IPA_CLIENT_MEMCPY_DMA_ASYNC_PROD	= 46,
	IPA_CLIENT_MEMCPY_DMA_ASYNC_CONS	= 47,

	IPA_CLIENT_ETHERNET_PROD		= 48,
	IPA_CLIENT_ETHERNET_CONS		= 49,

	IPA_CLIENT_Q6_LAN_PROD			= 50,
	IPA_CLIENT_Q6_LAN_CONS			= 51,

	IPA_CLIENT_Q6_WAN_PROD			= 52,
	IPA_CLIENT_Q6_WAN_CONS			= 53,

	IPA_CLIENT_Q6_CMD_PROD			= 54,
	IPA_CLIENT_Q6_DUN_CONS			= 55,

	IPA_CLIENT_Q6_DECOMP_PROD		= 56,
	IPA_CLIENT_Q6_DECOMP_CONS		= 57,

	IPA_CLIENT_Q6_DECOMP2_PROD		= 58,
	IPA_CLIENT_Q6_DECOMP2_CONS		= 59,

	/* RESERVED PROD			= 60, */
	IPA_CLIENT_Q6_LTE_WIFI_AGGR_CONS	= 61,

	IPA_CLIENT_TEST_PROD			= 62,
	IPA_CLIENT_TEST_CONS			= 63,

	IPA_CLIENT_TEST1_PROD			= 64,
	IPA_CLIENT_TEST1_CONS			= 65,

	IPA_CLIENT_TEST2_PROD			= 66,
	IPA_CLIENT_TEST2_CONS			= 67,

	IPA_CLIENT_TEST3_PROD			= 68,
	IPA_CLIENT_TEST3_CONS			= 69,

	IPA_CLIENT_TEST4_PROD			= 70,
	IPA_CLIENT_TEST4_CONS			= 71,

	/* RESERVED PROD			= 72, */
	IPA_CLIENT_DUMMY_CONS			= 73,

	IPA_CLIENT_Q6_DL_NLO_DATA_PROD		= 74,
	IPA_CLIENT_Q6_UL_NLO_DATA_CONS		= 75,

	/* RESERVERD PROD			= 76, */
	IPA_CLIENT_Q6_UL_NLO_ACK_CONS		= 77,

	/* RESERVERD PROD			= 78, */
	IPA_CLIENT_Q6_QBAP_STATUS_CONS		= 79,

	/* RESERVERD PROD			= 80, */
	IPA_CLIENT_MHI_DPL_CONS			= 81,

	/* RESERVERD PROD			= 82, */
	IPA_CLIENT_ODL_DPL_CONS			= 83,

	IPA_CLIENT_Q6_AUDIO_DMA_MHI_PROD	= 84,
	IPA_CLIENT_Q6_AUDIO_DMA_MHI_CONS	= 85,

	IPA_CLIENT_WIGIG_PROD			= 86,
	IPA_CLIENT_WIGIG1_CONS			= 87,

	/* RESERVERD PROD			= 88, */
	IPA_CLIENT_WIGIG2_CONS			= 89,

	/* RESERVERD PROD			= 90, */
	IPA_CLIENT_WIGIG3_CONS			= 91,

	/* RESERVERD PROD			= 92, */
	IPA_CLIENT_WIGIG4_CONS			= 93,

	/* RESERVED PROD			= 94, */
	IPA_CLIENT_APPS_WAN_COAL_CONS		= 95,

	IPA_CLIENT_MHI_PRIME_TETH_PROD		= 96,
	IPA_CLIENT_MHI_PRIME_TETH_CONS		= 97,

	IPA_CLIENT_MHI_PRIME_RMNET_PROD		= 98,
	IPA_CLIENT_MHI_PRIME_RMNET_CONS		= 99,

	IPA_CLIENT_MHI_PRIME_DPL_PROD		= 100,
	IPA_CLIENT_MHI_COAL_CONS			= 101,

	IPA_CLIENT_AQC_ETHERNET_PROD		= 102,
	IPA_CLIENT_AQC_ETHERNET_CONS		= 103,

	IPA_CLIENT_APPS_WAN_LOW_LAT_PROD	= 104,
	IPA_CLIENT_APPS_WAN_LOW_LAT_CONS	= 105,

	IPA_CLIENT_QDSS_PROD			= 106,
	IPA_CLIENT_MHI_QDSS_CONS		= 107,

	IPA_CLIENT_RTK_ETHERNET_PROD		= 108,
	IPA_CLIENT_RTK_ETHERNET_CONS		= 109,

	IPA_CLIENT_MHI_LOW_LAT_PROD		= 110,
	IPA_CLIENT_MHI_LOW_LAT_CONS		= 111,

	IPA_CLIENT_MHI2_PROD	= 112,
	IPA_CLIENT_MHI2_CONS	= 113,

	IPA_CLIENT_Q6_CV2X_PROD	= 114,
	IPA_CLIENT_Q6_CV2X_CONS	= 115,

	IPA_CLIENT_ETHERNET2_PROD = 116,
	IPA_CLIENT_ETHERNET2_CONS = 117,

	/* RESERVED PROD			= 118, */
	IPA_CLIENT_WLAN2_CONS1			= 119,

	IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_PROD	= 120,
	IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_CONS	= 121,

	IPA_CLIENT_Q6_DL_NLO_LL_DATA_PROD       = 122,
	/* RESERVED CONS			= 123, */

	/* RESERVED PROD                        = 124, */
	IPA_CLIENT_TPUT_CONS                    = 125,

	IPA_CLIENT_Q6_DL_NLO_ETH_DATA_PROD      = 126,
	/* RESERVED CONS			            = 127, */

	IPA_CLIENT_APPS_WAN_ETH_PROD            = 128,
	/* RESERVED CONS			            = 129, */
};

#define IPA_CLIENT_MAX (IPA_CLIENT_APPS_WAN_ETH_PROD + 1)

#define IPA_CLIENT_WLAN2_PROD IPA_CLIENT_A5_WLAN_AMPDU_PROD
#define IPA_CLIENT_Q6_DL_NLO_DATA_PROD IPA_CLIENT_Q6_DL_NLO_DATA_PROD
#define IPA_CLIENT_Q6_UL_NLO_ACK_CONS IPA_CLIENT_Q6_UL_NLO_ACK_CONS
#define IPA_CLIENT_Q6_QBAP_STATUS_CONS IPA_CLIENT_Q6_QBAP_STATUS_CONS
#define IPA_CLIENT_MHI_DPL_CONS IPA_CLIENT_MHI_DPL_CONS
#define IPA_CLIENT_Q6_AUDIO_DMA_MHI_PROD IPA_CLIENT_Q6_AUDIO_DMA_MHI_PROD
#define IPA_CLIENT_Q6_AUDIO_DMA_MHI_CONS IPA_CLIENT_Q6_AUDIO_DMA_MHI_CONS
#define IPA_CLIENT_WIGIG_PROD IPA_CLIENT_WIGIG_PROD
#define IPA_CLIENT_WIGIG1_CONS IPA_CLIENT_WIGIG1_CONS
#define IPA_CLIENT_WIGIG2_CONS IPA_CLIENT_WIGIG2_CONS
#define IPA_CLIENT_WIGIG3_CONS IPA_CLIENT_WIGIG3_CONS
#define IPA_CLIENT_WIGIG4_CONS IPA_CLIENT_WIGIG4_CONS
#define IPA_CLIENT_APPS_WAN_COAL_CONS IPA_CLIENT_APPS_WAN_COAL_CONS
#define IPA_CLIENT_MHI_PRIME_TETH_PROD IPA_CLIENT_MHI_PRIME_TETH_PROD
#define IPA_CLIENT_MHI_PRIME_TETH_CONS IPA_CLIENT_MHI_PRIME_TETH_CONS
#define IPA_CLIENT_MHI_PRIME_RMNET_PROD IPA_CLIENT_MHI_PRIME_RMNET_PROD
#define IPA_CLIENT_MHI_PRIME_RMNET_CONS IPA_CLIENT_MHI_PRIME_RMNET_CONS
#define IPA_CLIENT_MHI_PRIME_DPL_PROD IPA_CLIENT_MHI_PRIME_DPL_PROD
#define IPA_CLIENT_AQC_ETHERNET_PROD IPA_CLIENT_AQC_ETHERNET_PROD
#define IPA_CLIENT_AQC_ETHERNET_CONS IPA_CLIENT_AQC_ETHERNET_CONS
#define IPA_CLIENT_MHI_QDSS_CONS IPA_CLIENT_MHI_QDSS_CONS
#define IPA_CLIENT_QDSS_PROD IPA_CLIENT_QDSS_PROD
#define IPA_CLIENT_WLAN2_CONS1 IPA_CLIENT_WLAN2_CONS1
#define IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_PROD IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_PROD
#define IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_CONS IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_CONS
#define IPA_CLIENT_Q6_DL_NLO_LL_DATA_PROD IPA_CLIENT_Q6_DL_NLO_LL_DATA_PROD
#define IPA_CLIENT_MHI_COAL_CONS IPA_CLIENT_MHI_COAL_CONS
#define IPA_CLIENT_WLAN2_PROD1 IPA_CLIENT_WLAN2_PROD1
#define IPA_CLIENT_WLAN3_PROD1 IPA_CLIENT_WLAN3_PROD1

#define IPA_CLIENT_IS_APPS_CONS(client) \
	((client) == IPA_CLIENT_APPS_LAN_CONS || \
	(client) == IPA_CLIENT_APPS_WAN_CONS || \
	(client) == IPA_CLIENT_APPS_WAN_COAL_CONS || \
	(client) == IPA_CLIENT_APPS_WAN_LOW_LAT_CONS || \
	(client) == IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_CONS)

#define IPA_CLIENT_IS_APPS_PROD(client) \
	((client) == IPA_CLIENT_APPS_LAN_PROD || \
	(client) == IPA_CLIENT_APPS_WAN_PROD || \
	(client) == IPA_CLIENT_APPS_WAN_LOW_LAT_PROD || \
	(client) == IPA_CLIENT_APPS_WAN_LOW_LAT_DATA_PROD || \
	(client) == IPA_CLIENT_APPS_WAN_ETH_PROD)

#define IPA_CLIENT_IS_USB_CONS(client) \
	((client) == IPA_CLIENT_USB_CONS || \
	(client) == IPA_CLIENT_USB2_CONS || \
	(client) == IPA_CLIENT_USB3_CONS || \
	(client) == IPA_CLIENT_USB_DPL_CONS || \
	(client) == IPA_CLIENT_USB4_CONS)

#define IPA_CLIENT_IS_WAN_CONS(client) \
	((client) == IPA_CLIENT_APPS_WAN_CONS || \
	(client) == IPA_CLIENT_APPS_WAN_COAL_CONS)

#define IPA_CLIENT_IS_LOW_LAT_CONS(client) \
	((client) == IPA_CLIENT_APPS_WAN_LOW_LAT_CONS)

#define IPA_CLIENT_IS_WLAN_CONS(client) \
	((client) == IPA_CLIENT_WLAN1_CONS || \
	(client) == IPA_CLIENT_WLAN2_CONS || \
	(client) == IPA_CLIENT_WLAN3_CONS || \
	(client) == IPA_CLIENT_WLAN2_CONS1 || \
	(client) == IPA_CLIENT_WLAN4_CONS)

#define IPA_CLIENT_IS_ODU_CONS(client) \
	((client) == IPA_CLIENT_ODU_EMB_CONS || \
	(client) == IPA_CLIENT_ODU_TETH_CONS)

#define IPA_CLIENT_IS_Q6_CONS(client) \
	((client) == IPA_CLIENT_Q6_LAN_CONS || \
	(client) == IPA_CLIENT_Q6_WAN_CONS || \
	(client) == IPA_CLIENT_Q6_DUN_CONS || \
	(client) == IPA_CLIENT_Q6_DECOMP_CONS || \
	(client) == IPA_CLIENT_Q6_DECOMP2_CONS || \
	(client) == IPA_CLIENT_Q6_LTE_WIFI_AGGR_CONS || \
	(client) == IPA_CLIENT_Q6_UL_NLO_DATA_CONS || \
	(client) == IPA_CLIENT_Q6_UL_NLO_ACK_CONS || \
	(client) == IPA_CLIENT_Q6_QBAP_STATUS_CONS || \
	(client) == IPA_CLIENT_Q6_CV2X_CONS || \
	(client) == IPA_CLIENT_Q6_AUDIO_DMA_MHI_CONS)

#define IPA_CLIENT_IS_Q6_PROD(client) \
	((client) == IPA_CLIENT_Q6_LAN_PROD || \
	(client) == IPA_CLIENT_Q6_WAN_PROD || \
	(client) == IPA_CLIENT_Q6_CMD_PROD || \
	(client) == IPA_CLIENT_Q6_DECOMP_PROD || \
	(client) == IPA_CLIENT_Q6_DECOMP2_PROD || \
	(client) == IPA_CLIENT_Q6_DL_NLO_LL_DATA_PROD || \
	(client) == IPA_CLIENT_Q6_DL_NLO_DATA_PROD || \
	(client) == IPA_CLIENT_Q6_CV2X_PROD || \
	(client) == IPA_CLIENT_Q6_AUDIO_DMA_MHI_PROD || \
	(client) == IPA_CLIENT_Q6_DL_NLO_ETH_DATA_PROD)

#define IPA_CLIENT_IS_Q6_NON_ZIP_CONS(client) \
	((client) == IPA_CLIENT_Q6_LAN_CONS || \
	(client) == IPA_CLIENT_Q6_WAN_CONS || \
	(client) == IPA_CLIENT_Q6_DUN_CONS || \
	(client) == IPA_CLIENT_Q6_LTE_WIFI_AGGR_CONS || \
	(client) == IPA_CLIENT_Q6_UL_NLO_DATA_CONS || \
	(client) == IPA_CLIENT_Q6_UL_NLO_ACK_CONS || \
	(client) == IPA_CLIENT_Q6_QBAP_STATUS_CONS || \
	(client) == IPA_CLIENT_Q6_CV2X_CONS || \
	(client) == IPA_CLIENT_Q6_AUDIO_DMA_MHI_CONS)

#define IPA_CLIENT_IS_Q6_ZIP_CONS(client) \
	((client) == IPA_CLIENT_Q6_DECOMP_CONS || \
	(client) == IPA_CLIENT_Q6_DECOMP2_CONS)

#define IPA_CLIENT_IS_Q6_NON_ZIP_PROD(client) \
	((client) == IPA_CLIENT_Q6_LAN_PROD || \
	(client) == IPA_CLIENT_Q6_WAN_PROD || \
	(client) == IPA_CLIENT_Q6_CMD_PROD || \
	(client) == IPA_CLIENT_Q6_DL_NLO_DATA_PROD || \
	(client) == IPA_CLIENT_Q6_DL_NLO_LL_DATA_PROD || \
	(client) == IPA_CLIENT_Q6_CV2X_PROD || \
	(client) == IPA_CLIENT_Q6_AUDIO_DMA_MHI_PROD)

#define IPA_CLIENT_IS_Q6_ZIP_PROD(client) \
	((client) == IPA_CLIENT_Q6_DECOMP_PROD || \
	(client) == IPA_CLIENT_Q6_DECOMP2_PROD)

#define IPA_CLIENT_IS_MEMCPY_DMA_CONS(client) \
	((client) == IPA_CLIENT_MEMCPY_DMA_SYNC_CONS || \
	(client) == IPA_CLIENT_MEMCPY_DMA_ASYNC_CONS)

#define IPA_CLIENT_IS_MEMCPY_DMA_PROD(client) \
	((client) == IPA_CLIENT_MEMCPY_DMA_SYNC_PROD || \
	(client) == IPA_CLIENT_MEMCPY_DMA_ASYNC_PROD)

#define IPA_CLIENT_IS_MHI(client) \
	((client) == IPA_CLIENT_MHI_CONS || \
	(client) == IPA_CLIENT_MHI_PROD || \
	(client) == IPA_CLIENT_MHI2_PROD || \
	(client) == IPA_CLIENT_MHI2_CONS || \
	(client) == IPA_CLIENT_MHI_DPL_CONS || \
	(client) == IPA_CLIENT_MHI_LOW_LAT_CONS || \
	(client) == IPA_CLIENT_MHI_LOW_LAT_PROD || \
	(client) == IPA_CLIENT_MHI_QDSS_CONS || \
	(client) == IPA_CLIENT_MHI_COAL_CONS)

#define IPA_CLIENT_IS_TEST_PROD(client) \
	((client) == IPA_CLIENT_TEST_PROD || \
	(client) == IPA_CLIENT_TEST1_PROD || \
	(client) == IPA_CLIENT_TEST2_PROD || \
	(client) == IPA_CLIENT_TEST3_PROD || \
	(client) == IPA_CLIENT_TEST4_PROD)

#define IPA_CLIENT_IS_TEST_CONS(client) \
	((client) == IPA_CLIENT_TEST_CONS || \
	(client) == IPA_CLIENT_TEST1_CONS || \
	(client) == IPA_CLIENT_TEST2_CONS || \
	(client) == IPA_CLIENT_TEST3_CONS || \
	(client) == IPA_CLIENT_TEST4_CONS)

#define IPA_CLIENT_IS_TEST(client) \
	(IPA_CLIENT_IS_TEST_PROD(client) || IPA_CLIENT_IS_TEST_CONS(client))

/**
 * The following is used to describe the types of memory NAT can
 * reside in.
 *
 * PLEASE KEEP THE FOLLOWING IN SYNC WITH ipa3_nat_mem_in_as_str()
 * BELOW.
 */
enum ipa3_nat_mem_in {
	IPA_NAT_MEM_IN_DDR  = 0,
	IPA_NAT_MEM_IN_SRAM = 1,

	IPA_NAT_MEM_IN_MAX
};

#define IPA_VALID_NAT_MEM_IN(t) \
	((t) >= IPA_NAT_MEM_IN_DDR && (t) < IPA_NAT_MEM_IN_MAX)

/**
 * enum ipa_ip_type - Address family: IPv4 or IPv6
 *
 * PLEASE KEEP THE FOLLOWING IN SYNC WITH ipa_ip_type_as_str()
 * BELOW.
 */
enum ipa_ip_type {
	IPA_IP_v4,
	IPA_IP_v6,
	IPA_IP_MAX,
	IPA_IP_v4_VLAN = IPA_IP_MAX,
	IPA_IP_v6_VLAN,
	IPA_IP_MAX_WLAN
};

#define VALID_IPA_IP_TYPE(t) \
	((t) >= IPA_IP_v4 && (t) < IPA_IP_MAX)

static __inline__ const char *ipa_ip_type_as_str(enum ipa_ip_type t)
{
	return
		(t == IPA_IP_v4)       ? "v4"          :
		(t == IPA_IP_v6)       ? "v6"          :
		(t == IPA_IP_MAX)      ? "max|v4_vlan" :
		(t == IPA_IP_v6_VLAN)  ? "v6_vlan"     :
		(t == IPA_IP_MAX_WLAN) ? "max_wlan"    :
		"???";
}

/**
 * enum ipa_rule_type - Type of routing or filtering rule
 * Hashable: Rule will be located at the hashable tables
 * Non_Hashable: Rule will be located at the non-hashable tables
 */
enum ipa_rule_type {
	IPA_RULE_HASHABLE,
	IPA_RULE_NON_HASHABLE,
};
#define IPA_RULE_TYPE_MAX (IPA_RULE_NON_HASHABLE + 1)

/**
 * enum ipa_flt_action - action field of filtering rule
 *
 * Pass to routing: 5'd0
 * Pass to source NAT: 5'd1
 * Pass to destination NAT: 5'd2
 * Pass to default output pipe (e.g., Apps or Modem): 5'd3
 */
enum ipa_flt_action {
	IPA_PASS_TO_ROUTING,
	IPA_PASS_TO_SRC_NAT,
	IPA_PASS_TO_DST_NAT,
	IPA_PASS_TO_EXCEPTION
};

/**
 * enum ipa_wlan_event - Events for wlan client
 *
 * wlan client connect: New wlan client connected
 * wlan client disconnect: wlan client disconnected
 * wlan client power save: wlan client moved to power save
 * wlan client normal: wlan client moved out of power save
 * sw routing enable: ipa routing is disabled
 * sw routing disable: ipa routing is enabled
 * wlan ap connect: wlan AP(access point) is up
 * wlan ap disconnect: wlan AP(access point) is down
 * wlan sta connect: wlan STA(station) is up
 * wlan sta disconnect: wlan STA(station) is down
 * wlan client connect ex: new wlan client connected
 * wlan scc switch: wlan interfaces in scc mode
 * wlan mcc switch: wlan interfaces in mcc mode
 * wlan wdi enable: wdi data path completed
 * wlan wdi disable: wdi data path teardown
 */
enum ipa_wlan_event {
	WLAN_CLIENT_CONNECT,
	WLAN_CLIENT_DISCONNECT,
	WLAN_CLIENT_POWER_SAVE_MODE,
	WLAN_CLIENT_NORMAL_MODE,
	SW_ROUTING_ENABLE,
	SW_ROUTING_DISABLE,
	WLAN_AP_CONNECT,
	WLAN_AP_DISCONNECT,
	WLAN_STA_CONNECT,
	WLAN_STA_DISCONNECT,
	WLAN_CLIENT_CONNECT_EX,
	WLAN_SWITCH_TO_SCC,
	WLAN_SWITCH_TO_MCC,
	WLAN_WDI_ENABLE,
	WLAN_WDI_DISABLE,
	IPA_WLAN_EVENT_MAX
};

/**
 * enum ipa_wan_event - Events for wan client
 *
 * wan default route add/del
 * wan embms connect: New wan embms interface connected
 */
enum ipa_wan_event {
	WAN_UPSTREAM_ROUTE_ADD = IPA_WLAN_EVENT_MAX,
	WAN_UPSTREAM_ROUTE_DEL,
	WAN_EMBMS_CONNECT,
	WAN_XLAT_CONNECT,
	IPA_WAN_EVENT_MAX
};

enum ipa_ecm_event {
	ECM_CONNECT = IPA_WAN_EVENT_MAX,
	ECM_DISCONNECT,
	IPA_ECM_EVENT_MAX,
};

enum ipa_tethering_stats_event {
	IPA_TETHERING_STATS_UPDATE_STATS = IPA_ECM_EVENT_MAX,
	IPA_TETHERING_STATS_UPDATE_NETWORK_STATS,
	IPA_TETHERING_STATS_EVENT_MAX,
};


enum ipa_quota_event {
	IPA_QUOTA_REACH = IPA_TETHERING_STATS_EVENT_MAX,
	IPA_QUOTA_EVENT_MAX,
};

enum ipa_ssr_event {
	IPA_SSR_BEFORE_SHUTDOWN = IPA_QUOTA_EVENT_MAX,
	IPA_SSR_AFTER_POWERUP,
	IPA_SSR_EVENT_MAX,
};

enum ipa_vlan_l2tp_event {
	ADD_VLAN_IFACE = IPA_SSR_EVENT_MAX,
	DEL_VLAN_IFACE,
	ADD_L2TP_VLAN_MAPPING,
	DEL_L2TP_VLAN_MAPPING,
	IPA_VLAN_L2TP_EVENT_MAX,
};

enum ipa_per_client_stats_event {
	IPA_PER_CLIENT_STATS_CONNECT_EVENT = IPA_VLAN_L2TP_EVENT_MAX,
	IPA_PER_CLIENT_STATS_DISCONNECT_EVENT,
	IPA_PER_CLIENT_STATS_EVENT_MAX,
};

enum ipa_vlan_bridge_event {
	ADD_BRIDGE_VLAN_MAPPING = IPA_PER_CLIENT_STATS_EVENT_MAX,
	DEL_BRIDGE_VLAN_MAPPING,
	BRIDGE_VLAN_MAPPING_MAX,
};

enum ipa_wlan_fw_ssr_event {
	WLAN_FWR_SSR_BEFORE_SHUTDOWN = BRIDGE_VLAN_MAPPING_MAX,
	IPA_WLAN_FW_SSR_EVENT_MAX,
#define IPA_WLAN_FW_SSR_EVENT_MAX IPA_WLAN_FW_SSR_EVENT_MAX
};

enum ipa_gsb_event {
	IPA_GSB_CONNECT = IPA_WLAN_FW_SSR_EVENT_MAX,
	IPA_GSB_DISCONNECT,
	IPA_GSB_EVENT_MAX,
};

enum ipa_coalesce_event {
	IPA_COALESCE_ENABLE = IPA_GSB_EVENT_MAX,
	IPA_COALESCE_DISABLE,
	IPA_COALESCE_EVENT_MAX
#define IPA_COALESCE_EVENT_MAX IPA_COALESCE_EVENT_MAX
};

enum ipa_mtu_event {
	IPA_SET_MTU = IPA_COALESCE_EVENT_MAX,
	IPA_MTU_EVENT_MAX
#define IPA_MTU_EVENT_MAX IPA_MTU_EVENT_MAX
};

enum ipa_peripheral_event {
	IPA_PERIPHERAL_CONNECT = ECM_CONNECT,
	IPA_PERIPHERAL_DISCONNECT = ECM_DISCONNECT
};

#define WIGIG_CLIENT_CONNECT (IPA_MTU_EVENT_MAX)
#define WIGIG_FST_SWITCH (WIGIG_CLIENT_CONNECT + 1)
#define WIGIG_EVENT_MAX (WIGIG_FST_SWITCH + 1)

enum ipa_pdn_config_event {
	IPA_PDN_DEFAULT_MODE_CONFIG = WIGIG_EVENT_MAX, /* Default mode. */
	IPA_PDN_IP_COLLISION_MODE_CONFIG, /* IP Collision detected. */
	IPA_PDN_IP_PASSTHROUGH_MODE_CONFIG, /* IP Passthrough mode. */
	IPA_PDN_CONFIG_EVENT_MAX
#define IPA_PDN_CONFIG_EVENT_MAX IPA_PDN_CONFIG_EVENT_MAX
};

enum ipa_mac_flt_event {
	IPA_MAC_FLT_EVENT = IPA_PDN_CONFIG_EVENT_MAX,
	IPA_MAC_FLT_EVENT_MAX
#define IPA_MAC_FLT_EVENT_MAX IPA_MAC_FLT_EVENT_MAX
};

enum ipa_sockv5_event {
	IPA_SOCKV5_ADD = IPA_MAC_FLT_EVENT_MAX,
	IPA_SOCKV5_DEL,
	IPA_SOCKV5_EVENT_MAX
#define IPA_SOCKV5_EVENT_MAX IPA_SOCKV5_EVENT_MAX
};

enum ipa_sw_flt_event {
	IPA_SW_FLT_EVENT = IPA_SOCKV5_EVENT_MAX,
	IPA_SW_FLT_EVENT_MAX
#define IPA_SW_FLT_EVENT_MAX IPA_SW_FLT_EVENT_MAX
};

enum ipa_pkt_threshold_event {
	IPA_PKT_THRESHOLD_EVENT = IPA_SW_FLT_EVENT_MAX,
	IPA_PKT_THRESHOLD_EVENT_MAX
#define IPA_PKT_THRESHOLD_EVENT_MAX IPA_PKT_THRESHOLD_EVENT_MAX
};

enum ipa_move_nat_table_event {
	IPA_MOVE_NAT_TABLE = IPA_PKT_THRESHOLD_EVENT_MAX,
	IPA_MOVE_NAT_EVENT_MAX
#define IPA_MOVE_NAT_EVENT_MAX IPA_MOVE_NAT_EVENT_MAX
};

enum ipa_eogre_event {
	IPA_EoGRE_UP_EVENT = IPA_MOVE_NAT_EVENT_MAX,
	IPA_EoGRE_DOWN_EVENT,
	IPA_EoGRE_EVENT_MAX
#define IPA_EoGRE_EVENT_MAX IPA_EoGRE_EVENT_MAX
};

enum ipa_ippt_sw_flt_event {
	IPA_IPPT_SW_FLT_EVENT = IPA_EoGRE_EVENT_MAX,
	IPA_IPPT_SW_FLT_EVENT_MAX
#define IPA_IPPT_SW_FLT_EVENT_MAX IPA_IPPT_SW_FLT_EVENT_MAX
};

enum ipa_macsec_event {
	IPA_MACSEC_ADD_EVENT = IPA_IPPT_SW_FLT_EVENT_MAX,
	IPA_MACSEC_DEL_EVENT,
	IPA_MACSEC_EVENT_MAX
#define IPA_MACSEC_EVENT_MAX IPA_MACSEC_EVENT_MAX
};

enum ipa_done_restore_event {
	IPA_DONE_RESTORE_EVENT = IPA_MACSEC_EVENT_MAX,
	IPA_DONE_RESTORE_EVENT_MAX
	#define IPA_DONE_RESTORE_EVENT_MAX IPA_DONE_RESTORE_EVENT_MAX
};

enum ipa_ext_route_evt {
	IPA_SET_EXT_ROUTER_MODE_EVENT = IPA_DONE_RESTORE_EVENT_MAX,
	IPA_SET_EXT_ROUTER_MODE_EVENT_MAX
#define IPA_SET_EXT_ROUTER_MODE_EVENT_MAX IPA_SET_EXT_ROUTER_MODE_EVENT_MAX
};

enum ipa_eth_pdu_evt {
	IPA_ENABLE_ETH_PDU_MODE_EVENT = IPA_SET_EXT_ROUTER_MODE_EVENT_MAX,
	IPA_ENABLE_ETH_PDU_MODE_EVENT_MAX
#define IPA_ENABLE_ETH_PDU_MODE_EVENT_MAX IPA_ENABLE_ETH_PDU_MODE_EVENT_MAX
};


#define IPA_EVENT_MAX_NUM (IPA_ENABLE_ETH_PDU_MODE_EVENT_MAX)
#define IPA_EVENT_MAX ((int)IPA_EVENT_MAX_NUM)

/**
 * enum ipa_rm_resource_name - IPA RM clients identification names
 *
 * PROD resources are always even, and CONS resources are always odd.
 * Add new clients in the end of the list and update IPA_RM_RESOURCE_MAX
 */
enum ipa_rm_resource_name {
	IPA_RM_RESOURCE_Q6_PROD				= 0,
	IPA_RM_RESOURCE_Q6_CONS				= 1,

	IPA_RM_RESOURCE_USB_PROD			= 2,
	IPA_RM_RESOURCE_USB_CONS			= 3,

	IPA_RM_RESOURCE_USB_DPL_DUMMY_PROD		= 4,
	IPA_RM_RESOURCE_USB_DPL_CONS			= 5,

	IPA_RM_RESOURCE_HSIC_PROD			= 6,
	IPA_RM_RESOURCE_HSIC_CONS			= 7,

	IPA_RM_RESOURCE_STD_ECM_PROD			= 8,
	IPA_RM_RESOURCE_APPS_CONS			= 9,

	IPA_RM_RESOURCE_RNDIS_PROD			= 10,
	/* RESERVED CONS				= 11, */

	IPA_RM_RESOURCE_WWAN_0_PROD			= 12,
	/* RESERVED CONS				= 13, */

	IPA_RM_RESOURCE_WLAN_PROD			= 14,
	IPA_RM_RESOURCE_WLAN_CONS			= 15,

	IPA_RM_RESOURCE_ODU_ADAPT_PROD			= 16,
	IPA_RM_RESOURCE_ODU_ADAPT_CONS			= 17,

	IPA_RM_RESOURCE_MHI_PROD			= 18,
	IPA_RM_RESOURCE_MHI_CONS			= 19,

	IPA_RM_RESOURCE_ETHERNET_PROD			= 20,
	IPA_RM_RESOURCE_ETHERNET_CONS			= 21,
};
#define IPA_RM_RESOURCE_MAX (IPA_RM_RESOURCE_ETHERNET_CONS + 1)

/**
 * enum ipa_hw_type - IPA hardware version type
 * @IPA_HW_None: IPA hardware version not defined
 * @IPA_HW_v1_0: IPA hardware version 1.0
 * @IPA_HW_v1_1: IPA hardware version 1.1
 * @IPA_HW_v2_0: IPA hardware version 2.0
 * @IPA_HW_v2_1: IPA hardware version 2.1
 * @IPA_HW_v2_5: IPA hardware version 2.5
 * @IPA_HW_v2_6: IPA hardware version 2.6
 * @IPA_HW_v2_6L: IPA hardware version 2.6L
 * @IPA_HW_v3_0: IPA hardware version 3.0
 * @IPA_HW_v3_1: IPA hardware version 3.1
 * @IPA_HW_v3_5: IPA hardware version 3.5
 * @IPA_HW_v3_5_1: IPA hardware version 3.5.1
 * @IPA_HW_v4_0: IPA hardware version 4.0
 * @IPA_HW_v4_1: IPA hardware version 4.1
 * @IPA_HW_v4_2: IPA hardware version 4.2
 * @IPA_HW_v4_5: IPA hardware version 4.5
 * @IPA_HW_v4_7: IPA hardware version 4.7
 * @IPA_HW_v4_9: IPA hardware version 4.9
 * @IPA_HW_v4_11: IPA hardware version 4.11
 * @IPA_HW_v5_0: IPA hardware version 5.0
 * @IPA_HW_v5_1: IPA hardware version 5.1
 */
enum ipa_hw_type {
	IPA_HW_None = 0,
	IPA_HW_v1_0 = 1,
	IPA_HW_v1_1 = 2,
	IPA_HW_v2_0 = 3,
	IPA_HW_v2_1 = 4,
	IPA_HW_v2_5 = 5,
	IPA_HW_v2_6 = IPA_HW_v2_5,
	IPA_HW_v2_6L = 6,
	IPA_HW_v3_0 = 10,
	IPA_HW_v3_1 = 11,
	IPA_HW_v3_5 = 12,
	IPA_HW_v3_5_1 = 13,
	IPA_HW_v4_0 = 14,
	IPA_HW_v4_1 = 15,
	IPA_HW_v4_2 = 16,
	IPA_HW_v4_5 = 17,
	IPA_HW_v4_7 = 18,
	IPA_HW_v4_9 = 19,
	IPA_HW_v4_11 = 20,
	IPA_HW_v5_0 = 21,
	IPA_HW_v5_1 = 22,
	IPA_HW_v5_2 = 23,
};
#define IPA_HW_MAX (IPA_HW_v5_2 + 1)

#define IPA_HW_v4_0 IPA_HW_v4_0
#define IPA_HW_v4_1 IPA_HW_v4_1
#define IPA_HW_v4_2 IPA_HW_v4_2
#define IPA_HW_v4_5 IPA_HW_v4_5
#define IPA_HW_v4_7 IPA_HW_v4_7
#define IPA_HW_v4_9 IPA_HW_v4_9
#define IPA_HW_v4_11 IPA_HW_v4_11
#define IPA_HW_v5_0 IPA_HW_v5_0
#define IPA_HW_v5_1 IPA_HW_v5_1
#define IPA_HW_v5_2 IPA_HW_v5_2

/**
 * enum ipa_hw_feature_support - IPA HW supported feature
 * ETH_BRIDGING_SUPPORT: To check ETH BRIDGING support.
 * Add here new feature information need to send to userspace
 */
enum ipa_hw_feature_support {
	ETH_BRIDGING_SUPPORT = 0,
};

#define IPA_HW_ETH_BRIDGING_SUPPORT_BMSK 0x1

/**
 * enum ipa_exception_type
 *
 * This enum is for describing which field is to be looked at for
 * exception path consideration.
 *
 * NOTE 1: The field implies an offset into the packet under
 *         consideration.  This offset will be calculated on behalf of
 *         the user of this API.
 *
 * NOTE 2: When exceptions are generated/sent in an ipa_exception
 *         structure, they will considered to be from the upload
 *         perspective. And when appropriate, a corresponding, and
 *         perhaps inverted, downlink exception will be automatically
 *         created on the callers behalf.  As an example: If a
 *         FIELD_UDP_SRC_PORT is sent, an uplink exception will be
 *         created for udp source port, and a corresponding
 *         FIELD_UDP_DST_PORT will be automatically created for the
 *         downlink.
 */
enum ipa_exception_type {
	FIELD_IP_PROTOCOL  = 0,
	FIELD_TCP_SRC_PORT = 1,
	FIELD_TCP_DST_PORT = 2,
	FIELD_UDP_SRC_PORT = 3,
	FIELD_UDP_DST_PORT = 4,
	FIELD_ETHER_TYPE   = 5,
	FIELD_MAX
};

#define VALID_EXCEPTION_TYPE(x) \
	((x) >= FIELD_IP_PROTOCOL && (x) < FIELD_MAX)

static __inline__ const char *exception_type_as_str(enum ipa_exception_type t)
{
	return
		(t == FIELD_IP_PROTOCOL)  ? "ip_protocol"  :
		(t == FIELD_TCP_SRC_PORT) ? "tcp_src_port" :
		(t == FIELD_TCP_DST_PORT) ? "tcp_dst_port" :
		(t == FIELD_UDP_SRC_PORT) ? "udp_src_port" :
		(t == FIELD_UDP_DST_PORT) ? "udp_dst_port" :
		(t == FIELD_ETHER_TYPE)   ? "ether_type"   :
		(t == FIELD_MAX)          ? "max"          :
		"???";
}

/**
 * Macro ipa_exception_type_pppoe
 *
 * This macro is for describing which field is to be looked at for
 * exception path consideration.
 *
 * NOTE 1: The field implies an offset into the packet under
 *         consideration.  This offset will be calculated on behalf of
 *         the user of this API.
 *
 * NOTE 2: When exceptions are generated/sent in an ipa_exception
 *         structure, they will considered to be from the upload
 *         perspective. And when appropriate, a corresponding, and
 *         perhaps inverted, downlink exception will be automatically
 *         created on the callers behalf.  As an example: If a
 *         FIELD_UDP_SRC_PORT is sent, an uplink exception will be
 *         created for udp source port, and a corresponding
 *         FIELD_UDP_DST_PORT will be automatically created for the
 *         downlink.
 */
#define FIELD_IP_PROTOCOL_PPPOE (FIELD_ETHER_TYPE + 1)
#define FIELD_TCP_SRC_PORT_PPPOE (FIELD_IP_PROTOCOL_PPPOE + 1)
#define FIELD_TCP_DST_PORT_PPPOE (FIELD_TCP_SRC_PORT_PPPOE + 1)
#define FIELD_UDP_SRC_PORT_PPPOE (FIELD_TCP_DST_PORT_PPPOE + 1)
#define FIELD_UDP_DST_PORT_PPPOE (FIELD_UDP_SRC_PORT_PPPOE + 1)
#define FIELD_ETHER_TYPE_PPPOE   (FIELD_UDP_DST_PORT_PPPOE + 1)
#define FIELD_PPPOE_MAX	(FIELD_ETHER_TYPE_PPPOE + 1)

/* Function to read PPPoE exception in string format */
static __inline__ const char *pppoe_exception_type_as_str(uint32_t t)
{
	return
		(t == FIELD_IP_PROTOCOL_PPPOE)  ? "pppoe_ip_protocol"  :
		(t == FIELD_TCP_SRC_PORT_PPPOE) ? "pppoe_tcp_src_port" :
		(t == FIELD_TCP_DST_PORT_PPPOE) ? "pppoe_tcp_dst_port" :
		(t == FIELD_UDP_SRC_PORT_PPPOE) ? "pppoe_udp_src_port" :
		(t == FIELD_UDP_DST_PORT_PPPOE) ? "pppoe_udp_dst_port" :
		(t == FIELD_ETHER_TYPE_PPPOE)   ? "pppoe_ether_type"   :
		(t == FIELD_PPPOE_MAX)          ? "pppoe_max"          :
		"???";
}

#define IP_TYPE_EXCEPTION(x) \
	((x) == FIELD_IP_PROTOCOL  || \
	  (x) == FIELD_TCP_SRC_PORT || \
	  (x) == FIELD_TCP_DST_PORT || \
	  (x) == FIELD_UDP_SRC_PORT || \
	  (x) == FIELD_UDP_DST_PORT)

/**
 * enum ipa_data_flow_type
 *
 * This enum is for describing whether a data flow is uplink or down.
 */
enum ipa_data_flow_type {
	FLOW_UPLINK   = 0,
	FLOW_DOWNLINK = 1,
	FLOW_MAX
};

#define VALID_FLOW_TYPE(x) \
	((x) >= FLOW_UPLINK && (x) < FLOW_MAX)

static __inline__ const char *flow_type_as_str(enum ipa_data_flow_type t)
{
	return
		(t == FLOW_UPLINK)   ? "uplink"   :
		(t == FLOW_DOWNLINK) ? "downlink" :
		(t == FLOW_MAX)      ? "max"      :
		"???";
}

/**
 * struct ipa_field_val_equation_gen
 *
 *  Needed for generating an equation for peering into and finding
 *  data in a packet or frame.
 *
 * @flow:      Are we generating an equation for uplink or downlink
 * @inner_iptype: What's the ip type of the inner packet
 * @field:     Field we're generating equation for
 * @value:     The value at that field we're looking for
 */
struct ipa_field_val_equation_gen {
	enum ipa_data_flow_type  flow;
	enum ipa_ip_type         inner_iptype;
	enum ipa_exception_type  field;
	uint32_t                 value;
};

/**
 * struct ipa_rule_attrib - attributes of a routing/filtering
 * rule, all in LE
 * @attrib_mask: what attributes are valid
 * @src_port_lo: low port of src port range
 * @src_port_hi: high port of src port range
 * @dst_port_lo: low port of dst port range
 * @dst_port_hi: high port of dst port range
 * @type: ICMP/IGMP type
 * @code: ICMP/IGMP code
 * @spi: IPSec SPI
 * @src_port: exact src port
 * @dst_port: exact dst port
 * @meta_data: meta-data val
 * @meta_data_mask: meta-data mask
 * @u.v4.tos: type of service
 * @u.v4.protocol: protocol
 * @u.v4.src_addr: src address value
 * @u.v4.src_addr_mask: src address mask
 * @u.v4.dst_addr: dst address value
 * @u.v4.dst_addr_mask: dst address mask
 * @u.v6.tc: traffic class
 * @u.v6.flow_label: flow label
 * @u.v6.next_hdr: next header
 * @u.v6.src_addr: src address val
 * @u.v6.src_addr_mask: src address mask
 * @u.v6.dst_addr: dst address val
 * @u.v6.dst_addr_mask: dst address mask
 * @vlan_id: vlan id value
 * @payload_length: Payload length.
 * @ext_attrib_mask: Extended attributes.
 * @l2tp_udp_next_hdr: next header in L2TP tunneling
 * @p_exception : exception to enable for mpls-pppoe
 * @field_val_equ: for finding a value at a particular offset
 */
struct ipa_rule_attrib {
	uint32_t attrib_mask;
	uint16_t src_port_lo;
	uint16_t src_port_hi;
	uint16_t dst_port_lo;
	uint16_t dst_port_hi;
	uint8_t type;
	uint8_t code;
	uint8_t tos_value;
	uint8_t tos_mask;
	uint32_t spi;
	uint16_t src_port;
	uint16_t dst_port;
	uint32_t meta_data;
	uint32_t meta_data_mask;
	uint8_t src_mac_addr[ETH_ALEN];
	uint8_t src_mac_addr_mask[ETH_ALEN];
	uint8_t dst_mac_addr[ETH_ALEN];
	uint8_t dst_mac_addr_mask[ETH_ALEN];
	uint16_t ether_type;
	union {
		struct {
			uint8_t tos;
			uint8_t protocol;
			uint32_t src_addr;
			uint32_t src_addr_mask;
			uint32_t dst_addr;
			uint32_t dst_addr_mask;
		} v4;
		struct {
			uint8_t tc;
			uint32_t flow_label;
			uint8_t next_hdr;
			uint32_t src_addr[4];
			uint32_t src_addr_mask[4];
			uint32_t dst_addr[4];
			uint32_t dst_addr_mask[4];
		} v6;
	} u;
	__u16 vlan_id;
	__u16 payload_length;
	__u32 ext_attrib_mask;
	__u8 l2tp_udp_next_hdr;
	__u8 p_exception;
	struct ipa_field_val_equation_gen fld_val_eq;
};


/*! @brief The maximum number of Mask Equal 32 Eqns */
#define IPA_IPFLTR_NUM_MEQ_32_EQNS 2

/*! @brief The maximum number of IHL offset Mask Equal 32 Eqns */
#define IPA_IPFLTR_NUM_IHL_MEQ_32_EQNS 2

/*! @brief The maximum number of Mask Equal 128 Eqns */
#define IPA_IPFLTR_NUM_MEQ_128_EQNS 2

/*! @brief The maximum number of IHL offset Range Check 16 Eqns */
#define IPA_IPFLTR_NUM_IHL_RANGE_16_EQNS 2

/*! @brief Offset and 16 bit comparison equation */
struct ipa_ipfltr_eq_16 {
	int8_t offset;
	uint16_t value;
};

/*! @brief Offset and 32 bit comparison equation */
struct ipa_ipfltr_eq_32 {
	int8_t offset;
	uint32_t value;
};

/*! @brief Offset and 128 bit masked comparison equation */
struct ipa_ipfltr_mask_eq_128 {
	int8_t offset;
	uint8_t mask[16];
	uint8_t value[16];
};

/*! @brief Offset and 32 bit masked comparison equation */
struct ipa_ipfltr_mask_eq_32 {
	int8_t offset;
	uint32_t mask;
	uint32_t value;
};

/*! @brief Equation for identifying a range. Ranges are inclusive */
struct ipa_ipfltr_range_eq_16 {
	int8_t offset;
	uint16_t range_low;
	uint16_t range_high;
};

/*! @brief Rule equations which are set according to DS filter installation */
struct ipa_ipfltri_rule_eq {
	/*! 16-bit Bitmask to indicate how many eqs are valid in this rule  */
	uint16_t rule_eq_bitmap;

	/*
	 * tos_eq_present field has two meanings:
	 * IPA ver < 4.5:
	 *  specifies if a type of service check rule is present
	 *  (as the field name reveals).
	 * IPA ver >= 4.5:
	 *  specifies if a tcp pure ack check rule is present
	 */
	uint8_t tos_eq_present;
	/*! The value to check against the type of service (ipv4) field */
	uint8_t tos_eq;
	/*! Specifies if a protocol check rule is present */
	uint8_t protocol_eq_present;
	/*! The value to check against the protocol (ipv6) field */
	uint8_t protocol_eq;
	/*! The number of ip header length offset 16 bit range check
	 * rules in this rule
	 */
	uint8_t num_ihl_offset_range_16;
	/*! An array of the registered ip header length offset 16 bit
	 * range check rules
	 */
	struct ipa_ipfltr_range_eq_16
		ihl_offset_range_16[IPA_IPFLTR_NUM_IHL_RANGE_16_EQNS];
	/*! The number of mask equal 32 rules present in this rule */
	uint8_t num_offset_meq_32;
	/*! An array of all the possible mask equal 32 rules in this rule */
	struct ipa_ipfltr_mask_eq_32
		offset_meq_32[IPA_IPFLTR_NUM_MEQ_32_EQNS];
	/*! Specifies if the traffic class rule is present in this rule */
	uint8_t tc_eq_present;
	/*! The value to check the traffic class (ipv4) field against */
	uint8_t tc_eq;
	/*! Specifies if the flow equals rule is present in this rule */
	uint8_t fl_eq_present;
	/*! The value to check the flow (ipv6) field against */
	uint32_t fl_eq;
	/*! The number of ip header length offset 16 bit equations in this
	 * rule
	 */
	uint8_t ihl_offset_eq_16_present;
	/*! The ip header length offset 16 bit equation */
	struct ipa_ipfltr_eq_16 ihl_offset_eq_16;
	/*! The number of ip header length offset 32 bit equations in this
	 * rule
	 */
	uint8_t ihl_offset_eq_32_present;
	/*! The ip header length offset 32 bit equation */
	struct ipa_ipfltr_eq_32 ihl_offset_eq_32;
	/*! The number of ip header length offset 32 bit mask equations in
	 * this rule
	 */
	uint8_t num_ihl_offset_meq_32;
	/*! The ip header length offset 32 bit mask equation */
	struct ipa_ipfltr_mask_eq_32
		ihl_offset_meq_32[IPA_IPFLTR_NUM_IHL_MEQ_32_EQNS];
	/*! The number of ip header length offset 128 bit equations in this
	 * rule
	 */
	uint8_t num_offset_meq_128;
	/*! The ip header length offset 128 bit equation */
	struct ipa_ipfltr_mask_eq_128
		offset_meq_128[IPA_IPFLTR_NUM_MEQ_128_EQNS];
	/*! The metadata 32 bit masked comparison equation present or not */
	/* Metadata based rules are added internally by IPA driver */
	uint8_t metadata_meq32_present;
	/*! The metadata 32 bit masked comparison equation */
	struct ipa_ipfltr_mask_eq_32 metadata_meq32;
	/*! Specifies if the Fragment equation is present in this rule */
	uint8_t ipv4_frag_eq_present;
};

/**
 * struct ipa_flt_rule - attributes of a filtering rule
 * @retain_hdr: bool switch to instruct IPA core to add back to the packet
 *  the header removed as part of header removal
 * @to_uc: bool switch to pass packet to micro-controller
 * @action: action field
 * @rt_tbl_hdl: handle of table from "get"
 * @attrib: attributes of the rule
 * @eq_attrib: attributes of the rule in equation form (valid when
 * eq_attrib_type is true)
 * @rt_tbl_idx: index of RT table referred to by filter rule (valid when
 * eq_attrib_type is true and non-exception action)
 * @eq_attrib_type: true if equation level form used to specify attributes
 * @max_prio: bool switch. is this rule with Max priority? meaning on rule hit,
 *  IPA will use the rule and will not look for other rules that may have
 *  higher priority
 * @hashable: bool switch. is this rule hashable or not?
 *  ipa uses hashable rules to cache their hit results to be used in
 *  consecutive packets
 * @rule_id: rule_id to be assigned to the filter rule. In case client specifies
 *  rule_id as 0 the driver will assign a new rule_id
 * @set_metadata: bool switch. should metadata replacement at the NAT block
 *  take place?
 * @pdn_idx: if action is "pass to source\destination NAT" then a comparison
 * against the PDN index in the matching PDN entry will take place as an
 * additional condition for NAT hit.
 */
struct ipa_flt_rule {
	uint8_t retain_hdr;
	uint8_t to_uc;
	enum ipa_flt_action action;
	uint32_t rt_tbl_hdl;
	struct ipa_rule_attrib attrib;
	struct ipa_ipfltri_rule_eq eq_attrib;
	uint32_t rt_tbl_idx;
	uint8_t eq_attrib_type;
	uint8_t max_prio;
	uint8_t hashable;
	uint16_t rule_id;
	uint8_t set_metadata;
	uint8_t pdn_idx;
};

/**
 * struct ipa_flt_rule_v2 - attributes of a filtering rule
 * @retain_hdr: bool switch to instruct IPA core to add back to the packet
 *  the header removed as part of header removal
 * @to_uc: bool switch to pass packet to micro-controller
 * @action: action field
 * @rt_tbl_hdl: handle of table from "get"
 * @attrib: attributes of the rule
 * @eq_attrib: attributes of the rule in equation form (valid when
 * eq_attrib_type is true)
 * @rt_tbl_idx: index of RT table referred to by filter rule (valid when
 * eq_attrib_type is true and non-exception action)
 * @eq_attrib_type: true if equation level form used to specify attributes
 * @max_prio: bool switch. is this rule with Max priority? meaning on rule hit,
 *  IPA will use the rule and will not look for other rules that may have
 *  higher priority
 * @hashable: bool switch. is this rule hashable or not?
 *  ipa uses hashable rules to cache their hit results to be used in
 *  consecutive packets
 * @rule_id: rule_id to be assigned to the filter rule. In case client specifies
 *  rule_id as 0 the driver will assign a new rule_id
 * @set_metadata: bool switch. should metadata replacement at the NAT block
 *  take place?
 * @pdn_idx: if action is "pass to source\destination NAT" then a comparison
 * against the PDN index in the matching PDN entry will take place as an
 * additional condition for NAT hit.
 * @enable_stats: is true when we want to enable stats for this
 * flt rule.
 * @cnt_idx: if 0 means disable, otherwise use for index.
 * will be assigned by ipa driver.
 * @close_aggr_irq_mod: close aggregation/coalescing and close GSI
 *  interrupt moderation
 */
struct ipa_flt_rule_v2 {
	uint8_t retain_hdr;
	uint8_t to_uc;
	enum ipa_flt_action action;
	uint32_t rt_tbl_hdl;
	struct ipa_rule_attrib attrib;
	struct ipa_ipfltri_rule_eq eq_attrib;
	uint32_t rt_tbl_idx;
	uint8_t eq_attrib_type;
	uint8_t max_prio;
	uint8_t hashable;
	uint16_t rule_id;
	uint8_t set_metadata;
	uint8_t pdn_idx;
	uint8_t enable_stats;
	uint8_t cnt_idx;
	uint8_t close_aggr_irq_mod;
};

/**
 * enum ipa_hdr_l2_type - L2 header type
 * IPA_HDR_L2_NONE: L2 header which isn't Ethernet II and isn't 802_3
 * IPA_HDR_L2_ETHERNET_II: L2 header of type Ethernet II
 * IPA_HDR_L2_802_3: L2 header of type 802_3
 * IPA_HDR_L2_802_1Q: L2 header of type 802_1Q
 * IPA_HDR_L2_ETHERNET_II_AST: L2 header of type ETHERNET with AST update
 * IPA_HDR_L2_802_1Q_AST: L2 header of type 802_1Q with AST update
 */
enum ipa_hdr_l2_type {
	IPA_HDR_L2_NONE,
	IPA_HDR_L2_ETHERNET_II,
	IPA_HDR_L2_802_3,
	IPA_HDR_L2_802_1Q,
	IPA_HDR_L2_ETHERNET_II_AST,
	IPA_HDR_L2_802_1Q_AST,
};
#define IPA_HDR_L2_MAX (IPA_HDR_L2_802_1Q_AST + 1)

#define IPA_HDR_L2_802_1Q IPA_HDR_L2_802_1Q

#define IPA_HDR_L2_ETHERNET_II_AST IPA_HDR_L2_ETHERNET_II_AST

#define IPA_HDR_L2_802_1Q_AST IPA_HDR_L2_802_1Q_AST

/**
 * enum ipa_hdr_l2_type - Processing context type
 *
 * IPA_HDR_PROC_NONE:                   No processing context
 * IPA_HDR_PROC_ETHII_TO_ETHII:         Process Ethernet II to Ethernet II
 * IPA_HDR_PROC_ETHII_TO_802_3:         Process Ethernet II to 802_3
 * IPA_HDR_PROC_802_3_TO_ETHII:         Process 802_3 to Ethernet II
 * IPA_HDR_PROC_802_3_TO_802_3:         Process 802_3 to 802_3
 * IPA_HDR_PROC_L2TP_HEADER_ADD:
 * IPA_HDR_PROC_L2TP_HEADER_REMOVE:
 * IPA_HDR_PROC_ETHII_TO_ETHII_EX:      Process Ethernet II to Ethernet II with
 *                                      generic lengths of src and dst headers
 * IPA_HDR_PROC_L2TP_UDP_HEADER_ADD:    Process WLAN To Ethernet packets to
 *                                      add L2TP UDP header.
 * IPA_HDR_PROC_L2TP_UDP_HEADER_REMOVE: Process Ethernet To WLAN packets to
 *                                      remove L2TP UDP header.
 * IPA_HDR_PROC_SET_DSCP:
 * IPA_HDR_PROC_EoGRE_HEADER_ADD:       Add IPV[46] and GRE header
 * IPA_HDR_PROC_EoGRE_HEADER_REMOVE:    Remove IPV[46] and GRE header
 * IPA_HDR_PROC_WWAN_TO_ETHII_EX:		To update PCP value for E2E traffic.
 * IPA_HDR_PROC_GRE_HEADER_ADD,         Add IPV[46] and IP-GRE header
 * IPA_HDR_PROC_GRE_HEADER_REMOVE,      Remove IPV[46] and IP-GRE header
 */
enum ipa_hdr_proc_type {
	IPA_HDR_PROC_NONE,
	IPA_HDR_PROC_ETHII_TO_ETHII,
	IPA_HDR_PROC_ETHII_TO_802_3,
	IPA_HDR_PROC_802_3_TO_ETHII,
	IPA_HDR_PROC_802_3_TO_802_3,
	IPA_HDR_PROC_L2TP_HEADER_ADD,
	IPA_HDR_PROC_L2TP_HEADER_REMOVE,
	IPA_HDR_PROC_ETHII_TO_ETHII_EX,
	IPA_HDR_PROC_L2TP_UDP_HEADER_ADD,
	IPA_HDR_PROC_L2TP_UDP_HEADER_REMOVE,
	IPA_HDR_PROC_SET_DSCP,
	IPA_HDR_PROC_EoGRE_HEADER_ADD,
	IPA_HDR_PROC_EoGRE_HEADER_REMOVE,
	IPA_HDR_PROC_WWAN_TO_ETHII_EX,
	IPA_HDR_PROC_GRE_HEADER_ADD,
	IPA_HDR_PROC_GRE_HEADER_REMOVE
};
#define IPA_HDR_PROC_MAX (IPA_HDR_PROC_GRE_HEADER_REMOVE + 1)

/**
 * struct ipa_rt_rule - attributes of a routing rule
 * @dst: dst "client"
 * @hdr_hdl: handle to the dynamic header
	it is not an index or an offset
 * @hdr_proc_ctx_hdl: handle to header processing context. if it is provided
	hdr_hdl shall be 0
 * @attrib: attributes of the rule
 * @max_prio: bool switch. is this rule with Max priority? meaning on rule hit,
 *  IPA will use the rule and will not look for other rules that may have
 *  higher priority
 * @hashable: bool switch. is this rule hashable or not?
 *  ipa uses hashable rules to cache their hit results to be used in
 *  consecutive packets
 * @retain_hdr: bool switch to instruct IPA core to add back to the packet
 *  the header removed as part of header removal
 * @coalesce: bool to decide whether packets should be coalesced or not
 */
struct ipa_rt_rule {
	enum ipa_client_type dst;
	uint32_t hdr_hdl;
	uint32_t hdr_proc_ctx_hdl;
	struct ipa_rule_attrib attrib;
	uint8_t max_prio;
	uint8_t hashable;
	uint8_t retain_hdr;
	uint8_t coalesce;
};
#define IPA_RT_SUPPORT_COAL

/**
 * struct ipa_rt_rule_v2 - attributes of a routing rule
 * @dst: dst "client"
 * @hdr_hdl: handle to the dynamic header
	it is not an index or an offset
 * @hdr_proc_ctx_hdl: handle to header processing context. if it is provided
	hdr_hdl shall be 0
 * @attrib: attributes of the rule
 * @max_prio: bool switch. is this rule with Max priority? meaning on rule hit,
 *  IPA will use the rule and will not look for other rules that may have
 *  higher priority
 * @hashable: bool switch. is this rule hashable or not?
 *  ipa uses hashable rules to cache their hit results to be used in
 *  consecutive packets
 * @retain_hdr: bool switch to instruct IPA core to add back to the packet
 *  the header removed as part of header removal
 * @coalesce: bool to decide whether packets should be coalesced or not
 * @enable_stats: is true when we want to enable stats for this
 * rt rule.
 * @cnt_idx: if enable_stats is 1 and cnt_idx is 0, then cnt_idx
 * will be assigned by ipa driver.
 * @close_aggr_irq_mod: close aggregation/coalescing and close GSI
 *  interrupt moderation
 */
struct ipa_rt_rule_v2 {
	enum ipa_client_type dst;
	uint32_t hdr_hdl;
	uint32_t hdr_proc_ctx_hdl;
	struct ipa_rule_attrib attrib;
	uint8_t max_prio;
	uint8_t hashable;
	uint8_t retain_hdr;
	uint8_t coalesce;
	uint8_t enable_stats;
	uint8_t cnt_idx;
	uint8_t close_aggr_irq_mod;
};

/**
 * struct ipa_hdr_add - header descriptor includes in and out
 * parameters
 * @name: name of the header
 * @hdr: actual header to be inserted
 * @hdr_len: size of above header
 * @type: l2 header type
 * @is_partial: header not fully specified
 * @hdr_hdl: out parameter, handle to header, valid when status is 0
 * @status:	out parameter, status of header add operation,
 *		0 for success,
 *		-1 for failure
 * @is_eth2_ofst_valid: is eth2_ofst field valid?
 * @eth2_ofst: offset to start of Ethernet-II/802.3 header
 */
struct ipa_hdr_add {
	char name[IPA_RESOURCE_NAME_MAX];
	uint8_t hdr[IPA_HDR_MAX_SIZE];
	uint8_t hdr_len;
	enum ipa_hdr_l2_type type;
	uint8_t is_partial;
	uint32_t hdr_hdl;
	int status;
	uint8_t is_eth2_ofst_valid;
	uint16_t eth2_ofst;
};

/**
 * struct ipa_ioc_add_hdr - header addition parameters (support
 * multiple headers and commit)
 * @commit: should headers be written to IPA HW also?
 * @num_hdrs: num of headers that follow
 * @ipa_hdr_add hdr:	all headers need to go here back to
 *			back, no pointers
 */
struct ipa_ioc_add_hdr {
	uint8_t commit;
	uint8_t num_hdrs;
	struct ipa_hdr_add hdr[0];
};

/**
 * struct ipa_l2tp_header_add_procparams -
 * @eth_hdr_retained: Specifies if Ethernet header is retained or not
 * @input_ip_version: Specifies if Input header is IPV4(0) or IPV6(1)
 * @output_ip_version: Specifies if template header is IPV4(0) or IPV6(1)
 * @single_pass: Specifies if second pass is required or not
 */
struct ipa_l2tp_header_add_procparams {
	__u32 eth_hdr_retained:1;
	__u32 input_ip_version:1;
	__u32 output_ip_version:1;
	__u32 second_pass:1;
	__u32 reserved:28;
	__u32 padding;
};

/**
 * struct ipa_l2tp_header_remove_procparams -
 * @hdr_len_remove: Specifies how much of the header needs to
		be removed in bytes
 * @eth_hdr_retained: Specifies if Ethernet header is retained or not
 * @hdr_ofst_pkt_size_valid: Specifies if the Header offset is valid
 * @hdr_ofst_pkt_size: If hdr_ofst_pkt_size_valid =1, this indicates where the
		packet size field (2bytes) resides
 * @hdr_endianness: 0:little endian, 1:big endian
 */
struct ipa_l2tp_header_remove_procparams {
	uint32_t hdr_len_remove:8;
	uint32_t eth_hdr_retained:1;
	/* Following fields are valid if eth_hdr_retained =1 ( bridge mode) */
	uint32_t hdr_ofst_pkt_size_valid:1;
	uint32_t hdr_ofst_pkt_size:6;
	uint32_t hdr_endianness:1;
	uint32_t reserved:15;
};

/**
 * struct ipa_l2tp_hdr_proc_ctx_params -
 * @hdr_add_param: parameters for header add
 * @hdr_remove_param: parameters for header remove
 * @is_dst_pipe_valid: if dst pipe is valid
 * @dst_pipe: destination pipe
 */
struct ipa_l2tp_hdr_proc_ctx_params {
	struct ipa_l2tp_header_add_procparams hdr_add_param;
	struct ipa_l2tp_header_remove_procparams hdr_remove_param;
	uint8_t is_dst_pipe_valid;
	enum ipa_client_type dst_pipe;
};

#define IPA_EoGRE_MAX_PCP_IDX 8 /* From 802.1Q tag format (reflects IEEE P802.1p) */
#define IPA_EoGRE_MAX_VLAN    8 /* Supported number of VLAN id's (C-Tag when MPLSoGRE) */
#define IPA_GRE_MAX_S_VLAN    4 /* We'll support up to 4 vlans from the S-Tag */

/* vlan 12 bits + pcp 3 bites <-> dscp 6 bits */
struct IpaDscpVlanPcpMap_t {
	/*
	 * valid only lower 12 bits
	 */
	uint16_t vlan[IPA_EoGRE_MAX_VLAN];
	/*
	 * dscp[vlan][pcp], valid only lower 6 bits, using pcp as index
	 */
	uint8_t  dscp[IPA_EoGRE_MAX_VLAN][IPA_EoGRE_MAX_PCP_IDX];
	uint8_t  num_vlan;   /* indicate how many vlans valid vlan above */
	uint8_t  num_s_vlan; /* indicate how many vlans valid in s_vlan below */
	uint8_t  dscp_opt;   /* indicates if dscp is required or optional */
	uint8_t  tunnel_id;  /* tunnel id */
	/*
	 * The same lookup scheme, using vlan[] above, is used for
	 * generating the first index of mpls below; and in addition,
	 * we've added a similar array, s_vlan[], for generating the
	 * second index below.
	 */
	uint16_t s_vlan[IPA_GRE_MAX_S_VLAN];
	/*
	 * mpls[C-Tag vlan][S-Tag vlan] -> Only the lower 20 bits of the
	 * 32-bit mpls value will be used, since that's the size of the
	 * MPLS label component.
	 */
	uint32_t mpls[IPA_EoGRE_MAX_VLAN][IPA_GRE_MAX_S_VLAN];
	/*
	 * following three arrays are used for DL vlan tag lookup
	 * mpls_val_sorted is in ascending order, by mpls label values in mpls array
	 * vlan_c and vlan_s are vlan id values that are corresponding to the mpls label
	 */
	uint16_t del_add_vlan_id; /* vlan id to add or del */
	uint8_t  is_vlan_to_del_add; /* whether to add or del vlan? */
	uint8_t  num_mpls_val_sorted; /* num of elements in mpls_val_sorted */
	uint32_t mpls_val_sorted[IPA_EoGRE_MAX_VLAN * IPA_GRE_MAX_S_VLAN];
	uint16_t  vlan_c[IPA_EoGRE_MAX_VLAN * IPA_GRE_MAX_S_VLAN];
	uint16_t  vlan_s[IPA_EoGRE_MAX_VLAN * IPA_GRE_MAX_S_VLAN];
} __attribute__((packed));


#define MAX_VLAN_CONFIGURE 16
enum pkt_path {
	SW_PATH = 0,
	HW_PATH_OUTSIDE_TUNNEL = 1,
	HW_PATH_INSIDE_TUNNEL = 2
};

/* VLANID - Action - Tunnel_ID - MUX_ID */
struct singletag_mux_map_entry {
	uint16_t vlan_id;
	uint8_t mux_id;
	uint8_t pkt_path;
	uint32_t tunnel_id;
};

struct ipa_ioc_mux_mapping_table {
	struct singletag_mux_map_entry map_entries[MAX_VLAN_CONFIGURE];
};

/* Feature Type Supported Design*/
/* Cache all Design Support with Regular HPS for both EoGRE and MPLSoGRE tunnel */
#define DEFAULT_FEATURE 0x00
/* EoGRE to support Single Tag packet with new HPS */
#define SINGLE_TAG_FEATURE 0x01
/* MPLSoGRE to support Double Tag packet with new HPS */
#define DOUBLE_TAG_FEATURE 0x02
/* EoGRE to support UnTag packet with new HPS */
#define UNTAG_FEATURE 0x03

/* l2 header is adjusted for every hwp_pkt_next_action */
/* uc evaluate l2 header length and send packet to exception */
#define SW_PATH_ADJ_L2_EXCEPTION 0x00
/* uc evaluate l2 header length and send packet to 2nd pass */
#define HW_PATH_ADJ_L2_RESUME_2ND_PASS 0x01
/* uc evaluate l2 header length, update the metadata and send packet to 2nd pass */
#define HW_PATH_ADJ_L2_METADATA_UPDATE_RESUME_2ND_PASS 0x02
/* uc evaluate l2 header length, add outer header and send packet to 2nd pass */
#define HW_PATH_ADJ_L2_ADD_TUNNEL_RESUME_2ND_PASS 0x03
/* uc evaluate l2 header, update metadata, add outer header and send packet to 2nd pass */
#define HW_PATH_ADJ_L2_ADD_TUNNEL_WITH_METADATA_UPDATE_RESUME_2ND_PASS 0x04

/* untagged packet configuration */
struct untag_pkt_config_t {
	/* packet action that should follow untag packet */
	uint32_t action_configured;
	/* pdn from which untag packet should transfer */
	uint8_t mux_id;
	/* flag if 1=>pkt_with_option_hdr 0=>pkt_without_option_hdr */
	uint8_t is_v6_options_hdr_present;
	uint16_t pad0; /*for alignment*/
	/* lower 32 bit of tunnel header address */
	uint32_t *tunnel_template_addr;
	uint32_t pad1; /*for alignment*/
} __attribute__((packed));


/* vlanid - action - tunnel_id - mux_id */
struct singletag_mux_mapping_table_t {
	/* multi tunnel purpose */
	uint16_t vlan_id_start;
	uint16_t vlan_id_end;
	uint32_t action_configured;
	/* pdn from which untag packet should transfer */
	uint8_t mux_id;
	/* flag if 1=>pkt_with_option_hdr 0=>pkt_without_option_hdr */
	uint8_t is_v6_options_hdr_present;
	uint16_t tunnel_id;/* tunnel_id */
	uint32_t *tunnel_template_addr;
} __attribute__((packed));

struct doubletag_mux_mapping_table_t {
	/* multi tunnel purpose */
	uint16_t stag_id_start;
	uint16_t stag_id_end;
	uint16_t ctag_id_start;
	uint16_t ctag_id_end;
	uint32_t action_configured;
	/* pdn from which untag packet should transfer */
	uint8_t mux_id;
	/* flag if 1=>pkt_with_option_hdr 0=>pkt_without_option_hdr */
	uint8_t is_v6_options_hdr_present;
	uint16_t pad0; /*for alignment*/
	uint32_t *tunnel_template_addr;
	uint32_t pad1; /*for alignment*/
} __attribute__((packed));

/* max template side pass to uc */
#define MAX_TEMPLATE_SIZE 64
/* max number of tunnel to support ie: per PDN two tunnel (2*8)*/
#define MAX_TUNNEL_SUPPORT 16

/* @tunnel_protocols_config_table_t: Config tbl for uC
 * @untagged_mapping_table : Store the untag tunnel info.
 * @num_of_single_tag_configs : no of active tunnel in single tag config.
 * @feature_mode: which tunnel feature is enabled.
 * @tunnel_id: Which tunnel info receive from ipacm.
 * @is_tunnel_id_to_del: whether tunnel to delete.
 * @singletag_mux_mapping_table: Store tunnel info for active tunnels.
 * @num_of_double_tag_configs: no of active tunnel in double tag config.
 * @doubletag_mux_mapping_table: Store double tag tunnel info.
 */
struct tunnel_protocols_config_table_t {
	struct untag_pkt_config_t untagged_mapping_table;
	uint8_t num_of_single_tag_configs;
	uint8_t feature_mode;
	uint16_t tunnel_id;
	uint32_t is_tunnel_id_to_del;
	/* table for single tag pkt */
	struct singletag_mux_mapping_table_t singletag_mux_mapping_table[MAX_TUNNEL_SUPPORT];
	uint8_t num_of_double_tag_configs;
	uint8_t pad3; /*for alignment*/
	uint16_t pad4; /*for alignment*/
	uint32_t pad5; /*for alignment*/
	/* table for double tag pkt */
	struct doubletag_mux_mapping_table_t doubletag_mux_mapping_table[MAX_TUNNEL_SUPPORT];
};

/* ioctl tunnel configuration table */

struct ipa_ioc_tunnel_template_info {
	uint8_t template_header[MAX_TEMPLATE_SIZE];
	uint32_t template_len;
	uint32_t template_type;
	/*tunnel configuration table*/
	struct tunnel_protocols_config_table_t tunnel_config;
};

/**
 * struct ipa_exception
 *
 * This structure is used to generate an exception filter rule (see
 * exception_list in struct ipa_ipgre_info).
 *
 * NOTE:
 *
 *   When generating the exception list, generate them from the
 *   perepctive of the UL data flow.  The inner workings of the system
 *   will generate the complimentary DL rule, if necessary.  For
 *   example, UL TCP or UDP source/destination ports will have the
 *   complimentary DL rule generated with the addresses and ports
 *   reversed.
 *
 * For finding/matching @value at @field.
 *
 * Please always set @inner_iptype even when looking for an element in
 * an Ethernet header.  In that case, inner_iptype would be set to the
 * ip header type following the Ethernet header.
 */
struct ipa_exception {
	enum ipa_exception_type  field;
	uint32_t                 value;
	enum ipa_ip_type         inner_iptype;
} __attribute__((packed));

#define IPA_MAX_EXCEPTIONS 10  /* Max exception rule tuples */

struct ipa_ipgre_info {
	/*
	 * GRE tunnel's ip address type.
	 */
	enum ipa_ip_type iptype;
	/*
	 * If GRE tunnel is ipv4, then address goes here.
	 */
	uint32_t ipv4_src;
	uint32_t ipv4_dst;
	/*
	 * Else if GRE tunnel is ipv6, then address goes here.
	 */
	uint32_t ipv6_src[4];
	uint32_t ipv6_dst[4];
	/*
	 * If running MPLS over GRE, please provide mpls header value
	 * here.
	 */
	uint32_t mpls_protocol;
	/*
	 * GRE header value.
	 */
	uint16_t gre_protocol;
	/* If v6 tunnel: option header enabled then set "true"
	 * If v4 tunnel: option header enabled then set "false"
	 */
	uint8_t ipv6_option_hdr_enabled;
	/*
	 * The number of valid elements in, and the accompanying
	 * exception_list, below
	 */
	uint8_t num_exceptions;
	struct ipa_exception exception_list[IPA_MAX_EXCEPTIONS];
} __attribute__((packed));

struct ipa_ioc_eogre_info {
	/* ip and gre info */
	struct ipa_ipgre_info ipgre_info;
	/* mapping info */
	struct IpaDscpVlanPcpMap_t map_info;
};

/**
 * struct ipa_eogre_header_add_procparams -
 * @eth_hdr_retained:  Specifies if Ethernet header is retained or not
 * @input_ip_version:  Specifies if Input header is IPV4(0) or IPV6(1)
 * @output_ip_version: Specifies if template header's outer IP is IPV4(0) or IPV6(1)
 * @second_pass:       Specifies if the data should be processed again.
 * @is_mpls:           Specifies if ucp cmd is for legacy EoGRE(0) or MPLSoGRE(1)
 * @tag_remove_len:    Specifies amount to be removed for the tags
 */
struct ipa_eogre_header_add_procparams {
	uint32_t eth_hdr_retained :1;
	uint32_t input_ip_version :1;
	uint32_t output_ip_version :1;
	uint32_t second_pass :1;
	uint32_t is_mpls :1;
	uint32_t tag_remove_len :4;
	uint32_t reserved :23;
};

/**
 * struct ipa_eogre_header_remove_procparams -
 * @hdr_len_remove:    Specifies how much (in bytes) of the header needs
 *                     to be removed
 * @outer_ip_version:  Specifies if template header's outer IP is IPV4(0) or IPV6(1)
 * @is_mpls:           Specifies if ucp cmd is for legacy EoGRE(0) or MPLSoGRE(1)
 * @tag_add_len:       Specifies amount to be added for the tags
 */
struct ipa_eogre_header_remove_procparams {
	uint32_t hdr_len_remove :8; /* 44 bytes for IPV6, 24 for IPV4 */
	uint32_t outer_ip_version :1;
	uint32_t is_mpls :1;
	uint32_t tag_add_len :4;
	uint32_t reserved :18;
};

/**
 * struct ipa_eogre_hdr_proc_ctx_params -
 * @hdr_add_param: parameters for header add
 * @hdr_remove_param: parameters for header remove
 */
struct ipa_eogre_hdr_proc_ctx_params {
	struct ipa_eogre_header_add_procparams hdr_add_param;
	struct ipa_eogre_header_remove_procparams hdr_remove_param;
};


/**
 * struct ipa_gre_header_add_procparams -
 * @eth_hdr_retained:  Specifies if Ethernet header is retained or not
 * @input_ip_version:  Specifies if Input header is IPV4(0) or IPV6(1)
 * @output_ip_version: Specifies if template header's outer IP is IPV4(0) or IPV6(1)
 * @second_pass:       Specifies if the data should be processed again.
 * @is_mpls:           Specifies if ucp cmd is for legacy EoGRE(0) or MPLSoGRE(1)
 * @tag_remove_len:    Specifies amount to be removed for the tags
 */
struct ipa_gre_header_add_procparams {
	uint32_t eth_hdr_retained :1;
	uint32_t input_ip_version :1;
	uint32_t output_ip_version :1;
	uint32_t second_pass :1;
	uint32_t is_mpls :1;
	uint32_t tag_remove_len :4;
	uint32_t reserved :23;
};

/**
 * struct ipa_gre_header_remove_procparams -
 * @hdr_len_remove:    Specifies how much (in bytes) of the header needs
 *                     to be removed
 * @outer_ip_version:  Specifies if template header's outer IP is IPV4(0) or IPV6(1)
 * @is_mpls:           Specifies if ucp cmd is for legacy EoGRE(0) or MPLSoGRE(1)
 * @tag_add_len:       Specifies amount to be added for the tags
 */
struct ipa_gre_header_remove_procparams {
	uint32_t hdr_len_remove :8; /* 44 bytes for IPV6, 24 for IPV4 */
	uint32_t outer_ip_version :1;
	uint32_t is_mpls :1;
	uint32_t tag_add_len :4;
	uint32_t reserved :18;
};

/**
 * struct ipa_gre_hdr_proc_ctx_params -
 * @hdr_add_param: parameters for header add
 * @hdr_remove_param: parameters for header remove
 */
struct ipa_gre_hdr_proc_ctx_params {
	struct ipa_gre_header_add_procparams hdr_add_param;
	struct ipa_gre_header_remove_procparams hdr_remove_param;
};

/**
 * struct ipa_eth_II_to_eth_II_ex_procparams -
 * @input_ethhdr_negative_offset: Specifies where the ethernet hdr offset is
 *	(in bytes) from the start of the input IP hdr
 * @output_ethhdr_negative_offset: Specifies where the ethernet hdr offset is
 *	(in bytes) from the end of the template hdr
 * @output_dscp_pcp_update: Specifies if VLAN PCP needs to be updated based on
 *                         DSCP<->PCP mapping table.
 * @reserved: for future use
 */
struct ipa_eth_II_to_eth_II_ex_procparams {
	uint32_t input_ethhdr_negative_offset : 8;
	uint32_t output_ethhdr_negative_offset : 8;
	uint32_t output_dscp_pcp_update : 1;
	uint32_t reserved : 15;
};

/**
 * struct ipa_wwan_to_eth_II_ex_procparams -
 * @input_ethhdr_negative_offset: Specifies where the ethernet hdr offset is
 *	(in bytes) from the start of the input IP hdr
 * @output_ethhdr_negative_offset: Specifies where the ethernet hdr offset is
 *	(in bytes) from the end of the template hdr
 * @output_dscp_pcp_update: Specifies if VLAN PCP needs to be updated based on
 *                         DSCP<->PCP mapping table.
 * @input_ethhdr_valid: Specifies whether input ethernet header is valid or not.
 * @reserved: for future use
 */
struct ipa_wwan_to_eth_II_ex_procparams {
	uint32_t input_ethhdr_negative_offset : 8;
	uint32_t output_ethhdr_negative_offset : 8;
	uint32_t output_dscp_pcp_update : 1;
	uint32_t input_ethhdr_valid : 1;
	uint32_t reserved : 14;
};

#define L2TP_USER_SPACE_SPECIFY_DST_PIPE

/**
 * struct ipa_hdr_proc_ctx_add - processing context descriptor includes
 * in and out parameters
 * @type: processing context type
 * @hdr_hdl: in parameter, handle to header
 * @l2tp_params: l2tp parameters
 * @eogre_params: eogre parameters
 * @generic_params: generic proc_ctx params
 * @generic_params_v2: generic proc_ctx params for bridging
 * @proc_ctx_hdl: out parameter, handle to proc_ctx, valid when status is 0
 * @status:	out parameter, status of header add operation,
 *		0 for success,
 *		-1 for failure
 */
struct ipa_hdr_proc_ctx_add {
	enum ipa_hdr_proc_type type;
	uint32_t hdr_hdl;
	uint32_t proc_ctx_hdl;
	int status;
	struct ipa_l2tp_hdr_proc_ctx_params l2tp_params;
	struct ipa_eogre_hdr_proc_ctx_params eogre_params;
	struct ipa_eth_II_to_eth_II_ex_procparams generic_params;
	struct ipa_wwan_to_eth_II_ex_procparams generic_params_v2;
	struct ipa_gre_hdr_proc_ctx_params gre_params;
};

#define IPA_L2TP_HDR_PROC_SUPPORT

/**
 * struct ipa_ioc_add_hdr - processing context addition parameters (support
 * multiple processing context and commit)
 * @commit: should processing context be written to IPA HW also?
 * @num_proc_ctxs: num of processing context that follow
 * @proc_ctx:	all processing context need to go here back to
 *			back, no pointers
 */
struct ipa_ioc_add_hdr_proc_ctx {
	uint8_t commit;
	uint8_t num_proc_ctxs;
	struct ipa_hdr_proc_ctx_add proc_ctx[0];
};

/**
 * struct ipa_ioc_copy_hdr - retrieve a copy of the specified
 * header - caller can then derive the complete header
 * @name: name of the header resource
 * @hdr:	out parameter, contents of specified header,
 *	valid only when ioctl return val is non-negative
 * @hdr_len: out parameter, size of above header
 *	valid only when ioctl return val is non-negative
 * @type: l2 header type
 *	valid only when ioctl return val is non-negative
 * @is_partial:	out parameter, indicates whether specified header is partial
 *		valid only when ioctl return val is non-negative
 * @is_eth2_ofst_valid: is eth2_ofst field valid?
 * @eth2_ofst: offset to start of Ethernet-II/802.3 header
 */
struct ipa_ioc_copy_hdr {
	char name[IPA_RESOURCE_NAME_MAX];
	uint8_t hdr[IPA_HDR_MAX_SIZE];
	uint8_t hdr_len;
	enum ipa_hdr_l2_type type;
	uint8_t is_partial;
	uint8_t is_eth2_ofst_valid;
	uint16_t eth2_ofst;
};

/**
 * struct ipa_ioc_get_hdr - header entry lookup parameters, if lookup was
 * successful caller must call put to release the reference count when done
 * @name: name of the header resource
 * @hdl:	out parameter, handle of header entry
 *		valid only when ioctl return val is non-negative
 */
struct ipa_ioc_get_hdr {
	char name[IPA_RESOURCE_NAME_MAX];
	uint32_t hdl;
};

/**
 * struct ipa_hdr_del - header descriptor includes in and out
 * parameters
 *
 * @hdl: handle returned from header add operation
 * @status:	out parameter, status of header remove operation,
 *		0 for success,
 *		-1 for failure
 */
struct ipa_hdr_del {
	uint32_t hdl;
	int status;
};

/**
 * struct ipa_ioc_del_hdr - header deletion parameters (support
 * multiple headers and commit)
 * @commit: should headers be removed from IPA HW also?
 * @num_hdls: num of headers being removed
 * @ipa_hdr_del hdl: all handles need to go here back to back, no pointers
 */
struct ipa_ioc_del_hdr {
	uint8_t commit;
	uint8_t num_hdls;
	struct ipa_hdr_del hdl[0];
};

/**
 * struct ipa_hdr_proc_ctx_del - processing context descriptor includes
 * in and out parameters
 * @hdl: handle returned from processing context add operation
 * @status:	out parameter, status of header remove operation,
 *		0 for success,
 *		-1 for failure
 */
struct ipa_hdr_proc_ctx_del {
	uint32_t hdl;
	int status;
};

/**
 * ipa_ioc_del_hdr_proc_ctx - processing context deletion parameters (support
 * multiple headers and commit)
 * @commit: should processing contexts be removed from IPA HW also?
 * @num_hdls: num of processing contexts being removed
 * @ipa_hdr_proc_ctx_del hdl:	all handles need to go here back to back,
 *				no pointers
 */
struct ipa_ioc_del_hdr_proc_ctx {
	uint8_t commit;
	uint8_t num_hdls;
	struct ipa_hdr_proc_ctx_del hdl[0];
};

/**
 * struct ipa_rt_rule_add - routing rule descriptor includes in
 * and out parameters
 * @rule: actual rule to be added
 * @at_rear:	add at back of routing table, it is NOT possible to add rules at
 *		the rear of the "default" routing tables
 * @rt_rule_hdl: output parameter, handle to rule, valid when status is 0
 * @status:	output parameter, status of routing rule add operation,
 *		0 for success,
 *		-1 for failure
 */
struct ipa_rt_rule_add {
	struct ipa_rt_rule rule;
	uint8_t at_rear;
	uint32_t rt_rule_hdl;
	int status;
};

/**
 * struct ipa_rt_rule_add_v2 - routing rule descriptor includes
 * in and out parameters
 * @rule: actual rule to be added
 * @at_rear:	add at back of routing table, it is NOT possible to add rules at
 *		the rear of the "default" routing tables
 * @rt_rule_hdl: output parameter, handle to rule, valid when status is 0
 * @status:	output parameter, status of routing rule add operation,
 *		0 for success,
 *		-1 for failure
 */
struct ipa_rt_rule_add_v2 {
	uint8_t at_rear;
	uint32_t rt_rule_hdl;
	int status;
	struct ipa_rt_rule_v2 rule;
};


/**
 * struct ipa_ioc_add_rt_rule - routing rule addition parameters (supports
 * multiple rules and commit);
 *
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @rt_tbl_name: name of routing table resource
 * @num_rules: number of routing rules that follow
 * @ipa_rt_rule_add rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_add_rt_rule {
	uint8_t commit;
	enum ipa_ip_type ip;
	char rt_tbl_name[IPA_RESOURCE_NAME_MAX];
	uint8_t num_rules;
	struct ipa_rt_rule_add rules[0];
};

/**
 * struct ipa_ioc_add_rt_rule_v2 - routing rule addition
 * parameters (supports multiple rules and commit);
 *
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @rt_tbl_name: name of routing table resource
 * @num_rules: number of routing rules that follow
 * @rule_add_size: sizeof(struct ipa_rt_rule_add_v2)
 * @reserved1: reserved bits for alignment
 * @reserved2: reserved bits for alignment
 * @ipa_rt_rule_add rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_add_rt_rule_v2 {
	uint8_t commit;
	enum ipa_ip_type ip;
	char rt_tbl_name[IPA_RESOURCE_NAME_MAX];
	uint8_t num_rules;
	uint32_t rule_add_size;
	uint32_t reserved1;
	uint8_t reserved2;
	uint64_t rules;
};

/**
 * struct ipa_ioc_add_rt_rule_after - routing rule addition after a specific
 * rule parameters(supports multiple rules and commit);
 *
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @rt_tbl_name: name of routing table resource
 * @num_rules: number of routing rules that follow
 * @add_after_hdl: the rules will be added after this specific rule
 * @ipa_rt_rule_add rules: all rules need to go back to back here, no pointers
 *			   at_rear field will be ignored when using this IOCTL
 */
struct ipa_ioc_add_rt_rule_after {
	uint8_t commit;
	enum ipa_ip_type ip;
	char rt_tbl_name[IPA_RESOURCE_NAME_MAX];
	uint8_t num_rules;
	uint32_t add_after_hdl;
	struct ipa_rt_rule_add rules[0];
};

/**
 * struct ipa_ioc_add_rt_rule_after_v2 - routing rule addition
 * after a specific rule parameters(supports multiple rules and
 * commit);
 *
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @rt_tbl_name: name of routing table resource
 * @num_rules: number of routing rules that follow
 * @add_after_hdl: the rules will be added after this specific rule
 * @rule_add_size: sizeof(struct ipa_rt_rule_add_v2)
 * @reserved: reserved bits for alignment
 * @ipa_rt_rule_add rules: all rules need to go back to back here, no pointers
 *			   at_rear field will be ignored when using this IOCTL
 */
struct ipa_ioc_add_rt_rule_after_v2 {
	uint8_t commit;
	enum ipa_ip_type ip;
	char rt_tbl_name[IPA_RESOURCE_NAME_MAX];
	uint8_t num_rules;
	uint32_t add_after_hdl;
	uint32_t rule_add_size;
	uint8_t reserved;
	uint64_t rules;
};

/**
 * struct ipa_rt_rule_mdfy - routing rule descriptor includes
 * in and out parameters
 * @rule: actual rule to be added
 * @rt_rule_hdl: handle to rule which supposed to modify
 * @status:	output parameter, status of routing rule modify  operation,
 *		0 for success,
 *		-1 for failure
 *
 */
struct ipa_rt_rule_mdfy {
	struct ipa_rt_rule rule;
	uint32_t rt_rule_hdl;
	int status;
};

/**
 * struct ipa_rt_rule_mdfy_v2 - routing rule descriptor includes
 * in and out parameters
 * @rule: actual rule to be added
 * @rt_rule_hdl: handle to rule which supposed to modify
 * @status:	output parameter, status of routing rule modify  operation,
 *		0 for success,
 *		-1 for failure
 *
 */
struct ipa_rt_rule_mdfy_v2 {
	uint32_t rt_rule_hdl;
	int status;
	struct ipa_rt_rule_v2 rule;
};

/**
 * struct ipa_ioc_mdfy_rt_rule - routing rule modify parameters (supports
 * multiple rules and commit)
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @num_rules: number of routing rules that follow
 * @rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_mdfy_rt_rule {
	uint8_t commit;
	enum ipa_ip_type ip;
	uint8_t num_rules;
	struct ipa_rt_rule_mdfy rules[0];
};

/**
 * struct ipa_ioc_mdfy_rt_rule_v2 - routing rule modify
 * parameters (supports multiple rules and commit)
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @num_rules: number of routing rules that follow
 * @rule_mdfy_size: sizeof(struct ipa_rt_rule_mdfy_v2)
 * @reserved: reserved bits for alignment
 * @rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_mdfy_rt_rule_v2 {
	uint8_t commit;
	enum ipa_ip_type ip;
	uint8_t num_rules;
	uint32_t rule_mdfy_size;
	uint8_t reserved;
	uint64_t rules;
};

/**
 * struct ipa_rt_rule_del - routing rule descriptor includes in
 * and out parameters
 * @hdl: handle returned from route rule add operation
 * @status:	output parameter, status of route rule delete operation,
 *		0 for success,
 *		-1 for failure
 */
struct ipa_rt_rule_del {
	uint32_t hdl;
	int status;
};

/**
 * struct ipa_rt_rule_add_ext - routing rule descriptor includes in
 * and out parameters
 * @rule: actual rule to be added
 * @at_rear:	add at back of routing table, it is NOT possible to add rules at
 *		the rear of the "default" routing tables
 * @rt_rule_hdl: output parameter, handle to rule, valid when status is 0
 * @status:	output parameter, status of routing rule add operation,
 * @rule_id: rule_id to be assigned to the routing rule. In case client
 *  specifies rule_id as 0 the driver will assign a new rule_id
 *		0 for success,
 *		-1 for failure
 */
struct ipa_rt_rule_add_ext {
	struct ipa_rt_rule rule;
	uint8_t at_rear;
	uint32_t rt_rule_hdl;
	int status;
	uint16_t rule_id;
};

/**
 * struct ipa_rt_rule_add_ext_v2 - routing rule descriptor
 * includes in and out parameters
 * @rule: actual rule to be added
 * @at_rear:	add at back of routing table, it is NOT possible to add rules at
 *		the rear of the "default" routing tables
 * @rt_rule_hdl: output parameter, handle to rule, valid when status is 0
 * @status:	output parameter, status of routing rule add operation,
 * @rule_id: rule_id to be assigned to the routing rule. In case client
 *  specifies rule_id as 0 the driver will assign a new rule_id
 *		0 for success,
 *		-1 for failure
 */
struct ipa_rt_rule_add_ext_v2 {
	uint8_t at_rear;
	uint32_t rt_rule_hdl;
	int status;
	uint16_t rule_id;
	struct ipa_rt_rule_v2 rule;
};

/**
 * struct ipa_ioc_add_rt_rule_ext - routing rule addition
 * parameters (supports multiple rules and commit with rule_id);
 *
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @rt_tbl_name: name of routing table resource
 * @num_rules: number of routing rules that follow
 * @ipa_rt_rule_add_ext rules: all rules need to go back to back here,
 *  no pointers
 */
struct ipa_ioc_add_rt_rule_ext {
	uint8_t commit;
	enum ipa_ip_type ip;
	char rt_tbl_name[IPA_RESOURCE_NAME_MAX];
	uint8_t num_rules;
	struct ipa_rt_rule_add_ext rules[0];
};

/**
 * struct ipa_ioc_add_rt_rule_ext_v2 - routing rule addition
 * parameters (supports multiple rules and commit with rule_id);
 *
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @rt_tbl_name: name of routing table resource
 * @num_rules: number of routing rules that follow
 * @rule_add_ext_size: sizeof(struct ipa_rt_rule_add_ext_v2)
 * @reserved1: reserved bits for alignment
 * @reserved2: reserved bits for alignment
 * @ipa_rt_rule_add_ext rules: all rules need to go back to back here,
 *  no pointers
 */
struct ipa_ioc_add_rt_rule_ext_v2 {
	uint8_t commit;
	enum ipa_ip_type ip;
	char rt_tbl_name[IPA_RESOURCE_NAME_MAX];
	uint8_t num_rules;
	uint32_t rule_add_ext_size;
	uint32_t reserved1;
	uint8_t reserved2;
	uint64_t rules;
};


/**
 * struct ipa_ioc_del_rt_rule - routing rule deletion parameters (supports
 * multiple headers and commit)
 * @commit: should rules be removed from IPA HW also?
 * @ip: IP family of rules
 * @num_hdls: num of rules being removed
 * @ipa_rt_rule_del hdl: all handles need to go back to back here, no pointers
 */
struct ipa_ioc_del_rt_rule {
	uint8_t commit;
	enum ipa_ip_type ip;
	uint8_t num_hdls;
	struct ipa_rt_rule_del hdl[0];
};

/**
 * struct ipa_ioc_get_rt_tbl_indx - routing table index lookup parameters
 * @ip: IP family of table
 * @name: name of routing table resource
 * @index:	output parameter, routing table index, valid only when ioctl
 *		return val is non-negative
 */
struct ipa_ioc_get_rt_tbl_indx {
	enum ipa_ip_type ip;
	char name[IPA_RESOURCE_NAME_MAX];
	uint32_t idx;
};

/**
 * struct ipa_flt_rule_add - filtering rule descriptor includes
 * in and out parameters
 * @rule: actual rule to be added
 * @at_rear: add at back of filtering table?
 * @flt_rule_hdl: out parameter, handle to rule, valid when status is 0
 * @status:	output parameter, status of filtering rule add   operation,
 *		0 for success,
 *		-1 for failure
 *
 */
struct ipa_flt_rule_add {
	struct ipa_flt_rule rule;
	uint8_t at_rear;
	uint32_t flt_rule_hdl;
	int status;
};

/**
 * struct ipa_flt_rule_add_v2 - filtering rule descriptor
 * includes in and out parameters
 * @rule: actual rule to be added
 * @at_rear: add at back of filtering table?
 * @flt_rule_hdl: out parameter, handle to rule, valid when status is 0
 * @status:	output parameter, status of filtering rule add   operation,
 *		0 for success,
 *		-1 for failure
 *
 */
struct ipa_flt_rule_add_v2 {
	uint8_t at_rear;
	uint32_t flt_rule_hdl;
	int status;
	struct ipa_flt_rule_v2 rule;
};

/**
 * struct ipa_ioc_add_flt_rule - filtering rule addition parameters (supports
 * multiple rules and commit)
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @ep:	which "clients" pipe does this rule apply to?
 *	valid only when global is 0
 * @global: does this apply to global filter table of specific IP family
 * @num_rules: number of filtering rules that follow
 * @rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_add_flt_rule {
	uint8_t commit;
	enum ipa_ip_type ip;
	enum ipa_client_type ep;
	uint8_t global;
	uint8_t num_rules;
	struct ipa_flt_rule_add rules[0];
};

/**
 * struct ipa_ioc_add_flt_rule_v2 - filtering rule addition
 * parameters (supports multiple rules and commit)
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @ep:	which "clients" pipe does this rule apply to?
 *	valid only when global is 0
 * @global: does this apply to global filter table of specific IP family
 * @num_rules: number of filtering rules that follow
 * @flt_rule_size: sizeof(struct ipa_flt_rule_add_v2)
 * @reserved1: reserved bits for alignment
 * @reserved2: reserved bits for alignment
 * @reserved3: reserved bits for alignment
 * @rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_add_flt_rule_v2 {
	uint8_t commit;
	enum ipa_ip_type ip;
	enum ipa_client_type ep;
	uint8_t global;
	uint8_t num_rules;
	uint32_t flt_rule_size;
	uint32_t reserved1;
	uint16_t reserved2;
	uint8_t reserved3;
	uint64_t rules;
};


/**
 * struct ipa_ioc_add_flt_rule_after - filtering rule addition after specific
 * rule parameters (supports multiple rules and commit)
 * all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @ep:	which "clients" pipe does this rule apply to?
 * @num_rules: number of filtering rules that follow
 * @add_after_hdl: rules will be added after the rule with this handle
 * @rules: all rules need to go back to back here, no pointers. at rear field
 *	   is ignored when using this IOCTL
 */
struct ipa_ioc_add_flt_rule_after {
	uint8_t commit;
	enum ipa_ip_type ip;
	enum ipa_client_type ep;
	uint8_t num_rules;
	uint32_t add_after_hdl;
	struct ipa_flt_rule_add rules[0];
};

/**
 * struct ipa_ioc_add_flt_rule_after_v2 - filtering rule
 * addition after specific rule parameters (supports multiple
 * rules and commit) all rules MUST be added to same table
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @ep:	which "clients" pipe does this rule apply to?
 * @num_rules: number of filtering rules that follow
 * @add_after_hdl: rules will be added after the rule with this handle
 * @flt_rule_size: sizeof(struct ipa_flt_rule_add_v2)
 * @reserved: reserved bits for alignment
 * @rules: all rules need to go back to back here, no pointers. at rear field
 *	   is ignored when using this IOCTL
 */
struct ipa_ioc_add_flt_rule_after_v2 {
	uint8_t commit;
	enum ipa_ip_type ip;
	enum ipa_client_type ep;
	uint8_t num_rules;
	uint32_t add_after_hdl;
	uint32_t flt_rule_size;
	uint32_t reserved;
	uint64_t rules;
};

/**
 * struct ipa_flt_rule_mdfy - filtering rule descriptor includes
 * in and out parameters
 * @rule: actual rule to be added
 * @flt_rule_hdl: handle to rule
 * @status:	output parameter, status of filtering rule modify  operation,
 *		0 for success,
 *		-1 for failure
 *
 */
struct ipa_flt_rule_mdfy {
	struct ipa_flt_rule rule;
	uint32_t rule_hdl;
	int status;
};

/**
 * struct ipa_flt_rule_mdfy_v2 - filtering rule descriptor
 * includes in and out parameters
 * @rule: actual rule to be added
 * @flt_rule_hdl: handle to rule
 * @status:	output parameter, status of filtering rule modify  operation,
 *		0 for success,
 *		-1 for failure
 *
 */
struct ipa_flt_rule_mdfy_v2 {
	uint32_t rule_hdl;
	int status;
	struct ipa_flt_rule_v2 rule;
};

/**
 * struct ipa_ioc_mdfy_flt_rule - filtering rule modify parameters (supports
 * multiple rules and commit)
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @num_rules: number of filtering rules that follow
 * @rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_mdfy_flt_rule {
	uint8_t commit;
	enum ipa_ip_type ip;
	uint8_t num_rules;
	struct ipa_flt_rule_mdfy rules[0];
};

/**
 * struct ipa_ioc_mdfy_flt_rule_v2 - filtering rule modify
 * parameters (supports multiple rules and commit)
 * @commit: should rules be written to IPA HW also?
 * @ip: IP family of rule
 * @num_rules: number of filtering rules that follow
 * @rule_mdfy_size: sizeof(struct ipa_flt_rule_mdfy_v2)
 * @reserved: reserved bits for alignment
 * @rules: all rules need to go back to back here, no pointers
 */
struct ipa_ioc_mdfy_flt_rule_v2 {
	uint8_t commit;
	enum ipa_ip_type ip;
	uint8_t num_rules;
	uint32_t rule_mdfy_size;
	uint8_t reserved;
	uint64_t rules;
};

/**
 * struct ipa_flt_rule_del - filtering rule descriptor includes
 * in and out parameters
 *
 * @hdl: handle returned from filtering rule add operation
 * @status:	output parameter, status of filtering rule delete operation,
 *		0 for success,
 *		-1 for failure
 */
struct ipa_flt_rule_del {
	uint32_t hdl;
	int status;
};

/**
 * struct ipa_ioc_del_flt_rule - filtering rule deletion parameters (supports
 * multiple headers and commit)
 * @commit: should rules be removed from IPA HW also?
 * @ip: IP family of rules
 * @num_hdls: num of rules being removed
 * @hdl: all handles need to go back to back here, no pointers
 */
struct ipa_ioc_del_flt_rule {
	uint8_t commit;
	enum ipa_ip_type ip;
	uint8_t num_hdls;
	struct ipa_flt_rule_del hdl[0];
};

/**
 * struct ipa_ioc_get_rt_tbl - routing table lookup parameters, if lookup was
 * successful caller must call put to release the reference
 * count when done
 * @ip: IP family of table
 * @name: name of routing table resource
 * @htl:	output parameter, handle of routing table, valid only when ioctl
 *		return val is non-negative
 */
struct ipa_ioc_get_rt_tbl {
	enum ipa_ip_type ip;
	char name[IPA_RESOURCE_NAME_MAX];
	uint32_t hdl;
};

/**
 * struct ipa_ioc_query_intf - used to lookup number of tx and
 * rx properties of interface
 * @name: name of interface
 * @num_tx_props:	output parameter, number of tx properties
 *			valid only when ioctl return val is non-negative
 * @num_rx_props:	output parameter, number of rx properties
 *			valid only when ioctl return val is non-negative
 * @num_ext_props:	output parameter, number of ext properties
 *			valid only when ioctl return val is non-negative
 * @excp_pipe:		exception packets of this interface should be
 *			routed to this pipe
 */
struct ipa_ioc_query_intf {
	char name[IPA_RESOURCE_NAME_MAX];
	uint32_t num_tx_props;
	uint32_t num_rx_props;
	uint32_t num_ext_props;
	enum ipa_client_type excp_pipe;
};

/**
 * struct ipa_ioc_tx_intf_prop - interface tx property
 * @ip: IP family of routing rule
 * @attrib: routing rule
 * @dst_pipe: routing output pipe
 * @alt_dst_pipe: alternate routing output pipe
 * @hdr_name: name of associated header if any, empty string when no header
 * @hdr_l2_type: type of associated header if any, use NONE when no header
 */
struct ipa_ioc_tx_intf_prop {
	enum ipa_ip_type ip;
	struct ipa_rule_attrib attrib;
	enum ipa_client_type dst_pipe;
	enum ipa_client_type alt_dst_pipe;
	char hdr_name[IPA_RESOURCE_NAME_MAX];
	enum ipa_hdr_l2_type hdr_l2_type;
};

/**
 * struct ipa_ioc_query_intf_tx_props - interface tx propertie
 * @name: name of interface
 * @num_tx_props: number of TX properties
 * @tx[0]: output parameter, the tx properties go here back to back
 */
struct ipa_ioc_query_intf_tx_props {
	char name[IPA_RESOURCE_NAME_MAX];
	uint32_t num_tx_props;
	struct ipa_ioc_tx_intf_prop tx[0];
};

/**
 * struct ipa_ioc_ext_intf_prop - interface extended property
 * @ip: IP family of routing rule
 * @eq_attrib: attributes of the rule in equation form
 * @action: action field
 * @rt_tbl_idx: index of RT table referred to by filter rule
 * @mux_id: MUX_ID
 * @filter_hdl: handle of filter (as specified by provider of filter rule)
 * @is_xlat_rule: it is xlat flt rule or not
 */
struct ipa_ioc_ext_intf_prop {
	enum ipa_ip_type ip;
	struct ipa_ipfltri_rule_eq eq_attrib;
	enum ipa_flt_action action;
	uint32_t rt_tbl_idx;
	uint8_t mux_id;
	uint32_t filter_hdl;
	uint8_t is_xlat_rule;
	uint32_t rule_id;
	uint8_t is_rule_hashable;
#define IPA_V6_UL_WL_FIREWALL_HANDLE
	uint8_t replicate_needed;
};

/**
 * struct ipa_ioc_query_intf_ext_props - interface ext propertie
 * @name: name of interface
 * @num_ext_props: number of EXT properties
 * @ext[0]: output parameter, the ext properties go here back to back
 */
struct ipa_ioc_query_intf_ext_props {
	char name[IPA_RESOURCE_NAME_MAX];
	uint32_t num_ext_props;
	struct ipa_ioc_ext_intf_prop ext[0];
};

/**
 * struct ipa_ioc_rx_intf_prop - interface rx property
 * @ip: IP family of filtering rule
 * @attrib: filtering rule
 * @src_pipe: input pipe
 * @hdr_l2_type: type of associated header if any, use NONE when no header
 */
struct ipa_ioc_rx_intf_prop {
	enum ipa_ip_type ip;
	struct ipa_rule_attrib attrib;
	enum ipa_client_type src_pipe;
	enum ipa_hdr_l2_type hdr_l2_type;
};

/**
 * struct ipa_ioc_query_intf_rx_props - interface rx propertie
 * @name: name of interface
 * @num_rx_props: number of RX properties
 * @rx: output parameter, the rx properties go here back to back
 */
struct ipa_ioc_query_intf_rx_props {
	char name[IPA_RESOURCE_NAME_MAX];
	uint32_t num_rx_props;
	struct ipa_ioc_rx_intf_prop rx[0];
};

/**
 * struct ipa_ioc_nat_alloc_mem - nat table memory allocation
 * properties
 * @dev_name: input parameter, the name of table
 * @size: input parameter, size of table in bytes
 * @offset: output parameter, offset into page in case of system memory
 */
struct ipa_ioc_nat_alloc_mem {
	char dev_name[IPA_RESOURCE_NAME_MAX];
	size_t size;
	__kernel_off_t offset;
};

/**
 * struct ipa_ioc_nat_ipv6ct_table_alloc - NAT/IPv6CT table memory allocation
 * properties
 * @size: input parameter, size of table in bytes
 * @offset: output parameter, offset into page in case of system memory
 */
struct ipa_ioc_nat_ipv6ct_table_alloc {
	size_t size;
	__kernel_off_t offset;
};

/**
 * struct ipa_ioc_v4_nat_init - nat table initialization parameters
 * @tbl_index: input parameter, index of the table
 * @ipv4_rules_offset: input parameter, ipv4 rules address offset
 * @expn_rules_offset: input parameter, ipv4 expansion rules address offset
 * @index_offset: input parameter, index rules offset
 * @index_expn_offset: input parameter, index expansion rules offset
 * @table_entries: input parameter, ipv4 rules table number of entries
 * @expn_table_entries: input parameter, ipv4 expansion rules table number of
 *                      entries
 * @ip_addr: input parameter, public ip address
 * @mem_type: input parameter, type of memory the table resides in
 * @focus_change: input parameter, are we moving to/from sram or ddr
 */
struct ipa_ioc_v4_nat_init {
	uint8_t  tbl_index;
	uint32_t ipv4_rules_offset;
	uint32_t expn_rules_offset;

	uint32_t index_offset;
	uint32_t index_expn_offset;

	uint16_t table_entries;
	uint16_t expn_table_entries;
	uint32_t ip_addr;

	uint8_t  mem_type;
	uint8_t  focus_change;
};

/**
 * struct ipa_ioc_ipv6ct_init - IPv6CT table initialization parameters
 * @base_table_offset: input parameter, IPv6CT base table address offset
 * @expn_table_offset: input parameter, IPv6CT expansion table address offset
 * @table_entries: input parameter, IPv6CT table number of entries
 * @expn_table_entries: input parameter, IPv6CT expansion table number of
 *                      entries
 * @tbl_index: input parameter, index of the table
 */
struct ipa_ioc_ipv6ct_init {
	uint32_t base_table_offset;
	uint32_t expn_table_offset;
	uint16_t table_entries;
	uint16_t expn_table_entries;
	uint8_t tbl_index;
};

/**
 * struct ipa_ioc_v4_nat_del - nat table delete parameter
 * @table_index: input parameter, index of the table
 * @public_ip_addr: input parameter, public ip address
 */
struct ipa_ioc_v4_nat_del {
	uint8_t table_index;
	uint32_t public_ip_addr;
};

/**
 * struct ipa_ioc_nat_ipv6ct_table_del - NAT/IPv6CT table delete parameter
 * @table_index: input parameter, index of the table
 * @mem_type: input parameter, type of memory the table resides in
 */
struct ipa_ioc_nat_ipv6ct_table_del {
	uint8_t table_index;
	uint8_t mem_type;
};

/**
 * struct ipa_ioc_nat_dma_one - nat/ipv6ct dma command parameter
 * @table_index: input parameter, index of the table
 * @base_addr:	type of table, from which the base address of the table
 *		can be inferred
 * @offset: destination offset within the NAT table
 * @data: data to be written.
 */
struct ipa_ioc_nat_dma_one {
	uint8_t table_index;
	uint8_t base_addr;

	uint32_t offset;
	uint16_t data;

};

/**
 * struct ipa_ioc_nat_dma_cmd - To hold multiple nat/ipv6ct dma commands
 * @entries: number of dma commands in use
 * @dma: data pointer to the dma commands
 * @mem_type: input parameter, type of memory the table resides in
 */
struct ipa_ioc_nat_dma_cmd {
	uint8_t entries;
	uint8_t mem_type;
	struct ipa_ioc_nat_dma_one dma[0];
};

/**
 * struct ipa_ioc_nat_pdn_entry - PDN entry modification data
 * @pdn_index: index of the entry in the PDN config table to be changed
 * @public_ip: PDN's public ip
 * @src_metadata: PDN's source NAT metadata for metadata replacement
 * @dst_metadata: PDN's destination NAT metadata for metadata replacement
 */
struct ipa_ioc_nat_pdn_entry {
	uint8_t pdn_index;
	uint32_t public_ip;
	uint32_t src_metadata;
	uint32_t dst_metadata;
};

/**
 * struct ipa_ioc_vlan_iface_info - add vlan interface
 * @name: interface name
 * @vlan_id: VLAN ID
 */
struct ipa_ioc_vlan_iface_info {
	char name[IPA_RESOURCE_NAME_MAX];
	uint16_t vlan_id;
};

/**
 * enum ipa_l2tp_tunnel_type - IP or UDP
 */
enum ipa_l2tp_tunnel_type {
	IPA_L2TP_TUNNEL_IP = 1,
	IPA_L2TP_TUNNEL_UDP = 2
#define IPA_L2TP_TUNNEL_UDP IPA_L2TP_TUNNEL_UDP
};

/**
 * struct ipa_ioc_l2tp_vlan_mapping_info - l2tp->vlan mapping info
 * @iptype: l2tp tunnel IP type
 * @l2tp_iface_name: l2tp interface name
 * @l2tp_session_id: l2tp session id
 * @vlan_iface_name: vlan interface name
 * @tunnel_type: l2tp tunnel type
 * @src_port: UDP source port
 * @dst_port: UDP destination port
 * @mtu: MTU of the L2TP interface
 */
struct ipa_ioc_l2tp_vlan_mapping_info {
	enum ipa_ip_type iptype;
	char l2tp_iface_name[IPA_RESOURCE_NAME_MAX];
	uint8_t l2tp_session_id;
	char vlan_iface_name[IPA_RESOURCE_NAME_MAX];
	enum ipa_l2tp_tunnel_type tunnel_type;
	__u16 src_port;
	__u16 dst_port;
	__u16 mtu;
	__u8 padding;
};

/**
 * struct ipa_ioc_gsb_info - connect/disconnect
 * @name: interface name
 */
struct ipa_ioc_gsb_info {
	char name[IPA_RESOURCE_NAME_MAX];
};

#define QUERY_MAX_EP_PAIRS	2

#define IPA_USB0_EP_ID		11
#define IPA_USB1_EP_ID		12

#define IPA_PCIE0_EP_ID		21
#define IPA_PCIE1_EP_ID		22

#define IPA_ETH0_EP_ID		31
#define IPA_ETH1_EP_ID		32

enum ipa_peripheral_ep_type {
	IPA_DATA_EP_TYP_RESERVED = 0,
	IPA_DATA_EP_TYP_HSIC = 1,
	IPA_DATA_EP_TYP_HSUSB = 2,
	IPA_DATA_EP_TYP_PCIE = 3,
	IPA_DATA_EP_TYP_EMBEDDED = 4,
	IPA_DATA_EP_TYP_BAM_DMUX = 5,
	IPA_DATA_EP_TYP_ETH,
};

enum ipa_data_ep_prot_type {
	IPA_PROT_RMNET = 0,
	IPA_PROT_RMNET_CV2X = 1,
	IPA_PROT_MAX
};

struct ipa_ep_pair_info {
	__u32 consumer_pipe_num;
	__u32 producer_pipe_num;
	__u32 ep_id;
	__u32 padding;
};

/**
 * struct ipa_ioc_get_ep_info - query usb/pcie ep info
 * @ep_type: type USB/PCIE - i/p param
 * @max_ep_pairs: max number of ep_pairs (constant),
		(QUERY_MAX_EP_PAIRS)
 * @num_ep_pairs: number of ep_pairs - o/p param
 * @ep_pair_size: sizeof(ipa_ep_pair_info) * max_ep_pairs
 * @info: structure contains ep pair info
 * @teth_prot : RMNET/CV2X --i/p param
 * @teth_prot_valid - validity of i/p param protocol
 */
struct ipa_ioc_get_ep_info {
	enum ipa_peripheral_ep_type ep_type;
	__u32 ep_pair_size;
	__u8 max_ep_pairs;
	__u8 num_ep_pairs;
	__u16 padding;
	__u64 info;
	enum ipa_data_ep_prot_type teth_prot;
	__u8 teth_prot_valid;
};

/**
 * struct ipa_set_pkt_threshold
 * @pkt_threshold_enable: indicate pkt_thr enable or not
 * @pkt_threshold: if pkt_threshold_enable = true, given the values
 */
struct ipa_set_pkt_threshold {
	uint8_t pkt_threshold_enable;
	int pkt_threshold;
};

/**
 * struct ipa_ioc_set_pkt_threshold
 * @ioctl_ptr: has to be typecasted to (__u64)(uintptr_t)
 * @ioctl_data_size:
 * Eg: For ipa_set_pkt_threshold = sizeof(ipa_set_pkt_threshold)
 */
struct ipa_ioc_set_pkt_threshold {
	__u64 ioctl_ptr;
	__u32 ioctl_data_size;
	__u32 padding;
};

/**
 * struct ipa_ioc_wigig_fst_switch - switch between wigig and wlan
 * @netdev_name: wigig interface name
 * @client_mac_addr: client to switch between netdevs
 * @to_wigig: shall wlan client switch to wigig or the opposite?
 */
struct ipa_ioc_wigig_fst_switch {
	uint8_t netdev_name[IPA_RESOURCE_NAME_MAX];
	uint8_t client_mac_addr[IPA_MAC_ADDR_SIZE];
	int to_wigig;
};

/**
 * struct ipa_msg_meta - Format of the message meta-data.
 * @msg_type: the type of the message
 * @rsvd: reserved bits for future use.
 * @msg_len: the length of the message in bytes
 *
 * For push model:
 * Client in user-space should issue a read on the device (/dev/ipa) with a
 * sufficiently large buffer in a continuous loop, call will block when there is
 * no message to read. Upon return, client can read the ipa_msg_meta from start
 * of buffer to find out type and length of message
 * size of buffer supplied >= (size of largest message + size of metadata)
 *
 * For pull model:
 * Client in user-space can also issue a pull msg IOCTL to device (/dev/ipa)
 * with a payload containing space for the ipa_msg_meta and the message specific
 * payload length.
 * size of buffer supplied == (len of specific message  + size of metadata)
 */
struct ipa_msg_meta {
	uint8_t msg_type;
	uint8_t rsvd;
	uint16_t msg_len;
};

/**
 * struct ipa_wlan_msg - To hold information about wlan client
 * @name: name of the wlan interface
 * @mac_addr: mac address of wlan client
 * @if_index: netdev interface index
 * @ast_update: Boolean to indicate whether AST update is required or not
 *
 * wlan drivers need to pass name of wlan iface and mac address of
 * wlan client along with ipa_wlan_event, whenever a wlan client is
 * connected/disconnected/moved to power save/come out of power save
 */
struct ipa_wlan_msg {
	char name[IPA_RESOURCE_NAME_MAX];
	uint8_t mac_addr[IPA_MAC_ADDR_SIZE];
	int16_t if_index;
#define IPA_WDI_AST_UPDATE
	uint8_t ast_update;
};

/**
 * enum ipa_wlan_hdr_attrib_type - attribute type
 * in wlan client header
 *
 * WLAN_HDR_ATTRIB_MAC_ADDR: attrib type mac address
 * WLAN_HDR_ATTRIB_STA_ID: attrib type station id
 * WLAN_HDR_ATTRIB_TA_PEER_ID: ta peer id associated with mac
 */
enum ipa_wlan_hdr_attrib_type {
	WLAN_HDR_ATTRIB_MAC_ADDR,
	WLAN_HDR_ATTRIB_STA_ID,
	WLAN_HDR_ATTRIB_TA_PEER_ID
};
#define WLAN_HDR_ATTRIB_TA_PEER_ID WLAN_HDR_ATTRIB_TA_PEER_ID

/**
 * struct ipa_wlan_hdr_attrib_val - header attribute value
 * @attrib_type: type of attribute
 * @offset: offset of attribute within header
 * @u.mac_addr: mac address
 * @u.sta_id: station id
 * @u.ta_peer_id: ta peer id
 */
struct ipa_wlan_hdr_attrib_val {
	enum ipa_wlan_hdr_attrib_type attrib_type;
	uint8_t offset;
	union {
		uint8_t mac_addr[IPA_MAC_ADDR_SIZE];
		uint8_t sta_id;
		uint16_t ta_peer_id;
	} u;
};

/**
 * struct ipa_wlan_msg_ex - To hold information about wlan client
 * @name: name of the wlan interface
 * @num_of_attribs: number of attributes
 * @attrib_val: holds attribute values
 *
 * wlan drivers need to pass name of wlan iface and mac address
 * of wlan client or station id along with ipa_wlan_event,
 * whenever a wlan client is connected/disconnected/moved to
 * power save/come out of power save
 */
struct ipa_wlan_msg_ex {
	char name[IPA_RESOURCE_NAME_MAX];
	uint8_t num_of_attribs;
	struct ipa_wlan_hdr_attrib_val attribs[0];
};

/**
 * struct ipa_wigig_msg- To hold information about wigig event
 * @name: name of the wigig interface
 * @client_mac_addr: the relevant wigig client mac address
 * @ipa_client: TX pipe associated with the wigig client in case of connect
 * @to_wigig: FST switch direction wlan->wigig?
 */
struct ipa_wigig_msg {
	char name[IPA_RESOURCE_NAME_MAX];
	uint8_t client_mac_addr[IPA_MAC_ADDR_SIZE];
	union {
		enum ipa_client_type ipa_client;
		uint8_t to_wigig;
	} u;
};

struct ipa_ecm_msg {
	char name[IPA_RESOURCE_NAME_MAX];
	int ifindex;
};

/**
 * struct ipa_wan_msg - To hold information about wan client
 * @name: name of the wan interface
 *
 * CnE need to pass the name of default wan iface when connected/disconnected.
 * CNE need to pass the gw info in wlan AP+STA mode.
 * netmgr need to pass the name of wan eMBMS iface when connected.
 */
struct ipa_wan_msg {
	char upstream_ifname[IPA_RESOURCE_NAME_MAX];
	char tethered_ifname[IPA_RESOURCE_NAME_MAX];
	enum ipa_ip_type ip;
	uint32_t ipv4_addr_gw;
	uint32_t ipv6_addr_gw[IPA_WAN_MSG_IPv6_ADDR_GW_LEN];
};

/* uc activation command Ids */
#define IPA_SOCKSV5_ADD_COM_ID		15
#define IPA_IPv6_NAT_COM_ID		16

/**
 * ipa_kernel_tests_socksv5_uc_tmpl - uc activation entry info
 * @cmd_id: uc command id
 * @cmd_param: uC command param
 * @ipa_kernel_tests_ip_hdr_temp: ip header
 * @src_port: source port
 * @dst_port: destination port
 * @ipa_sockv5_mask: uc attribute mask for options/etc
 * @out_irs: 4B/4B Seq/Ack/SACK
 * @out_iss
 * @in_irs
 * @in_iss
 * @out_ircv_tsval: timestamp attributes
 * @in_ircv_tsecr
 * @out_ircv_tsecr
 * @in_ircv_tsval
 * @in_isnd_wscale: window scale attributes
 * @out_isnd_wscale
 * @in_ircv_wscale
 * @out_ircv_wscale
 * @direction: 1 for UL 0 for DL
 * @handle: uc activation table index
 */
struct ipa_kernel_tests_socksv5_uc_tmpl {
	/* direction 1 = UL, 0 = DL */
	__u8 direction;
	__u8 padding1;
	/* output: handle (index) */
	__u16 handle;
	__u16 cmd_id;
	__u16 padding2;
	__u32 cmd_param;

	__be32 ip_src_addr;
	__be32 ip_dst_addr;
	__be32 ipv6_src_addr[4];
	__be32 ipv6_dst_addr[4];

	/* 2B src/dst port */
	__u16 src_port;
	__u16 dst_port;

	/* attribute mask */
	__u32 ipa_sockv5_mask;

	/* required update 4B/4B Seq/Ack/SACK */
	__u32 out_irs;
	__u32 out_iss;
	__u32 in_irs;
	__u32 in_iss;

	/* option 10B: time-stamp */
	__u32 out_ircv_tsval;
	__u32 in_ircv_tsecr;
	__u32 out_ircv_tsecr;
	__u32 in_ircv_tsval;

	/* option 2B: window-scaling/dynamic */
	__u16 in_isnd_wscale : 4;
	__u16 out_isnd_wscale : 4;
	__u16 in_ircv_wscale : 4;
	__u16 out_ircv_wscale : 4;
	__u32 padding3;

};

/**
 * struct ipacm_socksv5_info - To hold information about socksv5 connections
 * @ip_type: ip type
 * @ipv4_src: ipv4 src address
 * @ipv4_dst: ipv4 dst address
 * @ipv6_src: ipv6 src address
 * @ipv6_dst: ipv6 dst address
 * @src_port: src port number
 * @dst_port: dst port number
 * @index: the uc activation tbl index
 */

struct ipacm_socksv5_info {
	/* ip-type */
	enum ipa_ip_type ip_type;

	/* ipv4 */
	__u32 ipv4_src;
	__u32 ipv4_dst;

	/* ipv6 */
	__u32 ipv6_src[4];
	__u32 ipv6_dst[4];

	/* 2B src/dst port */
	__u16 src_port;
	__u16 dst_port;

	/* uc-tbl index */
	__u16 index;
	__u16 padding;
};

/**
 * struct ipa_socksv5_msg - To hold information about socksv5 client
 * @ul_in: uplink connection info
 * @dl_in: downlink connection info
 * @handle: used for ipacm to distinguish connections
 *
 * CnE need to pass the name of default wan iface when connected/disconnected.
 * CNE need to pass the gw info in wlan AP+STA mode.
 * netmgr need to pass the name of wan eMBMS iface when connected.
 */
struct ipa_socksv5_msg {
	struct ipacm_socksv5_info ul_in;
	struct ipacm_socksv5_info dl_in;

	/* handle (index) */
	__u16 handle;
	__u16 padding;
};

/**
 * struct ipa_ioc_ipv6_nat_uc_act_entry - To hold information about IPv6 NAT
 *	uC entry
 * @cmd_id[in]: IPv6 NAT uC CMD ID - used for identifying uc activation type
 * @private_address_lsb[in]: client private address lsb
 * @private_address_msb[in]: client private address msbst
 * @public_address_lsb[in]: client public address lsb
 * @public_address_msb[in]: client public address msb
 * @private_port[in]: client private port
 * @public_port[in]: client public port
 * @index[out]: uC activation entry index
 */
struct ipa_ioc_ipv6_nat_uc_act_entry {
	__u16 cmd_id;
	__u16 index;
	__u32 padding;
	__u32 private_port;
	__u32 public_port;
	__u64 private_address_lsb;
	__u64 private_address_msb;
	__u64 public_address_lsb;
	__u64 public_address_msb;
};

/**
 * union ipa_ioc_uc_activation_entry - To hold information about uC activation
 *	entry
 * @socks[in]: fill here if entry is Socksv5 entry
 * @ipv6_nat[in]: fill here if entry is IPv6 NAT entry
 */
union ipa_ioc_uc_activation_entry {
	struct ipa_kernel_tests_socksv5_uc_tmpl socks;
	struct ipa_ioc_ipv6_nat_uc_act_entry ipv6_nat;
};

/**
 * struct ipa_ioc_rm_dependency - parameters for add/delete dependency
 * @resource_name: name of dependent resource
 * @depends_on_name: name of its dependency
 */
struct ipa_ioc_rm_dependency {
	enum ipa_rm_resource_name resource_name;
	enum ipa_rm_resource_name depends_on_name;
};

struct ipa_ioc_generate_flt_eq {
	enum ipa_ip_type ip;
	struct ipa_rule_attrib attrib;
	struct ipa_ipfltri_rule_eq eq_attrib;
};

/**
 * struct ipa_ioc_write_qmapid - to write mux id to endpoint meta register
 * @mux_id: mux id of wan
 */
struct ipa_ioc_write_qmapid {
	enum ipa_client_type client;
	uint8_t qmap_id;
};

/**
 * struct ipa_flt_rt_counter_alloc - flt/rt counter id allocation
 * @num_counters: input param, num of counters need to be allocated
 * @allow_less: input param, if true, success even few counter than request
 * @start_id: output param, allocated start_id, 0 when allocation fails
 * @end_id: output param, allocated start_id, 0 when allocation fails
 */
struct ipa_flt_rt_counter_alloc {
	uint8_t num_counters;
	uint8_t allow_less;
	uint8_t start_id;
	uint8_t end_id;
};

/**
 * struct ipa_ioc_flt_rt_counter_alloc - flt/rt counter id allocation ioctl
 * @hdl: output param, hdl used for deallocation, negative if allocation fails
 * @hw_counter: HW counters for HW process
 * @sw_counter: SW counters for uC / non-HW process
 */
struct ipa_ioc_flt_rt_counter_alloc {
	int hdl;
	struct ipa_flt_rt_counter_alloc hw_counter;
	struct ipa_flt_rt_counter_alloc sw_counter;
};

/**
 * struct ipa_flt_rt_stats - flt/rt stats info
 * @num_pkts: number of packets
 * @num_pkts_hash: number of packets in hash entry
 * @num_bytes: number of bytes
 */
struct ipa_flt_rt_stats {
	uint32_t num_pkts;
	uint32_t num_pkts_hash;
	uint64_t num_bytes;
};

/**
 * struct ipa_ioc_flt_rt_query - flt/rt counter id query
 * @start_id: start counter id for query
 * @end_id: end counter id for query
 * @reset: this query need hw counter to be reset or not
 * @stats_size: sizeof(ipa_flt_rt_stats)
 * @reserved: reserved bits for alignment
 * @stats: structure contains the query result
 */
struct ipa_ioc_flt_rt_query {
	uint8_t start_id;
	uint8_t end_id;
	uint8_t reset;
	uint32_t stats_size;
	uint8_t reserved;
	uint64_t stats;
};

enum ipacm_client_enum {
	IPACM_CLIENT_USB = 1,
	IPACM_CLIENT_WLAN,
	IPACM_CLIENT_MAX
};

#define IPACM_SUPPORT_OF_LAN_STATS_FOR_ODU_CLIENTS

enum ipacm_per_client_device_type {
	IPACM_CLIENT_DEVICE_TYPE_USB = 0,
	IPACM_CLIENT_DEVICE_TYPE_WLAN = 1,
	IPACM_CLIENT_DEVICE_TYPE_ETH = 2,
	IPACM_CLIENT_DEVICE_TYPE_ODU = 3,
#define DUAL_NIC_OFFLOAD
	IPACM_CLIENT_DEVICE_TYPE_ETH1 = 4,
	IPACM_CLIENT_DEVICE_MAX
};

/**
 * max number of device types supported.
 */
#define IPACM_MAX_CLIENT_DEVICE_TYPES IPACM_CLIENT_DEVICE_MAX

/**
 * @lanIface - Name of the lan interface
 * @mac: Mac address of the client.
 */
struct ipa_lan_client_msg {
	char lanIface[IPA_RESOURCE_NAME_MAX];
	uint8_t mac[IPA_MAC_ADDR_SIZE];
};

/**
 * struct ipa_lan_client - lan client data
 * @mac: MAC Address of the client.
 * @client_idx: Client Index.
 * @inited: Bool to indicate whether client info is set.
 */
struct ipa_lan_client {
	uint8_t mac[IPA_MAC_ADDR_SIZE];
	int8_t client_idx;
	uint8_t inited;
};

/**
 * struct ipa_lan_client_cntr_index
 * @ul_cnt_idx: H/w counter index for uplink stats
 * @dl_cnt_idx: H/w counter index for downlink stats
 */
struct ipa_lan_client_cntr_index {
	__u8 ul_cnt_idx;
	__u8 dl_cnt_idx;
};

/**
 * struct ipa_tether_device_info - tether device info indicated from IPACM
 * @ul_src_pipe: Source pipe of the lan client.
 * @hdr_len: Header length of the client.
 * @num_clients: Number of clients connected.
 */
struct ipa_tether_device_info {
	__s32 ul_src_pipe;
	__u8 hdr_len;
	__u8 padding1;
	__u16 padding2;
	__u32 num_clients;
	struct ipa_lan_client lan_client[IPA_MAX_NUM_HW_PATH_CLIENTS];
	struct ipa_lan_client_cntr_index
		lan_client_indices[IPA_MAX_NUM_HW_PATH_CLIENTS];
};

/**
 * enum ipa_vlan_ifaces - vlan interfaces types
 */
enum ipa_vlan_ifaces {
	IPA_VLAN_IF_ETH,
	IPA_VLAN_IF_ETH0,
	IPA_VLAN_IF_ETH1,
	IPA_VLAN_IF_RNDIS,
	IPA_VLAN_IF_ECM,
	IPA_VLAN_IF_WLAN
};

#define IPA_VLAN_IF_EMAC IPA_VLAN_IF_ETH
#define IPA_VLAN_IF_WLAN IPA_VLAN_IF_WLAN
#define IPA_VLAN_IF_MAX (IPA_VLAN_IF_WLAN + 1)

/**
 * struct ipa_get_vlan_mode - get vlan mode of a Lan interface
 * @iface: Lan interface type to be queried.
 * @is_vlan_mode: output parameter, is interface in vlan mode, valid only when
 *		ioctl return val is non-negative
 */
struct ipa_ioc_get_vlan_mode {
	enum ipa_vlan_ifaces iface;
	uint32_t is_vlan_mode;
};

/**
 * struct ipa_ioc_bridge_vlan_mapping_info - vlan to bridge mapping info
 * @bridge_name: bridge interface name
 * @vlan_id: vlan ID bridge is mapped to
 * @bridge_ipv4: bridge interface ipv4 address
 * @subnet_mask: bridge interface subnet mask
 * @lan2lan_sw: indicate lan2lan traffic take sw-path or not
 */
struct ipa_ioc_bridge_vlan_mapping_info {
	char bridge_name[IPA_RESOURCE_NAME_MAX];
	uint8_t lan2lan_sw;
	uint16_t vlan_id;
	uint32_t bridge_ipv4;
	uint32_t subnet_mask;
};

struct ipa_coalesce_info {
	uint8_t qmap_id;
	uint8_t tcp_enable;
	uint8_t udp_enable;
};

struct ipa_mtu_info {
	char if_name[IPA_RESOURCE_NAME_MAX];
	enum ipa_ip_type ip_type;
	uint16_t mtu_v4;
	uint16_t mtu_v6;
};

struct ipa_odl_ep_info {
	__u32 cons_pipe_num;
	__u32 prod_pipe_num;
	__u32 peripheral_iface_id;
	__u32 ep_type;
};

struct odl_agg_pipe_info {
	__u16 agg_byte_limit;
};

struct ipa_odl_modem_config {
	__u8 config_status;
};

struct ipa_ioc_fnr_index_info {
	uint8_t hw_counter_offset;
	uint8_t sw_counter_offset;
};

enum ipacm_hw_index_counter_type {
	UL_HW = 0,
	DL_HW,
	DL_ALL,
	UL_ALL,
};

enum ipacm_hw_index_counter_virtual_type {
	UL_HW_CACHE = 0,
	DL_HW_CACHE,
	UL_WLAN_TX,
	DL_WLAN_TX
};

/**
 * struct ipa_ioc_pdn_config - provide pdn configuration
 * @dev_name: PDN interface name
 * @pdn_cfg_type: type of the pdn config applied.
 * @enable: enable/disable pdn config type.
 * @u.collison_cfg.pdn_ip_addr: pdn_ip_address used in collision config.
 * @u.collison_cfg.vlan_id; VLAN ID of the client.
 * @u.passthrough_cfg.pdn_ip_addr: pdn_ip_address used in passthrough config.
 * @u.passthrough_cfg.device_type: Device type of the client.
 * @u.passthrough_cfg.vlan_id: VLAN ID of the client.
 * @u.passthrough_cfg.client_mac_addr: client mac for which passthough
 *»       is enabled.
 * @u.passthrough_cfg.skip_nat: skip NAT processing.
 * @default_pdn: bool to indicate the config is for default pdn.
 */
struct ipa_ioc_pdn_config {
	char dev_name[IPA_RESOURCE_NAME_MAX];
	enum ipa_pdn_config_event pdn_cfg_type;
	__u8 enable;
	union {
		struct ipa_pdn_ip_collision_cfg {
			__u32 pdn_ip_addr;
			__u16 vlan_id;
		} collison_cfg;

		struct ipa_pdn_ip_passthrough_cfg {
			__u32 pdn_ip_addr;
			enum ipacm_per_client_device_type device_type;
			__u16 vlan_id;
			__u8 client_mac_addr[IPA_MAC_ADDR_SIZE];
			__u8 skip_nat;
		} passthrough_cfg;
	} u;
	__u8 default_pdn;
};

/**
 * struct ipa_ioc_mac_client_list_type- mac addr exception list
 * @mac_addr: an array to hold clients mac addrs
 * @num_of_clients: holds num of clients to blacklist or whitelist
 * @flt_state: true to block current mac addrs and false to clean
 *		up all previous mac addrs
 */
struct ipa_ioc_mac_client_list_type {
	int num_of_clients;
	__u8 mac_addr[IPA_MAX_NUM_MAC_FLT][IPA_MAC_ADDR_SIZE];
	__u8 flt_state;
	__u8 padding;
};

/**
 * struct ipa_sw_flt_list_type- exception list
 * @mac_enable: true to block current mac addrs and false to clean
 *		up all previous mac addrs
 * @num_of_mac: holds num of clients to blacklist
 * @mac_addr: an array to hold clients mac addrs
 * @ipv4_segs_enable: true to block current ipv4 addrs and false to clean
 *		up all previous ipv4 addrs
 * @ipv4_segs_ipv6_offload: reserved flexibility for future use.
 *		true will indicate ipv6 could be still offloaded and
 *		default is set to false as sw-path for ipv6 as well.
 * @num_of_ipv4_segs: holds num of ipv4 segs to blacklist
 * @ipv4_segs: an array to hold clients ipv4 segs addrs
 * @iface_enable: true to block current ifaces and false to clean
 *		up all previous ifaces
 * @num_of_iface: holds num of ifaces to blacklist
 * @iface: an array to hold netdev ifaces
 */
struct ipa_sw_flt_list_type {
	uint8_t mac_enable;
	int num_of_mac;
	uint8_t mac_addr[IPA_MAX_NUM_MAC_FLT][IPA_MAC_ADDR_SIZE];
	uint8_t ipv4_segs_enable;
	uint8_t ipv4_segs_ipv6_offload;
	int num_of_ipv4_segs;
	uint32_t ipv4_segs[IPA_MAX_NUM_IPv4_SEGS_FLT][2];
	uint8_t iface_enable;
	int num_of_iface;
	char iface[IPA_MAX_NUM_IFACE_FLT][IPA_RESOURCE_NAME_MAX];
};

/**
 * struct ipa_ippt_sw_flt_list_type- exception list
 * @ipv4_enable: true to block ipv4 addrs given below and false to clean
 *		up all previous ipv4 addrs
 * @num_of_ipv4: holds num of ipv4 to SW-exception
 * @ipv4: an array to hold ipv4 addrs to SW-exception
 * @port_enable: true to block current ports and false to clean
 *		up all previous ports
 * @num_of_port: holds num of ports to SW-exception
 * @port: an array to hold connection ports to SW-exception
 */

struct ipa_ippt_sw_flt_list_type {
	uint8_t ipv4_enable;
	int num_of_ipv4;
	uint32_t ipv4[IPA_MAX_PDN_NUM];
	uint8_t port_enable;
	int num_of_port;
	uint16_t port[IPA_MAX_IPPT_NUM_PORT_FLT];
};

/**
 * struct ipa_ioc_sw_flt_list_type
 * @ioctl_ptr: has to be typecasted to (__u64)(uintptr_t)
 * @ioctl_data_size:
 * Eg: For ipa_sw_flt_list_type = sizeof(ipa_sw_flt_list_type)
 * Eg: For ipa_ippt_sw_flt_list_type = sizeof(ipa_ippt_sw_flt_list_type)
 */
struct ipa_ioc_sw_flt_list_type {
	__u64 ioctl_ptr;
	__u32 ioctl_data_size;
	__u32 padding;
};

/**
 * struct ipa_macsec_map - mapping between ethX to macsecY
 * @phy_name: name of the physical NIC (ethX)
 *	- must be equal to an existing physical NIC name
 * @macsec_name: name of the macsec NIC (macsecY)
 */
struct ipa_macsec_map {
	char phy_name[IPA_RESOURCE_NAME_MAX];
	char macsec_name[IPA_RESOURCE_NAME_MAX];
};

/**
 * struct ipa_ioc_macsec_info - provide macsec info
 * @ioctl_ptr: has to be typecasted to (__u64)(uintptr_t)
 * @ioctl_data_size:
 * Eg: For ipa_macsec_map = sizeof(ipa_macsec_map)
 */
struct ipa_ioc_macsec_info {
	__u64 ioctl_ptr;
	__u32 ioctl_data_size;
	__u32 padding;
};


enum ipa_ext_router_mode {
	IPA_PREFIX_DISABLED = 0,
	IPA_PREFIX_SHARING,
	IPA_PREFIX_DELEGATION
};

/**
 * struct ipa_ioc_ext_router_info - provide ext_router info
 * @ipa_ext_router_mode: prefix sharing, prefix delegation, or disabled mode
 * @pdn_name: PDN interface name
 * @ipv6_addr: the prefix addr used for the dummy prefix. (prefix sharing mode)
 * @ipv6_mask: the ipv6 mask used to mask above addr to get the correct prefix
 * @num_of_del_prefix_mapping: number of delegated prefix to IDU IP mapping
 * @idu_del_wan_ip: array of IDU WAN IP to be mapped to a delegated prefix
 * @idu_del_client_prefix: Array of delegated prefixes
 */
struct ipa_ioc_ext_router_info {
	enum ipa_ext_router_mode mode;
	char pdn_name[IPA_RESOURCE_NAME_MAX];
	uint32_t ipv6_addr[4];
	uint32_t ipv6_mask[4];
	int num_of_idu_prefix_mapping;
	uint32_t idu_wan_ip[IPA_PREFIX_MAPPING_MAX][4];
	uint32_t idu_client_prefix[IPA_PREFIX_MAPPING_MAX][4];
};

/**
 * struct ipa_ioc_dscp_pcp_map_info - provide dscp pcp mapping info to add/delete
 * @add: Boolean to indicate add or delete the mapping
 * @dscp_pcp_map: DSCP <6 bits> and PCP <3 bits>.
 *                Only 3 bits are valid(0-7) for PCP.
 *                DSCP is used as index (0-63).
 */
struct ipa_ioc_dscp_pcp_map_info {
	uint32_t add;
	uint8_t dscp_pcp_map[IPA_UC_MAX_DSCP_VAL];
};

/**
 *   actual IOCTLs supported by IPA driver
 */
#define IPA_IOC_ADD_HDR _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_HDR, \
					struct ipa_ioc_add_hdr *)
#define IPA_IOC_DEL_HDR _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_DEL_HDR, \
					struct ipa_ioc_del_hdr *)
#define IPA_IOC_ADD_RT_RULE _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_RT_RULE, \
					struct ipa_ioc_add_rt_rule *)
#define IPA_IOC_ADD_RT_RULE_V2 _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_RT_RULE_V2, \
					struct ipa_ioc_add_rt_rule_v2 *)
#define IPA_IOC_ADD_RT_RULE_EXT _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_RT_RULE_EXT, \
					struct ipa_ioc_add_rt_rule_ext *)
#define IPA_IOC_ADD_RT_RULE_EXT_V2 _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_RT_RULE_EXT_V2, \
					struct ipa_ioc_add_rt_rule_ext_v2 *)
#define IPA_IOC_ADD_RT_RULE_AFTER _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_RT_RULE_AFTER, \
					struct ipa_ioc_add_rt_rule_after *)
#define IPA_IOC_ADD_RT_RULE_AFTER_V2 _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_RT_RULE_AFTER_V2, \
					struct ipa_ioc_add_rt_rule_after_v2 *)
#define IPA_IOC_DEL_RT_RULE _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_DEL_RT_RULE, \
					struct ipa_ioc_del_rt_rule *)
#define IPA_IOC_ADD_FLT_RULE _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_FLT_RULE, \
					struct ipa_ioc_add_flt_rule *)
#define IPA_IOC_ADD_FLT_RULE_V2 _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_FLT_RULE_V2, \
					struct ipa_ioc_add_flt_rule_v2 *)
#define IPA_IOC_ADD_FLT_RULE_AFTER _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_FLT_RULE_AFTER, \
					struct ipa_ioc_add_flt_rule_after *)
#define IPA_IOC_ADD_FLT_RULE_AFTER_V2 _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_ADD_FLT_RULE_AFTER_V2, \
					struct ipa_ioc_add_flt_rule_after_v2 *)
#define IPA_IOC_DEL_FLT_RULE _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_DEL_FLT_RULE, \
					struct ipa_ioc_del_flt_rule *)
#define IPA_IOC_COMMIT_HDR _IO(IPA_IOC_MAGIC,\
					IPA_IOCTL_COMMIT_HDR)
#define IPA_IOC_RESET_HDR _IO(IPA_IOC_MAGIC,\
					IPA_IOCTL_RESET_HDR)
#define IPA_IOC_COMMIT_RT _IOW(IPA_IOC_MAGIC, \
					IPA_IOCTL_COMMIT_RT, \
					enum ipa_ip_type)
#define IPA_IOC_RESET_RT _IOW(IPA_IOC_MAGIC, \
					IPA_IOCTL_RESET_RT, \
					enum ipa_ip_type)
#define IPA_IOC_COMMIT_FLT _IOW(IPA_IOC_MAGIC, \
					IPA_IOCTL_COMMIT_FLT, \
					enum ipa_ip_type)
#define IPA_IOC_RESET_FLT _IOW(IPA_IOC_MAGIC, \
			IPA_IOCTL_RESET_FLT, \
			enum ipa_ip_type)
#define IPA_IOC_DUMP _IO(IPA_IOC_MAGIC, \
			IPA_IOCTL_DUMP)
#define IPA_IOC_GET_RT_TBL _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_RT_TBL, \
				struct ipa_ioc_get_rt_tbl *)
#define IPA_IOC_PUT_RT_TBL _IOW(IPA_IOC_MAGIC, \
				IPA_IOCTL_PUT_RT_TBL, \
				uint32_t)
#define IPA_IOC_COPY_HDR _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_COPY_HDR, \
				struct ipa_ioc_copy_hdr *)
#define IPA_IOC_QUERY_INTF _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_QUERY_INTF, \
				struct ipa_ioc_query_intf *)
#define IPA_IOC_QUERY_INTF_TX_PROPS _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_QUERY_INTF_TX_PROPS, \
				struct ipa_ioc_query_intf_tx_props *)
#define IPA_IOC_QUERY_INTF_RX_PROPS _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_QUERY_INTF_RX_PROPS, \
					struct ipa_ioc_query_intf_rx_props *)
#define IPA_IOC_QUERY_INTF_EXT_PROPS _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_QUERY_INTF_EXT_PROPS, \
					struct ipa_ioc_query_intf_ext_props *)
#define IPA_IOC_GET_HDR _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_HDR, \
				struct ipa_ioc_get_hdr *)
#define IPA_IOC_PUT_HDR _IOW(IPA_IOC_MAGIC, \
				IPA_IOCTL_PUT_HDR, \
				uint32_t)
#define IPA_IOC_ALLOC_NAT_MEM _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ALLOC_NAT_MEM, \
				struct ipa_ioc_nat_alloc_mem *)
#define IPA_IOC_ALLOC_NAT_TABLE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ALLOC_NAT_TABLE, \
				struct ipa_ioc_nat_ipv6ct_table_alloc *)
#define IPA_IOC_ALLOC_IPV6CT_TABLE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ALLOC_IPV6CT_TABLE, \
				struct ipa_ioc_nat_ipv6ct_table_alloc *)
#define IPA_IOC_V4_INIT_NAT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_V4_INIT_NAT, \
				struct ipa_ioc_v4_nat_init *)
#define IPA_IOC_INIT_IPV6CT_TABLE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_INIT_IPV6CT_TABLE, \
				struct ipa_ioc_ipv6ct_init *)
#define IPA_IOC_NAT_DMA _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_NAT_DMA, \
				struct ipa_ioc_nat_dma_cmd *)
#define IPA_IOC_TABLE_DMA_CMD _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_TABLE_DMA_CMD, \
				struct ipa_ioc_nat_dma_cmd *)
#define IPA_IOC_V4_DEL_NAT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_V4_DEL_NAT, \
				struct ipa_ioc_v4_nat_del *)
#define IPA_IOC_DEL_NAT_TABLE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_NAT_TABLE, \
				struct ipa_ioc_nat_ipv6ct_table_del *)
#define IPA_IOC_DEL_IPV6CT_TABLE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_IPV6CT_TABLE, \
				struct ipa_ioc_nat_ipv6ct_table_del *)
#define IPA_IOC_GET_NAT_OFFSET _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_NAT_OFFSET, \
				uint32_t *)
#define IPA_IOC_NAT_MODIFY_PDN _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_NAT_MODIFY_PDN, \
				struct ipa_ioc_nat_pdn_entry *)
#define IPA_IOC_SET_FLT _IOW(IPA_IOC_MAGIC, \
			IPA_IOCTL_SET_FLT, \
			uint32_t)
#define IPA_IOC_PULL_MSG _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_PULL_MSG, \
				struct ipa_msg_meta *)
#define IPA_IOC_RM_ADD_DEPENDENCY _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_RM_ADD_DEPENDENCY, \
				struct ipa_ioc_rm_dependency *)
#define IPA_IOC_RM_DEL_DEPENDENCY _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_RM_DEL_DEPENDENCY, \
				struct ipa_ioc_rm_dependency *)
#define IPA_IOC_GENERATE_FLT_EQ _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GENERATE_FLT_EQ, \
				struct ipa_ioc_generate_flt_eq *)
#define IPA_IOC_QUERY_EP_MAPPING _IOR(IPA_IOC_MAGIC, \
				IPA_IOCTL_QUERY_EP_MAPPING, \
				uint32_t)
#define IPA_IOC_QUERY_RT_TBL_INDEX _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_QUERY_RT_TBL_INDEX, \
				struct ipa_ioc_get_rt_tbl_indx *)
#define IPA_IOC_WRITE_QMAPID  _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_WRITE_QMAPID, \
				struct ipa_ioc_write_qmapid *)
#define IPA_IOC_MDFY_FLT_RULE _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_MDFY_FLT_RULE, \
					struct ipa_ioc_mdfy_flt_rule *)
#define IPA_IOC_MDFY_FLT_RULE_V2 _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_MDFY_FLT_RULE_V2, \
					struct ipa_ioc_mdfy_flt_rule_v2 *)
#define IPA_IOC_MDFY_RT_RULE _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_MDFY_RT_RULE, \
					struct ipa_ioc_mdfy_rt_rule *)
#define IPA_IOC_MDFY_RT_RULE_V2 _IOWR(IPA_IOC_MAGIC, \
					IPA_IOCTL_MDFY_RT_RULE_V2, \
					struct ipa_ioc_mdfy_rt_rule_v2 *)

#define IPA_IOC_NOTIFY_WAN_UPSTREAM_ROUTE_ADD _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_NOTIFY_WAN_UPSTREAM_ROUTE_ADD, \
				struct ipa_wan_msg *)

#define IPA_IOC_NOTIFY_WAN_UPSTREAM_ROUTE_DEL _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_NOTIFY_WAN_UPSTREAM_ROUTE_DEL, \
				struct ipa_wan_msg *)
#define IPA_IOC_NOTIFY_WAN_EMBMS_CONNECTED _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_NOTIFY_WAN_EMBMS_CONNECTED, \
				struct ipa_wan_msg *)
#define IPA_IOC_ADD_HDR_PROC_CTX _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ADD_HDR_PROC_CTX, \
				struct ipa_ioc_add_hdr_proc_ctx *)
#define IPA_IOC_DEL_HDR_PROC_CTX _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_HDR_PROC_CTX, \
				struct ipa_ioc_del_hdr_proc_ctx *)

#define IPA_IOC_GET_HW_VERSION _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_HW_VERSION, \
				enum ipa_hw_type *)

#define IPA_IOC_ADD_VLAN_IFACE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ADD_VLAN_IFACE, \
				struct ipa_ioc_vlan_iface_info *)

#define IPA_IOC_DEL_VLAN_IFACE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_VLAN_IFACE, \
				struct ipa_ioc_vlan_iface_info *)

#define IPA_IOC_ADD_L2TP_VLAN_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ADD_L2TP_VLAN_MAPPING, \
				struct ipa_ioc_l2tp_vlan_mapping_info *)

#define IPA_IOC_DEL_L2TP_VLAN_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_L2TP_VLAN_MAPPING, \
				struct ipa_ioc_l2tp_vlan_mapping_info *)
#define IPA_IOC_GET_VLAN_MODE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_VLAN_MODE, \
				struct ipa_ioc_get_vlan_mode *)
#define IPA_IOC_ADD_BRIDGE_VLAN_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ADD_BRIDGE_VLAN_MAPPING, \
				struct ipa_ioc_bridge_vlan_mapping_info)

#define IPA_IOC_DEL_BRIDGE_VLAN_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_BRIDGE_VLAN_MAPPING, \
				struct ipa_ioc_bridge_vlan_mapping_info)
#define IPA_IOC_CLEANUP _IO(IPA_IOC_MAGIC,\
					IPA_IOCTL_CLEANUP)
#define IPA_IOC_QUERY_WLAN_CLIENT _IO(IPA_IOC_MAGIC,\
					IPA_IOCTL_QUERY_WLAN_CLIENT)

#define IPA_IOC_ODL_QUERY_ADAPL_EP_INFO _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ODL_QUERY_ADAPL_EP_INFO, \
				struct ipa_odl_ep_info)
#define IPA_IOC_ODL_GET_AGG_BYTE_LIMIT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ODL_GET_AGG_BYTE_LIMIT, \
				struct odl_agg_pipe_info)

#define IPA_IOC_ODL_QUERY_MODEM_CONFIG _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ODL_QUERY_MODEM_CONFIG, \
				struct ipa_odl_modem_config)

#define IPA_IOC_GSB_CONNECT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GSB_CONNECT, \
				struct ipa_ioc_gsb_info)

#define IPA_IOC_GSB_DISCONNECT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GSB_DISCONNECT, \
				struct ipa_ioc_gsb_info)

#define IPA_IOC_WIGIG_FST_SWITCH _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_WIGIG_FST_SWITCH, \
				struct ipa_ioc_wigig_fst_switch)

#define IPA_IOC_FNR_COUNTER_ALLOC _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_FNR_COUNTER_ALLOC, \
				struct ipa_ioc_flt_rt_counter_alloc)

#define IPA_IOC_FNR_COUNTER_DEALLOC _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_FNR_COUNTER_DEALLOC, \
				int)

#define IPA_IOC_FNR_COUNTER_QUERY _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_FNR_COUNTER_QUERY, \
				struct ipa_ioc_flt_rt_query)

#define IPA_IOC_SET_FNR_COUNTER_INFO _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_SET_FNR_COUNTER_INFO, \
				struct ipa_ioc_fnr_index_info)

#define IPA_IOC_GET_NAT_IN_SRAM_INFO _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_NAT_IN_SRAM_INFO, \
				struct ipa_nat_in_sram_info)

#define IPA_IOC_APP_CLOCK_VOTE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_APP_CLOCK_VOTE, \
				uint32_t)

#define IPA_IOC_PDN_CONFIG _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_PDN_CONFIG, \
				struct ipa_ioc_pdn_config)

#define IPA_IOC_SET_MAC_FLT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_SET_MAC_FLT, \
				struct ipa_ioc_mac_client_list_type)

#define IPA_IOC_GET_PHERIPHERAL_EP_INFO _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_PHERIPHERAL_EP_INFO, \
				struct ipa_ioc_get_ep_info)

#define IPA_IOC_ADD_UC_ACT_ENTRY _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ADD_UC_ACT_ENTRY, \
				union ipa_ioc_uc_activation_entry)

#define IPA_IOC_DEL_UC_ACT_ENTRY _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_UC_ACT_ENTRY, \
				__u16)
#define IPA_IOC_QUERY_CACHED_DRIVER_MSG _IO(IPA_IOC_MAGIC,\
				IPA_IOCTL_QUERY_CACHED_DRIVER_MSG)

#define IPA_IOC_SET_SW_FLT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_SET_SW_FLT, \
				struct ipa_ioc_sw_flt_list_type)

#define IPA_IOC_GET_HW_FEATURE_SUPPORT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_GET_HW_FEATURE_SUPPORT, \
				__u32)

#define IPA_IOC_SET_PKT_THRESHOLD _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_SET_PKT_THRESHOLD, \
				struct ipa_ioc_set_pkt_threshold)

#define IPA_IOC_ADD_EoGRE_MAPPING _IOWR(IPA_IOC_MAGIC,	\
				IPA_IOCTL_ADD_EoGRE_MAPPING, \
				struct ipa_ioc_eogre_info)
#define IPA_IOC_DEL_EoGRE_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_EoGRE_MAPPING, \
				struct ipa_ioc_eogre_info)

#define IPA_IOC_SET_IPPT_SW_FLT _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_SET_IPPT_SW_FLT, \
				struct ipa_ioc_sw_flt_list_type)

#define IPA_IOC_FLT_MEM_PERIPHERAL_SET_PRIO_HIGH _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_FLT_MEM_PERIPHERAL_SET_PRIO_HIGH, \
				enum ipa_client_type)

#define IPA_IOC_ADD_MACSEC_MAPPING _IOWR(IPA_IOC_MAGIC,	\
				IPA_IOCTL_ADD_MACSEC_MAPPING, \
				struct ipa_ioc_macsec_info)
#define IPA_IOC_DEL_MACSEC_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_DEL_MACSEC_MAPPING, \
				struct ipa_ioc_macsec_info)

#define IPA_IOC_SET_EXT_ROUTER_MODE _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_SET_EXT_ROUTER_MODE, \
				struct ipa_ioc_ext_router_info)

#define IPA_IOC_ADD_DEL_DSCP_PCP_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_ADD_DEL_DSCP_PCP_MAPPING, \
				struct ipa_ioc_dscp_pcp_map_info)

#define IPA_IOC_SEND_VLAN_MUXID_MAPPING _IOWR(IPA_IOC_MAGIC, \
				IPA_IOCTL_SEND_VLAN_MUXID_MAPPING, \
				struct ipa_ioc_mux_mapping_table)

#define IPA_IOC_SEND_TUNNEL_TEMPLATE_INFO _IOW(IPA_IOC_MAGIC, \
				IPA_IOCTL_SEND_TUNNEL_TEMPLATE_INFO, \
				struct ipa_ioc_tunnel_template_info)


#define IPA_IOC_QUERY_TUNNEL_FEATURE _IOW(IPA_IOC_MAGIC, \
				IPA_IOCTL_QUERY_TUNNEL_FEATURE, \
				uint8_t)

/*
 * unique magic number of the Tethering bridge ioctls
 */
#define TETH_BRIDGE_IOC_MAGIC 0xCE

/*
 * Ioctls supported by Tethering bridge driver
 */
#define TETH_BRIDGE_IOCTL_SET_BRIDGE_MODE	0
#define TETH_BRIDGE_IOCTL_SET_AGGR_PARAMS	1
#define TETH_BRIDGE_IOCTL_GET_AGGR_PARAMS	2
#define TETH_BRIDGE_IOCTL_GET_AGGR_CAPABILITIES	3
#define TETH_BRIDGE_IOCTL_MAX			4


/**
 * enum teth_link_protocol_type - link protocol (IP / Ethernet)
 */
enum teth_link_protocol_type {
	TETH_LINK_PROTOCOL_IP,
	TETH_LINK_PROTOCOL_ETHERNET,
	TETH_LINK_PROTOCOL_MAX,
};

/**
 * enum teth_aggr_protocol_type - Aggregation protocol (MBIM / TLP)
 */
enum teth_aggr_protocol_type {
	TETH_AGGR_PROTOCOL_NONE,
	TETH_AGGR_PROTOCOL_MBIM,
	TETH_AGGR_PROTOCOL_TLP,
	TETH_AGGR_PROTOCOL_MAX,
};

/**
 * struct teth_aggr_params_link - Aggregation parameters for uplink/downlink
 * @aggr_prot:			Aggregation protocol (MBIM / TLP)
 * @max_transfer_size_byte:	Maximal size of aggregated packet in bytes.
 *				Default value is 16*1024.
 * @max_datagrams:		Maximal number of IP packets in an aggregated
 *				packet. Default value is 16
 */
struct teth_aggr_params_link {
	enum teth_aggr_protocol_type aggr_prot;
	uint32_t max_transfer_size_byte;
	uint32_t max_datagrams;
};


/**
 * struct teth_aggr_params - Aggregation parmeters
 * @ul:	Uplink parameters
 * @dl: Downlink parmaeters
 */
struct teth_aggr_params {
	struct teth_aggr_params_link ul;
	struct teth_aggr_params_link dl;
};

/**
 * struct teth_aggr_capabilities - Aggregation capabilities
 * @num_protocols:		Number of protocols described in the array
 * @prot_caps[]:		Array of aggregation capabilities per protocol
 */
struct teth_aggr_capabilities {
	uint16_t num_protocols;
	struct teth_aggr_params_link prot_caps[0];
};

/**
 * struct teth_ioc_set_bridge_mode
 * @link_protocol: link protocol (IP / Ethernet)
 * @lcid: logical channel number
 */
struct teth_ioc_set_bridge_mode {
	enum teth_link_protocol_type link_protocol;
	uint16_t lcid;
};

/**
 * struct teth_ioc_set_aggr_params
 * @aggr_params: Aggregation parmeters
 * @lcid: logical channel number
 */
struct teth_ioc_aggr_params {
	struct teth_aggr_params aggr_params;
	uint16_t lcid;
};

/**
 * struct ipa_nat_in_sram_info - query for nat in sram particulars
 * @sram_mem_available_for_nat: Amount SRAM available to fit nat table
 * @nat_table_offset_into_mmap: Offset into mmap'd vm where table will be
 * @best_nat_in_sram_size_rqst: The size to request for mmap
 *
 * The last two elements above are required to deal with situations
 * where the SRAM's physical address and size don't play nice with
 * mmap'ings page size and boundary attributes.
 */
struct ipa_nat_in_sram_info {
	uint32_t sram_mem_available_for_nat;
	uint32_t nat_table_offset_into_mmap;
	uint32_t best_nat_in_sram_size_rqst;
};

/**
 * enum ipa_app_clock_vote_type
 *
 * The types of votes that can be accepted by the
 * IPA_IOC_APP_CLOCK_VOTE ioctl
 */
enum ipa_app_clock_vote_type {
	IPA_APP_CLK_DEVOTE     = 0,
	IPA_APP_CLK_VOTE       = 1,
	IPA_APP_CLK_RESET_VOTE = 2,
};

#define TETH_BRIDGE_IOC_SET_BRIDGE_MODE _IOW(TETH_BRIDGE_IOC_MAGIC, \
				TETH_BRIDGE_IOCTL_SET_BRIDGE_MODE, \
				struct teth_ioc_set_bridge_mode *)
#define TETH_BRIDGE_IOC_SET_AGGR_PARAMS _IOW(TETH_BRIDGE_IOC_MAGIC, \
				TETH_BRIDGE_IOCTL_SET_AGGR_PARAMS, \
				struct teth_ioc_aggr_params *)
#define TETH_BRIDGE_IOC_GET_AGGR_PARAMS _IOR(TETH_BRIDGE_IOC_MAGIC, \
				TETH_BRIDGE_IOCTL_GET_AGGR_PARAMS, \
				struct teth_ioc_aggr_params *)
#define TETH_BRIDGE_IOC_GET_AGGR_CAPABILITIES _IOWR(TETH_BRIDGE_IOC_MAGIC, \
				TETH_BRIDGE_IOCTL_GET_AGGR_CAPABILITIES, \
				struct teth_aggr_capabilities *)

/*
 * unique magic number of the ODU bridge ioctls
 */
#define ODU_BRIDGE_IOC_MAGIC 0xCD

/*
 * Ioctls supported by ODU bridge driver
 */
#define ODU_BRIDGE_IOCTL_SET_MODE	0
#define ODU_BRIDGE_IOCTL_SET_LLV6_ADDR	1
#define ODU_BRIDGE_IOCTL_MAX		2


/**
 * enum odu_bridge_mode - bridge mode
 *			(ROUTER MODE / BRIDGE MODE)
 */
enum odu_bridge_mode {
	ODU_BRIDGE_MODE_ROUTER,
	ODU_BRIDGE_MODE_BRIDGE,
	ODU_BRIDGE_MODE_MAX,
};

#define ODU_BRIDGE_IOC_SET_MODE _IOW(ODU_BRIDGE_IOC_MAGIC, \
				ODU_BRIDGE_IOCTL_SET_MODE, \
				enum odu_bridge_mode)

#define ODU_BRIDGE_IOC_SET_LLV6_ADDR _IOW(ODU_BRIDGE_IOC_MAGIC, \
				ODU_BRIDGE_IOCTL_SET_LLV6_ADDR, \
				struct in6_addr *)

#endif /* _MSM_IPA_H_ */

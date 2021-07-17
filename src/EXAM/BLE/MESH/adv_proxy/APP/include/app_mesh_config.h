/********************************** (C) COPYRIGHT *******************************
* File Name          : app_mesh_config.h
* Author             : WCH
* Version            : V1.0
* Date               : 2021/03/24
* Description        : 
*******************************************************************************/

#ifndef APP_MESH_CONFIG_H
#define APP_MESH_CONFIG_H

#ifdef __cplusplus
extern "C"
{
#endif
/**************************功能配置,建议直接参考不同例程*****************************/

// relay功能
#define CONFIG_BLE_MESH_RELAY                                               1
// 代理功能
#define CONFIG_BLE_MESH_PROXY                                               1
// GATT层配网功能
#define CONFIG_BLE_MESH_PB_GATT                                             1
// FLASH存储功能
#define CONFIG_BLE_MESH_SETTINGS                                          	1
// 朋友节点功能
#define CONFIG_BLE_MESH_FRIEND                                              0
// 低功耗节点功能
#define CONFIG_BLE_MESH_LOW_POWER                                           0
// config模型客户端功能
#define CONFIG_BLE_MESH_CFG_CLI                                          		0
// health模型客户端功能
#define CONFIG_BLE_MESH_HLTH_CLI                                          	0


/************************************参数配置******************************************/

// Net数据缓存个数
#define CONFIG_MESH_ADV_BUF_COUNT_MIN (6)
#define CONFIG_MESH_ADV_BUF_COUNT_DEF (10)
#define CONFIG_MESH_ADV_BUF_COUNT_MAX (40)

// RPL数据缓存个数
#define CONFIG_MESH_RPL_COUNT_MIN (6)
#define CONFIG_MESH_RPL_COUNT_DEF (6)
#define CONFIG_MESH_RPL_COUNT_MAX (20)

// IV Update State Timer 基于96H的分频系数
#define CONFIG_MESH_IVU_DIVIDER_MIN (1)
#define CONFIG_MESH_IVU_DIVIDER_DEF (96)
#define CONFIG_MESH_IVU_DIVIDER_MAX (96)

// 代理黑白名单功能存储个数
#define CONFIG_MESH_PROXY_FILTER_MIN (2)
#define CONFIG_MESH_PROXY_FILTER_DEF (5)
#define CONFIG_MESH_PROXY_FILTER_MAX (20)

// 消息贮存个数
#define CONFIG_MESH_MSG_CACHE_MIN (3)
#define CONFIG_MESH_MSG_CACHE_DEF (20)
#define CONFIG_MESH_MSG_CACHE_MAX (20)

// 子网络个数
#define CONFIG_MESH_SUBNET_COUNT_MIN (1)
#define CONFIG_MESH_SUBNET_COUNT_DEF (1)
#define CONFIG_MESH_SUBNET_COUNT_MAX (4)

// APP key个数
#define CONFIG_MESH_APPKEY_COUNT_MIN (1)
#define CONFIG_MESH_APPKEY_COUNT_DEF (3)
#define CONFIG_MESH_APPKEY_COUNT_MAX (5)

// 是否允许一个网络中存在同地址的节点（使能后分包功能不可用）
#define CONFIG_MESH_ALLOW_SAME_ADDR (FALSE)

// 不分包消息支持的长度（超过此长度则需要分包，默认值为7，修改此值将不符合标准mesh协议）
#define CONFIG_MESH_UNSEG_LENGTH_MIN (7)
#define CONFIG_MESH_UNSEG_LENGTH_DEF (7)
#define CONFIG_MESH_UNSEG_LENGTH_MAX (221)

// 每个消息的最大分包数
#define CONFIG_MESH_TX_SEG_MIN (2)
#define CONFIG_MESH_TX_SEG_DEF (8)
#define CONFIG_MESH_TX_SEG_MAX (32)

// 允许同时存在的分包消息的最大发送个数
#define CONFIG_MESH_TX_SEG_COUNT_MIN (1)
#define CONFIG_MESH_TX_SEG_COUNT_DEF (2)
#define CONFIG_MESH_TX_SEG_COUNT_MAX (4)

// 允许同时存在的分包消息的最大接收个数
#define CONFIG_MESH_RX_SEG_COUNT_MIN (1)
#define CONFIG_MESH_RX_SEG_COUNT_DEF (2)
#define CONFIG_MESH_RX_SEG_COUNT_MAX (4)

// 每个接收的分包消息的最大字节数
#define CONFIG_MESH_RX_SDU_MIN (12)
#define CONFIG_MESH_RX_SDU_DEF (192)
#define CONFIG_MESH_RX_SDU_MAX (384)

// 虚拟地址个数
#define CONFIG_MESH_LABEL_COUNT_MIN (1)
#define CONFIG_MESH_LABEL_COUNT_DEF (2)
#define CONFIG_MESH_LABEL_COUNT_MAX (4)

// NVS存储使用扇区个数
#define CONFIG_MESH_SECTOR_COUNT_MIN (2)
#define CONFIG_MESH_SECTOR_COUNT_DEF (3)

// NVS存储首地址
#define CONFIG_MESH_NVS_ADDR_DEF	(0x3E800)

// RPL更新后存储的超时时长(s)
#define CONFIG_MESH_RPL_STORE_RATE_MIN (5)
#define CONFIG_MESH_RPL_STORE_RATE_DEF (60)
#define CONFIG_MESH_RPL_STORE_RATE_MAX (3600)

// SEQ更新后存储的超时时长(s)
#define CONFIG_MESH_SEQ_STORE_RATE_MIN (5)
#define CONFIG_MESH_SEQ_STORE_RATE_DEF (60)
#define CONFIG_MESH_SEQ_STORE_RATE_MAX (3600)

// 其他信息更新后存储的超时时长(s)
#define CONFIG_MESH_STORE_RATE_MIN (2)
#define CONFIG_MESH_STORE_RATE_DEF (2)
#define CONFIG_MESH_STORE_RATE_MAX (5)

// 朋友节点支持的每个消息的分包个数
#define CONFIG_MESH_FRIEND_SEG_RX_COUNT_MIN (1)
#define CONFIG_MESH_FRIEND_SEG_RX_COUNT_DEF (2)
#define CONFIG_MESH_FRIEND_SEG_RX_COUNT_MAX (4)

// 朋友节点支持的订阅个数
#define CONFIG_MESH_FRIEND_SUB_SIZE_MIN 		(1)
#define CONFIG_MESH_FRIEND_SUB_SIZE_DEF 		(4)
#define CONFIG_MESH_FRIEND_SUB_SIZE_MAX 		(8)

// 朋友节点支持的低功耗节点个数
#define CONFIG_MESH_FRIEND_LPN_COUNT_MIN 		(1)
#define CONFIG_MESH_FRIEND_LPN_COUNT_DEF 		(1)
#define CONFIG_MESH_FRIEND_LPN_COUNT_MAX 		(4)

// 朋友节点存储的消息队列大小
#define CONFIG_MESH_QUEUE_SIZE_MIN 				(2)
#define CONFIG_MESH_QUEUE_SIZE_DEF 				(4)
#define CONFIG_MESH_QUEUE_SIZE_MAX 				(30)

// 朋友节点接收窗口大小(ms)
#define CONFIG_MESH_FRIEND_RECV_WIN_MIN 		(1)
#define CONFIG_MESH_FRIEND_RECV_WIN_DEF 		(20)
#define CONFIG_MESH_FRIEND_RECV_WIN_MAX 		(255)

// 低功耗节点的请求消息队列大小
#define CONFIG_MESH_LPN_REQ_QUEUE_SIZE_MIN 		(2)
#define CONFIG_MESH_LPN_REQ_QUEUE_SIZE_DEF 		(2)
#define CONFIG_MESH_LPN_REQ_QUEUE_SIZE_MAX 		(20)

// 低功耗节点的请求消息超时时长(10ms)
#define CONFIG_MESH_LPN_POLLTIMEOUT_MIN 		(30)
#define CONFIG_MESH_LPN_POLLTIMEOUT_DEF 		(40)
#define CONFIG_MESH_LPN_POLLTIMEOUT_MAX 		(400)

// 低功耗节点支持的接收延迟(ms)
#define CONFIG_MESH_LPN_RECV_DELAY_MIN			(100)
#define CONFIG_MESH_LPN_RECV_DELAY_DEF			(100)
#define CONFIG_MESH_LPN_RECV_DELAY_MAX			(400)

// 朋友关系重建等待时长(s)
#define CONFIG_MESH_RETRY_TIMEOUT_MIN			(3)
#define CONFIG_MESH_RETRY_TIMEOUT_DEF			(10)
#define CONFIG_MESH_RETRY_TIMEOUT_MAX			(60)

// 配网发起者支持的配网设备节点个数
#define CONFIG_MESH_PROV_NODE_COUNT_MIN			(1)
#define CONFIG_MESH_PROV_NODE_COUNT_DEF			(2)

// ADV_RF配置
#define CONFIG_MESH_RF_ACCESSADDRESS      (0x8E89BED6)
#define CONFIG_MESH_RF_CHANNEL_37         (37)
#define CONFIG_MESH_RF_CHANNEL_38         (38)
#define CONFIG_MESH_RF_CHANNEL_39         (39)

#define APP_DBG(X...) 																								\
        if (1)                                         \
        {                                                           \
            printf("APP_DBG %s> ",  __FUNCTION__); 																		\
            printf(X); 																		\
            printf("\n"); 																		\
       }                                                           \
				

/******************************************************************************/


#ifdef __cplusplus
}
#endif

#endif

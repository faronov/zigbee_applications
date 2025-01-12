/***************************************************************************//**
* @file zigbee_rtc_time_sync_4161A_callbacks.c
*******************************************************************************
* # License
* <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
*******************************************************************************
*
* SPDX-License-Identifier: Zlib
*
* The licensor of this software is Silicon Laboratories Inc.
*
* This software is provided \'as-is\', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*
*******************************************************************************
* # Experimental Quality
* This code has not been formally tested and is provided as-is. It is not
* suitable for production environments. In addition, this code will not be
* maintained and there may be no bug maintenance planned for these resources.
* Silicon Labs may update projects from time to time.
******************************************************************************/

// This callback file is created for your convenience. You may add application
// code to this file. If you regenerate this file over a previous version, the
// previous version will be overwritten and any code you have added will be
// lost.

#include "app/framework/include/af.h"

/** @brief Stack Status
 *
 * This function is called by the application framework from the stack status
 * handler.  This callbacks provides applications an opportunity to be notified
 * of changes to the stack status and take appropriate action.  The return code
 * from this callback is ignored by the framework.  The framework will always
 * process the stack status after the callback returns.
 *
 * @param status   Ver.: always
 */


/** @brief Complete
 *
 * This callback is fired when the Network Steering plugin is complete.
 *
 * @param status On success this will be set to EMBER_SUCCESS to indicate a
 * network was joined successfully. On failure this will be the status code of
 * the last join or scan attempt. Ver.: always
 * @param totalBeacons The total number of 802.15.4 beacons that were heard,
 * including beacons from different devices with the same PAN ID. Ver.: always
 * @param joinAttempts The number of join attempts that were made to get onto
 * an open Zigbee network. Ver.: always
 * @param finalState The finishing state of the network steering process. From
 * this, one is able to tell on which channel mask and with which key the
 * process was complete. Ver.: always
 */
void emberAfPluginNetworkSteeringCompleteCallback(EmberStatus status,
                                                  uint8_t totalBeacons,
                                                  uint8_t joinAttempts,
                                                  uint8_t finalState)
{
  emberAfCorePrintln("%p network %p: 0x%X", "Join", "complete", status);
}


EmberEventControl emberTimeSyncEventControl;

void emberTimeSyncEventHandler()
{
  emberEventControlSetInactive(emberTimeSyncEventControl);

  if (emberAfNetworkState() == EMBER_JOINED_NETWORK) {
      //send read attribute
      uint8_t timeAttributeIds[] = {
        LOW_BYTE(ZCL_TIME_ATTRIBUTE_ID),
        HIGH_BYTE(ZCL_TIME_ATTRIBUTE_ID)
      };

      emberAfFillCommandGlobalClientToServerReadAttributes(ZCL_TIME_CLUSTER_ID, timeAttributeIds, sizeof(timeAttributeIds));
      emberAfGetCommandApsFrame()->sourceEndpoint = 1;
      emberAfGetCommandApsFrame()->destinationEndpoint = 1;
      EmberStatus status = emberAfSendCommandUnicast(EMBER_OUTGOING_DIRECT, 0x0000);
      emberAfCorePrintln("Query time from the gateway status=0x%X", status);

      emberEventControlSetDelayMS(emberTimeSyncEventControl, 5000);
  }
}

bool emberAfStackStatusCallback(EmberStatus status)
{
  if (status == EMBER_NETWORK_DOWN) {
    emberEventControlSetInactive(emberTimeSyncEventControl);
  } else if (status == EMBER_NETWORK_UP) {
    emberEventControlSetDelayMS(emberTimeSyncEventControl, 5000);
  }

  // This value is ignored by the framework.
  return false;
}

boolean emberAfReadAttributesResponseCallback(EmberAfClusterId clusterId,
                                            int8u *buffer,
                                            int16u bufLen)
{
    if (ZCL_TIME_CLUSTER_ID != clusterId)
    {
        return false;
    }

    //attribute ID (2B) + status (1B) + date type (0B or 1B) + value (4B)
    if (bufLen < 7)
    {
        return false;
    }

    if ((emberAfGetInt16u(buffer, 0, bufLen) == ZCL_TIME_ATTRIBUTE_ID) && (emberAfGetInt8u(buffer, 2, bufLen) == EMBER_ZCL_STATUS_SUCCESS))
    {
        emberAfSetTime(emberAfGetInt32u(buffer, 4, bufLen));
        emberAfCorePrintln("time sync ok, time: %4x", emberAfGetCurrentTime());

        emberEventControlSetDelayMS(emberTimeSyncEventControl, MILLISECOND_TICKS_PER_DAY);

        return true;
    }

    return false;
}


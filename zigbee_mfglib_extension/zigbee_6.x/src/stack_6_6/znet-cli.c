/***************************************************************************//**
 * @file znet-cli.c
 * @brief This file contains the mapping for the command line configuration
 * @version 1.0.1
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
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

#include "app/framework/include/af.h"
#include "app/framework/cli/custom-cli.h"
#include EMBER_AF_API_COMMAND_INTERPRETER2

void emAfCliBsendCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const bsendCommandArguments[] = {
  "Source endpoint to send a binding based message from",
  NULL
};
#endif


void changeKeyCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const changekeyLinkCommandArguments[] = {
  "The link key provided as a 16 byte array",
  NULL
};
#endif


void changeKeyCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const changekeyNetworkCommandArguments[] = {
  "The network key provided as a 16 byte array",
  NULL
};
#endif


static EmberCommandEntry emberCommandChangekeyTable[] = {
  emberCommandEntryActionWithDetails("link", changeKeyCommand, "b", "Change the link key to the one provided in the 16 byte array argument  ...", changekeyLinkCommandArguments),
  emberCommandEntryActionWithDetails("network", changeKeyCommand, "b", "Change the network key to the 16 byte array provided as an argument to ...", changekeyNetworkCommandArguments),
  emberCommandEntryTerminator(),
};
void emberAfPrintAllOff(void);
void emberAfPrintAllOn(void);
void printOffCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const debugprintOffCommandArguments[] = {
  "The debug area mask listed in the <application>.h file",
  NULL
};
#endif


void printOnCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const debugprintOnCommandArguments[] = {
  "The debug area mask listed in the <application>.h file",
  NULL
};
#endif


void emberAfPrintStatus(void);
static EmberCommandEntry emberCommandDebugprintTable[] = {
  emberCommandEntryActionWithDetails("all_off", emberAfPrintAllOff, "", "Turns off all debug printing", NULL),
  emberCommandEntryActionWithDetails("all_on", emberAfPrintAllOn, "", "Turns on all compiled in debug printing", NULL),
  emberCommandEntryActionWithDetails("off", printOffCommand, "u", "Turns off compiled in debug printing for a specific debug printing are ...", debugprintOffCommandArguments),
  emberCommandEntryActionWithDetails("on", printOnCommand, "u", "Turns on compiled in debug printing for a specific debug printing area ...", debugprintOnCommandArguments),
  emberCommandEntryActionWithDetails("status", emberAfPrintStatus, "", "Prints out the current settings for debug printing on the device", NULL),
  emberCommandEntryTerminator(),
};
void echoCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const echoCommandArguments[] = {
  "bool indicating whether to turn echo on (1) or off (0)",
  NULL
};
#endif


void enableDisableEndpoint(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const endpointDisableCommandArguments[] = {
  "Endpoint in question.",
  NULL
};
#endif


void enableDisableEndpoint(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const endpointEnableCommandArguments[] = {
  "Endpoint in question.",
  NULL
};
#endif


void endpointPrint(void);
static EmberCommandEntry emberCommandEndpointTable[] = {
  emberCommandEntryActionWithDetails("disable", enableDisableEndpoint, "u", "Disable the endpoint for processing ZCL messages.", endpointDisableCommandArguments),
  emberCommandEntryActionWithDetails("enable", enableDisableEndpoint, "u", "Enable the endpoint for processing ZCL messages.", endpointEnableCommandArguments),
  emberCommandEntryActionWithDetails("print", endpointPrint, "", "Print the status of all the endpoints.", NULL),
  emberCommandEntryTerminator(),
};
void printEvents(void);
void helpCommand(void);
void emAfCliInfoCommand(void);
void interpanCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const interpanGroupCommandArguments[] = {
  "group id to send to",
  "destination pan id",
  "destination profile ID",
  NULL
};
#endif


void interpanLongCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const interpanLongCommandArguments[] = {
  "long ieee address to send the interpan message to",
  "two byte destination PA ID",
  "two byte destination profile ID",
  "two byte options",
  NULL
};
#endif


void interpanCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const interpanShortCommandArguments[] = {
  "group id to send to",
  "destination pan id",
  "destination profile ID",
  NULL
};
#endif


static EmberCommandEntry emberCommandInterpanTable[] = {
  emberCommandEntryActionWithDetails("group", interpanCommand, "vvv", "send an interpan message to a group id.", interpanGroupCommandArguments),
  emberCommandEntryActionWithDetails("long", interpanLongCommand, "bvvv", "Send an interpan message to a long address (8 byte eui64)", interpanLongCommandArguments),
  emberCommandEntryActionWithDetails("short", interpanCommand, "vvv", "Send an interpan message to a short id.", interpanShortCommandArguments),
  emberCommandEntryTerminator(),
};
void keysClearCommand(void);
void keysDeleteCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const keysDeleteCommandArguments[] = {
  "index into the security key table",
  NULL
};
#endif


void keysPrintCommand(void);
static EmberCommandEntry emberCommandKeysTable[] = {
  emberCommandEntryActionWithDetails("clear", keysClearCommand, "", "Clear all security keys", NULL),
  emberCommandEntryActionWithDetails("delete", keysDeleteCommand, "u", "Delete a security key from a given index", keysDeleteCommandArguments),
  emberCommandEntryActionWithDetails("print", keysPrintCommand, "", "Print all security keys out to the command line.", NULL),
  emberCommandEntryTerminator(),
};
void printAllLibraryStatus(void);
void networkPermitJoinCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkBroadPjoinCommandArguments[] = {
  "Number of seconds during which devices will be allowed to join the net ...",
  NULL
};
#endif


void networkChangeChannelCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkChangeChannelCommandArguments[] = {
  "The channel to change to.",
  NULL
};
#endif


void changeKeepAliveModeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkChangeKeepAliveModeCommandArguments[] = {
  "The keep alive mode.",
  NULL
};
#endif


void networkExtendedPanIdCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkExtpanidCommandArguments[] = {
  "The bytes for the extended pan id",
  NULL
};
#endif


void findJoinableNetworkCommand(void);
void findUnusedPanIdCommand(void);
static EmberCommandEntry emberCommandNetworkFindTable[] = {
  emberCommandEntryActionWithDetails("joinable", findJoinableNetworkCommand, "", "Begin a search for a joinable networ ...", NULL),
  emberCommandEntryActionWithDetails("unused", findUnusedPanIdCommand, "", "Begin a search for an unused Channel and Pan I ...", NULL),
  emberCommandEntryTerminator(),
};
void networkFormCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkFormCommandArguments[] = {
  "The channel on which to form the network",
  "One byte signed value indicating the TX power that the radio should be ...",
  "Two byte pan id for the network",
  NULL
};
#endif


void networkIdCommand(void);
void networkInitCommand(void);
void networkJoinCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkJoinCommandArguments[] = {
  "The channel on which to form the network",
  "One byte signed value indicating the TX power that the radio should be ...",
  "Two byte pan id for the network",
  NULL
};
#endif


void networkLeaveCommand(void);
void networkMultiPhyStartCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkMultiPhyStartCommandArguments[] = {
  "The page on which to form the network.",
  "The channel on which to form the network.",
  "One byte signed value indicating the TX power that the radio should be ...",
  "",
  NULL
};
#endif


void networkMultiPhyStopCommand(void);
void networkPermitJoinCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkPjoinCommandArguments[] = {
  "Number of seconds during which devices will be allowed to join the net ...",
  NULL
};
#endif


void networkRejoinCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkRejoinCommandArguments[] = {
  "Boolean indicating whether the device can rejoin secure or no ...",
  "4 byte channel mask which should be used to search for the network to  ...",
  NULL
};
#endif


void networkRejoinDiffDeviceTypeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkRejoinDiffDeviceTypeCommandArguments[] = {
  "Boolean indicating whether the device can rejoin secure or no ...",
  "4 byte channel mask which should be used to search for the network to  ...",
  "An enumeration indicating the device type to rejoin a ...",
  NULL
};
#endif


void networkSetCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkSetCommandArguments[] = {
  "The network index to use for CLI commands",
  NULL
};
#endif


void networkChangeChildTimeoutOptionMaskCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const networkTimeoutOptionMaskCommandArguments[] = {
  "The timeout option mask.",
  NULL
};
#endif


static EmberCommandEntry emberCommandNetworkTable[] = {
  emberCommandEntryActionWithDetails("broad-pjoin", networkPermitJoinCommand, "u", "Permit joining on the network for a given number of seconds AND broadc ...", networkBroadPjoinCommandArguments),
  emberCommandEntryActionWithDetails("change-channel", networkChangeChannelCommand, "u", "Attempts to change device over to a different channel given in the cha ...", networkChangeChannelCommandArguments),
  emberCommandEntryActionWithDetails("change-keep-alive-mode", changeKeepAliveModeCommand, "u", "Switch between different keep alive modes supported by a router", networkChangeKeepAliveModeCommandArguments),
  emberCommandEntryActionWithDetails("extpanid", networkExtendedPanIdCommand, "b", "Write the extended pan id for the device.", networkExtpanidCommandArguments),
  emberCommandEntrySubMenu("find", emberCommandNetworkFindTable, ""),
  emberCommandEntryActionWithDetails("form", networkFormCommand, "usv", "Create a network on the given channel, power and panId.", networkFormCommandArguments),
  emberCommandEntryActionWithDetails("id", networkIdCommand, "", "Prints the current Node ID, EUI64, and Pan ID.", NULL),
  emberCommandEntryActionWithDetails("init", networkInitCommand, "", "Initialize a network; this is a test command used for tc-swap-out test ...", NULL),
  emberCommandEntryActionWithDetails("join", networkJoinCommand, "usv", "Join an existing network on the given channel, power and panId.", networkJoinCommandArguments),
  emberCommandEntryActionWithDetails("leave", networkLeaveCommand, "", "Leave the current network.", NULL),
  emberCommandEntryActionWithDetails("multi-phy-start", networkMultiPhyStartCommand, "uus*", "To start multi phy interface other than native and form the networ ...", networkMultiPhyStartCommandArguments),
  emberCommandEntryActionWithDetails("multi-phy-stop", networkMultiPhyStopCommand, "", "Terminates the multi phy interface", NULL),
  emberCommandEntryActionWithDetails("pjoin", networkPermitJoinCommand, "u", "Permit joining on the network for a given number of seconds", networkPjoinCommandArguments),
  emberCommandEntryActionWithDetails("rejoin", networkRejoinCommand, "uw", "Rejoin an existing network in a secure or insecure manner.", networkRejoinCommandArguments),
  emberCommandEntryActionWithDetails("rejoin-diff-device-type", networkRejoinDiffDeviceTypeCommand, "uwu", "Rejoin an existing network in a secure or insecure manner with a diffe ...", networkRejoinDiffDeviceTypeCommandArguments),
  emberCommandEntryActionWithDetails("set", networkSetCommand, "u", "Set the network index used by all future CLI command ...", networkSetCommandArguments),
  emberCommandEntryActionWithDetails("timeout-option-mask", networkChangeChildTimeoutOptionMaskCommand, "v", "Attempts to change child timeout option mask to filter out undesirable ...", networkTimeoutOptionMaskCommandArguments),
  emberCommandEntryTerminator(),
};
void optionApsRetryCommand(void);
void optionApsRetryCommand(void);
void optionApsRetryCommand(void);
static EmberCommandEntry emberCommandOptionApsretryTable[] = {
  emberCommandEntryActionWithDetails("default", optionApsRetryCommand, "", "Forces the AppFramework to set/clear the APS Retry option (in APS Fram ...", NULL),
  emberCommandEntryActionWithDetails("off", optionApsRetryCommand, "", "Forces the AppFramework to set/clear the APS Retry option (in APS Fram ...", NULL),
  emberCommandEntryActionWithDetails("on", optionApsRetryCommand, "", "Forces the AppFramework to set/clear the APS Retry option (in APS Fram ...", NULL),
  emberCommandEntryTerminator(),
};
void optionBindingTableClearCommand(void);
void optionBindingTablePrintCommand(void);
void optionBindingTableSetCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const optionBindingTableSetCommandArguments[] = {
  "one byte index into the binding table",
  "cluster id to send with the discovery message",
  "local endpoint to bind",
  "remote endpoint to bind",
  "8 byte IEEE address provided big endian",
  NULL
};
#endif


static EmberCommandEntry emberCommandOptionBindingTableTable[] = {
  emberCommandEntryActionWithDetails("clear", optionBindingTableClearCommand, "", "Clear the binding table", NULL),
  emberCommandEntryActionWithDetails("print", optionBindingTablePrintCommand, "", "Prints out the binding table to the command line.", NULL),
  emberCommandEntryActionWithDetails("set", optionBindingTableSetCommand, "uvuub", "Set a binding table entry for the arguments specified.", optionBindingTableSetCommandArguments),
  emberCommandEntryTerminator(),
};
void optionDiscoverCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const optionDiscCommandArguments[] = {
  "the profile id to send with the discovery message",
  "cluster id to send with the discovery message",
  NULL
};
#endif


void optionEndDeviceBindCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const optionEdbCommandArguments[] = {
  "The local endpoint whose simple descriptor will be used to create the  ...",
  NULL
};
#endif


void optionInstallCodeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD) && !defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
static const char * const optionInstallCodeCommandArguments[] = {
  "index into the link key table",
  "IEEE address to enter into the link key table",
  "install code including two-byte, little-endian CRC",
  NULL
};
#endif


void optionLinkCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const optionLinkCommandArguments[] = {
  "index into the link key table",
  "IEEE address to enter into the link key table",
  "link key to enter into the table",
  NULL
};
#endif


void optionPrintRxCommand(void);
void optionPrintRxCommand(void);
static EmberCommandEntry emberCommandOptionPrintRxMsgsTable[] = {
  emberCommandEntryActionWithDetails("disable", optionPrintRxCommand, "", "Disable the printing of received messages.", NULL),
  emberCommandEntryActionWithDetails("enable", optionPrintRxCommand, "", "Enable the printing of received messages.", NULL),
  emberCommandEntryTerminator(),
};
void optionRegisterCommand(void);
void optionApsSecurityCommand(void);
void optionApsSecurityCommand(void);
static EmberCommandEntry emberCommandOptionSecurityApsTable[] = {
  emberCommandEntryActionWithDetails("off", optionApsSecurityCommand, "", "Turns aps security off", NULL),
  emberCommandEntryActionWithDetails("on", optionApsSecurityCommand, "", "Turns aps security on", NULL),
  emberCommandEntryTerminator(),
};
void optionSecurityAllowTrustCenterRejoinUsingWellKnownKey(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const optionSecuritySetAllowTrustCenterRejoinUsingWellKnownKeyCommandArguments[] = {
  "Whether or not the Trust Center should allow trust center rejoins for  ...",
  NULL
};
#endif


void optionSecurityAllowTrustCenterRejoinUsingWellKnownKeyTimeout(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const optionSecuritySetAllowTrustCenterRejoinUsingWellKnownKeyTimeoutCommandArguments[] = {
  "The number of seconds that trust center rejoins will be responded to u ...",
  NULL
};
#endif


void optionSecuritySetKeyRequestPolicy(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const optionSecuritySetKeyRequestPolicyCommandArguments[] = {
  "The value to assign to emberTrustCenterLinkKeyRequestPolicy",
  "The value to assign to emberAppLinkKeyRequestPolicy",
  NULL
};
#endif


static EmberCommandEntry emberCommandOptionSecurityTable[] = {
  emberCommandEntrySubMenu("aps", emberCommandOptionSecurityApsTable, ""),
  emberCommandEntryActionWithDetails("set-allow-trust-center-rejoin-using-well-known-key", optionSecurityAllowTrustCenterRejoinUsingWellKnownKey, "u", "Set whether or not a Trust Center application will allow trust center  ...", optionSecuritySetAllowTrustCenterRejoinUsingWellKnownKeyCommandArguments),
  emberCommandEntryActionWithDetails("set-allow-trust-center-rejoin-using-well-known-key-timeout", optionSecurityAllowTrustCenterRejoinUsingWellKnownKeyTimeout, "v", "Sets the number of seconds to allow trust center rejoins for devices u ...", optionSecuritySetAllowTrustCenterRejoinUsingWellKnownKeyTimeoutCommandArguments),
  emberCommandEntryActionWithDetails("set-key-request-policy", optionSecuritySetKeyRequestPolicy, "uu", "Sets the local policy for handling TC link key requests and applicatio ...", optionSecuritySetKeyRequestPolicyCommandArguments),
  emberCommandEntryTerminator(),
};
static EmberCommandEntry emberCommandOptionTable[] = {
  emberCommandEntrySubMenu("apsretry", emberCommandOptionApsretryTable, ""),
  emberCommandEntrySubMenu("binding-table", emberCommandOptionBindingTableTable, ""),
  emberCommandEntryActionWithDetails("disc", optionDiscoverCommand, "vv", "Sends a ZDO Match Descriptor Request for the server side of the specif ...", optionDiscCommandArguments),
  emberCommandEntryActionWithDetails("edb", optionEndDeviceBindCommand, "u", "Sends a ZDO End Device Bind Request using the given local endpoint.", optionEdbCommandArguments),
#if !defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
  emberCommandEntryActionWithDetails("install-code", optionInstallCodeCommand, "ubb", "Derives a link key from an install code and sets it in the link key ta ...", optionInstallCodeCommandArguments),
#endif //!defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
  emberCommandEntryActionWithDetails("link", optionLinkCommand, "ubb", "Sets a link key in the link key tabl ...", optionLinkCommandArguments),
  emberCommandEntrySubMenu("print-rx-msgs", emberCommandOptionPrintRxMsgsTable, ""),
  emberCommandEntryActionWithDetails("register", optionRegisterCommand, "", "Initiates Smart Energy Registration including Key Establishmen ...", NULL),
  emberCommandEntrySubMenu("security", emberCommandOptionSecurityTable, ""),
  emberCommandEntryTerminator(),
};
void emberAfPluginCounterPrintCounterTypeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginCounterPrintCounterTypeCommandArguments[] = {
  "The counter type       to print.",
  NULL
};
#endif


static EmberCommandEntry emberCommandPluginCounterTable[] = {
  emberCommandEntryActionWithDetails("print-counter-type", emberAfPluginCounterPrintCounterTypeCommand, "u", "Print value of this particular counter.", pluginCounterPrintCounterTypeCommandArguments),
  emberCommandEntryTerminator(),
};
void emberAfPluginCountersClear(void);
void emberAfPluginCountersPrintCommand(void);
void emberAfPluginCountersPrintThresholdsCommand(void);
void emberAfPluginCountersResetThresholds(void);
void emberAfPluginCountersSendRequestCommand(void);
void emberAfPluginCountersSetThresholdCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginCountersSetThresholdCommandArguments[] = {
  "type of counter",
  "Threshold Value",
  NULL
};
#endif


void emberAfPluginCountersSimplePrintCommand(void);
static EmberCommandEntry emberCommandPluginCountersTable[] = {
  emberCommandEntryActionWithDetails("clear", emberAfPluginCountersClear, "", "Clear all counter values.", NULL),
  emberCommandEntryActionWithDetails("print", emberAfPluginCountersPrintCommand, "", "Print all counter values and clear them.", NULL),
  emberCommandEntryActionWithDetails("print-thresholds", emberAfPluginCountersPrintThresholdsCommand, "", "Prints the thresholds of all the counters.", NULL),
  emberCommandEntryActionWithDetails("reset-threshold", emberAfPluginCountersResetThresholds, "", "Resets all thresholds values to 0xFFFF.", NULL),
  emberCommandEntryActionWithDetails("send-request", emberAfPluginCountersSendRequestCommand, "", "Sends a request for ota counters", NULL),
  emberCommandEntryActionWithDetails("set-threshold", emberAfPluginCountersSetThresholdCommand, "uv", "Set a threshold value for a particular type of counter.", pluginCountersSetThresholdCommandArguments),
  emberCommandEntryActionWithDetails("simple-print", emberAfPluginCountersSimplePrintCommand, "", "Print all counter values.", NULL),
  emberCommandEntryTerminator(),
};
void emAfEepromDataPrintCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginEepromDataPrintCommandArguments[] = {
  "The offset within the EEPROM to print.",
  NULL
};
#endif


void emAfEepromInfoCommand(void);
void emAfEepromStatusCommand(void);
static EmberCommandEntry emberCommandPluginEepromTable[] = {
  emberCommandEntryActionWithDetails("data-print", emAfEepromDataPrintCommand, "w", "Print raw bytes stored in the EEPROM", pluginEepromDataPrintCommandArguments),
  emberCommandEntryActionWithDetails("info", emAfEepromInfoCommand, "", "Print detailed info about the EEPROM part.", NULL),
  emberCommandEntryActionWithDetails("status", emAfEepromStatusCommand, "", "Print the state of the EEPROM driver.", NULL),
  emberCommandEntryTerminator(),
};
void emberAfPluginEndDeviceSupportForceShortPollCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginEndDeviceSupportForceShortPollCommandArguments[] = {
  "The value indicating whether the device should short poll.",
  NULL
};
#endif


void emberAfPluginEndDeviceSupportPollCompletedCallbackCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginEndDeviceSupportPollCompletedCallbackCommandArguments[] = {
  "The value indicating whether the device's poll completed callback func ...",
  NULL
};
#endif


void emberAfPluginEndDeviceSupportStatusCommand(void);
static EmberCommandEntry emberCommandPluginEndDeviceSupportTable[] = {
  emberCommandEntryActionWithDetails("force-short-poll", emberAfPluginEndDeviceSupportForceShortPollCommand, "u", "Sets whether the CLI forces the device to short poll.", pluginEndDeviceSupportForceShortPollCommandArguments),
  emberCommandEntryActionWithDetails("poll-completed-callback", emberAfPluginEndDeviceSupportPollCompletedCallbackCommand, "u", "Sets whether the device's poll completed callback function is enabled.", pluginEndDeviceSupportPollCompletedCallbackCommandArguments),
  emberCommandEntryActionWithDetails("status", emberAfPluginEndDeviceSupportStatusCommand, "", "Display the status of the End Device's polling.", NULL),
  emberCommandEntryTerminator(),
};
void emberAfPluginFindAndBindInitiatorStartCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginFindAndBindInitiatorCommandArguments[] = {
  "The endpoint on which to begin the Finding and Binding initiator proce ...",
  NULL
};
#endif


static EmberCommandEntry emberCommandPluginFindAndBindTable[] = {
  emberCommandEntryActionWithDetails("initiator", emberAfPluginFindAndBindInitiatorStartCommand, "u", "Makes this node start the initiator part of the finding and binding pr ...", pluginFindAndBindInitiatorCommandArguments),
  emberCommandEntryTerminator(),
};
void emAfPluginIdentifyCliPrint(void);
static EmberCommandEntry emberCommandPluginIdentifyTable[] = {
  emberCommandEntryActionWithDetails("print", emAfPluginIdentifyCliPrint, "", "Print which endpoints are reporting.", NULL),
  emberCommandEntryTerminator(),
};
void emberAfPluginIdleSleepAwakeWhenNotJoinedCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginIdleSleepAwakeWhenNotJoinedCommandArguments[] = {
  "The value indicating whether the device should stay awake when not joi ...",
  NULL
};
#endif


void emberAfPluginIdleSleepStayAwakeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginIdleSleepForceAwakeCommandArguments[] = {
  "The value indicating whether the device should stay awake.",
  NULL
};
#endif


void emberAfPluginIdleSleepStatusCommand(void);
static EmberCommandEntry emberCommandPluginIdleSleepTable[] = {
  emberCommandEntryActionWithDetails("awake-when-not-joined", emberAfPluginIdleSleepAwakeWhenNotJoinedCommand, "u", "Sets whether the device stays awake when not joined to a ZigBee networ ...", pluginIdleSleepAwakeWhenNotJoinedCommandArguments),
  emberCommandEntryActionWithDetails("force-awake", emberAfPluginIdleSleepStayAwakeCommand, "u", "Sets whether the device is forced to stay awake.", pluginIdleSleepForceAwakeCommandArguments),
  emberCommandEntryActionWithDetails("status", emberAfPluginIdleSleepStatusCommand, "", "Display the status of the sleeping behavior.", NULL),
  emberCommandEntryTerminator(),
};
void emAfInterpanDisableCommand(void);
void emAfInterpanEnableCommand(void);
void emAfInterpanFragmentTestCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginInterpanFragmentTestCommandArguments[] = {
  "The PAN ID that the target is located on",
  "The target's EUI64 (big endian)",
  "The cluster ID that the sample message should contain",
  "The length of the randomly-filled message to be sent across inter-PAN",
  NULL
};
#endif


void emAfInterpanSetMessageTimeoutCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginInterpanSetMsgTimeoutCommandArguments[] = {
  "Message timeout in seconds.",
  NULL
};
#endif


static EmberCommandEntry emberCommandPluginInterpanTable[] = {
  emberCommandEntryActionWithDetails("disable", emAfInterpanDisableCommand, "", "Disables inter-PAN globally.", NULL),
  emberCommandEntryActionWithDetails("enable", emAfInterpanEnableCommand, "", "Enables inter-PAN globally.", NULL),
  emberCommandEntryActionWithDetails("fragment-test", emAfInterpanFragmentTestCommand, "vbvv", "Sends a message of specified length of random values to target device  ...", pluginInterpanFragmentTestCommandArguments),
  emberCommandEntryActionWithDetails("set-msg-timeout", emAfInterpanSetMessageTimeoutCommand, "u", "Sets the timeout for inter-PAN messages sent and received.", pluginInterpanSetMsgTimeoutCommandArguments),
  emberCommandEntryTerminator(),
};
void emAfMfglibEnableMfglib(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibMfgenableCommandArguments[] = {
  "1 = enable, 0 = disable.",
  NULL
};
#endif


void emAfMfglibProgramEuiCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibProgramEuiCommandArguments[] = {
  "IEEE address to program.",
  NULL
};
#endif


void emAfMfglibSendMessageCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSendMessageCommandArguments[] = {
  "The hex data to send, up to 16 bytes.",
  "The number of packets to send.",
  NULL
};
#endif


void emAfMfglibSendCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSendRandomCommandArguments[] = {
  "The number of packets to send.",
  "The length of the packet to send.",
  NULL
};
#endif


void emAfMfglibSendCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSendTestCommandArguments[] = {
  "The number of packets to send.",
  "The length of the packet to send.",
  NULL
};
#endif


static EmberCommandEntry emberCommandPluginMfglibSendTable[] = {
  emberCommandEntryActionWithDetails("message", emAfMfglibSendMessageCommand, "bv", "Send a test message with the specified data in it.", pluginMfglibSendMessageCommandArguments),
  emberCommandEntryActionWithDetails("random", emAfMfglibSendCommand, "vu", "Send a series of test packets with random data..", pluginMfglibSendRandomCommandArguments),
  emberCommandEntryActionWithDetails("test", emAfMfglibSendCommand, "vu", "Send a series of test packets with fixed data.", pluginMfglibSendTestCommandArguments),
  emberCommandEntryTerminator(),
};
void emAfMfglibSetChannelCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetChannelCommandArguments[] = {
  "The 802.15.4 channel number.",
  NULL
};
#endif


void emAfMfglibSetOptions(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetOptionsCommandArguments[] = {
  "The options bitmask (0 = normal transmit, 1 = CSMA transmit).",
  NULL
};
#endif


void emAfMfglibSetPowerAndModeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetPowerCommandArguments[] = {
  "The power level",
  "The power mode",
  NULL
};
#endif


void emAfMfglibSleepCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSleepCommandArguments[] = {
  "Sleep duration (mS).",
  NULL
};
#endif


void emAfMfglibStartCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibStartCommandArguments[] = {
  "Use the Rx callback.",
  NULL
};
#endif


void emAfMfglibStatusCommand(void);
void emAfMfglibStopCommand(void);
void emAfMfglibStreamStartCommand(void);
void emAfMfglibStreamStopCommand(void);
static EmberCommandEntry emberCommandPluginMfglibStreamTable[] = {
  emberCommandEntryActionWithDetails("start", emAfMfglibStreamStartCommand, "", "Start the stream test.", NULL),
  emberCommandEntryActionWithDetails("stop", emAfMfglibStreamStopCommand, "", "Stop the stream test.", NULL),
  emberCommandEntryTerminator(),
};
void emAfMfglibToneStartCommand(void);
void emAfMfglibToneStopCommand(void);
static EmberCommandEntry emberCommandPluginMfglibToneTable[] = {
  emberCommandEntryActionWithDetails("start", emAfMfglibToneStartCommand, "", "Starts a tone test.", NULL),
  emberCommandEntryActionWithDetails("stop", emAfMfglibToneStopCommand, "", "Stops the tone test.", NULL),
  emberCommandEntryTerminator(),
};
////MFG UPDATED CODE START -----------------------------------------------------------------------------------------------------------------
void emAfMfglibClearPackets(void);
void emAfMfglibSetPower(void); ////
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetPowerArguments[] = {
  "The power level",
  NULL
};
#endif

void emAfMfglibGetPower(void) ;
void emAfMfglibSetCcaThresholdReg(void) ; ///
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetCcaThresholdRegArguments[] = {
  "The CCA Threshold",
  NULL
};
#endif

void emAfMfglibGetCcaThresholdReg(void);
void emAfMfglibGetCtuneValueReg(void);
void emAfMfglibSetCtuneValueReg(void); //
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetCtuneValueRegArguments[] = {
  "The CTUNE value",
  NULL
};
#endif

void emAfMfglibGetCcaThresholdTok(void);
void emAfMfglibSetCcaThresholdTok(void); //
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetCcaThresholdTokArguments[] = {
  "The CCA Threshold token",
  NULL
};
#endif

void emAfMfglibGetCtuneValueTok(void) ;
void emAfMfglibSetCtuneValueTok(void) ; //
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetCtuneValueTokArguments[] = {
  "The CTUNE value token",
  NULL
};
#endif


void emAfMfglibSetGpio(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSetGpioArguments[] = {
  "port",
  "pin",
  "mode",
  "out",
  NULL
};
#endif

void emAfMfglibGetGpio(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibGetGpioArguments[] = {
	"port",
	"pin",
  NULL
};
#endif

void emAfMfglibGpioHelp(void);
void emAfMfglibTokDump(void);
void emAfMfglibSleepTest(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibSleepTestArguments[] = {
  "mode",
  NULL
};
#endif

void emAfMfglibEnterBootloader(void);

void emAfMfglibPERTest(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibPERtestArguments[] = {
  "The number of packets to send.",
  "The length of the interval between packets in microseconds.",
  NULL
};
#endif

void emAfMfglibContinuousPacket(void);
void emAfMfglibStopContinuous(void);
void emAfMfglibClearPacketCounter(void);
void emAfMfglibGetPackets(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginThroughputSetIntervalCommandArguments[] = {
  "Interval in ms",
  NULL
};
#endif

void emAfMfglibReceiveMode(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibreceiveModeArguments[] = {
  "The Mode",
  NULL
};
#endif

void emAfMfglibReceiveStart(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginMfglibreceiveModeArguments[] = {
  "The number of packets",
  NULL
};
#endif

void emAfMfglibReceiveStop(void);

///MFG UPDATED CODE END-----------------------------------------------------------------------------------------------------------------------

static EmberCommandEntry emberCommandPluginMfglibTable[] = {
  emberCommandEntryActionWithDetails("mfgenable", emAfMfglibEnableMfglib, "u", "Enable mfglib.", pluginMfglibMfgenableCommandArguments),
  emberCommandEntryActionWithDetails("programEui", emAfMfglibProgramEuiCommand, "b", "Program EUI.", pluginMfglibProgramEuiCommandArguments),
  emberCommandEntrySubMenu("send", emberCommandPluginMfglibSendTable, ""),
  emberCommandEntryActionWithDetails("set-channel", emAfMfglibSetChannelCommand, "u", "Sets the channel used by the manufacturing library for testing.", pluginMfglibSetChannelCommandArguments),
  emberCommandEntryActionWithDetails("set-options", emAfMfglibSetOptions, "u", "Sets options in the manufacturing library for testing.", pluginMfglibSetOptionsCommandArguments),
  emberCommandEntryActionWithDetails("set-power", emAfMfglibSetPowerAndModeCommand, "sv", "Set the power level and mode for the manufacturing test.", pluginMfglibSetPowerCommandArguments),
  emberCommandEntryActionWithDetails("sleep", emAfMfglibSleepCommand, "v", "Sleep.", pluginMfglibSleepCommandArguments),
  emberCommandEntryActionWithDetails("start", emAfMfglibStartCommand, "u", "Start the mfglib test mode.", pluginMfglibStartCommandArguments),
  emberCommandEntryActionWithDetails("status", emAfMfglibStatusCommand, "", "Prints the current status of the manufacturing library.", NULL),
  emberCommandEntryActionWithDetails("stop", emAfMfglibStopCommand, "", "Stop the mfglib test mode.", NULL),
  emberCommandEntrySubMenu("stream", emberCommandPluginMfglibStreamTable, ""),
  emberCommandEntrySubMenu("tone", emberCommandPluginMfglibToneTable, ""),
  ////MFG UPDATED CODE START
  emberCommandEntryActionWithDetails("clear-rx-packets",emAfMfglibClearPackets, "", "reset the number of received packets to 0", NULL),
  emberCommandEntryActionWithDetails("set-deci-dbm",emAfMfglibSetPower, "q", "Sets the power of radio transmissions(deci-dBm)", pluginMfglibSetPowerArguments),
  emberCommandEntryActionWithDetails("get-deci-dbm",emAfMfglibGetPower, "", "Gets the power of radio transmissions(deci-dBm)", NULL),
  emberCommandEntryActionWithDetails("set-cca",emAfMfglibSetCcaThresholdReg, "s", "Sets the temporary register value of the CCA threshold", pluginMfglibSetCcaThresholdRegArguments),
  emberCommandEntryActionWithDetails("get-cca",emAfMfglibGetCcaThresholdReg, "", "Gets the temporary register value of the CCA threshold", NULL),
  emberCommandEntryActionWithDetails("get-ctune-reg",emAfMfglibGetCtuneValueReg, "", "Gets the temporary register of the CTUNE value", NULL),
  emberCommandEntryActionWithDetails("set-ctune-reg",emAfMfglibSetCtuneValueReg, "v", "Sets the temporary register of the CTUNE value", pluginMfglibSetCtuneValueRegArguments),
  emberCommandEntryActionWithDetails("get-cca-tok",emAfMfglibGetCcaThresholdTok, "", "Gets the token value of the CCA threshold", NULL),
  emberCommandEntryActionWithDetails("set-cca-tok",emAfMfglibSetCcaThresholdTok, "v", "Sets the token value of the CCA threshold", pluginMfglibSetCcaThresholdTokArguments),
  emberCommandEntryActionWithDetails("get-ctune-tok",emAfMfglibGetCtuneValueTok, "", "Gets the token of the CTUNE value", NULL),
  emberCommandEntryActionWithDetails("set-ctune-tok",emAfMfglibSetCtuneValueTok, "v", "Sets the token of the CTUNE value", pluginMfglibSetCtuneValueTokArguments),
  emberCommandEntryActionWithDetails("set-gpio",emAfMfglibSetGpio, "?w?w", "Sets various gpio settings", pluginMfglibSetGpioArguments),
  emberCommandEntryActionWithDetails("get-gpio",emAfMfglibGetGpio, "?w", "Gets GPIO mode at a specified GPIO port and pin", pluginMfglibGetGpioArguments),
  emberCommandEntryActionWithDetails("gpio-help",emAfMfglibGpioHelp, "", "Gives information of GPIO command inputs", NULL),
  emberCommandEntryActionWithDetails("tok-dump",emAfMfglibTokDump, "", "Dumps all tokens", NULL),
  emberCommandEntryActionWithDetails("set-sleep",emAfMfglibSleepTest, "u", "Enters the specified sleep mode", pluginMfglibSleepTestArguments),
  emberCommandEntryActionWithDetails("enter-bl",emAfMfglibEnterBootloader, "", "Enters the bootloader mode", NULL),
  emberCommandEntryActionWithDetails("per-test",emAfMfglibPERTest, "vv", "Sends specified # of packets at the specified interval to all devices on the same network set to receive;PER is displayed on the receiving device", pluginMfglibPERTestArguments),
  emberCommandEntryActionWithDetails("contPack-start",emAfMfglibContinuousPacket, "", "Starts sending continuous packets at a 1000 millisecond interval", NULL),
  emberCommandEntryActionWithDetails("contPack-stop",emAfMfglibStopContinuous, "", "Stops sending continuous packets", NULL),
  emberCommandEntryActionWithDetails("receive-mode",emAfMfglibReceiveMode, "s", "Sets the print mode for incoming packets", pluginMfglibReceiveModeArguments),
  emberCommandEntryActionWithDetails("receivePER-start",emAfMfglibReceiveStart, "v", "Sets up receive mode for PER test by clearing packets and setting # of incoming packets", pluginMfglibemAfMfglibReceiveStartArguments),
  emberCommandEntryActionWithDetails("receivePER-stop",emAfMfglibReceiveStop, "", "Stops receive mode and prints out PER data", NULL),
  emberCommandEntryActionWithDetails("clear-tx-packets",emAfMfglibClearPacketCounter, "", "Clears the packet Counter(number of transmitted packets)", NULL),
  emberCommandEntryActionWithDetails("get-tx-packets",emAfMfglibGetPackets, "", "Prints packet Counter(number of transmitted packets)", NULL),
  emberCommandEntryTerminator(),
};
//MFG UPDATED CODE END----------------------------------------------------
void emberAfPluginNetworkSteeringChannelAddOrSubtractCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginNetworkSteeringMaskAddCommandArguments[] = {
  "The channel mask to add a channel to.",
  "The channel to add to the mask.",
  NULL
};
#endif


void emberAfPluginNetworkSteeringChannelSetCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginNetworkSteeringMaskSetCommandArguments[] = {
  "The channel mask to subtract the channel from.",
  "The value to set the channel mask to.",
  NULL
};
#endif


void emberAfPluginNetworkSteeringChannelAddOrSubtractCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginNetworkSteeringMaskSubtractCommandArguments[] = {
  "The channel mask to subtract the channel from.",
  "The channel to subtract the mask from.",
  NULL
};
#endif


static EmberCommandEntry emberCommandPluginNetworkSteeringMaskTable[] = {
  emberCommandEntryActionWithDetails("add", emberAfPluginNetworkSteeringChannelAddOrSubtractCommand, "uu", "Adds a channel to either the primary or secondary channel mask of the  ...", pluginNetworkSteeringMaskAddCommandArguments),
  emberCommandEntryActionWithDetails("set", emberAfPluginNetworkSteeringChannelSetCommand, "uw", "Set either the primary or secondary channel mask.", pluginNetworkSteeringMaskSetCommandArguments),
  emberCommandEntryActionWithDetails("subtract", emberAfPluginNetworkSteeringChannelAddOrSubtractCommand, "uu", "Subtracts a channel from either the primary or secondary channel mask  ...", pluginNetworkSteeringMaskSubtractCommandArguments),
  emberCommandEntryTerminator(),
};
void emberAfPluginNetworkSteeringSetPreconfiguredKeyCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginNetworkSteeringPreConfiguredKeySetCommandArguments[] = {
  "Set the preconfigured key so that the joining device can enter the net ...",
  NULL
};
#endif


void emberAfPluginNetworkSteeringStartCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginNetworkSteeringStartCommandArguments[] = {
  "A mask of options for indicating specific behavior within the network- ...",
  NULL
};
#endif


void emberAfPluginNetworkSteeringStatusCommand(void);
void emberAfPluginNetworkSteeringStopCommand(void);
static EmberCommandEntry emberCommandPluginNetworkSteeringTable[] = {
  emberCommandEntrySubMenu("mask", emberCommandPluginNetworkSteeringMaskTable, ""),
  emberCommandEntryActionWithDetails("pre-configured-key-set", emberAfPluginNetworkSteeringSetPreconfiguredKeyCommand, "b", "Set the pre-configured key", pluginNetworkSteeringPreConfiguredKeySetCommandArguments),
  emberCommandEntryActionWithDetails("start", emberAfPluginNetworkSteeringStartCommand, "u", "Starts the network steering process.", pluginNetworkSteeringStartCommandArguments),
  emberCommandEntryActionWithDetails("status", emberAfPluginNetworkSteeringStatusCommand, "", "Displays the current status of the network steering process.", NULL),
  emberCommandEntryActionWithDetails("stop", emberAfPluginNetworkSteeringStopCommand, "", "Stops the network steering process.", NULL),
  emberCommandEntryTerminator(),
};
void emberAfPluginSetTCLinkKeyUpdateTimerCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginUpdateTcLinkKeyTimerCommandArguments[] = {
  "The amount of time between subsequent trust center link key updates in ...",
  NULL
};
#endif


static EmberCommandEntry emberCommandPluginUpdateTcLinkKeyTable[] = {
  emberCommandEntryActionWithDetails("timer", emberAfPluginSetTCLinkKeyUpdateTimerCommand, "w", "This sets the the amount of time between subsequent trust center link  ...", pluginUpdateTcLinkKeyTimerCommandArguments),
  emberCommandEntryTerminator(),
};
void abortTouchLink(void);
void cancelRxOn(void);
void setScanChannel(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningChannelCommandArguments[] = {
  "The primary channel to be used.",
  NULL
};
#endif


void disable(void);
void enable(void);
void getEndpointListRequest(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningEndpointsCommandArguments[] = {
  "The network address of the device to which the request will be sent.",
  "The source endpoint from which the request will be sent.",
  "The destination endpoint to which the request will be sent.",
  "The endpoint index at which to start retreiving data.",
  NULL
};
#endif


void formNetwork(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningFormCommandArguments[] = {
  "The channel on which to form the network.",
  "The power setting for network transmissions.",
  "The PAN identifier for the network.",
  NULL
};
#endif


void getGroupIdentifiersRequest(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningGroupsCommandArguments[] = {
  "The network address of the device to which the request will be sent.",
  "The source endpoint from which the request will be sent.",
  "The destination endpoint to which the request will be sent.",
  "The group table index at which to start retreiving data.",
  NULL
};
#endif


void setIdentifyDuration(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningIdentifyCommandArguments[] = {
  "The duration (in tenths of a second) of identify mode or 0xFFFF to ind ...",
  NULL
};
#endif


void endpointInformation(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningInfoCommandArguments[] = {
  "The network address of the device to which the request will be sent.",
  "The source endpoint from which the request will be sent.",
  "The destination endpoint to which the request will be sent.",
  NULL
};
#endif


void joinable(void);
void initiateTouchLink(void);
void setScanMask(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningMaskCommandArguments[] = {
  "The index of the channel mask to be used.",
  NULL
};
#endif


void noTouchlinkForNFN(void);
void emberAfZllResetToFactoryNew(void);
void rxOnStatus(void);
void scanTouchLink(void);
void scanTouchLink(void);
void scanTouchLink(void);
static EmberCommandEntry emberCommandPluginZllCommissioningScanTable[] = {
  emberCommandEntryActionWithDetails("device", scanTouchLink, "", "Initiate a touch link for the purpose of retrieving information about  ...", NULL),
  emberCommandEntryActionWithDetails("identify", scanTouchLink, "", "Initiate a touch link for the purpose of causing a target device to id ...", NULL),
  emberCommandEntryActionWithDetails("reset", scanTouchLink, "", "Initiate a touch link for the purpose of resetting a target device.", NULL),
  emberCommandEntryTerminator(),
};
void setSecondaryScanChannel(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningSecondaryChannelCommandArguments[] = {
  "The secondary channel to be used.",
  NULL
};
#endif


void setRxOn(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const pluginZllCommissioningSetRxOnCommandArguments[] = {
  "The duration for the Rx On period.",
  NULL
};
#endif


void statusCommand(void);
void printZllTokens(void);
void unused(void);
static EmberCommandEntry emberCommandPluginZllCommissioningTable[] = {
  emberCommandEntryActionWithDetails("abort", abortTouchLink, "", "Abort the touch link procedure.", NULL),
  emberCommandEntryActionWithDetails("cancel-rx-on", cancelRxOn, "", "Cancel Rx On When Idle.", NULL),
  emberCommandEntryActionWithDetails("channel", setScanChannel, "u", "Set the scan channel used by the ZLL Commissioning plugin.", pluginZllCommissioningChannelCommandArguments),
  emberCommandEntryActionWithDetails("disable", disable, "", "Disable touchlinking. This will override the notouchlink-nfn command.", NULL),
  emberCommandEntryActionWithDetails("enable", enable, "", "Enable touchlinking. This will override the notouchlink-nfn command.", NULL),
  emberCommandEntryActionWithDetails("endpoints", getEndpointListRequest, "vuuu", "Send a GetEndpointListRequest to a server.", pluginZllCommissioningEndpointsCommandArguments),
  emberCommandEntryActionWithDetails("form", formNetwork, "usv", "Form a ZLL network.", pluginZllCommissioningFormCommandArguments),
  emberCommandEntryActionWithDetails("groups", getGroupIdentifiersRequest, "vuuu", "Send a GroupIdentifiersRequest to a server.", pluginZllCommissioningGroupsCommandArguments),
  emberCommandEntryActionWithDetails("identify", setIdentifyDuration, "v", "Set the duration that a target device should remain in identify mode d ...", pluginZllCommissioningIdentifyCommandArguments),
  emberCommandEntryActionWithDetails("info", endpointInformation, "vuu", "Send an EndpointInformationRequest to a client.", pluginZllCommissioningInfoCommandArguments),
  emberCommandEntryActionWithDetails("joinable", joinable, "", "Scan for joinable networks and attempt to join if a network is found.", NULL),
  emberCommandEntryActionWithDetails("link", initiateTouchLink, "", "Initiate the touch link procedure.", NULL),
  emberCommandEntryActionWithDetails("mask", setScanMask, "u", "Set the scan channel set used by the ZLL Commissioning plugi ...", pluginZllCommissioningMaskCommandArguments),
  emberCommandEntryActionWithDetails("notouchlink-nfn", noTouchlinkForNFN, "", "Disable touchlinking for NFN.", NULL),
  emberCommandEntryActionWithDetails("reset", emberAfZllResetToFactoryNew, "", "Reset the local device to factory new.", NULL),
  emberCommandEntryActionWithDetails("rx-on-active", rxOnStatus, "", "Get Rx On When Idle status.", NULL),
  emberCommandEntrySubMenu("scan", emberCommandPluginZllCommissioningScanTable, ""),
  emberCommandEntryActionWithDetails("secondary-channel", setSecondaryScanChannel, "u", "Set the scan channel used by the ZLL Commissioning plugin.", pluginZllCommissioningSecondaryChannelCommandArguments),
  emberCommandEntryActionWithDetails("set-rx-on", setRxOn, "w", "Set Rx On When Idle duration.", pluginZllCommissioningSetRxOnCommandArguments),
  emberCommandEntryActionWithDetails("status", statusCommand, "", "Print the ZLL channel set and tokens.", NULL),
  emberCommandEntryActionWithDetails("tokens", printZllTokens, "", "Print the ZLL tokens.", NULL),
  emberCommandEntryActionWithDetails("unused", unused, "", "Scan for an unused PAN identifier and form a new ZLL network.", NULL),
  emberCommandEntryTerminator(),
};
static EmberCommandEntry emberCommandPluginTable[] = {
  emberCommandEntrySubMenu("counter", emberCommandPluginCounterTable, ""),
  emberCommandEntrySubMenu("counters", emberCommandPluginCountersTable, ""),
  emberCommandEntrySubMenu("eeprom", emberCommandPluginEepromTable, ""),
  emberCommandEntrySubMenu("end-device-support", emberCommandPluginEndDeviceSupportTable, ""),
  emberCommandEntrySubMenu("find-and-bind", emberCommandPluginFindAndBindTable, ""),
  emberCommandEntrySubMenu("identify", emberCommandPluginIdentifyTable, ""),
  emberCommandEntrySubMenu("idle-sleep", emberCommandPluginIdleSleepTable, ""),
  emberCommandEntrySubMenu("interpan", emberCommandPluginInterpanTable, ""),
  emberCommandEntrySubMenu("mfglib", emberCommandPluginMfglibTable, ""),
  emberCommandEntrySubMenu("network-steering", emberCommandPluginNetworkSteeringTable, ""),
  emberCommandEntrySubMenu("update-tc-link-key", emberCommandPluginUpdateTcLinkKeyTable, ""),
  emberCommandEntrySubMenu("zll-commissioning", emberCommandPluginZllCommissioningTable, ""),
  emberCommandEntryTerminator(),
};
void emberAfPrintAttributeTable(void);
void emberAfPrintEntropySource(void);
static EmberCommandEntry emberCommandPrintEntropyTable[] = {
  emberCommandEntryActionWithDetails("source", emberAfPrintEntropySource, "", "Print the the entropy source that is used for true random number gener ...", NULL),
  emberCommandEntryTerminator(),
};
void printTimeCommand(void);
static EmberCommandEntry emberCommandPrintTable[] = {
  emberCommandEntryActionWithDetails("attr", emberAfPrintAttributeTable, "", "Print the attribute table.", NULL),
  emberCommandEntrySubMenu("entropy", emberCommandPrintEntropyTable, ""),
  emberCommandEntryActionWithDetails("time", printTimeCommand, "", "Print out the time information", NULL),
  emberCommandEntryTerminator(),
};
void emAfCliRawCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const rawCommandArguments[] = {
  "two byte cluster id",
  "ZCL message, including ZCL header and payload",
  NULL
};
#endif


void emAfCliReadCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const readCommandArguments[] = {
  "endpoint of the attribute to read",
  "cluster id of the attribute to read",
  "attribute id of the attribute to read",
  "direction mask of the attribute to read (client=0 or server=1)",
  NULL
};
#endif


void resetCommand(void);
void getSetMfgToken(void);
void getSetMfgToken(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD) && !defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
static const char * const securityMfgTokenSetCommandArguments[] = {
  "magic number",
  "value",
  NULL
};
#endif


static EmberCommandEntry emberCommandSecurityMfgTokenTable[] = {
#if !defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
  emberCommandEntryActionWithDetails("get", getSetMfgToken, "", "", NULL),
#endif //!defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
#if !defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
  emberCommandEntryActionWithDetails("set", getSetMfgToken, "wv", "", securityMfgTokenSetCommandArguments),
#endif //!defined(EMBER_AF_HAS_SECURITY_PROFILE_NONE)
  emberCommandEntryTerminator(),
};
static EmberCommandEntry emberCommandSecurityTable[] = {
  emberCommandEntrySubMenu("mfg-token", emberCommandSecurityMfgTokenTable, ""),
  emberCommandEntryTerminator(),
};
void emAfCliSendCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const sendCommandArguments[] = {
  "short id of the device to send the message to",
  "The endpoint to send the message from",
  "The endpoint to send the message to",
  NULL
};
#endif


void emAfCliSendUsingMulticastBindingCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const sendUsingMulticastBindingCommandArguments[] = {
  "Whether to send via a multicast binding",
  NULL
};
#endif


void emAfCliSendCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const sendMulticastCommandArguments[] = {
  "group id of the multicast group to send the message to",
  "The endpoint to send the message from",
  NULL
};
#endif


void emAfCliTimesyncCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const timesyncCommandArguments[] = {
  "two byte short id of the time server",
  "source endpoint to send time sync from",
  "destination endpoint to expect response on",
  NULL
};
#endif


void emAfCliVersionCommand(void);
void emAfCliWriteCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const writeCommandArguments[] = {
  "endpoint of the attribute to write",
  "cluster id of the attribute to write",
  "attribute id of the attribute to write",
  "direction mask of the attribute to write (client=0 or server=1)",
  "the attribute type as listed in the generated file attribute-type.h",
  "string of bytes you wish to write into the attribute table.",
  NULL
};
#endif


static void zclBasicGlsrCommand(void) {
  zclSimpleServerCommand( ZCL_BASIC_CLUSTER_ID,
                          ZCL_GET_LOCALES_SUPPORTED_RESPONSE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclBasicGlsrCommandArguments[] = {
  "discovery complete",
  "locale supported",
  "",
  NULL
};
#endif


static EmberCommandEntry emberCommandZclBasicTable[] = {
  emberCommandEntryActionWithDetails("glsr", zclBasicGlsrCommand, "ub*", "The locales supported response command is sent in response to a get lo ...", zclBasicGlsrCommandArguments),
  emberCommandEntryTerminator(),
};
static void zclColorControlEmovehueCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_ENHANCED_MOVE_HUE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlEmovehueCommandArguments[] = {
  "move mode",
  "rate",
  NULL
};
#endif


static void zclColorControlEmovetohueCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_ENHANCED_MOVE_TO_HUE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlEmovetohueCommandArguments[] = {
  "enhanced hue",
  "direction",
  "transition time",
  NULL
};
#endif


static void zclColorControlEmovetohueandsatCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_ENHANCED_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlEmovetohueandsatCommandArguments[] = {
  "enhanced hue",
  "saturation",
  "transition time",
  NULL
};
#endif


static void zclColorControlEstephueCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_ENHANCED_STEP_HUE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlEstephueCommandArguments[] = {
  "step mode",
  "step size",
  "transition time",
  NULL
};
#endif


static void zclColorControlLoopCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_COLOR_LOOP_SET_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlLoopCommandArguments[] = {
  "update flags",
  "action",
  "direction",
  "time",
  "start hue",
  NULL
};
#endif


static void zclColorControlMovecolorCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_COLOR_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovecolorCommandArguments[] = {
  "rate x",
  "rate y",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovecolortempCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_COLOR_TEMPERATURE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovecolortempCommandArguments[] = {
  "move mode",
  "rate",
  "color temperature minimum",
  "color temperature maximum",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovehueCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_HUE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovehueCommandArguments[] = {
  "move mode",
  "rate",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovesatCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_SATURATION_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovesatCommandArguments[] = {
  "move mode",
  "rate",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovetocolorCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_TO_COLOR_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovetocolorCommandArguments[] = {
  "color x",
  "color y",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovetocolortempCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_TO_COLOR_TEMPERATURE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovetocolortempCommandArguments[] = {
  "color temperature",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovetohueCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_TO_HUE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovetohueCommandArguments[] = {
  "hue",
  "direction",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovetohueandsatCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovetohueandsatCommandArguments[] = {
  "hue",
  "saturation",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlMovetosatCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_TO_SATURATION_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlMovetosatCommandArguments[] = {
  "saturation",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlStepcolorCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_STEP_COLOR_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlStepcolorCommandArguments[] = {
  "step x",
  "step y",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlStepcolortempCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_STEP_COLOR_TEMPERATURE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlStepcolortempCommandArguments[] = {
  "step mode",
  "step size",
  "transition time",
  "color temperature minimum",
  "color temperature maximum",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlStephueCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_STEP_HUE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlStephueCommandArguments[] = {
  "step mode",
  "step size",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlStepsatCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_STEP_SATURATION_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlStepsatCommandArguments[] = {
  "step mode",
  "step size",
  "transition time",
  "options mask",
  "options override",
  NULL
};
#endif


static void zclColorControlStopmovestepCommand(void) {
  zclSimpleClientCommand( ZCL_COLOR_CONTROL_CLUSTER_ID,
                          ZCL_STOP_MOVE_STEP_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclColorControlStopmovestepCommandArguments[] = {
  "options mask",
  "options override",
  NULL
};
#endif


static EmberCommandEntry emberCommandZclColorControlTable[] = {
  emberCommandEntryActionWithDetails("emovehue", zclColorControlEmovehueCommand, "uv", "Command description for EnhancedMoveHue", zclColorControlEmovehueCommandArguments),
  emberCommandEntryActionWithDetails("emovetohue", zclColorControlEmovetohueCommand, "vuv", "Command description for EnhancedMoveToHue", zclColorControlEmovetohueCommandArguments),
  emberCommandEntryActionWithDetails("emovetohueandsat", zclColorControlEmovetohueandsatCommand, "vuv", "Command description for EnhancedMoveToHueAndSaturation", zclColorControlEmovetohueandsatCommandArguments),
  emberCommandEntryActionWithDetails("estephue", zclColorControlEstephueCommand, "uvv", "Command description for EnhancedStepHue", zclColorControlEstephueCommandArguments),
  emberCommandEntryActionWithDetails("loop", zclColorControlLoopCommand, "uuuvv", "Command description for ColorLoopSet", zclColorControlLoopCommandArguments),
  emberCommandEntryActionWithDetails("movecolor", zclColorControlMovecolorCommand, "rr!uu", "Moves the color.", zclColorControlMovecolorCommandArguments),
  emberCommandEntryActionWithDetails("movecolortemp", zclColorControlMovecolortempCommand, "uvvv!uu", "Command description for MoveColorTemperature", zclColorControlMovecolortempCommandArguments),
  emberCommandEntryActionWithDetails("movehue", zclColorControlMovehueCommand, "uu!uu", "Move hue up or down at specified rate.", zclColorControlMovehueCommandArguments),
  emberCommandEntryActionWithDetails("movesat", zclColorControlMovesatCommand, "uu!uu", "Move saturation up or down at specified rate.", zclColorControlMovesatCommandArguments),
  emberCommandEntryActionWithDetails("movetocolor", zclColorControlMovetocolorCommand, "vvv!uu", "Move to specified color.", zclColorControlMovetocolorCommandArguments),
  emberCommandEntryActionWithDetails("movetocolortemp", zclColorControlMovetocolortempCommand, "vv!uu", "Move to a specific color temperature.", zclColorControlMovetocolortempCommandArguments),
  emberCommandEntryActionWithDetails("movetohue", zclColorControlMovetohueCommand, "uuv!uu", "Move to specified hue.", zclColorControlMovetohueCommandArguments),
  emberCommandEntryActionWithDetails("movetohueandsat", zclColorControlMovetohueandsatCommand, "uuv!uu", "Move to hue and saturation.", zclColorControlMovetohueandsatCommandArguments),
  emberCommandEntryActionWithDetails("movetosat", zclColorControlMovetosatCommand, "uv!uu", "Move to specified saturation.", zclColorControlMovetosatCommandArguments),
  emberCommandEntryActionWithDetails("stepcolor", zclColorControlStepcolorCommand, "rrv!uu", "Steps the lighting to a specific color.", zclColorControlStepcolorCommandArguments),
  emberCommandEntryActionWithDetails("stepcolortemp", zclColorControlStepcolortempCommand, "uvvvv!uu", "Command description for StepColorTemperature", zclColorControlStepcolortempCommandArguments),
  emberCommandEntryActionWithDetails("stephue", zclColorControlStephueCommand, "uuu!uu", "Step hue up or down by specified size at specified rate.", zclColorControlStephueCommandArguments),
  emberCommandEntryActionWithDetails("stepsat", zclColorControlStepsatCommand, "uuu!uu", "Step saturation up or down by specified size at specified rate.", zclColorControlStepsatCommandArguments),
  emberCommandEntryActionWithDetails("stopmovestep", zclColorControlStopmovestepCommand, "!uu", "Command description for StopMoveStep", zclColorControlStopmovestepCommandArguments),
  emberCommandEntryTerminator(),
};
void zclGlobalDirectionCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalDirectionCommandArguments[] = {
  "The direction for global commands, 0 = client to server, 1 = server to ...",
  NULL
};
#endif


void zclGlobalCommandDiscoveryCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalDiscComGenCommandArguments[] = {
  "The cluster to find commands on.",
  "The command id to start the command search on.",
  "Max command ids to search for.",
  NULL
};
#endif


void zclGlobalCommandDiscoveryCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalDiscComRecCommandArguments[] = {
  "The cluster to find commands on.",
  "The command id to start the command search on.",
  "Max command ids to search for.",
  NULL
};
#endif


void zclGlobalDiscoverCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalDiscoverCommandArguments[] = {
  "The cluster id of the cluster to discover.",
  "The attribute id of the attribute to read during discovery.",
  "Max number of discovery responses.",
  NULL
};
#endif


void zclGlobalExpectReportFromMeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalExpectReportFromMeCommandArguments[] = {
  "The cluster id for the requested report.",
  "The attribute id for the requested report.",
  "Maximum amount of time between reports.",
  NULL
};
#endif


void zclGlobalWriteCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalNwriteCommandArguments[] = {
  "The cluster id of the cluster to read from.",
  "The attribute id of the attribute to read.",
  "The type of the attribute to write.",
  "The data to be written.",
  NULL
};
#endif


void zclGlobalReadCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalReadCommandArguments[] = {
  "The cluster id of the cluster to read from.",
  "The attribute id of the attribute to read.",
  NULL
};
#endif


void zclGlobalReportCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalReportCommandArguments[] = {
  "The desired endpoint.",
  "The cluster id.",
  "The attribute id.",
  "The mask.",
  NULL
};
#endif


void zclGlobalReportReadCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalReportReadCommandArguments[] = {
  "The cluster id to read from.",
  "The attribute id to read from.",
  "0 for client-to-server, 1 for server-to-client.",
  NULL
};
#endif


void zclGlobalSendMeAReportCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalSendMeAReportCommandArguments[] = {
  "The cluster id of the requested report.",
  "The attribute id for requested report.",
  "The two byte ZigBee type value for the requested report.",
  "Minimum number of seconds between reports.",
  "Maximum number of seconds between reports.",
  "Amount of change to trigger a report.",
  NULL
};
#endif


void zclGlobalWriteCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalUwriteCommandArguments[] = {
  "The cluster id of the cluster to write to.",
  "The attribute id of the attribute to write.",
  "The type of the attribute to write.",
  "The data to be written.",
  NULL
};
#endif


void zclGlobalWriteCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclGlobalWriteCommandArguments[] = {
  "The cluster id of the cluster to write to.",
  "The attribute id of the attribute to write.",
  "The type of the attribute to write.",
  "The data to be written.",
  NULL
};
#endif


static EmberCommandEntry emberCommandZclGlobalTable[] = {
  emberCommandEntryActionWithDetails("direction", zclGlobalDirectionCommand, "u", "Sets the direction for global commands, either client to server or ser ...", zclGlobalDirectionCommandArguments),
  emberCommandEntryActionWithDetails("disc-com-gen", zclGlobalCommandDiscoveryCommand, "vuu", "Create a Discover Commands Generated command with associated values.", zclGlobalDiscComGenCommandArguments),
  emberCommandEntryActionWithDetails("disc-com-rec", zclGlobalCommandDiscoveryCommand, "vuu", "Create a Discover Commands Received command with associated values.", zclGlobalDiscComRecCommandArguments),
  emberCommandEntryActionWithDetails("discover", zclGlobalDiscoverCommand, "vvu", "Creates discovery message for devices with the associated cluster and  ...", zclGlobalDiscoverCommandArguments),
  emberCommandEntryActionWithDetails("expect-report-from-me", zclGlobalExpectReportFromMeCommand, "vvv", "Create a expect-report-from-me message with associated values.", zclGlobalExpectReportFromMeCommandArguments),
  emberCommandEntryActionWithDetails("nwrite", zclGlobalWriteCommand, "vvub", "Creates a global write command message to write to the cluster and att ...", zclGlobalNwriteCommandArguments),
  emberCommandEntryActionWithDetails("read", zclGlobalReadCommand, "vv", "Creates a global read command message to read from the cluster and att ...", zclGlobalReadCommandArguments),
  emberCommandEntryActionWithDetails("report", zclGlobalReportCommand, "uvvu", "", zclGlobalReportCommandArguments),
  emberCommandEntryActionWithDetails("report-read", zclGlobalReportReadCommand, "vvu", "Creates a global read reporting command for the associated cluster, at ...", zclGlobalReportReadCommandArguments),
  emberCommandEntryActionWithDetails("send-me-a-report", zclGlobalSendMeAReportCommand, "vvuvvb", "Creates a global send me a report command for the associated values.", zclGlobalSendMeAReportCommandArguments),
  emberCommandEntryActionWithDetails("uwrite", zclGlobalWriteCommand, "vvub", "Creates a global write undivided command message to write to the clust ...", zclGlobalUwriteCommandArguments),
  emberCommandEntryActionWithDetails("write", zclGlobalWriteCommand, "vvwb", "Creates a global write command message to write to the cluster and att ...", zclGlobalWriteCommandArguments),
  emberCommandEntryTerminator(),
};
static void zclIdentifyEzModeCommand(void) {
  zclSimpleClientCommand( ZCL_IDENTIFY_CLUSTER_ID,
                          ZCL_E_Z_MODE_INVOKE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclIdentifyEzModeCommandArguments[] = {
  "action",
  NULL
};
#endif


static void zclIdentifyIdCommand(void) {
  zclSimpleClientCommand( ZCL_IDENTIFY_CLUSTER_ID,
                          ZCL_IDENTIFY_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclIdentifyIdCommandArguments[] = {
  "identify time",
  NULL
};
#endif


void zclIdentifyOnOffCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclIdentifyOffCommandArguments[] = {
  "The endpoint on which to stop identifying",
  NULL
};
#endif


void zclIdentifyOnOffCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclIdentifyOnCommandArguments[] = {
  "The endpoint on the device which should begin identifying",
  "The number of seconds to spend identifying",
  NULL
};
#endif


static void zclIdentifyQueryCommand(void) {
  zclSimpleClientCommand( ZCL_IDENTIFY_CLUSTER_ID,
                          ZCL_IDENTIFY_QUERY_COMMAND_ID);
}

static void zclIdentifyTriggerCommand(void) {
  zclSimpleClientCommand( ZCL_IDENTIFY_CLUSTER_ID,
                          ZCL_TRIGGER_EFFECT_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclIdentifyTriggerCommandArguments[] = {
  "effect id",
  "effect variant",
  NULL
};
#endif


static EmberCommandEntry emberCommandZclIdentifyTable[] = {
  emberCommandEntryActionWithDetails("ez-mode", zclIdentifyEzModeCommand, "u", "Invoke EZMode on an Identify Server", zclIdentifyEzModeCommandArguments),
  emberCommandEntryActionWithDetails("id", zclIdentifyIdCommand, "v", "Command description for Identify", zclIdentifyIdCommandArguments),
  emberCommandEntryActionWithDetails("off", zclIdentifyOnOffCommand, "u", "Writes the IdentifyTime attribute", zclIdentifyOffCommandArguments),
  emberCommandEntryActionWithDetails("on", zclIdentifyOnOffCommand, "uv", "Writes the IdentifyTime attribute", zclIdentifyOnCommandArguments),
  emberCommandEntryActionWithDetails("query", zclIdentifyQueryCommand, "", "Command description for IdentifyQuery", NULL),
  emberCommandEntryActionWithDetails("trigger", zclIdentifyTriggerCommand, "uu", "Command description for TriggerEffect", zclIdentifyTriggerCommandArguments),
  emberCommandEntryTerminator(),
};
static void zclLevelControlMoveCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclLevelControlMoveCommandArguments[] = {
  "move mode",
  "rate",
  "option mask",
  "option override",
  NULL
};
#endif


static void zclLevelControlMvToLevelCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_TO_LEVEL_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclLevelControlMvToLevelCommandArguments[] = {
  "level",
  "transition time",
  "option mask",
  "option override",
  NULL
};
#endif


static void zclLevelControlOMoveCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_WITH_ON_OFF_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclLevelControlOMoveCommandArguments[] = {
  "move mode",
  "rate",
  NULL
};
#endif


static void zclLevelControlOMvToLevelCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_MOVE_TO_LEVEL_WITH_ON_OFF_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclLevelControlOMvToLevelCommandArguments[] = {
  "level",
  "transition time",
  NULL
};
#endif


static void zclLevelControlOStepCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_STEP_WITH_ON_OFF_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclLevelControlOStepCommandArguments[] = {
  "step mode",
  "step size",
  "transition time",
  NULL
};
#endif


static void zclLevelControlOStopCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_STOP_WITH_ON_OFF_COMMAND_ID);
}

static void zclLevelControlStepCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_STEP_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclLevelControlStepCommandArguments[] = {
  "step mode",
  "step size",
  "transition time",
  "option mask",
  "option override",
  NULL
};
#endif


static void zclLevelControlStopCommand(void) {
  zclSimpleClientCommand( ZCL_LEVEL_CONTROL_CLUSTER_ID,
                          ZCL_STOP_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclLevelControlStopCommandArguments[] = {
  "option mask",
  "option override",
  NULL
};
#endif


static EmberCommandEntry emberCommandZclLevelControlTable[] = {
  emberCommandEntryActionWithDetails("move", zclLevelControlMoveCommand, "uu!uu", "Command description for Move", zclLevelControlMoveCommandArguments),
  emberCommandEntryActionWithDetails("mv-to-level", zclLevelControlMvToLevelCommand, "uv!uu", "Command description for MoveToLevel", zclLevelControlMvToLevelCommandArguments),
  emberCommandEntryActionWithDetails("o-move", zclLevelControlOMoveCommand, "uu", "Command description for MoveWithOnOff", zclLevelControlOMoveCommandArguments),
  emberCommandEntryActionWithDetails("o-mv-to-level", zclLevelControlOMvToLevelCommand, "uv", "Command description for MoveToLevelWithOnOff", zclLevelControlOMvToLevelCommandArguments),
  emberCommandEntryActionWithDetails("o-step", zclLevelControlOStepCommand, "uuv", "Command description for StepWithOnOff", zclLevelControlOStepCommandArguments),
  emberCommandEntryActionWithDetails("o-stop", zclLevelControlOStopCommand, "", "Command description for StopWithOnOff", NULL),
  emberCommandEntryActionWithDetails("step", zclLevelControlStepCommand, "uuv!uu", "Command description for Step", zclLevelControlStepCommandArguments),
  emberCommandEntryActionWithDetails("stop", zclLevelControlStopCommand, "!uu", "Command description for Stop", zclLevelControlStopCommandArguments),
  emberCommandEntryTerminator(),
};
void zclMfgCodeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclMfgCodeCommandArguments[] = {
  "Manufacturer Specific Id",
  NULL
};
#endif


static void zclOnOffOffCommand(void) {
  zclSimpleClientCommand( ZCL_ON_OFF_CLUSTER_ID,
                          ZCL_OFF_COMMAND_ID);
}

static void zclOnOffOffeffectCommand(void) {
  zclSimpleClientCommand( ZCL_ON_OFF_CLUSTER_ID,
                          ZCL_OFF_WITH_EFFECT_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclOnOffOffeffectCommandArguments[] = {
  "effect id",
  "effect variant",
  NULL
};
#endif


static void zclOnOffOnCommand(void) {
  zclSimpleClientCommand( ZCL_ON_OFF_CLUSTER_ID,
                          ZCL_ON_COMMAND_ID);
}

static void zclOnOffOnrecallCommand(void) {
  zclSimpleClientCommand( ZCL_ON_OFF_CLUSTER_ID,
                          ZCL_ON_WITH_RECALL_GLOBAL_SCENE_COMMAND_ID);
}

static void zclOnOffOntimedoffCommand(void) {
  zclSimpleClientCommand( ZCL_ON_OFF_CLUSTER_ID,
                          ZCL_ON_WITH_TIMED_OFF_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclOnOffOntimedoffCommandArguments[] = {
  "on off control",
  "on time",
  "off wait time",
  NULL
};
#endif


static void zclOnOffToggleCommand(void) {
  zclSimpleClientCommand( ZCL_ON_OFF_CLUSTER_ID,
                          ZCL_TOGGLE_COMMAND_ID);
}

static EmberCommandEntry emberCommandZclOnOffTable[] = {
  emberCommandEntryActionWithDetails("off", zclOnOffOffCommand, "", "Command description for Off", NULL),
  emberCommandEntryActionWithDetails("offeffect", zclOnOffOffeffectCommand, "uu", "Command description for OffWithEffect", zclOnOffOffeffectCommandArguments),
  emberCommandEntryActionWithDetails("on", zclOnOffOnCommand, "", "Command description for On", NULL),
  emberCommandEntryActionWithDetails("onrecall", zclOnOffOnrecallCommand, "", "Command description for OnWithRecallGlobalScene", NULL),
  emberCommandEntryActionWithDetails("ontimedoff", zclOnOffOntimedoffCommand, "uvv", "Command description for OnWithTimedOff", zclOnOffOntimedoffCommandArguments),
  emberCommandEntryActionWithDetails("toggle", zclOnOffToggleCommand, "", "Command description for Toggle", NULL),
  emberCommandEntryTerminator(),
};
static void zclScenesAddCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_ADD_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesAddCommandArguments[] = {
  "group id",
  "scene id",
  "transition time",
  "scene name",
  "extension field sets",
  "",
  NULL
};
#endif


static void zclScenesCopyCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_COPY_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesCopyCommandArguments[] = {
  "mode",
  "group id from",
  "scene id from",
  "group id to",
  "scene id to",
  NULL
};
#endif


static void zclScenesEaddCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_ENHANCED_ADD_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesEaddCommandArguments[] = {
  "group id",
  "scene id",
  "transition time",
  "scene name",
  "extension field sets",
  "",
  NULL
};
#endif


static void zclScenesEviewCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_ENHANCED_VIEW_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesEviewCommandArguments[] = {
  "group id",
  "scene id",
  NULL
};
#endif


static void zclScenesGetCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_GET_SCENE_MEMBERSHIP_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesGetCommandArguments[] = {
  "group id",
  NULL
};
#endif


static void zclScenesRecallCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_RECALL_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesRecallCommandArguments[] = {
  "group id",
  "scene id",
  "transition time",
  NULL
};
#endif


static void zclScenesRemoveCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_REMOVE_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesRemoveCommandArguments[] = {
  "group id",
  "scene id",
  NULL
};
#endif


static void zclScenesRmallCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_REMOVE_ALL_SCENES_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesRmallCommandArguments[] = {
  "group id",
  NULL
};
#endif


static void zclScenesStoreCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_STORE_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesStoreCommandArguments[] = {
  "group id",
  "scene id",
  NULL
};
#endif


static void zclScenesViewCommand(void) {
  zclSimpleClientCommand( ZCL_SCENES_CLUSTER_ID,
                          ZCL_VIEW_SCENE_COMMAND_ID);
}

#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclScenesViewCommandArguments[] = {
  "group id",
  "scene id",
  NULL
};
#endif


static EmberCommandEntry emberCommandZclScenesTable[] = {
  emberCommandEntryActionWithDetails("add", zclScenesAddCommand, "vuvbw*", "Add a scene to the scene tabl ...", zclScenesAddCommandArguments),
  emberCommandEntryActionWithDetails("copy", zclScenesCopyCommand, "uvuvu", "Command description for CopyScene", zclScenesCopyCommandArguments),
  emberCommandEntryActionWithDetails("eadd", zclScenesEaddCommand, "vuvbw*", "Command description for EnhancedAddScene", zclScenesEaddCommandArguments),
  emberCommandEntryActionWithDetails("eview", zclScenesEviewCommand, "vu", "Command description for EnhancedViewScene", zclScenesEviewCommandArguments),
  emberCommandEntryActionWithDetails("get", zclScenesGetCommand, "v", "Command description for GetSceneMembership", zclScenesGetCommandArguments),
  emberCommandEntryActionWithDetails("recall", zclScenesRecallCommand, "vuv", "Command description for RecallScene", zclScenesRecallCommandArguments),
  emberCommandEntryActionWithDetails("remove", zclScenesRemoveCommand, "vu", "Command description for RemoveScene", zclScenesRemoveCommandArguments),
  emberCommandEntryActionWithDetails("rmall", zclScenesRmallCommand, "v", "Command description for RemoveAllScenes", zclScenesRmallCommandArguments),
  emberCommandEntryActionWithDetails("store", zclScenesStoreCommand, "vu", "Command description for StoreScene", zclScenesStoreCommandArguments),
  emberCommandEntryActionWithDetails("view", zclScenesViewCommand, "vu", "Command description for ViewScene", zclScenesViewCommandArguments),
  emberCommandEntryTerminator(),
};
void zclTestResponseOffCommand(void);
void zclTestResponseOnCommand(void);
static EmberCommandEntry emberCommandZclTestResponseTable[] = {
  emberCommandEntryActionWithDetails("off", zclTestResponseOffCommand, "", "Sets a flag so that the application framework WILL NOT respond to the  ...", NULL),
  emberCommandEntryActionWithDetails("on", zclTestResponseOnCommand, "", "Sets a flag so that the application framework WILL respond to the next ...", NULL),
  emberCommandEntryTerminator(),
};
static EmberCommandEntry emberCommandZclTestTable[] = {
  emberCommandEntrySubMenu("response", emberCommandZclTestResponseTable, ""),
  emberCommandEntryTerminator(),
};
void zclTimeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclTimeCommandArguments[] = {
  "ZigBee UTC time, number of seconds since the year 2000",
  NULL
};
#endif


void zclUseNextSequenceCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclUseNextSequenceCommandArguments[] = {
  "bool value indicating whether raw command will use the incremented seq ...",
  NULL
};
#endif


void zclXDefaultRespCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zclXDefaultRespCommandArguments[] = {
  "bool value indicating whether the disable default response bit is set( ...",
  NULL
};
#endif


static EmberCommandEntry emberCommandZclTable[] = {
  emberCommandEntrySubMenu("basic", emberCommandZclBasicTable, ""),
  emberCommandEntrySubMenu("color-control", emberCommandZclColorControlTable, ""),
  emberCommandEntrySubMenu("global", emberCommandZclGlobalTable, ""),
  emberCommandEntrySubMenu("identify", emberCommandZclIdentifyTable, ""),
  emberCommandEntrySubMenu("level-control", emberCommandZclLevelControlTable, ""),
  emberCommandEntryActionWithDetails("mfg-code", zclMfgCodeCommand, "v", "Sets the two byte manufacturer specific identifier to use for the next ...", zclMfgCodeCommandArguments),
  emberCommandEntrySubMenu("on-off", emberCommandZclOnOffTable, ""),
  emberCommandEntrySubMenu("scenes", emberCommandZclScenesTable, ""),
  emberCommandEntrySubMenu("test", emberCommandZclTestTable, ""),
  emberCommandEntryActionWithDetails("time", zclTimeCommand, "w", "Cli command to call emberAfSetTime function documented in af.h", zclTimeCommandArguments),
  emberCommandEntryActionWithDetails("use-next-sequence", zclUseNextSequenceCommand, "u", "Sets the flag to use the incremented sequence number from the framewor ...", zclUseNextSequenceCommandArguments),
  emberCommandEntryActionWithDetails("x-default-resp", zclXDefaultRespCommand, "u", "Sets the Disable Default Response Frame Control bit to use for the nex ...", zclXDefaultRespCommandArguments),
  emberCommandEntryTerminator(),
};
void zdoActiveEpCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoActiveCommandArguments[] = {
  "Two byte short id, destination for the active endpoint request",
  NULL
};
#endif


void zdoBindCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoBindCommandArguments[] = {
  "Two byte destination node id",
  "Remote device's source endpoint to bind",
  "Remote endpoint to bind",
  "Cluster on which to bind",
  "Remote node EUI64",
  "Binding's dest EUI64.  Usually the local node's EUI64",
  NULL
};
#endif


void zdoIeeeAddressRequestCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoIeeeCommandArguments[] = {
  "Short address of the device for which a long address is requested",
  NULL
};
#endif


void zdoAddClusterCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoInClListAddCommandArguments[] = {
  "Server cluster id",
  NULL
};
#endif


void zdoClearClusterCommand(void);
static EmberCommandEntry emberCommandZdoInClListTable[] = {
  emberCommandEntryActionWithDetails("add", zdoAddClusterCommand, "v", "Add clusters to the known server (in) clusters on this device.", zdoInClListAddCommandArguments),
  emberCommandEntryActionWithDetails("clear", zdoClearClusterCommand, "", "Clear the ZDO list of server (in) clusters.", NULL),
  emberCommandEntryTerminator(),
};
void zdoLeaveRequestCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoLeaveCommandArguments[] = {
  "Target node ID",
  "Remove children",
  "Rejoin after leave",
  NULL
};
#endif


void zdoMatchCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoMatchCommandArguments[] = {
  "Two byte node id indicating wher",
  "Two byte profile id for the match descriptor request",
  NULL
};
#endif


void zdoMgmtBindCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoMgmtBindCommandArguments[] = {
  "Target node ID",
  "Starting index into table query",
  NULL
};
#endif


void zdoMgmtLqiCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoMgmtLqiCommandArguments[] = {
  "Target node ID",
  "Starting index into table query",
  NULL
};
#endif


void zdoNodeCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoNodeCommandArguments[] = {
  "Two byte address for the target device.",
  NULL
};
#endif


void zdoNwkAddressRequestCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoNwkCommandArguments[] = {
  "IEEE address for which a short address is being requested",
  NULL
};
#endif


void zdoNetworkUpdateChannelCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoNwkUpdChanCommandArguments[] = {
  "One byte channel to change to.",
  NULL
};
#endif


void zdoNetworkUpdateChannelCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoNwkUpdChanPgCommandArguments[] = {
  "One byte channel to change to.",
  "One byte page to change to.",
  NULL
};
#endif


void zdoNetworkUpdateScanCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoNwkUpdScanCommandArguments[] = {
  "Two byte short id of the target device",
  "One byte scan duration. Must be in range 0 - 5",
  "Number of scans to perform. Must be in range 1 - 8",
  NULL
};
#endif


void zdoNetworkUpdateScanCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoNwkUpdScanChanMaskCommandArguments[] = {
  "Two byte short id of the target device",
  "One byte scan duration. Must be in range 0 - 5",
  "Number of scans to perform. Must be in range 1 - 8",
  "Four byte channel mask",
  NULL
};
#endif


void zdoNetworkUpdateSetCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoNwkUpdSetCommandArguments[] = {
  "Two byte network manager id",
  "Four byte channel mask",
  NULL
};
#endif


static EmberCommandEntry emberCommandZdoNwkUpdTable[] = {
  emberCommandEntryActionWithDetails("chan", zdoNetworkUpdateChannelCommand, "u", "Sends an update channel request.", zdoNwkUpdChanCommandArguments),
  emberCommandEntryActionWithDetails("chanPg", zdoNetworkUpdateChannelCommand, "uu", "Sends an update channel page reques ...", zdoNwkUpdChanPgCommandArguments),
  emberCommandEntryActionWithDetails("scan", zdoNetworkUpdateScanCommand, "vuv", "Performs an energy scan.", zdoNwkUpdScanCommandArguments),
  emberCommandEntryActionWithDetails("scan-chan-mask", zdoNetworkUpdateScanCommand, "vuvw", "Performs an energy scan on given channel mas ...", zdoNwkUpdScanChanMaskCommandArguments),
  emberCommandEntryActionWithDetails("set", zdoNetworkUpdateSetCommand, "vw", "Broadcasts the ID of the new network manager and active channels.", zdoNwkUpdSetCommandArguments),
  emberCommandEntryTerminator(),
};
void zdoAddClusterCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoOutClListAddCommandArguments[] = {
  "Client cluster ids",
  NULL
};
#endif


void zdoClearClusterCommand(void);
static EmberCommandEntry emberCommandZdoOutClListTable[] = {
  emberCommandEntryActionWithDetails("add", zdoAddClusterCommand, "v", "Add clusters to the known client (out) clusters on this device.", zdoOutClListAddCommandArguments),
  emberCommandEntryActionWithDetails("clear", zdoClearClusterCommand, "", "Clear the ZDO list of client (out) clusters.", NULL),
  emberCommandEntryTerminator(),
};
void zdoPowerDescriptorRequestCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoPowerCommandArguments[] = {
  "Target node ID",
  NULL
};
#endif


void zdoRouteRequestCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoRouteCommandArguments[] = {
  "Target node ID",
  "The index of the remote node's routing table to request.",
  NULL
};
#endif


void zdoSimpleCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoSimpleCommandArguments[] = {
  "Short address of the device where the simple descriptor request should ...",
  "The endpoint on the target device where the simple descriptor request  ...",
  NULL
};
#endif


void zdoUnbindGroupCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoUnbindGroupCommandArguments[] = {
  "Target node ID",
  "The source EUI64 of the binding (the remote device's EUI64)",
  "The source endpoint of the binding.",
  "The cluster ID to unbind.",
  "The group address in the binding",
  NULL
};
#endif


void zdoUnbindUnicastCommand(void);
#if defined(EMBER_COMMAND_INTEPRETER_HAS_DESCRIPTION_FIELD)
static const char * const zdoUnbindUnicastCommandArguments[] = {
  "Target node ID",
  "The source EUI64 of the binding (the remote device's EUI64)",
  "The source endpoint of the binding.",
  "The cluster ID to unbind.",
  "The destination EUI64 in the binding (usually the local node's EUI64",
  "The destination endpoint of the binding",
  NULL
};
#endif


static EmberCommandEntry emberCommandZdoUnbindTable[] = {
  emberCommandEntryActionWithDetails("group", zdoUnbindGroupCommand, "vbuvv", "Sends an unbind request for a multicast binding to the target device.", zdoUnbindGroupCommandArguments),
  emberCommandEntryActionWithDetails("unicast", zdoUnbindUnicastCommand, "vbuvbu", "Sends an unbind request for a unicast binding to the target device.", zdoUnbindUnicastCommandArguments),
  emberCommandEntryTerminator(),
};
static EmberCommandEntry emberCommandZdoTable[] = {
  emberCommandEntryActionWithDetails("active", zdoActiveEpCommand, "v", "Send an active endpoint request to the device with the given short id.", zdoActiveCommandArguments),
  emberCommandEntryActionWithDetails("bind", zdoBindCommand, "vuuvbb", "Send a ZDO Bind command to a device specified in the command arguments ...", zdoBindCommandArguments),
  emberCommandEntryActionWithDetails("ieee", zdoIeeeAddressRequestCommand, "v", "Request an ieee address based on a given node id.", zdoIeeeCommandArguments),
  emberCommandEntrySubMenu("in-cl-list", emberCommandZdoInClListTable, ""),
  emberCommandEntryActionWithDetails("leave", zdoLeaveRequestCommand, "vuu", "Send a ZDO Management Leave command to the target device.", zdoLeaveCommandArguments),
  emberCommandEntryActionWithDetails("match", zdoMatchCommand, "vv", "Sends a matchDescriptorsRequest to the given destination with the give ...", zdoMatchCommandArguments),
  emberCommandEntryActionWithDetails("mgmt-bind", zdoMgmtBindCommand, "vu", "Send a ZDO MGMT-Bind (Binding Table) Request to the target device.", zdoMgmtBindCommandArguments),
  emberCommandEntryActionWithDetails("mgmt-lqi", zdoMgmtLqiCommand, "vu", "Send a ZDO MGMT-LQI (LQI Table) Request to the target device.", zdoMgmtLqiCommandArguments),
  emberCommandEntryActionWithDetails("node", zdoNodeCommand, "v", "Sends a node descriptor request to a given target device", zdoNodeCommandArguments),
  emberCommandEntryActionWithDetails("nwk", zdoNwkAddressRequestCommand, "b", "Sends a network address request for the given IEEE address.", zdoNwkCommandArguments),
  emberCommandEntrySubMenu("nwk-upd", emberCommandZdoNwkUpdTable, ""),
  emberCommandEntrySubMenu("out-cl-list", emberCommandZdoOutClListTable, ""),
  emberCommandEntryActionWithDetails("power", zdoPowerDescriptorRequestCommand, "v", "Send a ZDO Power Descriptor Request to the target device.", zdoPowerCommandArguments),
  emberCommandEntryActionWithDetails("route", zdoRouteRequestCommand, "vu", "Send a ZDO route request command to the target.", zdoRouteCommandArguments),
  emberCommandEntryActionWithDetails("simple", zdoSimpleCommand, "vu", "Sends out a simple descriptor request for the short address and endpoi ...", zdoSimpleCommandArguments),
  emberCommandEntrySubMenu("unbind", emberCommandZdoUnbindTable, ""),
  emberCommandEntryTerminator(),
};
EmberCommandEntry emberCommandTable[] = {
  emberCommandEntryActionWithDetails("bsend", emAfCliBsendCommand, "u", "Send using a binding based on the clusterId in the globalApsFrame and  ...", bsendCommandArguments),
  emberCommandEntrySubMenu("changekey", emberCommandChangekeyTable, ""),
  emberCommandEntrySubMenu("debugprint", emberCommandDebugprintTable, ""),
  emberCommandEntryActionWithDetails("echo", echoCommand, "u", "Turns echo on the command line on or off depending on the argument", echoCommandArguments),
  emberCommandEntrySubMenu("endpoint", emberCommandEndpointTable, ""),
  emberCommandEntryActionWithDetails("events", printEvents, "", "Print the list of timer events.", NULL),
  emberCommandEntryActionWithDetails("help", helpCommand, "", "Prints out the cli command options for the device", NULL),
  emberCommandEntryActionWithDetails("info", emAfCliInfoCommand, "", "Gives information about the local node", NULL),
  emberCommandEntrySubMenu("interpan", emberCommandInterpanTable, ""),
  emberCommandEntrySubMenu("keys", emberCommandKeysTable, ""),
  emberCommandEntryActionWithDetails("libs", printAllLibraryStatus, "", "Lists which optional libraries of the stack are implemented on this de ...", NULL),
  emberCommandEntrySubMenu("network", emberCommandNetworkTable, ""),
  emberCommandEntrySubMenu("option", emberCommandOptionTable, ""),
  emberCommandEntrySubMenu("plugin", emberCommandPluginTable, ""),
  emberCommandEntrySubMenu("print", emberCommandPrintTable, ""),
  emberCommandEntryActionWithDetails("raw", emAfCliRawCommand, "vb", "Creates a message by specifying the raw byte ...", rawCommandArguments),
  emberCommandEntryActionWithDetails("read", emAfCliReadCommand, "uvvu", "Read an attribute from the local attribute tabl ...", readCommandArguments),
  emberCommandEntryActionWithDetails("reset", resetCommand, "", "resets the device", NULL),
  emberCommandEntrySubMenu("security", emberCommandSecurityTable, ""),
  emberCommandEntryActionWithDetails("send", emAfCliSendCommand, "vuu", "Send a pre-buffered message from a given endpoint to an endpoint on a  ...", sendCommandArguments),
  emberCommandEntryActionWithDetails("send-using-multicast-binding", emAfCliSendUsingMulticastBindingCommand, "u", "When sending using a binding, specify whether a multicast binding shou ...", sendUsingMulticastBindingCommandArguments),
  emberCommandEntryActionWithDetails("send_multicast", emAfCliSendCommand, "vu", "Send a pre-buffered multicast message to a given group id from a given ...", sendMulticastCommandArguments),
  emberCommandEntryActionWithDetails("timesync", emAfCliTimesyncCommand, "vuu", "This sends a read attr for the time of the device specifie ...", timesyncCommandArguments),
  emberCommandEntryActionWithDetails("version", emAfCliVersionCommand, "", "Shows the version of the software", NULL),
  emberCommandEntryActionWithDetails("write", emAfCliWriteCommand, "uvvuub", "Write an attribute value into the local attribute table", writeCommandArguments),
  emberCommandEntrySubMenu("zcl", emberCommandZclTable, ""),
  emberCommandEntrySubMenu("zdo", emberCommandZdoTable, ""),
#ifdef EMBER_AF_ENABLE_CUSTOM_COMMANDS
  CUSTOM_COMMANDS
#endif // EMBER_AF_ENABLE_CUSTOM_COMMANDS
  emberCommandEntryTerminator(),
};

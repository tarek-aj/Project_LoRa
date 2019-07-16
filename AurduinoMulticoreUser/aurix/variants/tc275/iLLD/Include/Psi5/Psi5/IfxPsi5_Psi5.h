/**
 * \file IfxPsi5_Psi5.h
 * \brief PSI5 PSI5 details
 * \ingroup IfxLld_Psi5
 *
 * \version iLLD_1_0_0_11_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Psi5_Psi5_Usage How to use the PSI5 PSI5 Interface driver?
 * \ingroup IfxLld_Psi5
 *
 * PSI5 communicates with the external world via one input/output line for each channel.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Psi5_Psi5_Preparation Preparation
 * \subsection IfxLld_Psi5_Psi5_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Psi5/Psi5/IfxPsi5_Psi5.h>
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_Variables Variables
 * //used globally
 * \code
 * IfxPsi5_Psi5_Channel psi5Channel[IFXPSI5_PINMAP_NUM_CHANNELS];
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_Module Module Initialisation
 * \code
 *  // create module config
 *  IfxPsi5_Psi5_Config psi5Config;
 *  IfxPsi5_Psi5_initModuleConfig(&psi5Config, &MODULE_PSI5);
 *
 *  // initialize module
 *  IfxPsi5_Psi5 psi5;
 *  IfxPsi5_Psi5_initModule(&psi5, &psi5Config);
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_Channel Channel Initialisation
 * \code
 * // create channel config
 * IfxPsi5_Psi5_ChannelConfig psi5ChannelConfig;
 * IfxPsi5_Psi5_initChannelConfig(&psi5ChannelConfig, &psi5);
 *
 *     psi5ChannelConfig.watchdogTimerLimit[0] = 0x32; // initial delay before slot 0 starts
 *     psi5ChannelConfig.watchdogTimerLimit[1] = 0x90;
 *     psi5ChannelConfig.watchdogTimerLimit[2] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[3] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[4] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[5] = 0x10;
 *     psi5ChannelConfig.watchdogTimerLimit[6] = 0x10;
 *
 *     for(int slot=0; slot<6; ++slot) {
 *         psi5ChannelConfig.receiveControl.payloadLength[slot] = 8;
 *         if( slot == 0 )
 *             psi5ChannelConfig.receiveControl.frameExpectation[slot] = IfxPsi5_FrameExpectation_expected;
 *         else
 *             psi5ChannelConfig.receiveControl.frameExpectation[slot] = IfxPsi5_FrameExpectation_notExpected;
 *     }
 *
 *     // initialize channels
 *     for(int chn=0; chn<IFXPSI5_PINMAP_NUM_CHANNELS; ++chn) {
 *         psi5ChannelConfig.channelId = (IfxPsi5_ChannelId)chn;
 *
 *         // TODO: currently no IOCRx.ALTI config field
 *         unsigned alti = 0;
 *
 *         IfxPsi5_Psi5_PinsConfig pinsConfig;
 *         for(int module=0;module<IFXPSI5_PINMAP_NUM_MODULES;module++)
 *         {
 *          pinsConfig.in = IfxPsi5_Rx_In_pinTable[module][chn][alti];
 *          pinsConfig.inMode = IfxPort_InputMode_pullUp;
 *          pinsConfig.out = IfxPsi5_Tx_Out_pinTable[module][chn][alti];
 *         }
 *         pinsConfig.outMode = IfxPort_OutputMode_pushPull;
 *         pinsConfig.pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
 *
 *         psi5ChannelConfig.pinsConfig = &pinsConfig;
 *
 *         IfxPsi5_Psi5_initChannel(&psi5Channel[chn], &psi5ChannelConfig);
 *     }
 * \endcode
 *
 * \subsection IfxLld_Psi5_Psi5_readChannelFrame read channel frame
 * \code
 *     for(int i=0; i<5; ++i) {
 *         for(int chn=0; chn<IFXPSI5_PINMAP_NUM_CHANNELS; ++chn) {
 *             IfxPsi5_Psi5_Frame frame;
 *
 *             while( !IfxPsi5_Psi5_readChannelFrame(&psi5Channel[chn], &frame) );
 *
 *         }
 *     }
 * \endcode
 *
 * \defgroup IfxLld_Psi5_Psi5 PSI5
 * \ingroup IfxLld_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Structures Data Structures
 * \ingroup IfxLld_Psi5_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Module Module Initialisation functions
 * \ingroup IfxLld_Psi5_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Channel Channel functions
 * \ingroup IfxLld_Psi5_Psi5
 * \defgroup IfxLld_Psi5_Psi5_Clock Clock Intialisation functions
 * \ingroup IfxLld_Psi5_Psi5
 */

#ifndef IFXPSI5_PSI5_H
#define IFXPSI5_PSI5_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Psi5/Std/IfxPsi5.h"
#include "Scu/Std/IfxScuCcu.h"
#include "IfxPsi5_bf.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Psi5_Psi5_Structures
 * \{ */
/** \brief PSI5 handle data structure
 */
typedef struct
{
    Ifx_PSI5 *psi5;     /**< \brief Specifies the pointer to the PSI5 module registers */
} IfxPsi5_Psi5;

/** \brief channel trigger configuration structure
 */
typedef struct
{
    uint32 channelTriggerValue;       /**< \brief Specifies the channel trigger value CTV */
    uint32 channelTriggerCounter;     /**< \brief Specifies the channel trigger counter */
} IfxPsi5_Psi5_ChannelTrigger;

/** \brief Clock configuration data structure
 */
typedef struct
{
    uint32              frequency;     /**< \brief Specifies the frequency for the clock */
    IfxPsi5_DividerMode mode;          /**< \brief Specifies the mode of division for the clock */
    IfxPsi5_ClockType   type;          /**< \brief Specifies the type of clock (fracDiv / slow 125kHz / fast 189 kHz / timestamp) */
} IfxPsi5_Psi5_Clock;

/** \brief Psi5 frame data structure with individual members
 */
typedef struct
{
    uint8  crcError : 1;                       /**< \brief Crc error flag */
    uint8  crc : 3;                            /**< \brief Received crc */
    uint32 readData : 28;                      /**< \brief Received data */
    uint32 timestamp : 24;                     /**< \brief Timestamp */
    uint8  slotCounter : 3;                    /**< \brief Slot counter */
    uint8  timeslotError : 1;                  /**< \brief Time slot error flag */
    uint8  numberOfBitsError : 1;              /**< \brief Number of bits error flag */
    uint8  messagingBitsError : 1;             /**< \brief Messaging bits error flag */
    uint8  noFrameReceivedError : 1;           /**< \brief No frame received flag */
    uint8  receiveMemoryOverflowError : 1;     /**< \brief Receive buffer overflow error flag */
} IfxPsi5_Psi5_FrameData;

/** \brief Input output configuration structure
 */
typedef struct
{
    boolean                         outputInverterEnabled;       /**< \brief Specifies the pulse polarity of the output */
    boolean                         inputInverterEnabled;        /**< \brief Specifies the pulse polarity of the input */
    IfxPsi5_DigitalInputFilterDepth digitalInputFilterDepth;     /**< \brief Specifies the the number of port input samples considered for floating average */
} IfxPsi5_Psi5_InputOutputControl;

/** \brief Psi5 serial message with individual members
 */
typedef struct
{
    uint16 serialData : 16;                     /**< \brief Serial message data */
    uint8  messageId : 8;                       /**< \brief Serial message Id */
    uint8  crc : 6;                             /**< \brief Serial message crc */
    uint8  serialMessageCRCFailedError : 1;     /**< \brief Serial message crc error flag */
    uint8  configuration : 1;                   /**< \brief Serial message configuration */
} IfxPsi5_Psi5_Message;

/** \brief Sync pulse generation configuration structure
 */
typedef struct
{
    uint32              pulseLength;                    /**< \brief Specifies the standard pulse width without data coding for standard pulse width or for coding a '0' */
    uint32              delayLength;                    /**< \brief Specifies the additional length of the pulse width for coding a '1' */
    IfxPsi5_TimeBase    timeBaseSelect;                 /**< \brief Specifies the clock source for CTV as internal or external */
    IfxPsi5_Trigger     externalTimeBaseSelect;         /**< \brief Specifies the clock source for CTV in the case of external */
    IfxPsi5_TriggerType periodicOrExternalOrBypass;     /**< \brief Specifies whether periodic trigger or external trigger or bypass is selected */
    IfxPsi5_Trigger     externalTriggerSelect;          /**< \brief Specifies the trigger source in case of external triggerring */
    uint32              blankoutTime;                   /**< \brief Specifies the duration of blank out period */
} IfxPsi5_Psi5_PulseGeneration;

/** \brief Psi5 frame in double word format
 */
typedef struct
{
    uint32 lowWord;      /**< \brief Lower 32 bits of the Psi5 frame */
    uint32 highWord;     /**< \brief Upper 32 bits of the Psi5 frame */
} IfxPsi5_Psi5_Rdm;

/** \brief Psi5 serial message as unsigned 32 bit value
 */
typedef struct
{
    uint32 value;     /**< \brief 32 bit value of the Psi5 serial message */
} IfxPsi5_Psi5_Rds;

/** \brief Receive control configuration structure
 */
typedef struct
{
    boolean                              asynchronousModeSelected;                     /**< \brief Specifies the asynchronous mode of operation */
    uint32                               fifoWarningLevel;                             /**< \brief Specifies the fifo warning level */
    uint32                               payloadLength[IFXPSI5_NUM_SLOTS];             /**< \brief Specifies the payload length for the slots 0 to 5 */
    IfxPsi5_Verbose                      verboseForAsynchronousMode;                   /**< \brief Specifies the verbose mode selection in asynchronous mode of operation */
    IfxPsi5_MessagingBits                messagingBitsPresence[IFXPSI5_NUM_SLOTS];     /**< \brief Specifies the presence or absence of messaging bits in the slots 0 to 5 */
    IfxPsi5_CRCorParity                  crcOrParity[IFXPSI5_NUM_SLOTS];               /**< \brief Specifies the crc or parity selection for the slots 0 to 5 */
    IfxPsi5_FrameExpectation             frameExpectation[IFXPSI5_NUM_SLOTS];          /**< \brief Specifies whether the frame is expected or not in the slots 0 to 5 */
    IfxPsi5_Verbose                      verbose[IFXPSI5_NUM_SLOTS];                   /**< \brief Specifies the verbose is enabled or disabled for the slots 0 to 5 */
    IfxPsi5_BaudRate                     baudrateSelect;                               /**< \brief Specifies the baudrate selection */
    IfxPsi5_TimestampRegister            pulseTimestampSelect;                         /**< \brief Specifies the timestamp register selection for pulses */
    IfxPsi5_TimestampRegister            frameTimestampSelect;                         /**< \brief Specifies the timestamp register selection for start of frames */
    IfxPsi5_ReceiveDataRegisterTimestamp receiveDataRegisterTimestamp;                 /**< \brief Specifies the pulse or start of frame based timestamp to be stored in receive data register RDRH */
} IfxPsi5_Psi5_ReceiveControl;

/** \brief Timestamp configuration data structure
 */
typedef struct
{
    IfxPsi5_Trigger  externalTimeBaseSelect;     /**< \brief Specifies the clock base for counter CTS in the case of external */
    IfxPsi5_TimeBase timeBaseSelect;             /**< \brief Specifies the clock source for CTS as internal or external */
} IfxPsi5_Psi5_TimeStampConfig;

/** \brief Transmit control configuration structure
 */
typedef struct
{
    boolean enhancedProtocolSelected;               /**< \brief Specifies whether the enhanced protocol is selected or not */
    boolean bitStuffingEnabled;                     /**< \brief Specifies whether the bit stuffing is turned on or not */
    boolean crcGenerationEnabled;                   /**< \brief Specifies whether the crc generation is turned on or not */
    boolean startSequenceGenerationEnabled;         /**< \brief Specifies whether the start sequence generation is turned on or not */
    boolean inhibitingAutomaticTransferEnabled;     /**< \brief Specifies whether automatic transfer from the shift registers SSRL/H to SORL/H is inhibited or not */
    uint32  payloadLength;                          /**< \brief Specifies the payload length to be sent */
    uint32  ssrPayloadLength;                       /**< \brief Specifies the payload length of SSR */
    uint32  sorPayloadLength;                       /**< \brief Specifies the payload length of SOR */
} IfxPsi5_Psi5_TransmitControl;

/** \} */

/** \brief Pin Configuration structure
 */
typedef struct
{
    const IfxPsi5_Rx_In  *in;            /**< \brief The RX Pin which should be configured */
    IfxPort_InputMode     inMode;        /**< \brief The pin input mode which should be configured */
    const IfxPsi5_Tx_Out *out;           /**< \brief The TX Pin which should be configured */
    IfxPort_OutputMode    outMode;       /**< \brief The pin output mode which should be configured */
    IfxPort_PadDriver     pinDriver;     /**< \brief The pad driver mode which should be configured */
} IfxPsi5_Psi5_PinsConfig;

/** \addtogroup IfxLld_Psi5_Psi5_Structures
 * \{ */
/** \brief Channel handle data structure
 */
typedef struct
{
    IfxPsi5_Psi5     *module;        /**< \brief The PSI5 handle structure */
    Ifx_PSI5_CH      *channel;       /**< \brief Pointer to the channel registers */
    IfxPsi5_ChannelId channelId;     /**< \brief Specifies the channel index */
} IfxPsi5_Psi5_Channel;

/** \brief Channel configuration structure
 */
typedef struct
{
    const IfxPsi5_Psi5             *module;                                   /**< \brief Specifies pointer to the IfxPsi5_Psi5 module handle */
    uint32                          watchdogTimerLimit[IFXPSI5_NUM_WDTS];     /**< \brief Specifies the watchdog timer limit for each of the slots 0 to 6 */
    IfxPsi5_ChannelId               channelId;                                /**< \brief Specifies the channel index */
    IfxPsi5_Psi5_PulseGeneration    pulseGeneration;                          /**< \brief Specifies the configuration for sync pulse generation */
    IfxPsi5_Psi5_ChannelTrigger     channelTrigger;                           /**< \brief Specifies the configuration for channel trigger */
    IfxPsi5_Psi5_ReceiveControl     receiveControl;                           /**< \brief Specifies the configuration for reception */
    IfxPsi5_Psi5_TransmitControl    sendControl;                              /**< \brief Specifies the configuration for transmission */
    IfxPsi5_Psi5_InputOutputControl inputOutputControl;                       /**< \brief Specifies the configuration for input output control */
    const IfxPsi5_Psi5_PinsConfig  *pinsConfig;                               /**< \brief Pin Configuration structure */
} IfxPsi5_Psi5_ChannelConfig;

/** \brief PSI5 module configuration structure
 */
typedef struct
{
    Ifx_PSI5                    *psi5;                  /**< \brief Specifies the pointer to the PSI5 module registers */
    IfxPsi5_Psi5_Clock           fracDiv;               /**< \brief Specifies fractionally divided clock properties */
    IfxPsi5_Psi5_Clock           slowClock;             /**< \brief Specifies the slower f125 clock properties */
    IfxPsi5_Psi5_Clock           fastClock;             /**< \brief Specifies the faster f189 clock properties */
    IfxPsi5_Psi5_Clock           timestampClock;        /**< \brief Specifies the time stamp clock properties */
    IfxPsi5_Psi5_TimeStampConfig timestampCounterA;     /**< \brief Specifies the time stamp counter A properties */
    IfxPsi5_Psi5_TimeStampConfig timestampCounterB;     /**< \brief Specifies the time stamp counter B properties */
    IfxPsi5_Psi5_TimeStampConfig timestampCounterC;     /**< \brief Specifies the time stamp counter C properties */
} IfxPsi5_Psi5_Config;

/** \brief Psi5 frame data union
 */
typedef union
{
    IfxPsi5_Psi5_Rdm       rdm;       /**< \brief Psi5 frame in double word format */
    IfxPsi5_Psi5_FrameData frame;     /**< \brief Psi5 frame data structure with individual members */
} IfxPsi5_Psi5_Frame;

/** \brief Psi5 serial message data structure
 */
typedef union
{
    IfxPsi5_Psi5_Rds     rds;         /**< \brief Psi5 serial message as unsigned 32 bit value */
    IfxPsi5_Psi5_Message message;     /**< \brief Psi5 serial message with individual members */
} IfxPsi5_Psi5_SerialMessage;

/** \brief startup related options TBD
 */
typedef struct
{
    uint8  a : 1;      /**< \brief TBD */
    uint32 b : 31;     /**< \brief TBD */
} IfxPsi5_Psi5_StartupOptions;

/** \} */

/** \addtogroup IfxLld_Psi5_Psi5_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Resets the PSI5 module
 * \param psi5 pointer to the PSI5 module
 * \return None
 */
IFX_EXTERN void IfxPsi5_Psi5_deInitModule(IfxPsi5_Psi5 *psi5);

/** \brief Initialise the PSI5 with the supplied configureation
 * \param psi5 pointer to the PSI5 module
 * \param config pointer to the PSI5 configuration
 * \return return TRUE on success & FALSE if configuration not valid
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 *
 */
IFX_EXTERN boolean IfxPsi5_Psi5_initModule(IfxPsi5_Psi5 *psi5, const IfxPsi5_Psi5_Config *config);

/** \brief Initialise buffer with default PSI5 configuration
 * \param config pointer to the PSI5 module configuration
 * \param psi5 base address of the PSI5 register space
 * \return None
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 *
 */
IFX_EXTERN void IfxPsi5_Psi5_initModuleConfig(IfxPsi5_Psi5_Config *config, Ifx_PSI5 *psi5);

/** \} */

/** \addtogroup IfxLld_Psi5_Psi5_Channel
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief start the channel with the selected options
 * \param channel pointer to the PSI5 channel
 * \param options startup related options
 * \return TRUE if successful; FALSE otherwise
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 *
 */
IFX_INLINE boolean IfxPsi5_Psi5_startupChannel(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Psi5_StartupOptions *options);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialize the channel with the supplied configuration
 * \param channel pointer to the PSI5 channel
 * \param config pointer to the PSI5 channel configuration
 * \return TRUE on success & FALSE if configuration not valid
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 *
 */
IFX_EXTERN boolean IfxPsi5_Psi5_initChannel(IfxPsi5_Psi5_Channel *channel, const IfxPsi5_Psi5_ChannelConfig *config);

/** \brief Get the current channel configuration (e.g. sample settings)
 * \param config pointer to the PSI5 channel configuration
 * \param psi5 pointer to the PSI5 module
 * \return None
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 *
 */
IFX_EXTERN void IfxPsi5_Psi5_initChannelConfig(IfxPsi5_Psi5_ChannelConfig *config, IfxPsi5_Psi5 *psi5);

/** \brief Gets the received psi5 frame for the channel
 * \param channel pointer to the PSI5 channel
 * \param frame pointer to the PSI5 frame buffer
 * \return TRUE if successful; FALSE if no frame available
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 *
 */
IFX_EXTERN boolean IfxPsi5_Psi5_readChannelFrame(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Psi5_Frame *frame);

/** \brief Get the received serial message for the channel
 * \param channel pointer to the PSI5 channel
 * \param slot Slot Id
 * \param message pointer to the PSI5 serial message buffer
 * \return TRUE if successful; FALSE if no serial message available
 */
IFX_EXTERN boolean IfxPsi5_Psi5_readChannelSerialMessage(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Slot slot, IfxPsi5_Psi5_SerialMessage *message);

/** \brief Transmit the data through the channel
 * \param channel pointer to the PSI5 channel
 * \param data data to be sent
 * \return TRUE if successful; FALSE otherwise
 *
 * A coding example can be found in \ref IfxLld_Psi5_Psi5_Usage
 *
 */
IFX_EXTERN boolean IfxPsi5_Psi5_sendChannelData(IfxPsi5_Psi5_Channel *channel, uint64 data);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxPsi5_Psi5_startupChannel(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Psi5_StartupOptions *options)
{
    return TRUE;
}


#endif /* IFXPSI5_PSI5_H */
/**
 * \file IfxI2c.h
 * \brief I2C  basic functionality
 * \ingroup IfxLld_I2c
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
 * \defgroup IfxLld_I2c_Std_enums Enumerations
 * \ingroup IfxLld_I2c_Std
 * \defgroup IfxLld_I2c_Std_functions Functions
 * \ingroup IfxLld_I2c_Std
 * \defgroup IfxLld_I2c_Std_structures Data Structures
 * \ingroup IfxLld_I2c_Std
 */

#ifndef IFXI2C_H
#define IFXI2C_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxI2c_cfg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Scu/Std/IfxScuCcu.h"
#include "IfxI2c_reg.h"
#include "IfxI2c_bf.h"
#include "_PinMap/IfxI2c_PinMap.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_I2c_Std_enums
 * \{ */
typedef enum
{
    IfxI2c_BusStatus_idle        = 0, /**< \brief idle */
    IfxI2c_BusStatus_started     = 1, /**< \brief started */
    IfxI2c_BusStatus_busyMaster  = 2, /**< \brief busy Master */
    IfxI2c_BusStatus_remoteSlave = 3  /**< \brief remote Slave */
} IfxI2c_BusStatus;

/** \brief enable error interrupt request source
 * Definition in Ifx.I2C.ERRIRQSM.U
 */
typedef enum
{
    IfxI2c_ErrorInterruptSource_rxFifoUnderflow = IFX_I2C_ERRIRQSM_RXF_UFL_OFF,  /**< \brief receive fifo underflow service request */
    IfxI2c_ErrorInterruptSource_rxFifoOverflow  = IFX_I2C_ERRIRQSM_RXF_OFL_OFF,  /**< \brief receive fifo overflow service request */
    IfxI2c_ErrorInterruptSource_txFifoUnderflow = IFX_I2C_ERRIRQSM_TXF_UFL_OFF,  /**< \brief transmit fifo underflow service request */
    IfxI2c_ErrorInterruptSource_txFifoOverflow  = IFX_I2C_ERRIRQSM_TXF_OFL_OFF   /**< \brief transmit fifo overflow service request */
} IfxI2c_ErrorInterruptSource;

typedef enum
{
    IfxI2c_PinSelect_a = 0,
    IfxI2c_PinSelect_b = 1,
    IfxI2c_PinSelect_c = 2,
    IfxI2c_PinSelect_d = 3,
    IfxI2c_PinSelect_e = 4,
    IfxI2c_PinSelect_f = 5,
    IfxI2c_PinSelect_g = 6,
    IfxI2c_PinSelect_h = 7
} IfxI2c_PinSelect;

/** \brief enable protocol interrupt source
 * Definition in Ifx.I2C.PIRQSM.U
 */
typedef enum
{
    IfxI2c_ProtocolInterruptSource_addressMatch           = IFX_I2C_PIRQSM_AM_OFF,     /**< \brief address match service request */
    IfxI2c_ProtocolInterruptSource_generalCall            = IFX_I2C_PIRQSM_GC_OFF,     /**< \brief general call service request */
    IfxI2c_ProtocolInterruptSource_masterCode             = IFX_I2C_PIRQSM_MC_OFF,     /**< \brief master code service request */
    IfxI2c_ProtocolInterruptSource_arbitrationLost        = IFX_I2C_PIRQSM_AL_OFF,     /**< \brief arbitration lost service request */
    IfxI2c_ProtocolInterruptSource_notAcknowledgeReceived = IFX_I2C_PIRQSM_NACK_OFF,   /**< \brief not acknowledge received service request */
    IfxI2c_ProtocolInterruptSource_transmissionEnd        = IFX_I2C_PIRQSM_TX_END_OFF, /**< \brief transmission end service request */
    IfxI2c_ProtocolInterruptSource_receiveMode            = IFX_I2C_PIRQSM_RX_OFF      /**< \brief receive mode service request */
} IfxI2c_ProtocolInterruptSource;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_I2C.CLC1.B.EDIS
 */
typedef enum
{
    IfxI2c_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxI2c_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxI2c_SleepMode;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_I2c_Std_structures
 * \{ */
/** \brief Pin Structure
 */
typedef struct
{
    IfxI2c_Scl_InOut *scl;
    IfxI2c_Sda_InOut *sda;
    IfxPort_PadDriver padDriver;
} IfxI2c_Pins;

/** \} */

/** \addtogroup IfxLld_I2c_Std_functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns if the bus is free
 */
IFX_INLINE boolean IfxI2c_busIsFree(Ifx_I2C *i2c);

/** \brief clears all Error Interrupt sources
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearAllErrorInterruptSources(Ifx_I2C *i2c);

/** \brief Clears all Protocol Interrupt sources
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearAllProtocolInterruptSources(Ifx_I2C *i2c);

/** \brief clears burst request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearBurstRequestInterruptSource(Ifx_I2C *i2c);

/** \brief clears the specified source of error interrupt
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_clearErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief clears last burst request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearLastBurstRequestInterruptSource(Ifx_I2C *i2c);

/** \brief clears last single request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearLastSingleRequestInterruptSource(Ifx_I2C *i2c);

/** \brief clears the specified source of protocol interrupt
 * \param i2c pointer to i2c registers
 * \param source protocol interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_clearProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/** \brief clears single request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_clearSingleRequestInterruptSource(Ifx_I2C *i2c);

/** \brief disables burst request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableBurstRequestInterruptSource(Ifx_I2C *i2c);

/** \brief disables the error interrupt flag
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableErrorInterruptFlag(Ifx_I2C *i2c);

/** \brief disables the specified source of error interrupt
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_disableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief disables last burst request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableLastBurstRequestInterruptSource(Ifx_I2C *i2c);

/** \brief disables last single request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableLastSingleRequestInterruptSource(Ifx_I2C *i2c);

/** \brief disables the Protocol interrupt flag
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableProtocolInterruptFlag(Ifx_I2C *i2c);

/** \brief disables the specified source of protocol interrupt
 * \param i2c pointer to i2c registers
 * \param source protocol interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_disableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/** \brief disables single request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_disableSingleRequestInterruptSource(Ifx_I2C *i2c);

/** \brief enables burst request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableBurstRequestInterruptSource(Ifx_I2C *i2c);

/** \brief enables the error interrupt flag
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableErrorInterruptFlag(Ifx_I2C *i2c);

/** \brief enables the specified source of error interrupt
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_enableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief enables last burst request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableLastBurstRequestInterruptSource(Ifx_I2C *i2c);

/** \brief enables last single request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableLastSingleRequestInterruptSource(Ifx_I2C *i2c);

/** \brief enables the protocol interrupt flag
 * \param i2c pointer to I2C registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableProtocolInterruptFlag(Ifx_I2C *i2c);

/** \brief enables the specified source of protocol interrupt
 * \param i2c pointer to I2C registers
 * \param source protocol interrupt source
 * \return None
 */
IFX_INLINE void IfxI2c_enableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/** \brief enables single request interrupt source
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_enableSingleRequestInterruptSource(Ifx_I2C *i2c);

/** \brief Returns the SRC pointer for I2C burst data transfer request interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C burst data transfer Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getBurstDataTransferSrcPointer(Ifx_I2C *i2c);

/** \brief returns the status of burst request interrupt source status
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getBurstRequestInterruptSourceStatus(Ifx_I2C *i2c);

/**
 * \param i2c pointer to i2c registers
 * \return BusStatus
 */
IFX_INLINE IfxI2c_BusStatus IfxI2c_getBusStatus(Ifx_I2C *i2c);

/** \brief returns the current status of error interrupt flag
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getErrorInterruptFlagStatus(Ifx_I2C *i2c);

/** \brief returns the status of the error interrupt source
 * \param i2c pointer to i2c registers
 * \param source error interrupt source
 * \return status
 */
IFX_INLINE boolean IfxI2c_getErrorInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source);

/** \brief Returns the SRC pointer for I2C Error interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C Error Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getErrorSrcPointer(Ifx_I2C *i2c);

/** \brief Returns the SRC pointer for I2C last burst data transfer request interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C last burst data transfer Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getLastBurstDataTransferSrcPointer(Ifx_I2C *i2c);

/** \brief returns the status of last burst request interrupt source status
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getLastBurstRequestInterruptSourceStatus(Ifx_I2C *i2c);

/** \brief Returns the SRC pointer for I2C last single data transfer request interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C last single data transfer Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getLastSingleDataTransferSrcPointer(Ifx_I2C *i2c);

/** \brief returns the status of last single request interrupt source status
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getLastSingleRequestInterruptSourceStatus(Ifx_I2C *i2c);

/** \brief returns the current raw status of protocol interrupt
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getProtocolInterruptFlagStatus(Ifx_I2C *i2c);

/** \brief returns the status of  specified protocol interrupt source
 * \param i2c pointer to i2c registers
 * \param source protocol interrupt source
 * \return status
 */
IFX_INLINE boolean IfxI2c_getProtocolInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source);

/** \brief Returns the SRC pointer for I2C Protocol interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C Protocol Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getProtocolSrcPointer(Ifx_I2C *i2c);

/** \brief Returns the SRC pointer for I2C single data transfer request interrupt
 * \param i2c pointer to i2c registers
 * \return SRC pointer for I2C single data transfer Service interrupt
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getSingleDataTransferSrcPointer(Ifx_I2C *i2c);

/** \brief returns the status of single request interrupt source status
 * \param i2c pointer to i2c registers
 * \return status
 */
IFX_INLINE boolean IfxI2c_getSingleRequestInterruptSourceStatus(Ifx_I2C *i2c);

/** \brief Returns if the Fifo is requesting new data
 */
IFX_INLINE boolean IfxI2c_isFifoRequest(Ifx_I2C *i2c);

/**
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_run(Ifx_I2C *i2c);

/** \brief selects the pin
 * \param i2c pointer to i2c registers
 * \param pisel pin to be select
 * \return None
 */
IFX_INLINE void IfxI2c_setPinSelection(Ifx_I2C *i2c, IfxI2c_PinSelect pisel);

/** \brief Sets the number of bytes to be received
 * \param i2c pointer to i2c registers
 * \param size number of packets
 * \return None
 */
IFX_INLINE void IfxI2c_setReceivePacketSize(Ifx_I2C *i2c, Ifx_SizeT size);

/**
 * \param i2c pointer to i2c registers
 * \param address device address
 * \return None
 */
IFX_INLINE void IfxI2c_setSlaveDeviceAddress(Ifx_I2C *i2c, uint16 address);

/** \brief Sets the sensitivity of the module to sleep signal
 * \param i2c pointer to i2c registers
 * \param mode mode selection (enable / disable)
 * \return None
 */
IFX_INLINE void IfxI2c_setSleepMode(Ifx_I2C *i2c, IfxI2c_SleepMode mode);

/** \brief Sets the number of bytes to be tansmitted
 * \param i2c pointer to i2c registers
 * \param size number of packets
 * \return None
 */
IFX_INLINE void IfxI2c_setTransmitPacketSize(Ifx_I2C *i2c, Ifx_SizeT size);

/**
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_stop(Ifx_I2C *i2c);

/**
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_INLINE void IfxI2c_waitBusFree(Ifx_I2C *i2c);

/** \brief Writes a packet (4 bytes) into the Fifo
 * \param i2c pointer to i2c registers
 * \param packet specifies the byte to be transfer
 * \return None
 */
IFX_INLINE void IfxI2c_writeFifo(Ifx_I2C *i2c, uint32 packet);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures the Module as Master
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_configureAsMaster(Ifx_I2C *i2c);

/** \brief Disables the I2c Module
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_disableModule(Ifx_I2C *i2c);

/** \brief Enables the Burst data transfer interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableBurstDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief Enables the Error interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableErrorInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief enables the last burst data transfer interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableLastBurstDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief enables the last single data transfer interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableLastSingleDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief Enables the I2c Module
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_enableModule(Ifx_I2C *i2c);

/** \brief Enables the protocol interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority Priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableProtocolInterrupt(void *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief enables the single data transfer interrupt
 * \param i2c pointer to i2c registers
 * \param typeOfService Type of Service (Cpu or DMA)
 * \param priority priority of the interrupt
 * \return None
 */
IFX_EXTERN void IfxI2c_enableSingleDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority);

/** \brief Returns the real Baudrate
 * \return Baudrate
 */
IFX_EXTERN float32 IfxI2c_getBaudrate(Ifx_I2C *i2c);

/**
 * \return None
 */
IFX_EXTERN void IfxI2c_initSclSdaPin(const IfxI2c_Scl_InOut *scl, const IfxI2c_Sda_InOut *sda, IfxPort_PadDriver padDriver);

/** \brief Releases the bus, i.e puts a stop condition on the bus
 * \return None
 */
IFX_EXTERN void IfxI2c_releaseBus(Ifx_I2C *i2c);

/**
 * \return None
 */
IFX_EXTERN void IfxI2c_resetFifo(Ifx_I2C *i2c);

/** \brief resets the I2c kernel
 * \param i2c pointer to i2c registers
 * \return None
 */
IFX_EXTERN void IfxI2c_resetModule(Ifx_I2C *i2c);

/** \brief Calculates the desired baudrate
 * \param i2c pointer to i2c registers
 * \param baudrate specifies the baud rate
 * \return None
 */
IFX_EXTERN void IfxI2c_setBaudrate(Ifx_I2C *i2c, float32 baudrate);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxI2c_busIsFree(Ifx_I2C *i2c)
{
    boolean free = FALSE;

    if (i2c->BUSSTAT.B.BS == IfxI2c_BusStatus_idle)
    {
        free = TRUE;
    }

    return free;
}


IFX_INLINE void IfxI2c_clearAllErrorInterruptSources(Ifx_I2C *i2c)
{
    i2c->ERRIRQSC.U = (1 << IFX_I2C_ERRIRQSC_RXF_UFL_OFF) | (1 << IFX_I2C_ERRIRQSC_RXF_OFL_OFF) | (1 << IFX_I2C_ERRIRQSC_TXF_UFL_OFF) | (1 << IFX_I2C_ERRIRQSC_TXF_OFL_OFF);
}


IFX_INLINE void IfxI2c_clearAllProtocolInterruptSources(Ifx_I2C *i2c)
{
    i2c->PIRQSC.U = (1 << IFX_I2C_PIRQSC_AM_OFF) | (1 << IFX_I2C_PIRQSC_GC_OFF) | (1 << IFX_I2C_PIRQSC_MC_OFF) | (1 << IFX_I2C_PIRQSC_AL_OFF) | (1 << IFX_I2C_PIRQSC_NACK_OFF) | (1 << IFX_I2C_PIRQSC_TX_END_OFF) | (1 << IFX_I2C_PIRQSC_RX_OFF);
}


IFX_INLINE void IfxI2c_clearBurstRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->ICR.B.BREQ_INT = 1;
}


IFX_INLINE void IfxI2c_clearErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    i2c->ERRIRQSC.U = (1 << source);
}


IFX_INLINE void IfxI2c_clearLastBurstRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->ICR.B.LBREQ_INT = 1;
}


IFX_INLINE void IfxI2c_clearLastSingleRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->ICR.B.LSREQ_INT = 1;
}


IFX_INLINE void IfxI2c_clearProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    i2c->PIRQSC.U = (1 << source);
}


IFX_INLINE void IfxI2c_clearSingleRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->ICR.B.SREQ_INT = 1;
}


IFX_INLINE void IfxI2c_disableBurstRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.BREQ_INT = 0;
}


IFX_INLINE void IfxI2c_disableErrorInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_ERR_INT = 0;
}


IFX_INLINE void IfxI2c_disableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    i2c->ERRIRQSM.U &= ~(1 << source);
}


IFX_INLINE void IfxI2c_disableLastBurstRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.LBREQ_INT = 0;
}


IFX_INLINE void IfxI2c_disableLastSingleRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.LSREQ_INT = 0;
}


IFX_INLINE void IfxI2c_disableProtocolInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_P_INT = 0;
}


IFX_INLINE void IfxI2c_disableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    i2c->PIRQSM.U &= ~(1 << source);
}


IFX_INLINE void IfxI2c_disableSingleRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.SREQ_INT = 0;
}


IFX_INLINE void IfxI2c_enableBurstRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.BREQ_INT = 1;
}


IFX_INLINE void IfxI2c_enableErrorInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_ERR_INT = 1;
}


IFX_INLINE void IfxI2c_enableErrorInterruptSource(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    i2c->ERRIRQSM.U |= (1 << source);
}


IFX_INLINE void IfxI2c_enableLastBurstRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.LBREQ_INT = 1;
}


IFX_INLINE void IfxI2c_enableLastSingleRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.LSREQ_INT = 1;
}


IFX_INLINE void IfxI2c_enableProtocolInterruptFlag(Ifx_I2C *i2c)
{
    i2c->IMSC.B.I2C_P_INT = 1;
}


IFX_INLINE void IfxI2c_enableProtocolInterruptSource(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    i2c->PIRQSM.U |= (1 << source);
}


IFX_INLINE void IfxI2c_enableSingleRequestInterruptSource(Ifx_I2C *i2c)
{
    i2c->IMSC.B.SREQ_INT = 1;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getBurstDataTransferSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].BREQ;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].BREQ;
    }
}


IFX_INLINE boolean IfxI2c_getBurstRequestInterruptSourceStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.BREQ_INT;
}


IFX_INLINE IfxI2c_BusStatus IfxI2c_getBusStatus(Ifx_I2C *i2c)
{
    return (IfxI2c_BusStatus)i2c->BUSSTAT.B.BS;
}


IFX_INLINE boolean IfxI2c_getErrorInterruptFlagStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.I2C_ERR_INT;
}


IFX_INLINE boolean IfxI2c_getErrorInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ErrorInterruptSource source)
{
    return (i2c->ERRIRQSS.U & (1 << source)) ? TRUE : FALSE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getErrorSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].ERR;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].ERR;
    }
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getLastBurstDataTransferSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].LBREQ;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].LBREQ;
    }
}


IFX_INLINE boolean IfxI2c_getLastBurstRequestInterruptSourceStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.LBREQ_INT;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getLastSingleDataTransferSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].LSREQ;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].LSREQ;
    }
}


IFX_INLINE boolean IfxI2c_getLastSingleRequestInterruptSourceStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.LSREQ_INT;
}


IFX_INLINE boolean IfxI2c_getProtocolInterruptFlagStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.I2C_P_INT;
}


IFX_INLINE boolean IfxI2c_getProtocolInterruptSourceStatus(Ifx_I2C *i2c, IfxI2c_ProtocolInterruptSource source)
{
    return (i2c->PIRQSS.U & (1 << source)) ? TRUE : FALSE;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getProtocolSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].P;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].P;
    }
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxI2c_getSingleDataTransferSrcPointer(Ifx_I2C *i2c)
{
    if (i2c == &MODULE_I2C0)
    {
        return &MODULE_SRC.I2C.I2C[0].SREQ;
    }
    else
    {
        return &MODULE_SRC.I2C.I2C[1].SREQ;
    }
}


IFX_INLINE boolean IfxI2c_getSingleRequestInterruptSourceStatus(Ifx_I2C *i2c)
{
    return i2c->RIS.B.SREQ_INT;
}


IFX_INLINE boolean IfxI2c_isFifoRequest(Ifx_I2C *i2c)
{
    return i2c->RIS.U & 0x0F ? TRUE : FALSE;
}


IFX_INLINE void IfxI2c_run(Ifx_I2C *i2c)
{
    i2c->RUNCTRL.U = 1;
}


IFX_INLINE void IfxI2c_setPinSelection(Ifx_I2C *i2c, IfxI2c_PinSelect pisel)
{
    i2c->GPCTL.B.PISEL = pisel;
}


IFX_INLINE void IfxI2c_setReceivePacketSize(Ifx_I2C *i2c, Ifx_SizeT size)
{
    i2c->MRPSCTRL.B.MRPS = size;
}


IFX_INLINE void IfxI2c_setSlaveDeviceAddress(Ifx_I2C *i2c, uint16 address)
{
    i2c->ADDRCFG.B.ADR = address;
}


IFX_INLINE void IfxI2c_setSleepMode(Ifx_I2C *i2c, IfxI2c_SleepMode mode)
{
    i2c->CLC1.B.EDIS = mode;
}


IFX_INLINE void IfxI2c_setTransmitPacketSize(Ifx_I2C *i2c, Ifx_SizeT size)
{
    i2c->TPSCTRL.B.TPS = size;
}


IFX_INLINE void IfxI2c_stop(Ifx_I2C *i2c)
{
    i2c->RUNCTRL.U = 0;
}


IFX_INLINE void IfxI2c_waitBusFree(Ifx_I2C *i2c)
{
    while (IfxI2c_getBusStatus(i2c) != IfxI2c_BusStatus_idle)
    {}
}


IFX_INLINE void IfxI2c_writeFifo(Ifx_I2C *i2c, uint32 packet)
{
    i2c->TXD.U = packet;
}


#endif /* IFXI2C_H */

/*******************************************************************************
* File Name: Qi.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Qi_H) /* Pins Qi_H */
#define CY_PINS_Qi_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Qi_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Qi__PORT == 15 && ((Qi__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Qi_Write(uint8 value);
void    Qi_SetDriveMode(uint8 mode);
uint8   Qi_ReadDataReg(void);
uint8   Qi_Read(void);
void    Qi_SetInterruptMode(uint16 position, uint16 mode);
uint8   Qi_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Qi_SetDriveMode() function.
     *  @{
     */
        #define Qi_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Qi_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Qi_DM_RES_UP          PIN_DM_RES_UP
        #define Qi_DM_RES_DWN         PIN_DM_RES_DWN
        #define Qi_DM_OD_LO           PIN_DM_OD_LO
        #define Qi_DM_OD_HI           PIN_DM_OD_HI
        #define Qi_DM_STRONG          PIN_DM_STRONG
        #define Qi_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Qi_MASK               Qi__MASK
#define Qi_SHIFT              Qi__SHIFT
#define Qi_WIDTH              1u

/* Interrupt constants */
#if defined(Qi__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Qi_SetInterruptMode() function.
     *  @{
     */
        #define Qi_INTR_NONE      (uint16)(0x0000u)
        #define Qi_INTR_RISING    (uint16)(0x0001u)
        #define Qi_INTR_FALLING   (uint16)(0x0002u)
        #define Qi_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Qi_INTR_MASK      (0x01u) 
#endif /* (Qi__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Qi_PS                     (* (reg8 *) Qi__PS)
/* Data Register */
#define Qi_DR                     (* (reg8 *) Qi__DR)
/* Port Number */
#define Qi_PRT_NUM                (* (reg8 *) Qi__PRT) 
/* Connect to Analog Globals */                                                  
#define Qi_AG                     (* (reg8 *) Qi__AG)                       
/* Analog MUX bux enable */
#define Qi_AMUX                   (* (reg8 *) Qi__AMUX) 
/* Bidirectional Enable */                                                        
#define Qi_BIE                    (* (reg8 *) Qi__BIE)
/* Bit-mask for Aliased Register Access */
#define Qi_BIT_MASK               (* (reg8 *) Qi__BIT_MASK)
/* Bypass Enable */
#define Qi_BYP                    (* (reg8 *) Qi__BYP)
/* Port wide control signals */                                                   
#define Qi_CTL                    (* (reg8 *) Qi__CTL)
/* Drive Modes */
#define Qi_DM0                    (* (reg8 *) Qi__DM0) 
#define Qi_DM1                    (* (reg8 *) Qi__DM1)
#define Qi_DM2                    (* (reg8 *) Qi__DM2) 
/* Input Buffer Disable Override */
#define Qi_INP_DIS                (* (reg8 *) Qi__INP_DIS)
/* LCD Common or Segment Drive */
#define Qi_LCD_COM_SEG            (* (reg8 *) Qi__LCD_COM_SEG)
/* Enable Segment LCD */
#define Qi_LCD_EN                 (* (reg8 *) Qi__LCD_EN)
/* Slew Rate Control */
#define Qi_SLW                    (* (reg8 *) Qi__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Qi_PRTDSI__CAPS_SEL       (* (reg8 *) Qi__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Qi_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Qi__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Qi_PRTDSI__OE_SEL0        (* (reg8 *) Qi__PRTDSI__OE_SEL0) 
#define Qi_PRTDSI__OE_SEL1        (* (reg8 *) Qi__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Qi_PRTDSI__OUT_SEL0       (* (reg8 *) Qi__PRTDSI__OUT_SEL0) 
#define Qi_PRTDSI__OUT_SEL1       (* (reg8 *) Qi__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Qi_PRTDSI__SYNC_OUT       (* (reg8 *) Qi__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Qi__SIO_CFG)
    #define Qi_SIO_HYST_EN        (* (reg8 *) Qi__SIO_HYST_EN)
    #define Qi_SIO_REG_HIFREQ     (* (reg8 *) Qi__SIO_REG_HIFREQ)
    #define Qi_SIO_CFG            (* (reg8 *) Qi__SIO_CFG)
    #define Qi_SIO_DIFF           (* (reg8 *) Qi__SIO_DIFF)
#endif /* (Qi__SIO_CFG) */

/* Interrupt Registers */
#if defined(Qi__INTSTAT)
    #define Qi_INTSTAT            (* (reg8 *) Qi__INTSTAT)
    #define Qi_SNAP               (* (reg8 *) Qi__SNAP)
    
	#define Qi_0_INTTYPE_REG 		(* (reg8 *) Qi__0__INTTYPE)
#endif /* (Qi__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Qi_H */


/* [] END OF FILE */

/*******************************************************************************
* File Name: sw.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_sw_ALIASES_H) /* Pins sw_ALIASES_H */
#define CY_PINS_sw_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define sw_0			(sw__0__PC)
#define sw_0_INTR	((uint16)((uint16)0x0001u << sw__0__SHIFT))

#define sw_1			(sw__1__PC)
#define sw_1_INTR	((uint16)((uint16)0x0001u << sw__1__SHIFT))

#define sw_2			(sw__2__PC)
#define sw_2_INTR	((uint16)((uint16)0x0001u << sw__2__SHIFT))

#define sw_INTR_ALL	 ((uint16)(sw_0_INTR| sw_1_INTR| sw_2_INTR))

#endif /* End Pins sw_ALIASES_H */


/* [] END OF FILE */

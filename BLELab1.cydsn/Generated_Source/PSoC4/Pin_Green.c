/*******************************************************************************
* File Name: Pin_Green.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Pin_Green.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Pin_Green_PC =   (Pin_Green_PC & \
                                (uint32)(~(uint32)(Pin_Green_DRIVE_MODE_IND_MASK << (Pin_Green_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Pin_Green_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Pin_Green_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Pin_Green_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Pin_Green_DR & (uint8)(~Pin_Green_MASK));
    drVal = (drVal | ((uint8)(value << Pin_Green_SHIFT) & Pin_Green_MASK));
    Pin_Green_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Pin_Green_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Pin_Green_DM_STRONG     Strong Drive 
*  Pin_Green_DM_OD_HI      Open Drain, Drives High 
*  Pin_Green_DM_OD_LO      Open Drain, Drives Low 
*  Pin_Green_DM_RES_UP     Resistive Pull Up 
*  Pin_Green_DM_RES_DWN    Resistive Pull Down 
*  Pin_Green_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Pin_Green_DM_DIG_HIZ    High Impedance Digital 
*  Pin_Green_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Pin_Green_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Pin_Green__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Pin_Green_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Pin_Green_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pin_Green_Read(void) 
{
    return (uint8)((Pin_Green_PS & Pin_Green_MASK) >> Pin_Green_SHIFT);
}


/*******************************************************************************
* Function Name: Pin_Green_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Pin_Green_ReadDataReg(void) 
{
    return (uint8)((Pin_Green_DR & Pin_Green_MASK) >> Pin_Green_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pin_Green_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pin_Green_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Pin_Green_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Pin_Green_INTSTAT & Pin_Green_MASK);
		Pin_Green_INTSTAT = maskedStatus;
        return maskedStatus >> Pin_Green_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */

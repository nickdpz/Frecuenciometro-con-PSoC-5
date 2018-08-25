/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

uint8 resolucion;

CY_ISR(InteQi){
    Qi_ClearInterrupt();//Limpia interucpcion en puerto
}

CY_ISR(InteSw){
    switch(sw_Read()){
    case 0x06:
        resolucion=100;
        break;
    case 0x05:
        resolucion=200;
        break;
    case 0x03:
        resolucion=7;
        break;
     default:
        break;
    }
    sw_ClearInterrupt();//Limpia interupcion en el puerto
}


int main(void)
{   
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    sw_irq_StartEx(InteSw);//Declara vector de interupcion para el bloque de interupcion
    Qi_irq_StartEx(InteQi);//Declara vector de interupcion para el bloque de interupcion
    LCD_Start();//Inicia LCD  y Carga caracteres personalizados 

    for(;;)
    {
        /* Place your application code here. */
    }
}



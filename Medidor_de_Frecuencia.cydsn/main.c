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

uint16 volatile i=0;
uint8 volatile  aux=0;
uint16 volatile tiempo;


void impri(){
        
       if(i==0){
                 LCD_Position(0,10);//Se ubica la Posicion Para el Numero
                 LCD_PrintString("Error ");
        }else{
             
        switch(aux){     
            
        case 0:
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintString("    Hz");//Se borra para que la libreria no afecte
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintNumber(i);
            break;
        case 1:
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintString("      ");//Se borra para que la libreria no afecte
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintNumber(i/1000);
            LCD_Position(0,12);//Se ubica la Posicion Para el Numero
            LCD_PrintString(".");
            LCD_PrintNumber(i%1000);
            break;
        default:
            break;
            }
       }
}

CY_ISR(InteQi){
    i=i+1;
    Qi_ClearInterrupt();//Limpia interucpcion en puerto
}

CY_ISR(InteSw){
    switch(sw_Read()){
    case 0x06:
        LCD_Position(1,0);//Se ubica la Posicion Para el Numero
        LCD_PrintString(" 1 Hz a 100 Hz");//Se pone la resolucion
        aux=0;
        tiempo=909;
        break;
    case 0x05:
        LCD_Position(1,0);//Se ubica la Posicion Para el Numero
        LCD_PrintString("100 Hz a 1 kHz");//Se pone la resolucion
        aux=0;
        tiempo=909;
        break;
    case 0x03:
        LCD_Position(1,0);//Se ubica la Posicion Para el Numero
        LCD_PrintString("1 kHz a 10 kHz");//Se pone la resolucion
        aux=1;
        tiempo=990;
        break;
     default:
        break;
    }
    sw_ClearInterrupt();//Limpia interupcion en el puerto
}



int main(void)
{   
    sw_irq_StartEx(InteSw);//Declara vector de interupcion para el bloque de interupcion
    Qi_irq_StartEx(InteQi);//Declara vector de interupcion para el bloque de interupcion
    LCD_Start();//Inicia LCD  y Carga caracteres personalizados 
    LCD_PrintString("Frecuency: ");
    LCD_Position(1,0);//Se ubica la Posicion Para el Numero
    LCD_PrintString("1 Hz a 100 Hz");//Se pone la resolucion
    tiempo=909;
    CyGlobalIntEnable; /* Enable global interrupts. */
    for(;;)
    {   
    i=0;
    CyDelay(tiempo);//Retardo de un segundo   
    CyDelayUs(400);
    impri();
    }    
}



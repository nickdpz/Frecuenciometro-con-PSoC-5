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

uint16 tiempo;
uint16 i=0;
uint16 f=0;
uint8 de=0;

CY_ISR(InteQi){
    if(de==0){
        i=0;//Incial El Timer
        de=1;
    }else{
        f=i;//Captura el valor;
        i=10000;//Deja de contar
        de=0;
    }
    Qi_ClearInterrupt();//Limpia interucpcion en puerto
}

CY_ISR(InteSw){
    switch(sw_Read()){
    case 0x06:
        tiempo=100;
        LCD_Position(1,0);//Se ubica la Posicion Para el Numero
        LCD_PrintString(" 1 Hz a 100 Hz");//Se pone la resolucion
        break;
    case 0x05:
        tiempo=10;
        LCD_Position(1,0);//Se ubica la Posicion Para el Numero
        LCD_PrintString("100 Hz a 1 kHz");//Se pone la resolucion
        break;
    case 0x03:
        tiempo=1;
        LCD_Position(1,0);//Se ubica la Posicion Para el Numero
        LCD_PrintString("1 kHz a 10 kHz");//Se pone la resolucion
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
    LCD_PrintString("Frecuency: ");
    LCD_Position(1,0);//Se ubica la Posicion Para el Numero
    LCD_PrintString(" 1 Hz a 100 Hz");//Se pone la resolucion
    tiempo=100;
    for(;;)
    {   
    for(i=0;i<10000;i++){
        CyDelayUs(tiempo);
            /*Para rango de 1 a 100 CyDelayUs(100)
              Para rango de 100 a 1k CyDelayUs(10)
              Para rango de 1k a 10k CyDelayUs(1)
            */
    }
    
        LCD_Position(1,0);
    if(f==0){
         LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintString("Error ");
    }else{
       switch(tiempo){
        case 100:
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintString("    Hz");//Se borra para que la libreria no afecte
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintNumber(10000/f);
            break;
        case 10:
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintString("    Hz");//Se borra para que la libreria no afecte
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintNumber(100000/f);
        break;
        case 1:
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintString("      ");//Se borra para que la libreria no afecte
            LCD_Position(0,10);//Se ubica la Posicion Para el Numero
            LCD_PrintNumber(10000/f);
            LCD_Position(0,12);//Se ubica la Posicion Para el Numero
            LCD_PrintString(".");
            LCD_PrintNumber(10000%f);
        break;
            default:
        break;
            }
        CyDelay(800);
        }
    }
    
}




/*
 * Defines ADC Sample Cycles
 * Sample time is Clock Sample Cycles / Frequency * Prescaler 
 */
#define ADC_SAMP_CYCLES  ADC_SMP_71cyc5  //ADC_SMP_1cyc5 ADC_SMP_7cyc5 ADC_SMP_13cyc5 ADC_SMP_28cyc5 ADC_SMP_41cyc5 ADC_SMP_55cyc5 ADC_SMP_71cyc5 ADC_SMP_239cyc5


#define adcBufferLength 32 // The memory length for DMA access Note: This also limits the sequence of the ADC conversions

/*
 * Define ADC Sequence 
 * ADCChannel STM32Pin MapleMiniPin
 * 0          PA0      D11
 * 1          PA1      D10
 * 2          PA2      D9
 * 3          PA3      D8
 * 4          PA4      D7
 * 5          PA5      D6
 * 6          PA6      D5
 * 7          PA7      D4
 * 8          PB0      D3
 * 9          PB1      D33(LED Pin)
 * 16 on ADC1 - Internal Temperature Sensor
 * 16 on ADC2 - VSS voltage
 */

//ADC Converter 1
#define ADC1_SQ1 16
#define ADC1_SQ2 0
#define ADC1_SQ3 1
#define ADC1_SQ4 2
#define ADC1_SQ5 3
#define ADC1_SQ6 4
#define ADC1_SQ7 0
#define ADC1_SQ8 1
#define ADC1_SQ9 2
#define ADC1_SQ10 3
#define ADC1_SQ11 4
#define ADC1_SQ12 0
#define ADC1_SQ13 1
#define ADC1_SQ14 2
#define ADC1_SQ15 3
#define ADC1_SQ16 4

//ADC Converter 2
#define ADC2_SQ1 16
#define ADC2_SQ2 5
#define ADC2_SQ3 6
#define ADC2_SQ4 7
#define ADC2_SQ5 8
#define ADC2_SQ6 9
#define ADC2_SQ7 5
#define ADC2_SQ8 6
#define ADC2_SQ9 7
#define ADC2_SQ10 8
#define ADC2_SQ11 9
#define ADC2_SQ12 5
#define ADC2_SQ13 6
#define ADC2_SQ14 7
#define ADC2_SQ15 8
#define ADC2_SQ16 9


/*
 * ADC Buffer
 */
uint32 uiADCBuffer[adcBufferLength/2]; //Use double words to guarantee compiler positioning if using double word frame
uint16* uiADCBufferPointer = (uint16*)&uiADCBuffer[0];


/*
 * Configures Analog Port
 */
void ConfigureAnalogNative() {
  uint32 uiAdress = 0;
  uint32 uiValue = 0;
  
  //***Configure RCC***
#ifdef debugConfiguration
  Serial.println("Configuring RCC");
#endif
  //ADC Prescaler
  uiAdress = RCC_B + RCC_CFGR;
  uiValue = PCLK2div6 << RCC_CFGR_ADCPRE; //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //Enable DMA1 clock
  uiAdress = RCC_B + RCC_AHBENR;
  uiValue = 1 << RCC_AHBENR_DMA1EN; //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //Enable ADC1 clock
  uiAdress = RCC_B + RCC_APB2ENR;
  uiValue = 1 << RCC_APB2ENR_ADC1EN; //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);

   //***Configure GPIO***
#ifdef debugConfiguration
  Serial.println("Configuring GPIO");
#endif   
  //Port configuration register low (GPIOx_CRL) (x=A..G) Address offset: 0x00 
  uiAdress = GPIOA_B + GPIOx_CRL ;
  uiValue = ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF7) + ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF6) + ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF5) + ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF4) + ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF3) + ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF2) + ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF1) + ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF0);
  SetValue32((uint32*)(uiAdress), 0xFFFFFFFF, false);
  SetValue32((uint32*)(uiAdress), uiValue, true);
   //Port configuration register low (GPIOx_CRL) (x=A..G) Address offset: 0x00 
  uiAdress = GPIOB_B + GPIOx_CRL ;
  uiValue = ((GPIOx_CR_CNF_AN + GPIOx_CR_MODE_IN) << GPIOx_CRL_CNF0);
  SetValue32((uint32*)(uiAdress), 0x0000000F, false);
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //***Configure DMA***
#ifdef debugConfiguration
  Serial.println("Configuring DMA");
#endif  
  //DMA channel 1 peripheral address register
  uiAdress = DMA_B + DMA_CPARx;
  uiValue = ADC1_B + ADC_DR;
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //DMA channel x memory address register
  uiAdress = DMA_B + DMA_CMARx;
  uiValue = (uint32)&uiADCBuffer[0]; 
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //DMA channel x number of data register (DMA_CNDTRx)
  uiAdress = DMA_B + DMA_CNDTRx;
  uiValue = (uint32)adcBufferLength/2;
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //DMA channel x configuration register (DMA_CCRx)
  uiAdress = DMA_B + DMA_CCRx;
  uiValue = (2 << DMA_CCRx_PL) + (2<< DMA_CCRx_MSIZE) + (2 << DMA_CCRx_PSIZE) + (1 << DMA_CCRx_MINC)+ (1 << DMA_CCRx_CIRC); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //Enable channel!!!
  //DMA channel x configuration register (DMA_CCRx)
  uiAdress = DMA_B + DMA_CCRx;
  uiValue = 1<< DMA_CCRx_EN; //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //***Configure ADC1***
#ifdef debugConfiguration
  Serial.println("Configuring ADC1");
#endif
  //ADC control register 1 (ADC_CR1) Address offset: 0x04 
  uiAdress = ADC1_B + ADC_CR1;
  uiValue = (B0110<< ADC_CR1_DUALMOD) + (1<<ADC_CR1_SCAN); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC control register 1 (ADC_CR1) Address offset: 0x04 
  uiAdress = ADC2_B + ADC_CR1;
  uiValue = (B0110<< ADC_CR1_DUALMOD) + (1<<ADC_CR1_SCAN); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);


  //ADC sample time register 1 (ADC_SMPR1) Address offset: 0x0C 
  uiAdress = ADC1_B + ADC_SMPR1;
  uiValue = (ADC_SAMP_CYCLES << ADC_SMPR1_SMP10) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP11) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP12) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP13) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP14) + + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP15) + + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP16) + + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP17); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC sample time register 2 (ADC_SMPR2) Address offset: 0x10
  uiAdress = ADC1_B + ADC_SMPR2;
  uiValue = (ADC_SAMP_CYCLES<< ADC_SMPR2_SMP0) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP1) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP2) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP3) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP4) + + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP5) + + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP6) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP7) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP8) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP9); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC regular sequence register 1 (ADC_SQR1) Address offset: 0x2C
  uiAdress = ADC1_B + ADC_SQR1;
  uiValue = ((uint32)(adcBufferLength/2-1) << ADC_SQR1_L) + (ADC1_SQ13 << ADC_SQR1_SQ13) + (ADC1_SQ14  << ADC_SQR1_SQ14) + (ADC1_SQ15 << ADC_SQR1_SQ15) + (ADC1_SQ16 << ADC_SQR1_SQ16); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC regular sequence register 2 (ADC_SQR1) Address offset: 0x30
  uiAdress = ADC1_B + ADC_SQR2;
  uiValue = (ADC1_SQ7 << ADC_SQR2_SQ7) + (ADC1_SQ8 << ADC_SQR2_SQ8) + (ADC1_SQ9 << ADC_SQR2_SQ9) + (ADC1_SQ10 << ADC_SQR2_SQ10) + (ADC1_SQ11 << ADC_SQR2_SQ11) + (ADC1_SQ12 << ADC_SQR2_SQ12); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC regular sequence register 3 (ADC_SQR1) Address offset: 0x34
  uiAdress = ADC1_B + ADC_SQR3;
  uiValue = (ADC1_SQ1 << ADC_SQR3_SQ1) + (ADC1_SQ2 << ADC_SQR3_SQ2) + (ADC1_SQ3 << ADC_SQR3_SQ3) + (ADC1_SQ4 << ADC_SQR3_SQ4) + (ADC1_SQ5 << ADC_SQR3_SQ5) + (ADC1_SQ1 << ADC_SQR3_SQ6); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //***Configure ADC2***
#ifdef debugConfiguration
  Serial.println("Configuring ADC2");
#endif
  //ADC sample time register 1 (ADC_SMPR1) Address offset: 0x0C 
  uiAdress = ADC2_B + ADC_SMPR1;
  uiValue = (ADC_SAMP_CYCLES << ADC_SMPR1_SMP10) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP11) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP12) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP13) + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP14) + + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP15) + + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP16) + + (ADC_SAMP_CYCLES << ADC_SMPR1_SMP17); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC sample time register 2 (ADC_SMPR2) Address offset: 0x10
  uiAdress = ADC2_B + ADC_SMPR2;
  uiValue = (ADC_SAMP_CYCLES << ADC_SMPR2_SMP0) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP1) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP2) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP3) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP4) + + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP5) + + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP6) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP7) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP8) + (ADC_SAMP_CYCLES << ADC_SMPR2_SMP9); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC regular sequence register 1 (ADC_SQR1) Address offset: 0x2C
  uiAdress = ADC2_B + ADC_SQR1;
  uiValue = ((uint32)(adcBufferLength/2-1) << ADC_SQR1_L) + (ADC2_SQ13 << ADC_SQR1_SQ13) + (ADC2_SQ14 << ADC_SQR1_SQ14) + (ADC2_SQ15 << ADC_SQR1_SQ15) + (ADC2_SQ16 << ADC_SQR1_SQ16); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC regular sequence register 2 (ADC_SQR1) Address offset: 0x30
  uiAdress = ADC2_B + ADC_SQR2;
  uiValue = (ADC2_SQ7 << ADC_SQR2_SQ7) + (ADC2_SQ8 << ADC_SQR2_SQ8) + (ADC2_SQ9 << ADC_SQR2_SQ9) + (ADC2_SQ10 << ADC_SQR2_SQ10) + (ADC2_SQ11 << ADC_SQR2_SQ11) + (ADC2_SQ12 << ADC_SQR2_SQ12); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC regular sequence register 3 (ADC_SQR1) Address offset: 0x34
  uiAdress = ADC2_B + ADC_SQR3;
  uiValue = (ADC2_SQ1 << ADC_SQR3_SQ1) + (ADC2_SQ2 << ADC_SQR3_SQ2) + (ADC2_SQ3 << ADC_SQR3_SQ3) + (ADC2_SQ4 << ADC_SQR3_SQ4) + (ADC2_SQ5 << ADC_SQR3_SQ5) + (ADC2_SQ6 << ADC_SQR3_SQ6); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);

  //***Enable ADC***
#ifdef debugConfiguration
  Serial.println("Enabling ADC");
#endif
  //Enable ADC DMA and internal temperature sensor
  //ADC control register 2 (ADC_CR2) Address offset: 0x08  
  uiAdress = ADC1_B + ADC_CR2;
  uiValue = (1<< ADC_CR2_DMA) + (1<< ADC_CR2_TSVREFE);//+ (1<< ADC_CR2_EXTTRIG) + (ADC_CR2_EXTSEL_T1_CC1 << ADC_CR2_EXTSEL); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  
  //Enable ADC
  //ADC control register 2 (ADC_CR2) Address offset: 0x08  
  uiAdress = ADC1_B + ADC_CR2;
  uiValue = (1<< ADC_CR2_ADON); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC control register 2 (ADC_CR2) Address offset: 0x08  
  uiAdress = ADC2_B + ADC_CR2;
  uiValue = (1<< ADC_CR2_ADON); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);

  delay(1);

  //Reset Calibration
  //ADC control register 2 (ADC_CR2) Address offset: 0x08  
  uiAdress = ADC1_B + ADC_CR2;
  uiValue = (1<< ADC_CR2_RSTCAL); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //ADC control register 2 (ADC_CR2) Address offset: 0x08  
  uiAdress = ADC2_B + ADC_CR2;
  uiValue = (1<< ADC_CR2_RSTCAL); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //wait for reset calibration to complete
  bool xCallResetting = true;
  uint32 auxVal1 = 0;
  uint32 auxVal2 = 0;
  while (xCallResetting){
    uiAdress = ADC1_B + ADC_CR2; // + 20 Ã— (1 â€“ 1);
    auxVal1 = *(uint32*)(uiAdress) & (1<< ADC_CR2_RSTCAL);
    uiAdress = ADC2_B + ADC_CR2;
    auxVal2 = *(uint32*)(uiAdress) & (1<< ADC_CR2_RSTCAL);
    xCallResetting = auxVal1 || auxVal2;
#ifdef debugConfiguration
    Serial.println("Waiting for calibration reset: " + String(xCallResetting) );
    Serial.println("ADC1_CR2_RSTCAL: " + DisplayBin32(auxVal1));
    Serial.println("ADC2_CR2_RSTCAL: " + DisplayBin32(auxVal2));
#endif
  }

  //Calibrate ADC1
  //ADC control register 2 (ADC_CR2) Address offset: 0x08  
  uiAdress = ADC1_B + ADC_CR2;
  uiValue = (1<< ADC_CR2_CAL); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //wait for calibration to complete
  xCallResetting = true;
  auxVal1 = 0;
  while (xCallResetting){
    uiAdress = ADC1_B + ADC_CR2; // + 20 Ã— (1 â€“ 1);
    auxVal1 = *(uint32*)(uiAdress) & (1<< ADC_CR2_CAL);
    xCallResetting = (bool)auxVal1;
#ifdef debugConfiguration
    Serial.println("Waiting for calibration: " + String(xCallResetting) );
    Serial.println("ADC1_CR2_CAL: " + DisplayBin32(auxVal1));
#endif
  }
  //Calibrate ADC2
  //ADC control register 2 (ADC_CR2) Address offset: 0x08  
  uiAdress = ADC1_B + ADC_CR2;
  uiValue = (1<< ADC_CR2_CAL); //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //wait for calibration to complete
  xCallResetting = true;
  auxVal1 = 0;
  while (xCallResetting){
    uiAdress = ADC2_B + ADC_CR2; // + 20 Ã— (1 â€“ 1);
    auxVal1 = *(uint32*)(uiAdress) & (1<< ADC_CR2_CAL);
    xCallResetting = (bool)auxVal1;
#ifdef debugConfiguration
    Serial.println("Waiting for calibration: " + String(xCallResetting) );
    Serial.println("ADC2_CR2_CAL: " + DisplayBin32(auxVal1));
#endif
  }

  //***Reset DMA Counter***
#ifdef debugConfiguration
  Serial.println("Resetting DMA Counter");
#endif
  //Disable channel!!!
  //DMA channel x configuration register (DMA_CCRx)
  uiAdress = DMA_B + DMA_CCRx;
  uiValue = 1<< DMA_CCRx_EN; //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, false);
  //Reset DMA counter
  //DMA channel x number of data register (DMA_CNDTRx)
  uiAdress = DMA_B + DMA_CNDTRx;
  uiValue = (uint32)adcBufferLength/2;
  SetValue32((uint32*)(uiAdress), 0xFFFFFFFF, false);
  SetValue32((uint32*)(uiAdress), uiValue, true);
  //Re-enable channel!!!
  //DMA channel x configuration register (DMA_CCRx)
  uiAdress = DMA_B + DMA_CCRx;
  uiValue = 1<< DMA_CCRx_EN; //Rotate LEFT
  SetValue32((uint32*)(uiAdress), uiValue, true);
  
}


void SetValue32(uint32* uiAdress, uint32 uiValue, bool set) {
#ifdef debugConfiguration
  uint32 uiOriginalValue = *uiAdress;
#endif
  if (set) {
    *uiAdress |= uiValue;
  }
  else {
    *uiAdress &= ~uiValue;
  }
#ifdef debugConfiguration
  Serial.println("Changed uint32 value in adress:" + String((uint32)uiAdress, HEX));
  Serial.println("With: " + DisplayBin32(uiValue));
  Serial.println("From: " + DisplayBin32(uiOriginalValue));
  Serial.println("to:   " + DisplayBin32(*(uint32*)uiAdress));
#else
  delay(1);
#endif
}

void SetValueFast32(uint32* uiAdress, uint32 uiValue, bool set) {
  if (set) {
    *uiAdress |= uiValue;
  }
  else {
    *uiAdress &= ~uiValue;
  }
}

void ReadAnalogNative() {
  uint32 uiAdress = 0;
  uint32 uiValue = 0;
  //***Configure RCC***
#ifdef debugConfigurationRead
  Serial.println("Reading Analog");
#endif
  //Clear DMA reset flags
  uiAdress = DMA_B + DMA_IFCR;
  uiValue = 0xF<<DMA_IFCR_CHN1; //Rotate LEFT
  SetValueFast32((uint32*)(uiAdress), uiValue, false);

  
  //ADC Start
  uiAdress = ADC1_B + ADC_CR2;
  uiValue = 1 << ADC_CR2_SWSTART; //Rotate LEFT
  SetValueFast32((uint32*)(uiAdress), uiValue, true);


}  

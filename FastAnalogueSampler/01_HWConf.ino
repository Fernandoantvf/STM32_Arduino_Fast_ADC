/*
 * HWCOnf - Hardware Configuration
 * 
 * This tab contains hardware specific definitions
 * 
 */

//RCC
#define RCC_B 0x40021000  //RCC base adress
//Clock control register (RCC_CR) Address offset: 0x00 
#define   RCC_CR      0x00
#define   RCC_CR_PLLRDY      25      //Bit 25 PLLRDY: PLL clock ready flag 
#define   RCC_CR_PLLON      24      //Bit 24 PLLON: PLL enable 
#define   RCC_CR_CSSON      19      //Bit 19 CSSON: Clock security system enable 
#define   RCC_CR_HSEBYP      18      //Bit 18 HSEBYP: External high-speed clock bypass 
#define   RCC_CR_HSERDY      17      //Bit 17 HSERDY: External high-speed clock ready flag 
#define   RCC_CR_HSEON      16      //Bit 16 HSEON: HSE clock enable 
#define   RCC_CR_HSICAL      8      //Bits 15:8 HSICAL[7:0]: Internal high-speed clock calibration 
#define   RCC_CR_HSITRIM      3      //Bits 7:3 HSITRIM[4:0]: Internal high-speed clock trimming 
#define   RCC_CR_HSIRDY      1      //Bit 1 HSIRDY: Internal high-speed clock ready flag 
#define   RCC_CR_HSION      0      //Bit 0 HSION: Internal high-speed clock enable 
//Clock configuration register (RCC_CFGR) Address offset: 0x04 
#define   RCC_CFGR      0x04
#define   RCC_CFGR_MCO      24      //Bits 26:24 MCO: Microcontroller clock output 
#define   RCC_CFGR_USBPRE      22      //Bit 22 USBPRE: USB prescaler 
#define   RCC_CFGR_PLLMUL      18      //Bits 21:18 PLLMUL: PLL multiplication factor 
#define   RCC_CFGR_HSEBYP      18      //Bit 18 HSEBYP: External high-speed clock bypass 
#define   RCC_CFGR_PLLXTPRE      17      //Bit 17 PLLXTPRE: HSE divider for PLL entry 
#define   RCC_CFGR_PLLSRC      16      //Bit 16 PLLSRC: PLL entry clock source 
#define   RCC_CFGR_ADCPRE      14      //Bits 15:14 ADCPRE: ADC prescaler 
#define   RCC_CFGR_PPRE2      11      //Bits 13:11 PPRE2: APB high-speed prescaler (APB2) 
#define   RCC_CFGR_PPRE1      8      //Bits 10:8 PPRE1: APB low-speed prescaler (APB1) 
#define   RCC_CFGR_HPRE      4      //Bits 7:4 HPRE: AHB prescaler 
#define   RCC_CFGR_SWS      2      //Bits 3:2 SWS: System clock switch status 
#define   RCC_CFGR_SW      0      //Bits 1:0 SW: System clock switch
//ADCPRE: ADC prescaler
#define PCLK2div2 B00 //: PCLK2 divided by 2
#define PCLK2div4 B01 //: PCLK2 divided by 4
#define PCLK2div6 B10 //: PCLK2 divided by 6
#define PCLK2div8 B11 //: PCLK2 divided by 8
//Clock interrupt register (RCC_CIR) Address offset: 0x08 
#define   RCC_CIR      0x08
#define   RCC_CIR_CSSC      23      //Bit 23 CSSC: Clock security system interrupt clear 
#define   RCC_CIR_PLLRDYC      20      //Bit 20 PLLRDYC: PLL ready interrupt clear 
#define   RCC_CIR_HSERDYC      19      //Bit 19 HSERDYC: HSE ready interrupt clear 
#define   RCC_CIR_LSERDYC      17      //Bit 17 LSERDYC: LSE ready interrupt clear 
#define   RCC_CIR_LSIRDYC      16      //Bit 16 LSIRDYC: LSI ready interrupt clear 
#define   RCC_CIR_PLLRDYIE      12      //Bit 12 PLLRDYIE: PLL ready interrupt enable 
#define   RCC_CIR_HSERDYIE      11      //Bit 11 HSERDYIE: HSE ready interrupt enable 
#define   RCC_CIR_HSIRDYIE      10      //Bit 10 HSIRDYIE: HSI ready interrupt enable 
#define   RCC_CIR_LSERDYIE      9      //Bit 9 LSERDYIE: LSE ready interrupt enable 
#define   RCC_CIR_LSIRDYIE      8      //Bit 8 LSIRDYIE: LSI ready interrupt enable 
#define   RCC_CIR_CSSF      7      //Bit 7 CSSF: Clock security system interrupt flag 
#define   RCC_CIR_PLLRDYF      4      //Bit 4 PLLRDYF: PLL ready interrupt flag 
#define   RCC_CIR_HSERDY      3      //Bit 3 HSERDYF: HSE ready interrupt flag 
#define   RCC_CIR_HSIRDYF      2      //Bit 2 HSIRDYF: HSI ready interrupt flag 
#define   RCC_CIR_LSERDYF      1      //Bit 1 LSERDYF: LSE ready interrupt flag 
#define   RCC_CIR_LSIRDYF      0      //Bit 0 LSIRDYF: LSI ready interrupt flag 
//APB2 peripheral reset register (RCC_APB2RSTR) Address offset: 0x0C 
#define   RCC_APB2RSTR      0x0C
#define   RCC_APB2RSTR_TIM11RST      21      //Bit 21 TIM11RST: TIM11 timer reset 
#define   RCC_APB2RSTR_TIM10RST      20      //Bit 20 TIM10RST: TIM10 timer reset 
#define   RCC_APB2RSTR_TIM9RST      19      //Bit 19 TIM9RST: TIM9 timer reset 
#define   RCC_APB2RSTR_ADC3RST      15      //Bit 15 ADC3RST: ADC3 interface reset 
#define   RCC_APB2RSTR_USART1RST      14      //Bit 14 USART1RST: USART1 reset 
#define   RCC_APB2RSTR_TIM8RST      13      //Bit 13 TIM8RST: TIM8 timer reset 
#define   RCC_APB2RSTR_SPI1RST      12      //Bit 12 SPI1RST: SPI1 reset 
#define   RCC_APB2RSTR_TIM1RST      11      //Bit 11 TIM1RST: TIM1 timer reset 
#define   RCC_APB2RSTR_ADC2RST      10      //Bit 10 ADC2RST: ADC 2 interface reset 
#define   RCC_APB2RSTR_ADC1RST      9      //Bit 9 ADC1RST: ADC 1 interface reset 
#define   RCC_APB2RSTR_IOPGRST      8      //Bit 8 IOPGRST: IO port G reset 
#define   RCC_APB2RSTR_IOPFRST      7      //Bit 7 IOPFRST: IO port F reset 
#define   RCC_APB2RSTR_IOPERST      6      //Bit 6 IOPERST: IO port E reset 
#define   RCC_APB2RSTR_IOPDRST      5      //Bit 5 IOPDRST: IO port D reset 
#define   RCC_APB2RSTR_IOPCRST      4      //Bit 4 IOPCRST: IO port C reset 
#define   RCC_APB2RSTR_IOPBRST      3      //Bit 3 IOPBRST: IO port B reset 
#define   RCC_APB2RSTR_IOPARST      2      //Bit 2 IOPARST: IO port A reset 
#define   RCC_APB2RSTR_AFIORST      0      //Bit 0 AFIORST: Alternate function IO reset 
//APB1 peripheral reset register (RCC_APB1RSTR) Address offset: 0x10 
#define   RCC_APB1RSTR      0x10
#define   RCC_APB1RSTR_DACRST      29      //Bit 29 DACRST: DAC interface reset 
#define   RCC_APB1RSTR_PWRRST      28      //Bit 28 PWRRST: Power interface reset 
#define   RCC_APB1RSTR_BKPRST      27      //Bit 27 BKPRST: Backup interface reset 
#define   RCC_APB1RSTR_CANRST      25      //Bit 25 CANRST: CAN reset 
#define   RCC_APB1RSTR_USBRST      23      //Bit 23 USBRST: USB reset 
#define   RCC_APB1RSTR_I2C2RST      22      //Bit 22 I2C2RST: I2C2 reset 
#define   RCC_APB1RSTR_I2C1RST      21      //Bit 21 I2C1RST: I2C1 reset 
#define   RCC_APB1RSTR_UART5RST      20      //Bit 20 UART5RST: USART5 reset 
#define   RCC_APB1RSTR_UART4RST      19      //Bit 19 UART4RST: USART4 reset 
#define   RCC_APB1RSTR_USART3RST      18      //Bit 18 USART3RST: USART3 reset 
#define   RCC_APB1RSTR_USART2RST      17      //Bit 17 USART2RST: USART2 reset 
#define   RCC_APB1RSTR_SPI3RST      15      //Bit 15 SPI3RST: SPI3 reset 
#define   RCC_APB1RSTR_SPI2RST      14      //Bit 14 SPI2RST: SPI2 reset 
#define   RCC_APB1RSTR_WWDGRST      11      //Bit 11 WWDGRST: Window watchdog reset 
#define   RCC_APB1RSTR_TIM14RST      8      //Bit 8 TIM14RST: TIM14 timer reset 
#define   RCC_APB1RSTR_TIM13RST      7      //Bit 7 TIM13RST: TIM13 timer reset 
#define   RCC_APB1RSTR_TIM12RST      6      //Bit 6 TIM12RST: TIM12 timer reset 
#define   RCC_APB1RSTR_TIM7RST      5      //Bit 5 TIM7RST: TIM7 timer reset 
#define   RCC_APB1RSTR_TIM6RST      4      //Bit 4 TIM6RST: TIM6 timer reset 
#define   RCC_APB1RSTR_TIM5RST      3      //Bit 3 TIM5RST: TIM5 timer reset 
#define   RCC_APB1RSTR_TIM4RST      2      //Bit 2 TIM4RST: TIM4 timer reset 
#define   RCC_APB1RSTR_TIM3RST      1      //Bit 1 TIM3RST: TIM3 timer reset 
#define   RCC_APB1RSTR_TIM2RST      0      //Bit 0 TIM2RST: TIM2 timer reset 
//AHB peripheral clock enable register (RCC_AHBENR) Address offset: 0x14 
#define   RCC_AHBENR      0x14
#define   RCC_AHBENR_SDIOEN      10      //Bit 10 SDIOEN: SDIO clock enable 
#define   RCC_AHBENR_FSMCEN      8      //Bit 8 FSMCEN: FSMC clock enable 
#define   RCC_AHBENR_CRCEN      6      //Bit 6 CRCEN: CRC clock enable 
#define   RCC_AHBENR_FLITFEN      4      //Bit 4 FLITFEN: FLITF clock enable 
#define   RCC_AHBENR_SRAMEN      2      //Bit 2 SRAMEN: SRAM interface clock enable 
#define   RCC_AHBENR_DMA2EN      1      //Bit 1 DMA2EN: DMA2 clock enable 
#define   RCC_AHBENR_DMA1EN      0      //Bit 0 DMA1EN: DMA1 clock enable
//APB2 peripheral clock enable register (RCC_APB2ENR) Address: 0x18 
#define   RCC_APB2ENR      0x18
#define   RCC_APB2ENR_TIM11EN      21      //Bit 21 TIM11EN: TIM11 timer clock enable 
#define   RCC_APB2ENR_TIM10EN      20      //Bit 20 TIM10EN: TIM10 timer clock enable 
#define   RCC_APB2ENR_TIM9EN      19      //Bit 19 TIM9EN: TIM9 timer clock enable 
#define   RCC_APB2ENR_ADC3EN      15      //Bit 15 ADC3EN: ADC3 interface clock enable 
#define   RCC_APB2ENR_USART1EN      14      //Bit 14 USART1EN: USART1 clock enable 
#define   RCC_APB2ENR_TIM8EN      13      //Bit 13 TIM8EN: TIM8 Timer clock enable 
#define   RCC_APB2ENR_SPI1EN      12      //Bit 12 SPI1EN: SPI1 clock enable 
#define   RCC_APB2ENR_TIM1EN      11      //Bit 11 TIM1EN: TIM1 timer clock enable 
#define   RCC_APB2ENR_ADC2EN      10      //Bit 10 ADC2EN: ADC 2 interface clock enable 
#define   RCC_APB2ENR_ADC1EN      9      //Bit 9 ADC1EN: ADC 1 interface clock enable 
#define   RCC_APB2ENR_IOPGEN      8      //Bit 8 IOPGEN: IO port G clock enable 
#define   RCC_APB2ENR_IOPFEN      7      //Bit 7 IOPFEN: IO port F clock enable 
#define   RCC_APB2ENR_IOPEEN      6      //Bit 6 IOPEEN: IO port E clock enable 
#define   RCC_APB2ENR_IOPDEN      5      //Bit 5 IOPDEN: IO port D clock enable 
#define   RCC_APB2ENR_IOPCEN      4      //Bit 4 IOPCEN: IO port C clock enable 
#define   RCC_APB2ENR_IOPBEN      3      //Bit 3 IOPBEN: IO port B clock enable 
#define   RCC_APB2ENR_IOPAEN      2      //Bit 2 IOPAEN: IO port A clock enable 
#define   RCC_APB2ENR_AFIOEN      0      //Bit 0 AFIOEN: Alternate function IO clock enable 
//APB1 peripheral clock enable register (RCC_APB1ENR) Address: 0x1C 
#define   RCC_APB1ENR      0x1C
#define   RCC_APB1ENR_DACEN      29      //Bit 29 DACEN: DAC interface clock enable 
#define   RCC_APB1ENR_PWREN      28      //Bit 28 PWREN: Power interface clock enable 
#define   RCC_APB1ENR_BKPEN      27      //Bit 27 BKPEN: Backup interface clock enable 
#define   RCC_APB1ENR_CANEN      25      //Bit 25 CANEN: CAN clock enable 
#define   RCC_APB1ENR_USBEN      23      //Bit 23 USBEN: USB clock enable 
#define   RCC_APB1ENR_I2C2EN      22      //Bit 22 I2C2EN: I2C2 clock enable 
#define   RCC_APB1ENR_I2C1EN      21      //Bit 21 I2C1EN: I2C1 clock enable 
#define   RCC_APB1ENR_UART5EN      20      //Bit 20 UART5EN: USART5 clock enable 
#define   RCC_APB1ENR_UART4EN      19      //Bit 19 UART4EN: USART4 clock enable 
#define   RCC_APB1ENR_USART3EN      18      //Bit 18 USART3EN: USART3 clock enable 
#define   RCC_APB1ENR_USART2EN      17      //Bit 17 USART2EN: USART2 clock enable 
#define   RCC_APB1ENR_SPI3EN      15      //Bit 15 SPI3EN: SPI 3 clock enable 
#define   RCC_APB1ENR_SPI2EN      14      //Bit 14 SPI2EN: SPI2 clock enable 
#define   RCC_APB1ENR_WWDGEN      11      //Bit 11 WWDGEN: Window watchdog clock enable 
#define   RCC_APB1ENR_TIM14EN      8      //Bit 8 TIM14EN: TIM14 timer clock enable 
#define   RCC_APB1ENR_TIM13EN      7      //Bit 7 TIM13EN: TIM13 timer clock enable 
#define   RCC_APB1ENR_TIM12EN      6      //Bit 6 TIM12EN: TIM12 timer clock enable 
#define   RCC_APB1ENR_TIM7EN      5      //Bit 5 TIM7EN: TIM7 timer clock enable 
#define   RCC_APB1ENR_TIM6EN      4      //Bit 4 TIM6EN: TIM6 timer clock enable 
#define   RCC_APB1ENR_TIM5EN      3      //Bit 3 TIM5EN: TIM5 timer clock enable 
#define   RCC_APB1ENR_TIM4EN      2      //Bit 2 TIM4EN: TIM4 timer clock enable 
#define   RCC_APB1ENR_TIM3EN      1      //Bit 1 TIM3EN: TIM3 timer clock enable 
#define   RCC_APB1ENR_TIM2EN      0      //Bit 0 TIM2EN: TIM2 timer clock enable 
//Backup domain control register (RCC_BDCR) Address offset: 0x20 
#define   RCC_BDCR      0x20
#define   RCC_BDCR_BDRST      16      //Bit 16 BDRST: Backup domain software reset 
#define   RCC_BDCR_RTCEN      15      //Bit 15 RTCEN: RTC clock enable 
#define   RCC_BDCR_RTCSEL      8      //Bits 9:8 RTCSEL[1:0]: RTC clock source selection 
#define   RCC_BDCR_LSEBYP      2      //Bit 2 LSEBYP: External low-speed oscillator bypass 
#define   RCC_BDCR_LSERDY      1      //Bit 1 LSERDY: External low-speed oscillator ready 
#define   RCC_BDCR_LSEON      0      //Bit 0 LSEON: External low-speed oscillator enable 
//Control/status register (RCC_CSR) Address: 0x24 
#define   RCC_CSR      0x24
#define   RCC_CSR_LPWRRSTF      31      //Bit 31 LPWRRSTF: Low-power reset flag 
#define   RCC_CSR_WWDGRSTF      30      //Bit 30 WWDGRSTF: Window watchdog reset flag 
#define   RCC_CSR_IWDGRSTF      29      //Bit 29 IWDGRSTF: Independent watchdog reset flag 
#define   RCC_CSR_SFTRSTF      28      //Bit 28 SFTRSTF: Software reset flag 
#define   RCC_CSR_PORRSTF      27      //Bit 27 PORRSTF: POR/PDR reset flag 
#define   RCC_CSR_PINRSTF      26      //Bit 26 PINRSTF: PIN reset flag 
#define   RCC_CSR_RMVF      24      //Bit 24 RMVF: Remove reset flag 
#define   RCC_CSR_LSIRDY      1      //Bit 1 LSIRDY: Internal low-speed oscillator ready 
#define   RCC_CSR_LSION      0      //Bit 0 LSION: Internal low-speed oscillator enable 
//ADCs
#define  ADC1_B 0x40012400 //ADC1 base adress
#define  ADC2_B 0x40012800 //ADC2 base adress
//ADC status register (ADC_SR) Address offset: 0x00
#define   ADC_SR      0x00
#define   ADC_SR_STRT      4      //Bit 4 STRT: Regular channel Start flag 
#define   ADC_SR_JSTRT      3      //Bit 3 JSTRT: Injected channel Start flag 
#define   ADC_SR_JEOC      2      //Bit 2 JEOC: Injected channel end of conversion 
#define   ADC_SR_EOC      1      //Bit 1 EOC: End of conversion 
#define   ADC_SR_AWD      0      //Bit 0 AWD: Analog watchdog flag 
//ADC control register 1 (ADC_CR1) Address offset: 0x04 
#define   ADC_CR1      0x04
#define   ADC_CR1_AWDEN      23      //Bit 23 AWDEN: Analog watchdog enable on regular channels 
#define   ADC_CR1_JAWDEN      22      //Bit 22 JAWDEN: Analog watchdog enable on injected channels 
#define   ADC_CR1_DUALMOD      16      //Bits 19:16 DUALMOD[3:0]: Dual mode selection 
#define   ADC_CR1_DISCNUM      13      //Bits 15:13 DISCNUM[2:0]: Discontinuous mode channel count 
#define   ADC_CR1_JDISCEN      12      //Bit 12 JDISCEN: Discontinuous mode on injected channels 
#define   ADC_CR1_DISCEN      11      //Bit 11 DISCEN: Discontinuous mode on regular channels 
#define   ADC_CR1_JAUTO      10      //Bit 10 JAUTO: Automatic Injected Group conversion 
#define   ADC_CR1_AWDSGL      9      //Bit 9 AWDSGL: Enable the watchdog on a single channel in scan mode 
#define   ADC_CR1_SCAN      8      //Bit 8 SCAN: Scan mode 
#define   ADC_CR1_JEOCIE      7      //Bit 7 JEOCIE: Interrupt enable for injected channels 
#define   ADC_CR1_AWDIE      6      //Bit 6 AWDIE: Analog watchdog interrupt enable 
#define   ADC_CR1_EOCIE      5      //Bit 5 EOCIE: Interrupt enable for EOC 
#define   ADC_CR1_AWDCH      0      //Bits 4:0 AWDCH[4:0]: Analog watchdog channel select bits 
//ADC control register 2 (ADC_CR2) Address offset: 0x08 
#define   ADC_CR2      0x08
#define   ADC_CR2_TSVREFE      23      //Bit 23 TSVREFE: Temperature sensor and VREFINT enable 
#define   ADC_CR2_SWSTART      22      //Bit 22 SWSTART: Start conversion of regular channels 
#define   ADC_CR2_JSWSTART      21      //Bit 21 JSWSTART: Start conversion of injected channels 
#define   ADC_CR2_EXTTRIG      20      //Bit 20 EXTTRIG: External trigger conversion mode for regular channels
#define   ADC_CR2_EXTSEL      17      //Bits 19:17 EXTSEL[2:0]: External event select for regular group 
#define   ADC_CR2_JEXTTRIG      15      //Bit 15 JEXTTRIG: External trigger conversion mode for injected channels 
#define   ADC_CR2_JEXTSEL      12      //Bits 14:12 JEXTSEL[2:0]: External event select for injected group 
#define   ADC_CR2_ALIGN      11      //Bit 11 ALIGN: Data alignment 
#define   ADC_CR2_DMA      8      //Bit 8 DMA: Direct memory access mode 
#define   ADC_CR2_RSTCAL      3      //Bit 3 RSTCAL: Reset calibration 
#define   ADC_CR2_CAL      2      //Bit 2 CAL: A/D Calibration 
#define   ADC_CR2_CONT      1      //Bit 1 CONT: Continuous conversion 
#define   ADC_CR2_ADON      0      //Bit 0 ADON: A/D converter ON / OFF
//EXTSEL_VALUES
#define   ADC_CR2_EXTSEL_T1_CC1   B000 //: Timer 1 CC1 event
#define   ADC_CR2_EXTSEL_T1_CC2   B001 //: Timer 1 CC2 event
#define   ADC_CR2_EXTSEL_T1_CC3   B010 //: Timer 1 CC3 event
#define   ADC_CR2_EXTSEL_T2_CC2   B011 //: Timer 2 CC2 event
#define   ADC_CR2_EXTSEL_T3_TRGO  B100 //: Timer 3 TRGO event
#define   ADC_CR2_EXTSEL_T4_CC4   B101 //: Timer 4 CC4 event 
//ADC sample time register 1 (ADC_SMPR1) Address offset: 0x0C 
#define   ADC_SMPR1      0x0C
#define   ADC_SMPR1_SMP17      21      //Bits 23:21 SMP17[2:0]: Channel 17 Sample time selection 
#define   ADC_SMPR1_SMP16      18      //Bits 20:18 SMP16[2:0]: Channel 16 Sample time selection 
#define   ADC_SMPR1_SMP15      15      //Bits 17:15 SMP15[2:0]: Channel 15 Sample time selection 
#define   ADC_SMPR1_SMP14      12      //Bits 14:12 SMP14[2:0]: Channel 14  Sample time selection 
#define   ADC_SMPR1_SMP13      9      //Bits 11:9 SMP13[2:0]: Channel 13  Sample time selection 
#define   ADC_SMPR1_SMP12      6      //Bits 8:6 SMP12[2:0]: Channel 12  Sample time selection 
#define   ADC_SMPR1_SMP11      3      //Bits 5:3 SMP11[2:0]: Channel 11  Sample time selection 
#define   ADC_SMPR1_SMP10      0      //Bits 2:0 SMP10[2:0]: Channel 10  Sample time selection 
//ADC sample time register 2 (ADC_SMPR2) Address offset: 0x10 
#define   ADC_SMPR2      0x10
#define   ADC_SMPR2_SMP9      27      //Bits 29:27 SMP9[2:0]: Channel 9 Sample time selection 
#define   ADC_SMPR2_SMP8      24      //Bits 26:24 SMP8[2:0]: Channel 8 Sample time selection 
#define   ADC_SMPR2_SMP7      21      //Bits 23:21 SMP7[2:0]: Channel 7 Sample time selection 
#define   ADC_SMPR2_SMP6      18      //Bits 20:18 SMP6[2:0]: Channel 6 Sample time selection 
#define   ADC_SMPR2_SMP5      15      //Bits 17:15 SMP5[2:0]: Channel 5 Sample time selection 
#define   ADC_SMPR2_SMP4      12      //Bits 14:12 SMP4[2:0]: Channel 4  Sample time selection 
#define   ADC_SMPR2_SMP3      9      //Bits 11:9 SMP3[2:0]: Channel 3  Sample time selection 
#define   ADC_SMPR2_SMP2      6      //Bits 8:6 SMP2[2:0]: Channel 2  Sample time selection 
#define   ADC_SMPR2_SMP1      3      //Bits 5:3 SMP1[2:0]: Channel 1  Sample time selection 
#define   ADC_SMPR2_SMP0      0      //Bits 2:0 SMP0[2:0]: Channel 0  Sample time selection 
//ADC sample time register 1 and 2 values
#define ADC_SMP_1cyc5    B000 //1.5 cycles
#define ADC_SMP_7cyc5    B001 //7.5 cycles
#define ADC_SMP_13cyc5   B010 //13.5 cycles
#define ADC_SMP_28cyc5   B011 //28.5 cycles
#define ADC_SMP_41cyc5   B100 //41.5 cycles
#define ADC_SMP_55cyc5   B101 //55.5 cycles
#define ADC_SMP_71cyc5   B110 //71.5 cycles
#define ADC_SMP_239cyc5  B111 //239.5 cycles
//ADC regular sequence register 1 (ADC_SQR1) Address offset: 0x2C 
#define   ADC_SQR1      0x2C
#define   ADC_SQR1_L      20      //Bits 23:20 L[3:0]: Regular channel sequence length 
#define   ADC_SQR1_SQ16      15      //Bits 19:15 SQ16[4:0]: 16th conversion in regular sequence 
#define   ADC_SQR1_SQ15      10      //Bits 14:10 SQ15[4:0]: 15th conversion in regular sequence 
#define   ADC_SQR1_SQ14      5      //Bits 9:5 SQ14[4:0]: 14th conversion in regular sequence 
#define   ADC_SQR1_SQ13      0      //Bits 4:0 SQ13[4:0]: 13th conversion in regular sequence 
//ADC regular sequence register 2 (ADC_SQR2) Address offset: 0x30 
#define   ADC_SQR2      0x30
#define   ADC_SQR2_SQ12      25      //Bits 29:25 SQ12[4:0]: 12th conversion in regular sequence 
#define   ADC_SQR2_SQ11      20      //Bits 24:20 SQ11[4:0]: 11th conversion in regular sequence 
#define   ADC_SQR2_SQ10      15      //Bits 19:15 SQ10[4:0]: 10th conversion in regular sequence 
#define   ADC_SQR2_SQ9      10      //Bits 14:10 SQ9[4:0]: 9th conversion in regular sequence 
#define   ADC_SQR2_SQ8      5      //Bits 9:5 SQ8[4:0]: 8th conversion in regular sequence 
#define   ADC_SQR2_SQ7      0      //Bits 4:0 SQ7[4:0]: 7th conversion in regular sequence 
//ADC regular sequence register 3 (ADC_SQR3) Address offset: 0x34 
#define   ADC_SQR3      0x34
#define   ADC_SQR3_SQ6      25      //Bits 29:25 SQ6[4:0]: 6th conversion in regular sequence 
#define   ADC_SQR3_SQ5      20      //Bits 24:20 SQ5[4:0]: 5th conversion in regular sequence 
#define   ADC_SQR3_SQ4      15      //Bits 19:15 SQ4[4:0]: 4th conversion in regular sequence 
#define   ADC_SQR3_SQ3      10      //Bits 14:10 SQ3[4:0]: 3rd conversion in regular sequence 
#define   ADC_SQR3_SQ2      5      //Bits 9:5 SQ2[4:0]: 2nd conversion in regular sequence 
#define   ADC_SQR3_SQ1      0      //Bits 4:0 SQ1[4:0]: 1st conversion in regular sequence 
//ADC regular data register (ADC_DR) Address offset: 0x4C 
#define   ADC_DR      0x4C
#define   ADC_DR_ADC2DATA      16      //Bits 31:16 ADC2DATA[15:0]: ADC2 data 
#define   ADC_DR_DATA      0      //Bits 15:0 DATA[15:0]: Regular data 
//DMA
#define  DMA_B 0x40020000 //Direct memory access base adress
//DMA interrupt status register (DMA_ISR) Address offset: 0x00 
#define   DMA_ISR      0x00
#define   DMA_ISR_CHN7      24      //Bit 24 CHN7: Channel7
#define   DMA_ISR_CHN6      20      //Bit 20 CHN6: Channel7
#define   DMA_ISR_CHN5      16      //Bit 16 CHN5: Channel5
#define   DMA_ISR_CHN4      12      //Bit 12 CHN4: Channel7
#define   DMA_ISR_CHN3      8      //Bit 8 CHN3: Channel3
#define   DMA_ISR_CHN2      4      //Bit 4 CHN2: Channel2
#define   DMA_ISR_CHN1      0      //Bit 0 CHN1: Channel1
#define   DMA_ISR_TEIFx      3      //Bit 3 TEIFx: Channel x transfer error flag (x = 1 ..7) 
#define   DMA_ISR_HTIFx      2      //Bit 2 HTIFx: Channel x half transfer flag (x = 1 ..7)
#define   DMA_ISR_TCIFx      1      //Bit 1 TCIFx: Channel x transfer complete flag (x = 1 ..7) 
#define   DMA_ISR_GIFx      0       //Bit 0 GIFx: Channel x global interrupt flag (x = 1 ..7) 
//DMA interrupt flag clear register (DMA_IFCR) Address offset: 0x04 
#define   DMA_IFCR      0x04
#define   DMA_IFCR_CHN7      24      //Bit 24 CHN7: Channel7
#define   DMA_IFCR_CHN6      20      //Bit 20 CHN6: Channel7
#define   DMA_IFCR_CHN5      16      //Bit 16 CHN5: Channel5
#define   DMA_IFCR_CHN4      12      //Bit 12 CHN4: Channel7
#define   DMA_IFCR_CHN3      8      //Bit 8 CHN3: Channel3
#define   DMA_IFCR_CHN2      4      //Bit 4 CHN2: Channel2
#define   DMA_IFCR_CHN1      0      //Bit 0 CHN1: Channel1
#define   DMA_IFCR_CTEIFx      3      //Bits 3 CTEIFx: Channel x transfer error clear (x = 1 ..7) 
#define   DMA_IFCR_CHTIFx      2      //Bits 2 CHTIFx: Channel x half transfer clear (x = 1 ..7)
#define   DMA_IFCR_CTCIFx      1      //Bit 1 CTCIFx: Channel x transfer complete clear (x = 1 ..7) 
#define   DMA_IFCR_CGIFx      0      //Bit 0 CGIFx: Channel x global interrupt clear (x = 1 ..7) 
//DMA channel x configuration register (DMA_CCRx) (x = 1..7, where x = channel number) Address offset: 0x08 + 0d20 Ã— (channel number â€“ 1) 
#define   DMA_CCRx      0x08  //+ 0d20 Ã— (channel number â€“ 1)
#define   DMA_CCRx_MEM2MEM      14      //Bit 14 MEM2MEM: Memory to memory mode 
#define   DMA_CCRx_PL      12      //Bits 13:12 PL[1:0]: Channel priority level 
#define   DMA_CCRx_MSIZE      10      //Bits 11:10 MSIZE[1:0]: Memory size 
#define   DMA_CCRx_PSIZE      8      //Bits 9:8 PSIZE[1:0]: Peripheral size 
#define   DMA_CCRx_MINC      7      //Bit 7 MINC: Memory increment mode 
#define   DMA_CCRx_PINC      6      //Bit 6 PINC: Peripheral increment mode 
#define   DMA_CCRx_CIRC      5      //Bit 5 CIRC: Circular mod 
#define   DMA_CCRx_DIR      4      //Bit 4 DIR: Data transfer direction 
#define   DMA_CCRx_HTIE      2      //Bit 2 HTIE: Half transfer interrupt enable 
#define   DMA_CCRx_TCIE      1      //Bit 1 TCIE: Transfer complete interrupt enable 
#define   DMA_CCRx_EN      0      //Bit 0 EN: Channel enable 
//DMA channel x number of data register (DMA_CNDTRx) (x = 1..7, where x = channel number) Address offset: 0x0C + 0d20 Ã— (channel number â€“ 1) 
#define   DMA_CNDTRx      0x0C
//DMA channel x peripheral address register (DMA_CPARx) (x = 1..7, where x = channel number) Address offset: 0x10 + 0d20 Ã— (channel number â€“ 1) 
#define   DMA_CPARx      0x10 //+ 0d20 Ã— (channel number â€“ 1) 
//DMA channel x memory address register (DMA_CMARx) (x = 1..7, where x = channel number) Address offset: 0x14 + 0d20 Ã— (channel number â€“ 1) 
#define   DMA_CMARx      0x14
//EXTI
#define  EXTI_B 0x40010400 //External interrupt base adress
//Interrupt mask register (EXTI_IMR) Address offset: 0x00 
#define   EXTI_IMR      0x00
#define   EXTI_IMR_MR19      19      //Bit 19 MR19: Interrupt Mask on line x 
#define   EXTI_IMR_MR18      18      //Bit 18 MR18: Interrupt Mask on line x 
#define   EXTI_IMR_MR17      17      //Bit 17 MR17: Interrupt Mask on line x 
#define   EXTI_IMR_MR16      16      //Bit 16 MR16: Interrupt Mask on line x 
#define   EXTI_IMR_MR15      15      //Bit 15 MR15: Interrupt Mask on line x 
#define   EXTI_IMR_MR14      14      //Bit 14 MR14: Interrupt Mask on line x 
#define   EXTI_IMR_MR13      13      //Bit 13 MR13: Interrupt Mask on line x 
#define   EXTI_IMR_MR12      12      //Bit 12 MR12: Interrupt Mask on line x 
#define   EXTI_IMR_MR11      11      //Bit 11 MR11: Interrupt Mask on line x 
#define   EXTI_IMR_MR10      10      //Bit 10 MR10: Interrupt Mask on line x 
#define   EXTI_IMR_MR9      9      //Bit 9 MR9: Interrupt Mask on line x 
#define   EXTI_IMR_MR8      8      //Bit 8 MR8: Interrupt Mask on line x 
#define   EXTI_IMR_MR7      7      //Bit 7 MR7: Interrupt Mask on line x 
#define   EXTI_IMR_MR6      6      //Bit 6 MR6: Interrupt Mask on line x 
#define   EXTI_IMR_MR5      5      //Bit 5 MR5: Interrupt Mask on line x 
#define   EXTI_IMR_MR4      4      //Bit 4 MR4: Interrupt Mask on line x 
#define   EXTI_IMR_MR3      3      //Bit 3 MR3: Interrupt Mask on line x 
#define   EXTI_IMR_MR2      2      //Bit 2 MR2: Interrupt Mask on line x 
#define   EXTI_IMR_MR1      1      //Bit 1 MR1: Interrupt Mask on line x 
#define   EXTI_IMR_MR0      0      //Bit 0 MR0: Interrupt Mask on line x 
//Event mask register (EXTI_EMR) Address offset: 0x04 
#define   EXTI_EMR      0x04
#define   EXTI_EMR_MR19      19      //Bit 19 MR19: Event Mask on line x 
#define   EXTI_EMR_MR18      18      //Bit 18 MR18: Event Mask on line x 
#define   EXTI_EMR_MR17      17      //Bit 17 MR17: Event Mask on line x 
#define   EXTI_EMR_MR16      16      //Bit 16 MR16: Event Mask on line x 
#define   EXTI_EMR_MR15      15      //Bit 15 MR15: Event Mask on line x 
#define   EXTI_EMR_MR14      14      //Bit 14 MR14: Event Mask on line x 
#define   EXTI_EMR_MR13      13      //Bit 13 MR13: Event Mask on line x 
#define   EXTI_EMR_MR12      12      //Bit 12 MR12: Event Mask on line x 
#define   EXTI_EMR_MR11      11      //Bit 11 MR11: Event Mask on line x 
#define   EXTI_EMR_MR10      10      //Bit 10 MR10: Event Mask on line x 
#define   EXTI_EMR_MR9      9      //Bit 9 MR9: Event Mask on line x 
#define   EXTI_EMR_MR8      8      //Bit 8 MR8: Event Mask on line x 
#define   EXTI_EMR_MR7      7      //Bit 7 MR7: Event Mask on line x 
#define   EXTI_EMR_MR6      6      //Bit 6 MR6: Event Mask on line x 
#define   EXTI_EMR_MR5      5      //Bit 5 MR5: Event Mask on line x 
#define   EXTI_EMR_MR4      4      //Bit 4 MR4: Event Mask on line x 
#define   EXTI_EMR_MR3      3      //Bit 3 MR3: Event Mask on line x 
#define   EXTI_EMR_MR2      2      //Bit 2 MR2: Event Mask on line x 
#define   EXTI_EMR_MR1      1      //Bit 1 MR1: Event Mask on line x 
#define   EXTI_EMR_MR0      0      //Bit 0 MR0: Event Mask on line x 
//Rising trigger selection register (EXTI_RTSR) Address offset: 0x08 
#define   EXTI_RTSR      0x08
#define   EXTI_RTSR_TR19      19      //Bit 19 TR19: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR18      18      //Bit 18 TR18: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR17      17      //Bit 17 TR17: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR16      16      //Bit 16 TR16: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR15      15      //Bit 15 TR15: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR14      14      //Bit 14 TR14: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR13      13      //Bit 13 TR13: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR12      12      //Bit 12 TR12: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR11      11      //Bit 11 TR11: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR10      10      //Bit 10 TR10: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR9      9      //Bit 9 TR9: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR8      8      //Bit 8 TR8: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR7      7      //Bit 7 TR7: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR6      6      //Bit 6 TR6: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR5      5      //Bit 5 TR5: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR4      4      //Bit 4 TR4: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR3      3      //Bit 3 TR3: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR2      2      //Bit 2 TR2: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR1      1      //Bit 1 TR1: Rising trigger event configuration bit of line x 
#define   EXTI_RTSR_TR0      0      //Bit 0 TR0: Rising trigger event configuration bit of line x 
//Falling trigger selection register (EXTI_FTSR) Address offset: 0x0C 
#define   EXTI_FTSR      0x0C
#define   EXTI_FTSR_TR19      19      //Bit 19 TR19: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR18      18      //Bit 18 TR18: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR17      17      //Bit 17 TR17: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR16      16      //Bit 16 TR16: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR15      15      //Bit 15 TR15: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR14      14      //Bit 14 TR14: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR13      13      //Bit 13 TR13: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR12      12      //Bit 12 TR12: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR11      11      //Bit 11 TR11: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR10      10      //Bit 10 TR10: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR9      9      //Bit 9 TR9: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR8      8      //Bit 8 TR8: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR7      7      //Bit 7 TR7: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR6      6      //Bit 6 TR6: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR5      5      //Bit 5 TR5: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR4      4      //Bit 4 TR4: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR3      3      //Bit 3 TR3: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR2      2      //Bit 2 TR2: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR1      1      //Bit 1 TR1: Falling trigger event configuration bit of line x 
#define   EXTI_FTSR_TR0      0      //Bit 0 TR0: Falling trigger event configuration bit of line x 
//Software interrupt event register (EXTI_SWIER) Address offset: 0x10 
#define   EXTI_SWIER      0x10
#define   EXTI_SWIER_SWIER19      19      //Bit 19 SWIER19:Software interrupt on line x 
#define   EXTI_SWIER_SWIER18      18      //Bit 18 SWIER18:Software interrupt on line x 
#define   EXTI_SWIER_SWIER17      17      //Bit 17 SWIER17:Software interrupt on line x 
#define   EXTI_SWIER_SWIER16      16      //Bit 16 SWIER16:Software interrupt on line x 
#define   EXTI_SWIER_SWIER15      15      //Bit 15 SWIER15:Software interrupt on line x 
#define   EXTI_SWIER_SWIER14      14      //Bit 14 SWIER14:Software interrupt on line x 
#define   EXTI_SWIER_SWIER13      13      //Bit 13 SWIER13:Software interrupt on line x 
#define   EXTI_SWIER_SWIER12      12      //Bit 12 SWIER12:Software interrupt on line x 
#define   EXTI_SWIER_SWIER11      11      //Bit 11 SWIER11:Software interrupt on line x 
#define   EXTI_SWIER_SWIER10      10      //Bit 10 SWIER10:Software interrupt on line x 
#define   EXTI_SWIER_SWIER9      9      //Bit 9 SWIER9:Software interrupt on line x 
#define   EXTI_SWIER_SWIER8      8      //Bit 8 SWIER8:Software interrupt on line x 
#define   EXTI_SWIER_SWIER7      7      //Bit 7 SWIER7:Software interrupt on line x 
#define   EXTI_SWIER_SWIER6      6      //Bit 6 SWIER6:Software interrupt on line x 
#define   EXTI_SWIER_SWIER5      5      //Bit 5 SWIER5:Software interrupt on line x 
#define   EXTI_SWIER_SWIER4      4      //Bit 4 SWIER4:Software interrupt on line x 
#define   EXTI_SWIER_SWIER3      3      //Bit 3 SWIER3:Software interrupt on line x 
#define   EXTI_SWIER_SWIER2      2      //Bit 2 SWIER2:Software interrupt on line x 
#define   EXTI_SWIER_SWIER1      1      //Bit 1 SWIER1:Software interrupt on line x 
#define   EXTI_SWIER_SWIER0      0      //Bit 0 SWIER0:Software interrupt on line x 
  //Pending register (EXTI_PR) Address offset: 0x14 
#define   EXTI_PR      0x14
#define   EXTI_PR_PR19       19      //Bit 19 PR19 :Pending bit 
#define   EXTI_PR_PR18       18      //Bit 18 PR18 :Pending bit 
#define   EXTI_PR_PR17       17      //Bit 17 PR17 :Pending bit 
#define   EXTI_PR_PR16       16      //Bit 16 PR16 :Pending bit 
#define   EXTI_PR_PR15       15      //Bit 15 PR15 :Pending bit 
#define   EXTI_PR_PR14       14      //Bit 14 PR14 :Pending bit 
#define   EXTI_PR_PR13       13      //Bit 13 PR13 :Pending bit 
#define   EXTI_PR_PR12       12      //Bit 12 PR12 :Pending bit 
#define   EXTI_PR_PR11       11      //Bit 11 PR11 :Pending bit 
#define   EXTI_PR_PR10       10      //Bit 10 PR10 :Pending bit 
#define   EXTI_PR_PR9       9      //Bit 9 PR9 :Pending bit 
#define   EXTI_PR_PR8       8      //Bit 8 PR8 :Pending bit 
#define   EXTI_PR_PR7       7      //Bit 7 PR7 :Pending bit 
#define   EXTI_PR_PR6       6      //Bit 6 PR6 :Pending bit 
#define   EXTI_PR_PR5       5      //Bit 5 PR5 :Pending bit 
#define   EXTI_PR_PR4       4      //Bit 4 PR4 :Pending bit 
#define   EXTI_PR_PR3       3      //Bit 3 PR3 :Pending bit 
#define   EXTI_PR_PR2       2      //Bit 2 PR2 :Pending bit 
#define   EXTI_PR_PR1       1      //Bit 1 PR1 :Pending bit 
#define   EXTI_PR_PR0       0      //Bit 0 PR0 :Pending bit 

//Position  Priority  Type of   Acronym   Description                     Address
//                    priority
//18        25        settable  ADC1_2    ADC1 and ADC2 global interrupt  0x0000_0088

//GPIO
#define  GPIOA_B 0x40010800 //Port A Base Adress
#define  GPIOB_B 0x40010C00 //Port A Base Adress
#define  GPIOC_B 0x40011000 //Port A Base Adress
#define  GPIOD_B 0x40011400 //Port A Base Adress
#define  GPIOE_B 0x40011800 //Port A Base Adress
//Port configuration register low (GPIOx_CRL) (x=A..G) Address offset: 0x00 
#define   GPIOx_CRL      0x00
#define   GPIOx_CRL_CNF7       30      //Bit 30 CNF7 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_CNF6       26      //Bit 26 CNF6 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_CNF5       22      //Bit 22 CNF5 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_CNF4       18      //Bit 18 CNF4 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_CNF3       14      //Bit 14 CNF3 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_CNF2       10      //Bit 10 CNF2 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_CNF1       6      //Bit 6 CNF1 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_CNF0       2      //Bit 2 CNF0 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRL_MODE7      28      //Bit 28 MODE7[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRL_MODE6      24      //Bit 24 MODE6[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRL_MODE5      20      //Bit 20 MODE5[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRL_MODE4      16      //Bit 16 MODE4[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRL_MODE3      12      //Bit 12 MODE3[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRL_MODE2      8      //Bit 8 MODE2[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRL_MODE1      4      //Bit 4 MODE1[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRL_MODE0      0      //Bit 0 MODE0[1:0]: Port x mode bits (y= 0 .. 7) 
//Port configuration register high (GPIOx_CRH) (x=A..G) Address offset: 0x04 
#define   GPIOx_CRH      0x04
#define   GPIOx_CRH_CNF15      30      //Bit 30 CNF15 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_CNF14      26      //Bit 26 CNF14 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_CNF13      22      //Bit 22 CNF13 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_CNF12      18      //Bit 18 CNF12 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_CNF11      14      //Bit 14 CNF11 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_CNF10      10      //Bit 10 CNF10 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_CNF9       6      //Bit 6 CNF9 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_CNF8       2      //Bit 2 CNF8 :[1:0]: Port x configuration bits (y= 0 .. 7)
#define   GPIOx_CRH_MODE15      28      //Bit 28 MODE15[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRH_MODE14      24      //Bit 24 MODE14[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRH_MODE13      20      //Bit 20 MODE13[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRH_MODE12      16      //Bit 16 MODE12[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRH_MODE11      12      //Bit 12 MODE11[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRH_MODE10      8      //Bit 8 MODE10[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRH_MODE9      4      //Bit 4 MODE9[1:0]: Port x mode bits (y= 0 .. 7) 
#define   GPIOx_CRH_MODE8      0      //Bit 0 MODE8[1:0]: Port x mode bits (y= 0 .. 7) 

#define   GPIOx_CR_CNF_AN 00    //: Analog mode
#define   GPIOx_CR_CNF_FLOAT 01 //: Floating input (reset state)
#define   GPIOx_CR_CNF_PULL 10  //: Input with pull-up / pull-down
#define   GPIOx_CR_CNF_PP 00    //: General purpose output push-pull
#define   GPIOx_CR_CNF_OD 01    //: General purpose output Open-drain
#define   GPIOx_CR_CNF_AFPP 10  //: Alternate function output Push-pull
#define   GPIOx_CR_CNF_AFOD 11  //: Alternate function output Open-drain
#define   GPIOx_CR_MODE_IN 00        //: Input mode (reset state)
#define   GPIOx_CR_MODE_OUT10MHz 01  //: Output mode, max speed 10 MHz.
#define   GPIOx_CR_MODE_OUT2MHz 10   //: Output mode, max speed 2 MHz.
#define   GPIOx_CR_MODE_OUT50MHz     //: Output mode, max speed 50 MHz.
//Port input data register (GPIOx_IDR) (x=A..G) Address offset: 0x08h 
#define   GPIOx_IDR      0x08h
//Port output data register (GPIOx_ODR) (x=A..G) Address offset: 0x0C 
#define   GPIOx_ODR      0x0C

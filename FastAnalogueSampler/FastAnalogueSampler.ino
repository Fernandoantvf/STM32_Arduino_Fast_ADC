/*
   Fast Analog Sampler
   Closed loop control of a revolute actuator with redundant feedback of
   Position and force serving as a colaborative robot actuator

   Author: Fernando Figueiredo
   Copyright: Fernando Figueiredo / SMILE.TECH Robótica / ISPGAYA
   Date of creation: 2020-11-10


   Processor: STM32F103RCBT6
      Clock Speed: 72 MHz/128 KB Flash and 20 KB SRAM
      Documentation:
        Datasheet:            http://www.st.com/content/ccc/resource/technical/document/datasheet/33/d4/6f/1d/df/0b/4c/6d/CD00161566.pdf/files/CD00161566.pdf/jcr:content/translations/en.CD00161566.pdf
        Programming manual:   http://www.st.com/content/ccc/resource/technical/document/programming_manual/5b/ca/8d/83/56/7f/40/08/CD00228163.pdf/files/CD00228163.pdf/jcr:content/translations/en.CD00228163.pdf
        Reference manual:     http://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf


      Memory:
      Adress Range                Memory Region               Notes:
      Family Specific
      0x0000 0000- 0x1FFF FFFF    Code                        Program + data
      0x2000 0000- 0x3FFF FFFF    SRAM                        Data + program
      0x4000 0000- 0x5FFF FFFF    Peripheral
      0x6000 0000- 0x9FFF FFFF    External RAM                Data
      0xA000 0000- 0xDFFF FFFF    External device             External Device memory
      0xE000 0000- 0xE00F FFFF    Private Peripheral BUS      NVIC, System timer, and system control block
      0xE010 0000- 0xFFFF FFFF    Memory mapped peripherals   STM32 standard peripherals
      STM32F103RCBT6
      0x0800 0000- 0x0801 FFFF    Flash memory

*/

HardwareTimer Tim1(1); //Trigger AD conversions
HardwareTimer Tim2(2); //Trigger control loop processing
HardwareTimer Tim4(4); //PWM output timer
#define Tim1per 200   //200 //Timer 1 period
#define Tim2per 115   //115 //Timer 2 period

int32_t lNow, lNowMicros;
int32_t lSerialLastScan, lSerialPauseStart;
bool xSerialPeriodicReport;



void setup() {
  ConfigureSerial();
  delay(100);
  ConfigureAnalogNative();

  delay(500);
  //Tim 1 determines the frequency at which the cyle starts
  Tim1.pause();
  Tim1.setPeriod(Tim1per); //Timer Period in us
  Tim1.setChannel1Mode(TIMER_OUTPUT_COMPARE);
  Tim1.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
  Tim1.attachCompare1Interrupt(StartAnalogConversion);
  Tim1.refresh();
  Tim1.resume();

  //Tim 2 Launches an interrupt after the A/D conversions are done
  Tim2.pause();
  Tim2.setPeriod(Tim2per); //Timer Period in us
  Tim2.setChannel1Mode(TIMER_OUTPUT_COMPARE);
  Tim2.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
  Tim2.attachCompare1Interrupt(CalculateAnalogValues);

  
  Serial.println("Fast Analogue Sampler Ready");

}

void loop() {
  // Read out current instant    
  lNow = millis();
  lNowMicros = micros();
  
  if (abs(lSerialLastScan - lNow) >= 100){
    lSerialLastScan = lNow;
    SerialPeriodicReport();
  }
}


void StartAnalogConversion (void){
  Tim2.resume();
  ReadAnalogNative();
}



void CalculateAnalogValues(void){
  Tim2.pause(); //Will be restarted @ analog conversion

  //Calculate Values here!


}

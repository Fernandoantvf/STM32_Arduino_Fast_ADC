void ConfigureSerial(){
  Serial.begin(2000000);
  Serial.setTimeout(0);
}


/*
 * Transmit Reports On Serial Port
 */
void SerialPeriodicReport(){
  if (xSerialPeriodicReport || abs(lSerialPauseStart - lNow) < 2000)
    return;

  report();
}

void report(){
  Serial.println(String(uiADCBufferPointer[0]) + " " + String(uiADCBufferPointer[1])+ " " + String(uiADCBufferPointer[2])+ " " + String(uiADCBufferPointer[3])+ " " + String(uiADCBufferPointer[4])+ " " + String(uiADCBufferPointer[5])+ " " + String(uiADCBufferPointer[6])+ " " + String(uiADCBufferPointer[7])+ " " + String(uiADCBufferPointer[8])+ " " + String(uiADCBufferPointer[9]));
}

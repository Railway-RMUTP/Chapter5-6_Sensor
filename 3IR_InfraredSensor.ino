int ledPin = 32;        //กำหนด pin ที่ต้องการใช้งานคือ pin 32
int digitalPin = 36;    //กำหนด pin ที่ต้องการใช้งานคือ pin 36
int val = 0;
void setup() {
pinMode(digitalPin, INPUT);  //คำสั่งที่มีไว้สำหรับกำหนดการทำงานของ pin
                             //ให้ทำงานเป็นแบบ INPUT หรือ OUTPUT
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}
 
void loop() {
val = digitalRead(digitalPin); //อ่านค่า digital ที่ต่อกับเซ็นเซอร์ตรวจจับวัตถุ
                               //ค่าที่ได้รับจะเป็น 1(ไม่พบวัตถุ)หรือ 0(พบวัตถุ)
Serial.print("val = ");
Serial.println(val);

if (val == 0) {
digitalWrite(ledPin, HIGH);  //กำหนดให้มีสถานะ logic เป็น1(high = ไฟติด) 
                             //หรือ 0(low = ไฟดับ)     
}
else {
digitalWrite(ledPin, LOW);
}
delay(100);   //ความเร็วในการแสดงผลบนหน้าจอ
}

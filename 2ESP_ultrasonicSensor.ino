const int LEDPin = 32;    //กำหนด pin ที่ต้องการใช้งานคือ pin 32
const int trigPin = 34;   //กำหนด pin ที่ต้องการใช้งานคือ pin 34
const int echoPin = 35;   //กำหนด pin ที่ต้องการใช้งานคือ pin 35

long duration;
int distance;

void setup() {
pinMode(LEDPin, OUTPUT);  //คำสั่งที่มีไว้สำหรับกำหนดการทำงานของ pin
                          //ให้ทำงานเป็นแบบ INPUT หรือ OUTPUT
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW); //กำหนดให้ trigpin มีสถานะ low หรือไม่ทำงานเป็นเวลา 2 ไมโครวินาที
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);//กำหนดให้ trigpin มีสถานะ high หรือทำงานเป็นเวลา 10 ไมโครวินาที     
delayMicroseconds(10);
digitalWrite(trigPin, LOW); //กำหนดให้ trigpin มีสถานะ low หรือไม่ทำงาน
duration = pulseIn(echoPin, HIGH);  //อ่าน echoPin, คลื่นเสียงที่สะท้อนกลับมาเป็นไมโครวินาที

distance= duration/29/2; //เป็นค่าที่ได้จากการคำนวณระยะทางของเสียงที่ได้จากการสะท้อนกลับ

//duration คือค่าที่ได้จาก echo นำมาหาร 29 microseconds/cm ซึ่งก็คือความเร็วของเสียง
//และนำมาหารด้วย 2 อีกครั้ง เพราะใช้เวลาเดินทางเพียงครึ่งเดียว

if(distance <= 10){ //เป็นการกำหนดเงื่อนไขของระยะทาง..
  
  digitalWrite(LEDPin, HIGH); //กำหนดให้มีสถานะ logic เป็น1(high = ไฟติด) 
                              //หรือ 0(low = ไฟดับ)     
}else
{
  digitalWrite(LEDPin, LOW);
}
Serial.print("Distance: ");
Serial.println(distance);
}

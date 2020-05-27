const int LEDPin = 32;      //กำหนด pin ที่ต้องการใช้งานคือ pin 32
const int capteur_D = 26;   //กำหนด pin ที่ต้องการใช้งานคือ pin 26

int val_analogique;

void setup()
{
  pinMode(capteur_D, INPUT); //คำสั่งที่มีไว้สำหรับกำหนดการทำงานของ pin
                             //ให้ทำงานเป็นแบบ INPUT หรือ OUTPUT
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
if(digitalRead(capteur_D) == LOW) //อ่านค่าสถานะ logic ที่ได้รับเป็น1(high = dry) 
                                  //หรือ 0(low = wet)
  {
    Serial.println("Digital value : wet"); 
    
    digitalWrite(LEDPin, HIGH);   //กำหนดให้มีสถานะ logic เป็น1(high = ไฟติด) 
                                  //หรือ 0(low = ไฟดับ)                     
    }
else
  {
    Serial.println("Digital value : dry");
    digitalWrite(LEDPin, LOW);  
  }
  
  val_analogique = analogRead(A0); //อ่านค่าสถานะที่ได้รับเป็น analog
  
  Serial.print("Analog value : ");
  Serial.println(val_analogique); 
  Serial.println("");
  delay(1000);    //ความเร็วในการแสดงผลบนหน้าจอ

}

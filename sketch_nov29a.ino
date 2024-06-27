#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

#define button1 5
#define button2 6
#define button3 8
#define button4 9
#define button5 10

Servo myservo1; //////////กำหนดตัวแปร servo
Servo myservo2; //////////กำหนดตัวแปร servo
Servo myservo3; //////////กำหนดตัวแปร servo
Servo myservo4;

Servo myservo5;
Servo myservo6;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin = 2; //////////// โมดูลรีบเหรียญ

int i = 0; /////// ให้ตัวแปร i = 0 จะไปใช้ใน loop for
int pen = 1; /////// ให้ตัวแปร pen = 1 จะไปใช้ใน loop for
unsigned long duration; ////////// ของ code หยอดเหรียญสำเจ็จรูป ไม่ขออธิบาย มาก
int n = 0; //////// ให้ n = 0 ไปในการใช้ค่า ต่อไป
int count = 0; ////////// ของ code หยอดเหรียญสำเจ็จรูป ไม่ขออธิบาย มาก


void setup() {
  lcd.begin();
  lcd.setCursor(0,0); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
lcd.print("INSERT Coin"); // จอ lcd น่าจะรู้อยู่แล้ว ไม่ขอลงลึก
pinMode(pin, INPUT); // กำหนดโมดุลหยอดเหรียญเป็น INput

  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);


  myservo1.attach(11); //////กำหนดขา servo 1
myservo1.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo2.attach(12); //////กำหนดขาservo 2
myservo2.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo3.attach(13); //////กำหนดขาservo 3
myservo3.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo3.attach(15); //////กำหนดขาservo 3
myservo3.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo3.attach(16); //////กำหนดขาservo 3
myservo3.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา

myservo3.attach(17); //////กำหนดขาservo 3
myservo3.write(0); //// เริ่มต้นครั้งแรก ให้อยู่ที่ 0 องศา



}
void ReadCoin() //สร้าง function อ่านค่าเหรียญ
{

duration = pulseIn(pin, HIGH, 1000000); // สำเร็จรูปไม่ขอลงลึก แค่ เอาค่าไปใช้ให้ถูก ไม่ต้องไปสนใจ
float time=duration/1000.00;


if (time > 2){
count = count + 1;      ////// กรณีหยอด เหรียญ 1 บาท ผมเอาแค่เหรียญ 5 เลยไม่ได้ใช้
//n  =  n+1;/// ถ้า ใช้เขียนว่า n = n+1 ;
Serial.println(count);
}
if (time ==0){

if (count > 3 &&count < 7){
Serial.print(" 5 Bath ");
lcd.clear();
lcd.print("Coin");
lcd.setCursor(0,1);
n = n + 5; ////ค่านี้ที่ผมเอาไปใช้ n = n +5;
}


if (count > 1 &&count < 2){
Serial.print(" 1 Bath ");
lcd.setBacklight(255);
lcd.clear();
lcd.print("Coin");
lcd.setCursor(0,1);
n = n + 1; ////ค่านี้ที่ผมเอาไปใช้ n = n +5;
}


if (count > 8 &&count < 11){
Serial.print(" 10 Bath ");
lcd.setBacklight(255);
lcd.clear();
lcd.print("Coin");
lcd.setCursor(0,1);
n = n + 10; ////ค่านี้ที่ผมเอาไปใช้ n = n +5;
}
count = 0;
}

lcd.setCursor(0,1);

Serial.println(n);
lcd.print(String(n)); //// การโชว์บน n บน LCD ต้องแปลง เป็น String ไม่ไม่แปลงจะเป็นภาษาต่างดาว
}



void Sw_1(){ ///// สร้าง functionSw_1
ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button1) == LOW && (n == 5)) {
Serial.println("button1 is pressed");
delay(50);
Serial.print(n);
for(i = 0 ; i < pen ; i ++){
  myservo1.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(2000); ///ดีเลย์ สองวิ
n = n - 5 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
n = 0 ; /// เคลียค่า เพราะใช้เสร็จแล้ว
myservo1.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_1");
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("TANK YOU");
delay(2000);
lcd.print("INSERT Coin");
}
}//// void Sw_1



void Sw_2(){ ///// สร้าง functionSw_1
ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button2) == LOW && (n == 5)) {
Serial.println("button2 is pressed");
delay(100);
Serial.print(n);
for(i = 0 ; i < pen ; i ++){
  myservo2.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(2000); ///ดีเลย์ สองวิ
n = n - 5 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
n = 0 ; /// เคลียค่า เพราะใช้เสร็จแล้ว
myservo2.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_2");
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("TANK YOU");
delay(2000);
lcd.print("INSERT Coin");
}
}//// void Sw_2






void Sw_3(){ ///// สร้าง functionSw_1
ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button3) == LOW && (n == 5)) {
Serial.println("button3 is pressed");
delay(100);
Serial.print(n);
for(i = 0 ; i < pen ; i ++){
  myservo3.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(2000); ///ดีเลย์ สองวิ
n = n - 10 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
n = 0 ; /// เคลียค่า เพราะใช้เสร็จแล้ว
myservo3.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_3");
lcd.clear();  
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("TANK YOU");
delay(2000);
lcd.print("INSERT Coin");
}
}//// void Sw_3





void Sw_4(){ ///// สร้าง functionSw_1
ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button4) == LOW && (n == 5)) {
Serial.println("button4 is pressed");
delay(100);
Serial.print(n);
for(i = 0 ; i < pen ; i ++){
  myservo4.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(2000); ///ดีเลย์ สองวิ
n = n - 5 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
n = 0 ; /// เคลียค่า เพราะใช้เสร็จแล้ว
myservo4.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_4");
lcd.clear();  
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("TANK YOU");
delay(2000);
lcd.print("INSERT Coin");
}
}//// void Sw_4



void Sw_5(){ ///// สร้าง functionSw_1
ReadCoin(); ///ดึงfunction ReadCoin มาใช้
if(digitalRead(button5) == LOW && (n == 10)) {
Serial.println("button4 is pressed");
delay(100);
Serial.print(n);
for(i = 0 ; i < pen ; i ++){
  myservo5.write(180);
  myservo6.write(180);// ให้ servo หมุนไป ที่ 180 เพราะปากกาจะหล่นมาในช่องรับปากกา
delay(2000); ///ดีเลย์ สองวิ
n = n - 10 ; /// พอปากกาหล่น ให้ n -5 /// 5-5 = 0 เก็บไว้ในตัวแปร n
Serial.print("servo 180");
}/// for
n = 0 ; /// เคลียค่า เพราะใช้เสร็จแล้ว
myservo5.write(0); //////// Servoหมุนไปที่ 0 องศา
myservo6.write(0); //////// Servoหมุนไปที่ 0 องศา
Serial.println("End process Sw_5");
lcd.clear();  
lcd.clear();  
lcd.setCursor(0,1);
lcd.print("TANK YOU");
delay(2000);
lcd.print("INSERT Coin");
}
}//// void Sw_5








void loop() {
  if(digitalRead(button1) == LOW){
    Serial.println("button1 is pressed");
    delay(100);
}
  if(digitalRead(button2) == LOW){
    Serial.println("button2 is pressed");
    delay(100);
}
 if(digitalRead(button3) == LOW){
    Serial.println("button3 is pressed");
    delay(100);
}

if(digitalRead(button4) == LOW){
    Serial.println("button4 is pressed");
    delay(100);
}

if(digitalRead(button5) == LOW){
    Serial.println("button5 is pressed");
    delay(100);
}


Sw_1();
Sw_2();
Sw_3();
Sw_4();
Sw_5();
}

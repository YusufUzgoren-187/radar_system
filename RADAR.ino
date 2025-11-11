#include <Servo.h>
const byte buzzerPin=4;/*const byte ifadesi değiştirilmeyen ifadeler için kullanılır,aynı kalacak olan ifadeler için*/
/*ayrıca const int 0-255 arası değer alır.ona göre bir değer vermemiz gerektir.*/
const byte trigPin=5;
const byte echoPin=6;
long sure;/*long ifadesi ise değişebilecek olan ifadeler için kullanılır,ayrıca değişecek ifadeler için.*/
long mesafe;
servo servo_motor_1;
void setup(){
pinMode(buzzerPin,OUTPUT);
pinMode(trigPin,OUTPUT);/*bu sinyali göndermeye yarar.*/
pinMode(echoPin,INPUT);/*bu gelen sinyali tanımlar,gelen sinyali alır.*/
servo_motor_1.attach(servoPin);/*buradaki(servoPin) biz hangi pine takarsak ona yönlendiriyor.*/
Serial.begin(9600);
}
void loop(){
for(int dönüm=10;dönüm<=200;dönüm++){
servo_motor_1.write(dönüm);
delay(150);
mesafe=mesafehesapla;/*burası (1-2) olarak tanımladığımız kısım mesafe=mesafehesapla diyerek int mesafehesapla( kısmını buraya yazdık.*/
verilerigoster(dönüm,mesafe);/*buradaki kısımda void verilerigoster(int dönüm,int mesafe){
kısmından gösteriliyor,ekrana yazdırıyoruz.LCD veya başka ekran.*/
if(mesafe<=25){
digitalWrite(buzzerpin,HIGH);
delay(100);
digitalWrite(buzzerPin,LOW);
delay(100);
}
}
for(int dönüm=200;dönüm<=10;dönüm--){
servo_motor_1.write(dönüm);
delay(150);
mesafe=mesafehesapla;/*burası (1-2) olarak tanımladığımız kısım mesafe=mesafehesapla diyerek int mesafehesapla( kısmını buraya yazdık.*/
verilerigoster(dönüm,mesafe);/*buradaki kısımda void verilerigoster(int dönüm,int mesafe){
kısmından gösteriliyor,ekrana yazdırıyoruz.LCD veya başka ekran.*/
if(mesafe<=25){
digitalWrite(buzzerpin,HIGH);
delay(100);
digitalWrite(buzzerPin,LOW);
delay(100);
}
}
int mesafehesapla(){/*burada mesafe hesaplamayı tanımladık,ve bunları (1-2) olarak adlandırayım.yukarıdaki mesafe=mesafe hesapla  kısmına yazdım,böylece döngünün içerisindekileri
tekrar etmeye gerek kalmıcak.*/
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
sure=pulseIn(echoPin,HIGH);
mesafe = sure/2*(0.034);
}
void verilerigoster(int dönüm,int mesafe){
Serial.print("Dönüm: ");
Serial.print(donum);
Serial.print(" --- ");
Serial.print(" Mesafe: ");
Serial.print(mesafe);
}
}
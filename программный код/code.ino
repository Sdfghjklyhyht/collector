//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////  

// определение режима соединения и подключение библиотеки RemoteXY 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// настройки соединения 
#define REMOTEXY_WIFI_SSID "Colector"
#define REMOTEXY_WIFI_PASSWORD "Give_me_your_money_now!"
#define REMOTEXY_SERVER_PORT 6666


// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 1060 bytes
  { 255,7,0,22,0,29,4,16,31,1,10,51,1,1,12,12,4,1,31,79,
  78,0,31,79,70,70,0,129,0,14,5,39,4,24,208,161,208,190,209,129,
  209,130,208,190,209,143,208,189,208,184,208,181,32,209,129,208,177,208,190,209,
  128,209,137,208,184,208,186,208,176,0,129,0,1,16,32,4,24,208,161,208,
  190,208,183,208,180,208,176,208,189,208,184,208,181,32,208,183,208,176,208,186,
  208,176,208,183,208,176,58,0,129,0,34,16,26,4,24,208,152,208,189,208,
  180,208,181,208,186,209,129,45,208,162,208,190,208,178,208,176,209,128,0,129,
  0,34,20,12,4,24,49,45,208,146,208,184,208,189,209,130,0,129,0,34,
  24,13,4,24,50,45,208,147,208,176,208,185,208,186,208,176,0,129,0,34,
  32,20,4,24,52,45,208,168,208,191,208,184,208,187,209,140,208,186,208,176,
  0,129,0,34,28,15,4,24,51,45,208,168,208,176,208,185,208,177,208,176,
  0,129,0,34,48,20,4,24,55,45,208,178,208,176,208,187,0,129,0,34,
  36,25,4,24,53,45,208,159,208,190,208,180,209,136,208,184,208,191,208,189,
  208,184,208,186,0,129,0,34,40,21,4,24,54,45,208,155,208,184,208,189,
  208,181,208,185,208,189,208,176,209,143,0,129,0,34,44,28,4,24,208,189,
  208,176,208,191,209,128,208,176,208,178,208,187,209,143,209,142,209,137,208,176,
  209,143,0,129,0,34,52,12,4,24,56,45,208,148,208,178,208,184,208,179,
  208,176,209,130,208,181,208,187,209,140,0,129,0,34,56,16,4,24,57,45,
  208,148,208,176,209,130,209,135,208,184,208,186,0,7,52,2,33,20,5,24,
  16,1,1,1,23,32,8,8,133,31,83,101,116,0,129,0,2,20,30,3,
  24,208,148,208,187,209,143,32,209,129,208,190,208,183,208,180,208,176,208,189,
  208,184,209,143,32,208,183,208,176,208,186,208,176,208,183,208,176,0,129,0,
  2,23,80,3,24,208,178,208,178,208,181,208,180,208,184,209,130,208,181,32,
  208,178,32,208,191,208,190,208,187,208,181,32,0,129,0,2,26,23,3,24,
  208,184,208,189,208,180,208,181,208,186,209,129,209,139,32,209,130,208,190,208,
  178,208,176,209,128,208,190,208,178,32,208,184,32,0,129,0,2,29,28,3,
  24,208,189,208,176,208,182,208,188,208,184,209,130,208,181,32,208,186,208,189,
  208,190,208,191,208,186,209,131,32,83,101,116,46,0,1,1,23,68,8,8,
  133,31,83,101,116,0,7,52,2,69,20,5,24,16,1,129,0,2,65,29,
  3,24,208,184,32,208,189,208,176,208,182,208,188,208,184,209,130,208,181,32,
  208,186,208,189,208,190,208,191,208,186,209,131,32,83,101,116,46,0,129,0,
  2,56,28,3,24,208,184,208,189,208,180,208,181,208,186,209,129,32,208,183,
  208,176,208,188,208,181,208,189,209,143,208,181,208,188,208,190,208,179,208,190,
  32,0,129,0,2,53,22,3,24,208,178,208,178,208,181,208,180,208,184,209,
  130,208,181,32,208,178,32,208,191,208,190,208,187,208,181,32,0,129,0,2,
  50,30,3,24,208,148,208,187,209,143,32,208,184,208,183,208,188,208,181,208,
  189,208,181,208,189,208,184,209,143,32,208,183,208,176,208,186,208,176,208,183,
  208,176,0,129,0,1,40,35,4,24,208,152,208,183,208,188,208,181,208,189,
  208,181,208,189,208,184,208,181,0,129,0,1,44,13,4,24,208,183,208,176,
  208,186,208,176,208,183,208,176,58,0,129,0,2,59,13,3,8,209,130,208,
  190,208,178,208,176,209,128,208,176,32,208,184,32,32,208,184,208,189,208,180,
  208,181,208,186,209,129,32,0,129,0,2,62,30,3,24,208,183,208,176,208,
  188,208,181,208,189,209,143,209,142,209,137,208,181,208,179,208,190,32,209,130,
  208,190,208,178,208,176,209,128,208,176,0,129,0,15,76,32,3,8,208,160,
  208,176,209,129,208,191,208,190,208,187,208,190,208,182,208,181,208,189,208,184,
  208,181,32,209,130,208,190,208,178,208,176,209,128,208,176,58,0,67,5,5,
  86,5,5,24,30,2,67,5,11,86,5,5,24,30,2,67,5,23,86,5,
  5,24,30,2,67,5,17,86,5,5,24,30,2,67,5,29,86,5,5,24,
  30,2,67,5,5,92,5,5,24,30,2,67,5,29,92,5,5,24,30,2,
  67,5,23,92,5,5,24,30,2,67,5,17,92,5,5,24,30,2,67,5,
  11,92,5,5,24,30,2,67,4,37,89,15,5,24,30,2,129,0,14,81,
  10,3,8,208,161,209,130,208,181,208,187,208,187,208,176,208,182,0,129,0,
  39,81,10,3,8,208,154,208,190,209,128,208,190,208,177,208,186,208,176,0 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  uint8_t system_sost; // =1 если включено, иначе =0 
  int16_t get_order;  // 32767.. +32767 
  uint8_t set_order; // =1 если кнопка нажата, иначе =0 
  uint8_t remove_order; // =1 если кнопка нажата, иначе =0 
  int16_t removed_order;  // 32767.. +32767 

    // output variables
  char s1[1];  // =строка UTF8 оканчивающаяся нулем 
  char s2[1];  // =строка UTF8 оканчивающаяся нулем 
  char s4[1];  // =строка UTF8 оканчивающаяся нулем 
  char s3[1];  // =строка UTF8 оканчивающаяся нулем 
  char s5[1];  // =строка UTF8 оканчивающаяся нулем 
  char s6[1];  // =строка UTF8 оканчивающаяся нулем 
  char s10[1];  // =строка UTF8 оканчивающаяся нулем 
  char s9[1];  // =строка UTF8 оканчивающаяся нулем 
  char s8[1];  // =строка UTF8 оканчивающаяся нулем 
  char s7[1];  // =строка UTF8 оканчивающаяся нулем 
  char box[3];  // =строка UTF8 оканчивающаяся нулем 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////


//Сканер
#include <SoftwareSerial.h> 

//Датчик растояния
#include <Wire.h> 
#include <VL53L0X.h>

//Датчик растояния
#define HIGH_ACCURACY 
VL53L0X sensor;
int distance;

//Моторы
#define RM1 D5 //движение робота вперёд назад скорость
#define LM1 D6 
#define SM1 D8
#define RM2 D7 //выдвижение платформы вперёд назад
#define LM2 D0
#define RM3 D3 //вверх вниз
#define LM3 D4 

//Сканер
String inputString = "";        
// все данные получены
boolean stringComplete = false;  
int countstr=0;
// для поиска окончания 
unsigned long millisendstr=0;

void setup() {
  RemoteXY_Init ();
  //моторы
  pinMode(RM1, OUTPUT); 
  pinMode(LM1, OUTPUT);
  pinMode(SM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM3, OUTPUT);
  pinMode(LM3, OUTPUT);
  

  //сканер
  Serial.begin(9600);
  Wire.begin();
  // резервирование 50 bytes для inputString:
  inputString.reserve(50);

  //датччик растояния
#if defined LONG_RANGE 
  // понижает предел скорости обратного сигнала (по умолчанию 0,25 MCPS (мчип/с))
  sensor.setSignalRateLimit(0.1);
  // увеличить периоды лазерного импульса (по умолчанию 14 и 10 PCLK)
  // * - PCLK — это частота периферии
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif

#if defined HIGH_SPEED
  // уменьшить тайминг до 20 мс (по умолчанию около 33 мс)
  sensor.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // увеличить тайминг 200 мс
  sensor.setMeasurementTimingBudget(200000);
#endif

}

//переменные чтобы ебаться в лупе
int zakaz[3] = {-1, -1, -1}; 
int karta[9] = {};//hranenie coordinat nam nuzhnah coordinat i nomera zakaza -1 ne oboznachena
int dist_toch[5] = {}; //сюда нада написать координаты ячеек по датчику ячейка - индекc
int input_zak = 0; //vremennoe hranenie zakaza pri activacii ebaeba
int maxg;
int ming;

int dist(){
  return sensor.readRangeSingleMillimeters();
}


void loop() {
  RemoteXY_Handler ();
  if(RemoteXY.set_order == 1){
    new_zak();
  }
}


 
// сканер функция получения данных по Serial
void serialScanerEvent() {
  //
  if (Serial.available()>0) { 
    // получить байт из буфера:
    char inChar = (char)Serial.read();
    // добавить в строку:
    inputString += inChar;
    countstr++;
    millisendstr=millis();
  }
  else { // окончание передачи
    if(millis()-millisendstr>1000 && countstr>0) {
       stringComplete=true;
    }
  }
}

//D5 D6 движение робота D8 скорость
//D7 D0 туда сюда
//D3 D4 вверх вниз


void move_to(int distant){
  //надо ето написать
  while (1){
  switch (distant)
  {
    case 1 : maxg=50;ming=160;
    case 2 : maxg=160;ming=220;
    case 3 : maxg=220;ming=280;
    case 4 : maxg=280;ming=340;
    case 5 : maxg=340;ming=400;
    case 6 : maxg=50;ming=160;
    case 7 : maxg=160;ming=220;
    case 8 : maxg=220;ming=280;
    case 9 : maxg=340;ming=400;
    case 11 : maxg=600;ming=660;
    case 12 : maxg=660;ming=720;
    case 13 : maxg=720;ming=780;
    if(dist() > maxg)
      {
        digitalWrite(D6, LOW);
        digitalWrite(D5, HIGH);        
      }
      else if(dist()<ming)
      {
        digitalWrite(D5, LOW);
        digitalWrite(D6, HIGH);
      }
      else
      {
        
        digitalWrite(D5, LOW);
        digitalWrite(D6, LOW);
        break;
      } 
  }
  }
}

void go_to_park(){
  //ето тоже надо
  while (1){
    if(dist()>maxg)
      {
        digitalWrite(D6, LOW);
        digitalWrite(D5, HIGH);        
      }
      else
      {
        
        digitalWrite(D5, LOW);
        digitalWrite(D6, LOW);
        break;
      } 
    }
}

void zah_up(){
  digitalWrite(D3, HIGH);
  delay(80000);
  digitalWrite(D3, LOW);
}

void zah_down(){
  digitalWrite(D4, HIGH);
  delay(80000);
  digitalWrite(D4, LOW);
}

void gruz_to_box(){
  //везём и кидаем груз в коробку
  move_to(11);
  digitalWrite(D4, HIGH);
  delay(20000);
  digitalWrite(D4, LOW);
  tuda();
  digitalWrite(D3, HIGH);
  delay(20000);
  digitalWrite(D3, LOW);
  obratno();
}

void hvat(){
  //хватаем коробка с штрихкода
  tuda();
  digitalWrite(D3, HIGH);
  delay(20000);
  digitalWrite(D3, LOW);
  obratno();
  digitalWrite(D4, HIGH);
  delay(20000);
  digitalWrite(D4, LOW);
}

void obratno(){
  digitalWrite(D7, HIGH);
  delay(11000);
  digitalWrite(D7, LOW);
}

void tuda(){
  digitalWrite(D0, HIGH);
  delay(11000);
  digitalWrite(D0, LOW);
}

void out_s(char input[1], int s){
  switch (s)
  {
    case 2 : RemoteXY.s2[1] =  input[1];
    case 3 : RemoteXY.s3[1] =  input[1];
    case 4 : RemoteXY.s4[1] =  input[1];
    case 5 : RemoteXY.s5[1] =  input[1];
    case 6 : RemoteXY.s6[1] =  input[1];
    case 7 : RemoteXY.s7[1] =  input[1];
    case 8 : RemoteXY.s8[1] =  input[1];
    case 9 : RemoteXY.s9[1] =  input[1];
    case 10 : RemoteXY.s10[1] =  input[1];
    case 11 : RemoteXY.box[1] =  input[1];
    case 12 : RemoteXY.box[2] =  input[1];
    case 13 : RemoteXY.box[3] =  input[1];
  }
}

void new_zak(){
    RemoteXY.box[0]=' ';
    RemoteXY.box[1]=' ';
    RemoteXY.box[2]=' ';
    input_zak = RemoteXY.get_order;
    int i = 0;
    while(input_zak != 0){ //цикл записи номеров заказов в input_zak
        zakaz[i] = input_zak % 10;
        i++;
        input_zak /= 10;
    }
    for(int i = 0; i < 5; i++){
      move_to(dist_toch[i]); //сканим нижний ряд
      while(stringComplete){
        serialScanerEvent();
      }
      out_s((char*)inputString[2],i+6);
      karta[(int)inputString[2]] = dist_toch[i];
      // при окончании передачи
      // очистить строку
      inputString = "";
      stringComplete = false;
      countstr=0;
      
    }
    zah_up();
    for(int i = 0; i < 4; i++){
      move_to(dist_toch[i]);//сканим верхний ряд
      while(stringComplete){
        serialScanerEvent();
      }
      out_s((char*)inputString[2],5-i);
      karta[(int)inputString[2]] = dist_toch[i + 5];
      // при окончании передачи
      // очистить строку
      inputString = "";
      stringComplete = false;
      countstr=0;
      
    }
    zah_down();

    for (int i = 0; i < 3; i++){
      if (zakaz[i] == -1){//забираем заказы нижний ряд
        continue;
      }
      if (zakaz[i] > 5){
        zah_up();
        move_to(karta[zakaz[i]]);
        hvat();
        zah_down();
        gruz_to_box();
        out_s((char*)karta[zakaz[i]],11+i);
      }else{
        move_to(karta[zakaz[i]]);
        hvat();
        gruz_to_box();
        out_s((char*)karta[zakaz[i]],11+i);
      }
    }

    zakaz[0] = -1;
    zakaz[1] = -1;
    zakaz[2] = -1; //зануляем всё
    karta[9] = {};
    dist_toch[5] = {}; //и тут тоже зануляем
    input_zak = 0; 
}

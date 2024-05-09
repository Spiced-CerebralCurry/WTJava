//Include the needed library, we will use softer serial communication with the ESP8266
#include <SoftwareSerial.h>
#include <avr/power.h>

//LCD config
#include <Wire.h> 

//Define the used
#define ESP8266_RX 10  //Connect the TX pin from the ESP to this RX pin of the Arduino
#define ESP8266_TX 11  //Connect the TX pin from the Arduino to the RX pin of ESP

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;


const char SSID_ESP[] = "Spiced";         //Give EXACT name of your WIFI
const char SSID_KEY[] = "12345678";              //Add the password of that WIFI connection



const char fetch = "GET http://projectserver.infinityfreeapp.com/TX.php? HTTP/1.1\r\n\r\n";



//Used variables in the code
String url = "";
String URL_withPacket = "";    
unsigned long multiplier[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
//MODES for the ESP
const char CWMODE = '1';//CWMODE 1=STATION, 2=APMODE, 3=BOTH
const char CIPMUX = '1';//CWMODE 0=Single Connection, 1=Multiple Connections

boolean setup_ESP();
boolean read_until_ESP(const char keyword1[], int key_size, int timeout_val, byte mode);
void timeout_start();
boolean timeout_check(int timeout_ms);
void serial_dump_ESP();
boolean connect_ESP();
void connect_webhost();
unsigned long timeout_start_val;
char scratch_data_from_ESP[20];//first byte is the length of bytes
char payload[200];
byte payload_size=0, counter=0;
char ip_address[16];


//Variable RECEIVED from the DATABASE
bool received_bool_1 = 0;
bool received_bool_2 = 0;
bool received_bool_3 = 0;
bool received_bool_4 = 0;
bool received_bool_5 = 0;


//Store received chars in this variables
char t1_from_ESP[5];  //For time from web
char d1_from_ESP[2];  //For received_bool_1
char d2_from_ESP[2];  //For received_bool_2
char d3_from_ESP[2];  //For received_bool_3
char d4_from_ESP[2];  //For received_bool_4
char d5_from_ESP[2];  //For received_bool_5
 

//DEFINE KEYWORDS HERE
const char keyword_OK[] = "OK";
const char keyword_Ready[] = "Ready";
const char keyword_no_change[] = "no change";
const char keyword_blank[] = "#&";
const char keyword_ip[] = "192.";
const char keyword_rn[] = "\r\n";
const char keyword_quote[] = "\"";
const char keyword_carrot[] = ">";
const char keyword_sendok[] = "SEND OK";
const char keyword_linkdisc[] = "Unlink";

const char keyword_t1[] = "t1";
const char keyword_b1[] = "b1";
const char keyword_b2[] = "b2";
const char keyword_b3[] = "b3";
const char keyword_b4[] = "b4";
const char keyword_b5[] = "b5";

const char keyword_doublehash[] = "##";


SoftwareSerial ESP8266(ESP8266_RX, ESP8266_TX);// rx tx



void setup(){//        SETUP     START

  
  //Pin Modes for ESP TX/RX
  pinMode(ESP8266_RX, INPUT);
  pinMode(ESP8266_TX, OUTPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
  digitalWrite(LED5,LOW);
  

  
  ESP8266.begin(115200);//default baudrate for ESP
  ESP8266.listen();//not needed unless using other software serial instances
  Serial.begin(115200); //for status and debug
  
  delay(2000);//delay before kicking things off
  setup_ESP();//go setup the ESP 
 
}




void loop(){

  send_to_server_1(); 
  digitalWrite(LED1,received_bool_1);
  digitalWrite(LED2,received_bool_2); 
  digitalWrite(LED3,received_bool_3); 
  digitalWrite(LED4,received_bool_4); 
  digitalWrite(LED5,received_bool_5);  

  delay(1000);

}//End of the main loop

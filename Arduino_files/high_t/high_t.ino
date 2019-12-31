
int green=9;
int yellow=10;
int red=11;
int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    
                          { 0,1,1,0,0,0,0 },   
                          { 1,1,0,1,1,0,1 },    
                          { 1,1,1,1,0,0,1 },    
                          { 0,1,1,0,0,1,1 },    
                          { 1,0,1,1,0,1,1 },    
                          { 1,0,1,1,1,1,1 },    
                          { 1,1,1,0,0,0,0 },    
                          { 1,1,1,1,1,1,1 },    
                          { 1,1,1,1,0,1,1 }};


void setup() 
{
  Serial.begin(9600);
  Serial.println("<ARDUINO IS READY>");
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(12,OUTPUT);
 }
void loop() 
 {
// digitalWrite(12,LOW);
  for (int counter = 8; counter > 0; --counter)
  {
 if(counter==8)
 {
  Serial.println("<READY TO RECEIVE SIGNAL>");Serial.println("<RECIEVED SIGNAL '1':TRAFFIC HIGH>");
 }
   delay(1000);
   if (counter==8||counter==7||counter==6)
   {
    digitalWrite(11,HIGH);digitalWrite(9,LOW); Num_Write(counter-1);Serial.println("<RED LIGHT IS ON>");
    }
   else if(counter==5||counter==4||counter==3||counter==2) 
   {
    digitalWrite(10,HIGH);digitalWrite(11,LOW); Num_Write(counter-1);Serial.println("<YELLOW LIGHT IS ON>");
    }
   else
   {
    digitalWrite(9,HIGH);digitalWrite(10,LOW); Num_Write(counter-1);Serial.println("<GREEN LIGHT IS ON FOR 23 SECONDS>");delay (23000);
    }
 
  // Num_Write(counter-1);
   }
//digitalWrite(12,HIGH);
  //delay(1000);
} 
void Num_Write(int number)
 {
  int pin= 2;
   for (int j=0; j < 7; j++)
 {
   digitalWrite(pin, num_array[number][j]);
    pin++;
   }
 }


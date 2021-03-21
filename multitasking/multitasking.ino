//defining task intervals
#define task_sw 100
#define task_led 500

//defining initial states
int sw_state=0;
int led_state=0;
unsigned current_value;
unsigned tasksw_ms=0;
unsigned taskled_ms=0;

void setup() {
  pinMode(7,INPUT_PULLUP);
  pinMode(10, OUTPUT);

}

void loop() {
   current_value=millis();
   if((current_value-tasksw_ms)>=task_sw)
    {
      tasksw_ms=current_value;
      if(digitalRead(7)==LOW)
         sw_state++;
    }
   if((current_value-taskled_ms)>=task_led)
   {
    taskled_ms=current_value;
    if(sw_state)
      {
        led_state=led_state^1;
        digitalWrite(10,led_state);
        sw_state--;
      }
    else
        digitalWrite(10,LOW);
   }

}

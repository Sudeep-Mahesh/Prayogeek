volatile byte rx_byte;
unsigned long var_ul;

void serial_transmit_bytes(unsigned char *var_addr,unsigned int len)
{
    for(int i=0;i<len;i++)
    {
        UDR0=*var_addr;
        var_addr++;
        while(!(UCSR0A & (1<<5)));         
    }
}
void setup() {
  // put your setup code here, to run once:
  UBRR0H = 0x00;
  UBRR0L = 103;
  UCSR0B =(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
  UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
  
  var_ul |=((unsigned long )'A' << 24);
  var_ul |=((unsigned long )'B' << 16);
  var_ul|=((unsigned long )'C' << 8);
  var_ul |=((unsigned long )'D');
}

void loop() {
  // put your main code here, to run repeatedly:
  if(rx_byte =='1')
  {
      rx_byte=0;
      serial_transmit_bytes((unsigned char *)&var_ul,4);
  }

}

ISR(USART_RX_vect)
{
    rx_byte=UDR0;
}

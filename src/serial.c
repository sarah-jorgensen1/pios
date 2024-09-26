void putc(int data);

void main{
  esp_printf(putc, "Current Execution Level is %d\r\n", getEL());
}

void putc(int data){
  int *ptr = (int*)0x3F215040;
  *ptr = data;
}

void main() {
  esp_printf(putc, "Current Execution Level is %d\r\n", getEL());
}

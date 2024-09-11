unsigned long get_timer_count() {
 unsigned long *timer_count_register = 0x3f003004;
 return *timer_count_register;
}


void kernel_main() {
    get_timer_count();
    while(1){
    }
}

struct ppage physical_page_array[128]; // 128 pages, each 2mb in length covers 256 megs of memory
struct ppage *free_phys_pages;

void init_pfa_list(void) { 
  for(int i=0; i<128; i++){
    list_add(free_phys_pages, physical_page_array[i]);
    physical_page_array[i].physical_addr = &physical_page_array[i];
    if(i>0){
      physical_page_array[i-1].next = &physical_page_array[i];
      physical_page_array[i].prev = &physical_page_array[i-1];
    }
  }
}

struct ppage *allocate_physical_pages(unsigned int npages) {
  struct ppage *allocd_list;
  for(int i=0; i<npages; i++){
    list_add(allocd_list, physical_page_array[i]);
  }
  return allocd_list;
}

void free_physical_pages(struct ppage *ppage_list){
  list_add(free_phys_pages, ppage_list);
}

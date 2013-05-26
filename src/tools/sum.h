#ifndef _SUM_H_
#define _SUM_H_

uint32_t sum_addc(uint32_t a, uint32_t b);
uint32_t sum_compute(int fd, size_t romsize);
void sum_write(int fd, size_t romsize);

#endif /* _SUM_H_ */


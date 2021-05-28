#ifndef DUTILITY_H
#define DUTILITY_H

#define isleap(y)		((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

int ndigit(int);
int isprime(int);
//void sleep(int millisecond);
void putline(void);
void clear_input_buffer(void);
void randomize(void);
void print_array(const int* p, int size);
void set_random_array(int* p, int size);

#endif

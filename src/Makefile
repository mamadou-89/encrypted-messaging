.PHONY: all clean
CC = gcc
CFLAGS = -Wall -std=c99
#LDFLAGS = -lm -lgmp
TARGET1= dh_crypt
OBJFILES1= dh_crypt.o balise_xor.o
TARGET2=dh_crack
OBJFILES2=dh_crack_c1.o dh_crack_c2_msg.o balise_crack.o dh_crack.o
TARGET3=dh_genkey
OBJFILES3=dh_prime.o dh_genkey.o balise_key.o


all: $(TARGET1) $(TARGET2) $(TARGET3)


dh_crypt.o:dh_crypt.c
	$(CC) $(CFLAGS) -o dh_crypt.o -c  dh_crypt.c $(LDFLAGS)
dh_crack_c1.o:dh_crack_c1.c
	$(CC) $(CFLAGS) -o dh_crack_c1.o -c  dh_crack_c1.c $(LDFLAGS)
dh_crack_c2_msg.o:dh_crack_c2_msg.c
	$(CC) $(CFLAGS) -o dh_crack_c2_msg.o -c  dh_crack_c2_msg.c $(LDFLAGS)
dh_crack.o:dh_crack.c
	$(CC) $(CFLAGS) -o dh_crack.o -c  dh_crack.c $(LDFLAGS)
dh_genkey.o:dh_genkey.c
	$(CC) $(CFLAGS) -o dh_genkey.o -c  dh_genkey.c $(LDFLAGS)
dh_prime.o:dh_prime.c
	$(CC) $(CFLAGS) -o dh_prime.o -c  dh_prime.c $(LDFLAGS)
balise_xor.o:balise_xor.c
	$(CC) $(CFLAGS) -o balise_xor.o -c balise_xor.c $(LDFLAGS)
balise_crack.o:balise_crack.c
	$(CC) $(CFLAGS) -o balise_crack.o -c balise_crack.c $(LDFLAGS)
balise_key.o:balise_key.c
	$(CC) $(CFLAGS) -o balise_key.o -c balise_key.c $(LDFLAGS)
$(TARGET1): $(OBJFILES1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJFILES1) $(LDFLAGS)
$(TARGET2): $(OBJFILES2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJFILES2) $(LDFLAGS)
$(TARGET3): $(OBJFILES3)
	$(CC) $(CFLAGS) -o $(TARGET3) $(OBJFILES3) $(LDFLAGS)

clean_crypt:
	rm -f $(OBJFILES1) $(TARGET1) *~
clean_crack:
	rm -f $(OBJFILES2) $(TARGET2) *~
clean_key:
	rm -f $(OBJFILES3) $(TARGET3) *~



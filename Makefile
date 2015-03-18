CC        = gcc

OPTFLAGS  = -Os -g

CFLAGS   += $(OPTFLAGS) \
            -W \
            -Wall \
            -Wextra \
            -Wimplicit-function-declaration \
            -Wredundant-decls \
            -Wstrict-prototypes \
            -Wundef \
            -Wshadow \
            -Wpointer-arith \
            -Wformat \
            -Wreturn-type \
            -Wsign-compare \
            -Wmultichar \
            -Wformat-nonliteral \
            -Winit-self \
            -Wuninitialized \
            -Wformat-security \
            -Werror

# disable sequence point warning because of AES code
CFLAGS += -Wno-sequence-point

# disable certain optimizations and features when small footprint is required
ifdef SMALL
CFLAGS += -DUSE_PRECOMPUTED_IV=0 -DUSE_PRECOMPUTED_CP=0
endif

OBJS   = bip39.o \
         sha2.o \
				 rand.o \
				 pbkdf2.o \
				 hmac.o \
				 bip32.o \
				 ecdsa.o \
				 bignum.o \
				 secp256k1.o \
				 base58.o \
				 ripemd160.o

all: bip39-cli

%.o: %.c %.h options.h
	$(CC) $(CFLAGS) -o $@ -c $<

bip39-cli.o: bip39-cli.c
	$(CC) $(CFLAGS) -c bip39-cli.c

bip39-cli: $(OBJS) bip39-cli.o
	$(CC) $(CFLAGS) -o bip39-cli bip39-cli.o $(OBJS)

clean:
	rm -f *.o tests test-openssl bip39-cli

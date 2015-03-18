#include <stdio.h>
#include <string.h>

#include "bip39.h"
#include "rand.h"
#include "bip32.h"

#define LOGO "    ██████╗ ██╗██████╗ ██████╗  █████╗        ██████╗██╗     ██╗\n"\
             "    ██╔══██╗██║██╔══██╗╚════██╗██╔══██╗      ██╔════╝██║     ██║\n"\
             "    ██████╔╝██║██████╔╝ █████╔╝╚██████║█████╗██║     ██║     ██║\n"\
             "    ██╔══██╗██║██╔═══╝  ╚═══██╗ ╚═══██║╚════╝██║     ██║     ██║\n"\
             "    ██████╔╝██║██║     ██████╔╝ █████╔╝      ╚██████╗███████╗██║\n"\
             "    ╚═════╝ ╚═╝╚═╝     ╚═════╝  ╚════╝        ╚═════╝╚══════╝╚═╝\n"\
             "    A CLI utility which generates and verifies BIP39 addresses. \n"

int main(void) {

  int i;
  uint8_t seed[512 / 8];
  const char *mnemonic;
  char passphrase[2056];
  char input_mnemonic[2056];
  char xprv_string[1024];
  char xpub_string[1024];

  // output logo
  printf("\n\n%s\n", LOGO);

  // read mnemonic
  printf("enter mnemonic (leave empty to generate): ");
  fgets(input_mnemonic, 2056, stdin);

  i = strlen(input_mnemonic) - 1;

  if (input_mnemonic[i] == '\n') {
    input_mnemonic[i] = '\0';
  }

  if (strlen(input_mnemonic) > 0) {
    mnemonic = input_mnemonic;
  } else {
    // generate mnemonic
    init_rand();
    mnemonic = mnemonic_generate(128);
    printf("generated mnemonic: %s\n", mnemonic);
    finalize_rand();
  }

  if (!mnemonic_check(mnemonic)) {
    fputs("mnemonic is invalid\n", stderr);
    return 1;
  }

  // read passphrase
  printf("enter passphrase (optional): ");
  fgets(passphrase, 2056, stdin);

  i = strlen(passphrase) - 1;

  if (passphrase[i] == '\n') {
    passphrase[i] = '\0';
  }

  // generate seed
  mnemonic_to_seed(mnemonic, passphrase, seed, 0);

  // generate HD node
  HDNode node;
  hdnode_from_seed(seed, 512 / 8, &node);

  // serialize and output master private key
  hdnode_serialize_private(&node, xprv_string, 1024);
  printf("master private key: %s\n", xprv_string);

  // serialize and output master public key
  hdnode_serialize_public(&node, xpub_string, 1024);
  printf("master public key: %s\n", xpub_string);

  return 0;

}

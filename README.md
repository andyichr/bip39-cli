
    ██████╗ ██╗██████╗ ██████╗  █████╗        ██████╗██╗     ██╗
    ██╔══██╗██║██╔══██╗╚════██╗██╔══██╗      ██╔════╝██║     ██║
    ██████╔╝██║██████╔╝ █████╔╝╚██████║█████╗██║     ██║     ██║
    ██╔══██╗██║██╔═══╝  ╚═══██╗ ╚═══██║╚════╝██║     ██║     ██║
    ██████╔╝██║██║     ██████╔╝ █████╔╝      ╚██████╗███████╗██║
    ╚═════╝ ╚═╝╚═╝     ╚═════╝  ╚════╝        ╚═════╝╚══════╝╚═╝
    A CLI utility which generates and verifies BIP39 addresses.

## Copying

This program is heavily based on the MIT-licensed Trezor source code, and as
such is released under the MIT license.

# Usage/Example

    ./bip39-cli
    enter mnemonic (leave empty to generate): 
    generated mnemonic: truly system urge doll panther crew vendor drill onion lamp fortune online
    enter passphrase (optional): 
    master private key: xprv9s21ZrQH143K4UwkcntG6XPGpuL7mkaaLWPs3hK8AKZacX5Vd4mouGZNB7vN8akx53mYg8sSkwu8CfaZDwWXY9rymKGETEt6QmRaQz1VCyo
    master public key: xpub661MyMwAqRbcGy2DipRGTfL1NwAcBDJRhjKTr5ijif6ZVKQeAc64T4sr2Q6heGuZfhDCKXc3SRPYSD1TtzDzXDGSo2XMuvrAQR6KBNuL9qn

# Compiling (requires Docker)

    ./shell make

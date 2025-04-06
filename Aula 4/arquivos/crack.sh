#!/bin/sh

clear

for key in $(seq 0 1023); do
    echo "Tentando a chave $key"
    ./sdes -d misterio_3sdes.txt misterio_3sdes_cifrado.txt $key
    cat misterio_3sdes_cifrado.txt
done
import sys
import numpy as np

i = 0
j = 0

#-------------------------------------------------------------------
# Funcao para transformar {a, b, c, ... z} para {0, 1, 2, ..., 25}:
def map_num (char):
   return ord(char)

#-------------------------------------------------------------------
# Funcao para transformar {0, 1, 2, ..., 25} para {a, b, c, ... z}:
def map_char (num):
   return chr(num)

#def KSA (chave, S, N):
#?????? 

#def PRGA (S, N):
#?????? 

#-------------------------------------------------------------------
file_out = open(sys.argv[3], 'w')
chave = sys.argv[2]
N = 256
S = [0] * N
#?????? 
with open(sys.argv[1]) as file: 
   for line in file:
      for char in line:
         #Nao modifique o intervalo do caractere em c, nem trate espacos ou nova linha!
         #?????? 
      file_out.write("\n")
file_out.close()  

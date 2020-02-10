import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os

file = os.path.join(os.path.realpath('../..'), 'tmp', 'p12out')
df = pd.read_csv(file, header=None)

print(df[0].value_counts())

def is_prime(n):
  if n<=3:  
      return n > 1
  elif n%2==0 or n%3==0:
      return False
  i = 5
  while i*i <= n:
      if n%i==0 or n%(i+2)==0:
          return False
      i = i + 6
  return True

df['is_prime'] = df[0].apply(is_prime)

print(df['is_prime'].value_counts())

cur_high = 1
gap = 0

df['last_gap'] = pd.Series()

cur_high = 1

gap = 1

for index, row in df.iterrows():
    if row[0] > cur_high:
        cur_high = row[0]
        df.iat[index,2] = gap
        gap = 0
    gap += 1

gaps = df['last_gap']

print(gaps.dropna())


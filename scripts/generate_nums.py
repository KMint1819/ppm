import sys
import numpy as np

num = int(sys.argv[1])
with open(f'{num}_nums.data', 'w') as f:
    for i in range(num):
        f.write(str(np.random.randint(0, num)) + '\n')
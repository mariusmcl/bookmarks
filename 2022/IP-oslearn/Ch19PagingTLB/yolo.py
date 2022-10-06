import os
import matplotlib.pyplot as plt
import numpy as np

time = []
sizes = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192]
for num_pages in sizes:
    stream = os.popen(f'./tlb {num_pages}')
    output = stream.read()
    if "fault" in output:
        break
    try:
        secs, usecs = output.split(",")
    except:
        break
    secs = int(secs)
    if secs < 1:
        time.append(int(usecs))
    else:
        time.append((secs * 10**6) - int(usecs))

plt.plot(np.log(sizes[:len(time)]), time)
plt.savefig("plot.png")
import matplotlib.pyplot as plt # plot
import numpy as np # read data

N, mysin, recursive, pade, exact, diff1, diff2, diff3  = np.loadtxt("datos.txt", unpack=True)
fig, ax = plt.subplots()
ax.semilogy(N, diff1, diff2, diff3, '-o', label="data")
ax.set_xlabel("Iter")
ax.set_ylabel("Percentual diff")
plt.show()
fig.savefig("plotting_hw.pdf",bbox_inches='tight')

# Beyla Darassia Martinez Perez
# Nicolas Acero Vargas
# Sergio Andres Cifuentes Vasquez
# Juan Manuel Gonzalez
# Sebastian Prieto Cruz

from matplotlib import pyplot as plt
import pandas as pd
import numpy as np
#Read data file
df = pd.read_table('lab1_data_2026.txt', sep='\t')

#Assign x,y from original data
x = df.iloc[:, 0]
y = df.iloc[:, 1]

#Generate corrected plot values
x1 = np.linspace(0, 5, 200)
c = 2.39*np.sin(2*np.pi*x1)+3.512955*np.cos(2*np.pi*x1)-69.988245

#Plot both data and corrected data
plt.figure(figsize=(8,6))
plt.plot(x, y, label='Data', alpha=.8)
plt.plot(x1, c, label = 'Corrected Data', color='red', alpha=.5)
plt.xlabel("Time"); plt.ylabel("Value"); plt.title("Data vs Time and Corrected Data")
plt.grid(True, alpha=.3); plt.legend(); plt.tight_layout(); plt.show()

#plt.savefig('lab1_model_fit.png', dpi=300)

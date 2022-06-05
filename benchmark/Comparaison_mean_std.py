
## dfs
from cProfile import label
from pandas import read_csv
import matplotlib.pyplot as plt

def makeFileName(AI_name, size_board):
	return f"{AI_name}_{size_board}_100_1.csv"

def loadFile(AI_name, size_board):
	return read_csv(makeFileName(AI_name, size_board), sep=";", comment="#") * 0.001

uet_name = "UniqueEndTest"
hft_name = "HoldFreeTiles"
hftbeg_name = "HoldFreeTilesBtwEachGame"


uet_5 = loadFile(uet_name, 5).to_numpy()
hft_5 = loadFile(hft_name, 5).to_numpy()
hftbeg_5 = loadFile(hftbeg_name, 5).to_numpy()

uet_5_std = uet_5.std(axis=0)
hft_5_std = hft_5.std(axis=0)
hftbeg_5_std = hftbeg_5.std(axis=0)

uet_5_mean = uet_5.mean(axis=0)
hft_5_mean = hft_5.mean(axis=0)
hftbeg_5_mean = hftbeg_5.mean(axis=0)

uet_7 = loadFile(uet_name, 7).to_numpy()
hft_7 = loadFile(hft_name, 7).to_numpy()
hftbeg_7 = loadFile(hftbeg_name, 7).to_numpy()

uet_7_std = uet_7.std(axis=0)
hft_7_std = hft_7.std(axis=0)
hftbeg_7_std = hftbeg_7.std(axis=0)

uet_7_mean = uet_7.mean(axis=0)
hft_7_mean = hft_7.mean(axis=0)
hftbeg_7_mean = hftbeg_7.mean(axis=0)

uet_9 = loadFile(uet_name, 9).to_numpy()
hft_9 = loadFile(hft_name, 9).to_numpy()
hftbeg_9 = loadFile(hftbeg_name, 9).to_numpy()

uet_9_std = uet_9.std(axis=0)
hft_9_std = hft_9.std(axis=0)
hftbeg_9_std = hftbeg_9.std(axis=0)

uet_9_mean = uet_9.mean(axis=0)
hft_9_mean = hft_9.mean(axis=0)
hftbeg_9_mean = hftbeg_9.mean(axis=0)

x_5 = range(5*5, 0, -1)
x_7 = range(7*7, 0, -1)
x_9 = range(9*9, 0, -1)

plt.subplot(311)
plt.errorbar(x_5, uet_5_mean, yerr=uet_5_std, label="UniqueEndTest")
plt.errorbar(x_5, hft_5_mean, yerr=hft_5_std, label="HoldFreeTiles")
plt.errorbar(x_5, hftbeg_5_mean, yerr=hftbeg_5_std, label="HoldFreeTilesBtwEachGame")
plt.xlabel("Nombre de cases restantes")
plt.ylabel("temps (s)")
plt.legend()

plt.subplot(312)
plt.errorbar(x_7, uet_7_mean, yerr=uet_7_std, label="UniqueEndTest")
plt.errorbar(x_7, hft_7_mean, yerr=hft_7_std, label="HoldFreeTiles")
plt.errorbar(x_7, hftbeg_7_mean, yerr=hftbeg_7_std, label="HoldFreeTilesBtwEachGame")
plt.xlabel("Nombre de cases restantes")
plt.ylabel("temps (s)")
plt.legend()

plt.subplot(313)
plt.errorbar(x_9, uet_9_mean, yerr=uet_9_std, label="UniqueEndTest")
plt.errorbar(x_9, hft_9_mean, yerr=hft_9_std, label="HoldFreeTiles")
plt.errorbar(x_9, hftbeg_9_mean, yerr=hftbeg_9_std, label="HoldFreeTilesBtwEachGame")
plt.xlabel("Nombre de cases restantes")
plt.ylabel("temps (s)")
plt.legend()

plt.show()

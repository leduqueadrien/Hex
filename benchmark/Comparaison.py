
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


plt.subplot(331)
plt.plot(uet_5_mean, label="UniqueEndTest")
plt.plot(hft_5_mean, label="HoldFreeTiles")
plt.plot(hftbeg_5_mean, label="HoldFreeTilesBtwEachGame")
plt.legend()

plt.subplot(332)
plt.plot(uet_7_mean, label="UniqueEndTest")
plt.plot(hft_7_mean, label="HoldFreeTiles")
plt.plot(hftbeg_7_mean, label="HoldFreeTilesBtwEachGame")
plt.legend()

plt.subplot(333)
plt.plot(uet_9_mean, label="UniqueEndTest")
plt.plot(hft_9_mean, label="HoldFreeTiles")
plt.plot(hftbeg_9_mean, label="HoldFreeTilesBtwEachGame")
plt.legend()

plt.subplot(334)
plt.plot(uet_5_std, label="UniqueEndTest")
plt.plot(hft_5_std, label="HoldFreeTiles")
plt.plot(hftbeg_5_std, label="HoldFreeTilesBtwEachGame")
plt.legend()

plt.subplot(335)
plt.plot(uet_7_std, label="UniqueEndTest")
plt.plot(hft_7_std, label="HoldFreeTiles")
plt.plot(hftbeg_7_std, label="HoldFreeTilesBtwEachGame")
plt.legend()

plt.subplot(336)
plt.plot(uet_9_std, label="UniqueEndTest")
plt.plot(hft_9_std, label="HoldFreeTiles")
plt.plot(hftbeg_9_std, label="HoldFreeTilesBtwEachGame")
plt.legend()

plt.show()

from sklearn.neural_network import MLPClassifier
import pandas as pd
import numpy as np

WhiteList = []
BlackList = []

f = open("../Game.rec", "r")
for x in f:
    if ("White" in x):
        WhiteList.append(x)
    else:
        BlackList.append(x)

lista1 = []
for x in WhiteList:
    lista1.append(x.split(" "))

lista2 = []
for x in BlackList:
    lista2.append(x.split(" "))

listNumWhite = []
listTargetWhite = []

listNumBlack = []
listTargetBlack = []

for x in lista1:
    size = len(x)
    new_str = str(x[size-1:])
    listTargetWhite.append(new_str.replace('\\n', '').replace('[', '').replace(']', '').replace("'", ''))

for x in lista2:
    size = len(x)
    new_str = str(x[size-1:])
    listTargetBlack.append(new_str.replace('\\n', '').replace('[', '').replace(']', '').replace("'", ''))


for x in lista1:
    del x[len(x)-4:]

for x in lista2:
    del x[len(x)-4:]

for x in lista1:
    listNumWhite.append([int(i) for i in x])

for x in lista2:
    listNumBlack.append([int(i) for i in x])


target = pd.DataFrame(listTargetWhite)
target.to_csv("targetWhite.csv", index=False)

data = pd.DataFrame(listNumWhite)
data.to_csv("dataChessWhite.csv", index=False)

target = pd.DataFrame(listTargetBlack)
target.to_csv("targetBlack.csv", index=False)

data = pd.DataFrame(listNumBlack)
data.to_csv("dataChessBlack.csv", index=False)

# data = pd.read_csv("dataChess.csv")
# target = pd.read_csv("target.csv")

# model = MLPClassifier(random_state=1, max_iter=5000)

# model.fit(data, target.values.ravel())

# import pickle

# # //pickle.dump(model, open('rfr_model.sav', 'wb'))

# model = pickle.load(open('rfr_model.sav', 'rb'))                 
# print('Loaded model score:', model.predict(data[0:1]))


# print(data[0:1])
# test = clf.predict(data[0:1])

# print(len(clf.classes_))
# print(clf.classes_)

# f = open("weightsBiasOut.txt", "a")
# test = np.array(clf.intercepts_[1])
# for x in test:
#     f.write(" ")
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.3f" % x}))
# f.close()

# f = open("weightsBiasHidden.txt", "a")
# test = np.array(clf.intercepts_[0])
# for x in test:
#     f.write(" ")
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.3f" % x}))
# f.close()

# f = open("weightsOutPut.txt", "a")
# test = np.array(clf.coefs_[1])
# for x in test:
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.3f" % x}))
# f.close()

# f = open("weightsHidden.txt", "a")
# test = np.array(clf.coefs_[0])
# for x in test:
#     f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.3f" % x}))
# f.close()
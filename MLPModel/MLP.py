from sklearn.neural_network import MLPClassifier
import pandas as pd
import numpy as np

# lista = []

# f = open("Game.rec", "r")
# for x in f:
#     if "White" in x:
#         lista.append(x)


# lista2 = []
# for x in lista:
#     lista2.append(x.split(" "))

# listNum = []
# listTarget = []

# for x in lista2:
#     size = len(x)
#     new_str = str(x[size-1:])
#     listTarget.append(new_str.replace('\\n', '').replace('[', '').replace(']', '').replace("'", ''))

# for x in lista2:
#     del x[len(x)-4:]

# for x in lista2:
#     listNum.append([int(i) for i in x])


# target = pd.DataFrame(listTarget)
# target.to_csv("target.csv", index=False)


# data = pd.DataFrame(listNum)
# data.to_csv("dataChess.csv", index=False)

data = pd.read_csv("PreprocessedData/dataChess.csv")
target = pd.read_csv("PreprocessedData/target.csv")

clf = MLPClassifier(random_state=1, max_iter=300)

clf.fit(data, target.values.ravel())

# test = clf.predict_proba(data[0:1])

print(clf.classes_)

f = open("weightsBiasOut.txt", "a")
test = np.array(clf.intercepts_[1])
for x in test:
    f.write(" ")
    f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
f.close()

f = open("weightsBiasHidden.txt", "a")
test = np.array(clf.intercepts_[0])
for x in test:
    f.write(" ")
    f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
f.close()

f = open("weightsOutPut.txt", "a")
test = np.array(clf.coefs_[1])
for x in test:
    f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
f.close()

f = open("weightsHidden.txt", "a")
test = np.array(clf.coefs_[0])
for x in test:
    f.write(np.array2string(x, formatter={'float_kind':lambda x: "%.5f" % x}))
f.close()